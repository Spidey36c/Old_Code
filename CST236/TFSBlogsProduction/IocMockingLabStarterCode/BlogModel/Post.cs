using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace BlogModel
{
    public class Post
    {
        public virtual int Id { get; set; }
        public virtual int BlogId { get; set; }
        public virtual string Title { get; set; }
        public virtual string Value { get; set; }
        public virtual DateTime DatePosted { get; set; }
        public virtual Blog Blog { get; set; }
        public virtual List<Comment> Comments { get; set; }
    }
}
