#include "NameCard.h"

NameCard * MakeNameCard(char * name, char * phone)
{
	NameCard* namecard = (NameCard *)malloc(sizeof(NameCard));
	strcpy(namecard->name, name);
	strcpy(namecard->phone, phone);
	return namecard;
}

void ShowNameCardInfo(NameCard * pcard)
{
	printf("[�̸�] %s\n[��ȭ��ȣ] %s\n\n", pcard->name, pcard->phone);
}

int NameCompare(NameCard * pcard, char * name)
{
	return strcmp(pcard->name, name);
}

void ChangePhoneNum(NameCard * pcard, char * phone)
{
	strcpy(pcard->phone, phone);
}