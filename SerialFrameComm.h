/*
  SerialComm.h - Library to send and receive strings of characters.
  Created by Julián Ariel Oviedo,
             Saverio Carnevale. 
  June 23, 2019.
  Released into the public domain.
*/

#include "SerialComm.h"
#ifndef SerialFrameComm_h
#define SerialFrameComm_h

class SerialFrameComm
{
  public:
    SerialFrameComm (int address=0, long baud_rate=9600, long serial_time_out=900);
    void post (int data, int destination); 
    int get_data ();
    int get_source();
  private: 
    int host;
    int source;
    SerialComm * driver;
};
 
#endif
