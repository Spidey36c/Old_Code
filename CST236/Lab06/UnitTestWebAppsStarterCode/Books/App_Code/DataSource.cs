using System;
using System.Collections.Generic;
using System.Data;
using System.Configuration;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Data.SqlClient;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;

/// <summary>
/// Summary description for DataSource
/// </summary>

namespace DM.UnitTest
{
    public class DataSource
    {
        public static List<Book> GetBooks()
        {
            BooksWS.Service service = new BooksWS.Service();

            BooksWS.Book[] booksReturned = service.GetBooks(10);

            List<Book> booksForDisplay = new List<Book>();

            foreach (BooksWS.Book book in booksReturned)
            {
                Book b = new Book(book.Id, book.Title, book.Author);
                booksForDisplay.Add(b);
            }

            return booksForDisplay;
        }
    }

    public class Book
    {
        public Book()
        {

        }

        public Book(int id, string title, string author)
        {
            this.Id = id;
            this.Title = title;
            this.Author = author;
        }

        int id;

        public int Id
        {
            get { return id; }
            set { id = value; }
        }
        
        String title;

        public String Title
        {
            get { return title; }
            set { title = value; }
        }

        String author;

        public String Author
        {
            get { return author; }
            set { author = value; }
        }
    }
}
