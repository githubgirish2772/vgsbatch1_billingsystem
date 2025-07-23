#include<stdio.h>
#include <string.h>
struct product
{
int pid;
char name[20];
float price;	
};

char* getProductName(int pid)
{
	struct product p1;
	static char name[20];
	FILE *ptr;
	ptr = fopen("product.dat","r");
	if(ptr == NULL)
	{
		return 0;
	}
	while(fread(&p1,sizeof(struct product),1,ptr))
	{
		if(p1.pid == pid)
		{
			strcpy(name,p1.name);
			break;
		}
	}
	fclose(ptr);
	//printf("ggg%s",name);
	//getche();
	return name;
}

float getProductPrice(int pid)
{
	struct product p1;
	float price = 0;
	FILE *ptr;
	ptr = fopen("product.dat","r");
	if(ptr == NULL)
	{
		return 0;
	}
	while(fread(&p1,sizeof(struct product),1,ptr))
	{
		if(p1.pid == pid)
		{
			price = p1.price;
			break;
		}
	}
	fclose(ptr);
	return price;
}

int isProductExists(int pid)
{
	struct product p1;
	int count = 0;
	FILE *ptr;
	ptr = fopen("product.dat","r");
	if(ptr == NULL)
	{
		return 2;
	}
	while(fread(&p1,sizeof(struct product),1,ptr))
	{
		if(p1.pid == pid)
		{
			count++;
			break;
		}
	}
	fclose(ptr);
	return count;
}

void addProduct()
{
	struct product p1;
	FILE *ptr;
	ptr = fopen("product.dat","a");
	do
	{
		system("cls");
		centerText("*********************************  |ADD PRODUCT|  ******************************** \n", 5);
		centerText("--------------------------------------------------------------------------------\n ", 6);
		centerText("* please press ESC for previous menu *\n", 7);
		centerText("* (or) Enter product Id \"0\" to ESC *\n", 8);
		centerText("--------------------------------------------------------------------------------\n ", 19);
		printText("Product Id    : ", 10,50);
		printText("Product Name  : ", 12,50);
		printText("Product Price : ", 14,50);
		gotoxy(66, 10);
		scanf("%d",&p1.pid);
		if(p1.pid == 0)
		{
			fclose(ptr);
			return;
		}
		gotoxy(66, 12);
		scanf("%s",&p1.name);
		gotoxy(66, 14);
		scanf("%f",&p1.price);
		
		if(isProductExists(p1.pid))
		{
			gotoxy(50,16);
			printf("Product With this Id already exists!\n");
			gotoxy(50,17);
			printf("Press ENTER to Add another product!");
		}
		else
		{
			fwrite(&p1,sizeof(struct product),1,ptr);
			gotoxy(50,16);
			printf("Product Saved Successfully!\n");
			gotoxy(50,17);
			printf("Press ENTER to Add another product!");
		}
	}
	while(getche() != '\e');
	fclose(ptr);
}

void productList()
{
	system("cls");
	centerText("*********************************  |PRODUCT LIST|  ******************************** \n", 5);
	centerText("--------------------------------------------------------------------------------\n ", 6);
	centerText("* please press ESC for previous menu *\n", 7);
	
		
	struct product p1;
	FILE *ptr;
	ptr = fopen("product.dat","r");
	if(ptr == NULL)
	{
		gotoxy(50,9);
		printf("Error opening file.\n");
		gotoxy(50,10);
		printf("Please contact your Administrator!");
	    return;
	}
	gotoxy(40,9);
	printf("Product Id");
	gotoxy(60,9);
	printf("Product Name");
	gotoxy(90,9);
	printf("Price");
	int y;
	y=10;
	while(fread(&p1,sizeof(struct product),1,ptr))
	{
		gotoxy(40,y);
		printf("%d",p1.pid);
		gotoxy(60,y);
		printf("%s",p1.name);
		gotoxy(90,y);
		printf("%6.2f\n",p1.price);
		y++;
	}
	gotoxy(40,++y);
	printf("Press ENTER to Previous Menu!");
	centerText("--------------------------------------------------------------------------------\n ", ++y);
	fclose(ptr);
	gotoxy(40,y);
	getche();
}


void updateProduct()
{
	int id;
	long int offset;
	struct product p1;
	struct product new_p1;
	FILE *ptr1;
	ptr1 = fopen("product.dat","r+");
	
	do
	{
		system("cls");
		centerText("*********************************  |UPDATE PRODUCT|  ******************************** \n", 5);
		centerText("--------------------------------------------------------------------------------\n ", 6);
		centerText("* please press ESC for previous menu *\n", 7);
		centerText("* (or) Enter product Id \"0\" to ESC *\n", 8);
		centerText("--------------------------------------------------------------------------------\n ", 19);
		printText("Product Id    : ", 10,50);
		printText("Product Name  : ", 12,50);
		printText("Product Price : ", 14,50);
		
		gotoxy(66, 10);
		scanf("%d",&id);
		if(id == 0)
		{
			fclose(ptr1);
			return;
		}
	
		if(isProductExists(id))
		{
			if(ptr1 == NULL)
			{
				gotoxy(50,16);
				printf("Error opening file.\n");
				gotoxy(50,17);
				printf("Please contact your Administrator!");
		        return;
			}
			while(fread(&p1,sizeof(struct product),1,ptr1))
			{
				if(p1.pid == id)
				{
					gotoxy(76, 10);
					printf("New Values");
					gotoxy(66, 12);
					printf("%s",p1.name);
					gotoxy(66, 14);
					printf("%6.2f",p1.price);
			
					new_p1.pid = id;
					
					gotoxy(76, 12);
					getchar();
					
					gets(new_p1.name);
										
					gotoxy(76, 14);
					scanf("%f",&new_p1.price);
					
					offset = sizeof(struct product);
					fseek(ptr1,-offset,1);
					
					fwrite(&new_p1,sizeof(struct product),1,ptr1);
					gotoxy(50,16);
					printf("Product Updated Successfully!\n");
					gotoxy(50,17);
					printf("Press ENTER to Update another product!");
					rewind(ptr1);
					break;
				}
			}	
		}
		else
		{
				gotoxy(50,16);
				printf("Product With this Id does not exists!\n");
				gotoxy(50,17);
				printf("Press ENTER to Update another product!");
		}
	}
	while(getche() != '\e');
	fclose(ptr1);
}

