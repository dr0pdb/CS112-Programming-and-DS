//Saurav 1601CS41
//the objective is to encrypt a given number and print it and also decrypt a number and print it



#include<stdio.h>


int main(void){


int number;
printf("Enter the four digit number to be encrypted:");
scanf("%d",&number);



int ones,tens,thousands,hundreds;

//finding all the digits

ones=number%10;
number/=10;

tens=number%10;
number/=10;

hundreds=number%10;
number/=10;

thousands=number;

//processing all the digits

ones=(ones+7)%10;
tens=(tens+7)%10;
hundreds=(hundreds+7)%10;
thousands=(thousands+7)%10;

int temp;

//interchanging the numbers

temp=ones;
ones=hundreds;
hundreds=temp;

temp=tens;
tens=thousands;
thousands=temp;

//printing the reversednumber

int reversednumber;
if(thousands==0){
 reversednumber=100*hundreds+10*tens+ones;
printf("The encrypted number: 0%d\n",reversednumber);

}


else{
 reversednumber=thousands*1000+hundreds*100+tens*10+ones;
printf("The encrypted number: %d\n",reversednumber);
}
//now for printing the original number
printf("Enter the four digit number to be decrypted:");
scanf("%d",&reversednumber);

//getting the digits

ones=reversednumber%10;
reversednumber/=10;

tens=reversednumber%10;
reversednumber/=10;

hundreds=reversednumber%10;
reversednumber/=10;

thousands=reversednumber;

//interchanging the digits

temp=ones;
ones=hundreds;
hundreds=temp;

temp=tens;
tens=thousands;
thousands=temp;

//getting the original digits
//we can subtract 7 from digits and if it comes out to be negative then add 10 otherwise it will be the answer

ones-=7;
if(ones<0){
ones+=10;
}

tens-=7;
if(tens<0){
tens+=10;
}


thousands-=7;
if(thousands<0){
thousands+=10;
}

hundreds-=7;
if(hundreds<0){
hundreds+=10;
}

//getting the number

number=thousands*1000+hundreds*100+tens*10+ones;

//printing the actual number
printf("The decrypted number: %d",number);


return 0;
}
