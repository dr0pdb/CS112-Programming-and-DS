/*
	Name-Saurav Roll-1601CS41 Date-11thApril 2017
	The aim of the program is to construct a binary search from its given post order and inorder traversals.
	The approach is to find the last element of the post array(which will be the root) and find its position in the inorder traversal array.
	Now its left and right child will be in the left and right part of the inorder array respectively. Use these steps recursively.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Declaration of the Node
struct node{
	char data;
	struct node *leftChild;
	struct node *rightChild;
};
//making the root of the binary tree a global variable.
struct node *root;

//function to find the index of the element in an array, Will be used to find the position of the root node in the inOrder array and then recursively for further nodes.
int searchIndex(char array[], int start, int end, int data){
		int i,position;
		for(i=start;i<=end;i++){
			if(array[i]==data){
				position=i;
				break;
			}
		}
		return position;
}

//function to insert a new node
struct node *insert(char data){
	struct node *element = (struct node *)malloc(sizeof(struct node));
	element->data=data;
	element->leftChild=NULL;
	element->rightChild=NULL;
	
	return element;	
}


struct node *Build(char inOrder[], char postOrder[],int inOrderStart, int inOrderend, int *postIndex){
	
	//base case for the recursion, it simply means that all the nodes have been added.
	if(inOrderStart>inOrderend){
		return NULL;
	}
	
	//inserting a new node
	struct node *element = insert(postOrder[*postIndex]);
	
	//Now that the element has been inserted we first decrement the index of postarray
	(*postIndex)--;
	
	//now we find the index of the node just inserted in the inorder array
	int inindex= searchIndex(inOrder,inOrderStart, inOrderend, element->data);
	
	/*
		Recursively building the Tree
		Right child has been built first because in the postOrder right child comes later than the left child and we are starting from the back in the postOrder 			array using the postIndex, we need to first build the right child.
	*/
	element->rightChild=Build(inOrder, postOrder, inindex+1 ,inOrderend,postIndex);
	element->leftChild=Build(inOrder,postOrder,inOrderStart,inindex-1,postIndex);
	
	return element;
}

//Builder function for the tree. Wrapper Function.
struct node *BuildTree(char inOrder[], char postOrder[], int size){
	int postIndex=size-1;
	return Build(inOrder,postOrder,0,size-1,&postIndex);//passing postindex's address so that we can modify it in the Build function and use recursively.
}


//Function to print the preOrder sequence of the tree traversal
void printPre(struct node *current){
		if(current != NULL){
			printf("%c ",current->data);
			printPre(current->leftChild);
			printPre(current->rightChild);
		}
		else{
			return;
		}	
	}

int main(){
	
	//opening the file
	FILE *fptr;
	fptr=fopen("ipseq.txt","r");

	//if the file is empty return with an error
	if (fptr==NULL){
		printf("Please check the File");
		return 1;
	}
	
	char string[1000];
	
	//getting the inorder line from the file
	fgets(string,sizeof string,fptr); 
	
	//variables to loop and store the size of the string 
	int i,size=strlen(string);

	
	size/=2;
	//the inorder traversal array
	char in[size];
	
	int j=0;
	for(i=0;i<size;i++){
		//saving the contents of the string array in the in array.  Note that alternate spaces are blank in the string array so j+=2
		in[i]=string[j];
		j+=2;
	}
	
	//similarly getting the postorder line from the file
	fgets(string,sizeof string,fptr);
	
	size=strlen(string);
	size/=2;
	char post[size];
	
	j=0;
	for(i=0;i<size;i++){
		post[i]=string[j];
		j+=2;
	}
	//closing the file after operation
	fclose(fptr);
 	
 	//buuilding the tree
    root= BuildTree(in,post,size);
    
    //printing the pre-order sequence of the tree 
    printf("Pre Order Sequence of the Tree: ");
    printPre(root);
	
return 0;
}
