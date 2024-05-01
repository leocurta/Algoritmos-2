#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *p;
	char str[80],c;

	/* Le um nome para o arquivo a ser aberto: */
	printf("\n\n Entre com um nome para o arquivo:\n");
	gets(str);

	if (!(p = fopen(str,"w")))  /* Caso ocorra algum erro na abertura do arquivo..*/ 
  	{                           /* o programa aborta automaticamente */
  		printf("Erro! Impossivel abrir o arquivo!\n");
  		exit(1);
  	}
	/* Se nao houve erro, imprime no arquivo, fecha ...*/
	fprintf(p,"Este e um arquivo chamado:\n%s\n", str);
	fclose(p);

	/* abre novamente para a leitura  */
	p = fopen(str,"r");
	while (!feof(p))
 	{
  		fscanf(p,"%c",&c);
  		printf("%c",c);
  	} 
	fclose(p);
	return(0);
}