/*
	Name-Saurav Roll-1601CS41 Date-4th April,2017
	The aim of the program is to create a BST and print its elements as well as the maximum and minimum leaf elements
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *leftChild; //points to left child
	struct node *rightChild; //points to right child
	struct node *parent; //points to parent
};

//this will be used to store the data and the level for the max leaf and min leaf
//index 0 for the minimum and 1 for the maximum
int levels[2]={99999,0};
int datas[2]={99999,0};



//head stores the head of the tree and prev will be used to store the parent of the current node while traversing the tree 
struct node *head=NULL,*prev=NULL;

//function to recursively print the parents
void printParent(struct node *node,int lev){
	
	//check if it is null
	if(node !=NULL){
		if(node->parent == NULL){
			printf("%d	No Parent\n",node->data);
		}
		else{
			printf("%d	%d\n",node->data,(node->parent)->data);	
		}

		//checks if it is a leaf
		if(node->leftChild==NULL && node->rightChild==NULL){
			//for finding the max leaf element
			if(lev>=levels[1]){
				if(datas[1]<node->data){
					datas[1]=(node->data);
					levels[1]=lev;
				}
			}
			//for finding the min leaf element
			if(lev<=levels[0]){
				//if the level is lesser than levels[0] then it is automatically the min leaf so far
				if(lev<levels[0]){
					datas[0]=(node->data);
					levels[0]=lev;
				}

				//among the elements with same level we have to compare which is the smaller				
				else{
					if(datas[0]>(node->data)){
					datas[0]=(node->data);
					levels[0]=lev;
					}

				}		
			}		
		
		}		
		
		//recursively call the left and right child
		printParent(node->leftChild,lev+1);
		printParent(node->rightChild,lev+1);
	}	
		
}


//adds a new node and return its pointer
struct node *addNewNode(int d){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data=d;

	//It has been set to null so that we can identify this as a leaf
	temp->leftChild=NULL;
	temp->rightChild=NULL;
	temp->parent=prev;

	return temp;
}


struct node *insert(struct node *temp, int data){
	
	//once we reach a leaf we can insert our new node
	if(temp==NULL){
		return addNewNode(data);
	}
		
	//otherwise keep traversing recursively untill we find a leaf
		
	//insert on the left side
	if(data <= temp->data){
		prev=temp;
		temp->leftChild = insert(temp->leftChild,data);
		
	}

	//insert on the right side
	else{
		prev=temp;
		temp->rightChild = insert(temp->rightChild,data);
	}

	return temp;
	
}


int main(){
	
	//getting the number of elements
	int n;
	printf("n:");
	scanf("%d",&n);
	
	//getting the input
	int i,d;
	for(i=0;i<n;i++){
		scanf("%d",&d);
		if(i==0){
			head=insert(head,d);
			head->parent=NULL;
		}
		else{
			insert(head,d);
		}
	}
	
	//printing the table
	printf("Node	Parent\n");
	printParent(head,0);
	
	//printing the min and max leaf	
	printf("Largest leaf from maximum level: element %d level %d\n",datas[1],levels[1]);		
	printf("Smallest leaf from the minimum level: element %d level %d\n",datas[0],levels[0]);		
return 0;
}
