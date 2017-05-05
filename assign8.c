//Name-Saurav Roll-1601cs41
//The aim of the program is to implement a singly linked list and do print, swap and reverse operations on it

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//the main node
struct node{

	char roll[6];
	float cpi;
	float attendance;
	struct node *next;
	

};

//head to store the head of the list and prev to store the value of the previous pointer to the current pointer
struct node *head,*prev=NULL;

//counter to count the number of elements in the list..will be used in reversing
int counter=1;

//to insert a new node in the linked list
void insert_node(struct node *x, char temproll[],float tempcpi,float tempattendance){

//for the first element i.e. the head
	if(prev==NULL){
		head=x;
		strcpy(head->roll,temproll);
		head->cpi=tempcpi;
		head->attendance=tempattendance;
		head->next=NULL;
		prev=head;
	}

//for the rest of the element	
	else{
		strcpy(x->roll,temproll);
		x->cpi=tempcpi;
		x->attendance=tempattendance;
		x->next=NULL;
		prev->next=x;
		prev=x;
	}
}
//To print the list of elements
void print_list(){
	
	struct node *ptr;
	ptr=head;
	while(ptr!=NULL){
		printf("<%s",ptr->roll);
		printf(",%.2f,%.2f> ",ptr->cpi,ptr->attendance);	
		ptr=ptr->next;
	}

}

//to swap the elements
void swap_elements(char roll1[],char roll2[]){
	
	
	//p1 and p2 are needed to store the data of the node which are to be swapped
	struct node *p1;
	struct node *p2;	

	
	struct node *ptr;
	ptr=head;
	
	//finding the node which has the roll as roll1
	while(strcmp(ptr->roll,roll1)!=0){
		ptr=ptr->next;	
	}	
	
	//p1 store the node with roll as roll1
	p1=ptr;
	ptr=head;

	//finding the node which has the roll as roll2
	while(strcmp(ptr->roll,roll2)!=0){
		ptr=ptr->next;
	}	
	//p2 stores the node with roll as roll2

	p2=ptr;
	
	//using temporary variable to swap the contents
	char temproll[6];
	float tempcpi;
	float tempattend;
	

	strcpy(temproll,roll1);
	tempcpi=p1->cpi;
	tempattend=p1->attendance;
	

	strcpy(p1->roll,p2->roll);
	p1->cpi=p2->cpi;
	p1->attendance=p2->attendance;
	
	strcpy(p2->roll,temproll);
	p2->cpi=tempcpi;
	p2->attendance=tempattend;
	
	
}

//function that returns the node pointing to the element at the position given....will use it for reversing
struct node *find_pointer(int position){
	struct node *p=head;
	while(position--){
		p=p->next;
	}
	return p;
}

//function to reverse the list
void reverse(){
	
	//if the number of elements is even...then number of swap operations is counter/2
	if((counter%2)==0){
		int pos1=1;
		int pos2=counter;
		int times=counter/2;
		while((times--)!=0){
			struct node *p1=find_pointer(pos1-1);
			struct node *p2=find_pointer(pos2-1);
			pos1++;
			pos2--;
			char temp1[6],temp2[6];
			strcpy(temp1,p1->roll);
			strcpy(temp2,p2->roll);

			swap_elements(temp1,temp2);
			}						
		}		
	
	//if the number of elements in the list is odd...then number of swap operations is (counter-1)/2
	else{
		int pos1=1;
		int pos2=counter;
		int times=(counter-1)/2;
		while((times--)!=0){

			struct node *p1=find_pointer(pos1-1);
			struct node *p2=find_pointer(pos2-1);
			pos1++;
			pos2--;
			
			char temp1[6],temp2[6];
			strcpy(temp1,p1->roll);
			strcpy(temp2,p2->roll);

			swap_elements(temp1,temp2);
		}	
	}
		
}		



int main(){
		
	char temproll[6];
	float tempcpi;
	float tempattendance;
		
	//variable to ask whether to add more elements in the list
	char addMore;

	//getting the input
	do{
		struct node *x;		
		x=(struct node*)malloc(sizeof(struct node));		
				
		printf("Enter elements of the node\n");		
		
		printf("Enter the roll=");
		scanf("%s",temproll);
		
		printf("Enter the cpi=");
		scanf("%f",&tempcpi);
		
		printf("Enter the attendance:");
		scanf("%f",&tempattendance);
		

		insert_node(x,temproll,tempcpi,tempattendance);
		if(counter==1){
		head=x;
		}
		
		printf("Any more node(y/n):");
		scanf(" %c",&addMore);
		if (addMore=='y')
		{
			++counter;	
		}
		
	}while(addMore=='y');
	
	//getting the instruction whether to print,swap or reverse or end
	int instruction;
	printf("Enter 1 for print , 2 for swap , 3 for reverse and 0 for exit:");
	scanf("%d",&instruction);
	
	if(instruction==1){
		printf("The list of Elements present in the list is\n");
		print_list();
	}
	
	//to swap
	else if(instruction==2){
		char roll1[5],roll2[5];
		printf("Enter the roll of first node(must be present in the list) to be swapped:");
		scanf("%s",roll1);
		printf("Enter the roll of the second node(must be present in the list) to be swapped:");
		scanf("%s",roll2);		
	
		swap_elements(roll1,roll2);	
		printf("The list after the swapping is:");
		print_list();
	}		
	//to reverse
	else if(instruction==3){
		reverse();
		printf("The elements after reversing the list are:\n");	
		print_list();	
	}
	//to end the program
	else{
		
		printf("Program ends\n");	
	}
return 0;
}

