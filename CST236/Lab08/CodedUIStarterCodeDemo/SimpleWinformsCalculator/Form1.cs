using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace SimpleWinformsCalculator
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            int result;
            result = Convert.ToInt32(this.textInput1.Text) + Convert.ToInt32(this.textInput2.Text);
            this.textAnswer.Text = result.ToString(); 
        }

        private void btnSubtract_Click(object sender, EventArgs e)
        {
            int result;
            result = Convert.ToInt32(this.textInput1.Text) - Convert.ToInt32(this.textInput2.Text);
            this.textAnswer.Text = result.ToString(); 

        }

        private void btnMultiply_Click(object sender, EventArgs e)
        {
            int result;
            result = Convert.ToInt32(this.textInput1.Text) * Convert.ToInt32(this.textInput2.Text);
            this.textAnswer.Text = result.ToString(); 

        }

        private void btnDivide_Click(object sender, EventArgs e)
        {
            int result;
            result = Convert.ToInt32(this.textInput1.Text) / Convert.ToInt32(this.textInput2.Text);
            this.textAnswer.Text = result.ToString(); 

        }
    }
}
