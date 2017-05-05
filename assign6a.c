//Name-Saurav Roll-1601CS41 date-14th feb 2017
//the aim is to find all the permutations of a string
#include <stdio.h>
#include <string.h>
 
//global variable to store the number of characters
int n;

//function to swap two characters
void swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//just to make sure we don't print comma after last word
int word_Count=0;

//function which permutes the string
//first parameter is that string,second is the starting index from where to permute the string and third one is the last index
void permute(char *a, int start, int end)
{	

//local variables to use in for loops etc.	
   int i,k;
   if (start == end){

	if(word_Count!=0){
	printf(",");	
	}
	for(k=0;k<=end;k++){
		printf("%c",a[k]);	
	}
	word_Count++;
}
     

   else
   {	
	//indicator whether the character to be permuted has already been repeated once
	//used in cases when duplicate characters are present
	//0 means it hasn't been used ,one means has been used
	int is_used[256]={0}; 
      for (i = start; i <= end; i++)
       {
	  if(is_used[*(a+i)-'A']==0){
		//swapping the two characters and permuting the remaining string	
       		   swap((a+start), (a+i));
		   permute(a, start+1, end);

		//backtracking step
                   swap((a+start), (a+i));
		//marking the character as used now
	           is_used[*(a+i)-'A']=1;
		} 
       }
   }
} 

int main()
{
    	//inputs
	printf("Number of letters: ");
	scanf("%d",&n);
	
	printf("Enter the letters: ");
	
	//place to store the string
	char str[n]; 
	int i=0;
	
	//temporary variable
	char temp;
	for(i=0;i<n-1;i++){
			
		scanf(" %c,",&temp);
		str[i]=temp;
	}
	scanf(" %c",&str[n-1]);
	
	//output
	printf("The possible words are: ");
	
	    permute(str, 0, n-1);
    return 0;
}
