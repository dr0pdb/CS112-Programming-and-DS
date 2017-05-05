//Name-Saurav Roll-1601CS41 Date-28th Feb,2017
//the aim is to input an array, make a copy of the array in reverse order and then shuffle its content such that the order of positive and negative numbers are same
//but the positive numbes are in front followed by the negative numbers


#include<stdio.h>

int main(){
	
	int no_elements;
	printf("Enter n:");
	scanf("%d",&no_elements);
	
	//arrays to store data
	int a[200];
	int b[200];
	int i=0;
	for(i=0;i<200;i++){
		a[i]=-1000000;
		b[i]=-1000000;
	}
	
	//to store the number of positive and negative numbers
	int no_pos=0,no_neg=0,no_zeroes=0;	
	
	printf("Enter Elements: ");
	
	for(i=0;i<no_elements;i++){
		scanf(" %d",&a[i]);
		if(a[i]>0){
		no_pos++;		
		}
		if(a[i]<0){
		no_neg++;		
		}
		else if(a[i]==0){
		no_zeroes++;		
		}
	}
	
	//printing the first array
	printf("Elements of array a[]=");
	for(i=0;i<no_elements;i++){
		if(i==0){
		printf("{");		
		}
		if(i !=no_elements-1){
		printf("%d,",a[i]);
		}
		
		if(i==no_elements-1){
		printf("%d}\n",a[i]);		
		}	
	}	
	
	//assigning the values to array b in reverse order
	for(i=no_elements-1;i>=0;i--){
		b[i]=a[no_elements-1-i];	
	}				
	
	//printing the array b
	printf("Elements of array b[]=");
	for(i=0;i<no_elements;i++){
		if(i==0){
		printf("{");		
		}
		if(i !=no_elements-1){
		printf("%d,",b[i]);
		}
		
		if(i==no_elements-1){
		printf("%d}\n",b[i]);		
		}	
	}	
	
	//if the element is less than zero, then push it to the back of the array
	int temp,count=199;
	for(i=0;i<no_elements;i++){
		if(b[i]<0){
			temp=b[i];
			b[i]=-1000000;
			b[count]=temp;
			count--;		
		}
	}

	//loop through zero to all the positive numbers and -1000000 and bring all the positive numbers in front 	
	count=0;
	for(i=0;i<200-no_neg;i++){
		if(b[i]==-1000000){
			continue;		
		}			
		else{
			temp=b[i];
			b[i]=-1000000;
			b[count]=temp;
			count++;		
			}			
	}
	count=199;
	//bring all the negative numbers back and add it after index i
	i=no_pos+no_zeroes;
	for(;i<no_elements;i++){
		b[i]=b[count];
		b[count]=0;
		count--;	
	}
	
	//printing the final value
	printf("After the task b[]={");
	for(i=0;i<no_elements;i++){
		if(i <no_elements-1){
		printf("%d,",b[i]);
		}
		else{
		printf("%d}",b[i]);		
		}
			
	}			
return 0;	
}
