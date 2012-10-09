#include <stdio.h>
#include <stdlib.h>

#include <z_timer.h>

int main(int argc, char *argv[]){
	int i,j,N,M;
	float a;
	z_timer T;
	z_timer_init(&T);

	printf("Test\n");

	N = 100;
	M = 65000;
	if(argc>1){
		N = atoi(argv[1]);
		if(N<1) N = 100;
		if(argc>2){
			M = atoi(argv[2]);
			if(M<1) M = 65000;
		}
	}


	for(j=0;j<N;j++){
		z_timer_start(&T);
		a=1.1e0;
		for(i=0;i<M;i++)a*=a;
		z_timer_stop(&T);
		printf("Time:\t%5ld:%3ld:%3ld:%3ld\t%lds %ldms %ldmcs %ldns\t%es\n",
				z_timer_get_second(&T),
				z_timer_get_millisecond(&T),
				z_timer_get_microsecond(&T),
				z_timer_get_nanosecond(&T),
				z_timer_get_in_second(&T),
				z_timer_get_in_millisecond(&T),
				z_timer_get_in_microsecond(&T),
				z_timer_get_in_nanosecond(&T),
				z_timer_get_in_real(&T));
	}
	return 0;
}
