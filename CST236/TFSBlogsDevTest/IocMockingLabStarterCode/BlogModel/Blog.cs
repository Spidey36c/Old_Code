using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace BlogModel
{
    public class Blog
    {
        public virtual int Id { get; set; }
        public virtual string Name { get; set; }
        public virtual string SubTitle { get; set; }
        public virtual int UserId { get; set; }
        public virtual List<Post> Posts { get; set; }
        public virtual User User { get; set; } // FK_BLOGS_USER
        public virtual List<User> Users { get; set; } // FK_USER_BLOGS
    }
}
