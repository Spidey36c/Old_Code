using Android.App;
using Android.OS;
using Android.Support.V7.App;
using Android.Runtime;
using Android.Widget;
using Android.Content;
using MySql.Data.MySqlClient;
using Android.Support.Design.Widget;
using System;
using System.Data;
//********************************************************
//Login in page
//What the user sees first
//********************************************************
namespace RideOrDrive2
{
    [Activity(Label = "@string/app_name", Theme = "@style/AppTheme", MainLauncher = true)]
    public class Login : AppCompatActivity
    {
        protected override void OnCreate(Bundle savedInstanceState)
        {
            base.OnCreate(savedInstanceState);
            Xamarin.Essentials.Platform.Init(this, savedInstanceState);
            // Set our view from the "main" layout resource
            SetContentView(Resource.Layout.Login);

            //Makes password layout toggle visibilty
            var editTextLayout = FindViewById<TextInputLayout>(Resource.Id.password_layout);

            editTextLayout.PasswordVisibilityToggleEnabled = true;


            //Allows loging to be submitted
            string message = string.Empty;
            var LoginButton = FindViewById<Button>(Resource.Id.Submit);

            LoginButton.Click += (s, e) =>
            {
                bool success = false;
                try
                {
                    var user = FindViewById<EditText>(Resource.Id.Username).Text;
                    var pass = FindViewById<TextInputEditText>(Resource.Id.Password).Text;
                    String server = "server=184.181.99.29;user id=monty;database=5GLTE;password=9hZh4S7t";
                    MySqlConnection con = new MySqlConnection(server);
                    String query = "SELECT * FROM 5GLTE.Users WHERE FirstName = '" + user + "' AND UserID = " + pass;
                    MySqlCommand cmd = new MySqlCommand(query, con);
                    Globals.UserName = user;
                    Globals.UserId = pass;
                    con.Open();
                    MySqlDataReader reader = cmd.ExecuteReader();
                    
                    if (reader.HasRows)
                    {
                        success = true;            
                    }
                    con.Close();
                }
                catch (Exception ee)
                { message = ee.Message; }
                if (success == true)
                {
                    Intent nextActivity = new Intent(this, typeof(DriverActivity));

                    StartActivity(nextActivity);

                    Finish();
                }

            };


            //Account Creation Button
            var AccountButton = FindViewById<Button>(Resource.Id.Account);

            AccountButton.Click += (s, e) =>
            {
                Intent nextActivity = new Intent(this, typeof(AccountActivity));
                StartActivity(nextActivity);
                Finish();
            };

        }
        public override void OnRequestPermissionsResult(int requestCode, string[] permissions, [GeneratedEnum] Android.Content.PM.Permission[] grantResults)
        {
            Xamarin.Essentials.Platform.OnRequestPermissionsResult(requestCode, permissions, grantResults);

            base.OnRequestPermissionsResult(requestCode, permissions, grantResults);
        }
    }
}


