#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

float fib(int n)
{
    float fib1 = 1, fib2 = 1, soma;
    int i;
    for (i = 3; i <= n; i = i + 1)
    {
        soma = fib1 + fib2;
        fib1 = fib2;
        fib2 = soma;
        printf("%d - fib = %.0f\n", i, fib2);
    }                                        
    return fib2;                             
}

float fatorial(int num)
{
	float fat;
	for(fat = 1; num > 1; num = num - 1){
		fat = fat * num;
		printf("fat = %.0f\n", fat);
 	}
	return fat;
}

void hanoi(int n, char a, char b, char c)
{
    if (n == 0) return;
    if (n == 1)
        printf("mova disco %d de %c para %c\n", n, a, c);
    else
    {
        hanoi(n - 1, a, c, b);
        printf("mova disco %d de %c para %c\n", n, a, c);
        hanoi(n - 1, b, a, c);
    }
}
     
int main(void)
{
    pid_t pid;

    pid = fork();

    if (pid == 0){
        fatorial(19);
    } else {
        hanoi(6, 'A', 'B', 'C');
    }
    
    return 0;
}
