#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void fib(int num)
{
    float fib1 = 0, fib2 = 1, soma;
    int i;
    printf("fib[1] = 0\n");
    printf("fib[2] = 1\n");
    for (i = 3; i <= num; i = i + 1)
    {
        soma = fib1 + fib2;
        fib1 = fib2;
        fib2 = soma;
        printf("fib[%d] = %.0f\n", i, fib2);
    }
    printf("\n*** Processo FILHO finalizado ***\n");
    //return fib2;
}

void fat(int num)
{
	float fat;
    int cont = num;
	for(fat = 1; num > 1; num = num - 1){
		fat = fat * num;
		printf("%d! = %.0f\n", cont, fat);
 	}
    printf("\n*** Processo PAI finalizado ***\n");
	//return fat;
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
    pid_t pid_filho, pid_neto;

    pid_filho = fork();

    if (pid_filho == 0)
    {
        pid_neto = fork();

        if (pid_neto == 0)
        {
            hanoi(6, 'A', 'B', 'C');
            printf("\n*** Processo NETO finalizado ***\n");
        } else {
            fib(100);
        }
    } else {
        fat(19);
    }
    
    return 0;
}
