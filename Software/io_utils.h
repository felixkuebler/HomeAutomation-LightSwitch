#ifndef IO_UTILS
#define IO_UTILS

struct io_obj
{
  String topic;
  short int pin;
  short int state;
  String on_command;
  String off_command;
  String toggle_command;

  io_obj(String topic, short int pin): topic(topic), pin(pin), state(LOW), on_command("1"), off_command("0"), toggle_command("t"){}
};

typedef std::map<String, io_obj> io_list;

void addToIOList(io_list &list, String id, String topic, short int pin, short int io_flag)
{
  pinMode(pin, io_flag);
  io_obj input(topic, pin);
  list.insert(std::make_pair(id, input));
}

String ioListToString(io_list list)
{
  String str;
  for (io_list::iterator it=list.begin(); it!=list.end(); ++it)
  {
    str += it->first + " topic : " + it->second.topic + "\n";
    str += it->first + " on_command : " + it->second.on_command + "\n";
    str += it->first + " off_command : " + it->second.off_command + "\n";
    str += it->first + " toggle_command : " + it->second.toggle_command + "\n";

  }
  return str;
}
  
#endif //IO_UTILS



