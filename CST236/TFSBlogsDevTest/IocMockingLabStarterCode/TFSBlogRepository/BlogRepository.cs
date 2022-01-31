using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using BlogModel;

namespace TFSBlogRepository
{
    public class BlogRepository : TFSBlogRepository<Blog>, IBlogRepository
    {
        public BlogRepository(string connectionString)
            : base(connectionString)
        {
        }

        public IQueryable<Blog> GetBlogPosts(int id)
        {
            var value = from b in ObjectSet.Include("Posts.Comments").Include("User")
                        where b.Id == id
                        select b;

            return value.AsQueryable();
        }

        public IQueryable<Blog> GetBlogs()
        {
            var value = from b in ObjectSet.Include("User")
                        select b;

            return value.AsQueryable();
        }
    }
}
