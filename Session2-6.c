#include<stdio.h>
int main(){
  const float PI = 3.14;
  int ban_kinh = 6;
  printf("Ban kinh hinh tron la %d\n", ban_kinh);
  float chu_vi = Pi * ban_kinh * 2;
  printf("Chu vi hinh tron la %.2f\n", chu_vi);
  float dien_tich = PI*(ban_kinh*ban_kinh);
  printf("Dien tich hinh tron la %.2f", dien_tich);
  return 0;
}
