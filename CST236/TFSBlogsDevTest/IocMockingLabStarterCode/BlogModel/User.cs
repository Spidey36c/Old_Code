using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace BlogModel
{
    public class User
    {
        public virtual int Id { get; set; }
        public virtual int? BlogId { get; set; }
        public virtual string Name { get; set; }
        public virtual string EMail { get; set; }
        public virtual string Salt { get; set; }
        public virtual string HashedPassword { get; set; }
        public virtual Blog Blog { get; set; } // FK_USERS_BLOGS
        public virtual List<Blog> Blogs { get; set; } // FK_BLOGS_USERS
    }
}
