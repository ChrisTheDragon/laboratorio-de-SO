#include <stdio.h>	//}
#include <fcntl.h>	//}inclusão de bibliotecas
#include <string.h>	//}
#include <unistd.h>	//}inclusão da biblioteca de manipulação de arquivo
#include <stdlib.h>	//}inclusão da biblioteca de manibulação de ponteiro


int main(){
	char *buff, fn[10];	//ponteiros de char
	int fd, n, i;

	buff = malloc(100);	//aloca memoria de 100 bytes para a variavel buf

	printf("Entre com o nome de um arquivo novo:\n");
	scanf("%s",fn);
	printf("\nEntre com um texto qualquer:");
	scanf("%s",buff);

	//fgets(buff,100,stdin);
	fd = open(fn,O_CREAT|O_WRONLY);	//apre o arquivo, se não existir, cria, com o nome definido pelo usuario
	n = write(fd,buff,strlen(buff));//escreve no arquivo o que tem na variavel buff
	close(fd);			//fecha o arquivo

	printf("\n\nVeja o conteúdo do arquivo criado\n");
	free(buff);		//libera a memoria
}
