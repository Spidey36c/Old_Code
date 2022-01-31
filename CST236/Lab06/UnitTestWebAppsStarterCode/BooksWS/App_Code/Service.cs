using System;
using System.Web;
using System.Web.Services;
using System.Web.Services.Protocols;
using System.Collections.Generic;


[WebService(Namespace = "http://TestingClass.Org/")]
[WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
public class Service : System.Web.Services.WebService
{
    private static List<Book> CreateBooksList()
    {
        List<Book> books = new List<Book>();
        Book b = new Book(1, "Test Driven Development", "Beck");
        books.Add(b); //etc…. 
        b = new Book(2, "Have Spacesuit will travel", "Heinlein");
        books.Add(b);
        b = new Book(3, "Do Androids Dream of Electric Sheep", "K. Dick");
        books.Add(b);
        b = new Book(4, "The Green Bible", "Breedlove");
        books.Add(b);
        b = new Book(5, "Another Book", "Someone");
        books.Add(b);
        b = new Book(6, "Green Eggs and Ham", "Suess");
        books.Add(b);
        b = new Book(7, "A Fistful of Books", "Westtree");
        books.Add(b);
        b = new Book(8, "A Fistful More", "Westtree");
        books.Add(b);
        b = new Book(9, "Two More Books", "Else");
        books.Add(b);
        b = new Book(10, "This", "That");
        books.Add(b);
        return books; 
    }
    [WebMethod]
    public int BookCount()
    {
        return 5;
    }

    [WebMethod]
    public List<Book> GetBooks(int Count)
    {
        List<Book> allBooks = CreateBooksList();
        List<Book> returnedBooks = new List<Book>();
        returnedBooks = allBooks.GetRange(0, Count);
        return returnedBooks;
    }

}