void deleteProduct() 
{
	struct product p1;
   	FILE *fp, *temp;
   	int deleteId;
	do
	{
		fp = fopen("product.dat", "rb");
   		temp = fopen("temp.dat", "wb");
		system("cls");
		centerText("*********************************  |DELETE PRODUCT|  ******************************** \n", 5);
		centerText("--------------------------------------------------------------------------------\n ", 6);
		centerText("* please press ESC for previous menu *\n", 7);
		centerText("* (or) Enter product Id \"0\" to ESC *\n", 8);
		centerText("--------------------------------------------------------------------------------\n ", 19);
		printText("Product Id    : ", 10,50);
		printText("Product Name  : ", 12,50);
		//printText("Product Price : ", 14,50);
		
		gotoxy(66, 10);
		scanf("%d",&deleteId);
		if(deleteId == 0)
		{
			fclose(fp);
			return;
		}
		if (fp == NULL) 
		{
        	gotoxy(50,16);
			printf("Error opening file.\n");
			gotoxy(50,17);
			printf("Please contact your Administrator!");
	        return;
    	}
    	//check if the selected product id present in file
    	if(isProductExists(deleteId))
    	{
    		char opt;
    		gotoxy(66, 12);
			printf("%s",getProductName(deleteId));
    		gotoxy(50,16);
			printf("This will delete the record from file,are you sure?(y/n)");
			getchar();
			opt = getchar();
			if(opt== 'y' || opt == 'Y')
			{
				while (fread(&p1, sizeof(struct product), 1, fp)) 
				{
			        if (p1.pid != deleteId) 
					{
			            fwrite(&p1, sizeof(struct product), 1, temp); 
			        } 
		    	}
		    	fclose(fp);
	    		fclose(temp);
				remove("product.dat");
	    		rename("temp.dat", "product.dat");
	    		gotoxy(50,16);
				printf("Product Deleted Successfully!                                  \n");
				gotoxy(50,17);
				printf("Press ENTER to Delete another product!");
			}
			else
			{
				gotoxy(50,16);
				printf("Product Not Deleted!                                       \n");
				gotoxy(50,17);
				printf("Press ENTER to Delete another product!");
			}
		}
		else
		{
			gotoxy(50,16);
			printf("Product Not Found!\n");
			gotoxy(50,17);
			printf("Press ENTER to Delete another product!");
			fclose(fp);
    		fclose(temp);
		}	
	}
	while(getche() != '\e');
}

void searchProduct() 
{
	int searchId;
	struct product p1;
	FILE *ptr;
	ptr = fopen("product.dat", "r");
	int found;
	do
	{
		found=0;
		system("cls");
		centerText("*********************************  |SEARCH PRODUCT|  ******************************** \n", 5);
		centerText("--------------------------------------------------------------------------------\n ", 6);
		centerText("* please press ESC for previous menu *\n", 7);
		centerText("* (or) Enter product Id \"0\" to ESC *\n", 8);
		centerText("--------------------------------------------------------------------------------\n ", 19);
		printText("Product Id    : ", 10,50);
		printText("Product Name  : ", 12,50);
		printText("Product Price : ", 14,50);
		
		gotoxy(66, 10);
		scanf("%d",&searchId);
		if(searchId == 0)
		{
			fclose(ptr);
			return;
		}
	    
	    if (ptr == NULL) {
	        gotoxy(50,16);
			printf("Error opening file.\n");
			gotoxy(50,17);
			printf("Please contact your Administrator!");
	        return;
	    }

	    while(fread(&p1, sizeof(struct product), 1, ptr)) 
		{
	        if (p1.pid == searchId) 
			{
			  	gotoxy(66, 12);
				printf("%s",p1.name);
				gotoxy(66, 14);
				printf("%6.2f",p1.price);
				found = 1;
				gotoxy(50,16);
				printf("Product Found!\n");
				gotoxy(50,17);
				printf("Press ENTER to Search another product!");
				rewind(ptr);
	            break;
	        }
	    }

	    if (!found) 
		{
			gotoxy(50,16);
			printf("Product Not Found!\n");
			gotoxy(50,17);
			printf("Press ENTER to Search another product!");
			rewind(ptr);
	    }
	}
	while(getche() != '\e');
	fclose(ptr);
}


