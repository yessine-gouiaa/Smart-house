#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include "DHTesp.h"

#include <ESP32Servo.h>
// parametre wifi
//const char *ssid = "TOPNET_0530";
//const char *password = "drealkv03u";

const char *ssid = "TOPNET_0530";
const char *password = "drealkv03u";

//pins :      

#define ledsalon 22
#define ledgarage 5
#define ledcuisine 21
#define ledterrace 12
#define  gazbuzzer  23    
#define  gazsensor 33
#define vent  18
//#define DHTPIN 25
#define  firesensor 27
#define  firebuzzer  14
#define rainsensor 34

#define lumsensor 19
#define trig 26
#define eco 32


Servo servogarage;
Servo servofenetre;



String stateledsalon = " ";
String stateledgarage = " ";
String stateledcuisine = " ";
String stateledterrace = " ";
String gazstate = " ";
String ventstate = " ";
String firestate = " ";
String rainstate = " ";
String lumstate = " ";
DHTesp dht;
float temperature ;
int temp = 25 ;
long ultrason_duration;
float distance_cm;
const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m à 340m/s

/* Vitesse du son dans l'air en mm/us */
const float SOUND_SPEED = 340.0 / 1000;

String capgaz = "on";
String caprain = "on";
String capfire = "on";
String capvent = "on";
String caplum = "on";
String statecapgaz = " ";
String statecaprain = " ";
String statecapfire = " ";
String statecapvent = " ";
String statecaplum = " ";
String CGOS = " ";
String CROS = " ";
String CFOS = " ";
String CVOS = " ";
String CLOS =" ";
String capmov ="";
String statecapmov ="";
String CMOS="";
String servofenetrestate="";
String garage="";
String stateservogarage="";
String fenetre ="";


// serveur asynchrone 

AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);

  pinMode(ledsalon, OUTPUT);
  pinMode(ledgarage , OUTPUT);
  pinMode(ledcuisine , OUTPUT);
  pinMode(ledterrace , OUTPUT);
  pinMode(gazbuzzer , OUTPUT);
  pinMode(gazsensor , INPUT);
  pinMode(vent, OUTPUT);
  pinMode(firesensor, INPUT);
  pinMode(firebuzzer,OUTPUT);
  pinMode(rainsensor, INPUT);
  pinMode(lumsensor, INPUT);
  pinMode(trig,OUTPUT);
  pinMode(eco,INPUT);
  digitalWrite(trig, LOW); // La broche TRIGGER doit être à LOW au repos
  
  dht.setup(25, DHTesp::DHT11);
  servogarage.attach(4);
  servofenetre.attach(15);
//******************************* vérification des fichiers dans la mémoire **********
  if(!SPIFFS.begin())
  {
    Serial.println("Erreur SPIFFS...");
    return;
  }

  File root = SPIFFS.open("/");
  File file = root.openNextFile();

  while(file)
  {
    Serial.print("File: ");
    Serial.println(file.name());
    file.close();
    file = root.openNextFile();
  }

  //************** connexion au wifi **************
  WiFi.begin(ssid, password);
	Serial.print("Tentative de connexion...");
	
	while(WiFi.status() != WL_CONNECTED)
	{
		Serial.print(".");
		delay(100);
	}
	
	Serial.println("\n");
	Serial.println("Connexion etablie!");
	Serial.print("Adresse IP: ");
	Serial.println(WiFi.localIP());
  server.begin();
  Serial.println("Serveur actif!");

  //************************  chargement des fichiers ****************** 
  server.on("/select.html", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    request->send(SPIFFS, "/select.html", "text/html");
  });
   server.on("/select.js", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    request->send(SPIFFS, "/select.js", "text/javascript");
  });
   server.on("/select.css", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    request->send(SPIFFS, "/select.css", "text/css");
  });
   server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    request->send(SPIFFS, "/login.html", "text/html");
  });

 server.on("/login.css", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    request->send(SPIFFS, "/login.css", "text/css");
  });

  server.on("/script.js", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    request->send(SPIFFS, "/script.js", "text/javascript");
  });
  server.on("/login.js", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    request->send(SPIFFS, "/login.js", "text/javascript");
  });
  server.on("/PA.html", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    request->send(SPIFFS, "/PA.html", "text/html");
      });
      server.on("/PC.html", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    request->send(SPIFFS, "/PC.html", "text/html");
      });
       server.on("/PE.html", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    request->send(SPIFFS, "/PE.html", "text/html");
      });


