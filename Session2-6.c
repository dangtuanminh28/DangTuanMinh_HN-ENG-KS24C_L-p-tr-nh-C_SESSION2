#include<stdio.h>
int main(){
//khai bao bien PI float ban kinh
	const float Pi = 3.14;
	int ban_kinh  = 5;
	//tinh chu vi va dien tich hinh tron
	int Perimeter  = Pi * ban_kinh * 2;
	printf(" chu vi hinh tron la %d\n",Perimeter );
	int Acreage = Pi * ban_kinh * ban_kinh;
	printf(" dien tich hinh tron la %d\n",Acreage);
	return 0;
}
