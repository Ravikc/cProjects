#include<stdio.h>
#include<stdbool.h>
#include<string.h>


struct todo
{
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

 func1()
   {
    int sum,res,y4,y,t,y3,yo,y1,y2,dd,mm,yy,p;
    printf("Enter date in DD MM YYYY format\n");
   
    scanf("%d %d %d",&dd,&mm,&yy);
    y=yy/100;
    p=(y%4);
    t=4-p;
    yo=y+t;
    yo=yo-1;
    yo=yo-y;
    yo=yo*2;
   switch(mm)
    {
        case 1:y1=0;break;
        case 2:y1=3;break;
        case 3:y1=3;break;
        case 4:y1=6;break;
        case 5:y1=1;break;
        case 6:y1=4;break;
        case 7:y1=6;break;
        case 8:y1=2;break;
        case 9:y1=5;break;
        case 10:y1=0;break;
        case 11:y1=3;break;
        case 12:y1=5;break;
    }
    y2=dd%7;
    y3=(yy-(y*100));
     if(((yy%4)==0)&&((mm==1)||(mm==2)))
    {
        y4=((y3+(y3/4))%7)-1;
    }
    else
    {
        y4=(y3+(y3/4))%7;
    }
    sum=y4+y2+y1+yo;
    res=sum%7;
    switch(res)
    {
        case 1:printf("monday\n");break;
        case 2:printf("tuesday\n");break;
        case 3:printf("wednesday\n");break;
        case 4:printf("thursday\n");break;
        case 5:printf("friday\n");break;
        case 6:printf("saturday\n");break;
        case 7:printf("sunday\n");break;
    }

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


void ShowNotes(int month, int year)
{
	 int count=0;
	FILE *fp = fopen("notes.txt", "rb");
	struct todo search;
	while(fread(&search, sizeof(struct todo), 1, fp) != 0)
	{ 		
		if( month == search.month && year == search.year )
		{
			count++;	
			if(count == 1)	
				printf("Remainders for this month:\n");
			printf("%d %s: %s",search.day,months[month], search.note);
		}
	}
	fclose(fp);
}


void printCalendar(int firstDayOfMonth, int month, int year, bool leapYear) {
int i, count = 0, newLinePosition = 7 - firstDayOfMonth;	
struct todo temp;
//FILE *fp = fopen("notes.txt","rb");
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
			printf("%2d\t", i);		
		 if(i % 7 == newLinePosition)
			printf("\n");
		}
	}
	else {
	for(i = 0; i < days[month]; i++) {			//changed from 1 to 0 to accomodate sunday as the first day of month
               
	
	 printf("%2d\t", i + 1);
                if(i % 7 == newLinePosition - 1)
                        printf("\n");
                }
	}
printf("\n\n");
ShowNotes(month, year);
return;
}

void addNote(void)
{
	struct todo tempStruct;
	
	char note[100];
	printf("Enter day, month and year in DD MM YYYY: ");
	scanf("%d %d %d", &tempStruct.day, &tempStruct.month, &tempStruct.year);
	printf("\nNote: ");

	int c;
	while ((c = getchar()) != EOF && c != '\n');

	fgets(note, 100, stdin);
	strcpy(tempStruct.note, note);
	FILE *fp = fopen("notes.txt", "ab");
	fwrite(&tempStruct, sizeof(tempStruct), 1, fp);
	fclose(fp);

	printf("Note successfully added!\n\n");
}



int main(void) {
system("clear");
char choice;
int initialChoice;
printf("1. Show day for a given date\n2.Show calendar for a month\n");
scanf("%d", &initialChoice);
if(initialChoice == 1){
	func1();
	return 0;
}

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
	printf("'n': Go to next month, 'p': Go to previous month, 'a': Add Note, 'q': quit \n");
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
	
		case 'a': addNote();
				goto navigate;
				break;

		case 'q': return 0;

		default: return 0;		
	}
return 0;
}
