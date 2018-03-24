/**@file**/

#ifndef EEPROM_UTILS
#define EEPROM_UTILS


/**
 * writes a given character to a specific address of the eeprom.
 * @param addr address to write to
 * @param character charater written to eeprom
 * @return next writable address
 **/
short int writeCharToEEPROM(short int addr, char character)
{
  EEPROM.write(addr,character);
  EEPROM.commit();
  
  return addr+1;
}

/**
 * reads a character from a specific address of the eeprom.
 * @param addr address to read from
 * @param character character readfrom eeprom
 * @return next readable address
 **/
short int readCharFromEEPROM(short int addr, char &character)
{
  character = EEPROM.read(addr);
  
  return addr+1;
}

/**
 * writes a given string to a specific address of the eeprom.
 * @param addr address to start writing to
 * @param str string written to eeprom
 * @return next writable address
 **/
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

/**
 * reads a string from a specific address of the eeprom.
 * @param addr address to start reading from
 * @param str string read from eeprom
 * @return next readable address
 **/
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

/**
 * writes a single character to the first address of the eeprom.
 * the first character is used as a reset mode indicator
 * @param reset_byte reset indicator char (0:default settings, 1:user setting)
 **/
void saveResetByteToEEPROM(char reset_byte)
{
  writeCharToEEPROM(0, reset_byte);
}

/**
 * reads a single character from the first address of the eeprom.
 * the first character is used as a reset mode indicator
 * @param reset_byte reset indicator char (0:default settings, 1:user setting)
 **/
void readResetByteFromEEPROM(char &reset_byte)
{
  readCharFromEEPROM(0,reset_byte);
}

/**
 * writes all necessary wifi and io settings to the eeprom.
 * @param wifi_info container for wifi settings
 * @param input_list list of container for input settings
 * @param output_list list of container for output settings
 **/
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

/**
 * reades all necessary wifi and io settings from the eeprom.
 * @param wifi_info container for wifi settings
 * @param input_list list of container for input settings
 * @param output_list list of container for output settings
 **/
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




