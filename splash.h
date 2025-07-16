#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

void splash()
{
	int i=0;
	time_t t;
	time(&t);
	//SPLASH SCREEN
	centerText("------------------------------------------------------------------------------\n",4);
	centerText("|                                                                            |\n",5);
	centerText("|  000000  000000  000000  000000  000000  000000  0      0  000000  0000000 |\n",6);
	centerText("|  0       0    0  0       0          0       0    0 0    0  0       0       |\n",7);
	centerText("|  0  000  000000  000000  000000     0       0    0   0  0  0  000  0000000 |\n",8);
	centerText("|  0    0  0  0    0       0          0       0    0    0 0  0    0        0 |\n",9);
	centerText("|  000000  0   0   000000  000000     0    000000  0     00  000000  0000000 |\n",10);
	centerText("|                                                                            |\n",11);
	centerText("------------------------------------------------------------------------------\n",12);
	centerText("           *************************************************\n",13);
	centerText("           *                                               *\n",14);
	centerText("           *      ----------------------------------       *\n",15);
	centerText("           *              WELCOME TO HOTEL GALAXY          *\n",16);
	centerText("           *      ----------------------------------       *\n",17);
	centerText("           *                                               *\n",18);
	centerText("           *        Powered By VGS Infotech Students       *\n",19);
	centerText("           *                  Hyderabad                    *\n",20);
	centerText("           *        CONTACT US: 123456789,0123456789       *\n",21);
	centerText("           *                                               *\n",22);
	centerText("           *************************************************\n",23);
	gotoxy(20,25);
	for(i=0;i<80;i++)
		printf("-");
		
	gotoxy(20,26);
	printf("                Current date and time : %s",ctime(&t));
	
	gotoxy(20,27);
	for(i=0;i<80;i++)
		printf("-");
		
	centerText("            Press any key to continue :",29);
	getch();
}