//******************** réponses aux requetes du client ************

  server.on("/tempup", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    
    temp = temp +1 ;
    request->send(200);
  });

  server.on("/tempdown", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    temp = temp -1 ;
    request->send(200);
  });

  server.on("/lireTemp", HTTP_GET, [](AsyncWebServerRequest *request)
  {
   request->send(200, "text/plain", String(temp));
     
  });


 server.on("/lireTemperature", HTTP_GET, [](AsyncWebServerRequest *request)
  {
   temperature = dht.getTemperature();
   Serial.print("temperature:");
   Serial.println(temperature);  
  

   if(capvent == "on"){
    statecapvent ="activé";
    if (temperature > temp) {   
    digitalWrite (vent, HIGH) ;
    ventstate ="ventilateur en marche";
   }
  else {
    digitalWrite (vent, LOW) ;
     ventstate = "ventilateur est en repos";
    }
   }
   else{
     statecapvent ="désactivé";
     ventstate="activer la ventilateur dans le menu commande";
   }
     request->send(200, "text/plain", String(temperature));
    });
  server.on("/lirEtatvent", HTTP_GET, [](AsyncWebServerRequest *request)
  {
request->send(200, "text/plain", ventstate);
    });

     server.on("/capvent", HTTP_GET, [](AsyncWebServerRequest *request)
  {
request->send(200, "text/plain", statecapvent);
    });

  server.on("/lireHumidity", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    

  float humidity = dht.getHumidity();
  
   Serial.print("humidity:");
   Serial.println(humidity);
    request->send(200, "text/plain", String(humidity));
    
   
  });

  server.on("/onvent", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    digitalWrite(vent, HIGH);
    CVOS= "si la ventilateur  marche tt est bien";
    request->send(200);
  });

  server.on("/offvent", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    digitalWrite(vent, LOW);
    CVOS ="si la ventilateur est atteint tt est bien ";
    request->send(200);
  });
  server.on("/cvo", HTTP_GET, [](AsyncWebServerRequest *request)
  {
   
    request->send(200, "text/plain", CVOS );
    
  });
  
  server.on("/oncapvent", HTTP_GET, [](AsyncWebServerRequest *request)
  {
   capvent = "on";
    request->send(200);
  });

  server.on("/offcapvent", HTTP_GET, [](AsyncWebServerRequest *request)
  {
   capvent ="off";
    request->send(200);
  });
  



//*******************capteur incendie****************

  server.on("/lirefirestate", HTTP_GET, [](AsyncWebServerRequest *request)
  {
  int flame = digitalRead(firesensor);
  Serial.print("Flame Sensor - ");
   Serial.println(flame);
     if(capfire == "on"){
        statecapfire ="activé";
       
      if (flame == 0) {   
      digitalWrite(firebuzzer, HIGH);
      
    firestate ="IL Y A UNE INCENDIE!!!!!";
    
    }
  else {
     digitalWrite(firebuzzer, LOW);
   firestate ="pas d'incendie détecté"; 
  }
      }
   else{
    statecapfire ="désactivé";
    firestate="activer le capteur d'incendie dans le panneau de commande";
 }
      request->send(200, "text/plain", firestate);
    });
    server.on("/lirecapfirestate", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    request->send(200, "text/plain", statecapfire);

      });

    server.on("/onincendie", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    CFOS = "si le buzzer  marche tt est bien";
    //for(int i = 0 ; i < 500 ; i++)
//{  
digitalWrite(firebuzzer, HIGH);
   
    
    request->send(200);
  });

  server.on("/offincendie", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    digitalWrite(firebuzzer, LOW);
    
    CFOS ="si le buzzer est atteint tt est bien ";
    request->send(200);
  });

  server.on("/cfo", HTTP_GET, [](AsyncWebServerRequest *request)
  {
   
    request->send(200, "text/plain", CFOS );
    
  });

  server.on("/oncapincendie", HTTP_GET, [](AsyncWebServerRequest *request)
  {
   capfire="on";
    request->send(200);
  });

  server.on("/offcapincendie", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    capfire="off";
    request->send(200);
  });
  

  
    
    
    
    //********************** capteur GAZ****************************
 
  server.on("/liregazstate", HTTP_GET, [](AsyncWebServerRequest *request)
  {
   float sensor_Aout = analogRead(gazsensor);  
  Serial.print("Gas Sensor: ");  
  Serial.println(sensor_Aout);   
  
   if(capgaz =="on"){
     statecapgaz="activé";
   if (sensor_Aout > 2000) {   
    digitalWrite (gazbuzzer, HIGH) ;
    gazstate ="il y a une fuite ATTENTION!!!";  
  }
  else  {
    
    digitalWrite (gazbuzzer, LOW) ;  
    gazstate = "pas de fuite"; 
  }
  }else{
    statecapgaz="désactivé";
    gazstate="activer le capteur de gaz dans le panneau de commande";
  }
 request->send(200, "text/plain", gazstate);
  });

