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
//Driver UI page
//Driver Stuff
//********************************************************
namespace RideOrDrive2
{
    [Activity(Label = "DriverActivity")]
    public class DriverActivity : Activity
    {

        protected override void OnCreate(Bundle savedInstanceState)
        {
            base.OnCreate(savedInstanceState);

            // Create your application here
            SetContentView(Resource.Layout.Driver);

            var RiderButton = FindViewById<Button>(Resource.Id.RiderButton);

            RiderButton.Click += (s, e) =>
            {
                Intent nextActivity = new Intent(this, typeof(RiderActivity));
                StartActivity(nextActivity);
                Finish();
            };

            //  var EditTripButton = FindViewById<Button>(Resource.Id.EditTrip);
            var EditTripButton = FindViewById<Button>(Resource.Id.EditTrip);
            EditTripButton.Click += (s, e) =>
            {
                Intent nextActivity = new Intent(this, typeof(EditTrip));
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

            var PlanTripButton = FindViewById<Button>(Resource.Id.PlanTrip);

            PlanTripButton.Click += (s, e) =>
            {
                Intent nextActivity = new Intent(this, typeof(PlanTrip));
                StartActivity(nextActivity);
                Finish();
            };

            var HomeButton = FindViewById<Button>(Resource.Id.test);

            HomeButton.Click += (s, e) =>
            {
                Intent nextActivity = new Intent(this, typeof(Login));
                StartActivity(nextActivity);
                Finish();
            };

            var list = FindViewById<ListView>(Resource.Id.ReviewList);
            String reviewstr = "server=184.181.99.29;user id=monty;database=5GLTE;password=9hZh4S7t";
            String reviewquery = "select * from Reviews WHERE UserID = '" + Globals.UserId + "'";
            ArrayAdapter reviewarrayAdapter = new ArrayAdapter<string>(this, Android.Resource.Layout.SimpleListItem1);


            var reviewconn = new MySqlConnection(reviewstr);
            MySqlDataAdapter reviewadapter = new MySqlDataAdapter(reviewquery, reviewconn);
            ArrayList reviewitems = new ArrayList();

            MySqlCommandBuilder reviewcmd = new MySqlCommandBuilder(reviewadapter);

            DataTable reviewdt = new DataTable();
            reviewadapter.Fill(reviewdt);
            foreach (DataRow row in reviewdt.Rows)
            {  
                    {
                        string Cols = "";
                        Cols += (row["ReviewComment"].ToString());
                        reviewarrayAdapter.Add(Cols);
                    }    
            }
            reviewarrayAdapter.SetDropDownViewResource(Android.Resource.Layout.SimpleListItem1);

            list.Adapter = reviewarrayAdapter;
            reviewconn.Close();


            String str = "server=184.181.99.29;user id=monty;database=5GLTE;password=9hZh4S7t";
            String query = "select * from Trips WHERE DriverID = '" + Globals.UserId + "'";
            ArrayAdapter arrayAdapter = new ArrayAdapter<string>(this, Android.Resource.Layout.SimpleSpinnerItem);


            var conn = new MySqlConnection(str);
            MySqlDataAdapter adapter = new MySqlDataAdapter(query, conn);
            ArrayList items = new ArrayList();

            MySqlCommandBuilder cmd = new MySqlCommandBuilder(adapter);

            DataTable dt = new DataTable();
            adapter.Fill(dt);




            String str2 = "server=184.181.99.29;user id=monty;database=5GLTE;password=9hZh4S7t";
            String query2 = "select * from Requests";
            ArrayAdapter arrayAdapter2 = new ArrayAdapter<string>(this, Android.Resource.Layout.SimpleSpinnerItem);


            var conn2 = new MySqlConnection(str2);
            MySqlDataAdapter adapter2 = new MySqlDataAdapter(query2, conn2);
            ArrayList items2 = new ArrayList();

            MySqlCommandBuilder cmd2 = new MySqlCommandBuilder(adapter2);

            DataTable dt2 = new DataTable();
            adapter2.Fill(dt2);

            var spinner = FindViewById<Spinner>(Resource.Id.RequestDropdown);


            arrayAdapter.Add("Requests");
            foreach (DataRow row in dt2.Rows)
                    {
                        foreach (DataRow row2 in dt.Rows)
                        {
                            if ((row2["TripID"].ToString() == row["TripNum"].ToString()) && row2["DriverID"].ToString() == Globals.UserId)
                            {
                                string Cols = "";
                                Cols += (row["RequestorName"].ToString());
                                arrayAdapter.Add(Cols);
                            }
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
                        int pos = e.Position;
                        String str3 = "server=184.181.99.29;user id=monty;database=5GLTE;password=9hZh4S7t";
                        String query3 = "select * from Users where FirstName= '" + dt2.Rows[pos]["RequestorName"]
                                                                                       .ToString() + "' ";
                        ArrayAdapter arrayAdapter3 = new ArrayAdapter<string>(this, Android.Resource.Layout.SimpleSpinnerItem);


                        var conn3 = new MySqlConnection(str3);
                        MySqlDataAdapter adapter3 = new MySqlDataAdapter(query3, conn3);
                        ArrayList items3 = new ArrayList();

                        MySqlCommandBuilder cmd3 = new MySqlCommandBuilder(adapter3);
                        DataTable dt3 = new DataTable();
                        adapter3.Fill(dt3);


                        Globals.ProfileFirstName = dt3.Rows[0]["FirstName"].ToString();
                        Globals.ProfileLastName = dt3.Rows[0]["LastName"].ToString();
                        Globals.ProfileEmail = dt3.Rows[0]["Email"].ToString();
                        Globals.ProfileGender = dt3.Rows[0]["Gender"].ToString();
                        Globals.ProfileSalt = dt3.Rows[0]["Salt"].ToString();
                        Globals.ProfileID = dt3.Rows[0]["UserID"].ToString();
                        Globals.TripID = (int)dt2.Rows[pos]["TripNum"];
                        Intent nextActivity = new Intent(this, typeof(OtherUserProfile));
                        StartActivity(nextActivity);
                        Finish();

                    };
              //  }
            
        } 
    }  
} 