/*
    NAME-Saurav ROLL-1601CS41 DATE-21st march 2017
    The aim of the program is to implement a singely linked list and sort it using its height and weight
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//defining the strucure of the node
typedef struct node {
    char roll[10];
    int ht;
    int wt;
    
    struct node *nextht;
    struct node *nextwt;
    };

//some global variables to be used
struct node *headwt,*headht,*prev=NULL;
int counter=0;

//function to insert a node into the linked list
void insert_node(struct node *x , char temp_roll[],int tht, int twt){
    
    //for the first element i.e. the head
	if(prev==NULL){
		headht=x;
		strcpy(headht->roll,temp_roll);
		headht->ht=tht;
		headht->wt=twt;
		headht->nextht=NULL;
        headht->nextwt=NULL;
		prev=headht;

        headwt=x;
		strcpy(headwt->roll,temp_roll);
		headwt->ht=tht;
		headwt->wt=twt;
		headwt->nextht=NULL;
        headwt->nextwt=NULL;
		prev=headwt;
	}

    //for the rest of the elements	
	else{
		strcpy(x->roll,temp_roll);
		x->ht=tht;
		x->wt=twt;
		x->nextht=NULL;
        x->nextwt=NULL;
		prev->nextht=x;
        prev->nextwt=x;
		prev=x;
	}
}

//bubble sort in terms of height
void sort_ht(struct node *h){
    
    int num_nodes = counter;
    int count;

    //looping and pairwise swapping if necessary
    for (count = 0; count < num_nodes; count++) {
        struct node* current = headht;
        struct node* next = current->nextht;
        struct node* previous = NULL;

        while(next != NULL) {
           
            if (current->ht > next->ht) {
                if (current == headht){
                    headht = next;
                } else {
                    previous->nextht = next;
                }
                current->nextht = next->nextht;
                next->nextht = current; 

                previous = next;
                next = current->nextht;
            }
            else {
                previous = current;
                current = current->nextht;
                next = current->nextht;
            }
        }
    }
    
       

}
//bubble sort in terms of weight
void sort_wt(struct node *h){

    int num_nodes = counter;
    int count;

    for (count = 0; count < num_nodes; count++) {
        struct node* current = headwt;
        struct node* next = current->nextwt;
        struct node* previous = NULL;

        while(next != NULL) {
           
            if (current->wt > next->wt) {
                if (current == headwt){
                    headwt = next;
                } else {
                    previous->nextwt = next;
                }
                current->nextwt = next->nextwt;
                next->nextwt = current; 

                previous = next;
                next = current->nextwt;
            }
            else {
                previous = current;
                current = current->nextwt;
                next = current->nextwt;
            }
        }
    }
    
}

//to print the list in desired way
void printNameList(struct node *h , int option){
    
    //sorting using height
    if (option==0)
    {
        sort_ht(h);
        printf("Sorted using height:");
        struct node *ptr=headht;
        while (ptr !=NULL)
        {
            printf("%s  ",ptr->roll);
            ptr=ptr->nextht;
        }
        printf("\n");
    }

    //sorting using weight
    else
    {
        sort_wt(h);
        printf("Sorted using weight:");
        struct node *ptr=headwt;
        while (ptr !=NULL)
        {
            printf("%s  ",ptr->roll);
            ptr=ptr->nextwt;
        }
        printf("\n");
    }
}

int main(){

    //the number of elements
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);

    //temporary variables to store the data
    char temp_roll[10];
    int tht,twt;

    //looping n times and inserting the nodes
    int i;
    for ( i = 0; i < n; i++)
    {
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data:");
        scanf("%s %d %d",temp_roll,&tht,&twt);
        
        insert_node(temp,temp_roll,tht,twt);
        counter++;
         
    }

    //printing after sorting using ht
    printNameList(headht,0);
    
    //Printing after sorting using wt
    printNameList(headwt,1);
    return 0;
}

