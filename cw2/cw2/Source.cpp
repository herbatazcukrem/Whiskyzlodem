#include <iostream>
#include <time.h>
#include<math.h>
#include<string>
#include <fstream>
using namespace std;

struct s
{
	s* next;
	int w;
};


s* Dodaj(s*h, int i)
{
	s*temp = new s;
	temp->w = i;
	temp->next = h;
	
	return temp;
}

s* DodajKoniec(s*h, int i)
{
	s*temp1 = new s;
	
	temp1->w = i;
	temp1->next = NULL;

	if (h == NULL)
		return temp1;
	s*temp2 = h;
	while (temp2->next != NULL)
		temp2 = temp2->next;
	temp2->next = temp1;
	return h;

}



void Wypisz(s*h)
{
	while (h) {

		cout << h->w << endl;
		h = h->next;
	}
}


int main()
{
	fstream plik;
	srand(time(NULL));
	s*head = NULL;
//	for (int i = 0; i < 4; i++)
	//	head = DodajSort(head, rand()%100);
	//Wypisz(head);
	int a ,b;
	head = Dodaj(head, 1); head = Dodaj(head,7); head = Dodaj(head, 9);
	plik.open("a.txt", ios_base::in);
	while (!plik.eof())
	{
		plik >> a;
		head = DodajKoniec(head, a);;// cout << endl; head = DodajKoniec(head, 50); cout << endl; head = DodajKoniec(head, 2); cout << endl;
		plik >> b;
		head = DodajKoniec(head, b);
	}Wypisz(head);
	cin.get();
	return 1;
}
