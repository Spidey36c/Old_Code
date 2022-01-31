using Microsoft.VisualStudio.TestTools.UnitTesting;
using MyStack;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics.CodeAnalysis;

namespace MyStack.Tests
{
    //This is a comment
    [TestClass()]
    [ExcludeFromCodeCoverage]
    public class IMyStackTests
    {

        private TestContext testContext;
        public TestContext TestContext
        {
            get { return testContext; }
            set { testContext = value; }
        }

        [TestMethod()]
        public void TestPushSucceeds()
        {
            MyStack temp = new MyStack();
            temp.Push(35);
            Assert.AreEqual(35, temp.Top());
        }

        [TestMethod()]
        public void TestPopSucceeds()
        {
            MyStack temp = new MyStack();
            temp.Push(35);
            temp.Push(42);
            temp.Pop();
            Assert.AreEqual(35, temp.Top());
        }

        [TestMethod()]
        public void TestTopSucceeds()
        {
            MyStack temp = new MyStack();
            temp.Push(35);
            temp.Push(42);
            Assert.AreEqual(temp.Top(), 42);
        }

        [TestMethod()]
        public void TestSizeSucceeds()
        {
            MyStack temp = new MyStack();
            for (int i = 0; i < 5; i++)
                temp.Push(i);
            Assert.AreEqual(5, temp.Size());
        }

        [TestMethod()]
        public void TestClearSucceeds()
        {
            MyStack temp = new MyStack();
            for (int i = 0; i < 10; i++)
                temp.Push(i);
            temp.Clear();
            Assert.AreEqual(0, temp.Size());
        }

        [TestMethod()]
        [ExpectedException(typeof(InvalidOperationException))]
        public void TestOverFlow()
        {
            MyStack temp = new MyStack();
            for (int i = 0; i < 11; i++)
                temp.Push(i);
        }

        [TestMethod()]
        [ExpectedException(typeof(InvalidOperationException))]
        public void TestUnderFlow()
        {
            MyStack temp = new MyStack();
            temp.Pop();
        }

        [TestMethod()]
        [DeploymentItem("TestData.xlsx")]
        [DataSource("System.Data.OleDb", // The provider 
        "Provider=Microsoft.ACE.OLEDB.12.0;Data Source='TestData.xlsx';Persist Security Info=False;Extended Properties='Excel 8.0'", "StackData$",      // The table name, in this case, the sheet name with a '$' appended.				
         DataAccessMethod.Sequential)]
        public void TestPushPopDataDrive()
        {
            MyStack temp = new MyStack();
            int pushNumber = Convert.ToInt32(TestContext.DataRow["pushNumber"]);
            int popNumber = Convert.ToInt32(TestContext.DataRow["popNumber"]);
            int expectedLeft = Convert.ToInt32(TestContext.DataRow["expectedLeft"]);
            string description = TestContext.DataRow["description"].ToString();

            for(int i = 0; i < pushNumber;i++)
            {
                temp.Push(i);
            }

            for(int i = 0; i < popNumber;i++)
            {
                temp.Pop();
            }

            Assert.AreEqual(expectedLeft, temp.Size());
        }
    }
}