#include <stdio.h>

unsigned long int fatorial(int num)
{
	unsigned long int fat;
	for(fat = 1; num > 1; num = num - 1){
		fat = fat * num;
		printf("fat = %lu\n", fat);
 	}
	return fat;
}

int main()
{
	int n;

	printf("Digite um numero menor que 20: ");
	scanf("%d", &n);

	if (n < 20){
		printf("\nFatorial = %lu\n", fatorial(n));
	} else {
		printf("numero inválido\n");
	}

	return 0;
}
