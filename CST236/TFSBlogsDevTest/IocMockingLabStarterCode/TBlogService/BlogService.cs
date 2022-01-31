using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using TFSBlogRepository;
using Microsoft.Practices.Unity;
using System.Configuration;
using TBlogService.Models;
using Audit;
using SimpleAudit;

namespace TBlogService
{
    public class BlogService : IBlogService
    {
        private IBlogRepository _repository;

        private IAudit _audit;

        public BlogService()
        : this(IoC.Container.GetInstance().Resolve<IBlogRepository>(),IoC.Container.GetInstance().Resolve<IAudit>())
        { }

        public BlogService(IBlogRepository repository,IAudit audit)
        {
            _repository = repository;
            _audit = audit;
        }

        public IEnumerable<Blog> GetBlogs()
        {
            //string connectionString = ConfigurationManager.ConnectionStrings["TFSBlogEntities"].ConnectionString;
            //IBlogRepository repository = new BlogRepository(connectionString);

            Blogs blogFactory = new Blogs();
            IEnumerable<Blog> blogs;
            try
            {
                blogs = blogFactory.GetBlogs(_repository, 10, 1);
            }
            catch (Exception)
            {
                throw new ServiceException();
            }
            if(_audit != null)
            {
                _audit.Message("Get Blogs");
            }

            return blogs;
        }

    }
}
