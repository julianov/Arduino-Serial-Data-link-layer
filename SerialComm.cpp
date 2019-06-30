#include "SerialComm.h"

SerialComm::SerialComm(long baud_rate=9600, long serial_time_out=500)
{
   Serial.begin(baud_rate);
   Serial.setTimeout(serial_time_out); // time in mili seconds


   data_received="";
   data_to_send="";
}


void SerialComm::send_data_frame(){
  
  //Serial.println(data_to_send);
  for (int i=0;i<data_to_send.length();i++){
      Serial.write(data_to_send[i]);
      Serial.flush(); 
  }
//  Serial.flush(); 

}

bool SerialComm::get_data_frame()
{
    data_received=""; 
    while (Serial.available() > 0) {
      data_received+=Serial.readString();
      }
  if (data_received!="")
    return true;
  else
    return false;

}