server.on("/lirecapgazstate", HTTP_GET, [](AsyncWebServerRequest *request)
  {
 request->send(200, "text/plain",statecapgaz);
    });

  //------------------verif capteur gaz----------------
  server.on("/ongaz", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    digitalWrite(gazbuzzer, HIGH);
    
    CGOS = "si le buzzer marche tt est bien";
    request->send(200);
  });

  server.on("/offgaz", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    digitalWrite(gazbuzzer, LOW);
   
    CGOS ="si le buzzer est atteint tt est bien ";
    request->send(200);
  });

  server.on("/cgo", HTTP_GET, [](AsyncWebServerRequest *request)
  {
   
    request->send(200, "text/plain", CGOS );
    
  });

   server.on("/oncapgaz", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    
   capgaz="on";
   request->send(200);
  });

  server.on("/offcapgaz", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    capgaz="off";
    request->send(200);
  });
  
  //*******************************************




server.on("/lirerainstate", HTTP_GET, [](AsyncWebServerRequest *request)
  {
   float rain_amount = analogRead(rainsensor);  
  Serial.print("rain Sensor: ");  
  Serial.println(rain_amount);   
  
  if(caprain == "on"){
    statecaprain="activé";
    if (rain_amount > 200) {   
    Serial.println("pluie");  
    rainstate ="il y a du pluie";
    
  }
  else {
    rainstate = "pas de pluie";
  }
  }
  else{
    statecaprain="désactivé";
    rainstate="activer le capteur de pluie dans le panneau de commande";
    
 }
 request->send(200, "text/plain", rainstate);
   });

  server.on("/lirecaprainstate", HTTP_GET, [](AsyncWebServerRequest *request)
  {
request->send(200, "text/plain", statecaprain);
 });
 
  //------------------verif capteur gaz----------------
  server.on("/onrain", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    
    CROS = "si le buzzer marche tt est bien";
    request->send(200);
  });

  server.on("/offrain", HTTP_GET, [](AsyncWebServerRequest *request)
  {

    CROS ="si le buzzer est atteint tt est bien ";
    request->send(200);
  });

  server.on("/cro", HTTP_GET, [](AsyncWebServerRequest *request)
  {
   
    request->send(200, "text/plain", CROS );
    
  });

  server.on("/oncaprain", HTTP_GET, [](AsyncWebServerRequest *request)
  {
   caprain = "on";
    request->send(200);
  });

  server.on("/offcaprain", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    caprain ="off";
    request->send(200);
  });
  
  //*******************************************

  server.on("/servofenetre", HTTP_GET, [](AsyncWebServerRequest *request)
  {

  if ((( rainstate =="il y a du pluie") && (gazstate =="pas de fuite")||(fenetre=="on"))){
  servofenetre.write(0);
  servofenetrestate="fenetre fermé";}
 else if ((( rainstate =="pas de  pluie") && (gazstate =="il y a une fuite ATTENTION!!!")||(fenetre=="off"))){
  servofenetre.write(90);
  servofenetrestate="fenetre ouvert";
 }
 else if ((( rainstate =="pas de  pluie") && (gazstate =="il y a une fuite ATTENTION!!!") ||(fenetre=="on"))){
  servofenetre.write(90);
  servofenetrestate="fenetre ouvert";
 }
 else if ((( rainstate =="il y a du pluie") && (gazstate =="pas de fuite") ||(fenetre=="off"))){
  servofenetre.write(90);
  servofenetrestate="fenetre ouvert";
 }
 else  {
  servofenetrestate="fenetre pas controlé";
 }
request->send(200, "text/plain", servofenetrestate);
 });

server.on("/servogarage", HTTP_GET, [](AsyncWebServerRequest *request)
  {

 if (garage=="on"){
  servogarage.write(90);
stateservogarage="portié fermé";
 }
 else{
  servogarage.write(0);
stateservogarage="portié ouvert";
 }
request->send(200, "text/plain", stateservogarage);
 });

 server.on("/onservogarage", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    
   garage ="on";
   
   request->send(200);
  });

  server.on("/offservogarage", HTTP_GET, [](AsyncWebServerRequest *request)
  {
   garage = "off";
   
    request->send(200);
  });

  server.on("/onservofenetre", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    
   fenetre ="on";
   
   request->send(200);
  });

  server.on("/offservofenetre", HTTP_GET, [](AsyncWebServerRequest *request)
  {
   fenetre = "off";
   
    request->send(200);
  });




