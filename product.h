// add these five methods in this file
//addProduct()
//productList()
//searchProductById()
//updateProductById()
//deleteProductById()

void addProduct()
{
	char opt1;
	do
	{
		getchar();
		system("cls");
		printf("create Add product screen here, and save to file...\n");
		printf("do you want to add another product...(y/n)? ");
		opt1 = getchar();
	}
	while(opt1 == 'y');
}


