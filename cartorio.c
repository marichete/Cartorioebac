#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //bibliotece de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio cria��o de vari�veis/strings(conjunto de vari�veis)
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se ao armanezamento das string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo,"w"); //Cria o arquivo
	fprintf(file,cpf); //Salvo o valor da vari�vel
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

int consulta() //Fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//in�cio cria��o de vari�veis/strings(conjunto de vari�veis)
	char cpf[40];
	char conteudo[200];
	//final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser consultado: "); //coletando informa��o do usu�rio para a consulta no sistema
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // o "r" � de rodar o arquivo
	
	if(file == NULL) //Se for digitado algo que n�o foi cadastrado, informar a frase abaixo
	{
		printf ("N�o foi possivel abrir o arquivo, n�o localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar() //Fun��o respons�vel por deletar os usu�rios no sistema
{ 
	//in�cio cria��o de vari�vel/string (conjunto de vari�veis)
	char cpf[40];
	//final da cria��o da vari�vel/string
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	 
	remove(cpf); //Usado para remover a vari�vel (no caso o "cpf")
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //Se for digitado algo que n�o foi cadastrado ou que foi deletado, informar a frase abaixo
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}


}

int main()
{			
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;) //In�cio do la�o de repeti��o
	{
	
		system("cls"); //limpar a tela

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf ("### Cart�rio da EBAC ### \n\n"); //In�cio do menu
		printf ("Escolha a op��o desejada do menu:\n\n");
		printf ("\t1 - Registrar nomes\n");
		printf ("\t2 - Consultar nomes\n");
		printf ("\t3 - Deletar nomes\n\n");
		printf ("Op��o: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio 
	
		system("cls"); //respons�vel por limpar a tela
		
		switch(opcao) //In�cio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf ("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		} //Fim da sele��o
					
	} //Fim do la�o de repeti��o
}

