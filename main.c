#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include "login.h"
#include "layout.h"
#include "splash.h"
#include "product.h"


void exitApp() {
    system("cls");
    centerText("Exiting the application. Thank you!", 10);
    Sleep(2000);
    exit(0);
}

void productMenu()
{
	int opt;
	while(1)
	{
		system("cls");
	    centerText("*********************************  |PRODUCT MENU|  ******************************** \n", 5);
	    centerText("--------------------------------------------------------------------------------\n ", 6);
		centerText("* please enter your choice from menu *\n", 7);
		printText("Enter 1 -> Add Product", 9,50);
	    printText("Enter 2 -> Products List", 10,50);
	    printText("Enter 3 -> Search Product", 11,50);
	    printText("Enter 4 -> Edit Product", 12,50);
	    printText("Enter 5 -> Delete Product", 13,50);
	    printText("Enter 6 -> Back to Main Menu", 14,50);
	    centerText("--------------------------------------------------------------------------------\n ", 15);
			
		printText("Enter your choice: ", 16,50);
	    gotoxy(70, 16);
	    scanf("%d",&opt);
	    switch (opt) {
	        case 1:  
	            addProduct(); 
				break;
	        case 2:  
	        	
				productList();
				break;
	        case 3:  
				searchProduct();
				break;
	        case 4:  
				updateProduct();
				break;
	        case 5:  
				deleteProduct();
				break;
	        case 6:  
				return;
	    }
	}
	
}

void orderMenu()
{
	
}
void mainmenu() {
    int choice;
    time_t t;
	time(&t);
	splash();
    while (1) {
        system("cls");
        centerText("*********************************  |MAIN MENU|  ******************************** \n", 5);
        centerText("--------------------------------------------------------------------------------\n ", 6);
		centerText("* please enter your choice from menu *\n", 7);
		printText("Enter 1 -> Manage Products", 9,50);
        printText("Enter 2 -> Manage Order", 10,50);
        printText("Enter 3 -> Exit", 11,50);
        centerText("--------------------------------------------------------------------------------\n ", 13);
		printText("Current date and time : ",14,50);
		gotoxy(75, 14);
		printf("%s",ctime(&t));
		centerText("---------------------------------------------------------------------------------\n",15);
        
		printText("Enter your choice: ", 16,50);
        gotoxy(70, 16);
        scanf("%d",&choice);
        switch (choice) {
            case 1:  productMenu();break;
            case 2:  orderMenu();break;
            case 3:  exitApp(); break;
        }
    }
}




int main() {
    setFullScreen();
    setColor();
    mainmenu();
    return 0;
}
