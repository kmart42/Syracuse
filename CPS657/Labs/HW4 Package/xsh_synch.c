/* xsh_synch.c - xsh_synch */

#include <xinu.h>
#include <stdio.h>
#include <string.h>


/*------------------------------------------------------------------------
 * xsh_synch - shell command to create synchronized processes
 *------------------------------------------------------------------------
 */
shellcmd xsh_synch(int nargs, char *args[])
{
	pid32   pid;
	int semStart;
	char ch;
	char *chSem;
	
	if(nargs == 1){
		semStart = 1;
	}else{
		chSem = args[1];
		ch = *chSem++;
		semStart = 0;
		while(ch != NULLCH) {
            if ((ch <'0') || (ch > '9')) {
                kprintf("%s: non-digit in request\n", args[1]);
                return 1;
            }
			semStart = 10*semStart + (ch - '0');
            ch = *chSem++;
		}
	}
	

	pid = create(synchstart, 1024, 20, "Synch_Print", 1, semStart);
	//pid = create(synchstart, 1024, 20, "Synch_Print", 0);

    resume(pid);
	
	return 0;

}