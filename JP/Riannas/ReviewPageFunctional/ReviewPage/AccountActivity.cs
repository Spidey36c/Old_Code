using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using Android.App;
using Android.Content;
using Android.OS;
using Android.Runtime;
using Android.Views;
using Android.Widget;

using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Threading.Tasks;
using MySql.Data.MySqlClient;
//********************************************************
//Account Creation Page
//Account Creation stuff
//********************************************************
namespace RideOrDrive2
{
    [Activity(Label = "AccountActivity")]

    public class AccountActivity : Activity
    {
        private int m_gender;
        protected override void OnCreate(Bundle savedInstanceState)
        {
            base.OnCreate(savedInstanceState);

            // Create your application here
            SetContentView(Resource.Layout.account_creation);

            var bCreate = FindViewById<Button>(Resource.Id.bCreate);

            bCreate.Click += (s, e) =>
            {
                Intent nextActivity = new Intent(this, typeof(Login));
                StartActivity(nextActivity);

                String server = "server=184.181.99.29;user id=monty;database=5GLTE;password=9hZh4S7t"; 
                MySqlConnection con = new MySqlConnection(server);
                String query = "INSERT INTO Users(FirstName, LastName, LicensePlate, UserID, ReviewScore, Gender, Location, Phone, Email) " +
                                "VALUES (@FirstName, @LastName, @LicensePlate, @UserID, @ReviewScore, @Gender, @Location, @Phone, @Email )";
                MySqlCommand cmd = new MySqlCommand(query, con);

                con.Open();

                TextView findText = FindViewById<EditText>(Resource.Id.eFname);
                string fName = findText.Text;

                findText = FindViewById<EditText>(Resource.Id.eLname);
                string lName = findText.Text;

                findText = FindViewById<EditText>(Resource.Id.eID);
                string UserID = findText.Text;

                findText = FindViewById<EditText>(Resource.Id.eMail);
                string Email = findText.Text;

                RadioButton radio_male = FindViewById<RadioButton>(Resource.Id.rMale);
                RadioButton radio_female = FindViewById<RadioButton>(Resource.Id.rFemale);
                RadioButton radio_other = FindViewById<RadioButton>(Resource.Id.rNon_Binary);

                radio_male.Click += RadioButtonClick;
                radio_female.Click += RadioButtonClick;
                radio_other.Click += RadioButtonClick;


                cmd.Parameters.AddWithValue("@FirstName", fName);
                cmd.Parameters.AddWithValue("@LastName", lName);
                cmd.Parameters.AddWithValue("@LicensePlate", null);
                cmd.Parameters.AddWithValue("@UserID", UserID);
                cmd.Parameters.AddWithValue("@ReviewScore", null);
                cmd.Parameters.AddWithValue("@Gender", m_gender);
                cmd.Parameters.AddWithValue("@Location", null);
                cmd.Parameters.AddWithValue("@Phone", null);
                cmd.Parameters.AddWithValue("@Email", Email);

                cmd.ExecuteNonQuery();
                con.Close();
            };

            var bBack = FindViewById<Button>(Resource.Id.bBack);

            bBack.Click += (s, e) =>
            {
                Intent nextActivity = new Intent(this, typeof(Login));
                StartActivity(nextActivity);
            };

            var spinner = FindViewById<Spinner>(Resource.Id.TripDropdown);

        }
        private void RadioButtonClick(object sender, EventArgs e)
        {
            RadioButton rb = (RadioButton)sender;
            if (rb.Text == "Male")
            {
                m_gender = 0;
            }
            else if(rb.Text == "Female")
            {
                m_gender = 1;
            }
            else
            {
                m_gender = 2;
            }
        }

    }
}