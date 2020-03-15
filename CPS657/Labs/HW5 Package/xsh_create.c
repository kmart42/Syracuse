/* xsh_create.c - xsh_create */

#include <xinu.h>
#include <stdio.h>
#include <string.h>

/*------------------------------------------------------------------------
 * xsh_create - shell command to create
 *------------------------------------------------------------------------
 */
shellcmd xsh_create(int nargs, char *args[])
{
	int32   schChoice;
	char    ch;
    char    *chprio;
	pid32   pid1, pid2, pid3;

    if (nargs == 1) {
        schChoice=1;

    }

    else if ( nargs >= 2 ) {
        chprio = args[1];
        ch = *chprio++;
        schChoice = 0;
        while(ch != NULLCH) {
            if ((ch <'0') || (ch > '9')) {
                kprintf("%s: non-digit in entry\n", args[1]);
                return 1;
            }
            schChoice = 10*schChoice + (ch - '0');
            ch = *chprio++;
        }

        if (schChoice < (pri16)MINKEY) {
            kprintf("%s: invalid entry\n", args[1]);
            return 1;
        }

    }
    else {
        kprintf("Too many arguments\n");
        return 1;
    }
    pid1 = create(runforever, 1024, 5, "Process1", 0);
	pid2 = create(runforever, 1024, 10, "Process2", 0);
	pid3 = create(runforever, 1024, 20, "Process3", 0);

	extern int32 order;

	switch(schChoice){
		case 1:
			resume(pid1);
			resume(pid2);
			resume(pid3);
			break;
		case 2:
			kprintf("here\n");
			resume2(pid1);
			order++;
			resume2(pid2);
			order++;
			resume2(pid3);
			break;
		default:
			kprintf("%s: invalid entry\n", args[1]);
			break;
	}

    return 0;



}
