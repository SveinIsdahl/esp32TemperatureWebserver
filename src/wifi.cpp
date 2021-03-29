#include "main.h"

void wifiTask(void *ssidPointer)
{
  WiFiServer server(80);

  // Variable to store the HTTP request
  String header;

  // Dereferncing "double" pointer i.e ssidPointer is a pointer to a bunch of char-pointers?
  WiFi.softAP(*(char **)ssidPointer);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.begin();
  while (1)
  {
    WiFiClient client = server.available(); // Listen for incoming clients
    if (client)
    { // If a new client connects,
      Serial.println(
          "New Client."); // print a message out in the serial port
      String currentLine =
          ""; // make a String to hold incoming data from the client
      while (client.connected())
      { // loop while the client's connected
        if (client.available())
        {                         // if there's bytes to read from the
                                  // client,
          char c = client.read(); // read a byte, then
          Serial.write(c);        // print it out the serial monitor
          header += c;
          if (c == '\n')
          { // if the byte is a newline character
            // if the current line is blank, you got two newline
            // characters in a row. that's the end of the client
            // HTTP request, so send a response:
            if (currentLine.length() == 0)
            {
              // HTTP headers always start with a response code
              // (e.g. HTTP/1.1 200 OK) and a content-type so the
              // client knows what's coming, then a blank line:
              client.println("HTTP/1.1 200 OK");
              client.println("Content-type:text/html");
              client.println("Connection: close");

              int i = header.indexOf("/val/");
              if (i >= 0)
              {
                String s1 = String(header[i+5]);
                String s2 = String(header[i+6]);
                globalTargetTemp = (s1+s2).toInt();
              }
              client.println(html1);
              
              double temperature = analogReadToDegrees(analogRead(tempPin));
              client.println(String(temperature, 1));
              client.println(html2);
              client.println(globalTargetTemp);
              client.println(html3);

              // The HTTP response ends with another blank line
              client.println();
              // Break out of the while loop
              break;
            }
            else
            { // if you got a newline, then clear
              // currentLine
              currentLine = "";
            }
          }
          else if (c != '\r')
          { // if you got anything else but a
            // carriage return character,
            currentLine +=
                c; // add it to the end of the currentLine
          }
        }
      }
      // Clear the header variable
      header = "";
      // Close the connection
      client.stop();
      Serial.println("Client disconnected.");
      Serial.println("");
    }
    // Keeps wifi-task from crashing, not a good way of fixing it but works
    vTaskDelay(10 / portTICK_PERIOD_MS);
  }
}
