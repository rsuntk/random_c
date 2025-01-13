/* A simple timer by @RissuDesu */
/* Yeah idk why i do this :P */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

static void timer(uint32_t minutes, uint32_t sec)
{
	// do checks
	if (sec < 0 || sec > 59) {
		printf("Excess value: %d !!\n", sec);
		return;
	}
	
	// do time loop
	for (;; sec--) {
		sleep(1); // sleep for 1sec
#ifdef __linux__
		system("clear");
#else
		system("cls");
#endif
		if (sec < 10)
			printf("Timer is running! %d:0%d\n", minutes, sec);
		else
			printf("Timer is running! %d:%d\n", minutes, sec);
			
		if (sec == 0 && minutes > 0) {
			// add 60s into int first!!
			sec += 60;
			minutes--;
		} else if (sec == 0 && minutes < 1) {
			printf("Timer ended!\n");
			return;
		}
	}
}

// call timer func
int main(void)
{
	timer(2, 59);
	return 1;
}
