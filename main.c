#include<stdlib.h>
#include<string.h>
#include<stdio.h>
struct Customer
{
    int CustomerID;
    char name[100];
    char phone[100];
    float payment;
    struct Customer *next;

}* head;
void insert(int CustomerID, char* name, char* phone, float payment)
{

    struct Customer * customer = (struct Customer *) malloc(sizeof(struct Customer));
    customer->CustomerID = CustomerID;
    strcpy(customer->name, name);
    strcpy(customer->phone, phone);
    customer->payment = payment;
    customer->next = NULL;

    if(head==NULL){
        // if head is NULL
        // set student as the new head
        head = customer;
    }
    else{
        // if list is not empty
        // insert student in beginning of head
        customer->next = head;
        head = customer;
    }

}
void search(int CustomerID)
{
    struct Customer * temp = head;
    while(temp!=NULL){
        if(temp->CustomerID==CustomerID){
            printf("Customer ID: %d\n", temp->CustomerID);
            printf("Name: %s\n", temp->name);
            printf("Phone: %s\n", temp->phone);
            printf("payment: %0.4f\n", temp->payment);
            return;
        }
        temp = temp->next;
    }
    printf("Student with roll number %d is not found !!!\n", CustomerID);
}
void update(int CustomerID)
{

    struct Customer * temp = head;
    while(temp!=NULL){

        if(temp->CustomerID==CustomerID){
            printf("Record with roll number %d Found !!!\n", CustomerID);
            printf("Enter new name: ");
            scanf("%s", temp->name);
            printf("Enter new phone number: ");
            scanf("%s", temp->phone);
            printf("Enter new payment: ");
            scanf("%f",&temp->payment);
            printf("Updation Successful!!!\n");
            return;
        }
        temp = temp->next;

    }
    printf("Student with roll number %d is not found !!!\n", CustomerID);

}
void Delete(int CustomerID)
{
    struct Customer * temp1 = head;
    struct Customer * temp2 = head;
    while(temp1!=NULL){

        if(temp1->CustomerID==CustomerID){

            printf("Record with roll number %d Found !!!\n", CustomerID);

            if(temp1==temp2){
                // this condition will run if
                // the record that we need to delete is the first node
                // of the linked list
                head = head->next;
                free(temp1);
            }
            else{
                // temp1 is the node we need to delete
                // temp2 is the node previous to temp1
                temp2->next = temp1->next;
                free(temp1);
            }

            printf("Record Successfully Deleted !!!\n");
            return;

        }
        temp2 = temp1;
        temp1 = temp1->next;

    }
    printf("Student with roll number %d is not found !!!\n", CustomerID);

}
void display()
{
    struct Customer * temp = head;
    while(temp!=NULL){

        printf("Customer ID: %d\n", temp->CustomerID);
        printf("Name: %s\n", temp->name);
        printf("Phone: %s\n", temp->phone);
        printf("payment: %0.4f\n\n", temp->payment);
        temp = temp->next;

    }
}
int main()
{
    head = NULL;
    int choice;
    char name[100];
    char phone[100];
    int CustomerID;
    float payment;
    printf("1 to insert Customer details\n2 to search for Customer details\n3 to delete Customer details\n4 to update Customer details\n5 to display all Customer details");
    do
    {
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter Customer ID: ");
                scanf("%d", &CustomerID);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                printf("Enter payment: ");
                scanf("%f", &payment);
                insert(CustomerID, name, phone, payment);
                break;
            case 2:
                printf("Enter Customer ID to search: ");
                scanf("%d", &CustomerID);
                search(CustomerID);
                break;
            case 3:
                printf("Enter CustomerID to delete: ");
                scanf("%d", &CustomerID);
                Delete(CustomerID);
                break;
            case 4:
                printf("Enter CustomerID to update: ");
                scanf("%d", &CustomerID);
                update(CustomerID);
                break;
            case 5:
                display();
                break;
        }

    } while (choice != 0);
}
