// password for train 1234567
//user for bus- admin  and password - pass






#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
//*********************************Cab functions******************************************
struct Cab {
    char driverName[50];
    char cabNumber[20];
    int available;
    float price; // Price for each ride
    float interCityPrice; 
    float outerCityPrice;
};

// Function prototypes
void displayMenu();
void bookCab(struct Cab cabs[], int numCabs);
void displayAvailableCabs(struct Cab cabs[], int numCabs);
void cancelCabBooking(struct Cab cabs[], int numCabs);
void showBookingStatus(struct Cab cabs[], int numCabs);
void displayPrices(struct Cab cabs[], int numCabs);
int findCabIndex(struct Cab cabs[], int numCabs, const char *cabNumber);
float calculateTotalPrice(float basePrice, float distance);
float allotVehicle(int numTravelers, float totalAmount);


//*********************************Train functions******************************************


void viewinfo();
void bookticket();
void cancelticket();
void admin();
void password();
void viewpassenger();
void addtrain();
void dlttrain();
void awrite();
void aread();
void bookticket_write();
void viewpassengers_read();


//************************************Bus functions******************************************


char ch[10][130]={"Manglore Express","Karwar Express","Airavat Express",
                "SeaBird Express","Newport Express","VRL Express"};
char nameN[32][100]={'\0'};
char number[32][2]={'\0'};
int num1[32]={0};
int trno;
void bus();//for list of bus
void name_number(int booking,char numstr[100]);
void booking();//for booking the tickets
int read_number(int trno);//for reading the number from the file
void read_name(int trno);//for reading the name from the file
void status();//for printing the status by user input
void status_1(int trno);//for printing the status while booking ticket
void cancle();


//*************************************train function definition********************************main_t

struct adddata
{
	char si[10];
	char train_number[10];
	char train_name[20];
	char start[10];
	char destination[10];
	char price[10];
	int seat;
	char time[10];
} add[1000];

struct bookticket
{
	char train_number[20];
	char name[20];
	char phone[20];
	char date[20];
	int seat;
}book[1000];

int k=0,u=0;
char trn_nmbr[100],name[100],phn[100];

void main_t()
{
	aread();
	viewpassengers_read();
	system("COLOR 0f");
	int ch;
	time_t currentTime;
	time(&currentTime);
	printf("\n\t\t\t     %s\n",ctime(&currentTime));

	printf("\n\t\t\t=================================\n");
	printf("\t\t\t=   RAILWAY MANAGEMENT SYSTEM   =\n");
	printf("\t\t\t=================================\n\n\n");
	printf("\n\t\t\t[1] VIEW INFORMATION\n");
	printf("\n\t\t\t[2] BOOK TICKET\n");
	printf("\n\t\t\t[3] CANCEL TICKET\n");
	printf("\n\t\t\t[4] ADMIN");
	printf("\n\n\t\t\t[5] EXIT\n");
	printf("\n\t\t\t********************************");
	printf("\n\t\t\t********************************");
	printf("\n\t\t\tENTER YOUR CHOICE: ");

	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			viewinfo();
			break;
			case 2:
				bookticket();
				break;
				case 3:
					cancelticket();
					break;
					case 4:
						password();
						break;
						case 5:
							system("cls");
                            printf("\n\t\t\t=================================\n");
                            printf("\t\t\t=   RAILWAY MANAGEMENT SYSTEM   =\n");
                            printf("\t\t\t=================================");
							getch();
							system("cls");
							main();
							break;
							
							default:
								system("cls");
                                printf("\n\t\t\t=================================\n");
                                printf("\t\t\t=   RAILWAY MANAGEMENT SYSTEM   =\n");
                                printf("\t\t\t=================================\n");
								printf("\n\n\t\t\t<<<<<<<<YOU ENTERED WRONG CHOICE>>>>>>>>\n");
								printf("\t\t\t<<<<<<<<PLEASE ENTER RIGHT THING>>>>>>>>\n");
								getch();
								system("cls");	
                                main_t();
								
	}
    
	return 0;
}

