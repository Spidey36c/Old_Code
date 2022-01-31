using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Microsoft.VisualStudio.TestTools.UnitTesting.Web;
using BookWSTest.localhost;

namespace BookWSTest
{
    [TestClass]
    public class ServiceTest
    {
        private TestContext testContextInstance;
        public TestContext TestContext
        {
            get { return testContextInstance; }
            set { testContextInstance = value; }
        }

        [TestMethod]
        public void GetBookTest()
        {
            Service target = new Service();
            int count = 10;
            int expected = 10;
            Book[] actual = target.GetBooks(count);
            Assert.AreEqual(expected, actual.Length);
        }

        [TestMethod]
        [AspNetDevelopmentServer("BooksServer", @"%PathToWebRoot%")]
        public void GetBooksTest2()
        {
            Service target = new Service();
            WebServiceHelper.TryUrlRedirection(target, TestContext, "BooksServer");
            int count = 10;
            int expected = 10;
            Book[] actual = target.GetBooks(count);
            Assert.AreEqual(expected, actual.Length);
        }
    }
}
