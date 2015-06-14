#include <iostream>
#include <vector>
#include <math.h>

using namespace std; 

int SumOfMultiplesOfThreeAndFive();
int SumOfEvenFibonacci(); 
bool isPrime(long num);
long long largestPrimeFactor(long long num);
bool IsPalindromic(int sum, vector<int> reverseArray, vector<int> normalArray);
int calculateNumberOfDigits(int number);
void largestPalidromicNumber(); 

int main(){

	bool exit = false; 
	long long numToCheck = 600851475143;
	int input; 
	do{
	cout << "1.Problem One: Sum of multiples of 3 and 5?\n2.Even Fibonacci Numbers?\n3.Largest Prime Factor?\n4.Largest Palidromic Number, from the product of two 3 digit numbers?\n";
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
		case 4: 
			cout << "The largest Palidromic Number, made from the product of 3 digit numbers is: ";
			largestPalidromicNumber(); cout << "\n"; 
		default:
			cout << "invalid input\n";
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
void largestPalidromicNumber()
{
	vector<int> arrayToReverse;
	vector<int> normalArray;

	int largestPalindrome = 0, temp;

	for (int i = 100; i < 1000; i++)
	{
		for (int j = 100; j < 1000; j++)
		{
			temp = i * j;
			if (IsPalindromic(temp, arrayToReverse, normalArray))
			{
				if (temp > largestPalindrome)
				{
					largestPalindrome = temp;
				}
			}
		}
	}
	cout << largestPalindrome << endl;
	arrayToReverse.clear(); 
	normalArray.clear(); 
}
bool IsPalindromic(int sum, vector<int> reverseArray, vector<int> normalArray)
{
	int temp = sum;
	int OriginalNum = sum;


	for (int div = pow(10, calculateNumberOfDigits(OriginalNum) - 1); div > 0; div /= 10)
	{
		int calc = (temp / div) % 10;
		reverseArray.insert(reverseArray.begin(), calc);
		normalArray.push_back(calc);
	}
	for (int i = 0; i < normalArray.size(); i++)
	{
		if (normalArray[i] != reverseArray[i])
		{
			return false;
		}

	}
	return true;
}
int calculateNumberOfDigits(int number)
{
	int counter = 0;
	int tempInt = number;
	while (tempInt != 0)
	{
		tempInt = tempInt / 10;
		counter++;
	}
	return counter;
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
