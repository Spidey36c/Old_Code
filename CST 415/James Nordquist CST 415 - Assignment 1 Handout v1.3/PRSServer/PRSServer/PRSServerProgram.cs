// PRSServerProgram.cs
//
// Pete Myers
// CST 415
// Fall 2019
// 
// Modified by: James Nordquist
// CST 415
// Fall 2021

using System;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using PRSLib;

namespace PRSServer
{
    class PRSServerProgram
    {
        class PRS
        {
            // represents a PRS Server, keeps all state and processes messages accordingly

            class PortReservation
            {
                private ushort port;
                private bool available;
                private string serviceName;
                private DateTime lastAlive;

                public PortReservation(ushort port)
                {
                    this.port = port;
                    available = true;
                }

                public string ServiceName { get { return serviceName; } }
                public ushort Port { get { return port; } }
                public bool Available { get { return available; } }

                public bool Expired(int timeout)
                {
                    // return true if timeout secons have elapsed since lastAlive
                    if (lastAlive.AddSeconds(timeout) < DateTime.Now)
                    {
                        Close();
                        return true;
                    }

                    return false;
                }

                public void Reserve(string serviceName)
                {
                    // reserve this port for serviceName
                    this.serviceName = serviceName;
                    this.lastAlive = DateTime.Now;
                    available = false;
                }

                public void KeepAlive()
                {
                    // save current time in lastAlive
                    this.lastAlive = DateTime.Now;
                }

                public void Close()
                {
                    // make this reservation available
                    available = true;
                    this.serviceName = null;
                }
            }

            // server attribues
            private ushort startingClientPort;
            private ushort endingClientPort;
            private int keepAliveTimeout;
            private int numPorts;
            private PortReservation[] ports;
            private bool stopped;

            public PRS(ushort startingClientPort, ushort endingClientPort, int keepAliveTimeout)
            {
                // save parameters
                this.startingClientPort = startingClientPort;
                this.endingClientPort = endingClientPort;
                this.keepAliveTimeout = keepAliveTimeout;

                // initialize to not stopped
                stopped = false;
                // initialize port reservations
                numPorts = (endingClientPort - startingClientPort) + 1;
                ports = new PortReservation[numPorts];
                for (ushort i = 0; i < numPorts; i++)
                {
                    ports[i] = new PortReservation((ushort)(startingClientPort + i));
                }
            }

            public bool Stopped { get { return stopped; } }

            private void CheckForExpiredPorts()
            {
                // expire any ports that have not been kept alive
                /*
                 * Probably an easier way, Maybe LINQ or something alike?
                 * Would only avoid one function call, but could potentially speed up if lots of ports are made
                 */
                foreach (PortReservation reservation in ports)
                {
                    // if found, send port number back
                    reservation.Expired(keepAliveTimeout);
                }
            }

            private PRSMessage RequestPort(string serviceName)
            {

                // client has requested the lowest available port, so find it!
                //PortReservation reservation = new Portreservation
                //while (reservation.Available) --v avoids early return
                foreach (PortReservation reservation in ports)
                {
                    if (reservation.Available)
                    {
                        reservation.Reserve(serviceName);
                        return new PRSMessage(PRSMessage.MESSAGE_TYPE.RESPONSE, serviceName, reservation.Port, PRSMessage.STATUS.SUCCESS);

                    }
                }

                // if found an avialable port, reserve it and send SUCCESS
                // else, none available, send ALL_PORTS_BUSY
                return new PRSMessage(PRSMessage.MESSAGE_TYPE.RESPONSE, serviceName, 0, PRSMessage.STATUS.ALL_PORTS_BUSY);
            }

