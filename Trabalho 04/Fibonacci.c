#include <stdio.h>

float fib(int n)
{
    float fib1 = 1, fib2 = 1, soma;
    int i;
    for (i = 3; i <= n; i = i + 1)
    {
        soma = fib1 + fib2;
        fib1 = fib2;
        fib2 = soma;
        printf("%d - fib = %f\n", i, fib2);
    }                                        
    return fib2;                             
}                                          
     
int main(void)
{
    printf("Fibonacci = %f\n", fib(100));
    return 0;
}
