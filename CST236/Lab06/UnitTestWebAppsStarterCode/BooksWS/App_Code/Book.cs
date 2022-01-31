using System;
using System.Collections.Generic;
using System.Web;


public class Book
{
    int id;
    string title;
    string author;
    public int Id
    {
        get { return id; }
        set { id = value; }
    }

    public string Title
    {
        get { return title; }
        set { title = value; }
    }

    public string Author
    {
        get { return author; }
        set { author = value; }
    }

    public Book()
    {

    }

    public Book(int id, string title, string author)
    {
        this.Id = id;
        this.Title = title;
        this.Author = author;
    }
}