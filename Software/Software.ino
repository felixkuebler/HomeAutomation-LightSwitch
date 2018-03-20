
#include <map>
#include <vector>

#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h> 
#include <PubSubClient.h>
#include <ESP8266HTTPUpdateServer.h>
#include <EEPROM.h>

#include "utils.h"
#include "io_utils.h"
#include "wifi_utils.h"
#include "eeprom_utils.h"
#include "web_interface.h"


io_list input_list;
io_list output_list;

wifi_obj wifi_info;

short int reset_pin;


DNSServer dnsServer;
ESP8266WebServer wifiServer(80);
WiFiClient wifiClient;
ESP8266HTTPUpdateServer wifiUpdater;
PubSubClient client(wifiClient);


CONFIG setup_type = default_config;
bool network_available = false;



/*
 * this function is called when a html request was send to the local html server
 */
void htmlHandleRequest() 
{

  //webrequest for output
  for (io_list::iterator it=output_list.begin(); it!=output_list.end(); ++it)
  {
    //get name of output
    String val = wifiServer.arg(it->second.topic);
    //check if message is not empty
    if(val.length()>0)
    {
      Serial.print("Setting " + it->second.topic + " to ");

      int trigger_value = -1;
      
      //set changes
      if(strcmp(val.c_str(),"toggle") == 0) 
      {
        if(it->second.state == HIGH)
        {
          trigger_value = LOW;
          Serial.println("OFF");
        }
        else
        {
          trigger_value = HIGH;
          Serial.println("ON");
        }
      }
      else if(strcmp(val.c_str(),"on") == 0) 
      {
        trigger_value = HIGH;
        Serial.println("ON");
      }
      else if(strcmp(val.c_str(),"off") == 0) 
      {
        trigger_value = LOW;
        Serial.println("OFF");
      }


      if(trigger_value != -1)
      { 
        it->second.state = trigger_value;
        digitalWrite(it->second.pin, trigger_value);
      }
    }  
  }
     



  
  
  //get ssid request message from client
  String val = wifiServer.arg("wifi_ssid");
  //check if a message is not empty
  if(val.length()>0)
  {
    //set changes
    if(strcmp(val.c_str(),"-1") == 0) val="";
    Serial.println("wifi_ssid : " + val);
    wifi_info.wifi_ssid = val;
  }

  //get pw request message from client
  val = wifiServer.arg("wifi_pw");
  //check if a message is not empty
  if(val.length()>0)
  {
    //set changes
    if(strcmp(val.c_str(),"-1") == 0) val="";
    Serial.println("wifi_pw : " + val);
    wifi_info.wifi_pw = val;
  }

  //get host name request message from client
  val = wifiServer.arg("host_name");
  //check if a message is not empty
  if(val.length()>0)
  {
    //set changes
    if(strcmp(val.c_str(),"-1") == 0) val="";
    Serial.println("host name : " + val);
    wifi_info.host_name = val;
  }

  //get host name request message from client
  val = wifiServer.arg("host_pw");
  //check if a message is not empty
  if(val.length()>0)
  {
    //set changes
    if(strcmp(val.c_str(),"-1") == 0) val="";
    Serial.println("host pw : " + val);
    wifi_info.host_pw = val;
  }
  
  //get mqtt broker request message from client
  val = wifiServer.arg("mqtt_broker");
  //check if a message is not empty
  if(val.length()>0)
  {
    //set changes
    if(strcmp(val.c_str(),"-1") == 0) val="";
    Serial.println("mqtt broker : " + val);
    wifi_info.mqtt_broker = val;
  }
 
  //loop will apply changes to the input settings
  for (io_list::iterator it=input_list.begin(); it!=input_list.end(); ++it)
  {
    //get topic from client
    val = wifiServer.arg(it->first + "_topic");
    //check if message is not empty
    if(val.length()>0)
    {
      if(strcmp(val.c_str(),"-1") == 0) val="";
      Serial.println(it->first + "_topic : " + val);
      //apply changes
      it->second.topic = val;
    }

    //get on command from client
    val = wifiServer.arg(it->first + "_on_command");
    //check if message is not empty
    if(val.length()>0)
    {
      if(strcmp(val.c_str(),"-1") == 0) val="";
      Serial.println(it->first + "_on_command : " + val);
      //apply changes
      it->second.on_command = val;
    }

    //get off command from client
    val = wifiServer.arg(it->first + "_off_command");
    //check if message is not empty
    if(val.length()>0)
    {
      if(strcmp(val.c_str(),"-1") == 0) val="";
      Serial.println(it->first + "_off_command : " + val);
      //apply changes
      it->second.off_command = val;
    }

    //get toggle command from client
    val = wifiServer.arg(it->first + "_toggle_command");
    //check if message is not empty
    if(val.length()>0)
    {
      if(strcmp(val.c_str(),"-1") == 0) val="";
      Serial.println(it->first + "_toggle_command : " + val);
      //apply changes
      it->second.toggle_command = val;
    }
  }

  //loop will apply output changes
  for (io_list::iterator it=output_list.begin(); it!=output_list.end(); ++it)
  {
    //get topic from client
    val = wifiServer.arg(it->first + "_topic");
    //check if message is not empty
    if(val.length()>0)
    {
      if(strcmp(val.c_str(),"-1") == 0) val="";
      Serial.println(it->first + "_topic : " + val);
      //apply changes
      it->second.topic = val;
    }

    //get on command from client
    val = wifiServer.arg(it->first + "_on_command");
    //check if message is not empty
    if(val.length()>0)
    {
      if(strcmp(val.c_str(),"-1") == 0) val="";
      Serial.println(it->first + "_on_command : " + val);
      //apply changes
      it->second.on_command = val;
    }

    //get off command from client
    val = wifiServer.arg(it->first + "_off_command");
    //check if message is not empty
    if(val.length()>0)
    {
      if(strcmp(val.c_str(),"-1") == 0) val="";
      Serial.println(it->first + "_off_command : " + val);
      //apply changes
      it->second.off_command = val;
    }

    //get toggle command from client
    val = wifiServer.arg(it->first + "_toggle_command");
    //check if message is not empty
    if(val.length()>0)
    {
      if(strcmp(val.c_str(),"-1") == 0) val="";
      Serial.println(it->first + "_toggle_command : " + val);
      //apply changes
      it->second.toggle_command = val;
    }
  }

  //get reset trigger from client
  String reset_settings = wifiServer.arg("reset_settings");
  //check if a reset was triggered
  if(reset_settings.length()>0)
  {
    Serial.println("System Settings set to default");
    //write reset flag to eeprom to use after a system reboot
    writeCharToEEPROM(0, 0);

    //reboot system
    ESP.eraseConfig();
    ESP.reset();
  }

  //get save trigger from client
  String save_settings = wifiServer.arg("save_settings");
  //check if save was triggered
  if(save_settings.length()>0)
  {
    Serial.println("user settings saved, system is going to restart");

    //save local changes to eeprom
    saveSettingsToEEPROM(wifi_info, input_list, output_list);
    writeCharToEEPROM(0, 1);
    
    //reboot system
    ESP.eraseConfig();
    ESP.reset();
  }

  //give wifiServer new webpage
  wifiServer.send(200, "text/html", generateWebpage(wifi_info, input_list, output_list));
}


