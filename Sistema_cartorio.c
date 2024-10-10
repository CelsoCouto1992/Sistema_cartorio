#include <stdio.h>//biblioteca de comunicação com usuário
#include <stdlib.h>//biblioteca de alocação de memoria
#include <locale.h>//biblioteca de alocações de texto por região (sistema vai intender Gramática portuguesa)
#include <string.h>//biblioteca para strings
int registro()//função responsável por cadastrar os usuários no sistema
{
	//inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis
	
	printf("Digite o CPF: ");//coletando informação do usuário
	scanf("%s", cpf);// %s se refere a string
	
	strcpy(arquivo, cpf);//responsavel por copiar os valores da string
	
	FILE *file;//cria o arquivo no banco de dados
	file = fopen(arquivo, "w");//cria o arquivo "w"
	fprintf(file, cpf);//salvo o valor da variável
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
		printf("Não foi localizado o arquivo.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	system("cls");
	
	
	
}
int deletar()
{
	char cpf[40];
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema\n");
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
		
		printf("## Cartório da Cidade ##\n\n");//inicio do menu
		
		
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do Sistema\n\n");
		
		scanf("%d", &opcao);//armazenando a escolha do usuário
		
		system("cls"); //responsável por limpar a tela
		
		switch(opcao)
		{
			case 1:
			registro();// chamada de funções
			break;
				
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema\n");
			return 0;
			break;
								
			default:
			printf("Essa opção não está disponível\n");
			system("pause");
			break;
			
			system("cls");
					
		}		
	}
}
