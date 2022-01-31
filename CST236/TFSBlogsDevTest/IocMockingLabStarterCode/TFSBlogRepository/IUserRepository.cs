using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using BlogModel;
using Repository;

namespace TFSBlogRepository
{
    public interface IUserRepository : IRepository<User>
    {
    }
}
