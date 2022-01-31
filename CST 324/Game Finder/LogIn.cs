using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace Game_Finder
{
    public partial class LogIn : Form
    {
        public LogIn()
        {
            InitializeComponent();
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            //String query = "SELECT * from translate";
            //String connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist";
            //SqlConnection con = new SqlConnection(connectionString);
            //SqlCommand cmd = new SqlCommand(query, con);
            //con.Open();
            //MessageBox.Show("Connected with sql server");
            //con.Close();
            CreateAccount m = new CreateAccount();
            m.Show();
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            //String query = "SELECT * from translate";
            //String connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist";
            //SqlConnection con = new SqlConnection(connectionString);
            //SqlCommand cmd = new SqlCommand(query, con);
            //con.Open();
            //SqlDataReader dataReader = cmd.ExecuteReader();
            //while(dataReader.Read())
            //{
            //    if(dataReader.GetValue(0).Equals(textBox1.Text))
            //    {
            //        label1.Text = dataReader.GetValue(1) + "";
            //    }
            //}
            //con.Close();
            Log m = new Log(this);
            m.Show();
        }
    }
}
