//Name-Saurav ROll-1601CS41
//The aim of the program is to dynamically allocate a string array and then sort it in dictionary format to print it

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	
	//no of strings
	int n;
	scanf("%d",&n);
	
	//array of pointers , one for each string
	char *array[100];
	
	//temp string to store the entered string	
	char temp[100];
	
	//some variables to be used for iteration or malloc
	int i,length;
	
	for(i=0;i<n;i++){
		scanf("%s",temp);
		
		//store the length  of the string
		length=strlen(temp)+1;
	
		//allocating the space for each string
		array[i]=(char*)malloc(sizeof(char)*length);
		
		//storing the string in the array
		strcpy(array[i],temp);		
	}
	
	int j;
	
	//sorting the array 	
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(strcmp(array[i],array[j])>0){
				strcpy(temp,array[i]);
				strcpy(array[i],array[j]);
				strcpy(array[j],temp);						
			}			
		}		
	}
	
	//printing the array
	for(i=0;i<n;i++){

		printf("%s\n",array[i]);	
	}
	
	//free the memory allocated
	free(*array);
return 0;
}
