#include <stdio.h> //bilioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca responsavel por cuidar da string

int registro()// Fun�a� respons�vel por cadastrar os usu�rios
{
	// inicio cria��o de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final cria��o de variaveis/strings
	
	printf("Digite o cpf a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy (arquivo, cpf); // responsavel por copiar os valores da string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo,"w"); // cria o arquivo e o "w"significa escrever
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo	
	
	file = fopen(arquivo, "a");	
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	
	
	system("pause");
	
	
}

int consulta()
{
	setlocale(LC_ALL , "Portuguese"); //Definido a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Esse arquivo n�o est� registrado. N�o localizado!.\n");
	}
	
	while(fgets(conteudo,200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:\n ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove (cpf);
	
	FILE *file;
	file = fopen(cpf,"r");// "r" � usado para ler algo no arquivo
	
	if(file == NULL)
{
	printf("O usu�rio nao se encontra no sistema! \n");
	system("pause");
}
	
}

int main()
{
	
	int opcao=0; // defini��o de variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
        system("cls");
	    setlocale(LC_ALL , "Portuguese");
	
	    printf("~~~~ Registro de nomes dos alunos ~ EBAC ~~~~\n\n"); // inicio do menu
	    printf(" Escolha uma das op��es abaixo \n\n");
	    printf("\t1 - registrar nomes\n\t~\n");
	    printf("\t2 - consultar nomes\n\t~\n");
	    printf("\t3 - deletar nomes\n\t~\n\n");
	    printf("Op��o: "); // fim do menu
	
	    scanf("%d", &opcao); // armazenamento de escolha do usuario
	
	    system("cls"); // respons�vel por limbar a tela
	
	    switch(opcao)
	    {
		case 1:
		registro(); // chamada de fun��es
	    break;
	    
	    case 2:
		consulta();
		break; 
		
		case 3:
		deletar();
		break; 
		
		default:
		printf("Essa op��o nao est� disponivel!\n");
		system("pause");
		break;
	    } // fim da sele��o
    }
}

