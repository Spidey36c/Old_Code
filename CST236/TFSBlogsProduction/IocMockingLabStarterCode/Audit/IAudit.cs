using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Audit
{
    public interface IAudit
    {
        void Message(string msg);
    }
}
