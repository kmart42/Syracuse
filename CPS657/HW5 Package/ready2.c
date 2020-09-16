/* ready.c - ready */

#include <xinu.h>

qid16	readylist;			/* index of ready list		*/

/*------------------------------------------------------------------------
 *  ready  -  Make a process eligible for CPU service
 *------------------------------------------------------------------------
 */
status	ready2(
	  pid32		pid,		/* ID of process to make ready	*/
	  bool8		resch		/* reschedule afterward?	*/
	)
{
	register struct procent *prptr;

	if (isbadpid(pid)) {
		return(SYSERR);
	}

	/* Set process state to indicate ready and add to ready list */
	extern int32 order;
	prptr = &proctab[pid];
	prptr->prstate = PR_READY;
	insert(pid, readylist, order);

	if (resch == RESCHED_YES) {
		resched2();
	}
	return OK;
}
