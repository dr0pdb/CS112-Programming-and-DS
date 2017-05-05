//Name-Saurav Roll-1601CS41 Date-8th feb,2017
//the aim of the program is to find the number of students who can see the stage and find out the type of party

#include<stdio.h>
#include<math.h>
#include<string.h>

int main(void){

//getting the input
int nostudents;
printf("Enter the number of students participated:");
scanf("%d",&nostudents);

printf("\n");
printf("Enter their heights: ");

//array to store the height
int htarray[nostudents];

//variable to store the maximum of the height in the iteration and the final answer
int max=0,answer=0;

//getting the height
//only those people will be able to see the stage who have their height equal or greater than the value of the maximum height entered so far
int i;
for(i=0;i<nostudents;i++){
	
	scanf("%d",&htarray[i]);
	if(htarray[i]>=max){
		max=htarray[i];
		answer++;
	}
}

printf("\n");

//getting the colors
printf("Enter the color of robes denoted by integers: ");

//array to store colours
int colour[nostudents];

//indicator whether the party is allboys or not(if zero then boys else its girls)
int allboys=0;


for(i=0;i<nostudents;i++){
	scanf("%d",&colour[i]);
	
	int j;

	//checking from the previous entered colours whether the colour matches from any previously entered colour
	for(j=0;j<i;j++){
		if(colour[j]==colour[i]){
			//if their is any match then it will be a boys party			
			allboys=1;
			break;
		}
	}
}

//getting the output

printf("No. of students can see the stage: %d\n",answer);

//if allboys=0 then its a girls party
if(allboys==0){
	printf("It is a GIRLS party.");
	}
else{
	printf("It is a BOYS party.");
}
return 0;
}
