#include <stdio.h>	//}
#include <stdlib.h>	//}
#include <dirent.h>	//}Bibiolteca de Manipulaçao de Diretorios

int main(){
	char d[10];
	DIR *p;			//Ponteiro para um diretorio
	struct dirent *d1;	//Ponteiro para uma estrutura de diretorios

	printf("Entre com um nome de um diretório:\n");
	scanf("%s",d);
	p = opendir(d);		//abre o diretorio digitado pelo usuario e guarda no ponteiro

	if( p==NULL ){		//se o diretorio não existe retorna um erro
		perror("Diretório não encontrado");
		exit(-1);
	}

	while( d1 = readdir(p) )	//varre todos os diretorios de dentro do diretorio digitado pelo usuario
	printf("%s\n",d1->d_name);	//imprime o nome dos diretorios
}