            public PRSMessage HandleMessage(PRSMessage msg)
            {

                // handle one message and return a response
                CheckForExpiredPorts();
                PRSMessage response = null;

                switch (msg.MsgType)
                {
                    case PRSMessage.MESSAGE_TYPE.REQUEST_PORT:
                        {

                            // send requested report
                            response = RequestPort(msg.ServiceName);
                        }
                        break;

                    case PRSMessage.MESSAGE_TYPE.KEEP_ALIVE:
                        {
                            // client has requested that we keep their port alive
                            // find the port
                            foreach (PortReservation reservation in ports)
                            {
                                // if found, keep it alive and send SUCCESS
                                if (!reservation.Available && reservation.Port == msg.Port && reservation.ServiceName == msg.ServiceName)
                                {
                                    reservation.KeepAlive();
                                    response = new PRSMessage(PRSMessage.MESSAGE_TYPE.RESPONSE, msg.ServiceName, msg.Port, PRSMessage.STATUS.SUCCESS);
                                }
                            }

                            if (response == null)
                            {
                                // else, SERVICE_NOT_FOUND
                                response = new PRSMessage(PRSMessage.MESSAGE_TYPE.RESPONSE, msg.ServiceName, msg.Port, PRSMessage.STATUS.SERVICE_NOT_FOUND);
                            }
                        }
                        break;

                    case PRSMessage.MESSAGE_TYPE.CLOSE_PORT:
                        {
                            // client has requested that we close their port, and make it available for others!
                            // find the port
                            foreach (PortReservation reservation in ports)
                            {
                                // if found, close it and send SUCCESS
                                if (!reservation.Available && reservation.Port == msg.Port && reservation.ServiceName == msg.ServiceName)
                                {
                                    reservation.Close();
                                    response = new PRSMessage(PRSMessage.MESSAGE_TYPE.RESPONSE, msg.ServiceName, msg.Port, PRSMessage.STATUS.SUCCESS);
                                }
                            }

                            if (response == null)
                            {
                                // else, SERVICE_NOT_FOUND
                                response = new PRSMessage(PRSMessage.MESSAGE_TYPE.RESPONSE, msg.ServiceName, msg.Port, PRSMessage.STATUS.SERVICE_NOT_FOUND);
                            }
                        }
                        break;

                    case PRSMessage.MESSAGE_TYPE.LOOKUP_PORT:
                        {
                            // client wants to know the reserved port number for a named service
                            // find the port
                            foreach (PortReservation reservation in ports)
                            {
                                // if found, send port number back
                                if (!reservation.Available && reservation.ServiceName == msg.ServiceName)
                                {
                                    response = new PRSMessage(PRSMessage.MESSAGE_TYPE.RESPONSE, msg.ServiceName, reservation.Port, PRSMessage.STATUS.SUCCESS);
                                }
                            }

                            if (response == null)
                            {
                                // else, SERVICE_NOT_FOUND
                                response = new PRSMessage(PRSMessage.MESSAGE_TYPE.RESPONSE, msg.ServiceName, msg.Port, PRSMessage.STATUS.SERVICE_NOT_FOUND);
                            }
                        }
                        break;

                    case PRSMessage.MESSAGE_TYPE.STOP:
                        {
                            // client is telling us to close the appliation down
                            this.stopped = true;
                            // stop the PRS and return SUCCESS
                            response = new PRSMessage(PRSMessage.MESSAGE_TYPE.RESPONSE, msg.ServiceName, msg.Port, PRSMessage.STATUS.SUCCESS);
                        }
                        break;
                }

                return response;
            }

        }

        static void Usage()
        {
            Console.WriteLine("usage: PRSServer [options]");
            Console.WriteLine("\t-p < service port >");
            Console.WriteLine("\t-s < starting client port number >");
            Console.WriteLine("\t-e < ending client port number >");
            Console.WriteLine("\t-t < keep alive time in seconds >");
        }

