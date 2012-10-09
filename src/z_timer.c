/*
 * z_timer.c
 *
 *	Функции для мультиплатформенной работы со временем
 *
 *  Created on: 10.05.2012
 *      Author: moric
 */

sometext

#include "z_timer.h"


void z_timer_gettime(struct timespec*time){
#ifdef UNIX
	clock_gettime(CLOCK_REALTIME, time);
#endif

#ifdef WIN

	LARGE_INTEGER Frequency;
	LARGE_INTEGER Counter;

	QueryPerformanceFrequency(&Frequency);
	QueryPerformanceCounter(&Counter);

	time->tv_sec = Counter.QuadPart/Frequency.QuadPart;
	time->tv_nsec = Counter.QuadPart%Frequency.QuadPart*int1e9/Frequency.QuadPart;

#endif
}

void z_timer_init(z_timer*T){
	T->start.tv_sec = 0;
	T->start.tv_nsec = 0;
	T->finish.tv_sec = 0;
	T->finish.tv_nsec = 0;
	T->diff.tv_sec = 0;
	T->diff.tv_nsec = 0;
}

void z_timer_start(z_timer*T){
	z_timer_gettime(&(T->start));
}

void z_timer_find_diff(z_timer*T){
	T->diff.tv_sec = T->finish.tv_sec - T->start.tv_sec;
	if(T->finish.tv_nsec < T->start.tv_nsec){
		T->diff.tv_sec--;
		T->diff.tv_nsec = T->finish.tv_nsec - T->start.tv_nsec+int1e9;
	}else{
		T->diff.tv_nsec = T->finish.tv_nsec - T->start.tv_nsec;
	}
}

void z_timer_stop(z_timer*T){
	z_timer_gettime(&(T->finish));
	z_timer_find_diff(T);
}

double z_timer_get_in_real(z_timer*T){
	return (double)T->diff.tv_sec + (double)T->diff.tv_nsec*1.e-9;
}

long z_timer_get_second(z_timer*T){
	return T->diff.tv_sec;
}

long z_timer_get_millisecond(z_timer*T){
	return T->diff.tv_nsec/int1e6;
}

long z_timer_get_microsecond(z_timer*T){
	return T->diff.tv_nsec/int1e3%int1e3;
}

long z_timer_get_nanosecond(z_timer*T){
	return T->diff.tv_nsec%int1e3;
}

long z_timer_get_in_second(z_timer*T){
	return z_timer_get_second(T);
}

long z_timer_get_in_millisecond(z_timer*T){
	return z_timer_get_millisecond(T)+z_timer_get_in_second(T)*int1e3;
}

long z_timer_get_in_microsecond(z_timer*T){
	return z_timer_get_microsecond(T)+z_timer_get_in_millisecond(T)*int1e3;
}

long z_timer_get_in_nanosecond(z_timer*T){
	return z_timer_get_nanosecond(T)+z_timer_get_in_microsecond(T)*int1e3;
}
