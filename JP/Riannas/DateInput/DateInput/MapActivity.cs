
using Android;
using Android.Content;
using Android.App;
using Android.OS;
using Android.Widget;
using Android.Runtime;
using Android.Gms.Maps;
using Android.Gms.Common;
using Android.Locations;
using Android.Gms.Maps.Model;
using Android.Gms.Location;
using System.Threading.Tasks;
using Newtonsoft.Json;
//********************************************************
//Map page
//Map stuff
//********************************************************
namespace RideOrDrive2
{
    [Activity(Label = "MapActivity")]
    public class MapActivity : Activity, IOnMapReadyCallback
    {


        static readonly int REQUEST_LOCATION = 0;
        static readonly int RC_INSTALL_GOOGLE_PLAY_SERVICES = 1000;

        static string[] PERMISSIONS_LOCATION =
        {
            Manifest.Permission.AccessFineLocation,
            Manifest.Permission.AccessCoarseLocation
        };
        GoogleMap googleMap;

        bool TestIfGooglePlayServicesIsInstalled()
        {
            var queryResult = GoogleApiAvailability.Instance.IsGooglePlayServicesAvailable(this);
            if (queryResult == ConnectionResult.Success)
            {
                return true;
            }

            if (GoogleApiAvailability.Instance.IsUserResolvableError(queryResult))
            {
                var errorString = GoogleApiAvailability.Instance.GetErrorString(queryResult);
                var errorDialog = GoogleApiAvailability.Instance.GetErrorDialog(this, queryResult, RC_INSTALL_GOOGLE_PLAY_SERVICES);
                var dialogFrag = new ErrorDialogFragment();

                dialogFrag.Show(FragmentManager, "GooglePlayServicesDialog");
            }

            return false;
        }

        async void TestApiCallAsync()
        {
            string requestApi = "https://maps.googleapis.com/maps/api/directions/json?origin=Chicago,IL&destination=Los+Angeles,CA&waypoints=Joplin,MO|Oklahoma+City,OK&key=AIzaSyAfwMLTw7DFuJeK-a39KxZPaBoqdUGsZBg";
            var client = new System.Net.Http.HttpClient();
            var response = await client.GetAsync(requestApi);
            string directionsJson = await response.Content.ReadAsStringAsync();
            RootObject directions = new RootObject();
            if (directionsJson != "")
            {
                directions = JsonConvert.DeserializeObject<RootObject>(directionsJson);
            }
        }

        protected override void OnCreate(Bundle savedInstanceState)
        {

            base.OnCreate(savedInstanceState);

            RequestPermissions(PERMISSIONS_LOCATION, REQUEST_LOCATION);

            SetContentView(Resource.Layout.Map);

            var mapFragment = (MapFragment)FragmentManager.FindFragmentById(Resource.Id.map);
            mapFragment.GetMapAsync(this);



            var RiderButton = FindViewById<Button>(Resource.Id.RiderButton);

            RiderButton.Click += (s, e) =>
            {
                Intent nextActivity = new Intent(this, typeof(RiderActivity));
                StartActivity(nextActivity);
                Finish();
            };

            var DriverButton = FindViewById<Button>(Resource.Id.DriverButton);

            DriverButton.Click += (s, e) =>
            {
                Intent nextActivity = new Intent(this, typeof(DriverActivity));
                StartActivity(nextActivity);
                Finish();
            };
        }

        public void OnMapReady(GoogleMap map)
        {
            googleMap = map;

            googleMap.UiSettings.ZoomControlsEnabled = true;
            googleMap.UiSettings.CompassEnabled = true;
            googleMap.UiSettings.MyLocationButtonEnabled = false;
            googleMap.MyLocationEnabled = true;

            LocationManager locationManager = (LocationManager)GetSystemService(LocationService);
            Criteria criteria = new Criteria();
            string provider = locationManager.GetBestProvider(new Criteria(), true);


            Location location = locationManager.GetLastKnownLocation(provider);
            if(location != null)
            {
                LatLng mylocation = new LatLng(location.Latitude, location.Longitude);
                CameraPosition.Builder builder = CameraPosition.InvokeBuilder();
                builder.Target(mylocation);
                builder.Zoom(15);
                builder.Bearing(0);
                builder.Tilt(0);

                CameraPosition cameraPosition = builder.Build();

                CameraUpdate cameraUpdate = CameraUpdateFactory.NewCameraPosition(cameraPosition);

                googleMap.MoveCamera(cameraUpdate);
            }


        }

        public override void OnRequestPermissionsResult(int requestCode, string[] permissions, [GeneratedEnum] Android.Content.PM.Permission[] grantResults)
        {
            Xamarin.Essentials.Platform.OnRequestPermissionsResult(requestCode, permissions, grantResults);

            base.OnRequestPermissionsResult(requestCode, permissions, grantResults);
        }
    }
}