        static void Main(string[] args)
        {

            // defaults
            ushort SERVER_PORT = 30000;
            ushort STARTING_CLIENT_PORT = 40000;
            ushort ENDING_CLIENT_PORT = 40099;
            int KEEP_ALIVE_TIMEOUT = 300;

            // process command options
            // -p < service port >
            // -s < starting client port number >
            // -e < ending client port number >
            // -t < keep alive time in seconds >
            if (args.Length == 0)
            {
                Usage();
            }
            else
            {
                for (int i = 0; i < args.Length; i++)
                {
                    if (args[i] == "-p")
                    {
                        if (i + 1 < args.Length)
                        {
                            if (!ushort.TryParse(args[++i], out SERVER_PORT))
                            {
                                Console.WriteLine("Incorrect use of -p, needs a number between {0} and {1}", ushort.MinValue, ushort.MaxValue);
                            }
                        }
                        else
                        {
                            Console.WriteLine("Incorrect use of -p, needs a number after -p between {0} and {1}", ushort.MinValue, ushort.MaxValue);
                        }

                    }
                    else if (args[i] == "-s")
                    {
                        if (i + 1 < args.Length)
                        {
                            if (!ushort.TryParse(args[++i], out STARTING_CLIENT_PORT))
                            {
                                Console.WriteLine("Incorrect use of -s, needs a number between {0} and {1}", ushort.MinValue, ushort.MaxValue);
                            }
                        }
                        else
                        {
                            Console.WriteLine("Incorrect use of -s, needs a number after -p between {0} and {1}", ushort.MinValue, ushort.MaxValue);
                        }
                    }
                    else if (args[i] == "-e")
                    {
                        if (i + 1 < args.Length)
                        {
                            if (!ushort.TryParse(args[++i], out ENDING_CLIENT_PORT))
                            {
                                Console.WriteLine("Incorrect use of -e, needs a number between {0} and {1}", ushort.MinValue, ushort.MaxValue);
                            }
                        }
                        else
                        {
                            Console.WriteLine("Incorrect use of -e, needs a number after -p between {0} and {1}", ushort.MinValue, ushort.MaxValue);
                        }
                    }
                    else if (args[i] == "-t")
                    {
                        if (i + 1 < args.Length)
                        {
                            if (!int.TryParse(args[++i], out KEEP_ALIVE_TIMEOUT))
                            {
                                Console.WriteLine("Incorrect use of -t, needs a number between {0} and {1}", int.MinValue, int.MaxValue);
                            }
                        }
                        else
                        {
                            Console.WriteLine("Incorrect use of -t, needs a number after -p between {0} and {1}", int.MinValue, int.MaxValue);
                        }
                    }
                    else
                    {
                        Console.WriteLine("Error: Unrecognized parameter");
                        Usage();
                        return;
                    }
                }
            }

            // check for valid STARTING_CLIENT_PORT and ENDING_CLIENT_PORT
            if (STARTING_CLIENT_PORT > ENDING_CLIENT_PORT)
            {
                Console.WriteLine("Error: starting port must be less than ending port");
                return;
            }

            if(STARTING_CLIENT_PORT == 0 || SERVER_PORT == 0 || ENDING_CLIENT_PORT == 0)
            {
                Console.WriteLine("Can't have a port of 0");
                return;
            }

            Console.WriteLine("Server Port: " + SERVER_PORT.ToString());
            Console.WriteLine("Starting Client Port: " + STARTING_CLIENT_PORT.ToString());
            Console.WriteLine("Ending Client Port: " + ENDING_CLIENT_PORT.ToString());
            Console.WriteLine("Keep alive Time:" + KEEP_ALIVE_TIMEOUT.ToString());

            // initialize the PRS server
            PRS prs = new PRS(STARTING_CLIENT_PORT, ENDING_CLIENT_PORT, KEEP_ALIVE_TIMEOUT);

            // create the socket for receiving messages at the server
            Socket listeningSocket = new Socket(SocketType.Dgram, ProtocolType.Udp);

            // bind the listening socket to the PRS server port
            listeningSocket.Bind(new IPEndPoint(IPAddress.Any, SERVER_PORT));

            //
            // Process client messages
            //

            while (!prs.Stopped)
            {
                EndPoint remoteEndPoint = null;
                try
                {
                    System.Console.WriteLine("Waiting for message from client...");
                    // receive a message from a client
                    remoteEndPoint = new IPEndPoint(IPAddress.Any, 0);
                    PRSMessage request = PRSMessage.ReceiveMessage(listeningSocket, ref remoteEndPoint);

                    // let the PRS handle the message
                    PRSMessage response = prs.HandleMessage(request);

                    // send response message back to client
                    response.SendMessage(listeningSocket, remoteEndPoint);
                }
                catch (Exception ex)
                {
                    if (remoteEndPoint != null)
                    {
                        // attempt to send a UNDEFINED_ERROR response to the client, if we know who that was
                        PRSMessage errMsg = new PRSMessage(PRSMessage.MESSAGE_TYPE.RESPONSE, null, 0, PRSMessage.STATUS.UNDEFINED_ERROR);
                        errMsg.SendMessage(listeningSocket, remoteEndPoint);
                    }
                }
            }

            // close the listening socket
            listeningSocket.Close();

            // wait for a keypress from the user before closing the console window
            Console.WriteLine("Press Enter to exit");
            Console.ReadKey();
        }
    }
}
