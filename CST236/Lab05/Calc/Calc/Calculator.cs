using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Calc
{
    public class Calculator
    {
        static public int Add(int x, int y)
        {
            return x + y;
        }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Performance", "CA1822:MarkMembersAsStatic")]
        public int Sub(int x, int y)
        {
            return x - y;
        }

        static public int Mult(int x, int y)
        {
            return x * y;
        }

        public int Div(int x, int y)
        {
            return x / y;
        }
    }
}
