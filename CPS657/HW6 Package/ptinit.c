/* ptinit.c*/

#include <xinu.h>

struct	ptnode *ptfree;
struct	ptentry	porttab[NPORTS];
int32	ptnextid;

/*------------------------------------------------------------------------
 *  intialize all ports
 *------------------------------------------------------------------------
 */
syscall	ptinit(
	  int32		maxmsgs
	)
{
	int32 	i;
	struct	ptnode *next, *curr;
	
	ptfree = (struct ptnode *)getmem(maxmsgs*sizeof(struct ptnode));
	if (ptfree == (struct ptnode *)SYSERR){
		panic("ptinit failed, insufficient memory");
	}
	for (i=0; i<NPORTS; i++){
		porttab[i].ptstate = PT_FREE;
		porttab[i].ptseq = 0;
	}
	ptnextid = 0;
	
	for (curr=next=ptfree; --maxmsgs>0; curr=next){
		curr->ptnext = ++next;
	}
	
	curr->ptnext = NULL;
	return OK;	

}
