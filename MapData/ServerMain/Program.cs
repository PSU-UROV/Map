using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Runtime.Serialization.Json;
using System.Runtime.Serialization;
using MapData;

namespace ServerMain
{
    class Loop
    {
        /// <summary>
        /// some basic test parameters
        /// </summary>
        //ALREADY FOUND A BUG...the add appears to be able to create lines outside of the bounds, and the
        //bulletproofing for the addline isn't up
        static void Testing()
        {
            Map test = new Map();
            test.AddNewRandomLine();
            test.AddNewRandomLine();
            test.AddNewRandomLine();
            DataContractJsonSerializer serializer = new DataContractJsonSerializer(typeof(Map));
            using (MemoryStream stream = new MemoryStream())
            {
                using (StreamWriter fileoutput = new StreamWriter(@"F:\test.json"))
                {

                    serializer.WriteObject(stream, test);
                    byte[] output = stream.ToArray();

                    foreach (byte print in output)
                    {
                        fileoutput.Write((char)print);
                    }
                }
            }

        }

        static void Main(string[] args)
        {
            Testing();
            
            Socket server = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

            Console.WriteLine("\n\nany key to continue");
            Console.ReadKey();
            
        }
    }
}
