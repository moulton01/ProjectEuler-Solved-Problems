#include <iostream>
#include <vector>
#include <math.h>

using namespace std; 

int SumOfMultiplesOfThreeAndFive();
int SumOfEvenFibonacci(); 
bool isPrime(long num);
long long largestPrimeFactor(long long num);

int main(){

	bool exit = false; 
	long long numToCheck = 600851475143;
	int input; 
	do{
	cout << "1. Problem One: Sum of multiples of 3 and 5?\n2.Even Fibonacci Numbers?\n3. Largest Prime Factor?\n";
	cin >> input; 

		switch (input){
		case 1:
			cout << "The sum of all numbers up to a thousand that are either a multiple of three or five are: " << SumOfMultiplesOfThreeAndFive() << endl;
			break;
		case 2:
			cout << "The sum of all even fibonacci numbers with a value less than 4 million are : " << SumOfEvenFibonacci() << endl; 
			break;
		case 3:
			cout << "The largest prime factor of " << numToCheck << " is: " << largestPrimeFactor(numToCheck) << endl;
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
long long largestPrimeFactor(long long num)
{
	//Revised version. 
	//First version was brute force, checking all numbers below the max that % 0.
	//I then checked whether the numbers were prime. Repeated this until max factor found. 
	long long newNum = num; 
	long long largestFact = 0; 

	int counter = 2; 
	while (counter * counter <= newNum)
	{
		if (newNum % counter == 0)
		{
			newNum = newNum / counter; 
			largestFact = counter; 
		}
		else {
			counter++; 
		}
	}
	if (newNum > largestFact)
	{
		largestFact = newNum;
	}
	return largestFact;
}
