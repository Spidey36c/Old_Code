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
//Patential Trips 
//********************************************************
namespace RideOrDrive2
{

    [Activity(Label = "PotentialTrip")]
    public class PotentialTrip : Activity
    {

        protected override void OnCreate(Bundle savedInstanceState)
        {
            string start = Globals.Start;
            string end = Globals.End;
            base.OnCreate(savedInstanceState);


            SetContentView(Resource.Layout.TripView);

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

            TextView name = FindViewById<TextView>(Resource.Id.TripName);
            TextView departDate = FindViewById<TextView>(Resource.Id.DepartDate);
            TextView departTime = FindViewById<TextView>(Resource.Id.DepartTime);
            TextView arriveDate = FindViewById<TextView>(Resource.Id.ArriveDate);
            TextView arriveTime = FindViewById<TextView>(Resource.Id.ArriveTime);

            var spinner = FindViewById<Spinner>(Resource.Id.TripViewDropdown);
            String str2 = "server=184.181.99.29;user id=monty;database=5GLTE;password=9hZh4S7t";
            String query2 = "select * from TripMembers WHERE TripNum = '" + Globals.TripID + "'";

            ArrayAdapter arrayAdapter2 = new ArrayAdapter<string>(this, Android.Resource.Layout.SimpleSpinnerItem);


            var conn2 = new MySqlConnection(str2);
            MySqlDataAdapter adapter2 = new MySqlDataAdapter(query2, conn2);
            {
                ArrayList items2 = new ArrayList();
                //  var qry = "SELECT FileName FROM FileStore";
                MySqlCommandBuilder cmd2 = new MySqlCommandBuilder(adapter2);
                //conn.Open();
                //rdr = cmd.ExecuteReader();
                DataTable dt2 = new DataTable();
                adapter2.Fill(dt2);
                // spinner. = dt;
                //if (dt.)
                {
                    arrayAdapter2.Add("Members");
                    foreach (DataRow row in dt2.Rows)
                    {
                        string Cols = "";
                        Cols += (row["MemberName"].ToString());
                        //// Cols.Append(row["StartLocation"].ToString());
                        //Cols += (" to ");
                        //Cols += (row["EndLocation"].ToString());
                        arrayAdapter2.Add(Cols);


                    }
                }

                arrayAdapter2.SetDropDownViewResource(Android.Resource.Layout.SimpleSpinnerDropDownItem);
                spinner.Adapter = (arrayAdapter2);

                conn2.Close();

                spinner.DispatchSetSelected(false);  // must
                spinner.SetSelection(0, true);  //must
                                                //   spinner.Selected = false;
                spinner.ItemSelected += (object sender, AdapterView.ItemSelectedEventArgs e) =>
                {
                    int pos = e.Position;
                    String str3 = "server=184.181.99.29;user id=monty;database=5GLTE;password=9hZh4S7t";
                    String query3 = "select * from Users where UserID = '"+dt2.Rows[pos - 1]["MemberID"].ToString()+"'";
                    ArrayAdapter arrayAdapter3 = new ArrayAdapter<string>(this, Android.Resource.Layout.SimpleSpinnerItem);


                    var conn3 = new MySqlConnection(str3);
                    MySqlDataAdapter adapter3 = new MySqlDataAdapter(query3, conn3);
                    ArrayList items3 = new ArrayList();

                    MySqlCommandBuilder cmd3 = new MySqlCommandBuilder(adapter3);
                    DataTable dt3 = new DataTable();
                    adapter3.Fill(dt3);


                    Globals.ProfileFirstName = dt3.Rows[pos - 1]["FirstName"].ToString();
                    Globals.ProfileLastName = dt3.Rows[pos - 1]["LastName"].ToString();
                    Globals.ProfileEmail = dt3.Rows[pos - 1]["Email"].ToString();
                    Globals.ProfileGender = dt3.Rows[pos -1]["Gender"].ToString();
                    Globals.ProfileSalt = dt3.Rows[pos - 1]["Salt"].ToString();
                    Globals.ProfileID = dt3.Rows[pos - 1]["UserID"].ToString();
                    Globals.TripID = (int)dt2.Rows[pos - 1]["TripNum"];
                    Intent nextActivity = new Intent(this, typeof(OtherUserProfile));
                    StartActivity(nextActivity);
                    Finish();

                };


                // name.SetText(Globals.Start + " to " + Globals.End);
                name.Text = (Globals.Start + " to " + Globals.End);
                departDate.Text = Globals.LeaveDate;
                departTime.Text = Globals.LeaveTime;
                arriveDate.Text = Globals.ArriveDate;
                arriveTime.Text = Globals.ArriveTime;
                Button RequestButton = FindViewById<Button>(Resource.Id.RequestTrip);
                RequestButton.Click += (s, e) =>
                {
                    String str = "server=184.181.99.29;user id=monty;database=5GLTE;password=9hZh4S7t";
                    String query = "INSERT INTO Requests(TripNum, RequestorID, RequestorName) VALUES " +
                    "('" + Globals.TripID + "','" + Globals.UserId + "', '" + Globals.UserName + "')";
                    var conn = new MySqlConnection(str);
                    conn.Open();
                    MySqlCommand cmd = new MySqlCommand(query, conn);
                    cmd.ExecuteNonQuery();
                    conn.Close();
                };

            }
        }
    }
}