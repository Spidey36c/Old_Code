using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Blog = TBlogService.Models.Blog;
using System.Collections.Generic;
using System.Linq;
using TBlogService;
using TFSBlogRepository;
using Rhino.Mocks;
using Audit;

namespace TBlogServiceTest
{
    [TestClass]
    public class TBlogServiceTest
    {
        
        //Merging this comment
        private IBlogRepository _repository;

        [TestInitialize()]
        public void Initialize()
        {
            _repository = MockRepository.GenerateStub<IBlogRepository>();
        }

        [TestMethod]
        public void GetBlogs_ReturnsAllBlogs()
        {
            BlogModel.User user = new BlogModel.User { Name = "dummyname" };
            List<BlogModel.Blog> blogs = new List<BlogModel.Blog>
            {
                new BlogModel.Blog { User = user }, new BlogModel.Blog { User = user },
            };
            _repository.Stub(r => r.GetBlogs()).Return(blogs.AsQueryable());

            BlogService target = new BlogService(_repository, null);
            IEnumerable<Blog> actual;
            actual = target.GetBlogs();
            Assert.AreEqual(2, actual.Count());
        }

        [TestMethod()]
        [ExpectedException(typeof(ServiceException))]
        public void GetBlogs_ShouldThrowAnException_WhenRepositoryIsNull()
        {
            _repository.Stub(r => r.GetBlogs()).Return(null);
            BlogService target = new BlogService(_repository, null);
            IEnumerable<Blog> actual;
            actual = target.GetBlogs();
        }

        [TestMethod()]
        [ExpectedException(typeof(ServiceException))]
        public void GetBlogs_ShouldThrowAServiceException_WhenGetBlogsThrowsAnException()
        {
            _repository.Stub(r => r.GetBlogs()).IgnoreArguments().Throw(new NullReferenceException());
            BlogService target = new BlogService(_repository, null);
            IEnumerable<Blog> actual;
            actual = target.GetBlogs();
        }

        [TestMethod()]
        public void GetBlogs_ShouldProduceAnAuditMessage_WhenAnIAuditIsPassed()
        {
            MockRepository mocks = new MockRepository();
            _repository = mocks.DynamicMock<IBlogRepository>();
            IAudit audit = mocks.StrictMock<IAudit>();

            BlogModel.User user = new BlogModel.User { Name = "dummyname" };

            List<BlogModel.Blog> blogs = new List<BlogModel.Blog>
            {
                new BlogModel.Blog { User = user },
                new BlogModel.Blog { User = user },
            };
            using (mocks.Record())
            {
                Expect.Call(() => audit.Message("Get Blogs"));
                Expect.Call(_repository.GetBlogs()).Return(blogs.AsQueryable());
            }
            using (mocks.Playback())
            {
                BlogService target = new BlogService(_repository, audit);
                target.GetBlogs();
            }
        }
    }
}
