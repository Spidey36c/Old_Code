using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyStack
{
    abstract public class IMyStack
    {
        public abstract void Push(int x);
        public abstract int Pop();
        public abstract int Top();
        public abstract int Size();
        public abstract void Clear();

    }

    public class MyStack : IMyStack
    {
        public override void Push(int x)
        {
            if (m_arrlen >= 10)
                throw new InvalidOperationException("Can't push onto a full stack");
            m_arr[m_arrlen] = x;
            ++m_arrlen;
        }

        public override int Pop()
        {
            if (m_arrlen <= 0)
                throw new InvalidOperationException("Can't pop off of a empty stack");
            return m_arr[--m_arrlen];
        }

        public override int Top()
        {
            if (m_arrlen <= 0)
                throw new InvalidOperationException("Can't look at the top of an empty stack");
            return m_arr[m_arrlen - 1];
        }

        public override int Size()
        {
            return m_arrlen;
        }

        public override void Clear()
        {
            Array.Clear(m_arr, 0, 10);
            m_arrlen = 0;
        }

        int[] m_arr = new int[10];
        int m_arrlen = 0;
    }
}
