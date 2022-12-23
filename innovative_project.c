#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//   Building a Node
struct Node
{
    int ID;
    int quantity;
    double pp; //   Product price
    char pName[100];
    struct Node *next;
} * head = NULL; 

//   Declarations of functions
int search(int);
int display();
int back();
int check(int);
int value = 0;

//   For entering 1st record in list
void beg()
{
    system("cls");
    int id, quant;  //  id and quant variable for Identification code and quantity respectively
    char name[100]; // char array for storing
    double price;   //  price variable for price
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter product ID:-");
    scanf("%d", &id);
    t->ID = id;
    printf("Enter product Name:-");
    scanf("%s", name);
    for (int i = 0; i < 100; i++)
    {
        t->pName[i] = name[i];
    }
    printf("Enter product price:-");
    scanf("%lf", &price);
    t->pp = price;
    printf("Enter product quantity:-");
    scanf("%d", &quant);
    t->quantity = quant;
    t->next = head;
    head = t;
    system("cls");
    printf("This product is Inserted!\n\n\n");
}

// for entering1 2nd records onwards in list
void end()
{
    system("cls");
    int id, quant; //   quant for quantity
    char name[100];
    double price; //  price for price
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    printf("Enter product ID:-");
    scanf("%d", &id);
    t->ID = id;
    printf("Enter product Name:-");
    scanf("%s", name);
    for (int i = 0; i < 100; i++)
    {
        t->pName[i] = name[i];
    }
    printf("Enter product price:-");
    scanf("%lf", &price);
    t->pp = price;
    printf("Enter product quantity:-");
    scanf("%d", &quant);
    t->quantity = quant;
    while (p->next)
    {
        p = p->next;
    }
    p->next = t;
    t->next = NULL;
    system("cls");
    printf("\n\nThis product is Inserted!\n\n");
}

int check(int quant)
{ //  Check function
    int a = quant;
    if (quant <= 0)
        return 0;
    else
        return quant;
}

void delPro()
{
    system("cls");
    display();
    int id;
    struct Node *cur = head;
    struct Node *price = head;
    printf("\n\nEnter ID to delete that product:\n\n");
    scanf("%d", &id);
    if (head == NULL)
    {
        system("cls");
        printf("List is empty\n");
    }
    int pos = 0;
    int count = display(); //   For load no. of nodes
    pos = search(id);      //   For checking whether the required node is present or not
    if (pos <= count)
    {
        while (cur->ID != id)
        { //  For deleting middle nodes
            price = cur;
            cur = cur->next;
        }
        price->next = cur->next;
        system("cls");
        printf("\nItem is deleted\n");
    }
    else
    {
        printf("\nItem not found\n\n");
    }
}

void modify()
{
    int id;
    double price;
    char pName[100]; //   For new product name
    if (head == NULL)
    {
        system("cls");
        printf("List is empty\n");
    }
    else
    {
        printf("\n\nEnter ID to modify product Name and its price:\n");
        scanf("%d", &id);
        struct Node *cur = head;
        int pos = 0;
        int count = display(); // For load no. of nodes
        pos = search(id);      // For checking whether the required node is present or not
        if (pos <= count)
        {

            while (cur->ID != id)
            {
                cur = cur->next;
            }
            printf("\nOld Name : ");
            printf("%s", cur->pName);
            printf("\nOld Price : ");
            printf("%lf\n", cur->pp);
            printf("Enter new Name: ");
            scanf("%s", pName);
            for (int i = 0; i < 100; i++)
            {
                cur->pName[i] = pName[i];
            }
            printf("Enter new Price:");
            scanf("%lf", &price);
            cur->pp = price;
        }
        else
        {
            printf("%d is not there\n\n", id);
        }
    }
}

int display()
{
    system("cls");
    int c = 0; //   c variable for counting the no. of products
    struct Node *p = head;
    printf("Existing products are :\n");
    printf("ID\t\tProduct Name\t\tPrice\t\tQuantity\n");
    while (p)
    {
        printf("%d\t\t%s\t\t\t%lf\t", p->ID, p->pName, p->pp); //  Calling check function and passing product quantity
        if (check(p->quantity) <= 0)
            printf("OUT OF STOCK!\n");
        else
            printf("%d\n", check(p->quantity));
        p = p->next;
        c++;
    }
    printf("\nTotal products in our mini mall is : %d\n\n\n", c);
    return c;
}

int search(int id) //  For searching the item in the list
{
    int count = 1;
    struct Node *p = head;
    while (p)
    {
        if (p->ID == id)
            break;
        else
            count++;
        p = p->next;
    }
    return count;
}

