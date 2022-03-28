#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>


// structure to store the data
struct Product
{
    int id;
    char name[50];
    float price;
};


// Utility function which print the list of items in ascending order of their names
void printAscending(struct Product *p1,int n)
{
    char temp[50];
    int id;
    float price;

    // Buggle sort algorithm for sorting items according to their names
    for(int i=0;i<n;i++)
      for(int j=i+1;j<n;j++){
         if(strcmp(p1[i].name,p1[j].name)>0){
            strcpy(temp,p1[i].name);
            id=p1[i].id;
            price=p1[i].price;
            strcpy(p1[i].name,p1[j].name);
            p1[i].id=p1[j].id;
            p1[i].price=p1[j].price;
            strcpy(p1[j].name,temp);
            p1[j].id=id;
            p1[j].price=price;
         }
      }

    // printing list of items in ascending order
    printf("\nList of Product names in ascending order: \n");
    for(int i=0;i<n;i++)
    {
        printf("Name: %s\n",p1[i].name);
        printf("ID: %d\n",p1[i].id);
        printf("Price: %.2f\n",p1[i].price);
        printf("\n");
    }
}


// Utility function which print the product name along with heighest price
void highestProductPrice(struct Product *p1,int n)
{
    float price=0;
    char productName[50];
    for(int i=0;i<n;i++)
    {
        if(p1[i].price>price)
        {
            price=p1[i].price;
            strcpy(productName,p1[i].name);
        }
    }

    // print the product data
    printf("\nProduct which have highest price: \n");
    printf("Name: %s\n",productName);
    printf("Price: %.2f\n",price);
}

int main()
{
    printf("\nEnter number of products to add in list: ");
    // number of list items
    int n;
    scanf("%d",&n);

    // structure object to store list of items
    struct Product p1[n];
    printf("\nEnter Information about products: \n");
    // storing information
    for (int i = 0; i < n; i++)
    {
        int id;
        printf("\nEnter id of product: ");
        scanf("%d",&id);
        p1[i].id=id;
        printf("Enter product name: ");
        scanf("%s",p1[i].name);
        float price;
        printf("Enter price of product: ");
        scanf("%f",&p1[i].price);
    }


    // calling function to print names in ascending order
    printAscending(p1,n);  


    // calling function to print the highest price product             
    highestProductPrice(p1,n);
    
}