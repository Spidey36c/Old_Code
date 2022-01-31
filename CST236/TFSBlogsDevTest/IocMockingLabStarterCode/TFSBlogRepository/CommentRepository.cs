using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using BlogModel;

namespace TFSBlogRepository
{
    public class CommentRepository : TFSBlogRepository<Comment>, ICommentRepository
    {
        public CommentRepository(string connectionString)
            : base(connectionString)
        {
        }
    }
}
