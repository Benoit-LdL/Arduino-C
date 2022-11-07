/*
 * Ce programme permet de controller un robot grâce à une connexion WiFi.
 * Le robot utilise des codeurs optiques pour calculer sa position.
 * 
 * Le programme utilise deux interruptions pour gérer les informations capteur.
 * 
 * REMARQUE : le port UART est ouvert le temps de donner l'adresse IP du serveur.
 */

#include <WiFi.h>
#include <WiFiServer.h>
#include <WiFiClient.h>

//######################################
//##                                  ##
//##           DEFINITION             ##
//##                                  ##
//######################################

#define D1 5
#define D2 4
#define D3 0
#define D4 2
#define D5 14
#define D6 12

//######################################
//##                                  ##
//##            VARIABLES             ##
//##                                  ##
//######################################

// Reglage de la connexion :
WiFiServer server(80);
WiFiClient client;
// const char *ssid     = "IMERIR_IoT";
// const char *password = "kohWoong5oox";

const char *ssid     = "LdL";
const char *password = "LaBassePradelle1998";

const int led_red     = 32;
const int led_yellow  = 33;
const int led_green   = 25;

bool led_red_state    = false;
bool led_yellow_state = false;
bool led_green_state = false;

String demande_client;

//######################################
//##                                  ##
//##             SETUP                ##
//##                                  ##
//######################################

void setup()
{
  // Reglage du port UART :
  Serial.begin(115200);

  pinMode(led_red,OUTPUT);
  pinMode(led_yellow,OUTPUT);
  pinMode(led_green,OUTPUT);

  // Connection au wifi :  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)  // Tant que le module n'est pas connecte
  {
    delay(1000);
    Serial.print(".");
  }

  // Affichage de adresse IP sur le moniteur serie :
  Serial.println("\n adresse IP : ");
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
    
    // Reception
    demande_client = "";
    while ( client.available() )
    {
      demande_client += (char)client.read();  //Serial.print( (char)client.read() );
    }

    // Traitement :
    if(demande_client.indexOf("GET /AVANCE") >= 0)
    {
      Serial.println("Avance");
      led_green_state = !led_green_state;
      UpdateLed(led_green,led_green_state);
    }
    
    if(demande_client.indexOf("GET /GAUCHE") >= 0)
    {
      Serial.println("Gauche");
    }
    
    if(demande_client.indexOf("GET /DROITE") >= 0)
    {
      Serial.println("Droite");
    }
    
    if(demande_client.indexOf("GET /RECULE") >= 0)
    {
      Serial.println("Recule");
      led_yellow_state = !led_yellow_state;
      UpdateLed(led_yellow,led_yellow_state);
    }
    
    if(demande_client.indexOf("GET /STOP") >= 0)
    {
      Serial.println("STOP");
      led_red_state = !led_red_state;
      UpdateLed(led_red,led_red_state);
    }
    
    // Envoie du site internet :
    client.println("<!DOCTYPE html>");
    client.println("<html>");
    client.println("<head><title>RC robot</title></head>");
    client.println("<body><table width=\"100%\" border=\"0\">");
    client.println("<tr valign=\"center\">");
    client.println("<td></td>");
    client.println("<td height=\"200\" align=\"center\"><a href=\"/AVANCE\"><button style=\"width:100%;height:100%\"class=\"button\">AVANCE</button></a></td></tr>");
    client.println("<tr valign=\"center\">");
    client.println("<td height=\"200\" width=\"30%\" align=\"center\"><a href=\"/GAUCHE\"><button style=\"width:100%;height:100%\"class=\"button\">GAUCHE</button></a></td>");
    client.println("<td height=\"200\" width=\"40%\" align=\"center\"><a href=\"/STOP\"><button style=\"width:100%;height:100%\"class=\"button\">STOP</button></a></td>");
    client.println("<td height=\"200\" width=\"30%\" align=\"center\"><a href=\"/DROITE\"><button style=\"width:100%;height:100%\"class=\"button\">DROITE</button></a></td>");
    client.println("</tr>");
    client.println("<td></td>");
    client.println("<td height=\"200\" align=\"center\"><a href=\"/RECULE\"><button style=\"width:100%;height:100%\"class=\"button\">RECULE</button></a></td>");
    client.println("</table>");
    client.println("Radiocommande WiFi<br>");
    client.println("</body></html>");

    // Deconnexion du client :
    client.stop();
  }
  
  delay(50);
}

void UpdateLed(int ledPin,bool led_state)
{
  if (led_state == true)
    digitalWrite(ledPin,HIGH);
  else
    digitalWrite(ledPin,LOW);
}