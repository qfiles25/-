#include<stdio.h>
int main(){
    int arr1[5]={1,2,3,4,5};//一维数组
    int *p1=arr;//数组名等价首元素指针
    //指针+循环遍历数组
    for(int i=0;i<5;i++){
        printf("%d ",*(p1+i));
    }
    printf("\n");
    int arr2[3][3]={1,2,3,4,5,6,7,8,9};//二维数组
    int (*p2)[3]=arr2;//数组指针
    for(int i=0;i<3;i++){
        printf("%d ",*(*(p2+i)+i));
    }
    return 0;
}
