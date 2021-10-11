#include <stdio.h>
int main(){
  int five_digit_num = 0;
  int Ans = 0;

  scanf("%d", &five_digit_num);

  for(int i=0; i<5; i++, five_digit_num /= 10)
  {
      Ans += five_digit_num % 10;
  }
  printf("%d",Ans);

  return 0;
}
