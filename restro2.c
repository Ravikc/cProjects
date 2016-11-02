#include<stdio.h>
#include<string.h>
void print1()
{
    printf("\t\t\t\t\t  The Indian Parliament \t\t\t\n");
    printf("  11. TakeAway  \t\t\t\t   12. Need a Table  \n\n\n");
 }
void menu()
{
      printf("\t\t\t\t\t The Indian Parliament \t\t\t\n\n");
      printf("\t A. VEG: \n");
      printf(" 1. Panner Butter Masala ---  100 \n");
      printf(" 2. Corn Masala ---           140 \n");
      printf("\t B. NON VEG:\n");
      printf(" 3. Chicken Masala ---        120 \n");
      printf(" 4. Chicken Korma ---         150 \n");
      printf("\t C. BEVERAGES:\n");
      printf(" 5. Coca Cola ---              20 \n");
      printf(" 6. Fanta ---                  20 \n");
      
}
void takeaway()
{
   int a[]={100,140,120,150,20,20};
   int choice_1;
   char choice_2,choice_3;
   int total=0;
   while(choice_3!='e' || 'E')
   {
         printf(" Welcome to Take Away service Of The Indian Parliament \n");
         menu();
         printf(" Enter the section(Veg/NonVeg/Beverage): ");
         scanf("%c",&choice_2);
         switch(choice_2)
         {
         veg: case 'v': printf("\n Enter the veg dishes : ");
                        scanf("%d",&choice_1);
                        switch(choice_1)
                        {
                            case 1: printf(" You choose Panner Butter masala \n");
                                    total=total+a[0];
                                    printf("To change section press 'n' or 'b' or to order in same press 's' or to exit to payment 'e' \n");
                                    scanf("%c",&choice_3);
                                    if(choice_3=='n' || choice_3=='N')
                                    {
                                         goto nonveg;
                                      }
                                    else if(choice_3=='b' || choice_3=='B')
                                    {
                                        goto bevrage;
                                      }
                                   else if(choice_3=='s' || choice_3=='S')
                                   {
                                         goto veg;
                                     }
                                  // else{ continue;}
                                    break;
                           case 2: printf(" You choose Corn Masala \n");
                                   total=total+a[1];
                                   printf(" To change section press 'n' or 'b' or to order in same press 's' or to exit to payment 'e' \n");
                                   scanf("%c",&choice_3);
                                   if(choice_3=='n' || choice_3== 'N')
                                   {
                                        goto nonveg;
                                     }
                                   else if(choice_3=='b' || choice_3=='B')
                                  {
                                         goto bevrage;
                                    }
                                   else if(choice_3=='s' || choice_3=='S')
                                   {
                                           goto veg;
                                     }
                                   else{ continue;}
                                   break;
                            }
        nonveg:     case 'n': printf("\n Enter the Non Veg dishes : ");
                       scanf("%d",&choice_1);
                       switch(choice_1)
                       {
                           case 3: printf(" You choose Chicken Masala \n");
                                   total=total+a[2];
                                   printf(" To change section press 'v' or 'b' or to order in same press 's' or to exit to payment 'e' \n");
                                   scanf("%c",&choice_3);
                                   if(choice_3=='v' || choice_3== 'V')
                                   {
                                          goto veg;
                                    }
                                  else if(choice_3=='b' || choice_3=='B')
                                 {
                                     goto bevrage;
                                   }
                                  else if(choice_3=='s' || choice_3=='S')
                                  {
                                         goto nonveg;
                                     }
                                  else{continue;}
                           case 4: printf(" You choose Chicekn korma \n");
                                   total=total+a[3];
                                   printf(" To change section press 'v' or 'b' or to order in same press 's' or to exit to payment 'e' \n");
                                   scanf("%c",&choice_3);
                                   if(choice_3=='v' || choice_3=='V')
                                   {
                                       goto veg;
                                     }
                                   else if(choice_3=='b' || choice_3=='B')
                                   {
                                         goto bevrage;
                                     }
                                   else if(choice_3=='s' || choice_3== 'S')
                                   {
                                           goto nonveg;
                                    }
                                    else{ continue;}
                              }
     bevrage:    case 'b': printf("\n Enter the bevrages : ");
                        scanf("%d",&choice_1);
                        switch(choice_1)
                        {
                            case 5: printf(" You choose coca cola \n");
                                    total=total+a[4];
                                    printf(" To change section press 'v' or 'n' or to order in the same press 's' or to exit to payment 'e' \n");
                                    scanf("%c",&choice_3);
                                    if(choice_3=='v' || choice_3=='V')
                                    {
                                           goto veg;
                                      }
                                    else if(choice_3=='n' || choice_3== 'N')
                                    {
                                            goto nonveg;
                                       }
                                    else if(choice_3=='s' || choice_3=='S')
                                    {
                                          goto bevrage;
                                      }
                                     else{continue;}
                            case 6: printf(" You choose Fanta \n");
                                    total=total+a[5];
                                    printf(" To change section press 'v' or 'n' or to order in the same press 's' or to exit to payment 'e' \n");
                                    scanf("%c",&choice_3);
                                    if(choice_3=='v' || choice_3=='V')
                                    {
                                          goto veg;
                                      }
                                    else if(choice_3=='n' || choice_3== 'N')
                                    {
                                          goto nonveg;
                                      }
                                    else if(choice_3=='s' || choice_3=='S')
                                    {
                                            goto bevrage;
                                      }
                                     else {continue;}
                              }
		}
	}
}

int main()
{ 
   	takeaway();
	return 0;
}