void bookticket()
{
	int c,j,n,i,found=-1;
	char v,train_number[10];
	system ("cls");
	aread();
    printf("\n\t\t\t=================================\n");
    printf("\t\t\t=   RAILWAY MANAGEMENT SYSTEM   =\n");
    printf("\t\t\t=================================\n");
	printf("\n\n\t\t\thow many ticket do you want to buy: ");
	scanf("%d",&n);
	for(j=u;j<u+n;j++)
	{
	printf("\n\n\t\t\tEnter train number: ");
	scanf("%s", book[j].train_number);
	for(i=0;i<k;i++)
	{
	if(strcmp(book[j].train_number,add[i].train_number)==0)
	{
	if(add[i].seat==0)
	{
		printf("\n\n\t\t\tnot available seat");

		getch();
		system("cls");
		main_t();
	}
	else
	{
	    found=1;
		printf("\n\t\t\tenter book %d no ticket: ",j+1);
		printf("\n\t\t\tenter date: ");
		scanf("%s",book[j].date);
		printf("\n\t\t\tenter your name: ");
		scanf("%s",book[j].name);
		printf("\n\t\t\tenter your phone number: ");
		scanf("%s",book[j].phone);
		printf("\n\t\t\tseat number : %d",add[i].seat );
		book[j].seat=add[i].seat;
		bookticket_write();
		add[i].seat--;
		awrite();
		}
	}
}
	if(found==-1)
	{
		printf("\n\n\t\t\ttrain not found!!!");
		getch();
		system("cls");
		main_t();
	}

	}
		u=j;
		bookticket_write();
		printf("\n\n\t\t\tenter '1' for main_t menu & press any key to exit: ");
		scanf("%d",&c);
			if(c==1)
			{
				system("cls");
				main_t();
			}
			if(c!=1)
			{
				exit;
			}
}

void cancelticket()
{
	viewpassengers_read();
    char pnnmbr[100];
    int location = -1,e;
    printf ("\n\n\t\t\tenter phone number: ");
    scanf ("%s",pnnmbr);
    for (e=0;e<u;e++)
    {
        if (strcmp(pnnmbr,book[e].phone)==0)
        {
            location=e;
            break;
        }
    }
    if (location==-1)
    {
        printf ("\n\n\t\t\t<<<<<<<<<<<<<<Data Not Found>>>>>>>>>>>>>>>>> \n");
        getch();
        system("cls");
        main_t();
    }
    else
    {
        for (e=location;e<u-1;e++)
        {
            strcpy(book[e].date,book[e+1].date);
            strcpy(book[e].train_number,book[e+1].train_number);
            strcpy(book[e].name,book[e+1].name);
            strcpy(book[e].phone,book[e+1].phone);
            bookticket_write();
        }
        u--;
        bookticket_write();
        printf("\n\n\t\t\t<<<<<<<<<<<<<<<ticket cancelled successfully>>>>>>>>>>>>");
        getch();
        system("cls");
        main_t();
    }
}

void admin()
{
	int chhh;
	system("cls");
	printf("\n\t\t\t=================================\n");
    printf("\t\t\t=   RAILWAY MANAGEMENT SYSTEM   =\n");
    printf("\t\t\t=================================\n");
	printf("\n\n");
	printf("\n\n");
	printf("              ************************************\n");
	printf("              ||      CHOOSE YOUR LIST     ||\n");
	printf("              ||--------------------------------||\n");
	printf("              ||      [1] VIEW PASSENGERS       ||\n");
	printf("              ||      [2] ADD TRAIN             ||\n");
	printf("              ||      [3] DELETE TRAIN          ||\n");
	printf("              ||      [4] BACK                  ||\n");       
	printf("              ||                                ||\n");
	printf("              ************************************\n\n");
	printf("     **********************************************************\n");
	printf("\n\t\tENTER YOUR CHOICE(*Only digits*): ");
	scanf("%d",&chhh);

	switch(chhh)
	{
		case 1:
			viewpassenger();
			break;
			case 2:
				addtrain();
				break;
				case 3:
					dlttrain();
					break;
					case 4:
						system("cls");
						getch();
						main_t();
						break;
						default:
							getch();
							printf("\n\t\t\tyou entered wrong KEY!!!!");
							//getch();
							system("cls");
							main_t();
	}
	getch();
}

