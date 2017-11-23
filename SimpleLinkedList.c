#include <stdio.h>

typedef struct Node				//자기참조구조체 선언.
{
	int data;
	struct Node *link;
}Node;

//searchNode 함수문제점 잡자.

void createList(Node **);				// 사용자가 원하는 노드 수 만큼 단순연결리스트를 만드는 함수
void appendNode(Node **, int );			// 새로운 노드를 리스트에 연결시키는 함수, (첫번째 전달인자 Node, 다음에 전달되는 데이터를 연결시킴)
void printNode(Node *);					// 리스트를 모두 출력 해주는 함수.
Node *searchNode(Node **, int );		// 함수의 두번째 전달인자를 리스트에서 찾아 데이터의 이전 포인터를 리턴하고 찾은 데이터를 가르키는 포인터를 첫번째 전달인자에 저장하는 함수
void insertNode(Node *, int );			// 함수의 두번째 전달인자를 찾고 노드 입력
void printJusoNode(Node *);				// 리스트(주소 까지)를 모두 출력 해주는 함수.
void deleteNode(Node **);				// 리스트의 노드를 찾고 그 노드를 삭제하는 함수.

int main()
{
//*********테스트용 메인함수입니다.************
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

void createList(Node **p)					//사용자가 원하는 노드 수 만큼 단순연결리스트를 만드는 함수
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
	
void appendNode(Node **p, int data)		// 새로운 노드를 리스트에 연결시키는 함수, (첫번째 전달인자 Node, 다음에 전달되는 데이터를 연결시킴)
{
	Node *new_node;
	new_node = (Node *)malloc(sizeof(Node));

	new_node->data = data;

	if (*p == NULL)							//*p가 널일 경우는 (즉, 헤드일 경우) new_node를 가르키게 하고.
	{
		new_node->link = NULL;
		*p = new_node;
	}
	else									//헤드가 아닐경우는 *p의 링크가 뉴노드를 가르키게 한다.
	{
		new_node->link = (*p)->link;
		(*p)->link = new_node;
		(*p) = (*p)->link;					//넣었던 인수는 다음 링크를 가르키게 한다.
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
	