#include<stdio.h>
int grade(int);
int main()
{
    int marks;
    printf("Enter the marks=");
    scanf("%d",&marks);
    grade(marks);
    return 0;

}
int grade(int marks)
{
    if(marks<0 || marks>100)
    {
        printf("Wrong Entry");
    }
    else if (marks>=90 && marks<=100)
    {
        printf("Grade A");
    }
    else if(marks>=89 && marks<=75)
    {
        printf("Grade B");
    }
    else if(marks>=74 && marks<=60)
    {
        printf("Grade C");
    }
    else if(marks>=59 && marks<=50)
    {
        printf("Grade D");
    }
    else
    {
        printf("Grade F");
    }
}