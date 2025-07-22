#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "search.h"

struct orderitem
{
	int ordid;
	int prodid;
	int qty;
	float tot;
};

struct order 
{
    int orderId;
    char orddate[10];
    float ordamt;
};

void addOrder() 
{
	int count;
	
	int ordid;
	char orddate[10];
	float ordamt;
	
   int pid;
   int qty;
   char more;
   
   ordid = 1001;
   //orddate = "22/07/2025";
   strcpy(orddate,"22/07/2025");
   ordamt = 0;
   
   struct orderitem items[10];
   count = 0;
	do
	{
		float price = 0;
		items[count].ordid = ordid;
		printf("Order Id : %d\n",ordid);
		
		printf("Enter Product ID: ");
    	scanf("%d", &items[count].prodid);
    	
    	
    	price = getPrice(items[count].prodid);
    	
    	printf("Price : %f\n",price);

    	printf("Enter Quantity: ");
    	scanf("%d", &items[count].qty);
    	
    	items[count].tot = price * items[count].qty;
    	printf("total : %f\n",items[count].tot);
    	
    	ordamt = ordamt + items[count].tot;
    	 	
    	
    	getchar();
    	printf("Do you need more item? (y/n)");
    	scanf("%c",&more);
    	count++;
	}
	while(more == 'y');
	
	
	//write order on file
	struct order o;
	o.orderId = ordid;
	//o.orddate = orddate;
	strcpy(o.orddate,orddate);
	o.ordamt = ordamt;
	
	FILE *fporder = fopen("order.dat", "a");
   fwrite(&o, sizeof(struct order), 1, fporder);
   fclose(fporder);
   
   
   //write orderitem on file
	struct orderitem oi;
	FILE *fpitem = fopen("orderitem.dat", "a");
	int i;
	for(i=0;i<=count;i++)
	{
		oi.ordid = items[i].ordid;
		oi.prodid = items[i].prodid;
		oi.qty = items[i].qty;
		oi.tot = items[i].tot; 
   	fwrite(&o, sizeof(struct order), 1, fpitem);
	}
	fclose(fpitem); 
	
	
}

void searchOrder() 
{
    /*int searchId, found = 0;
    struct Order o;
    FILE *fp = fopen("orders.txt", "r");

    if (fp == NULL) 
	 {
        printf("? No orders found.\n");
        return;
    }

    printf("\nEnter Order ID to search: ");
    scanf("%d", &searchId);

    while (fread(&o, sizeof(o), 1, fp)) 
	 {
    	
        if (o.orderId == searchId) 
		  {
            printf("\n? Order Found:\n");
            printf("Order ID: %d\n", o.orderId);
            printf("Product ID: %d\n", o.productId);
            printf("Customer Name: %s\n", o.customerName);
            printf("Quantity: %d\n", o.quantity);
            printf("Total Amount: ?%.2f\n", o.totalAmount);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("? Order not found.\n");

    fclose(fp);*/
}

int main() 
{
    int choice;

    do {
        printf("\n======= Order Management System =======\n");
        printf("1. Add Order\n");
        printf("2. Search Order\n");
        printf("3. Exit\n");
        printf("Choose option: ");
        scanf("%d", &choice);

        switch (choice) 
		  {
            case 1: addOrder(); break;
            case 2: searchOrder(); break;
            case 3: printf("Exiting...\n"); break;
            default: printf("? Invalid choice\n");
        }
    } while (choice != 3);

    return 0;
}
