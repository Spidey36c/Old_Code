using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using BlogModel;

namespace TFSBlogRepository
{
    public class PostRepository : TFSBlogRepository<Post>, IPostRepository
    {
        public PostRepository(string connectionString)
            : base(connectionString)
        {
        }
    }
}
