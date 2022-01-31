// FTServerProgram.cs
//
// Pete Myers
// CST 415
// Fall 2019
// 

using System;
using PRSLib;


namespace FTServer
{
    class FTServerProgram
    {
        private static void Usage()
        {
            Console.WriteLine("Usage: FTServer -prs <PRS IP address>:<PRS port>");
        }

        static void Main(string[] args)
        {
            // defaults
            ushort FTSERVER_PORT = 40000;
            int CLIENT_BACKLOG = 5;
            string PRS_ADDRESS = "127.0.0.1";
            ushort PRS_PORT = 30000;
            string SERVICE_NAME = "FT Server";

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
                        PRS_ADDRESS = parts[0];
                        PRS_PORT = ushort.Parse(parts[1]);
                    }
                    else
                    {
                        throw new Exception("Unrecognizable Parameter");
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.Message);
                Usage();
                return;
            }

            Console.WriteLine("PRS Address: " + PRS_ADDRESS);
            Console.WriteLine("PRS Port: " + PRS_PORT);
            
            try
            {
                // contact the PRS, request a port for "FT Server" and start keeping it alive
                PRSClient PRS = new PRSClient(PRS_ADDRESS, PRS_PORT, SERVICE_NAME);
                FTSERVER_PORT = PRS.RequestPort();
                PRS.KeepPortAlive();

                // instantiate FT server and start it running
                FTServer ft = new FTServer(FTSERVER_PORT, CLIENT_BACKLOG);
                ft.Start();

                // tell the PRS that it can have it's port back, we don't need it anymore
                PRS.ClosePort();
                
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
