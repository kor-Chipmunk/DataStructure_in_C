/*
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node * next;
} Node;

int main(void)
{
	Node * head = NULL;
	Node * tail = NULL;
	Node * cur = NULL;

	Node * newNode = NULL;
	int readData;

	// ���̳�� ����
	newNode = (Node *)malloc(sizeof(Node));
	newNode->data = 0;
	newNode->next = NULL;

	head = newNode;
	tail = newNode;

	// �����͸� �Է� �޴� ����
	while (1)
	{
		printf("�ڿ��� �Է�: ");
		scanf("%d", &readData);
		if (readData < 1)
			break;

		// ����� �߰�����
		newNode = (Node *)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		tail->next = newNode;
		tail = newNode;
	}
	printf("\n");

	// �Է� ���� �������� ��°���
	printf("�Է� ���� �������� ��ü���! \n");
	if (head->next == NULL)
	{
		printf("����� �ڿ����� �������� �ʽ��ϴ�. \n");
	}
	else
	{
		cur = head->next;
		printf("%d ", cur->data);		// ù ��° ������ ���

		while (cur->next != NULL)		// �� ��° ������ ������ ���
		{
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}
	printf("\n\n");

	// �޸��� ��������
	if (head == NULL)
	{
		return 0;						// ������ ��尡 �������� �ʴ´�.
	}
	else
	{
		Node * delNode = head->next;
		Node * delNextNode = delNode->next;

		printf("%d��(��) �����մϴ�. \n", head->data);
		free(delNode);					// ù ��° ��� ����

		while (delNextNode != NULL)		// �� ��° ���� ��� ����
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d��(��) �����մϴ�. \n", delNode->data);
			free(delNode);
		}
	}

	// ���̳�� ����
	free(head);

	return 0;
}
*/