void password()
{
	int number=1234567;
	int pass;
	printf("\n\t\t\tenter password: ");
	scanf("%d",&pass);
	if(pass==number)
	{
		printf("\n\n\t\t\t<<<<<login successfully>>>>>");
		getch();
		system("cls");
		admin();
	}
	else
	{
		printf("\n\n\t\t\t\t   ERROR!!!!!");
		printf("\n\n\t\t\t<<<<<<<<wrong password>>>>>>>>");
		getch();
		system("cls");
		main_t();
	}
}
//------------------------------------delete train function----------------------------------------------
void dlttrain()
{
	aread();
    char train[100];
    int location = -1,f;
    printf ("\n\n\tenter train number: ");
    scanf ("%s",train);
    for (f=0;f<k;f++)
    {
        if (strcmp(train,add[f].train_number)==0)
        {
            location=f;
            break;
        }
    }
    if (location==-1)
    {
        printf ("\n\n\t<<<<<<<<<<<<<<Data Not Found>>>>>>>>>>>>>>>>> \n");
        getch();
        system("cls");
        admin();
    }
    else
    {
        for (f=location;f<k;f++)
        {
            strcpy(add[f].si,add[f+1].si);
            strcpy(add[f].train_number,add[f+1].train_number);
            strcpy(add[f].train_name,add[f+1].train_name);
            strcpy(add[f].start,add[f+1].start);
            strcpy(add[f].destination,add[f+1].destination);
            strcpy(add[f].price,add[f+1].price);

            strcpy(add[f].time,add[f+1].time);
            awrite();
        }
        k--;
        awrite();
		printf("\n\n\t<<<<<<<<<<<<<train deleted successfully>>>>>>>>>>>>>");
		getch();
		system("cls");
		admin();
    }
}
//--------------------------------------view passengers function----------------------------------------
void viewpassenger()
{
	int a,j;
	system("cls");
	viewpassengers_read();
	printf("\n\t\t\t=================================\n");
    printf("\t\t\t=   RAILWAY MANAGEMENT SYSTEM   =\n");
    printf("\t\t\t=================================\n");
	printf("\n\n\t\t\ttrain number\t\tname\t\tphone number\t\tdate\t\tseat\n");
	printf("\n\t\t\t**********************************************************************************\n");
	for(j=0;j<u;j++)
	{
		printf("\n\t\t\t%s\t\t\t%s\t\t%s\t\t%s\t%d",book[j].train_number,book[j].name,book[j].phone,book[j].date,book[j].seat);
		book[j].seat++;
	}
	printf("\n\t\t\t**********************************************************************************\n");
	printf("\n\n\t\t\tenter '1' for main_t menu & enter '0' for back: ");
	scanf("%d",&a);
	if(a==1)
	{
		system("cls");
		main_t();
	}
	if(a==0)
	{
		system("cls");
		admin();
	}
}

void addtrain()
{
	system("cls");
	int ch;
	aread();
	int i,a;
	printf("\n\t\t\t=================================\n");
    printf("\t\t\t=   RAILWAY MANAGEMENT SYSTEM   =\n");
    printf("\t\t\t=================================\n");
	printf("\n\n\t\t\thow many trains do you want to add: ");
	scanf("%d",&a);
	for(i=k;i<k+a;i++)
	{
		printf("\n\t\t\tenter %d train details: ",i+1);
		printf("\n\t\t\tenter serial number(in words): ");
		scanf("%s",add[i].si);
		printf("\n\t\t\tenter train number(in words): ");
		scanf("%s",add[i].train_number);
		printf("\n\t\t\tenter train name: ");
		scanf("%s",add[i].train_name);
		printf("\n\t\t\tenter start place: ");
		scanf("%s",add[i].start);
		printf("\n\t\t\tenter destination place: ");
		scanf("%s",add[i].destination);
		printf("\n\t\t\t enter price(in words): ");
		scanf("%s",add[i].price);
		printf("\n\t\t\t enter seat: ");
		scanf("%d", & add[i].seat);
		printf("\n\t\t\t enter time(in words): ");
		scanf("%s",add[i].time);
	}

		printf("\n\n\t\t\tconfirm train: (y=1/n=0):- ");
		scanf("%d",&ch);
		if(ch==1)
		{
			awrite();
			k=i;
			awrite();
			system("cls");
			printf("\n\t\t\t=================================\n");
            printf("\t\t\t=   RAILWAY MANAGEMENT SYSTEM   =\n");
            printf("\t\t\t=================================\n");
			printf("\n\n");
			printf("\n\t\t\t\t   **********************************");
			printf("\n\t\t\t\t   *<<<<<train add successfully>>>>>*");
			printf("\n\t\t\t\t   **********************************");
			getch();
			system("cls");
			main_t();
		}
			if(ch==0)
			{
				system("cls");
				admin();
			}
			if((ch!=1)&&(ch!=0))
			{
				system("cls");
				main_t();
			}
}