server.on("/oncaplum", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    
   caplum="on";
   statecaplum="capteur activé";
   request->send(200);
  });

  server.on("/offcaplum", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    caplum="off";
      statecaplum="capteur désactivé";
    request->send(200);
  });
  server.on("/lirstatecaplum", HTTP_GET, [](AsyncWebServerRequest *request)
  {
   
   float lumval = digitalRead(lumsensor);
 
  // Afficher la valeur du capteur sur le moniteur série
  Serial.print("Valeur du capteur lum : ");
  Serial.println(lumval);
  Serial.print("valeur capteur ultrason:");
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long measure = pulseIn(eco, HIGH, MEASURE_TIMEOUT);
  float distance_mm = measure / 2.0 * SOUND_SPEED;
  Serial.println(distance_mm / 10.0, 2);
  
  if(caplum == "on"){

  if ((lumval == 1) && (distance_mm < 100 )){
    digitalWrite(ledsalon, HIGH);
    digitalWrite(ledgarage, HIGH);
    digitalWrite(ledcuisine, HIGH);
    digitalWrite(ledterrace, HIGH);
  }
  else{
    digitalWrite(ledsalon, LOW);
    digitalWrite(ledgarage, LOW);
    digitalWrite(ledcuisine, LOW);
    digitalWrite(ledterrace, LOW);
   }
  }else{}
   request->send(200, "text/plain", statecaplum );
   });
 server.on("/ultrason", HTTP_GET, [](AsyncWebServerRequest *request)
  {
   
  

    request->send(200, "text/plain", String(distance_cm) );
    
  });
  


  //****************capteur led salon**************
  server.on("/onledsalon", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    if(caplum =="off"){
    stateledsalon = "allumée";
    
    digitalWrite(ledsalon, HIGH);
    
 
  }else{
    stateledsalon =("desactiver le capteur de luminosité pour controler l'eclairage manuellement");
   }
   request->send(200);
 });
  server.on("/offledsalon", HTTP_GET, [](AsyncWebServerRequest *request)
  {
   if(caplum =="off"){
    digitalWrite(ledsalon, LOW);
    stateledsalon = "éteinte";;
    
   
   }else{
    stateledsalon =("desactiver le capteur de luminosité pour controler l'eclairage manuellement");
   }  request->send(200, "text/plain", stateledsalon );
  });
   server.on("/lirEtatledsalon", HTTP_GET, [](AsyncWebServerRequest *request)
  {
   
    request->send(200, "text/plain", stateledsalon );
    
  });
  
  
  
  //------------------------------capteur led garage----------------------
server.on("/onledgarage", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    if(caplum =="off"){
    digitalWrite(ledgarage, HIGH);
    stateledgarage = "allumée";
   

     }else{
       stateledgarage =("desactiver le capteur de luminosité pour controler l'eclairage manuellement");
   } request->send(200);
  });

  server.on("/offledgarage", HTTP_GET, [](AsyncWebServerRequest *request)
  {
     if(caplum =="off"){
    digitalWrite(ledgarage, LOW);
    stateledgarage ="eteinte";
   
    }else{
       stateledgarage =("desactiver le capteur de luminosité pour controler l'eclairage manuellement");
   } request->send(200);
  });
 

  server.on("/lirEtatledgarage", HTTP_GET, [](AsyncWebServerRequest *request)
  {
   
    request->send(200, "text/plain", stateledgarage );
  });


   
   
   
   //------------------------------capteur led cuisine----------------------
server.on("/onledcuisine", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    if(caplum =="off"){
    digitalWrite(ledcuisine, HIGH);
    stateledcuisine = "allumée";
   
    }else{
       stateledcuisine =("desactiver le capteur de luminosité pour controler l'eclairage manuellement");
   } request->send(200);
  });

  server.on("/offledcuisine", HTTP_GET, [](AsyncWebServerRequest *request)
  {
     if(caplum =="off"){
    digitalWrite(ledcuisine, LOW);
    stateledcuisine ="eteinte";
   
    }else{
       stateledcuisine =("desactiver le capteur de luminosité pour controler l'eclairage manuellement");
   } request->send(200);
  });
 

  server.on("/lirEtatledcuisine", HTTP_GET, [](AsyncWebServerRequest *request)
  {
   
    request->send(200, "text/plain", stateledcuisine );
  });


 
 
 
  //------------------------------capteur led terrace----------------------
server.on("/onledterrace", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    if(caplum =="off"){
    digitalWrite(ledterrace, HIGH);
    stateledterrace = "allumée";
   
    }else{
       stateledterrace =("desactiver le capteur de luminosité pour controler l'eclairage manuellement");
   } request->send(200);
  });

  server.on("/offledterrace", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    if(caplum =="off"){
    digitalWrite(ledterrace, LOW);
    stateledterrace ="eteinte";
    
     }else{
       stateledterrace =("desactiver le capteur de luminosité pour controler l'eclairage manuellement");
   }request->send(200);
  });
 

  server.on("/lirEtatledterrace", HTTP_GET, [](AsyncWebServerRequest *request)
  {
   
    request->send(200, "text/plain", stateledterrace );
  });
  //-------------------------------------
   



}




void loop() {

  
}