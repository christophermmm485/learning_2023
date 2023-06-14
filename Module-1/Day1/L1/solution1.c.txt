#include<stdio.h>
int biggestifelse(int,int);
int biggestternary(int,int);
int main(){
    int a,b;
    printf("Enter the two numbers");
    scanf("%d%d",&a,&b);
    biggestifelse(a,b);
    biggestternary(a,b);
    return 0;

}
int biggestifelse(int a,int b)
{
 if(a>b)
 {
    printf("\n The biggest number is %d using ifelse",a);
 }
 else
 {
    printf("\n The biggest number is %d using ifelse",b);
 }
}
 int biggestternary(int a, int b)
{
    int max;
    max=(a>b)?a:b;
    printf("\n The biggest number is %d using ternary operator",max);
}


