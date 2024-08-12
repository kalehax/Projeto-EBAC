#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca de strings
		
		int registrar() // criação de variáveis 
		{
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		
		printf("Digite o CPF que deseja cadastrar: "); // pedindo informação ao usuário
		scanf("%s", cpf); //leitura de strings
		
		strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
		
		FILE *file;
		file = fopen(arquivo, "w"); // Comando responsável por criar o arquivo. "w" comando referente a 'write'
		fprintf(file,cpf); //Comando para salvar o valor da variável
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
		printf("O CPF digitado não foi localizado no sistema. \n");
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
		printf("Usuário não encontrado no sistema.");
		system("pause");
		fclose(file);
		}
			
		else if(file != NULL)
		{
		fclose(file);
		printf("Usuário deletado com sucesso! \n");
		system("pause");
		remove (cpf);
		}			
			
		}	
		int main()
		{
		int opcao=0; //Definindo as variáveis
		int laco=1;
	
		for (laco=1;laco=1;)
		{
		system("cls"); //limpar a tela 
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		system("cls");
	
		printf("HHH Cartório da EBAC ###\n\n"); //Início do menu
	
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1 - Registrar nome\n");
		printf("\t2 - Consultar nome\n");
		printf("\t3 - Deletar nome\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenamento das escolhas do usuário
		
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
		printf("Até logo!");
		return 0;
		break;
		
		default:
		printf("Por favor, digite uma opção entre 1 a 3\n");
		system("pause");
		break;
		
			
		}
		
 
		}
		}
