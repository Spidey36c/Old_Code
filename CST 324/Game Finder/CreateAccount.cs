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
    public partial class CreateAccount : Form
    {
        bool createfail = false;
        public CreateAccount()
        {
            InitializeComponent();
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            double num1;
            if(textBox9.Text.Length == 0)
            {
                createfail = true;
                MessageBox.Show("Need Name");
            }
            if (textBox1.Text.Length == 0 && !createfail) //check if email is not empty
            {
                createfail = true;
                MessageBox.Show("Need Email");
            }
            if (textBox2.Text.Length == 0 && !createfail) //check if password is not empty
            {
                createfail = true;
                MessageBox.Show("Need Password");
            }
            //Check if phone number is long enough and only has numbers
            if (textBox4.Text.Length == 0 | textBox4.Text.Length != 3 | textBox5.Text.Length == 0 | textBox5.Text.Length != 3 | textBox8.Text.Length == 0 | textBox8.Text.Length != 4 && !createfail)
            {
                createfail = true;
                MessageBox.Show("Phone Number Length Incorrect");
            }
            if (!double.TryParse(textBox4.Text, out num1) | !double.TryParse(textBox5.Text, out num1) | !double.TryParse(textBox5.Text, out num1) && !createfail)
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
                String query = "SELECT email FROM individual";
                String connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist";
                SqlConnection con = new SqlConnection(connectionString);
                SqlCommand cmd = new SqlCommand(query, con);
                con.Open();
                SqlDataReader dataReader = cmd.ExecuteReader();
                while(dataReader.Read())
                {
                    if(dataReader.GetValue(0).Equals(textBox1.Text))
                    {
                        createfail = true;
                        MessageBox.Show("User with that Email already exists");
                    }
                }
                con.Close();
                if (!createfail)
                {
                    string gender;
                    string phonenumber = textBox4.Text + textBox5.Text + textBox8.Text;
                    if(comboBox1.Text == "Male")
                    {
                        gender = "M";
                    }
                    else
                    {
                        gender = "F";
                    }
                    query = string.Format("INSERT INTO individual(NAME,handle,age,gender,description,participatedID,email,phonenumber,addr,discount," +
                        "password)VALUES(\'{0}\', \'{1}\', {2}, \'{3}\', \'{4}\', NEXT VALUE FOR part_id, \'{5}\', {6}, \'{7}\', 0, \'{8}\')",
                            textBox9.Text, textBox3.Text,numericUpDown1.Value, gender, textBox7.Text, textBox1.Text,phonenumber,textBox6.Text,textBox2.Text);
                    connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist";
                    con = new SqlConnection(connectionString);
                    cmd = new SqlCommand(query, con);
                    cmd.Connection.Open();
                    cmd.ExecuteNonQuery();
                    cmd.Connection.Close();
                    MessageBox.Show("Successfuly Created Account");
                    this.Close(); //insert into individual table if user does not already exist, and generate user ID
                }
            }
            else
            {
                createfail = false;
            }
        }
    }
}
