#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca de strings
		
		int registrar() // cria��o de vari�veis 
		{
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		
		printf("Digite o CPF que deseja cadastrar: "); // pedindo informa��o ao usu�rio
		scanf("%s", cpf); //leitura de strings
		
		strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
		
		FILE *file;
		file = fopen(arquivo, "w"); // Comando respons�vel por criar o arquivo. "w" comando referente a 'write'
		fprintf(file,cpf); //Comando para salvar o valor da vari�vel
		fclose(file); //Comando para fechar o arquivo
		
		file = fopen(arquivo, "a"); //abre o arquivo
		fprintf(file,","); //
		fclose(file);
		
		printf("Digite o nome que deseja cadastrar: ");
		scanf("%s",nome);
		
		file = fopen(arquivo, "a");
		fprintf(file,nome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o seu sobrenome: ");
		scanf("%s",sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		printf("Qual o seu cargo? ");
		scanf("%s",cargo);
			
		file = fopen(arquivo,"a");
		fprintf(file,cargo);
		fclose(file);
		
		system("pause");
		
		}
		
		int consultar()
		{
		setlocale(LC_ALL, "Portuguese");
		
		char cpf [40];
		char conteudo [200];
		
		printf("Digite o CPF que deseja consultar: ");
		scanf("%s",cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		
		if(file == NULL)
		{
		printf("O CPF digitado n�o foi localizado no sistema. \n");
		}
		
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\n Resultado da sua busca: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
		
		system("pause");
		fclose(file);
		}
		
		int deletar()
		{		
		char cpf [40];
			
		printf("Digite o CPF que deseja deletar: ");
		scanf("%s",cpf);
			
		
		FILE *file;
		file = fopen(cpf,"r");
					
		if(file == NULL)
		{
		printf("Usu�rio n�o encontrado no sistema.");
		system("pause");
		fclose(file);
		}
			
		else if(file != NULL)
		{
		fclose(file);
		printf("Usu�rio deletado com sucesso! \n");
		system("pause");
		remove (cpf);
		}			
			
		}	
		int main()
		{
		int opcao=0; //Definindo as vari�veis
		int laco=1;
	
		for (laco=1;laco=1;)
		{
		system("cls"); //limpar a tela 
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		system("cls");
	
		printf("HHH Cart�rio da EBAC ###\n\n"); //In�cio do menu
	
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t1 - Registrar nome\n");
		printf("\t2 - Consultar nome\n");
		printf("\t3 - Deletar nome\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenamento das escolhas do usu�rio
		
		system("cls");
	
		switch(opcao)
		{
		case 1:
		registrar();
		break;
		
		case 2: 
		consultar();
		break;
		
		case 3:
		deletar();
		break;
		
		case 4:
		printf("At� logo!");
		return 0;
		break;
		
		default:
		printf("Por favor, digite uma op��o entre 1 a 3\n");
		system("pause");
		break;
		
			
		}
		
 
		}
		}
