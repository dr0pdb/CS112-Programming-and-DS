//Saurav 1601cs41
//the purpose of the code is to calculate the bmi of the person using the height and weight and also categorise on the basis of bmi


#include<stdio.h>


int main(void){
float weight;
float height;
float answer;


printf("Please enter your weight and height (separated by comma): ");
scanf("%f,%f",&weight,&height);

//calculate bmi and save it in variable answer
answer=weight/((height)*(height));

// categorise into various categories
if(answer<18.5){

	printf("Your BMI is: %.1f and you are Underweight.",answer);


	}

else if(answer>18.5 && answer<24.9){
	printf("Your BMI is: %.1f and you are Normal.",answer);

}

else if(answer>25 && answer<29.9){

	printf("Your BMI is: %.1f and you are Overweight.",answer);

}

else if(answer>=30){

	printf("Your BMI is: %.1f and you are Obese.",answer);


}


return 0;
}