/*
 * this function is called when a mqtt post was received
 */
void mqttSubscribeCallback(char* topic, byte* payload, unsigned int length) 
{  
  //loop through all available outputs
  for (io_list::iterator it=output_list.begin(); it!=output_list.end(); ++it)
  {
    //check if subscribe topic is equal to output topic
    if (strcmp(topic,(it->second.topic).c_str())==0)
    {
      //turn byte* into String
      String msg ="";
      for(int i=0; i<length; i++)
      {
        msg+=(char)payload[i];
      }

      Serial.print("mqtt post \"");
      Serial.print(msg);
      Serial.print("\" on topic \"");
      Serial.print(topic);
      Serial.println("\" received");
  
      short int trigger_value = -1;
      
      if(it->second.on_command.length()>0 && strcmp(msg.c_str(),it->second.on_command.c_str())==0)
      {
        trigger_value = 1;
      }
      else if(it->second.off_command.length()>0 && strcmp(msg.c_str(),it->second.off_command.c_str())==0)
      {
        trigger_value = 0;
      }
      else if(it->second.toggle_command.length()>0 && strcmp(msg.c_str(),it->second.toggle_command.c_str())==0)
      {
        if (it->second.state == 0)
        {
          trigger_value = 1;
        }
        else 
        {
          trigger_value = 0;
        }
      }

      if(trigger_value != -1)
      {
        //write value to pin
        Serial.print("set ");
        Serial.print(it->first);
        Serial.print(" to ");
        Serial.println(trigger_value);
      
        it->second.state = trigger_value;
        digitalWrite(it->second.pin, trigger_value);
      }
      else
      {
        Serial.print("unknown command");
      }
    }
  }
}

