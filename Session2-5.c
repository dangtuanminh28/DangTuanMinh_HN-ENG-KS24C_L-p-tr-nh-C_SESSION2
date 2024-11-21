#include<stdio.h>
int main(){
// Khai bao hai bien chieu dai va chieu rong
   int lengt = 10;
   printf("Chieu dai la %d cm\n",lengt);
   int width = 4;
   printf("Chieu rong la %d cm\n",width);
// Tinh chu vi va dien tich
    int chu_vi = 2 * (lengt+width);
    int dien_tich = lengt * width;
// Xuat ket qua
    printf("Chu vi la %d\n",chu_vi);
    printf("Dien tich la %d",dien_tich);
	return 0;
}
