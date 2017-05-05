#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	
	struct node *prev;
	int data;
	struct node *next;

};

int convert_to_int(char arr[],int initialindex,int finalindex){
	int i;
	int result=0;
	for(i=initialindex;i<=finalindex;i++){
		result=(result*10)+(arr[i]-'0');
	}
	return result;		
}

	int firstnegative=0,secondnegative=0;
	int no_nodes1,no_nodes2;
	struct node *head1=NULL,*head2=NULL;



int main(){
	char operation;
	printf("Comparison (c) or Addition (a) or Subtraction (s)or Exit (x):");
	scanf("%c",&operation);
	
	char firstnumber[1000];
	printf("Enter first number\n");
	scanf("%s",firstnumber);

	char secondnumber[1000];
	printf("Enter second number\n");
	scanf("%s",secondnumber);
	
	
	int index1=0,index2=0;
	int l1=strlen(firstnumber),l2=strlen(secondnumber);	

	if(firstnumber[0]=='-'){
		firstnegative=1;
		index1=1;
		l1--;
	}
	if(secondnumber[0]== '-'){
		secondnegative=1;
		index2=1;
		l2--;
	}

	int no_nodes1=l1/5,no_nodes2=l2/5;
	if(l1%5 !=0){
		no_nodes1++;
	}
	if(l2%5 !=0){
		no_nodes2++;
	}	


	int i;
	//will store the previous node while creating the list
	struct node *temp1=NULL;
	int nextindex1=index1+4;	

	if(l1%5 !=0){
		nextindex1=(l1)%5-1;	
	}

	//creating the first list
	for(i=1;i<=no_nodes1;i++){
	
		struct node *temp = (struct node *)malloc(sizeof(struct node));		
			
		if(i==1){
			head1=temp;
			temp->prev= NULL;
			temp->data=no_nodes1 -1;
			temp->next=NULL;
			temp1=temp;
		}
		else if(i==2){
			temp1->next=temp;
			temp->prev=head1;
			temp->next=NULL;
			temp->data=convert_to_int(firstnumber,index1,nextindex1);
			index1=nextindex1+1;
			nextindex1+=5;
			temp1=temp;
		}
		else if(i !=no_nodes1 ){
			temp1->next=temp;
			temp->prev=temp1;
			temp->data=convert_to_int(firstnumber,index1,nextindex1);
			temp->next=NULL;
			index1=nextindex1+1;
			nextindex1+=5;
			temp1=temp;	
		}
		else{
			temp1->next=temp;
			temp->prev=temp1;
			temp->data=convert_to_int(firstnumber,index1,nextindex1);
			temp->next=head1;
			head1->prev=temp;
		}	
	}

	//printing the list
	struct node *ptr= head1;
	do{
		printf("%d\n",ptr->data);
		ptr=ptr->prev;
	}while(ptr != head1);
	
	
return 0;
}