void buy()
{
    system("cls");
    int pay = 0, no, price, id, i = 1;
    if (head == NULL)
    {
        printf("\nThere are no items to buy\n\n");
    }
    else
    {
        printf("How many items you want to buy!\n");
        scanf("%d", &no);
        int count = display(); //  FOr storing no. of nodes in c
        while (i <= no)
        {
            struct Node *cur = head;

            int quant; //   quant variable for quantity
            printf("Enter id of item that you want to buy : ");
            int id, pos = 0;
            scanf("%d", &id);
            pos = search(id);
            if (pos <= count)
            {
                //   Item is available in mini mall
                while (cur->ID != id)
                {
                    cur = cur->next;
                }
                printf("How many quantities you want : ");
                scanf("%d", &quant);
                pay = pay + (cur->pp * quant);         //    For calculating bill
                cur->quantity = cur->quantity - quant; //   For changing the qauntity
                i++;
                printf("\n\nYou have bought : ");
                printf("%s\n", cur->pName);
            }
            else
            {
                printf("\nThis item is not available at the moment. We are very sorry for the inconvinience caused :( \n\n");
            }
        }
    }
    price = pay * (0.90); //    with 10% discount
    printf("\n\nTOTAL BILL AMOUNT : %d\n", pay);
    printf("\nFINAL AMOUNT :   %d\n\nThank you for the shopping at our mall :) !! Please visit again ^_^  \n\n", price);
}

int back()
{
    int no, i = 1, give = 0;
    printf("How many items you want to return!\n");
    scanf("%d", &no);
    int count = display();
    while (i <= no)
    {
        struct Node *cur = head;
        int quant, cho; //   quant variable for quantity and cho variable for choice
        printf("Enter the id of product you want to return");
        int id, pos = 0;
        scanf("%d", &id);
        pos = search(id);
        if (pos <= count)
        {
            //   Item is available in mini mall
            while (cur->ID != id)
            {
                cur = cur->next;
            }
            printf("\n\nHow many quantities you want to return\n\n");
            scanf("%d", &quant);
            give = give + (cur->pp * quant); //  Calculating the Bill
            cur->quantity = cur->quantity + quant;
            i++;
        }
    }
    printf("\n\nYou will get %d rs back", give);
}

//   Main function
int main()
{
    int flag, flag1;
    printf("\n\n***************  MALL MANAGEMENT SYSTEM  ***************\n\n\n");
    int temp = 1;
    while (1)
    {
        int cm;
        flag = 1;
        flag1 = 1;
        printf("OPTION 1 : Manager portal \n\nOPTION 2 : Customer portal\n\nPRESS 0 for exit\n\n");
        printf("Option - ");
        scanf("%d", &cm);
        switch (cm)
        {
        case 1:
            while (flag)
            {
                int ch; //  Choice
                printf("OPTION 1 : ADD a new product \n\nOPTION 2 : Display all products \n\nOPTION 3 : Modify Existing product\n\n");
                printf("OPTION 4 : Delete a particular product item\n\nPRESS 0 for exit\n\n");
                printf("SELECT YOUR OPTION : ");
                scanf("%d", &ch);
                switch (ch)
                {
                case 1:
                    if (temp == 0)
                    { //    Second time and onwards this is only executed
                        end();
                    }
                    if (temp == 1)
                    {
                        value++; //  this will be executed only one time
                        beg();
                        temp = 0;
                    }
                    break;
                case 2:
                    system("cls");
                    display();
                    break;
                case 3:
                    modify();
                    break;
                case 4:
                    delPro();
                    break;
                case 0:
                    printf(" \nExiting...\n");
                    flag = 0; //   Exit from while loop
                    break;
                default:
                    system("cls");
                    printf("Invalid Choice\n\n");
                    break;
                }
            }
            break;
        case 2:
            while (flag1)
            {
                int cd;
                printf("\n\nEnter 1 To buy something\nEnter 2 to return something\nEnter 0 for exit\n\n");
                printf("OPTION - ");
                scanf("%d", &cd);
                switch (cd)
                {
                case 1:
                    buy();
                    break;
                case 2:
                    back();
                    break;
                case 0:
                    printf("\nExiting...\n");
                    flag1 = 0; //   Exit from while loop
                    break;
                default:
                    system("cls");
                    printf("Invalid Choice\n");
                    break;
                }
            }
            break;
        case 0:
            printf("\nExiting...\n");
            exit(1); //   Exit from while loop
            break;
        default:
            system("cls");
            printf("Invalid Choice\n");
            break;
        }
    }
}
