//------------------------------------------------------------------------------
//  File:       Serial.c
//  Date:       04/11/2013
//  Purpose:    Main "Serial" module.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Include files
//------------------------------------------------------------------------------
#include <Windows.h>
#include "rs232.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//extern int RS232_OpenComport(int ,int );
//extern int RS232_PollComport(int , unsigned char , int );
//extern int SendBuf(int, unsigned char *, int);

//------------------------------------------------------------------------------
// Application entry-point
//------------------------------------------------------------------------------
int main(void)
{
	int i, j, n, login, cport_nr=15, bdrate=115200;     /*  cport_nr 15 is (COM16 on windows) */
             /* 115200 baud */

  unsigned char buf[4096], buffer1[5];
	 
  if(RS232_OpenComport(cport_nr, bdrate))
  {
    printf("Can not open comport\n");

    return(0);
  }

  Sleep(25000);
    
  for(j=0;j<2; j++) {
    //n = RS232_PollComport(cport_nr, buf, 4095);
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
	   printf("received %i bytes: %s\n", n, (char *)buf);
	 }
	Sleep(100);
 }
  strcpy(buffer1, "root\n ");
  login = SendBuf (cport_nr, buffer1, 5);

     // TODO: Add application code here.
 
    return 0;
}
