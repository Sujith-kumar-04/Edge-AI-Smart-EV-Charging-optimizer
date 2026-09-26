#include <Arduino.h>
#include <WiFi.h>
#include "State.h"
#include "config.h"
#include "Peripherals.h"
#include "Network.h"
#include "Telemetry.h"
#include "model.h"
#include "edge_ai.h"
#include "optimization.h"
#include "rpc.h"
#include "attributes.h"



void setup()
{

    //initialise serial moniter
    Serial.begin(115200);
    dht.begin();
    //config esp32 with real time
    configTime(0,0,"pool.ntp.org", "time.nist.gov");  
    //config periperal pins
    pinMode(BTN_PLUGIN, INPUT_PULLUP );
    pinMode(BTN_PLUGOUT, INPUT_PULLUP );
    pinMode(RELAY_PIN, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_YELLOW, OUTPUT);
    pinMode(LED_RED, OUTPUT);

    //connect Board to wifi
    connectWiFi();

    
    // Configure MQTT server
    mqtt.setServer(MQTT_SERVER, MQTT_PORT); //mqqt server addr of things and port number
    //set call back function upon reciving data from the cloud
    mqtt.setCallback(mqttCallback);
    mqtt.setBufferSize(512);

    
   //connect board to the cloud
   connectMQTT() ; // TOKEN , device id

}

unsigned long now;
unsigned long last_print;

void loop()
{
  //listen to incoming request
  mqtt.loop();

    //print data every 5 sec
    now = millis();
    if((now - last_print) > 5000)
    {
        last_print = now;
         // read data from sensor  // voltage , current , temperature , power , baby status
         sample_semsor();
         //run AI to get prediction
        runEdgeAIInference();
        // decide load based on the precdictions
        if(manualOverrideActive == 0)
        {
         runOptimization();
        }
        //publish the data
        publishTelemetry() ;
        
        
    }
    plug_status();
    updateLeds();
    
}

