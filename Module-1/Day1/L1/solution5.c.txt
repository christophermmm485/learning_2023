#include <stdio.h>

int main()
{
   int num, oper_type;

   printf("Enter an integer (32 bits): ");
   scanf("%d", &num);

   printf("Enter the operation type (1, 2, or 3): ");
   scanf("%d", &oper_type);

   switch (oper_type)
   {
   case 1:
      num |= 1; // Set 1st bit
      break;
   case 2:
      num &= ~(1 << 31); // Clear 31st bit
      break;
   case 3:
      num ^= (1 << 15); // Toggle 16th bit
      break;
   default:
      printf("Error: Invalid operation type.\n");
      return 1;
   }

   printf("Result: %d\n", num);

   return 0;
}