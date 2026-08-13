#include<stdio.h>
//循环基础：1~100求和
int main(){
    int sum=0;
    for(int i=1;i<=100;i++){
        sum+=i;
    }
    printf("1到100累加和%d\n",sum);
    return 0;
}
