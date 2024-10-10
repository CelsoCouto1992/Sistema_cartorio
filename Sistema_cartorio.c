#include <stdio.h>//biblioteca de comunica��o com usu�rio
#include <stdlib.h>//biblioteca de aloca��o de memoria
#include <locale.h>//biblioteca de aloca��es de texto por regi�o (sistema vai intender Gram�tica portuguesa)
#include <string.h>//biblioteca para strings
int registro()//fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis
	
	printf("Digite o CPF: ");//coletando informa��o do usu�rio
	scanf("%s", cpf);// %s se refere a string
	
	strcpy(arquivo, cpf);//responsavel por copiar os valores da string
	
	FILE *file;//cria o arquivo no banco de dados
	file = fopen(arquivo, "w");//cria o arquivo "w"
	fprintf(file, cpf);//salvo o valor da vari�vel
	fclose(file);//fechando o comando file
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite nome: ");
	scanf("%s", nome);
	file = fopen(arquivo, "a");//atualiza o arquivo "a"
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite sobrenome: ");
	scanf("%s", sobrenome);
	file = fopen(arquivo,"a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite cargo: ");
	scanf("%s", cargo);
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	
	system("pause");
	system("cls");
	
}

int consulta()
{
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consutado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");//para ler o arquivo "r"
	
	if(file == NULL)
	{
		printf("N�o foi localizado o arquivo.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	system("cls");
	
	
	
}
int deletar()
{
	char cpf[40];
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema\n");
		system("pause");
	}
	system("cls");
}
int main()
{
	
	int opcao = 0;//definindo as variaveis
	int laco=1;
	
	for(laco=1; laco<=10;)
	{
		setlocale(LC_ALL, "Portuguese");//definindo a liguagem
		
		printf("## Cart�rio da EBAC ##\n\n");//inicio do menu
		
		
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\n1-Registrar nomes\n");
		printf("\n2-Consultar nomes\n");
		printf("\n3-Deletar nomes\n\n");
		printf("Esse software � de livre uso dos alunos\n");
		
		scanf("%d", &opcao);//armazenando a escolha do usu�rio
		
		system("cls"); //respons�vel por limpar a tela
		
		switch(opcao)
		{
			case 1:
			registro();// chamada de fun��es
			break;
				
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
								
			default:
			printf("Essa op��o n�o est� dispon�vel\n");
			system("pause");
			break;
			
			system("cls");
					
		}		
	}
}
