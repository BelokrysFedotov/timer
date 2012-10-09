/*
 * z_timer.h
 *
 *	Функции для мультиплатформенной работы со временем
 *
 *  Created on: 01.07.2012
 *      Author: Belokrys-Fedotov A.I.
 */

#ifndef Z_TIMER_H_
#define Z_TIMER_H_

#ifdef UNIX

#include <time.h>

#endif

#ifdef WIN

#include <windows.h>

struct timespec {
	long		tv_sec;			/* seconds */
	long		tv_nsec;		/* nanoseconds */
};

#endif


struct z_timer_struct{
	struct timespec start;
	struct timespec finish;
	struct timespec diff;
};

typedef struct z_timer_struct z_timer;

#define int1e3 1000
#define int1e6 1000000
#define int1e9 1000000000

/**
 * Инициализация таймера
 */
void z_timer_init(z_timer*T);

/**
 * Старт таймера
 */
void z_timer_start(z_timer*T);

/**
 * Остановка таймера
 */
void z_timer_stop(z_timer*T);


/**
 * Считать результат таймера в секундах.
 */
double z_timer_get_in_real(z_timer*T);

/**
 * Считать секунды с таймера
 */
long z_timer_get_second(z_timer*T);

/**
 * Считать миллисекунды с таймера
 */
long z_timer_get_millisecond(z_timer*T);

/**
 * Считать миллисекунды с таймера
 */
long z_timer_get_microsecond(z_timer*T);

/**
 * Считать миллисекунды с таймера
 */
long z_timer_get_nanosecond(z_timer*T);

/**
 * Считать результат таймера в секундах
 */
long z_timer_get_in_second(z_timer*T);

/**
 * Считать результат таймера в миллисекундах
 */
long z_timer_get_in_millisecond(z_timer*T);

/**
 * Считать результат таймера в микросекундах
 */
long z_timer_get_in_microsecond(z_timer*T);

/**
 * Считать результат таймера в наносекундах
 */
long z_timer_get_in_nanosecond(z_timer*T);



#endif /* Z_TIMER_H_*/
