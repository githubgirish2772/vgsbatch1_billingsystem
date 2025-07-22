#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct product 
{
    int pid;
    char name[50];
    float price;
};

void addproduct()
{
		
	struct product p1 ;
	
	printf("Enter id: ");
	scanf("%d",&p1.pid);
	
	printf("Enter name:");
	scanf("%s",&p1.name);
	
	printf("Enter price:");
	scanf("%f",&p1.price);
	
	FILE *ptr;
	ptr = fopen("product.dat","a");
	
	fwrite(&p1,sizeof(struct product),1,ptr);
	
	fclose(ptr);	
}

void searchProduct() 
{
	char choice;
	do
	{
		system("cls");
		int searchId;
    struct product p1;
    FILE *ptr;
    int found = 0;

    printf("Enter product ID to search: ");
    scanf("%d", &searchId);

    ptr = fopen("product.dat", "r");

    if (ptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (fread(&p1, sizeof(struct product), 1, ptr)) 
	 {
        if (p1.pid == searchId) 
		  {
            printf("\nProduct Found:\n");
            printf("ID   : %d\n", p1.pid);
            printf("Name : %s\n", p1.name);
            printf("Price: %.2f\n", p1.price);
            found = 1;
            break;
        }
    }

    if (!found) 
	 {
        printf("\nProduct with ID %d not found.\n", searchId);
    }
    
    getchar();
    printf("do you want to cont(y/n):");
    scanf("%c",&choice);

    fclose(ptr);
	}
	while(choice == 'y');
	
    
}
int main()
{
	searchProduct();
	
}
