#include <stdio.h>
#include <limits.h>
#include <time.h>

double totTime();



int main()
{
	unsigned long long int Divider, Remainder;
	unsigned long long int Divisor = 4000000007llu;
	time_t Attack;
	
	
	printf("\n\nWelcome Back!\n\n");
	
	
	Divider = totTime();		  
	
	
	do {
		
		Remainder = (Divider*Divider)%Divisor;
		
		
		if(Remainder == 1749870067)
		{
			printf("\n --- We have broken through Sire! --- \n\n");
			// printf("\nDivider: %llu\n", Divider);
			
			Attack = Divider - (3 * 60 * 60);
			
			printf("Le Camel Invasion: %s (GMT)", ctime(&Attack));
			
			return 0;
		}
		else
		{
			Divider = Divider - 1;
		}
	
	}
	while(Divider > 0);
	
	printf("\n >>> We have failed Sire! <<< \n");
	
	
	return 0;
	
}

double totTime()
{
	time_t time_beg, time_end;
	struct tm ConvertorB, ConvertorE; 
	double seconds;
	
	ConvertorB.tm_sec = 0;			/* Seconds: 0-59 (K&R says 0-61?) */
	ConvertorB.tm_min = 0;			/* Minutes: 0-59 */
	ConvertorB.tm_hour = 12;			/* Hours since midnight: 0-23 */
	ConvertorB.tm_mday = 1;			/* Day of the month: 1-31 */
	ConvertorB.tm_mon = 0;			/* Months *since* january: 0-11 */
	ConvertorB.tm_year = 70;			/* Years since 1900 */
	ConvertorB.tm_wday = 0;			/* Days since Sunday (0-6) */
	ConvertorB.tm_yday = 0;			/* Days since Jan. 1: 0-365 */
	ConvertorB.tm_isdst = 1;		/* +1 Daylight Savings Time, 0 No DST,
									/* -1 don't know */
	
	
	ConvertorE.tm_sec = 0;			/* Seconds: 0-59 (K&R says 0-61?) */
	ConvertorE.tm_min = 0;			/* Minutes: 0-59 */
	ConvertorE.tm_hour = 0;			/* Hours since midnight: 0-23 */
	ConvertorE.tm_mday = 1;			/* Day of the month: 1-31 */
	ConvertorE.tm_mon = 0;			/* Months *since* january: 0-11 */
	ConvertorE.tm_year = 130;			/* Years since 1900 */
	ConvertorE.tm_wday = 0;			/* Days since Sunday (0-6) */
	ConvertorE.tm_yday = 0;			/* Days since Jan. 1: 0-365 */
	ConvertorE.tm_isdst = 1;		/* +1 Daylight Savings Time, 0 No DST,
									/* -1 don't know */
	
	
	
	
	time_beg = mktime(&ConvertorB);
	if(time_beg == -1)
	{
		printf("\nThe beginning is not beginning too well.\n");
	}
	
	
	time_end = mktime(&ConvertorE);
	if(time_end == -1)
	{
		printf("\nThe ending is not ending too well.\n");
	}
	
	
	seconds = difftime(time_end, time_beg);	
	
	// printf("totTime: %.f", seconds);
	
	return seconds;

}