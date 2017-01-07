#include <iostream>
#include <time.h>

using namespace std;

struct s {
	int dana;
	s *next;
};

void wypisz(s *head)
{
	if (!head) cout << "Pusta lista" << endl;
	while (head)
	{
		cout << head->dana << endl;
		head = head->next;
	}
}

void dodaj(s *&head, int i)
{
	s *tmp = new s;
	tmp->dana = i;
	tmp->next = NULL;
	if (head == NULL)
	{
		head = tmp;
		return;
	}
	if (head->dana > i)
	{
		tmp->next = head;
		head = tmp;
		return;
	}
	else
	{
		s *it = head;
		while (it->next != NULL && it->next->dana < i)
			it = it->next;
		if (it->next == NULL)
			it->next = tmp;
		else
		{
			tmp->next = it->next;
			it->next = tmp;
		}
	}
}

bool znajdzP(s *head, s *&findprev)
{
	if (!head)
	{
		return false;
	}
	if (head->dana % 2 == 0)
	{
		findprev = NULL;
		return true;
	}
	while (head->next != NULL && head->dana % 2 != 0)
		head = head->next;
	if (head->next == NULL) return false;
	findprev = head;
	return true;
}

void usun(s *&head, s *findprev)
{
	if (findprev == NULL)
	{
		findprev = head;
		head = head->next;
		delete findprev;
		return;
	}
	s *tmp = findprev->next;
	findprev->next = findprev->next->next;
	delete tmp;
}

int main()
{
	srand(time(NULL));
	s *head = NULL;
	for (int i = 0; i < 10; ++i)
		dodaj(head, rand() % 100);
	wypisz(head);
	s *findprev = NULL;
	if (znajdzP(head, findprev))
	{
		if (findprev == NULL)
		{
			cout << "znaleziony: " << head->dana << endl;
		}
		else
		{
			cout << "znaleziony: " << findprev->next->dana << endl;
		}
	}
	else
	{
		cout << "Nie znalazl." << endl;
	}
	usun(head, findprev);
	wypisz(head);
	cin.get();
	return 0;
}