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



/// Invoke the function by using SeriaComC.exe and Arguments to follow, argv[0] = //LocationOnHardDrive/SerialCom.exe 
//argv[1] = 

char* ComC(int a, int cport_nr, char *b)
{
  static int j=0;
  int i, k=0, n, bdrate=115200;         /*  cport_nr 15 is (COM16 on windows) */
         /* 115200 baud */
  int bytes_sent, bytes_received;
  unsigned char buf[4096]; //key[70];
  char temp [65];//char temp [64];
  unsigned char login[6] = "root\r";
  unsigned char getValue[11]="fpga info\r";
  //a=1;

  if( a<2 && RS232_OpenComport(cport_nr, bdrate) )
	{
	printf("Can not open comport\n");
    return b[0];
	}


  while(1 && j <1 && a <2)
  {
	
    n = RS232_PollComport(cport_nr, buf, 4095);
	if(n > 0)
    {
      buf[n] = 0;   /* always put a "null" at the end of a string! */

      for(i=0; i < n; i++)
      {
        if(buf[i] < 32)  /* replace unreadable control-codes by dots */
        {
          buf[i] = '.';
        }
      }
	  printf("%s", (char*) buf);
	    if (strstr((char*) buf,"login:")){
		bytes_sent=  RS232_SendBuf(cport_nr,login,6);
		//printf("Sent %i bytes\n",bytes_sent); 
		// printf("received %i bytes: %s\n", n, (char *)buf);
		j++;
		}
    }
  }
  
  while (a<2) {
	  a=1;
	printf("%s", (char*) buf);
	memset(&buf[0], 0, sizeof(buf));
	Sleep(1000);
	bytes_sent = RS232_SendBuf(cport_nr,getValue, 10);
	Sleep(1000);
	n = RS232_PollComport(cport_nr, buf, 4095);
	Sleep(1000);
	printf("%s", (char*) buf);
	a++;
	}

  j=0;
  //while (j<1 && a>=2 && a <= 64)
  while (j<1 && a>=2 )
  {
	//printf("%s", (char*) buf);
	memset(&buf[0], 0, sizeof(buf));
	Sleep(1000);
	bytes_sent = RS232_SendBuf(cport_nr,getValue, 10);
	Sleep(1000);
	n = RS232_PollComport(cport_nr, buf, 4095);
	Sleep(1000);
	printf("%s \n", (char*) buf);
	fflush(stdout);
	i=0;

	while(k<66) {
		if((buf[112+k]!= 13) && (buf[112+k]!= 10)) {		
			temp[i] = buf[112+k];	
		printf("%c", temp[i]);
		i++;
		}
		k++;
	}

	temp[i] = '\0';
	printf("\n\nThe string is %s", temp);
	a++;
	j++;
  }  

  strcpy(b,temp);
   
  printf("\n%s",b);
  Sleep(100);
  //Print for Debug
  return b;
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

