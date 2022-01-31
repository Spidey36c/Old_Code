using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Calc1;

namespace Client
{
    class Program
    {
        //After Release 2.2
        static void Main(string[] args)
        {
            Calculator c = new Calculator();

            Console.WriteLine("The sum of 5 + 3 is: {0}",c.Add(5,3));
        }
    }
}
