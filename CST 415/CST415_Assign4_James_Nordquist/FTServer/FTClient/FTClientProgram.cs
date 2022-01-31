// FTClientProgram.cs
//
// Pete Myers
// CST 415
// Fall 2019
// 

using System;
using PRSLib;
using System.IO;
using FTClientLib;

namespace FTClient
{
    class FTClientProgram
    {
        private static void Usage()
        {
            /*
                -prs <PRS IP address>:<PRS port>
                -s <file transfer server IP address>
                -d <directory requested>
            */
            Console.WriteLine("Usage: FTClient -d <directory> [-prs <PRS IP>:<PRS port>] [-s <FT Server IP>]");
        }

        static void Main(string[] args)
        {
            // defaults
            string PRSSERVER_IPADDRESS = "127.0.0.1";
            ushort PRSSERVER_PORT = 30000;
            string FTSERVICE_NAME = "FT Server";
            string FTSERVER_IPADDRESS = "127.0.0.1";
            ushort FTSERVER_PORT = 40000;
            string DIRECTORY_NAME = null;

            // process the command line arguments
            try
            {

                for (int i = 0; i < args.Length; i++)
                {
                    if (args[i] == "-prs")
                    {
                        if (i + 1 >= args.Length)
                            throw new Exception("-prs expects a value");
                        //split
                        string[] parts = args[++i].Split(':');
                        if (parts.Length != 2)
                            throw new Exception("-prs Expects <serverIP>:<serverPort>");
                        PRSSERVER_IPADDRESS = parts[0];
                        PRSSERVER_PORT = ushort.Parse(parts[1]);
                    }
                    else if (args[i] == "-s")
                    {
                        if (i + 1 >= args.Length)
                            throw new Exception("-s expects a value");
                        FTSERVER_IPADDRESS = args[++i];
                    }
                    else if (args[i] == "-d")
                    {
                        if (i + 1 >= args.Length)
                            throw new Exception("-e expects a value");
                        DIRECTORY_NAME = args[++i];
                    }
                    else
                    {
                        throw new Exception("Unrecognizable Parameter");
                    }
                }

                if(DIRECTORY_NAME == null)
                {
                    throw new Exception("-d is a required parameter");
                }
            }
            catch(Exception ex)
            {
                Console.WriteLine("Error: " + ex.Message);
                Usage();
                return;
            }
            Console.WriteLine("PRS Address: " + PRSSERVER_IPADDRESS);
            Console.WriteLine("PRS Port: " + PRSSERVER_PORT);
            Console.WriteLine("FT Server Address: " + FTSERVER_IPADDRESS);
            Console.WriteLine("Directory: " + DIRECTORY_NAME);
            
            try
            {
                // contact the PRS and lookup port for "FT Server"
                PRSClient prs = new PRSClient(PRSSERVER_IPADDRESS, PRSSERVER_PORT, FTSERVICE_NAME);
                FTSERVER_PORT = prs.LookupPort();

                // create an FTClient and connect it to the server
                FTClientLib.FTClient ft = new FTClientLib.FTClient(FTSERVER_IPADDRESS, FTSERVER_PORT);
                ft.Connect();

                // get the contents of the specified directory
                try
                {
                    FTClientLib.FTClient.Directory dir = ft.GetDirectory(DIRECTORY_NAME);

                    // create the local directory if needed
                    DirectoryInfo di = new DirectoryInfo(DIRECTORY_NAME);
                    if (!di.Exists)
                    {
                        di.Create();
                        Console.WriteLine("Created local directory: " + DIRECTORY_NAME);
                    }

                    foreach (FTClientLib.FTClient.Directory.File f in dir.Files)
                    {
                        // save the files locally on the disk
                        string filePath = Path.Combine(DIRECTORY_NAME, f.Name);
                        StreamWriter sw = File.CreateText(filePath);
                        sw.Write(f.Contents);
                        sw.Flush();
                        sw.Close();
                        Console.WriteLine("Wrote file to file: " + f.Name);
                    }
                }
                catch(Exception ex)
                {
                    Console.WriteLine("Error while getting directory: " + ex.Message);
                }


                // disconnect from the server
                ft.Disconnect();
            }
            catch (Exception ex)
            {
                
                Console.WriteLine("Error " + ex.Message);
                Console.WriteLine(ex.StackTrace);
            }

            // wait for a keypress from the user before closing the console window
            Console.WriteLine("Press Enter to exit");
            Console.ReadKey();
        }
    }
}
