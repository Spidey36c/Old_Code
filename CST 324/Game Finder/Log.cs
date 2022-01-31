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
    public partial class Log : Form
    {

        bool logfail = true;
        public Log()
        {
            InitializeComponent();
        }

        private LogIn prevform = null;
        public Log(Form calling)
        {
            prevform = calling as LogIn;
            InitializeComponent();
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            int userid = 0;
            String query = "SELECT email, password, participatedID from individual";
            String connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist";
            SqlConnection con = new SqlConnection(connectionString);
            SqlCommand cmd = new SqlCommand(query, con);
            con.Open();
            SqlDataReader dataReader = cmd.ExecuteReader();
            while(dataReader.Read() && logfail)
            {
                if(dataReader.GetValue(0).Equals(textBox1.Text))
                {
                    if(dataReader.GetValue(1).Equals(textBox2.Text))
                    {
                        userid = (int)dataReader.GetValue(2);
                        logfail = false;
                    }
                }
            }
            con.Close();
            if (!logfail)
            {
                prevform.Close();
                this.Close();
                Program.close = true;
                Program.open = new GameDesc(userid); //pass User ID if log in was successful, otherwise tell user it was not successful
            }
            else
            {
                MessageBox.Show("Log In Failed\nNo email associated with that password");
            }
        }
    }
}
