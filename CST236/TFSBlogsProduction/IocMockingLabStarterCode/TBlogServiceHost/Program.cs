using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.ServiceModel;
using TBlogService;
using Microsoft.Practices.Unity;
using System.Configuration;
using TFSBlogRepository;
using Audit;
using SimpleAudit;

namespace TBlogServiceHost
{
    class Program
    {
        static void Main(string[] args)
        {
            //InjectionConstructor ctor = new InjectionConstructor(ConfigurationManager.ConnectionStrings["TFSBlogEntities"].ConnectionString);
            //IoC.Container.GetInstance().RegisterType<IBlogRepository, BlogRepository>(ctor);

            using (ServiceHost service = new ServiceHost(typeof(BlogService), new Uri("http://localhost:9000/TBlog")))
            {
                service.Open();
                Console.WriteLine("Service started");
                Console.ReadLine();
            }
        }
    }
}
