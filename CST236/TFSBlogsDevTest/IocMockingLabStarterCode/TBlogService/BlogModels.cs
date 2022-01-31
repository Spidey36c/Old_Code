using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using TFSBlogRepository;
using System.Configuration;

namespace TBlogService.Models
{
    public class Blogs
    {
        public IEnumerable<Blog> GetBlogs(IBlogRepository repository, int pageSize, int page)
        {
            List<BlogModel.Blog> blogs = (from b in repository.GetBlogs()
                                          select b).ToList();

            List<Blog> vmBlogs = new List<Blog>();

            foreach (var blog in blogs)
            {
                Blog vmBlog = new Blog { Title = blog.Name, SubTitle = blog.SubTitle, UserName = blog.User.Name, EMail = blog.User.EMail };
                vmBlogs.Add(vmBlog);
            }

            return vmBlogs;
        }
    }

    public class Blog
    {
        public string Title { get; set; }
        public string SubTitle { get; set; }
        public string UserName { get; set; }
        public string EMail { get; set; }
    }
}