

#include "SerialFrameComm.h"


SerialFrameComm::SerialFrameComm(int address=0, long baud_rate=9600, long serial_time_out=900)
{
   driver = new SerialComm(baud_rate, serial_time_out); 
   host=address;
}

void SerialFrameComm::post(int data, int destination){
  String sincro;                                                                    
  sincro="o";                      

  int sum=host+destination+data; 
  
  byte host_h, host_l, destination_h, destination_l, data_h, data_l, sum_h,sum_l; 
  host_h=highByte(host);
  host_l=lowByte(host);
  destination_h=highByte(destination);
  destination_l=lowByte(destination);
  data_h=highByte(data);
  data_l=lowByte(data); 
  sum_h=highByte(sum);
  sum_l=lowByte(sum); 

  driver->data_to_send=sincro+host_h+host_l+destination_h+destination_l+data_h+data_l+sum_h+sum_l;

  driver->send_data_frame();
}

int SerialFrameComm::get_data (){
  if(driver->get_data_frame()){  
   String string;
   int dest_, source_, data_, sum_;
   byte sinc, source_h, source_l, dest_h, dest_l, data_h,data_l, sum_h,sum_l;
   
   string=driver->data_received;

   sinc=string[0];
   source_h=string[1]-'0';
   source_l=string[2]-'0';
   dest_h=string[3]-'0';
   dest_l=string[4]-'0';
   data_h=string[5]-'0';
   data_l=string[6]-'0';
   data_h=string[5]-'0';
   data_l=string[6]-'0';
   sum_h=string[7]-'0';
   sum_l=string[8]-'0';
  
   source_=source_h;
   source_<<= 8;
   source_ |= source_l;

   source=source_;

   dest_=dest_h;
   dest_<<= 8;
   dest_|= dest_l ;

   data_=data_h;
   data_<<= 8;
   data_ |= data_l;
     
   sum_=sum_h;
   sum_<<= 8;
   sum_ |= sum_l;

   if ( (sinc=='o')&&(dest_==host)&&(sum_==(source_+dest_+data_))){return data_; }
   else { return -1;}
  }
else {return -1;}  
}

int SerialFrameComm::get_source () {return source;}



