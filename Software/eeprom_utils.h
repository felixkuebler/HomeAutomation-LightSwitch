#ifndef EEPROM_UTILS
#define EEPROM_UTILS


short int writeCharToEEPROM(short int addr, char character)
{
  EEPROM.write(addr,character);
  EEPROM.commit();
  
  return addr+1;
}

short int readCharFromEEPROM(short int addr, char &character)
{
  character = EEPROM.read(addr);
  
  return addr+1;
}

short int writeStringToEEPROM(short int addr, String str)
{
  for (int i=addr; i<addr+str.length(); i++)
  {
    EEPROM.write(i, str.charAt(i-addr));
  }
  EEPROM.write(addr+str.length(), '\0');
  EEPROM.commit();

  return addr+str.length()+1;
}

short int readStringFromEEPROM(short int addr, String &str)
{
  str="";
  int i=addr;
  
  for (; ; i++)
  {
    char entry = EEPROM.read(i);
    
    if(entry == '\0') break;
    str += entry;  
  }
  return i+1;
}

void saveResetByteToEEPROM(char reset_byte)
{
  writeCharToEEPROM(0, reset_byte);
}

void readResetByteFromEEPROM(char &reset_byte)
{
  readCharFromEEPROM(0,reset_byte);
}
 
void saveSettingsToEEPROM(wifi_obj wifi_info, io_list input_list, io_list output_list)
{
  int addr = sizeof(char);

  addr = writeStringToEEPROM(addr, wifi_info.wifi_ssid);
  addr = writeStringToEEPROM(addr, wifi_info.wifi_pw);
  addr = writeStringToEEPROM(addr, wifi_info.host_name);
  addr = writeStringToEEPROM(addr, wifi_info.host_pw);
  addr = writeStringToEEPROM(addr, wifi_info.mqtt_broker);

  for (io_list::iterator it=input_list.begin(); it!=input_list.end(); ++it)
  {
    addr = writeStringToEEPROM(addr, it->second.topic);
    addr = writeStringToEEPROM(addr, it->second.on_command);
    addr = writeStringToEEPROM(addr, it->second.off_command);
    addr = writeStringToEEPROM(addr, it->second.toggle_command);
  }

  for (io_list::iterator it=output_list.begin(); it!=output_list.end(); ++it)
  {
    addr = writeStringToEEPROM(addr, it->second.topic);
    addr = writeStringToEEPROM(addr, it->second.on_command);
    addr = writeStringToEEPROM(addr, it->second.off_command);
    addr = writeStringToEEPROM(addr, it->second.toggle_command);
  }
}

void loadSettingsFromEEPROM(wifi_obj &wifi_info, io_list &input_list, io_list &output_list)
{
  int addr = sizeof(char);

  String val;
  addr = readStringFromEEPROM(addr, val);
  wifi_info.wifi_ssid=val;
  addr = readStringFromEEPROM(addr, val);
  wifi_info.wifi_pw=val;
  addr = readStringFromEEPROM(addr, val);
  wifi_info.host_name=val;
  addr = readStringFromEEPROM(addr, val);
  wifi_info.host_pw=val;
  addr = readStringFromEEPROM(addr, val);
  wifi_info.mqtt_broker=val;
  
  for (io_list::iterator it=input_list.begin(); it!=input_list.end(); ++it)
  {
    String val;
    addr = readStringFromEEPROM(addr, val);
    it->second.topic=val;
    addr = readStringFromEEPROM(addr, val);
    it->second.on_command=val;
    addr = readStringFromEEPROM(addr, val);
    it->second.off_command=val;
    addr = readStringFromEEPROM(addr, val);
    it->second.toggle_command=val;
  }

  for (io_list::iterator it=output_list.begin(); it!=output_list.end(); ++it)
  {  
     String val;
    addr = readStringFromEEPROM(addr, val);
    it->second.topic=val;
    addr = readStringFromEEPROM(addr, val);
    it->second.on_command=val;
    addr = readStringFromEEPROM(addr, val);
    it->second.off_command=val;
    addr = readStringFromEEPROM(addr, val);
    it->second.toggle_command=val;
  }
}

#endif //EEPROM_UTILS




