#include <stdio.h>

char c; //Stores the Value given from Standard Input
int X; //Stores the Last Value from the Stack
char temp;
int STACK[15]; //Stack that stores the 16 input Values
char buffer[15];
int i = 0; //controlvariable, controls the while loop for input
int j = 0;
int k = 0;
int sum = 0;

int main()
{
  while(1) //endless loop which takes input as long as 0x03(EOF) apears
  {
    c = getchar();
    if(c == EOF) //break out the while loop if 0x03(EOF) appears
    {
      break;
    }
    else          //Input as expected
    {
      if(c == 0x0A)
      {
        if(buffer[j] != 0x2B)
        {
          X = 0;
          do {
            if(k > 0)
              X = X * 10;
            X = X + buffer[k] - 0x30;
            k++;
            j--;
          } while(j > 0);

          k = 0;
          STACK[i] = X;
          printf("%d\n", STACK[i]);
          i++;

          if(i > 15)
          break;
        }
      }
      else if(c == 0x2B)
      {
        buffer[j] = 0x2B;
        i--;
        printf(" X I,IST %d %d\n", X, i);
        sum = STACK[i-1] + X;
        STACK[i-1] = sum;
        X = STACK[i-1];
        STACK[i] = 0;

        printf("Stack %d\n",STACK[i-1]);
      }
      else
      {
        buffer[j] = c;
        j++;
      }
    }
  }
  int v;
  for(v = 0; v <16; v++)
  {
    printf("Final %d : %d\n",v, STACK[v]);
  }
  return(0);
}
