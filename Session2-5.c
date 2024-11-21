#include<stdio.h>
int main(){
// Khai bao hai bien chieu dai va chieu rong
   int lengt = 10;
   printf("Chieu dai la %d cm\n",lengt);
   int width = 4;
   printf("Chieu rong la %d cm\n",width);
// Tinh chu vi va dien tich
    int Perimeter = 2 * (lengt+width);
    int Acreage = lengt * width;
// Xuat ket qua
    printf("Chu vi la %d\n",Perimeter);
    printf("Dien tich la %d",Acreage);
	return 0;
}
