/*
	Name-Saurav Roll-1601CS41
	The aim of the program is to create a linked list to represent a three variable polynomial and implement add operation on it.
*/

#include<stdio.h>
#include<stdlib.h>

//defining the node
struct _node{
	int powerx;
	int powery;
	int powerz;
	int coeff;
	struct _node *next;
};
typedef struct _node *NODEPTR;

//The main head of the linked list
NODEPTR MainHead=NULL;


//Function to insert a node at the beginning of the linked list
NODEPTR polyFirst(int nx, int ny, int nz, int ncoeff, NODEPTR head){
	NODEPTR temp= (NODEPTR)malloc(sizeof(struct _node));
	temp->next=head;
	head=temp;
	temp->powerx=nx;
	temp->powery=ny;
	temp->powerz=nz;
	temp->coeff=ncoeff;
	
	return head;
}

//function to swap two nodes of the list
void swap(NODEPTR n1, NODEPTR n2){
	
	//store data in temporary variable
	int tcof=n1->coeff;
	int tpx=n1->powerx;
	int tpy=n1->powery;
	int tpz=n1->powerz;
	
	//use temporary variable to swap
	n1->coeff=n2->coeff;
	n1->powerx=n2->powerx;
	n1->powery=n2->powery;
	n1->powerz=n2->powerz;
	
	n2->coeff=tcof;
	n2->powerx=tpx;
	n2->powery=tpy;
	n2->powerz=tpz;
}

//Function to sort the list in the desired order
void sortList(NODEPTR head){
	NODEPTR temp1=head;
	NODEPTR temp2=head->next;
	
	//sorting using the bubble sort technique
	while(temp1 !=NULL){
		
		//the sorting conditions
		if(temp1->powerx > temp2->powerx){
			swap(temp1,temp2);
		}else if((temp1->powerx == temp2->powerx) && (temp1->powery > temp2->powery)){
			swap(temp1,temp2);
		}else if((temp1->powerx == temp2->powerx) && (temp1->powery == temp2->powery) && (temp1->powerz > temp2->powerz)){
			swap(temp1,temp2);
		}
		
		temp2=temp2->next;
		if(temp2 == NULL){
			temp1=temp1->next;
			temp2=head;
		}	
	}
	
}



//function to print the list in the desired manner
void printList(NODEPTR head){
	
	//first sort the list in the required manner
	sortList(head);
	
	NODEPTR temp=head;
	while(temp !=NULL){
		
		//if coefficient is 0 then the term vanishes	
		if(temp->coeff !=0){
				
			//for the head we dont need a '+'sign before it	
			if(temp!=head){
			printf("+");
			}
			
			//if the coefficent is 1 then it's not necessary to write it
			if(temp->coeff !=1){
				printf("%d",temp->coeff);
			}
			
			if(temp->powerx !=0){
				printf("x^%d",temp->powerx);
			}
			if(temp->powery !=0){
				printf("y^%d",temp->powery);
			}
			if(temp->powerz !=0){
				printf("z^%d",temp->powerz);
			}
		}		
	
		temp=temp->next;
	}
	printf("\n");
}

//Function to add the two polynomials
NODEPTR addPoly(NODEPTR head1, NODEPTR head2){
	NODEPTR temp1= head1,temp2=head2;
	
	//we will first take a node of list1 and try to find the element with same powers in list2, if found we add their coefficients
	//if not found we insert it at the beginning of the list2
	int check=0;
	while(temp1 !=NULL){
		int c1=temp1->coeff,x1=temp1->powerx,y1=temp1->powery,z1=temp1->powerz;
		temp2=head2;
		check=0;
		while(temp2 !=NULL){
			
			int c2=temp2->coeff,x2=temp2->powerx,y2=temp2->powery,z2=temp2->powerz;
			
			if(x1==x2 && y1==y2 && z1==z2){
				temp2->coeff=(c1+c2);
				check=1;
				break;
			}
			
			temp2=temp2->next;
			
		}
		//if the same power term not found in the list2 then insert it at the front
		if(check==0){
				head2=polyFirst(x1,y1,z1,c1,head2);
			}
		temp1=temp1->next;
	}
	
	return head2;
}

//the main function to drive the program
int main(){
	printf("Options Create Polynomial (1), Display Polynomial (2), Add Polynomials(3), Exit (0)");
	int option;
    
    //loop as long as the user presses 0 i.e exit
    while(1){
    	printf("Enter Option:");
		scanf("%d",&option);
	
		//for creating a new polynomial
		if(option==1){
			char opt;
			do{
				int px,py,pz,coeff; 
				printf("Enter term: ");
				scanf("%d %d %d %d",&px,&py,&pz,&coeff);			
				MainHead=polyFirst(px,py,pz,coeff,MainHead);
				printf("Again(y/n): ");
				scanf(" %c",&opt);		
			}while(opt=='y');
		
		}
		
		//for printing the list
		else if(option==2){
			if(MainHead==NULL){
				printf("Create the list first\n");
			}
			printf("The Polynomial is:");
			printList(MainHead);
		}		
		
		// to add two polynomials
		else if(option==3){
			printf("First Polynomial\n");
			NODEPTR headFirst=NULL;
			
			//building the first polynomial
			char opt;
			do{
				int px,py,pz,coeff; 
				printf("Enter term: ");
				scanf("%d %d %d %d",&px,&py,&pz,&coeff);			
				headFirst=polyFirst(px,py,pz,coeff,headFirst);
				printf("Again(y/n): ");
				scanf(" %c",&opt);		
			}while(opt=='y');
			
			printf("The Polynomial is:");
			printList(headFirst);
			
			printf("Second Polynomial\n");
			NODEPTR headSecond=NULL;
			
			//building the second polynomial
			
			do{
				int px,py,pz,coeff; 
				printf("Enter term: ");
				scanf("%d %d %d %d",&px,&py,&pz,&coeff);			
				headSecond=polyFirst(px,py,pz,coeff,headSecond);
				printf("Again(y/n): ");
				scanf(" %c",&opt);		
			}while(opt=='y');
		
			printf("The Polynomial is:");
			printList(headSecond);
		
			printf("The polynomial after addition:");
			NODEPTR newHead=addPoly(headFirst,headSecond);
			sortList(newHead);
			printList(newHead);
		}
		else{
			printf("Exit\n");
			break;
		}
    	
    } 
    
	
	return 0;
}
