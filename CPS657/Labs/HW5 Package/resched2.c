/* resched2.c - resched2 */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  resched  -  Reschedule processor to first come first serve
 *------------------------------------------------------------------------
 */
void	resched2(void)		/* assumes interrupts are disabled	*/
{
	struct procent *ptold;	/* ptr to table entry for old process	*/
	struct procent *ptnew;	/* ptr to table entry for new process	*/

	/* If rescheduling is deferred, record attempt and return */

	if (Defer.ndefers > 0) {
		Defer.attempt = TRUE;
		return;
	}

	/* Point to process table entry for the current (old) process */

	ptold = &proctab[currpid];

	//if (ptold->prstate == PR_CURR) {  /* process remains running */
	//	if (order > firstkey(readylist)) {
	//		return;
	//	}

		/* Old process will no longer remain current */

	ptold->prstate = PR_READY;
	extern int32 order;
	insert(currpid, readylist, order);
	//}

	/* Force context switch to highest priority ready process */

	currpid = dequeue(readylist);
	ptnew = &proctab[currpid];
	ptnew->prstate = PR_CURR;
	preempt = QUANTUM;		/* reset time slice for process	*/
	ctxsw(&ptold->prstkptr, &ptnew->prstkptr);

	/* Old process returns here when resumed */

	return;
}
