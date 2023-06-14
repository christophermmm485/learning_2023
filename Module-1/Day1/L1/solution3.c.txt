#include<stdio.h>
int studentdetails();
int main()
{
studentdetails();
return 0;
}
int studentdetails()
{
    int rollno,mark1,mark2,mark3,total;
    float percent;
    char name[50];
    printf("Enter the rollno:");
    scanf("%d",&rollno);
    printf("\nEnter the name of the student:");
    scanf("%s",&name);
    printf("\nEnter the physics mark:");
    scanf("%d",&mark1);
    printf("\nEnter the math mark:");
    scanf("%d",&mark2);
    printf("\nEnter the chemistry mark:");
    scanf("%d",&mark3);
    total=mark1+mark2+mark3;
    percent=total/3.0;
    printf("\nThe roll no of the student:%d",rollno);
    printf("\nName of the student:%s",name);
    printf("\nPhysics mark:%d",mark1);
    printf("\nMath mark:%d",mark2);
    printf("\nChemistry mark:%d",mark3);
    printf("\nTotal marks:%d",total);
    printf("\nPercent:%0.4f",percent);

}