void viewinfo()
{
	int ch,i;
	system("cls");
	aread();
	printf("\n\t\t\t=================================\n");
    printf("\t\t\t=   RAILWAY MANAGEMENT SYSTEM   =\n");
    printf("\t\t\t=================================\n");
	printf("\n\n\n    SI\ttrain number\ttrain name\tstart place\tdestination place\tprice\tseat\ttime\n\n");
	for(i=0;i<k;i++)
	{
		printf("    %s\t%s\t\t%s\t\t%s\t\t%s\t\t\t%s\t%d\t%s\n",add[i].si,add[i].train_number,add[i].train_name,add[i].start,add[i].destination,add[i].price,add[i].seat,add[i].time);
	}
	printf("    ***********************************************************************************************\n");
	printf("\n\t\t\tpress '1' for main_t menu & press any key for exit:  ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			system("cls");
			main_t();
			break;
				default:
					exit(0);
	}
}
//------------------------------------------book ticket file start-----------------------------------------
void bookticket_write()
{
	FILE *booklist;
	booklist=fopen("booklist.txt","w");
	fwrite(&book,sizeof(book),1,booklist);
	fclose(booklist);

	FILE *booklistreport;
	booklistreport=fopen("booklistreport.txt","w");
	fwrite(&u,sizeof(u),1,booklistreport);
	fclose(booklistreport);
}
void viewpassengers_read()
{
	FILE *booklist;
	booklist=fopen("booklist.txt","r");
	fread(&book,sizeof(book),1,booklist);
	fclose(booklist);

	FILE *booklistreport;
	booklistreport=fopen("booklistreport.txt","r");
	fread(&u,sizeof(u),1,booklistreport);
	fclose(booklistreport);
}

void awrite()
{
	FILE *train_details;
	train_details = fopen("train_details.txt","w");
	fwrite(&add,sizeof(add),1,train_details);
	fclose(train_details);

	FILE *train_report;
	train_report = fopen("train_report.txt","w");
	fwrite(&k,sizeof(k),1,train_report);
	fclose(train_report);
}
void aread()
{
	FILE *train_details;
	train_details = fopen("train_details.txt","r");
	fread(&add,sizeof(add),1,train_details);
	fclose(train_details);

	FILE *train_report;
	train_report = fopen("train_report.txt","r");
	fread(&k,sizeof(k),1,train_report);
	fclose(train_report);
}

//*************************************Bus function definition********************************main_b
void main_b()
{
    

	login();
    int num,i;
    do{
    system("cls");
    printf("\n\n\n");
    system("COLOR 0f");
	int ch;
	time_t currentTime;
	time(&currentTime);
	printf("\n\t\t\t\t\t     %s\n",ctime(&currentTime));
    printf("====================================== WELCOME TO BUS RESERVATION SYSTEM ======================================\n\n\n");
    printf("\t\t\t\t\t[1]=> View Bus List\n");
    printf("\n");
    printf("\t\t\t\t\t[2]=> Book Tickets\n");
    printf("\n");
    printf("\t\t\t\t\t[3]=> Cancle Booking\n");
    printf("\n");
    printf("\t\t\t\t\t[4]=> Bus Status Board\n");
    printf("\n");
    printf("\t\t\t\t\t[5]=> Exit\n\n");
    printf("===============================================================================================================\n\n");
    printf("\t\t\tEnter Your Choice:: ");
    scanf("%d",&num);
    switch(num)
    {
    case 1:
        bus();//for list of bus
        break;
    case 2:
        booking();//for booking the tickets
        break;
    case 3:
        cancle();
        break;
    case 4:
        status();
        break;
    }
getch();
    }while(num != 5);
    system("CLS");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\tThank You For Using This System\t\t\t\t\t\t\n");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    system("cls");
	main();
	getch();
    return 0;
}


