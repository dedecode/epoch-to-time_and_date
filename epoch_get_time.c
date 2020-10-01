#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct DataTime{     // struct. members are date 
    uint16_t year;   // time infos.
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
};
	struct DataTime D_T;
	long sec_in_year=365*24*60*60;

int leap(int y) // function for check the year leap or not
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

 int leap_years;
 int day_of_year;
 
void get_time(unsigned long secs){  // function starts  here
                                  
 D_T.second = secs % 60;             // gets second, minute 
 D_T.minute = (secs /60)%60;        // and hour info.
 D_T.hour = (secs % 86400)/3600;
 
 int days_since_epoch= secs/ (24*60*60); // number of days completed since 01/01/1970 00:00:00
 D_T.year =1970 + days_since_epoch / 365;

int i;
leap_years=0;

for( i=1970;i<D_T.year;i++){  // calculates # of leap years 
	if( leap(i))               // we need it for determine #of leap seconds
	leap_years++;
}
 	D_T.year =1970 + ( days_since_epoch - leap_years)/ 365;  // year info updated 
  day_of_year = (days_since_epoch - leap_years)%365 + 1 ;   // according to # of leap years

// this is very important tricky point. Read readme.
if ( leap(D_T.year)){
	if ( (day_of_year+leap_years) >365 ) {
		day_of_year++;
	}
}
	int mo[12] = {31,28+leap(D_T.year),31,30,31,30,31,31,30,31,30,31};
 	i=0;
  int temp_x=0;
  
    while(i<12){
	    	temp_x += mo[i]; 
	      if(day_of_year <=temp_x)
          break;
	      i++;
    }
  D_T.day = day_of_year -temp_x + mo[i];
	D_T.month = i+1;
	int k;
}

int main(){

	// this part is for testing
	unsigned long epoch = 1601555133;
	epoch= epoch+ 10800; // GMT +3 ( 10800 = 3*3600 )

	int k;
	for (k=0;k<8000;k++){
		get_time(epoch);
	  printf ("leaps: %2d, days:%3d, lol %4d. %d->  %2d-%2d-%4d   %2d:%2d:%2d   \n",leap_years,day_of_year,k,epoch, D_T.day,D_T.month, D_T.year,D_T.hour,D_T.minute,D_T.second );
    epoch += 86400;
	}
}
