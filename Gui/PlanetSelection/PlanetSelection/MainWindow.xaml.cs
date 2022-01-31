using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace PlanetSelection
{
    public class LabelText
    {
        public LabelText()
        {
            UOri = "?";
            GOri = "?";
            SOri = "?";
            POri = "?";
            UDest = "?";
            GDest = "?";
            SDest = "?";
            PDest = "?";
        }

        string UOri;
        public string UniverseOrigin
        {
            get { return UOri; }
            set { UOri = value; }
        }

        string GOri;
        public string GalaxyOrigin
        {
            get { return GOri; }
            set { GOri = value; }
        }

        string SOri;
        public string SolarOrigin
        {
            get { return SOri; }
            set { SOri = value; }
        }
        string POri;
        public string  PlanetOrigin
        {
            get { return POri; }
            set { POri = value; }
        }
        string UDest;
        public string UniverseDest
        {
            get { return UDest; }
            set { UDest = value; }
        }

        string GDest;
        public string GalaxyDest
        {
            get { return GDest; }
            set { GDest = value; }
        }

        string SDest;
        public string SolarDest
        {
            get { return SDest; }
            set { SDest = value; }
        }
        string PDest;
        public string PlanetDest
        {
            get { return PDest; }
            set { PDest = value; }
        }
    }
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        LabelText label = new LabelText();
        bool universe = false;
        bool galaxy = false;
        bool solar = false;
        public MainWindow()
        {
            InitializeComponent();
            ClickSelection.Content = FindResource("Universe");
            universe = true;
            UniverseOri.Items.Add("Universe Q1"); //could use some data source but this is easier
            UniverseDest.Items.Add("Universe Q1");
            GalaxyOri.Items.Add("Milky Way");
            GalaxyDest.Items.Add("Milky Way");
            SolarSystemOri.Items.Add("Solar System");
            SolarSystemDest.Items.Add("Solar System");
            PlanetOri.Items.Add("Mercury");
            PlanetOri.Items.Add("Venus");
            PlanetOri.Items.Add("Earth");
            PlanetOri.Items.Add("Mars");
            PlanetOri.Items.Add("Jupiter");
            PlanetOri.Items.Add("Saturn");
            PlanetOri.Items.Add("Uranus");
            PlanetOri.Items.Add("Neptune");
            PlanetOri.Items.Add("Pluto");
            PlanetDest.Items.Add("Mercury");
            PlanetDest.Items.Add("Venus");
            PlanetDest.Items.Add("Earth");
            PlanetDest.Items.Add("Mars");
            PlanetDest.Items.Add("Jupiter");
            PlanetDest.Items.Add("Saturn");
            PlanetDest.Items.Add("Uranus");
            PlanetDest.Items.Add("Neptune");
            PlanetDest.Items.Add("Pluto");
        }

        private void UpdateOri() //update the label for origin
        {
            string origin = label.UniverseOrigin + "/" + label.GalaxyOrigin + "/" + label.SolarOrigin + "/" + label.PlanetOrigin;
            Ori.Content = origin;
        }
        private void UpdateDest() //update the label for dest
        {
            string Desti = label.UniverseDest + "/" + label.GalaxyDest + "/" + label.SolarDest + "/" + label.PlanetDest;
            Dest.Content = Desti;
        }

        private void button_Click(object sender, RoutedEventArgs e) //change the picture and fill the appropriate combobox
        {
            if(universe)
            {
                if(UniverseOri.Text != "")
                {
                    UniverseDest.Text = "Universe Q1";
                    label.UniverseDest = UniverseDest.Text;
                }
                else
                {
                    UniverseOri.Text = "Universe Q1";
                    label.UniverseOrigin = UniverseOri.Text;
                }
                universe = false;
                galaxy = true;
                ClickSelection.Content = FindResource("Galaxy");
            }
            else if(galaxy)
            {
                if(GalaxyOri.Text != "")
                {
                    GalaxyDest.Text = "Milky Way";
                    label.GalaxyDest = GalaxyDest.Text;
                }
                else
                {
                    GalaxyOri.Text = "Milky Way";
                    label.GalaxyOrigin = GalaxyOri.Text;
                }
                galaxy = false;
                solar = true;
                ClickSelection.Content = FindResource("MilkyWay");
            }
            else if(solar)
            {
                if (SolarSystemOri.Text != "")
                {
                    SolarSystemDest.Text = "Solar System";
                    label.SolarDest = SolarSystemDest.Text;
                }
                else
                {
                    SolarSystemOri.Text = "Solar System";
                    label.SolarOrigin = SolarSystemOri.Text;
                }
                solar = false;
                ClickSelection.Content = FindResource("SolarSystem");
            }
            else
            {
                if(PlanetOri.Text != "")
                {
                    PlanetDest.Text = "Mars";
                    label.PlanetDest = PlanetDest.Text;
                    DestPlanet.Source = ((Image)FindResource("Mars")).Source;
                }
                else
                {
                    PlanetOri.Text = "Earth";
                    label.PlanetOrigin = PlanetOri.Text;
                    OriPlanet.Source = ((Image)FindResource("Earth")).Source;
                    universe = true;
                    ClickSelection.Content = FindResource("Universe");
                }
            }

            UpdateOri();
            UpdateDest();
        }

        private void UniverseOri_GotFocus(object sender, RoutedEventArgs e)
        {
            ClickSelection.Content = FindResource("Universe");
            universe = true;
            galaxy = false;
            solar = false;
        }

        private void UniverseOri_LostFocus(object sender, RoutedEventArgs e)
        {
            if(UniverseOri.Text != "")
            {
                label.UniverseOrigin = UniverseOri.Text;
                UpdateOri();
            }
            else
            {
                label.UniverseOrigin = "?";
                OriPlanet.Source = ((Image)FindResource("Unknown")).Source;
                UpdateOri();
            }
        }

        private void GalaxyOri_GotFocus(object sender, RoutedEventArgs e)
        {
            ClickSelection.Content = FindResource("Galaxy");
            galaxy = true;
            universe = false;
            solar = false;
        }

        private void GalaxyOri_LostFocus(object sender, RoutedEventArgs e)
        {
            if (GalaxyOri.Text != "")
            {
                label.GalaxyOrigin = GalaxyOri.Text;
                UpdateOri();
            }
            else
            {
                label.GalaxyOrigin = "?";
                OriPlanet.Source = ((Image)FindResource("Unknown")).Source;
                UpdateOri();
            }
        }

        private void SolarSystemOri_GotFocus(object sender, RoutedEventArgs e)
        {
            ClickSelection.Content = FindResource("MilkyWay");
            galaxy = false;
            universe = false;
            solar = true;
        }

        private void SolarSystemOri_LostFocus(object sender, RoutedEventArgs e)
        {
            if (SolarSystemOri.Text != "")
            {
                label.SolarOrigin = SolarSystemOri.Text;
                UpdateOri();
            }
            else
            {
                label.SolarOrigin = "?";
                OriPlanet.Source = ((Image)FindResource("Unknown")).Source;
                UpdateOri();
            }
        }

        private void PlanetOri_GotFocus(object sender, RoutedEventArgs e)
        {
            ClickSelection.Content = FindResource("SolarSystem");
            galaxy = false;
            universe = false;
            solar = false;
        }

        private void PlanetOri_LostFocus(object sender, RoutedEventArgs e)
        {
            if (PlanetOri.Text != "")
            {
                label.PlanetOrigin = PlanetOri.Text;
                OriPlanet.Source = ((Image)FindResource("Earth")).Source;
                UpdateOri();
            }
            else
            {
                label.PlanetOrigin = "?";
                OriPlanet.Source = ((Image)FindResource("Unknown")).Source;
                UpdateOri();
            }
        }

        private void UniverseDest_GotFocus(object sender, RoutedEventArgs e)
        {
            ClickSelection.Content = FindResource("Universe");
            universe = true;
        }

        private void UniverseDest_LostFocus(object sender, RoutedEventArgs e)
        {
            if (UniverseDest.Text != "")
            {
                label.UniverseDest = UniverseDest.Text;
                UpdateDest();
            }
            else
            {
                label.UniverseDest = "?";
                DestPlanet.Source = ((Image)FindResource("Unknown")).Source;
                UpdateDest();
            }
        }

        private void GalaxyDest_GotFocus(object sender, RoutedEventArgs e)
        {
            ClickSelection.Content = FindResource("Galaxy");
            galaxy = true;
            universe = false;
            solar = false;
        }

        private void GalaxyDest_LostFocus(object sender, RoutedEventArgs e)
        {
            if (GalaxyDest.Text != "")
            {
                label.GalaxyDest = GalaxyDest.Text;
                UpdateDest();
            }
            else
            {
                label.GalaxyDest = "?";
                DestPlanet.Source = ((Image)FindResource("Unknown")).Source;
                UpdateDest();
            }
        }

        private void SolarSystemDest_GotFocus(object sender, RoutedEventArgs e)
        {
            ClickSelection.Content = FindResource("MilkyWay");
            galaxy = false;
            universe = false;
            solar = true;
        }

        private void SolarSystemDest_LostFocus(object sender, RoutedEventArgs e)
        {
            if (SolarSystemDest.Text != "")
            {
                label.SolarDest = SolarSystemDest.Text;
                UpdateDest();
            }
            else
            {
                label.SolarDest = "?";
                DestPlanet.Source = ((Image)FindResource("Unknown")).Source;
                UpdateDest();
            }
        }

        private void PlanetDest_GotFocus(object sender, RoutedEventArgs e)
        {
            ClickSelection.Content = FindResource("SolarSystem");
            galaxy = false;
            universe = false;
            solar = false;
        }

        private void PlanetDest_LostFocus(object sender, RoutedEventArgs e)
        {
            if (PlanetDest.Text != "")
            {
                label.PlanetDest = PlanetDest.Text;
                DestPlanet.Source = ((Image)FindResource("Mars")).Source;
                UpdateDest();
            }
            else
            {
                label.PlanetDest = "?";
                UpdateDest();
            }
        }

        private void Cancel_Click(object sender, RoutedEventArgs e)
        {
            Application.Current.Shutdown();
        }

        private void TimeSelect_Click(object sender, RoutedEventArgs e)
        {
            DateSelect dateSelect = new DateSelect();
            dateSelect.Show();
        }

        private void Transport_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }
    }
}
