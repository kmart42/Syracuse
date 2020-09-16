#include <xinu.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


	void procA();
	void procB();
	
	sid32 sem;
	pid32 pidA, pidB;
	
	void synchstart(int runNum){
		srand((unsigned long)clktime);
		sem = semcreate(0);
		pidB = create(procB, 1024, 45, "PrintB", 0);
		pidA = create(procA, 1024, 47, "PrintA", 1, runNum);
		resume(pidB);
		resume(pidA);
		return 0;
	}
	
	void procA(runNum){
		while(runNum>0){
			if(rand() % 2 == 0){
				kprintf("\nA1\nB1");
			}
			else{
				kprintf("\nB1\nA1");
			}
			runNum--;
			wait(sem);
		}
		kill(pidB);
		return 0;
	}
	
	void procB(){
		sleepms(1);
		while(1){
			if(rand() % 2 == 0){
				kprintf("\nA2\nB2\n");
			}
			else{
				kprintf("\nB2\nA2\n");
			}

			signal(sem);
			
		}
		
	}
	

