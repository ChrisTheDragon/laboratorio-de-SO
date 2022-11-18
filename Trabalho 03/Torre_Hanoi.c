#include <stdio.h>
#include <stdlib.h>

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
    int numDiscos;
    scanf("%d", &numDiscos);
    hanoi(numDiscos, 'A', 'B', 'C');
return 0;
}
