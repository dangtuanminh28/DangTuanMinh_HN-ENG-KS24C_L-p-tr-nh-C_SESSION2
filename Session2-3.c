#include<stdio.h>
int main(){
// khoi tao hai so nguyen
   int firstNumber = 4;
   int secondNumber = 10;
//  tinh tong va luu ket qua vao bien khac
   int total = firstNumber + secondNumber;
//  ket qua
   printf("tong cua firstnumber va secondnumber la: %d\n",total);
// tao them 3 bien tich hieu thuong
	int minus = firstNumber - secondNumber;
	printf(" hieu cua firstNumber va secondNumber la %d\n", minus);
	int multy = firstNumber * secondNumber;
	printf(" tich cua firstNumber va secondNumber la %d\n", multy);	
	int divide = firstNumber / secondNumber;
	printf(" thuong cua firstNumber va secondNumber la %d\n", divide);	
	return 0;
}
