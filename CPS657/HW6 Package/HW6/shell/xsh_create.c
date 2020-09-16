/* xsh_create.c - xsh_create */

#include <xinu.h>
#include <stdio.h>
#include <string.h>


umsg32 msg, msg2;
/*------------------------------------------------------------------------
 * xsh_create - shell command to createeeeee
 *------------------------------------------------------------------------
 */
shellcmd xsh_create(int nargs, char *args[])
{
	int32   portNum, msgNum, portID;
	char    ch, ch1;
    char    *portCount, *msgCount;
	pid32   pid1, pid2;


	// if no arguments given, default to 5 ports 10 messages
	portNum=5;
    if (nargs == 1) {
        msgNum=10;
		
    }

    else if ( nargs >= 2 ) {
        msgCount = args[1];
        ch = *msgCount++;
        msgNum = 0;
        while(ch != NULLCH) {
            if ((ch <'0') || (ch > '9')) {
                kprintf("%s: non-digit in port numbers\n", args[1]);
                return 1;
            }
            msgNum = 10*msgNum + (ch - '0');
            ch = *msgCount++;
        }

		/*
		msgCount = args[2];
        ch1 = *msgCount++;
        msgNum = 0;
        while(ch1 != NULLCH) {
            if ((ch1 <'0') || (ch1 > '9')) {
                kprintf("%s: non-digit in message numbers\n", args[2]);
                return 1;
            }
            msgNum = 10*msgNum + (ch1 - '0');
            ch1 = *msgCount++;
        }*/
    }
    else {
        kprintf("Too many arguments\n");
        return 1;
    }

	
int32 portSend(int32 portID, umsg32 msg)
{
	ptsend(portID, msg);
	return OK;
}

int32 portRec(int32 msgNum, int32 portNum){
	int k, c;
	if(portNum>=msgNum){
		for(k=1;k<=msgNum;k++){
		msg2 = ptrecv(0);
		kprintf("Message at receiver: %d\n",msg2);
		}
	}else{
		for(c=1;c<=portNum;c++){
		msg2 = ptrecv(0);
		kprintf("Message at receiver: %d\n",msg2);
		}
		kprintf("Error! %d messages not received\n",msgNum-portNum);
		return 1;
	}
		
	return(OK);
	
}



void msgPass1() 
{
	ptinit(portNum);
	ptcreate(portNum);
	int j;
	pid1 = create(portRec,1024,20,"Receiver",2,msgNum,portNum);
	resume(pid1);
	recvclr();
	int32 result = 1;
	for(j = 0;j<=msgNum;j++){
	result = portSend(0, j);
	}
	
}
	msgPass1();
    return 0;

}
