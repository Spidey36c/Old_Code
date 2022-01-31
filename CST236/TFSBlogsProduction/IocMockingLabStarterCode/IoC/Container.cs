using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Practices.Unity;
using Microsoft.Practices.Unity.Configuration;
using System.Configuration;

namespace IoC
{
    public class Container
    {
        private static UnityContainer container;

        static void RegisterIoc()
        {
            UnityConfigurationSection section =
                ConfigurationManager.GetSection("unity") as UnityConfigurationSection;
            if (section != null)
            {
                section.Configure(container);
            }
        }
        public static IUnityContainer GetInstance()
        {
            if (container == null)
            {
                container = new UnityContainer();
                RegisterIoc();
            }
            return container;
        }
    }
}
