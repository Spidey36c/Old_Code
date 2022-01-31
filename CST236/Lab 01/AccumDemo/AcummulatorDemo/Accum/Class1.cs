using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Accum
{
    public class Accumulator
    {
        int data = 0;

        public int Add(int x)
        {
            return data += x;
        }
    }
}
