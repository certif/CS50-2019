#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    
     do {

	   n = get_int("Height: ");

        } 
    while (n < 1 || n > 8);
    
    for (int i = 1; i < n + 1; i++)
      {
              for (int j = n; j > i; j--)
          {         
                printf(" ");
          }
               for (int z = 0; z < i ; z++)
          {         
                printf("#");
          } 
               for (int p = 0; p < 2; p++)
          {
                printf(" ");   
          }
               for (int zz = 0; zz < i; zz++)
          {
                printf("#");    
          }         
      printf("\n"); 
        }
}
