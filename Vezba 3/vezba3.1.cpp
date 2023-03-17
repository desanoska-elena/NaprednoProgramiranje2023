/* difftime example */
#include <stdio.h>      /* printf */
#include <time.h>       /* time_t, struct tm, difftime, time, mktime */

// Elena Desanoska INKI 767 

int main ()
{
  time_t now;                // deklariranje promenliva za da go drzi tekovnoto vreme kako tip "time_t" 
  struct tm newyear;         // deklariranje promenliva struct tm za da gi drzi datumot i vremeto na novata godina
  double seconds;            // deklariranje promenliva za da ja drzi razlikata vo sekundi pomegju sega i novata godina

  time(&now);                // go dobiva tekovnoto vreme i go skladira vo promenliva "now"; ekvivalentno na now = time(NULL)

  newyear = *localtime(&now);// go zema tekovniot datum i vreme od lokalnata vremenska zona i go skladira vo promenliva struct tm newyear
                             // operatorot * se koristi za dereferenciranje na pokazuvacot vraten od lokalno vreme i za dodeluvanje na struct vrednost na newyear

  // postavuvanje na vremenskite polinja na novata godina na polnokj na 1vi januari
  newyear.tm_hour = 0; newyear.tm_min = 0; newyear.tm_sec = 0;
  newyear.tm_mon = 0;  newyear.tm_mday = 1;

  // presmetuvanje na razlikata pomegu sega i nova godina vo sekundi koristejki gi funkciite difftime i mktime
  seconds = difftime(now,mktime(&newyear));

  // pecatenje na rezultatot
  printf ("%.f seconds since new year in the current timezone.\n", seconds);

  return 0;  
}
