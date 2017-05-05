// Saurav 1601CS41
// the aim is to calculate the busfare when given its basefare and no of seats remaining

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float baseprice;
    int seatsremaining;
    float busfare;

    //getting the input

	printf("Enter the base fare: ");
	scanf("%f",&baseprice);

	printf("Enter the remaining seats: ");
	scanf("%d",&seatsremaining);

	//processing the input

	float percentsold=(700.0-seatsremaining)/7.0;

	if (percentsold<10.0)
	{
		busfare=baseprice;
	}
	else if (percentsold>=10 && percentsold<20)
	{
		busfare=(1.1)*baseprice;
	}

	else if (percentsold>=20 && percentsold<30)
	{
		busfare=(1.2)*baseprice;
	}
	else if (percentsold>=30 && percentsold<40)
	{
		busfare=(1.3)*baseprice;
	}
	else if (percentsold>=40 && percentsold<50)
	{
		busfare=(1.4)*baseprice;
	}

	else
	{
		busfare=(1.5)*baseprice;
	}


	//printing the result

	printf("Your ticket price is: %.2f",busfare);
    return 0;
}
