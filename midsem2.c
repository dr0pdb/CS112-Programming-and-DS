//Name-Saurav Roll-1601CS41 Date-28th Feb,2017
//The objective of the program is to evaluate the value of a polynomial with the given degree and coefficients

#include<stdio.h>
#include<stdlib.h>

int main(){
	
	//Array to store the coefficients indexed at the degree(the coefficient of degree 0 will be at index 0 and so on...)
	//initialised to zero
	int coefficients[101]={0};
	
	//getting the input
	int number_terms;
	printf("Enter the number of terms: ");
	scanf("%d",&number_terms);
	printf("Enter the degree, coefficient pairs:\n");
	
	//some temporary variables to store data or for looping
	int i,temp1,temp2;	

	//temp1 will store the degree of the term and temp2 will store the coefficient
	for(i=0;i<number_terms;i++){
		scanf("%d,%d",&temp1,&temp2);
		coefficients[temp1]=temp2;
	}

	float x;
	printf("Enter x= ");
	scanf("%f",&x);
	
	int j;
	
	float answer=0,temp3;
	
	//first of all temp3 will store the value of x raised to the power i and then multiplied by the coefficient of it
	for(i=0;i<101;i++){
		temp3=1;
		//making temp x to the power i
		for(j=0;j<i;j++){
			temp3*=x;
		}
		//multiplying by its coefficient
		temp3*=coefficients[i];		
		//finally adding it to our answer variable... this will be done for all the degrees
		answer+=temp3;
	}
	//printing the output
	printf("The value of evaluated polynomial is %.6f",answer);
return 0;
}