void bus()
{
    system("cls");
    printf("\n\n\n");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    printf("\t\t\t\t\t[1]  =>  %s\n",ch[0]);
    printf("\n");
    printf("\t\t\t\t\t[2]  =>  %s\n",ch[1]);
    printf("\n"); 
	printf("\t\t\t\t\t[3]  =>  %s\n",ch[2]);
    printf("\n"); 
	printf("\t\t\t\t\t[4]  =>  %s\n",ch[3]);
    printf("\n"); 
	printf("\t\t\t\t\t[5]  =>  %s\n",ch[4]);
}

void booking()
{

int i=0;
char numstr[100];
system("cls");
//printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");//for entering bus number
bus();//for seeing bus list
printf("Enter the Bus number:--->");
scanf("%d",&trno);
system("cls");
printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");//for selecting seat
printf("Your Bus Number is %d ********** %s",trno,ch[trno-1]);
status_1(trno);
 FILE *f1, *fopen();//for reading the seats from the user.
 char str1[80]="32",str2[4],str3[4];
 int seat1,seat2,booking=0;
if(trno == 1)
{
 f1 = fopen("tr1.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}else if(trno == 2)
{
 f1 = fopen("tr2.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}else if(trno == 3)
{
 f1 = fopen("tr3.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
else if(trno == 4)
{
 f1 = fopen("tr4.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
else if(trno == 5)
{
 f1 = fopen("tr5.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
seat1=atoi(str1);//covert the string into number
if(seat1 <= 0)
{
 printf("There is no blank seat in this bus ");
}else
{
printf("\n\n\n\t\t\t\tAvailable Seats:------>%d\n",seat1);
printf("\n\t\t\t\tNumber of Tickets:----->");
scanf("%d",&booking);
printf("\n");

seat1=seat1-booking;
itoa(trno,numstr,10);
nameN_number(booking,numstr);
printf("\n\t\t\t\tThe Total booking amount is %d",200*booking);
itoa(seat1, str1, 10);
//for reading the seats from the user.
if(trno == 1)
{
 f1 = fopen("tr1.txt","w");
 fputs(str1,f1);
 fclose(f1);
}
else if(trno == 2)
{
 f1 = fopen("tr2.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(trno == 3)
{
 f1 = fopen("tr3.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(trno == 4)
{
 f1 = fopen("tr4.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(trno == 5)
{
 f1 = fopen("tr5.txt","w");
 fputs(str1,f1);
 fclose(f1);
}
}
}



void nameN_number(int booking,char numstr[100])
{
char tempstr[100],tempstr1[12]="status",tempstr2[12]="number";
int number;
    FILE *a,*b;
    int i=0;
   strcat(numstr,".txt");
   strcat(tempstr1,numstr);
   strcat(tempstr2,numstr);
   a = fopen(tempstr1,"a");//for open the file to write the nameN in the file
   b = fopen(tempstr2,"a");//for open the file for writing the number in the file
for(i=0; i<booking; i++)//for entering the person nameN and seat number in the file
{
    printf("============================Enter the details for ticket no %d============================\n\n\n",i+1);
      printf("\t\t\t\tEnter the seat number:--->");
      scanf("%d",&number);
      printf("\t\t\t\tEnter the nameN of person:--->");
      scanf("%s",nameN[number-1]);
    printf("\n======================================================================================================\n\n");
    printf("\n");
      itoa(number, tempstr, 10);
      fprintf(a,"%s ",nameN[number-1]);
      fprintf(b,"%s ",tempstr);

}
fclose(a);
fclose(b);
}



int read_number(int trno)//for putting the numeric value in the array
{
char tempstr[100],tempstr2[12]="number";
FILE *a,*b;
char numstr[100];
int i=0,j=0,k;
itoa(trno,numstr,10);
strcat(numstr,".txt");
strcat(tempstr2,numstr);
a = fopen(tempstr2,"a+");//for open the file to write the nameN in the file
   while(!feof(a))
   {
      number[i][j] = fgetc(a);

      if(number[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
      j++;
      }
   }
   k=i;
   for(i=0; i<k; i++)
   {
       num1[i] = atoi(number[i]);
   }
   fclose(a);
   return k;
}


void read_nameN(int trno)//for putting the numeric value in the array
{
char tempstr1[12]="status";
FILE *b;
char numstr[100];
int i=0,j=0,k=0;
itoa(trno,numstr,10);
strcat(numstr,".txt");
strcat(tempstr1,numstr);
b = fopen(tempstr1,"a+");//for open the file to write the nameN in the file
   while(!feof(b))
   {
      nameN[i][j] = fgetc(b);

      if(nameN[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
        j++;
      }

   }
   nameN[i][j]='\0';
   k=i;
   fclose(b);
}

void status()
{
system("cls");
//printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    int i,trno,index=0,j;
    char tempnameN[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
    printf("Enter the number of bus:---->");
    scanf("%d",&trno);
    j=read_number(trno);
    read_nameN(trno);
    printf("____________________________________________________________________________________________________________________\n");
    printf("                                      Bus.no-->%d---->%s                                                            \n",trno,ch[trno-1]);
   // printf("____________________________________________________________________________________________________________________\n");
    
    for(i=0; i<j; i++)
    {
        strcpy(tempnameN[num1[i]],nameN[i]);
    }
    for(i=0; i<8; i++)
    {
        //printf("\t\t\t\t");
        for(j=0; j<4; j++)
        {
        printf("%d.%s\t",index+1,tempnameN[index+1]);
        index++;
        }
        printf("\n");
    }
}

void status_1(int trno)
{
    printf("Your Bus Number is %d ********** %s",trno,ch[trno-1]);
    system("cls");
printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    int i,index=0,j;
    j=read_number(trno);
    read_nameN(trno);
    char tempnameN[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
    for(i=0; i<j; i++)
    {
        strcpy(tempnameN[num1[i]],nameN[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempnameN[index+1]);
        index++;
            }
            printf("\n");
}
}


void cancle()
{
 int seat_no,i,j;
 char numstr[100],tempstr2[15]="number",tempstr1[15]="status";
 printf("Enter the bus number:---->");
 scanf("%d",&trno);
 itoa(trno,numstr,10);
 strcat(numstr,".txt");
 strcat(tempstr1,numstr);
 strcat(tempstr2,numstr);
 read_number(trno);
 read_nameN(trno);
 status_1(trno);
 printf("Enter the seat number:--->");
 scanf("%d",&seat_no);
 FILE *a,*b;
 a = fopen(tempstr1,"w+");
 b = fopen(tempstr2,"w+");
 for(i=0; i<32; i++)
 {
     if(num1[i] == seat_no)
     {
         for(j=0; j<32; j++)
         {
             if(num1[j] != seat_no && num1[j] != 0)
             {
                 fprintf(b,"%d ",num1[j]);
                 fprintf(a,"%s",nameN[j]);
             }
             else if(num1[j] == seat_no && num1[j] != 0)
             {
                 strcpy(nameN[j],"Empty ");
             }
         }
     }
 }
fclose(a);
fclose(b);
printf("\n\n");
    printf("======================================================================================================\n");
 printf("\t\t\t\tYour 200 rupees has been Returned\t\t\t\n");
    printf("======================================================================================================\n");
}


void login()
{
	int a=0,i=0;
    char unameN[10],c=' '; 
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{
	system("cls");
	
    printf("\n  =========================  LOGIN FORM  =========================  ");
    printf(" \n                       ENTER USERnameN:-");
	scanf("%s", &unameN); 
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword); 
	if(strcmp(unameN,"user")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \n\n\n       WELCOME TO OUR SYSTEM !!!! LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		
		getch();//holds the screen
		
	}
    
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong usernameN and password for four times!!!");
		
		getch();
		
		}
		system("cls");	
        
}



//**********************************************Cab Functions**************************************************

void main_c() {
    // Initializing an array of cabs with prices
    struct Cab cabs[8] = {
        {"John", "ABC123", 1, 10.0, 12.0},
        {"Alice", "XYZ456", 1, 12.0, 15.0},
        {"Bob", "DEF789", 1, 15.0, 18.0},
        {"Eva", "GHI012", 1, 8.0, 10.0},
        {"Mike", "JKL345", 1, 14.0, 16.0},
        {"Sara", "MNO678", 1, 11.0, 13.0},
        {"Tom", "PQR901", 1, 13.0, 15.0},
        {"Grace", "STU234", 1, 9.0, 11.0}
    };
    cabs[0].interCityPrice = 100.0;
    cabs[0].outerCityPrice = 250.0;

    cabs[1].interCityPrice = 120.0;
    cabs[1].outerCityPrice = 200.0;

    cabs[2].interCityPrice = 140.0;
    cabs[2].outerCityPrice = 170.0;

    cabs[3].interCityPrice = 70.0;
    cabs[3].outerCityPrice = 190.0;

    cabs[4].interCityPrice = 130.0;
    cabs[4].outerCityPrice = 150.0;

    cabs[5].interCityPrice = 160.0;
    cabs[5].outerCityPrice = 220.0;

    cabs[6].interCityPrice = 190.0;
    cabs[6].outerCityPrice = 300.0;

    cabs[7].interCityPrice = 80.0;
    cabs[7].outerCityPrice = 150.0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Book a cab
                bookCab(cabs, 8);
                break;

            case 2:
                // Display available cabs
                displayAvailableCabs(cabs, 8);
                break;

            case 3:
                // Cancel cab booking
                cancelCabBooking(cabs, 8);
                break;

            case 4:
                // Show booking status
                showBookingStatus(cabs, 8);
                break;

            case 5:
                // Display prices
                displayPrices(cabs, 8);
                break;

            case 6:
                // Exit the program
                printf("Exiting Cab Booking System. Have a great day!\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 6);
	system("CLS");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\tThank You For Using This System\t\t\t\t\t\t\n");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    system("cls");
	main();
	getch();
    return 0;

    return 0;
}

// Function to display the menu
void displayMenu() {
    system("cls");
    printf("=========================================== CAB RESERVATION SYSTEM ============================================\n\n\n");
    printf("\t\t\t\t[1]. Book Cabs \n");
    printf("\t\t\t\t[2]. Display Available Cabs\n");
    printf("\t\t\t\t[3]. Cancel Cab Booking\n");
    printf("\t\t\t\t[4]. Show Booking Status\n");
    printf("\t\t\t\t[5]. Display Prices\n");
    printf("\t\t\t\t[6]. Exit\n");
    printf("\t\t\t\tEnter your choice: ");
}

// Function to book a cab
void bookCab(struct Cab cabs[], int numCabs) {
    system("cls");
    
    printf("Enter the cab number you want to book: ");
    char cabToBook[20];
    scanf("%s", cabToBook);

    int cabIndex = findCabIndex(cabs, numCabs, cabToBook);

    float distance;

    if (cabIndex != -1 && cabs[cabIndex].available) {
        printf("Cab booked successfully! Enjoy your ride with %s.\n", cabs[cabIndex].driverName);
        
        // New code to ask for the number of travelers
        int numTravelers;
        float total=0;
        printf("Enter the number of travelers: ");
        scanf("%d", &numTravelers);

        printf("Select ride type:\n");
        printf("1. Intra-City (Price: Rs.%.2f)\n", cabs[cabIndex].interCityPrice);
        printf("2. Outer-City (Price: Rs.%.2f)\n", cabs[cabIndex].outerCityPrice);
        
        int rideType;
        scanf("%d", &rideType);

        if (rideType == 1) {
            // New code to calculate total price for intra-city based on the number of travelers
            float totalIntraCityPrice = cabs[cabIndex].interCityPrice * numTravelers;
            total = allotVehicle(numTravelers,totalIntraCityPrice);
            printf("Intra-City ride booked. Price (for %d travelers): Rs.%.2f\n", numTravelers, total);
            
        } else if (rideType == 2) {
            printf("Enter the distance of your ride in units: ");
            scanf("%f", &distance);
            // For outer-city, add an additional amount based on distance
            float totalOuterCityPrice = calculateTotalPrice(cabs[cabIndex].outerCityPrice, distance);
            total =  allotVehicle(numTravelers,totalOuterCityPrice);
            printf("Outer-City ride booked. Price (including distance amount) for %d travelers: Rs.%.2f\n", numTravelers, total);
           
        } else {
            printf("Invalid ride type selected.\n");
        }

        cabs[cabIndex].available = 0; // Mark the cab as unavailable
    } else {
        printf("Sorry, the requested cab is not available or does not exist.\n");
    }
}

float allotVehicle(int numTravelers, float totalAmount) {
    float total=0;
    if (numTravelers <= 4) {
        printf("Vehicle Allotted: Sedan\n");
        total = totalAmount + 20.0;
        return total;
         // Additional price for Sedan
    } else if (numTravelers <= 7) {
        printf("Vehicle Allotted: HATCHBACK\n");
        total = totalAmount + 30.0;
        return total;
         // Additional price for SUV
    } else if (numTravelers <= 12) {
        printf("Vehicle Allotted: SUV\n");
        total = totalAmount + 15.0;
        return total;
         // Additional price for Hatchback
    } else {
        printf("Vehicle Allotted: Bus\n");
        total = totalAmount + 50.0; 
        return total;// Additional price for Bus
    }
}

float calculateTotalPrice(float basePrice, float distance) {
    // Add an amount of 70 to every 50 units
    float additionalAmount = (distance / 50) * 70;
    return basePrice + additionalAmount;
}
// Function to display available cabs
void displayAvailableCabs(struct Cab cabs[], int numCabs) {
     system("cls");
    printf("Available Cabs:\n");
    
    for (int i = 0; i < numCabs; i++) {
        if (cabs[i].available) {
            printf("%s (%s)\n", cabs[i].driverName, cabs[i].cabNumber);
            printf("  - Intra-City Price: Rs.%.2f\n", cabs[i].interCityPrice);
            printf("  - Outer-City Price: Rs.%.2f\n", cabs[i].outerCityPrice);
            printf("\n");
        }
    }
}

// Function to cancel cab booking
void cancelCabBooking(struct Cab cabs[], int numCabs) {
    system("cls");
    printf("Enter the cab number you want to cancel: ");
    char cabToCancel[20];
    scanf("%s", cabToCancel);

    int cabIndex = findCabIndex(cabs, numCabs, cabToCancel);

    if (cabIndex != -1 && !cabs[cabIndex].available) {
        printf("Cab booking canceled for %s. Thank you!\n", cabs[cabIndex].driverName);
        cabs[cabIndex].available = 1; // Mark the cab as available
    } else {
        printf("Sorry, the requested cab is not booked or does not exist.\n");
    }
}

// Function to show booking status
void showBookingStatus(struct Cab cabs[], int numCabs) {
    system("cls");
    printf("Booking Status:\n");
    for (int i = 0; i < numCabs; i++) {
        printf("%s (%s): %s\n", cabs[i].driverName, cabs[i].cabNumber, cabs[i].available ? "Available" : "Booked");
    }
}

// Function to display prices
void displayPrices(struct Cab cabs[], int numCabs) {
    system("cls");
    printf("Available Cabs:\n");
    for (int i = 0; i < numCabs; i++) {
        if (cabs[i].available) {
            printf("%s (%s)\n", cabs[i].driverName, cabs[i].cabNumber);
            printf("  - Intra-City Price: Rs.%.2f\n", cabs[i].interCityPrice);
            printf("  - Outer-City Price: Rs.%.2f\n", cabs[i].outerCityPrice);
            printf("\n");
        }
    }
}

// Function to find the index of a cab in the array based on the cab number
int findCabIndex(struct Cab cabs[], int numCabs, const char *cabNumber) {

    for (int i = 0; i < numCabs; i++) {
        if (strcmp(cabNumber, cabs[i].cabNumber) == 0) {
            return i;
        }
    }
    return -1; // Cab not found
}



int main()
{
	int ch;
	do{
    system("cls");
	system("COLOR 0f");
	int ch;
	time_t currentTime;
	time(&currentTime);
	printf("\n       \t\t\t\t     %s\n",ctime(&currentTime));
	printf("=========================================== ABC TRAVELLING SYSTEM ============================================\n\n\n");
	printf("\t\t\t\t\t[1]=> BUS RESERVATION\n");
    printf("\n");
    printf("\t\t\t\t\t[2]=> TRAIN RESERVATION\n");
    printf("\n");
	printf("\t\t\t\t\t[3]=> CAB RESERVATION\n");
    printf("\n");
	printf("Enter the choice :  ");
	scanf(" %d",&ch);
	switch(ch)
	{
		case 1:
			main_b();
			break;
		case 2:
			main_t();
			break;
		case 3:
			main_c();
			break;
		default:
			printf("Enter a valid choice\n");
			break;
		
		}
	}while(ch!=0);

    return 0;
}



