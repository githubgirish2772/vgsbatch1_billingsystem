#include<stdio.h>
struct product
{
int pid;
char name[20];
float price;	
};
void addProduct()
{
	struct product p1;
	printf("Enter id :");
	scanf("%d",&p1.pid);
	
	printf("Enter name :");
	scanf("%s",&p1.name);
	
	printf("Enter price :");
	scanf("%f",&p1.price);
	
	FILE *ptr;
	ptr = fopen("product.dat","a");
	
	fwrite(&p1,sizeof(struct product),1,ptr);
	
	fclose(ptr);
}

void productList()
{
	struct product p1;
	
	FILE *ptr;
	ptr = fopen("product.dat","r");
	
	while(fread(&p1,sizeof(struct product),1,ptr))
	{
		printf("%d\t%s\t%f\n",p1.pid,p1.name,p1.price);
	}
	fclose(ptr);
}


void updateProduct()
{
	int id;
	int offset;
	struct product p1;
	struct product new_p1;
	
	printf("Enter PRoduct ID:");
	scanf("%d",&id);
	
	FILE *ptr1,*ptr2;
	ptr1 = fopen("product.dat","r+");
	
	if(ptr1 == null)
	{
		printf("unable to open file");
		return;
	}
	
	while(fread(&p1,sizeof(struct product),1,ptr1))
	{
		if(p1.pid == id)
		{
			new_p1.pid = id;
			
			printf("Enter new name :");
			scanf("%s",&new_p1.name);
			
			printf("Enter new price :");
			scanf("%f",&new_p1.price);
			
			offset = -1 * sizeof(struct product);
			fseek(ptr1,offset,1);
			
			fwrite(&new_p1,sizeof(struct product),1,ptr1);
			
			fclose(ptr1);
			
			break;
			
		}
	}
}


