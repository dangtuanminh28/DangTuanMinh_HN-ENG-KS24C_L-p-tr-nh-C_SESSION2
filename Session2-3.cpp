#include<stdio.h>
int main(){
// khoi tao hai so nguyen
   int firstNumber = 5;
   int secondNumber = 10;
//  tinh tong va luu ket qua vao bien khac
   int firstTotal = firstNumber + secondNumber;
//  ket qua
   printf("tong cua firstnumber va secondnumber la: %d/n",firstTotal);
// tao them 3 bien  tich hieu thuong
	int secondTotal = firstNumber - secondNumber;
	printf(" hieu cua firstNumber va secondNumber la %d\n", secondTotal);
	int thirdTotal = firstNumber * secondNumber;
	printf(" tich cua firstNumber va secondNumber la %d\n", thirdTotal);	
	int fourthTotal = firstNumber / secondNumber;
	printf(" thuong cua firstNumber va secondNumber la %d\n", fourthTotal);	
	return 0;
}
