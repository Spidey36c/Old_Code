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
    public partial class UpdateAccount : Form
    {
        int userID;
        bool founduser = false;
        bool createfail = false;
        public UpdateAccount(int id)
        {
            userID = id;
            InitializeComponent(); //populate text fields with user info
        }

        private void UpdateAccount_Load(object sender, EventArgs e)
        {
            String query = "SELECT participatedID, NAME, email, age, gender, description, phonenumber, addr, password, handle from individual";
            String connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist"; //connection string
            SqlConnection con = new SqlConnection(connectionString);
            SqlCommand cmd = new SqlCommand(query, con);
            con.Open();
            SqlDataReader dataReader = cmd.ExecuteReader();
            while (dataReader.Read() && !founduser)
            {
                if (dataReader.GetValue(0).Equals(userID)) //find user in database
                {
                    textBox5.Text = dataReader.GetString(1); //fill out users info in form
                    textBox1.Text = dataReader.GetString(2);
                    numericUpDown1.Value = dataReader.GetInt32(3);
                    if(dataReader.GetValue(4).Equals("M"))
                    {
                        comboBox1.Text = "Male";
                    }
                    else
                    {
                        comboBox1.Text = "Female";
                    }
                    textBox7.Text = dataReader.GetString(5);
                    string phonenumber = dataReader.GetString(6);
                    textBox9.Text = phonenumber.Substring(0, 3);
                    textBox4.Text = phonenumber.Substring(3, 3);
                    textBox8.Text = phonenumber.Substring(6, 4);
                    textBox6.Text = dataReader.GetString(7);
                    textBox2.Text = dataReader.GetString(8);
                    textBox3.Text = dataReader.GetString(9);
                    founduser = true;
                }
            }
            con.Close();
            if(!founduser)
            {
                MessageBox.Show("Error User ID not found");
                this.Close();
            }
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            double num1;
            if (textBox5.Text.Length == 0)
            {
                createfail = true;
                MessageBox.Show("Need Name");
            }
            if (textBox2.Text.Length == 0 && !createfail) //check if password is not empty
            {
                createfail = true;
                MessageBox.Show("Need Password");
            }
            //Check if phone number is long enough and only has numbers
            if (textBox9.Text.Length == 0 | textBox9.Text.Length != 3 | textBox4.Text.Length == 0 | textBox4.Text.Length != 3 | textBox8.Text.Length == 0 | textBox8.Text.Length != 4 && !createfail)
            {
                createfail = true;
                MessageBox.Show("Phone Number Length Incorrect");
            }
            if (!double.TryParse(textBox9.Text, out num1) | !double.TryParse(textBox4.Text, out num1) | !double.TryParse(textBox8.Text, out num1) && !createfail)
            {
                createfail = true;
                MessageBox.Show("Phone Number can only contain numbers");
            }
            if (textBox6.Text.Length == 0 && !createfail) //check if address is not empty
            {
                createfail = true;
                MessageBox.Show("Need address");
            }
            if (comboBox1.Text.Length == 0 && !createfail) //check if gender is not empty
            {
                createfail = true;
                MessageBox.Show("Need Gender");
            }
            if (!createfail)
            {
                string gender;
                string phonenumber = textBox9.Text + textBox4.Text + textBox8.Text;
                if (comboBox1.Text == "Male")
                {
                    gender = "M";
                }
                else
                {
                    gender = "F";
                }
                string query = string.Format("UPDATE individual SET NAME = \'{0}\', password = \'{1}\', age = {2}, description = \'{3}\'," +
                    " gender = \'{4}\', addr = \'{5}\', phonenumber = {6}, handle = \'{7}\' WHERE participatedID = {8}",
                    textBox5.Text, textBox2.Text, numericUpDown1.Value,textBox7.Text,gender,textBox6.Text,phonenumber,textBox3.Text,userID);
                string connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist";
                SqlConnection con = new SqlConnection(connectionString);
                SqlCommand cmd = new SqlCommand(query, con);
                cmd.Connection.Open();
                cmd.ExecuteNonQuery();
                cmd.Connection.Close();
                MessageBox.Show("Successfuly Updated Account");
                this.Close(); //Update account
            }
            else
            {
                createfail = false;
            }
        }
    }
}
