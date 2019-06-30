/*
  SerialComm.h - Library to send and receive strings of characters.
  Created by Julián Ariel Oviedo, June 23, 2019.
  Released into the public domain.
*/


#ifndef SerialComm_h
#define SerialComm_h
 
#include  <Arduino.h>
#include  <SoftwareSerial.h>

 
class SerialComm
{
  public:
    SerialComm(long baud_rate=9600, long serial_time_out=500);
    void send_data_frame();
    bool get_data_frame();
    String data_to_send; 
    String data_received;
};
 
#endif
