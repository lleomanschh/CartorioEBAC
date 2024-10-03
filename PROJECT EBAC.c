#include <stdio.h> //bibliotea de comunicacao com o usuario
#include <stdlib.h> //bibliotea de aluca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca�oes de texto por regiao - brasil por ex
#include <string.h> // biblioteca responsael por cuidar das strings

int registro() // fun��o responsavel pelo cadastro de usuarios
{
	
	// cria��o de variaveis (String � a mesma coisa de conjunto de variavel [])
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];

    // final das strings

    printf("Digite o CPF a ser cadastrado: "); // coletar a informa��o o usuario
    scanf("%s", cpf); // %s refere-se a STRINGS
    
    strcpy(arquivo, cpf); // responsavel por copiar os valores das strings
    
    FILE *file; // falando pro sistema para procurar estrutura FILE e cria o arquivo file
    file = fopen(arquivo, "w"); // abre o arquivo de nome arquivo, por isso o w de write
    fprintf(file,cpf); // f pois esta salvando no file a variavel cpf
    fclose(file); // fecha o arquivo e salva 
    
    file = fopen(arquivo, "a"); // abriu o arquivo A pois quer atualizar a informa��o do arquivo
    fprintf(file, ","); // cria a virgula para separar o CPF do restante
    fclose(file); // fecha o arquivo
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a"); // atualizando o nome
    fprintf(file, nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a"); // atualizando o sobrenome
    fprintf(file, sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a"); // atualizando o cargo
    fprintf(file, cargo);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    

}

int consulta()
{
	char cpf[40]; // pois esta consultando o cpf
	char conteudo[400]; // vai ler 400 cpf
	
	setlocale(LC_ALL, "Portuguese"); // definir o brasil como referencia sempre
	
	printf("digite o CPF a ser consultado: "); // pergunta que sera feita
	scanf("%s", cpf); // lembrar de mandar escanear colocar as cordas e mencionar o cpf
	
	FILE *file; // pois � para abrir o arquivo ja criado
	file = fopen (cpf, "r"); // R pois � de ler em ingles e o objeto a ser pesquisado � cpf
	
	if(file == NULL) // caso nao exister o cpf ira mandar os codigos abaixo NULL de "caso nulo"
	{
		printf("n�o foi possivel abrir o arquivo, pois nao foi localizado! \n");
	}
	
	while(fgets(conteudo, 400, file) != NULL) // enquanto tiver conteudo e ele vai trazer estas informa��es abaixo
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar() // fun��o de deletar 
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	
	printf("Informe o CPF do usu�rio a ser deletado: \n");
	scanf("%s", cpf);
	
	remove(cpf); // remove o CPF
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) // caso nao exista
	{
		printf("O usu�rio n�o se encontra no sistema.\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; // definir a variavel como valor 0
	int x=1; // definindo a variavel de resposta como = 1
	
	for(x=1; x=1;) // definindo a variavel quando for 1 continua quando for 1 mantem
	{ // tudo que tiver dentro das chaves ira utilizar o couteudo compelto e nesse caso volta para o inicio
	
	system("cls"); // limpar a tela
	
	setlocale(LC_ALL, "Portuguese"); // definir o local - brasil
	
  	
	printf("### cart�rio da EBAC ###\n\n "); // texto que vai aparecer
	printf("escolha a op��o desejada do menu:\n\n");
	printf("\t1 - Registar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n"); 
	printf("Op��o: ");// final do que vai aparecer
	
	scanf("%d", &opcao); // scanf vai pausara tela e dxar o user digitar a variavel e armazena
	
	system("cls"); // sistema vai limpar a tela
	
	switch(opcao) // resume os IF's e caso seja 1 usa apenas a programa��o do 1
		{
		case 1: // : para falar tudo que vai acontecer
	    registro(); // chama de fun��o
		break; // encerra o comando nao precisa ficar repetindo
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		default: // nao � nenhuma das op��es e roda o comando padr�o
		printf("N�o existe este comando por enquanto!");
		system("pause");
		break;
		}

	
	if(opcao==1) // se a variaval � igual a 1 (== comapara��o) (if traduzindo - se)
	{
		printf("voc� escolheu o registro de nomes!\n"); // se ele digitar 1 - aparece este texto
		system("pause"); // pausa a mensagem na tela
	}
	if(opcao==2)
	{
		printf("Voce escolheu consultar os nomes!\n");
		system("pause");
	}
	if(opcao==3)
	{
		printf("Voce escolheu deletar os nomes!\n");
		system("pause");
	}
	if(opcao>=4 || opcao<=0) // || significa mais ou menos como um OU
	{
		printf("N�o existe este comando por enquanto!\n");
	} // fim da sele��o
	}
	
}
