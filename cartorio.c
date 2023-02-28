#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //bibliotece de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//início criação de variáveis/strings(conjunto de variáveis)
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se ao armanezamento das string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo,"w"); //Cria o arquivo
	fprintf(file,cpf); //Salvo o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e atualiza
	fprintf(file,","); // inclui a virgula
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); 
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf ("Digite o sobrenome a ser cadastro: ");
	scanf("%s",sobrenome);

	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);

    file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf ("Digite o cargo a ser cadastro: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);

    system("pause");

}

int consulta() //Função responsável por consultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//início criação de variáveis/strings(conjunto de variáveis)
	char cpf[40];
	char conteudo[200];
	//final da criação de variáveis/strings
	
	printf("Digite o CPF a ser consultado: "); //coletando informação do usuário para a consulta no sistema
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // o "r" é de rodar o arquivo
	
	if(file == NULL) //Se for digitado algo que não foi cadastrado, informar a frase abaixo
	{
		printf ("Não foi possivel abrir o arquivo, não localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar() //Função responsável por deletar os usuários no sistema
{ 
	//início criação de variável/string (conjunto de variáveis)
	char cpf[40];
	//final da criação da variável/string
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	 
	remove(cpf); //Usado para remover a variável (no caso o "cpf")
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //Se for digitado algo que não foi cadastrado ou que foi deletado, informar a frase abaixo
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}


}

int main()
{			
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;) //Início do laço de repetição
	{
	
		system("cls"); //limpar a tela

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf ("### Cartório da EBAC ### \n\n"); //Início do menu
		printf ("Escolha a opção desejada do menu:\n\n");
		printf ("\t1 - Registrar nomes\n");
		printf ("\t2 - Consultar nomes\n");
		printf ("\t3 - Deletar nomes\n\n");
		printf ("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário 
	
		system("cls"); //responsável por limpar a tela
		
		switch(opcao) //Início da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf ("Essa opção não está disponível!\n");
			system("pause");
			break;
		} //Fim da seleção
					
	} //Fim do laço de repetição
}

