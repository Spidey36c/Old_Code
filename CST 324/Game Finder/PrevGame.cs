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
    public partial class PrevGame : Form
    { // Pass in user ID
        int userID;
        int gameID;
        bool viewgame = false;
        public PrevGame(int id) //load users previous games
        {
            userID = id;
            InitializeComponent();
        }
        public PrevGame(int id, bool game) //load specific game
        {
            gameID = id;
            viewgame = true;
            InitializeComponent();
        }
        //TODO: prev game SQL load command
        private void PrevGame_Load(Object sender, EventArgs e)
        {
            if(!viewgame)
            {
                String query = string.Format("SELECT gd.gamehost, gd.gametype, gd.gametitle, gd.gamedate FROM gamedesc as gd" +
                    " FULL OUTER JOIN participated as pd ON pd.gameID = gd.gameID WHERE pd.particpantID = {0} AND gamedate < GETDATE()", userID);
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
            else
            {
                String query = string.Format("SELECT iv.NAME, iv.handle, iv.age, iv.gender, iv.description, iv.email " +
                    "FROM individual as iv FULL OUTER JOIN participated as pd ON pd.particpantID = iv.participatedID " +
                    "WHERE pd.gameID = {0} AND pd.host = 1 UNION ALL " +
                    "SELECT iv.NAME, iv.handle, iv.age, iv.gender, iv.description, null " +
                    "FROM individual as iv FULL OUTER JOIN participated as pd ON pd.particpantID = iv.participatedID " +
                    "WHERE pd.gameID = {0} AND pd.participant = 1 UNION ALL SELECT iv.NAME, iv.handle, null, null, null, null " +
                    "FROM individual as iv FULL OUTER JOIN participated as pd ON pd.particpantID = iv.participatedID " +
                    "WHERE pd.gameID = {0} AND pd.spec = 1", gameID);
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
        }
    }
}