/*
 * this function is called a interrupt was triggerd on an input pin
 */
void mqttPublishCallback() 
{  
  //loop through inputs
  for (io_list::iterator it=input_list.begin(); it!=input_list.end(); ++it)
  {
    //reade current state from pin
    short int state = digitalRead(it->second.pin);
    //compare to last known state
    if(state!=it->second.state)
    {
      //change to new state
      it->second.state=state;
      
      //write value to pin
      Serial.print("io input triggered by ");
      Serial.println(it->first);

      if(it->second.on_command.length()>0 && state==HIGH)
      {
        Serial.print("post \"");
        Serial.print(it->second.on_command);
        Serial.print("\" on topic \"");
        Serial.print(it->second.topic);
        Serial.println("\"");
        //publish on command to pin topic
        client.publish((it->second.topic).c_str(), (it->second.on_command).c_str());
      }

      if(it->second.off_command.length()>0 && state==LOW)
      {
        Serial.print("post \"");
        Serial.print(it->second.off_command);
        Serial.print("\" on topic \"");
        Serial.print(it->second.topic);
        Serial.println("\"");
        //publish off command to pin topic
        client.publish((it->second.topic).c_str(), (it->second.off_command).c_str());
      }

      if(it->second.toggle_command.length()>0)
      {
        Serial.print("post \"");
        Serial.print(it->second.toggle_command);
        Serial.print("\" on topic \"");
        Serial.print(it->second.topic);
        Serial.println("\"");
        //publish toggle command to pin topic
        client.publish((it->second.topic).c_str(), (it->second.toggle_command).c_str());
      }
    }
  }
}

/*
 * this function tryes to reconnect the mqtt client to the mqtt broker
 */
void mqttReconnect() 
{
  //repeat until a connection is astablished
  if (!client.connected()) 
  {
    Serial.print("attempting mqtt connection to ");
    Serial.print(wifi_info.mqtt_broker);
    Serial.print(" as ");
    Serial.print(wifi_info.host_name);
    Serial.print("...");
    
    // attempt to connect
    if (client.connect(wifi_info.host_name.c_str()))
    {
      Serial.println("  ok");

      //setup subscribe topics for relays
      for (io_list::iterator it=output_list.begin(); it!=output_list.end(); ++it)
      {
        //add ouputs to mqtt subscriber list
        client.subscribe((it->second.topic).c_str());
      }
    } 
    else 
    {
      //print error value
      Serial.print("  fail, rc=");
      Serial.println(client.state());
    }
  }
}


/*
 * this function will setup all wifi functions
 */
