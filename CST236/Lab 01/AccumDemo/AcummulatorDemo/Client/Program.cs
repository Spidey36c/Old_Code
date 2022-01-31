using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Accum;

namespace Client
{
    class Program
    {
        static void Main(string[] args)
        {
            Accumulator a = new Accumulator();

            Console.WriteLine("Adding 5: {0}", a.Add(5));
            Console.WriteLine("Adding 2: {0}", a.Add(2));
            Console.WriteLine("Adding 3: {0}", a.Add(3));
        }
    }
}
