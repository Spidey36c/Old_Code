using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using TBlogServiceClient.TBlogServiceReference;

namespace TBlogServiceClient
{
    class ClientProgram
    {

        static void Main(string[] args)
        {
            BlogServiceClient proxy = new BlogServiceClient();

            var blogs = proxy.GetBlogs();

            foreach (var item in blogs)
            {
                Console.WriteLine(item.Title);
            }
        }
    }
}
