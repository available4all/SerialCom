///**************************************************
//
//file: main.c
//purpose: simple demo that receives characters from
//the serial port and print them on the screen
//
//**************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#ifdef _WIN32
#include <Windows.h>
//#else
//#include <unistd.h>
//#endif
#include "rs232.h"


int main() 
{
int a=0, cport_nr, VarNum =1, i;
char b[65] = " ", j[65] = " ";
char IdString[9] = " ", buildNo[8] =" " , FirmwareNo[11] = " " ,FirmwareVar[3] = " ", FirmwareRev[5] = " " ;

char ComC(int , int , char*);
printf("\nPlease enter the ComPort Number : ");
scanf("%d", &cport_nr);
cport_nr --; //cport_nr is 1 less than Com Port value
ComC(a , cport_nr, b);
printf("\n%s\n", b);
while(VarNum){
	printf("\n Enter Number : ");
scanf("%d", & VarNum);
if (VarNum > 1){
ComC(2,cport_nr, b);
printf("\nI am here %d time, The string  : %s\n",VarNum, b);
//String Parsing code begins here
for ( i=1; i< 64; i++ ){
if (i==1 && i<= 9) {
IdString[i] = b[i];
}
else if ( i == 10 && i<= 16) {
buildNo[i-10] = b[i];
}
else if ( i == 17 && i <=26) {
	FirmwareNo[i-17] = b[i];
}
else if (i==27 && i <=28) {
	FirmwareVar[i-27] = b[i];
}
else if (i == 29 && i <= 32) {
	FirmwareRev[i-29] = b[i];
}
else if (i == 33) {


}
}
}
else {
	VarNum =0;
}
}
return 0;
}















//
///**************************************************
//
//file: main.c
//purpose: simple demo that receives characters from
//the serial port and print them on the screen
//
//**************************************************/
//
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
////#ifdef _WIN32
//#include <Windows.h>
////#else
////#include <unistd.h>
////#endif
//#include "rs232.h"
//
//
//int main(int argc)
//{
//  static int j=0;
//  int i, n, cport_nr=15,        /*  cport_nr 15 is (COM16 on windows) */
//      bdrate=115200;       /* 115200 baud */
//  int bytes_sent, bytes_received;
//  unsigned char buf[4096];
//  unsigned char login[6] = "root\r";
//  unsigned char getValue[11]="fpga info\r";
//
//
//  if(RS232_OpenComport(cport_nr, bdrate))
//  {
//    printf("Can not open comport\n");
//    return(0);
//  }
////if()
//
//  while(1 && j <1)
//  {
//    n = RS232_PollComport(cport_nr, buf, 4095);
//
//    if(n > 0)
//    {
//      buf[n] = 0;   /* always put a "null" at the end of a string! */
//
//      for(i=0; i < n; i++)
//      {
//        if(buf[i] < 32)  /* replace unreadable control-codes by dots */
//        {
//          buf[i] = '.';
//        }
//      }
//	  printf("%s", (char*) buf);
//	    if (strstr((char*) buf,"login:")){
//		bytes_sent=  RS232_SendBuf(cport_nr,login,6);
//		// printf("received %i bytes: %s\n", n, (char *)buf);
//		j++;
//		}
//		
//    }
//  }
//  
//	while (1 && argc==1 && j<2) {
// // else
//		printf("%s", (char*) buf);
//	bytes_sent = RS232_SendBuf(cport_nr,getValue, 10);
//	printf("%s", (char*) buf);
//	}
//
////#ifdef _WIN32
//    Sleep(100);
////#else
////    usleep(100000);  /* sleep for 100 milliSeconds */
////#endif
//  //	RS232_CloseComport(cport_nr);  	
//    return(0);
//}

