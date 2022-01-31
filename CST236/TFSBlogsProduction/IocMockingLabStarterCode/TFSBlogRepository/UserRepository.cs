using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using BlogModel;

namespace TFSBlogRepository
{
    public class UserRepository : TFSBlogRepository<User>, IUserRepository
    {
        public UserRepository(string connectionString)
            : base(connectionString)
        {
        }
    }
}
