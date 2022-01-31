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
    public partial class GameDesc : Form
    {
        int userid;
        public GameDesc(int user_ID)
        {
            userid = user_ID;
            InitializeComponent();
        }

        private void GameDesc_Load(object sender, EventArgs e)
        {
            String query = "SELECT * from gamedesc WHERE gamedate >= GETDATE()";
            String connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist";
            SqlConnection con = new SqlConnection(connectionString);
            SqlDataAdapter adapter = new SqlDataAdapter(query, con);
            SqlCommandBuilder sqlBuilder = new SqlCommandBuilder(adapter);
            con.Open();
            DataTable dt = new DataTable();
            adapter.Fill(dt);
            dataGridView1.DataSource = dt; //fill datagridview with data from gamedesc table
            con.Close();
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            bool failed = false;
            if(comboBox1.Text.Length == 0)
            {
                MessageBox.Show("Need to select what is being done");
                failed = true;
            }
            if(textBox1.Text.Length == 0 & !failed)
            {
                MessageBox.Show("Need to enter a game ID");
                failed = true;
            }
            if (comboBox2.Visible)
            {
                if (comboBox2.Text.Length == 0 & !failed)
                {
                    MessageBox.Show("Need to choose what to join as");
                    failed = true;
                }
            }
            if (!failed)
            {
                failed = true;
                String query = "SELECT gameID from gamedesc";
                String connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist"; //connection string
                SqlConnection con = new SqlConnection(connectionString);
                SqlCommand cmd = new SqlCommand(query, con);
                con.Open();
                SqlDataReader dataReader = cmd.ExecuteReader();
                while (dataReader.Read())
                {
                    if (dataReader.GetInt32(0).Equals(textBox1.Text))
                    {
                        failed = false;
                    }
                }
                con.Close();
                if(!failed)
                {
                    query = "SELECT gameID from gamedesc WHERE gamedate < GETDATE()";
                    connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist"; //connection string
                    con = new SqlConnection(connectionString);
                    cmd = new SqlCommand(query, con);
                    con.Open();
                    dataReader = cmd.ExecuteReader();
                    while (dataReader.Read() && !failed)
                    {
                        if (dataReader.GetInt32(0).Equals(textBox1.Text))
                        {
                            failed = true;
                        }
                    }
                    con.Close();
                }
                if (!failed)
                {
                    int current = 0;
                    string cost = null;
                    switch (comboBox1.Text)
                    {
                        case "Join":
                            if(comboBox2.Text == "Spectator")
                            {
                                query = string.Format("SELECT currentspec, specmax from gamedesc WHERE gameID = {0}",textBox1.Text);
                                connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist"; //connection string
                                con = new SqlConnection(connectionString);
                                cmd = new SqlCommand(query, con);
                                con.Open();
                                dataReader = cmd.ExecuteReader();
                                while (dataReader.Read())
                                {
                                    current = dataReader.GetInt32(0);
                                    if (dataReader.GetInt32(0).Equals(dataReader.GetInt32(1)))
                                    {
                                        failed = true;
                                        MessageBox.Show("Spectators are currently full");
                                    }
                                }
                                con.Close();
                                if(!failed)
                                {
                                    query = string.Format("SELECT particpantID from participated WHERE gameID = {0}", textBox1.Text);
                                    connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist"; //connection string
                                    con = new SqlConnection(connectionString);
                                    cmd = new SqlCommand(query, con);
                                    con.Open();
                                    dataReader = cmd.ExecuteReader();
                                    while (dataReader.Read() && !failed)
                                    {
                                        if (dataReader.GetInt32(0).Equals(userid))
                                        {
                                            failed = true;
                                            MessageBox.Show("You are already a part of this game");
                                        }
                                    }
                                    con.Close();
                                    if(!failed)
                                    {
                                        query = string.Format("SELECT speccost from gamedesc WHERE gameID = {0}", textBox1.Text);
                                        connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist"; //connection string
                                        con = new SqlConnection(connectionString);
                                        cmd = new SqlCommand(query, con);
                                        con.Open();
                                        dataReader = cmd.ExecuteReader();
                                        while (dataReader.Read() && !failed)
                                        {
                                            cost = dataReader.GetString(0);
                                        }
                                        con.Close();
                                        query = string.Format("UPDATE gamedesc SET currentspec = {0} WHERE gameID = {1}",current++, textBox1.Text);
                                        connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist"; //connection string
                                        con = new SqlConnection(connectionString);
                                        cmd = new SqlCommand(query, con);
                                        cmd.Connection.Open();
                                        cmd.ExecuteNonQuery();
                                        cmd.Connection.Close();
                                        query = string.Format("INSERT INTO participated(particpantID,gameID,host,participant,spec) " +
                                            "VALUES({0},{1},0,0,1)", userid,textBox1.Text);
                                        connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist"; //connection string
                                        con = new SqlConnection(connectionString);
                                        cmd = new SqlCommand(query, con);
                                        cmd.Connection.Open();
                                        cmd.ExecuteNonQuery();
                                        cmd.Connection.Close();
                                        MessageBox.Show(string.Format("Successfully joined {0} at the price of {1}", textBox1.Text, cost));
                                    }
                                }
                            }
                            else
                            {
                                int discount = 0;
                                query = string.Format("SELECT currentpart, participantsmax from gamedesc WHERE gameID = {0}", textBox1.Text);
                                connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist"; //connection string
                                con = new SqlConnection(connectionString);
                                cmd = new SqlCommand(query, con);
                                con.Open();
                                dataReader = cmd.ExecuteReader();
                                while (dataReader.Read())
                                {
                                    current = dataReader.GetInt32(0);
                                    if (dataReader.GetInt32(0).Equals(dataReader.GetInt32(1)))
                                    {
                                        failed = true;
                                        MessageBox.Show("Participants are currently full");
                                    }
                                }
                                con.Close();
                                if (!failed)
                                {
                                    query = string.Format("SELECT particpantID from participated WHERE gameID = {0}", textBox1.Text);
                                    connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist"; //connection string
                                    con = new SqlConnection(connectionString);
                                    cmd = new SqlCommand(query, con);
                                    con.Open();
                                    dataReader = cmd.ExecuteReader();
                                    while (dataReader.Read() && !failed)
                                    {
                                        if (dataReader.GetInt32(0).Equals(userid))
                                        {
                                            failed = true;
                                            MessageBox.Show("You are already a part of this game");
                                        }
                                    }
                                    con.Close();
                                    if (!failed)
                                    {
                                        query = string.Format("SELECT participantscost from gamedesc WHERE gameID = {0}", textBox1.Text);
                                        connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist"; //connection string
                                        con = new SqlConnection(connectionString);
                                        cmd = new SqlCommand(query, con);
                                        con.Open();
                                        dataReader = cmd.ExecuteReader();
                                        while (dataReader.Read() && !failed)
                                        {
                                            cost = dataReader.GetString(0);
                                        }
                                        con.Close();
                                        if(Int32.Parse(cost.Substring(1)) > 0)
                                        {
                                            query = string.Format("SELECT discount from invdividual WHERE participatedID = {0}", userid);
                                            connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist"; //connection string
                                            con = new SqlConnection(connectionString);
                                            cmd = new SqlCommand(query, con);
                                            con.Open();
                                            dataReader = cmd.ExecuteReader();
                                            while (dataReader.Read())
                                            {
                                                discount = dataReader.GetInt32(0);
                                            }
                                            con.Close();
                                            if(discount != 11)
                                            {
                                                discount++;
                                                query = string.Format("UPDATE individual SET discount = {0} WHERE participantID = {1}", discount, userid);
                                                connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist"; //connection string
                                                con = new SqlConnection(connectionString);
                                                cmd = new SqlCommand(query, con);
                                                cmd.Connection.Open();
                                                cmd.ExecuteNonQuery();
                                                cmd.Connection.Close();
                                            }
                                        }
                                        query = string.Format("UPDATE gamedesc SET currentpart = {0} WHERE gameID = {1}", current++, textBox1.Text);
                                        connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist"; //connection string
                                        con = new SqlConnection(connectionString);
                                        cmd = new SqlCommand(query, con);
                                        cmd.Connection.Open();
                                        cmd.ExecuteNonQuery();
                                        cmd.Connection.Close();
                                        query = string.Format("INSERT INTO participated(particpantID,gameID,host,participant,spec) " +
                                            "VALUES({0},{1},0,1,0)", userid, textBox1.Text);
                                        connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist"; //connection string
                                        con = new SqlConnection(connectionString);
                                        cmd = new SqlCommand(query, con);
                                        cmd.Connection.Open();
                                        cmd.ExecuteNonQuery();
                                        cmd.Connection.Close();
                                        if (discount != 10)
                                        {
                                            MessageBox.Show(string.Format("Successfully joined {0} at the price of {1}", textBox1.Text, cost));
                                        }
                                        else
                                        {
                                            MessageBox.Show(string.Format("Successfully joined {0} at the price of {1}", textBox1.Text, Double.Parse(cost.Substring(1)) - (Double.Parse(cost.Substring(1)) * .1)));
                                        }
                                    }
                                }
                            }
                            break;
                        case "Leave":
                            query = string.Format("SELECT particpantID from participated WHERE gameID = {0}", textBox1.Text);
                            connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist"; //connection string
                            con = new SqlConnection(connectionString);
                            cmd = new SqlCommand(query, con);
                            con.Open();
                            dataReader = cmd.ExecuteReader();
                            failed = true;
                            while (dataReader.Read() && failed)
                            {
                                if(dataReader.GetInt32(0) == userid)
                                {
                                    failed = false;
                                }
                            }
                            con.Close();
                            if (!failed)
                            {
                                query = string.Format("SELECT host from participated WHERE gameID = {0} AND particpantID = {1}", textBox1.Text, userid);
                                connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist"; //connection string
                                con = new SqlConnection(connectionString);
                                cmd = new SqlCommand(query, con);
                                con.Open();
                                dataReader = cmd.ExecuteReader();
                                failed = true;
                                while (dataReader.Read() && !failed)
                                {
                                    if (dataReader.GetInt32(0) == 1)
                                    {
                                        failed = true;
                                        MessageBox.Show("Hosts are not allowed to leave their own game");
                                    }
                                }
                                con.Close();
                                if(!failed)
                                {
                                    bool participant = false;
                                    query = string.Format("SELECT participant from participated WHERE gameID = {0} AND particpantID = {1}", textBox1.Text, userid);
                                    connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist"; //connection string
                                    con = new SqlConnection(connectionString);
                                    cmd = new SqlCommand(query, con);
                                    con.Open();
                                    dataReader = cmd.ExecuteReader();
                                    failed = true;
                                    while (dataReader.Read())
                                    {
                                        if (dataReader.GetInt32(0) == 1)
                                        {
                                            participant = true;
                                        }
                                    }
                                    if (!participant)
                                    {
                                        query = string.Format("SELECT currentspec from gamedesc WHERE gameID = {0}", textBox1.Text);
                                        connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist"; //connection string
                                        con = new SqlConnection(connectionString);
                                        cmd = new SqlCommand(query, con);
                                        con.Open();
                                        dataReader = cmd.ExecuteReader();
                                        failed = true;
                                        while (dataReader.Read())
                                        {
                                            current = dataReader.GetInt32(0);
                                        }
                                        query = string.Format("UPDATE gamedesc SET currentspec = {0} WHERE gameID = {1}", current--, textBox1.Text);
                                        connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist"; //connection string
                                        con = new SqlConnection(connectionString);
                                        cmd = new SqlCommand(query, con);
                                        cmd.Connection.Open();
                                        cmd.ExecuteNonQuery();
                                        cmd.Connection.Close();
                                        query = string.Format("DELETE FROM participated " +
                                           "WHERE particpantID = {0} AND gameID = {1}", userid, textBox1.Text);
                                        connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist"; //connection string
                                        con = new SqlConnection(connectionString);
                                        cmd = new SqlCommand(query, con);
                                        cmd.Connection.Open();
                                        cmd.ExecuteNonQuery();
                                        cmd.Connection.Close();
                                    }
                                    else
                                    {
                                        int discount = 0;
                                        query = string.Format("SELECT currentpart from gamedesc WHERE gameID = {0}", textBox1.Text);
                                        connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist"; //connection string
                                        con = new SqlConnection(connectionString);
                                        cmd = new SqlCommand(query, con);
                                        con.Open();
                                        dataReader = cmd.ExecuteReader();
                                        failed = true;
                                        while (dataReader.Read())
                                        {
                                            current = dataReader.GetInt32(0);
                                        }
                                        query = string.Format("UPDATE gamedesc SET currentspec = {0} WHERE gameID = {1}", current--, textBox1.Text);
                                        connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist"; //connection string
                                        con = new SqlConnection(connectionString);
                                        cmd = new SqlCommand(query, con);
                                        cmd.Connection.Open();
                                        cmd.ExecuteNonQuery();
                                        cmd.Connection.Close();
                                        query = string.Format("DELETE FROM participated " +
                                           "WHERE particpantID = {0} AND gameID = {1}", userid, textBox1.Text);
                                        connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist"; //connection string
                                        con = new SqlConnection(connectionString);
                                        cmd = new SqlCommand(query, con);
                                        cmd.Connection.Open();
                                        cmd.ExecuteNonQuery();
                                        cmd.Connection.Close();
                                        query = string.Format("SELECT discount from invdividual WHERE participatedID = {0}", userid);
                                        connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist"; //connection string
                                        con = new SqlConnection(connectionString);
                                        cmd = new SqlCommand(query, con);
                                        con.Open();
                                        dataReader = cmd.ExecuteReader();
                                        while (dataReader.Read())
                                        {
                                            discount = dataReader.GetInt32(0);
                                        }
                                        con.Close();
                                        if (discount != 11)
                                        {
                                            discount--;
                                            query = string.Format("UPDATE individual SET discount = {0} WHERE participantID = {1}", discount, userid);
                                            connectionString = "server=aura.cset.oit.edu,5433;database=jamesnordquist;UID=jamesnordquist;password=jamesnordquist"; //connection string
                                            con = new SqlConnection(connectionString);
                                            cmd = new SqlCommand(query, con);
                                            cmd.Connection.Open();
                                            cmd.ExecuteNonQuery();
                                            cmd.Connection.Close();
                                        }
                                    }

                                }
                            }
                            else
                            {
                                MessageBox.Show("You are not apart of this game");
                            }
                            break;
                        case "View":
                            PrevGame m = new PrevGame(Int32.Parse(textBox1.Text), true);
                            m.Show();
                            break;
                    }
                }
                else
                {
                    MessageBox.Show("Game ID Invalid\nDoes not exist or GameID references game that already took place");
                }
            }
            failed = false;
            //todo: add fail state to non existant game ID
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            GameCreate m = new GameCreate(userid);
            m.Show();
        }

        private void Button3_Click(object sender, EventArgs e)
        {
            PrevGame m = new PrevGame(userid);
            m.Show();
        }

        private void Button4_Click(object sender, EventArgs e)
        {
            UpdateAccount m = new UpdateAccount(userid);
            m.Show();
        }

        private void ComboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch(comboBox1.Text)
            {
                case "Join":
                    label2.Visible = true;
                    comboBox2.Visible = true;
                    break;
                case "Leave":
                    label2.Visible = false;
                    comboBox2.Visible = false;
                    break;
                case "View":
                    label2.Visible = false;
                    comboBox2.Visible = false;
                    break;
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            GameDesc_Load(sender,e);
        }
    }
}
