#include <stdio.h>

typedef struct Node				//�ڱ���������ü ����.
{
	int data;
	struct Node *link;
}Node;

//searchNode �Լ������� ����.

void createList(Node **);				// ����ڰ� ���ϴ� ��� �� ��ŭ �ܼ����Ḯ��Ʈ�� ����� �Լ�
void appendNode(Node **, int );			// ���ο� ��带 ����Ʈ�� �����Ű�� �Լ�, (ù��° �������� Node, ������ ���޵Ǵ� �����͸� �����Ŵ)
void printNode(Node *);					// ����Ʈ�� ��� ��� ���ִ� �Լ�.
Node *searchNode(Node **, int );		// �Լ��� �ι�° �������ڸ� ����Ʈ���� ã�� �������� ���� �����͸� �����ϰ� ã�� �����͸� ����Ű�� �����͸� ù��° �������ڿ� �����ϴ� �Լ�
void insertNode(Node *, int );			// �Լ��� �ι�° �������ڸ� ã�� ��� �Է�
void printJusoNode(Node *);				// ����Ʈ(�ּ� ����)�� ��� ��� ���ִ� �Լ�.
void deleteNode(Node **);				// ����Ʈ�� ��带 ã�� �� ��带 �����ϴ� �Լ�.

int main()
{
//*********�׽�Ʈ�� �����Լ��Դϴ�.************
	Node *head = NULL;
	Node **p;
	Node *search;
	int data;

	createList(&head);

	p = &head;

	printJusoNode(head);

	printf("\nhead pointer : %d\n", *head);
	printf("searchdata : ");
	scanf("%d", &data);

	search = searchNode(p, data);

	printf("\nsearch : %d	head pointer :%d\n", search, *head);

//	printJusoNode(head);

	_getch();

	return 0;

//*********************************************
}

void createList(Node **p)					//����ڰ� ���ϴ� ��� �� ��ŭ �ܼ����Ḯ��Ʈ�� ����� �Լ�
{
	int a;
	int data;
	Node *q;

	q = NULL;

	while(1)
	{
		printf("insert?(1/0) : ");
		scanf("%d", &a);
		if(a == 0)
		{
			break;
		}

		printf("insert data : ");
		scanf("%d", &data);
		appendNode(&q, data);
		
		if (*p == NULL) *p = q;
	}		
}
	
void appendNode(Node **p, int data)		// ���ο� ��带 ����Ʈ�� �����Ű�� �Լ�, (ù��° �������� Node, ������ ���޵Ǵ� �����͸� �����Ŵ)
{
	Node *new_node;
	new_node = (Node *)malloc(sizeof(Node));

	new_node->data = data;

	if (*p == NULL)							//*p�� ���� ���� (��, ����� ���) new_node�� ����Ű�� �ϰ�.
	{
		new_node->link = NULL;
		*p = new_node;
	}
	else									//��尡 �ƴҰ��� *p�� ��ũ�� ����带 ����Ű�� �Ѵ�.
	{
		new_node->link = (*p)->link;
		(*p)->link = new_node;
		(*p) = (*p)->link;					//�־��� �μ��� ���� ��ũ�� ����Ű�� �Ѵ�.
	}
}

void printNode(Node *list)
{
	if(list == NULL)
	{
		printf(" end");
	}
	else
	{
		printf(" %d", list->data);
		printNode(list->link);
	}
}

Node *searchNode(Node **p, int data)
{
	Node *prev;
	Node *temp;

	prev = *p;
	temp = p;

	while((*p)->data != data)
	{
		if((*p)->link == NULL)
		{
			printf("\nerror!!!");
			prev = NULL;
			break;
		}
		prev = (*p);
		*p = (*p)->link;
	}
	if(prev == (*p))
	{
		prev = temp;
	}

	return prev;
}

void insertNode(Node *p, int data)
{
	Node *a;
	int insertdata;

	a = searchNode(&p, data);

	printf("insert data : ");
	scanf("%d", &insertdata);

	appendNode(&p, insertdata);
}

void printJusoNode(Node *list)
{
	if(list == NULL)
	{
		printf(" end");
	}
	else
	{

		printf(" %d : %d ", list->data, list);
		printJusoNode(list->link);
	}
}

void deleteNode(Node **p)
{
	Node *q;
	int data;

	printf("\ndelete node : ");
	scanf("%d", &data);

	q = searchNode(p, data);

	printf("q : %d		p : %d\n", q, *p);

//	q->link = (*p)->link;
	
//	free(*p);
}
	