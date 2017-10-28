#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct details
{
	char name[20];
	int price;
	int qty;
	int id;
};
struct details items[50];
void Display();
void main()
{
	FILE *fptr;
	fptr=fopen("qty.csv","w");
	fprintf(fptr,"Id,Name,Price,Quantity\n");
	fseek(fptr,0,SEEK_END);
	int i,n;
	printf("Enter the number of items :-");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Item's name :-");
		scanf("%s",items[i].name);
		printf("Price of %s :-",items[i]);
		scanf("%d",&items[i].price);
		printf("Quantity of %s:-",items[i]);
		scanf("%d",&items[i].qty);
		printf("Enter Product ID of %s:-",items[i]);
		scanf("%d",&items[i].id);
	}
	for(i=0;i<n;i++)
	{	
		
		fprintf(fptr,"%d, %s, %d, %d\n",items[i].id,items[i].name,items[i].price,items[i].qty);
	}
	fclose(fptr);
	Display();		
}

void Display()
{
	system("libreoffice qty.csv");
}
