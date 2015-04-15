#include <stdio.h>
#include <stdlib.h>

static const char dayMonths[] = 
            {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
#define BASE_YEAR 1970

static long int elapsedDaysYear(int year)
{
  register int countYear = 0;
  long int totalElapsedDates = 0;

  for(countYear = BASE_YEAR; countYear < year; countYear++)
  {
    if (!(countYear % 400) || (!(countYear % 4) && countYear % 100))
    {
      totalElapsedDates += 366;
      continue;
    }
    totalElapsedDates += 365;
  }
  return totalElapsedDates;
}

static long int elapsedDaysYearMouth(const int month, const int year)
{
  register int i = 0;
  long int totalDays = 0;

  totalDays = elapsedDaysYear(year);

  for(i = 1; i < month; i++)
  {
      if ((!(year % 400) || (!(year % 4) && year % 100)) && i == 2)
      {
        totalDays += 29;
        continue;
      }
      totalDays += dayMonths[i];
  }
  return totalDays;
}

int main(int argc, char ** argv)
{
  char firstDate[4096], secondDate[4096];
  int testCases = 0;
  register int i = 0;
  int year1 = 0, month1 = 0, days1 = 0;
  int year2 = 0, month2 = 0, days2 = 0;
  long int totalDay1 = 0, totalDay2 = 0, finalResult = 0;

  scanf("%d", &testCases);

  for (i = 0; i < testCases; i++)
  {
    scanf("%s %s", firstDate, secondDate);
    sscanf(firstDate, "%d-%d-%d", &year1, &month1, &days1);
    sscanf(secondDate, "%d-%d-%d", &year2, &month2, &days2);

    totalDay1 = elapsedDaysYearMouth(month1, year1) + days1;
    totalDay2 = elapsedDaysYearMouth(month2, year2) + days2;

    finalResult = (totalDay1 >= totalDay2) ? totalDay1 - totalDay2
                                           : totalDay2 - totalDay1;

    printf("%ld\n", finalResult);
  }

  return 0;
}
