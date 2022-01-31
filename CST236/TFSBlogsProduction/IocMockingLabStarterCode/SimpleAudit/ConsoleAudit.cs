using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Audit;

namespace SimpleAudit
{
    public class ConsoleAudit: IAudit
    {
        public void Message(string msg)
        {
            Console.WriteLine(msg);
        }
    }
}
