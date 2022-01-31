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
//*********************************************
//The Edit trip page
//Edit a trip
//*********************************************
namespace RideOrDrive2
{
    [Activity(Label = "EditTrip")]
    public class EditTrip : Activity
    {

        protected override void OnCreate(Bundle savedInstanceState)
        {
            base.OnCreate(savedInstanceState);

            // Create your application here
            SetContentView(Resource.Layout.EditTrip);

            //Cancel and go back
            var CancelButton = FindViewById<Button>(Resource.Id.Cancel);

            CancelButton.Click += (s, e) =>
            {
                Intent nextActivity = new Intent(this, typeof(DriverActivity));
                StartActivity(nextActivity);
                Finish();
            };


            //Submit Text Fields
            var spinner = FindViewById<Spinner>(Resource.Id.DriverTripDropdown);
            //  spinner.ItemSelected += new EventHandler<AdapterView.ItemSelectedEventArgs>(spinner_ItemSelected);
            //This causes item to be automatically selected and transfers to potential trip page, it is commented out just so demo is smoother


            {

                String str = "server=184.181.99.29;user id=monty;database=5GLTE;password=9hZh4S7t";
                String query = "select * from Trips where DriverID = '"+Globals.UserId+"'";

                ArrayAdapter arrayAdapter = new ArrayAdapter<string>(this, Android.Resource.Layout.SimpleSpinnerItem);


                var conn = new MySqlConnection(str);
                MySqlDataAdapter adapter = new MySqlDataAdapter(query, conn);
                {
                    ArrayList items = new ArrayList();
                    //  var qry = "SELECT FileName FROM FileStore";
                    MySqlCommandBuilder cmd = new MySqlCommandBuilder(adapter);
                    //conn.Open();
                    //rdr = cmd.ExecuteReader();
                    DataTable dt = new DataTable();
                    adapter.Fill(dt);
                    // spinner. = dt;
                    //if (dt.)
                    {
                        arrayAdapter.Add("Current Trips");
                        foreach (DataRow row in dt.Rows)
                        {
                            string Cols = "";
                            Cols += (row["StartLocation"].ToString());
                            // Cols.Append(row["StartLocation"].ToString());
                            Cols += (" to ");
                            Cols += (row["EndLocation"].ToString());
                            arrayAdapter.Add(Cols);


                        }
                    }

                    arrayAdapter.SetDropDownViewResource(Android.Resource.Layout.SimpleSpinnerDropDownItem);
                    spinner.Adapter = (arrayAdapter);

                    conn.Close();

                    spinner.DispatchSetSelected(false);  // must
                    spinner.SetSelection(0, true);  //must
                                                    //   spinner.Selected = false;
                    spinner.ItemSelected += (object sender, AdapterView.ItemSelectedEventArgs e) =>
                    {
                        int pos = e.Position - 1;

                        Globals.Start = dt.Rows[pos]["StartLocation"].ToString();
                        Globals.End = dt.Rows[pos]["EndLocation"].ToString();
                        Globals.ArriveDate = dt.Rows[pos]["ArriveTime"].ToString().Substring(0, 10);
                        Globals.ArriveTime = dt.Rows[pos]["ArriveTime"].ToString().Substring(9, 8);
                        Globals.LeaveDate = dt.Rows[pos]["LeaveDateTime"].ToString().Substring(0, 10);
                        Globals.LeaveTime = dt.Rows[pos]["LeaveDateTime"].ToString().Substring(9, 8);
                        Globals.TripID = (int)dt.Rows[pos]["TripID"];
                        Intent nextActivity = new Intent(this, typeof(PotentialTrip));
                        //StartActivity(nextActivity);
                        //Finish();
                        TextView findText = FindViewById<EditText>(Resource.Id.DepartLocation);
                        findText.Text = Globals.Start;

                        findText = FindViewById<EditText>(Resource.Id.ArriveLocation);
                        findText.Text = Globals.End;

                        findText = FindViewById<EditText>(Resource.Id.Departuredate);
                       findText.Text = Globals.LeaveDate;

                        findText = FindViewById<EditText>(Resource.Id.ArriveDate);
                        findText.Text = Globals.ArriveDate;
                    };

                    var SubmitButton = FindViewById<Button>(Resource.Id.Submit);

                    SubmitButton.Click += (s, e) =>
                    {
                        String server = "server=184.181.99.29;user id=monty;database=5GLTE;password=9hZh4S7t";
                        MySqlConnection con = new MySqlConnection(server);
                        String query3 = "DELETE FROM Trips WHERE TripID = '"+Globals.TripID+"'";
                        MySqlCommand cmd3 = new MySqlCommand(query3, con);

                        String query2 = "INSERT INTO Trips(StartLocation, EndLocation, Stops, ExtraDistance, Storage, DriverID, Completed, LeaveDateTime, ArriveTime, TripID) " +
                                        "VALUES (@StartLocation, @EndLocation, @Stops, @ExtraDistance, @Storage, @DriverID, @Completed, @LeaveDateTime, @ArriveTime, @TripID)";
                        MySqlCommand cmd2 = new MySqlCommand(query2, con);
                        con.Open();

                        TextView findText = FindViewById<EditText>(Resource.Id.DepartLocation);
                        string StartLocation = findText.Text;

                        findText = FindViewById<EditText>(Resource.Id.ArriveLocation);
                        string EndLocation = findText.Text;

                        findText = FindViewById<EditText>(Resource.Id.Departuredate);
                        string LeaveDateTime = findText.Text;

                        findText = FindViewById<EditText>(Resource.Id.ArriveDate);
                        string ArriveTime = findText.Text;

                        cmd2.Parameters.AddWithValue("@StartLocation", StartLocation);
                        cmd2.Parameters.AddWithValue("@EndLocation", EndLocation);
                        cmd2.Parameters.AddWithValue("@LeaveDateTime", LeaveDateTime);
                        cmd2.Parameters.AddWithValue("@ArriveTime", ArriveTime);
                        cmd2.Parameters.AddWithValue("@Stops", null);
                        cmd2.Parameters.AddWithValue("@ExtraDistance", null);
                        cmd2.Parameters.AddWithValue("@Storage", null);
                        cmd2.Parameters.AddWithValue("@DriverID", Globals.UserId);
                        cmd2.Parameters.AddWithValue("@Completed", null);
                        Random gen = new Random();
                        var randomNumber = gen.Next(1000000, 9999999).ToString();
                        cmd2.Parameters.AddWithValue("@TripID", randomNumber);

                        cmd3.ExecuteNonQuery();
                        cmd2.ExecuteNonQuery();
                        con.Close();

                        Intent nextActivity = new Intent(this, typeof(DriverActivity));
                        StartActivity(nextActivity);
                        Finish();
                    };
                    // spinner.setOnItemSelectedListener(this);
                }
            };
        }
    }
}