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


namespace RideOrDrive2
{
    [Activity(Label = "OtherUserProfile")]
    class OtherUserProfile : Activity
    {
        protected override void OnCreate(Bundle savedInstanceState)
        {
            string Name = Globals.ProfileFirstName + " " + Globals.ProfileLastName;
            string Gender = Globals.ProfileGender;
            string Email = Globals.ProfileEmail;
            string Salt = Globals.ProfileSalt;

            base.OnCreate(savedInstanceState);


            SetContentView(Resource.Layout.OtherUserProfile);

            var DriverButton = FindViewById<Button>(Resource.Id.DriverButton);


            DriverButton.Click += (s, e) =>
            {
                Intent nextActivity = new Intent(this, typeof(DriverActivity));
                StartActivity(nextActivity);
                Finish();
            };

            var MapButton = FindViewById<Button>(Resource.Id.MapButton);

            MapButton.Click += (s, e) =>
            {
                Intent nextActivity = new Intent(this, typeof(MapActivity));
                StartActivity(nextActivity);
                Finish();
            };

            TextView name = FindViewById<TextView>(Resource.Id.Name);
            TextView email = FindViewById<TextView>(Resource.Id.Email);
            TextView gender = FindViewById<TextView>(Resource.Id.Gender);
            TextView salt = FindViewById<TextView>(Resource.Id.Salt);
            
            // name.SetText(Globals.Start + " to " + Globals.End);
            name.Text = Name;
            email.Text = Email;
            gender.Text = Gender;
            salt.Text = Salt;
            Button ReviewButton = FindViewById<Button>(Resource.Id.ReviewUser);
            ReviewButton.Click += (s, e) =>
            {
                Intent nextActivity = new Intent(this, typeof(ReviewPage));
                StartActivity(nextActivity);
                Finish();
            };
            Button AcceptButton = FindViewById<Button>(Resource.Id.AcceptRider);
            AcceptButton.Click += (s, e) =>
            {
                String str = "server=184.181.99.29;user id=monty;database=5GLTE;password=9hZh4S7t";
                String query = "INSERT INTO TripMembers(TripNum, MemberID, MemberName, DriverName, DriverID) VALUES " +
                "('" + Globals.TripID + "', '"+Globals.ProfileID+ "', '" + Name + "',  '" + Globals.UserName + "', '" + Globals.UserId + "')";
                var conn = new MySqlConnection(str);
                conn.Open();
                MySqlCommand cmd = new MySqlCommand(query, conn);
                cmd.ExecuteNonQuery();
                conn.Close();
            };

            Button RejectButton = FindViewById<Button>(Resource.Id.RejectRider);
            RejectButton.Click += (s, e) =>
            {

            };

        }
    }
}