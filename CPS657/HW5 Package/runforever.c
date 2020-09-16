#include <xinu.h>

void runforever(){
	kprintf("Process %d with priority %d is running\n", getpid(), getprio(getpid()));
	sleep(15);
	while(1){
		kprintf("Process %d with priority %d is running\n", getpid(), getprio(getpid()));
		//sleep(2);
	}
}
