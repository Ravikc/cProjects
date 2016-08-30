#include<stdio.h>
#include<stdbool.h>
char *months[] = {" ", "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool checkLeapYear(int year) {
	 if(year%400 ==0 || (year%100 != 0 && year%4 == 0))
		return true;
	 return false;
}

int determineFirstDay(int Year, int Month) {
	int Day = 1, ZMonth, ZYear, Zeller;
    if(Month < 3)
        ZMonth = Month+10;
    else
        ZMonth = Month-2;
    if(ZMonth > 10)
        ZYear = Year-1;
    else
        ZYear = Year;
    Zeller = ((int)((13*ZMonth-1)/5)+Day+ZYear%100+
            (int)((ZYear%100)/4)-2*(int)(ZYear/100)+
            (int)(ZYear/400)+77)%7;
    return Zeller;
	
}

void printCalendar(int firstDayOfMonth, int month, int year, bool leapYear) {
int i, newLinePosition = 7 - firstDayOfMonth;	
printf("\n\n");
	printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
	for(i = 0; i < firstDayOfMonth; i++)
		printf("\t");
	if(leapYear == true && month == 2) {
	for(i = 1; i <= days[month] + 1; i++) {
		printf("%2d\t", i);
		 if(i % 7 == newLinePosition)
			printf("\n");
		}
	}
	else {
	for(i = 1; i <= days[month]; i++) {
                printf("%2d\t", i);
                if(i % 7 == newLinePosition)
                        printf("\n");
                }
	}
printf("\n\n");
return;
}

int main(void) {
system("clear");
int month, year, firstDayOfMonth;
bool leapYear;
start:	
	printf("Enter date in MM YYYY: ");
	scanf("%d %d", &month, &year);
	if(month < 1 || month > 12) {
		printf("Enter in MM YYYY format only\n");
		goto start;
		}
	leapYear = checkLeapYear(year);
	firstDayOfMonth = determineFirstDay(year, month);
	printCalendar(firstDayOfMonth, month, year, leapYear);
return 0;
}
