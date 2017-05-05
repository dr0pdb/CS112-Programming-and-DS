//Name-Saurav Roll-1601cs41 Date-7th feb 2017
// the aim of the code is to define the seating arrangement of people based on their unique id and also print number of males and females with their arrangement
//we also have to print number of people wearing red and blue with their arrangement and at last we have to add another id and print the new seating arrangement

#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){

//array to store ids
int id[15]={0};

//getting the input
int noguests=0;
printf("Enter the unique ids of the guests: ");
int i;

//index of all the types initialised to zero 
int males[15]={0};
int females[15]={0};
int red[15]={0};
int blue[15]={0};

//to store the number of each type
int nomales=0;
int nofemales=0;
int redones=0;
int blueones=0;

//getting the input
for(i=0;i<15;i++){
	scanf("%d,",&id[i]);
	
	//the user has to enter the number 0 in order to end the input or else it will only end after 15 entries
	if(id[i]==0){
		break;	
	}
		
	else{
		
		noguests++;

		if(id[i]<0){
		males[nomales]=id[i];
		nomales++;	
		}

		if(id[i]>0){
			females[nofemales]=id[i];
			nofemales++;	
		}
		
		
			
	}
	
}

printf("\n");

//variables to use in loop or as a temporary variable for sorting
int j,a;    

//sorting the array in descending order except the ids that are zero(as zero is not a valid id)
for (i = 0; i < noguests; ++i)
{
	for (j = i + 1; j < noguests; ++j)
	{
            if (id[i] < id[j])
            {
                a =  id[i];
                id[i] = id[j];
                id[j] = a;
            }
        }
}

//getting the blue and red ones positions

for(i=0;i<noguests;i++){
	if(id[i]%2==0){
		red[redones]=i+1;
		redones++;	
	}
	else{
		blue[blueones]=i+1;
		blueones++;	
	}
}

//getting the required id to search
int reqid;
printf("Enter the id to be searched: ");
scanf("%d",&reqid);

//to store index of the id searched
int answerindex=-1;

for(i=0;i<noguests;i++){
	if(reqid==id[i]){
		answerindex=i;
		break;
	}	
}


printf("\n");

//copy of the id array to edit for the new guest
int copyid[15]={0};


int newnoguests=0;
if(noguests<15){
	
	//to store the id of the new guest
	int newguestid;
	newnoguests=noguests+1;

	
	//creating a copy of the array to edit for the new guest
	for(i=0;i<noguests;i++){
		copyid[i]=id[i];
	}

	printf("Enter the unique id of the new guest:");
	scanf("%d",&newguestid);
	copyid[noguests]=newguestid;

	//sorting the new formed array again
	for (i = 0; i < newnoguests; ++i)
	{
		for (j = i + 1; j < newnoguests; ++j)
		{
   		
			 if (copyid[i] < copyid[j])
	            	{
	      			  a =  copyid[i];
				copyid[i] = copyid[j];
	        		copyid[j] = a;
		        }
	        }
	}
	
	
}

//printing the output arrangement

printf("The seating arrangement is: \n");
for(i=0;i<noguests;i++){
	printf("%d ",id[i]);
	
	if(i%5==4){
	printf("\n");	
	}	
	
}

printf("\n");

//we have to check whether that person is present in the party or not
if(answerindex!=-1){
printf("The guest with id %d is present in the party and is seated at position %d.\n",reqid,answerindex+1);
}

else{
printf("The guest with id %d is not present in the party\n",reqid);	
}
printf("There are %d males and %d females.\n",nomales,nofemales);
printf("The male guest id's are:");

//sorting the male array

for (i = 0; i < nomales; ++i)
	{
		for (j = i + 1; j < nomales; ++j)
		{
   		
			 if (males[i] < males[j])
	            	{
	      			  a =  males[i];
				males[i] = males[j];
	        		males[j] = a;
		        }
	        }
	}
	
//printing the male array
for(i=0;i<nomales;i++){
	printf("%d ",males[i]);
}

printf("\nThe female guest ids are:");

//sorting the female array

for (i = 0; i < nofemales; ++i)
	{
		for (j = i + 1; j < nofemales; ++j)
		{
   		
			 if (females[i] < females[j])
	            	{
	      			  a =  females[i];
				females[i] = females[j];
	        		females[j] = a;
		        }
	        }
	}


//printing the female array

for(i=0;i<nofemales;i++){
	printf("%d ",females[i]);
}



//printing the red and blue


printf("\nThere are %d guests in red and %d guests in blue dress respectively.\n",redones,blueones);

//printing the red array
printf("The seating positions of the guests in red dress are:");

//sorting the red array to find their position 

for (i = 0; i < redones; ++i)
	{
		for (j = i + 1; j < redones; ++j)
		{
   		
			 if (red[i] > red[j])
	            	{
	      			  a =  red[i];
				red[i] = red[j];
	        		red[j] = a;
		        }
	        }
	}
	

for(i=0;i<redones;i++){
	printf("%d ",red[i]);
}


//printing the blue array
printf("\nThe seating positions of the guests in blue dress are:");

//sorting the blue array to find their position

for (i = 0; i < blueones; ++i)
	{
		for (j = i + 1; j < blueones; ++j)
		{
   		
			 if (blue[i] > blue[j])
	            	{
	      			  a =  blue[i];
				blue[i] = blue[j];
	        		blue[j] = a;
		        }
	        }
	}


for(i=0;i<blueones;i++){
	printf("%d ",blue[i]);
}

//printing the new seating arrangement
if(newnoguests-noguests==1){

	printf("\nThe new seating arrangement is:\n");

	for(i=0;i<newnoguests;i++){
		printf("%d ",copyid[i]);
	
		if(i%5==4){
		printf("\n");	
		}	
	
	}
}

return 0;
}
