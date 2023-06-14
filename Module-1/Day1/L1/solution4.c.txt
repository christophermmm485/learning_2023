#include<stdio.h>
int calculator(int,char,int);
int main()
{
    int operand1,operand2;
    char operator;
    printf("Enter the number1:");
    scanf("%d",&operand1);
    printf("Enter the operator:");
    scanf("%s",&operator);
    printf("Enter the number2:");
    scanf("%d",&operand2);
    calculator(operand1,operator,operand2);
}
int calculator(int operand1,char operator,int operand2)
{
    switch(operator)
    {
    case '+':
    printf("\nAddition:%d",(operand1+operand2));
    break;
    case '-':
    printf("\nsubtraction:%d",(operand1-operand2));
    break;
    case '*':
    printf("\nMultiplication:%d",(operand1*operand2));
    break;
    case '/':
    printf("\nDivision:%d",(operand1/operand2));
    break;
    case '%':
    printf("\nModulo:%d",(operand1%operand2));
    break;
    default:
    printf("\nInvalid option");
    
}
}