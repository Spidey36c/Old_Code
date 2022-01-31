using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.ServiceModel;
using TBlogService.Models;

namespace TBlogService
{
    [ServiceContract]
    public interface IBlogService
    {
        [OperationContract]
        IEnumerable<Blog> GetBlogs();
    }
}
