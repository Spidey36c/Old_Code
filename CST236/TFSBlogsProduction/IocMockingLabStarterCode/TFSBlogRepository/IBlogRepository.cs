using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using BlogModel;
using Repository;

namespace TFSBlogRepository
{
    public interface IBlogRepository : IRepository<Blog>
    {
        IQueryable<Blog> GetBlogPosts(int id);
        IQueryable<Blog> GetBlogs();
    }
}
