using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Microsoft.VisualStudio.TestTools.UnitTesting.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace BooksTest
{
    [TestClass]
    public class AddBookTest
    {
        private TestContext testContextInstance;
        public TestContext TestContext
        {
            get { return testContextInstance; }
            set { testContextInstance = value; }
        }
        [TestMethod]
        [HostType("ASP.NET")]
        [AspNetDevelopmentServerHost(@"%PathToWebRoot2%", "/Books")]
        [UrlToTest("http://localhost:1642/Default.aspx")]
        public void TestAddSingleBook()
        {
            Page page = TestContext.RequestedPage;

            ListBox bookList = (ListBox)page.FindControl("allBooks");
            ListBox orderedBooks = (ListBox)page.FindControl("orderedBooks");
            Button select = (Button)page.FindControl("SelectBook");

            Assert.IsNotNull(bookList);
            Assert.IsNotNull(orderedBooks);
            Assert.IsNotNull(select);

            bookList.DataBind();
            bookList.SelectedIndex = 0;

            PrivateObject po = new PrivateObject(page);
            po.Invoke("Select_OnClick", select, EventArgs.Empty);

            Assert.AreEqual(1, orderedBooks.Items.Count);
        }
        [TestMethod]
        [HostType("ASP.NET")]
        [AspNetDevelopmentServerHost(@"%PathToWebRoot2%", "/Books")]
        [UrlToTest("http://localhost:1642/Default.aspx")]
        public void TestAddSingleBook2()
        {
            Page page = TestContext.RequestedPage;

            ListBox bookList = (ListBox)page.FindControl("allBooks");
            ListBox orderedBooks = (ListBox)page.FindControl("orderedBooks");
            Button select = (Button)page.FindControl("SelectBook");

            Assert.IsNotNull(bookList);
            Assert.IsNotNull(orderedBooks);
            Assert.IsNotNull(select);

            bookList.DataBind();
            bookList.SelectedIndex = 0;

            PrivateObject po = new PrivateObject(page);
            po.Invoke("Select_OnClick", select, EventArgs.Empty);
            po.Invoke("Select_OnClick", select, EventArgs.Empty);

            Assert.AreEqual(1, orderedBooks.Items.Count);
        }

        [TestMethod]
        [HostType("ASP.NET")]
        [AspNetDevelopmentServerHost(@"%PathToWebRoot2%", "/Books")]
        [UrlToTest("http://localhost:1642/Default.aspx")]
        public void TestAddNoBooks()
        {
            Page page = TestContext.RequestedPage;

            ListBox bookList = (ListBox)page.FindControl("allBooks");
            ListBox orderedBooks = (ListBox)page.FindControl("orderedBooks");
            Button select = (Button)page.FindControl("SelectBook");

            Assert.IsNotNull(bookList);
            Assert.IsNotNull(orderedBooks);
            Assert.IsNotNull(select);

            bookList.DataBind();

            PrivateObject po = new PrivateObject(page);
            po.Invoke("Select_OnClick", select, EventArgs.Empty);

            Assert.AreEqual(0, orderedBooks.Items.Count);
        }
    }
}
