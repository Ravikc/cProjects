#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define RED  "\x1B[31m"
#define RESET "\x1B[0m"

struct todo {
int day, month, year;
char note[100];
};


char *months[] = {" ", "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char pattern[52];

void initPattern(char Pattern) {
	int i;
	for(i = 0; i < 52; i++)
		pattern[i] = Pattern;
	return;
}

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
int i, count = 0, newLinePosition = 7 - firstDayOfMonth;	
struct todo temp;
FILE *fp = fopen("notes.txt","rb");
printf("\n\n");
	printf("%s \n", pattern);
	printf("\t\t %s, %d\n", months[month], year);
	printf("%s", pattern);
	printf("\n");
	printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
	for(i = 0; i < firstDayOfMonth; i++)
		printf("\t");
	if(leapYear == true && month == 2) {
	for(i = 1; i <= days[month] + 1; i++) {

		while(fread(&temp, sizeof(struct todo), 1, fp) != 0) {
			if((temp.day == i) && (temp.month == month) && (temp.year == year)) {
				count++;
				}
			}
		if(count == 0)
			printf("%2d\t", i);
		else{
			printf(RED);
			printf("%2d\t", i);
			printf(RESET);
		}	
		 if(i % 7 == newLinePosition)
			printf("\n");



		}
	}
	else {
	for(i = 0; i < days[month]; i++) {			//changed from 1 to 0 to accomodate sunday as the first day of month
               
		while(fread(&temp, sizeof(struct todo), 1, fp) != 0) {
                        if((temp.day == i + 1) && (temp.month == month) && (temp.year == year)) {
                                count++;
                                }
                        }
		if(count > 0){
			printf(RED);
			printf("%2d\t", i+1);
			printf(RESET);
			}
		else
	 printf("%2d\t", i + 1);
                if(i % 7 == newLinePosition - 1)
                        printf("\n");
                }
	}
printf("\n\n");
return;
}

/*void addNote() {
struct todo temp;
char buffer[100];
int day, month, year,n;
	printf("Enter day month and year in DD MM YYYY format\n");
	scanf("%d %d %d", &day, &month, &year);
//	fflush(stdin);
	temp.day = day;
	temp.month = month;
	temp.year = year;
	printf("Enter the note :");
	scanf("%d", &n);				// TO DEAL WITH THE EXTRA \n LEFT BY PREVIOUS SCANF
	fgets(buffer, sizeof(buffer), stdin);
	strcpy(temp.note, buffer);
	FILE *fp = fopen("notes.txt","ab");
	fwrite(&temp, sizeof(temp), 1, fp);
	fclose(fp);
}
*/


int main(void) {
system("clear");
char choice;
int month, year, firstDayOfMonth;
bool leapYear;
FILE *F = fopen("notes.txt", "ab");
fclose(F);
initPattern('-');
start:	
	printf("Enter date in MM YYYY: ");
	scanf("%d %d", &month, &year);
	if(month < 1 || month > 12) {
		printf("Enter in MM YYYY format only\n");
		goto start;
		}
navigate:
	leapYear = checkLeapYear(year);
	firstDayOfMonth = determineFirstDay(year, month);
	printCalendar(firstDayOfMonth, month, year, leapYear);
	printf("'n': Go to next month, 'p': Go to previous month, 'q': quit \n");
	scanf(" %c", &choice);
	switch(choice) {
		case 'n': month = month + 1;
			 if(month > 12){
				month = 1;
				year = year + 1;
				}
			 goto navigate;
			break;

		case 'p': month = month-1;
			if(month < 1) {
				month = 12;
				year = year - 1;
				}
			goto navigate;
			break;
	
//		case 'a': addNote();
//				break;

		case 'q': return 0;

		default: return 0;		
	}
return 0;
}
