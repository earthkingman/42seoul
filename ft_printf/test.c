#include <stdio.h>

int main()
{
    // printf("hello %0*d %2s %%", 5, 1, "world");
    // printf("%*.*d\n",10,10,7);
    // printf("%.d\n",7);
    // printf("%.3d\n",7);
    //printf("%025.10s\n","stsrsrs");
    // printf("%5.d\n",7);
    // printf("%-5.d\n",7);
    // printf("%-5d\n",7);
    // printf("%4d\n",-30);
    // printf("|%-5.1d|\n",123);
    // printf("%.5d\n",10);
    printf("|%-5.2s|\n","123");
    printf("|%-5.1s|\n","123");
    printf("|%-0.1s|\n","123");
    printf("|%0.1s|","123");
    // printf("%010.9s\n","ssss sss"); //인자길이 , 너비 , 정확도 3개중에 가장큰것을 !
    // printf("%025.3s\n","stsrsrs");
    // printf("%-03.*d\n",2,100000); //->  printf("%-15.*d\n",10,7); //->
    // printf("%+-015.*d 안녕하세요 %10d\n",10 ,7 ,10); // ->쓰레기같은 경우 
    return(0);
} 

