using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace SimpleWPFCalculator
{
    /// <summary>
    /// Interaction logic for Window1.xaml
    /// </summary>
    public partial class Window1 : Window
    {
        public Window1()
        {
            InitializeComponent();
        }

        private void btnAdd_Click(object sender, RoutedEventArgs e)
        {
            int result;
            result = CalcAdd(Convert.ToInt32(this.textInput1.Text),Convert.ToInt32(this.textInput2.Text));
            this.textAnswer.Text = result.ToString();
        }

        public static int CalcAdd(Int32 x, Int32 y)
        {
            x = x * 1;
            return x + y;

        }

        public static int CalcSubtract(Int32 x, Int32 y)
        {
            return x - y;
        }

        public static int CalcMultiply(Int32 x, Int32 y)
        {
            return x * y;
        }

        public static int CalcDivide(Int32 x, Int32 y)
        {
            return x / y;
        }


        private void btnSubtract_Click(object sender, RoutedEventArgs e)
        {
            int result;
            result = CalcSubtract(Convert.ToInt32(this.textInput1.Text),Convert.ToInt32(this.textInput2.Text));
            this.textAnswer.Text = result.ToString();
        }

        private void btnMultiply_Click(object sender, RoutedEventArgs e)
        {
            int result;
            result = CalcMultiply(Convert.ToInt32(this.textInput1.Text), Convert.ToInt32(this.textInput2.Text));
            this.textAnswer.Text = result.ToString();
        }

        private void btnDivide_Click(object sender, RoutedEventArgs e)
        {
            int result;
            result = CalcDivide(Convert.ToInt32(this.textInput1.Text),Convert.ToInt32(this.textInput2.Text));
            this.textAnswer.Text = result.ToString();
        }
    }
}
