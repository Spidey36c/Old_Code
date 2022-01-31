using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using Android.App;
using Android.Content;
using Android.OS;
using Android.Runtime;
using Android.Views;
using Android.Widget;
using MySql.Data.MySqlClient;
//*********************************************
//The plan trip page
//Plan a trip
//*********************************************
namespace RideOrDrive2
{
    [Activity(Label = "PlanTrip")]
    public class PlanTrip : Activity
    {

        protected override void OnCreate(Bundle savedInstanceState)
        {
            base.OnCreate(savedInstanceState);

            // Create your application here
            SetContentView(Resource.Layout.PlanTrip);

            //Cancel and go back
            var CancelButton = FindViewById<Button>(Resource.Id.Cancel);

            CancelButton.Click += (s, e) =>
            {
                Intent nextActivity = new Intent(this, typeof(DriverActivity));
                StartActivity(nextActivity);
                Finish();
            };


            //Submit Text Fields
            var SubmitButton = FindViewById<Button>(Resource.Id.Submit);
           
            SubmitButton.Click += (s, e) =>
            {
                String server = "server=184.181.99.29;user id=monty;database=5GLTE;password=9hZh4S7t";
                MySqlConnection con = new MySqlConnection(server);
                String query = "INSERT INTO Trips(StartLocation, EndLocation, Stops, ExtraDistance, Storage, DriverID, Completed, LeaveDateTime, ArriveTime, TripID) " +
                                "VALUES (@StartLocation, @EndLocation, @Stops, @ExtraDistance, @Storage, @DriverID, @Completed, @LeaveDateTime, @ArriveTime, @TripID)";
                MySqlCommand cmd = new MySqlCommand(query, con);

                con.Open();

                TextView findText = FindViewById<EditText>(Resource.Id.DepartLocation);
                string StartLocation = findText.Text;

                findText = FindViewById<EditText>(Resource.Id.ArriveLocation);
                string EndLocation = findText.Text;

                findText = FindViewById<EditText>(Resource.Id.Departuredate);
                string LeaveDateTime = findText.Text;

                findText = FindViewById<EditText>(Resource.Id.ArriveDate);
                string ArriveTime = findText.Text;

                cmd.Parameters.AddWithValue("@StartLocation", StartLocation);
                cmd.Parameters.AddWithValue("@EndLocation", EndLocation);
                cmd.Parameters.AddWithValue("@LeaveDateTime", LeaveDateTime);
                cmd.Parameters.AddWithValue("@ArriveTime", ArriveTime);
                cmd.Parameters.AddWithValue("@Stops", null);
                cmd.Parameters.AddWithValue("@ExtraDistance", null);
                cmd.Parameters.AddWithValue("@Storage", null);
                cmd.Parameters.AddWithValue("@DriverID", Globals.UserId);
                cmd.Parameters.AddWithValue("@Completed", null);
                Random gen = new Random();
                var randomNumber = gen.Next(1000000, 9999999).ToString();
                cmd.Parameters.AddWithValue("@TripID", randomNumber);
                
                cmd.ExecuteNonQuery();
                con.Close();

                Intent nextActivity = new Intent(this, typeof(DriverActivity));
                 StartActivity(nextActivity);
                 Finish();
             };
        }
    }
}