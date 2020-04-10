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
	Node* root;
	root = (Node*)malloc(sizeof(Node));
	root = init();
	Node* tmp;

	while (1)
	{
		int op = menu();
		int c;
		int RU = NULL;

		switch (op)
		{
		case 0:
			treeFree(root);
			exit(0);
			break;
		case 1:
			char nome[lenght];
			char email[lenght];
			system("cls");
			printf("\n INFORME O RU DO ESTUDANTE: \n");
			scanf_s("%d", &RU);
			while ((c = getchar()) != '\n' && c != EOF) {};
			printf("\n DIGITE NOME \n");
			gets_s(nome);
			printf("\n DIGITE O E-MAIL \n");
			gets_s(email);
			root = insert(root, RuCreate(RU, nome,email));
			break;
		case 2:
			system("cls");
			char giovani[lenght];
			char giovaniemail[lenght];
			strcpy_s(giovani, "Giovani");
			strcpy_s(giovaniemail, "giovaniwahl@gmail.com");
			root = insert(root, RuCreate(2787739, giovani, giovaniemail));
			printf("\n ARVORE CRIADA COM SECESSO \n");
			system("pause");
			break;
		case 3:
			system("cls");
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
