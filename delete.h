#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product 
{
   int pid;
   char name[50];
   float price;
};

void deleteProduct() 
{
   struct product p1;
   FILE *fp, *temp;
   int deleteId;
   int found = 0;

   printf("Enter the product ID to delete: ");
   scanf("%d", &deleteId);

   fp = fopen("product.dat", "rb");
   if (fp == NULL) 
	 {
        printf("Error opening file.\n");
        return;
    }

   temp = fopen("temp.dat", "wb");  

    while (fread(&p1, sizeof(struct product), 1, fp)) 
	 {
        if (p1.pid == deleteId) 
		  {
            found = 1;
            printf("Product with ID %d deleted.\n", deleteId);
        } else 
		  {
            fwrite(&p1, sizeof(struct product), 1, temp); 
        }
    }

    fclose(fp);
    fclose(temp);
	 remove("product.dat");
    rename("temp.dat", "product.dat");

    if (!found) 
	 {
      printf("Product with ID %d not found.\n", deleteId);
    }
}

int main()
{
	deleteProduct();
}
