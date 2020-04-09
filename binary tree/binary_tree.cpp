# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <locale.h>

#define lenght 30 

int menu(); 

struct  student_register  
{
	int RU;
	char name_student[lenght];
	char email_student[lenght];
};

typedef struct student_register Student;

struct node 
{
	Student Ru;
	node* right;
	node* left;
};

typedef node Node;

Node* init() 
{
	return NULL;
}

Student RuCreate(int ru, char nome[], char email[]) 
{
	Student student;
	student.RU = ru; 
	strcpy_s(student.name_student, nome);
	strcpy_s(student.email_student, email);
	return student;
}

Node* insert(Node* root, Student newRu) 
{
	if (root == NULL)
	{
		Node* new_node = NULL;  
		new_node = (Node*)malloc(sizeof(Node)); 
		new_node->Ru = newRu; 
		new_node->right = NULL; 
		new_node->left = NULL; 
		return new_node;
	}
	else 
	{
		if (newRu.RU > root->Ru.RU) 
			root->right = insert(root->right, newRu);
		else if (newRu.RU < root->Ru.RU) 
			root->left = insert(root->left, newRu);
	}
	return root;
}

void printSorted(Node* root)
{
	if (root != NULL) 
	{
		printSorted(root->left); 
		printf("\n %d \n", root->Ru); 
		printSorted(root->right);
	}
}

void treeFree(Node* root)
{
	if (root != NULL)
	{
		treeFree(root->left);
		treeFree(root->right);
		free(root);
	}
}

Node* search(Node* root, int searchRu)
{
	if (root != NULL)
	{
		if (root->Ru.RU == searchRu)
			return root;
		else
		{
			if (root->Ru.RU < searchRu)
				return search(root->right, searchRu);
			else
				return search(root->left, searchRu);
		}
	}
	return NULL;
}

int main() {
	setlocale(LC_ALL, "Portuguese"); 
	int RU;
	char nome[lenght];
	char email[lenght];

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
	root = (Node*)malloc(sizeof(Node));
	root = NULL;
	Node* tmp;

	while (1)
	{
		int op = menu();
		int c;

		switch (op)
		{
		case 0:
			treeFree(root);
			exit(0);
			break;

		case 1:
			root = insert(root,RuCreate(RU,nome,email))
			break;

		case 2:
			system("cls");
			root = init();
			root = insert(root, RuCreate(2787739, giovani, giovaniemail));
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
		case 3:
			system("cls");
			int RU;
			if (root == NULL)
				printf("\n ARVORE NÃO GERADA \n");

			if (root != NULL)
			{
				printf("\n DIGITE A RU DESEJADA \n");
				scanf_s("%d", &RU);
				while ((c = getchar()) != '\n' && c != EOF) {};
				tmp = search(root, RU);
				if (tmp == NULL)
					printf("\n  REGISTRO NÃO LOCALIZADO \n");
				else
					printf("\n RU: %d \n Nome: %s \n E-mail: %s \n", tmp->Ru.RU, tmp->Ru.name_student, tmp->Ru.email_student);
			}
			system("pause");
			break;
		case 4:
			system("cls");
			if (root != NULL)
			{
				printf("\n ARVORE ORDENADA \n");
				printSorted(root);
			}
			if (root == NULL)
				printf("\n ARVORE NÃO GERADA \n");
			system("pause");
			break;
		default:
			return 0;
			break;
		}
	}
	treeFree(root);
	system("pause");
	return 0;
}

int menu()
{
	system("cls");
	int op = 0;
	int c;
	printf("\n DIGITE A OPÇÃO DESEJADA DO MENU \n");
	printf("\n // * 1 CADASTRAR ESTUDANTE \n");
	printf("\n // ** 2 GERAR ARVORE \n");
	printf("\n // *** 3 LOCALIZAR RU \n");
	printf("\n // **** 4 IMPRIMIR TODA A ARVORE \n");
	printf("\n // 0 SAIR \n");
	scanf_s("%d", &op);
	while ((c = getchar()) != '\n' && c != EOF) {};
	return op;
}