
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
//Rider page
//Rider Stuff
//********************************************************
namespace RideOrDrive2
{
  //  [Activity(Label = "Globals")]
    public static class Globals 
    {
        private static string profileFirstName;
        public static string ProfileFirstName
        {
            get
            {
                // Reads are usually simple
                return profileFirstName;
            }
            set
            {
                // You can add logic here for race conditions,
                // or other measurements
                profileFirstName = value;
            }
        }
        private static string profileLastName;
        public static string ProfileLastName
        {
            get
            {
                // Reads are usually simple
                return profileLastName;
            }
            set
            {
                // You can add logic here for race conditions,
                // or other measurements
                profileLastName = value;
            }
        }


        private static string profileEmail;
        public static string ProfileEmail
        {
            get
            {
                // Reads are usually simple
                return profileEmail;
            }
            set
            {
                // You can add logic here for race conditions,
                // or other measurements
                profileEmail = value;
            }
        }

        private static string profileSalt;
        public static string ProfileSalt
        {
            get
            {
                // Reads are usually simple
                return profileSalt;
            }
            set
            {
                // You can add logic here for race conditions,
                // or other measurements
                profileSalt = value;
            }
        }
        private static string profileAge;
        public static string ProfileAge
        {
            get
            {
                // Reads are usually simple
                return profileAge;
            }
            set
            {
                // You can add logic here for race conditions,
                // or other measurements
                profileAge = value;
            }
        }

        private static string profileGender;
        public static string ProfileGender
        {
            get
            {
                // Reads are usually simple
                return profileGender;
            }
            set
            {
                // You can add logic here for race conditions,
                // or other measurements
                profileGender = value;
            }
        }

        private static string profileID;
        public static string ProfileID
        {
            get
            {
                // Reads are usually simple
                return profileID;
            }
            set
            {
                // You can add logic here for race conditions,
                // or other measurements
                profileID = value;
            }
        }
        private static string start;
        public static string Start
        {
            get
            {
                // Reads are usually simple
                return start;
            }
            set
            {
                // You can add logic here for race conditions,
                // or other measurements
                start = value;
            }
        }
        private static string end;
        public static string End
        {
            get
            {
                // Reads are usually simple
                return end;
            }
            set
            {
                // You can add logic here for race conditions,
                // or other measurements
                end = value;
            }
        }
        private static string leaveDate;
        public static string LeaveDate
        {
            get { return leaveDate; }
            set { leaveDate = value; }
        }

        private static string arriveDate;
        public static string ArriveDate
        {
            get { return arriveDate; }
            set { arriveDate = value; }
        }

        private static string leaveTime;
        public static string LeaveTime
        {
            get { return leaveTime; }
            set { leaveTime = value; }
        }

        private static string arriveTime;
        public static string ArriveTime
        {
            get { return arriveTime; }
            set { arriveTime = value; }
        }

        private static string userName;
        public static string UserName
        {
            get { return userName; }
            set { userName = value; }
        }

        private static string userId;
        public static string UserId
        {
            get { return userId; }
            set { userId = value; }
        }

        private static int tripID;
        public static int TripID
        {
            get { return tripID; }
            set { tripID = value; }
        }

    };

    [Activity(Label = "RiderActivity")]
    public class RiderActivity : Activity
    {
        
        protected override void OnCreate(Bundle savedInstanceState)
        {
            base.OnCreate(savedInstanceState);

            // Create your application here
            SetContentView(Resource.Layout.Rider);

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

            var spinner = FindViewById<Spinner>(Resource.Id.TripDropdown);
          //  spinner.ItemSelected += new EventHandler<AdapterView.ItemSelectedEventArgs>(spinner_ItemSelected);
            //This causes item to be automatically selected and transfers to potential trip page, it is commented out just so demo is smoother


            {

                String str = "server=184.181.99.29;user id=monty;database=5GLTE;password=9hZh4S7t";
                String query = "select * from Trips";
                
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
                        arrayAdapter.Add("Existing Trips");
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
                        StartActivity(nextActivity);
                        Finish();

                    };
                    // spinner.setOnItemSelectedListener(this);
                }
            };
            

        }

        

    }
}