# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <locale.h>

#define lenght 30 // define o tamnaho da string

// declação de funções
int menu(); // menu principal

struct  student_register  // modelo da estrutura do registro de alunos
{
	int RU;
	char name_student[lenght];
	char email_student[lenght];
};

typedef struct student_register Student;

struct node // modelo do nó da arvore
{
	Student Ru;
	node* right;
	node* left;
};

typedef node Node;

Node* init() // fução para  inicializar a arvore
{
	return NULL;
}

Student RuCreate(int ru, char nome[], char email[]) // função para retornar o item x de Student para a função insert
{
	Student student;
	student.RU = ru; // o codigo RU de student_register vai receber o parametro  informado
	strcpy_s(student.name_student, nome);
	strcpy_s(student.email_student, email);
	return student;
}

Node* insert(Node* root, Student newRu) // função para inserir dados na arvore
{
	if (root == NULL)// insere dados na raiz (root) vazia
	{
		Node* new_node = NULL; // cria um novo nó 
		new_node = (Node*)malloc(sizeof(Node)); // aloca a memória para o novo nó
		new_node->Ru = newRu; // novo nó recebe o item RU do Student vindo de fora (x)
		new_node->right = NULL; // por ser a ultima posição do nó (folha) ponteiro para proximo item a Direita recebe nulo
		new_node->left = NULL; // por ser a ultima posição do nó (folha) ponteiro para proximo item a Esquerda recebe nulo
		return new_node;
	}
	else // caso a arvore ja tenha algum registro (nó)
	{
		if (newRu.RU > root->Ru.RU) // se o novo item for maior que o nó, alocar a Direita do mesmo
		{
			root->right = insert(root->right, newRu);
		}
		else if (newRu.RU < root->Ru.RU) // se o novo item for menor que o nó, alocar a Esquerda deste
		{
			root->left = insert(root->left, newRu);
		}

	}
	return root;
}

// imprimir toda a arvore  ordenada  Menor ->> Maior
void printSorted(Node* root)
{
	if (root != NULL) // caso a raiz (root) esteja vazio (null) não sera executada a função
	{
		printSorted(root->left); // vai chamar ela mesma para imprimir o que houver a Esquerda do nó anterior
		printf("\n %d \n", root->Ru); // vai imprimir o RU do nó
		printSorted(root->right); // vai chamar ela mesma para imprimir o que houver a Direita do nó anterior
	}
}

// libera os nós
void treeFree(Node* root)
{
	if (root != NULL)
	{
		treeFree(root->left); // vai liberar o que houver a Esquerda do nó anterior
		treeFree(root->right); // vai liberar o que houver a Direita do nó anterior
		free(root); // vai liberar a raiz da arvore
	}
}

// localiza um RU 
Node* search(Node* root, int searchRu)
{
	if (root != NULL)
	{
		if (root->Ru.RU == searchRu)
		{
			return root;
		}
		else
		{
			if (root->Ru.RU < searchRu)
			{
				return search(root->right, searchRu);
			}
			else
			{
				return search(root->left, searchRu);
			}
		}
	}
	return NULL;
}

// inicializa uma consulta

