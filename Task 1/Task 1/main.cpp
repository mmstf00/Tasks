#include <iostream>
using namespace std;

class Arrays {

private:
	int element;
	float squareRoot[30], sum[30] = {};
	int n, number[30], num[30], max;

public:
	void sumSquareRootOfEvens();
	void theBiggestElement();
	void getData();
};

//Getting data for amount of elements and the array of numbers.
void Arrays::getData() {
	cout << "Write amount of elements: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "Element number " << i + 1 << endl;
		cin >> number[i];
	}
}

//Getting the square root of each element and sum of them.
void Arrays::sumSquareRootOfEvens() {


	for (int i = 0; i < n; i++)
	{
		num[i] = number[i]; //Saving the elements in new array to work with them.
	}

	for (int i = 0; i < n; i++) {
		while (num[i] > 0) {
			element = num[i] % 10;                //Getting the last digit of element.
			if (element % 2 == 0) {              //Check if its even.
				squareRoot[i] = sqrt(element);  //Finding the square root and saving the element in new array.
				sum[i] += squareRoot[i];       //Saving the summation of the square roots in new array.
			}
			num[i] = num[i] / 10;            //Deleting the last digit to move on the next.
		}
	}
	for (int i = 0; i < n; i++) {
		cout << "Sum and square root even digits in element " << i + 1 << " = " << sum[i] << endl;
	}
}

void Arrays::theBiggestElement() {

	max = number[0];
	for (int i = 1; i < n; i++) {
		if (number[i] > max) {
			max = number[i];
		}
	}
	cout << max;

}


int main() {

	Arrays A;

	A.getData();
	A.sumSquareRootOfEvens();
	cout << "The biggest element is: ";
	A.theBiggestElement();
	cout << endl;
}