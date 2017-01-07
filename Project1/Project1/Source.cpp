/*#include <iostream>

using namespace std;



struct s {

	int liczba;
	s* nast;

};


void dodaj(s*&glowa, int i)//dodaj na koniec
{
	s*temp = new s;
	temp->nast = glowa;
	temp->liczba = i;

	glowa = temp;

}


s* dodajk(s*glowa, int i)
{
	s*temp = new s; s*temp2 = new s; 

	temp->liczba =i;	temp->nast = NULL;
	if (glowa==NULL)
	{
		return temp;
	}


	temp2 = glowa;
	while (temp2->nast != NULL)
		temp2=temp2->nast;
	temp2->nast = temp;
	return temp;
}








void wypisz(s*glowa)
{
	while (glowa != NULL)
	{
		cout << glowa->liczba<<endl;
		glowa=glowa->nast;
	}

}




int main()
{
	s*gora = NULL;
	for (int i = 0; i < 5; i++)
	{
		dodaj(gora, i);
	}

	for (int i = 5; i < 10; i++)
	{
		dodajk(gora, i);
	}
	wypisz(gora);
	 


	cin.get();
	return 0;
}*/





#include <iostream>
#include <time.h>
#include<math.h>

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
	s *aaa = new s;
	aaa->dana = i;
	aaa->next = NULL;
	if (head == NULL)
	{
		head = aaa;
		return;
	}
	if (head->dana > i)
	{
		aaa->next = head;
		head = aaa;
		return;
	}
	else
	{
		s *it = head;
		while (it->next != NULL && it->next->dana < i)
			it = it->next;
		if (it->next == NULL)
			it->next = aaa;
		else
		{
			aaa->next = it->next;
			it->next = aaa;
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
	if (head->next == NULL)
		return false;
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
	s *aaa = findprev->next;
	findprev->next = findprev->next->next;
	delete temp;
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