int main() {
	setlocale(LC_ALL, "Portuguese"); // define a localização e padrão de escrita
	// while ((c = getchar()) != '\n' && c != EOF) {}; // limpar buffer teclado
	char giovani[lenght];
	char giovaniemail[lenght];
	strcpy_s(giovani, "Giovani");
	strcpy_s(giovaniemail, "giovaniwahl@gmail.com");

	char antonio[lenght];
	char antonioemail[lenght];
	strcpy_s(antonio, "Antonio");
	strcpy_s(antonioemail, "antonio@gmail.com");

	char maira[lenght];
	char mairaemail[lenght];
	strcpy_s(maira, "Maira");
	strcpy_s(mairaemail, "maira@gmail.com");

	char sueli[lenght];
	char sueliemail[lenght];
	strcpy_s(sueli, "Sueli");
	strcpy_s(sueliemail, "sueli@gmail.com");

	char jose[lenght];
	char joseemail[lenght];
	strcpy_s(jose, "Jose");
	strcpy_s(joseemail, "jose@gmail.com");

	char albino[lenght];
	char albinoemail[lenght];
	strcpy_s(albino, "Albino");
	strcpy_s(albinoemail, "albino@gmail.com");

	char jean[lenght];
	char jeanemail[lenght];
	strcpy_s(jean, "Jean");
	strcpy_s(jeanemail, "jean@gmail.com");

	char henrique[lenght];
	char henriqueemail[lenght];
	strcpy_s(henrique, "Henrique");
	strcpy_s(henriqueemail, "henrique@gmail.com");

	char cristina[lenght];
	char cristinaemail[lenght];
	strcpy_s(cristina, "Cristina");
	strcpy_s(cristinaemail, "cristina@gmail.com");

	char maria[lenght];
	char mariaemail[lenght];
	strcpy_s(maria, "Maria");
	strcpy_s(mariaemail, "maria@gmail.com");

	char daniele[lenght];
	char danieleemail[lenght];
	strcpy_s(daniele, "Daniele");
	strcpy_s(danieleemail, "daniele@gmail.com");

	char casiano[lenght];
	char casianoemail[lenght];
	strcpy_s(casiano, "Casiano");
	strcpy_s(casianoemail, "casiano@gmail.com");

	char miguel[lenght];
	char miguelemail[lenght];
	strcpy_s(miguel, "Miguel");
	strcpy_s(miguelemail, "miguel@gmail.com");

	char fabio[lenght];
	char fabioemail[lenght];
	strcpy_s(fabio, "Fabio");
	strcpy_s(fabioemail, "fabio@gmail.com");

	char osama[lenght];
	char osamaemail[lenght];
	strcpy_s(osama, "Osama");
	strcpy_s(osamaemail, "osama@gmail.com");


	Node* root;
	root = (Node*)malloc(sizeof(Node)); // cria um novo nó e aloca a memória
	root = NULL;
	Node* tmp;

	while (1)
	{
		int op = menu();
		int c;

		switch (op)
		{
		case 0: // Sair -- encerrar o programa
			treeFree(root); // libera a memória
			exit(0);
			break;

		case 1: // insersão dos dados -- ler o arquivo txt
			system("cls"); // limpa a tela

			root = init(); // cria a arvore, inicializa o 1 nó
			root = insert(root, RuCreate(2787739, giovani, giovaniemail)); // insere os dados no nó
			root = insert(root, RuCreate(5874813, antonio, antonio));
			root = insert(root, RuCreate(8750143, maira, mairaemail));
			root = insert(root, RuCreate(7515656, sueli, sueliemail));
			root = insert(root, RuCreate(2162033, jose, joseemail));
			root = insert(root, RuCreate(5736213, albino, albinoemail));
			root = insert(root, RuCreate(8481484, jean, jeanemail));
			root = insert(root, RuCreate(2155664, henrique, henriqueemail));
			root = insert(root, RuCreate(5724550, cristina, cristinaemail));
			root = insert(root, RuCreate(4181602, maria, mariaemail));
			root = insert(root, RuCreate(7862577, daniele, danieleemail));
			root = insert(root, RuCreate(6334235, casiano, casianoemail));
			root = insert(root, RuCreate(6601487, miguel, miguelemail));
			root = insert(root, RuCreate(3768301, fabio, fabioemail));
			root = insert(root, RuCreate(5330385, osama, osamaemail));

			printf("\n ARVORE CRIADA COM SECESSO \n");

			system("pause");
			break;

		case 2: // localiza uma RU especifica e imprime seus dados na tela
			system("cls"); // limpa a tela
			int RU;

			if (root == NULL)
			{
				printf("\n ARVORE NÃO GERADA \n");
			}

			if (root != NULL)
			{
				printf("\n DIGITE A RU DESEJADA \n");
				scanf_s("%d", &RU);
				while ((c = getchar()) != '\n' && c != EOF) {}; // limpar buffer teclado

				tmp = search(root, RU);
				if (tmp == NULL)
				{
					printf("\n  REGISTRO NÃO LOCALIZADO \n");
				}
				else
				{
					printf("\n RU: %d \n Nome: %s \n E-mail: %s \n", tmp->Ru.RU, tmp->Ru.name_student, tmp->Ru.email_student);
				}
			}
			system("pause");
			break;

		case 3: // imprime toda a arvore
			system("cls"); // limpa a tela

			if (root != NULL)
			{
				printf("\n ARVORE ORDENADA \n");
				printSorted(root);// imprimir toda a arvore  ordenada  Menor ->> Maior
			}
			if (root == NULL)
			{
				printf("\n ARVORE NÃO GERADA \n");
			}
			system("pause");
			break;

		default: // chama o menu de novo
			break;
		}

	}

	treeFree(root); // libera a memória

	system("pause");
	return 0;
}

// Menu
int menu()
{
	system("cls");
	int op = 0;
	int c;
	printf("\n DIGITE A OPÇÃO DESEJADA DO MENU \n");
	printf("\n // * 1 GERAR ARVORE \n");
	printf("\n // ** 2 LOCALIZAR RU \n");
	printf("\n // *** 3 IMPRIMIR TODA A ARVORE \n");
	printf("\n // 0 SAIR \n");
	scanf_s("%d", &op);
	while ((c = getchar()) != '\n' && c != EOF) {}; // limpar buffer teclado

	return op;
}