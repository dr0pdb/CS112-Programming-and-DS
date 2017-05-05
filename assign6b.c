//Name-Saurav Roll-1601CS41 Date-14th Feb,2017
//the aim of the program is to print all the unique combinations of numbers in a range(zero to max over allowed) which sum a target number(total overs).

#include <stdio.h>
#include <math.h>

//prototyping the other functions
int check_unique(int array[],int no_bowlers, int I);
void combinations (int total_overs, int max_allowed, int no_bowlers);

//the main function
int main()
{	
	
    //getting the input
    int total_overs,max_allowed,no_bowlers;

    printf("\n Total overs:");
    scanf("%d", &total_overs);

    printf("Maximum number of overs for one bowler:");
    scanf("%d", &max_allowed);

    printf( "Number of bowlers:");
    scanf("%d",&no_bowlers);

    printf("All possible ways for Mayank are");

    //calling the function to combine
    combinations(total_overs,max_allowed,no_bowlers);

    return 0;
}

//function to check whether it is unique.
//return 1 if it is unique otherwise zero
//basically it check that the combination is in decreasing order
//for example out of (4,3,1)(4,1,3)(3,1,4)(3,4,1)(1,3,4)(1,4,3) ,it chooses (4,3,1) and returns zero for rest of the combinations 

int check_unique(int array[],int no_bowlers, int original_number)
{ 

    //some temporary variables
    int i,j,temp ;
    int number=0;
    
    //multiplier to get the sum as a number
    float multiplier = 1.0;

    //sorting the array in descending order
    for (i=0; i<no_bowlers; i++)
    {
	for (j= i +1; j < no_bowlers; j++)
	{
	    if( array[i]< array[j])
	    {
	        temp= array[i];
	        array[i]= array[j];
	        array[j]=temp;
	    }
	}
    }

    //it finds the sum of the array elements as a number(example, if the sorted array is 4,3,1  then the value of number is 431)
    for(i=no_bowlers-1; i>=0;i--)
    {
	number= number + array[i]*multiplier;
	
		multiplier=multiplier*10;

    }
    //if the value of the number is equal to original number then it hasn't been used yet
    if (number== original_number){
	return 1;
	}

    else{
	return 0;
	}
    
}

//function to find all possible combinations
void combinations (int total_overs, int max_allowed, int no_bowlers)
{	
	
    int array[no_bowlers], sum=0;
    int addition, i,j,temp;
    float multiplier =1.0;

	//this will return the value of the sum of the array as a number with all the digits equal to the max over allowed(for eg if max over allowed is 4, and number bowlers is 5, sum will be 44444)
    for(i=0; i<no_bowlers; i++)
    {
	sum = sum + max_allowed*multiplier;
	
	multiplier=multiplier*10;    
    }

	//loop from sum and check for each whether it can be the possible combination or not
    for (i=sum ; i>=0; i--)
    {
	temp=i;
	addition=0;
	
	//getting the digits of i and storing each digit in an array
	for(j=0;j<no_bowlers; j++)
	{
	    array[j]=temp %10;
	    temp= temp/10;
	//addition variable stores the sum of the digits 
	    addition= addition + array[j];
	}
	
	//if the value of the addition variable is equal to total overs and it is unique then we will print it
	if(addition==total_overs && check_unique(array,no_bowlers,i)==1)
	{
	    printf("\n\n");

	    for( j=0; j<no_bowlers; j++)
	    {
	        printf("%d", array[j]);
	    }
	}

    }
    printf("\n");
}