void wifi_setup(char reset_byte)
{
  //check reset indicatior
  if(reset_byte==0)
  {
    //reset was applied
    Serial.println("0  -> reset to default config");
    
    //save default settings to eeprom
    Serial.println("save default settings to epprom");
    Serial.print(wifiToString(wifi_info));
    Serial.print(ioListToString(input_list));
    Serial.print(ioListToString(output_list));
    saveSettingsToEEPROM(wifi_info, input_list, output_list);

    //start access point for settings configuration 
    Serial.println("start access point");
    WiFi.softAPdisconnect(true);
    WiFi.disconnect();
    WiFi.mode(WIFI_AP);
    delay(100);
    WiFi.hostname(wifi_info.host_name);
    WiFi.softAPConfig(IPAddress(192, 168, 1, 1), IPAddress(192, 168, 1, 1), IPAddress(255, 255, 255, 0));
    WiFi.softAP(wifi_info.host_name.c_str());

    Serial.println("start dns captive portal");
    dnsServer.start(53, "*", IPAddress(192, 168, 1, 1));

    setup_type = default_config;
  }
  else
  {
    //reset was not applied
    Serial.println("1  -> load user config");

    //load settings from eeprom, make backup of wifi_info
    Serial.println("load settings from epprom");
    wifi_obj wifi_info_backup = wifi_info;
    loadSettingsFromEEPROM(wifi_info, input_list, output_list);
    Serial.print(wifiToString(wifi_info));
    Serial.print(ioListToString(input_list));
    Serial.print(ioListToString(output_list));
    
    //connect to wifi network
    Serial.println("start as wifi client station");
    WiFi.softAPdisconnect(true);
    WiFi.disconnect();
    WiFi.mode(WIFI_STA);
    delay(100);
    WiFi.hostname(wifi_info.host_name);

    if(wifi_info.wifi_pw.length()>0)
    {
      WiFi.begin(wifi_info.wifi_ssid.c_str(), wifi_info.wifi_pw.c_str());
    }
    else
    {
      WiFi.begin(wifi_info.wifi_ssid.c_str());
    }

    //wait for wifinetwork, timeout after 20 seconds
    Serial.print("connecting to ");
    Serial.print(wifi_info.wifi_ssid);
    Serial.print("...");
    bool timeout = false;
    for(int timer = 0; WiFi.status() != WL_CONNECTED; timer++)
    {
      delay(500);
      Serial.print(".");

      if(timer>=40)
      {
        timeout = true;
        break;
      }
    }

    //check if timeout occured
    if(timeout)
    {
      //timeout was triggered
      Serial.println(" fail");
      
      //start access point if connection to network not possible
      Serial.println("start as accesspoint");
      WiFi.softAPdisconnect(true);
      WiFi.disconnect();
      WiFi.mode(WIFI_AP);
      delay(100);
      WiFi.hostname(wifi_info.host_name);
      WiFi.softAPConfig(IPAddress(192, 168, 1, 1), IPAddress(192, 168, 1, 1), IPAddress(255, 255, 255, 0));

      if(wifi_info.host_pw.length()>0)
      {
        WiFi.softAP(wifi_info.host_name.c_str(), wifi_info.host_pw.c_str());
      }
      else
      {
        WiFi.softAP(wifi_info.host_name.c_str());
      }

      Serial.println("start dns captive portal");
      dnsServer.start(53, "*", IPAddress(192, 168, 1, 1));

      setup_type=backup_config;

      network_available = networkAvailable(wifi_info.wifi_ssid);

    }
    else 
    {
      //no timeout
      Serial.println(" ok");

      //start mqtt client
      Serial.println("start mqtt pub/sub client");
      client.setServer(wifi_info.mqtt_broker.c_str(), 1883);
      client.setCallback(mqttSubscribeCallback);

      setup_type = user_config;
    }
  }
    
  //define request actions
  wifiServer.onNotFound(htmlHandleRequest);

  //start http server
  Serial.println("start http server");
  wifiUpdater.setup(&wifiServer);
  wifiServer.begin();
}


/*
 * on system boot this function is called once for setup purposes
 */
void setup(void)
{
  //start serial connection
  Serial.begin(9600);

  //add switches with default values
  addToIOList(input_list, "switch_1", "switch_1", 16, INPUT);
  addToIOList(input_list, "switch_2", "switch_2", 14, INPUT);

  //add relays with default values
  addToIOList(output_list, "relay_1", "relay_1", 12, OUTPUT);
  addToIOList(output_list, "relay_2", "relay_2", 13, OUTPUT);

  //add default wifi info
  wifi_info = wifi_obj("HA_Node_005");

  reset_pin = 4;

  //define eeprom space
  EEPROM.begin(512);

  //read first byte of eeprom as reset indicatior
  Serial.print("read reset byte from eeprom: ");
  char reset_byte;
  readCharFromEEPROM(0, reset_byte);
  
  wifi_setup(reset_byte);
}


/*
 * main loop that evaluates dns, wifiServer and mqtt events
 */
void loop(void)
{
  //check if a connection to network was established
  if(setup_type==user_config)
  {
    //try to connect to mqtt broker
    mqttReconnect();

    //if connection lost reboot
    if(WiFi.status() != WL_CONNECTED)
    {
      WiFi.softAPdisconnect(true);
      WiFi.disconnect();
      delay(100);
      wifi_setup(1);
      
      //reboot system
      //ESP.eraseConfig();
      //ESP.reset();
    }
  }
  else if(setup_type==backup_config)
  {
    //check if a network exists that matches the users network that did not exist before
    if(!network_available)
    {
      if(networkAvailable(wifi_info.wifi_ssid))
      {
        WiFi.softAPdisconnect(true);
        WiFi.disconnect();
        delay(100);
        wifi_setup(1);
      
        //reboot system
        //ESP.eraseConfig();
        //ESP.reset();
      }
    }
  }

  //repeat following commands 100 times before next mqtt reconnect attempt
  for (short int timeout = 0; timeout < 100; timeout++)
  { 
    //check if a connection to network was established
    if(setup_type==user_config)
    {
      //handle mqtt client
      client.loop();
      mqttPublishCallback();
    }

    dnsServer.processNextRequest();
    wifiServer.handleClient();

    delay(50);
  }

  //check for hardware reset
  if(digitalRead(reset_pin)==HIGH)
  {
    /*
    Serial.print("reset button high");
    writeCharToEEPROM(0, 0);
    ESP.eraseConfig();
    ESP.reset();
    */
  }
}



