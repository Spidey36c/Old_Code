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
    public partial class GameCreate : Form
    {
        int userID;
        bool createfail = false;
        bool founduser = false;
        public GameCreate(int id)
        {
            userID = id;
            InitializeComponent();
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            double num1;
            if (textBox1.Text.Length == 0) // check if game type is not empty
            {
                createfail = true;
                MessageBox.Show("Need Game Type");
            }
            if (textBox2.Text.Length == 0 && !createfail) //check if game title is not empty
            {
                createfail = true;
                MessageBox.Show("Need Game Title");
            }
            if (textBox4.Text.Length == 0 && !createfail) //check if location is not empty
            {
                createfail = true;
                MessageBox.Show("Need Location");
            }
            if (textBox5.Text.Length == 0 && !createfail) //check if duration is not empty
            {
                createfail = true;
                MessageBox.Show("Need Duration");
            }
            if(numericUpDown2.Value < numericUpDown1.Value && !createfail) //check max greater than min
            {
                createfail = true;
                MessageBox.Show("Participants Max needs to be larger than Participants Min");
            }
            if (numericUpDown3.Value < numericUpDown4.Value && !createfail)
            {
                createfail = true;
                MessageBox.Show("Spectators Max needs to be larger than Spectators Min");
            }
            if (!double.TryParse(textBox9.Text, out num1) | !double.TryParse(textBox10.Text, out num1) && !createfail) //make sure cost is number
            {
                createfail = true;
                MessageBox.Show("Cost can only contain numbers");
            }
            if (textBox9.Text.Length == 0) //make sure default is 0
            {
                textBox9.Text = "0";
            }
            if(textBox10.Text.Length == 0)
            {
                textBox10.Text = "0";
            }
            if (!createfail)
            {
                string username = null;
                int currentgameid = 0;
                String query = "SELECT participatedID, NAME from individual";
                String connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist"; //connection string
                SqlConnection con = new SqlConnection(connectionString);
                SqlCommand cmd = new SqlCommand(query, con);
                con.Open();
                SqlDataReader dataReader = cmd.ExecuteReader();
                while (dataReader.Read() && !founduser)
                {
                    if(dataReader.GetInt32(0).Equals(userID))
                    {
                        username = dataReader.GetString(1);
                    }
                }
                con.Close();
                string date = numericUpDown7.Value.ToString() + "-" + numericUpDown6.Value.ToString() + "-" + numericUpDown5.Value.ToString();
                query = string.Format("INSERT INTO gamedesc(gameID, gametype, gametitle,gamedesc, gamelocation, gamedate, gameduration, gamehost, " +
                    "gamehostcost, participantsmin, participantsmax, currentpart, participantscost, specmin,specmax, currentspec, speccost) VALUES(" +
                    "NEXT VALUE FOR game_seq,\'{0}\',\'{1}\',\'{2}\',\'{3}\',\'{4}\', \'{5}\', \'{6}\', 0, {7}, {8}, 0, \'{9}\', {10}, {11}, 0, \'{12}\')",
                    textBox1.Text,textBox2.Text,textBox3.Text,textBox4.Text,date,textBox5.Text,username,numericUpDown1.Value,numericUpDown2.Value, "$"+textBox9.Text,
                    numericUpDown4.Value,numericUpDown3.Value, "$"+textBox10.Text);
                connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist";
                con = new SqlConnection(connectionString);
                cmd = new SqlCommand(query, con);
                cmd.Connection.Open();
                cmd.ExecuteNonQuery();
                cmd.Connection.Close();
                query = "SELECT CAST(current_value as int) from sys.sequences WHERE name = \'game_seq\'";
                connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist"; //connection string
                con = new SqlConnection(connectionString);
                cmd = new SqlCommand(query, con);
                con.Open();
                dataReader = cmd.ExecuteReader();
                while (dataReader.Read())
                {
                    currentgameid = dataReader.GetInt32(0);
                }
                con.Close();
                query = string.Format("INSERT INTO participated(particpantID, gameID, host, participant,spec)" +
                    "VALUES ({0},{1},1,0,0)",userID,currentgameid);
                connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist";
                con = new SqlConnection(connectionString);
                cmd = new SqlCommand(query, con);
                cmd.Connection.Open();
                cmd.ExecuteNonQuery();
                cmd.Connection.Close();
                MessageBox.Show("Successfuly Created Game");
                this.Close(); //insert into game table
            }
            else
            {
                createfail = false;
            }
        }
    }
}
