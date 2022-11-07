/*
 * Ce programme permet de lancer un serveur WiFi.
 * 
 * Le programme renvoie une page internet.
 * 
 * REMARQUE : le port UART est ouvert le temps de donner l'adresse IP du serveur.
 */

#include <WiFi.h>
#include <WiFiServer.h>
#include <WiFiClient.h>

//######################################
//##                                  ##
//##            VARIABLES             ##
//##                                  ##
//######################################

// Reglage de la connexion :
WiFiServer server(80);
WiFiClient client;
const char *ssid      = "IMERIR_IoT";
const char *password  = "kohWoong5oox";
int counter           = 0;

//######################################
//##                                  ##
//##             SETUP                ##
//##                                  ##
//######################################

void setup()
{
  // Reglage du port UART :
  Serial.begin(115200);

  
  // Connection au wifi :  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)  // Tant que le module n'est pas connecté
  {
    delay(1000);
    Serial.print(".");
  }

  
  // Affichage de adresse IP sur le moniteur serie :
  Serial.print("\nAdresse IP : ");
  Serial.println(WiFi.localIP());


  // Demarrage du serveur :
  server.begin();
}



//######################################
//##                                  ##
//##             LOOP                 ##
//##                                  ##
//######################################

void loop()
{
  // Serveur WEB :
  client = server.available();   // Demande si presence de client
  if (client)  // Si il y a un client
  {
    counter++;
    Serial.print("Client connected:"); Serial.println(counter);

    // Envoie du site internet :
    client.println("<!DOCTYPE html>");
    client.println("<html>");
    client.println("<head><title>Web server</title></head>");
    client.println("<body><h1>Hello World</h1></body></html>");
    client.print("<body><h2>client counter: "); client.print(counter); client.println("</h2></body></html>");
    
    // Deconnexion du client :
    client.stop();
    Serial.println("Website sent, client disconnected.");
    Serial.println("----------------------------------");
  }
  
  delay(50);
}