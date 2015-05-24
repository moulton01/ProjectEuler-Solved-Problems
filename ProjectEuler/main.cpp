#include <iostream>

using namespace std; 

int SumOfMultiplesOfThreeAndFive();
int SumOfEvenFibonacci(); 

int main(){

	bool exit = false; 
	int input; 
	do{
	cout << "1. Problem One: Sum of multiples of 3 and 5?\n2.Even Fibonacci Numbers?\n";
	cin >> input; 

		switch (input){
		case 1:
			cout << "The sum of all numbers up to a thousand that are either a multiple of three or five are: " << SumOfMultiplesOfThreeAndFive() << endl;
			break;
		case 2:
			cout << "The sum of all even fibonacci numbers with a value less than 4 million are : " << SumOfEvenFibonacci() << endl; 
			break;
		default:
			cout << "invalid input";
			break; 

		}
	} while (!exit);

	system("pause");
}
int SumOfMultiplesOfThreeAndFive()
{
	int SumOfMultiples = 0; 
	for(int i = 1; i < 1000; i++)
	{
		if (i % 3 == 0)
		{
			SumOfMultiples += i; 
		}
		else if (i % 5 == 0)
		{
			SumOfMultiples += i; 
		}
	}
	return SumOfMultiples; 

}
int SumOfEvenFibonacci()
{
	bool valueExceedsLimit = false;
	int termOne = 1, termTwo = 2, sum = 2;
	int temp;
	
	do
	{
		temp = termOne + termTwo; 

		if (temp < 4000000)
		{
			termOne = termTwo;
			termTwo = temp;
		}
		else
			valueExceedsLimit = true; 

		if (temp % 2 == 0)
		{
			sum += temp; 
		}

	} while (temp < 4000000);
	return sum; 
}