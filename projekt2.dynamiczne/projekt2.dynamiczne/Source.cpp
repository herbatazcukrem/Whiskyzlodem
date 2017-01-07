#include <iostream>
#include <time.h>
using namespace std;

struct godzina {
	int godz;
	godzina* nast;
};

struct dzien {
	int data;
	dzien*nast;
	godzina*lista;
};

void dodajd(dzien*&g, int d)
{
	dzien*temp = new dzien;
	temp->data = d;
	temp->lista = NULL;
	temp->nast = g;
	g=temp;
}

void dodajgs(godzina*&g, int d)
{
	godzina*temp = new godzina;
	temp->godz = d;
	temp->nast = NULL;

	if (g == NULL)
	{
		g = temp;
		return;
	}
	if (g->godz> d)
	{
		temp->nast = g;
		g = temp;
		return;
	}
	else
	{
		godzina * it = g;
		while ((it->nast != NULL) && (it->nast->godz < d))
			it = it->nast;
		if (it->nast == NULL)
		{
			it->nast = temp;
		}
		else
		{
			temp->nast = it->nast;
			it->nast = temp;
		}
	}
}

void dodajds(dzien*&g, int d)
{
	
	dzien*temp = new dzien;
	temp->data = d;
	temp->nast = NULL;
	temp->lista = NULL;

	if (g == NULL)
	{
		g = temp;  dodajgs(g->lista, rand() % 10);
		return;
	}
	if (g->data > d)
	{
		temp->nast = g;
		g = temp; for(int i=0; i<2; i++)dodajgs(g->lista, rand() % 10);
		return;
	}
	else
	{
		dzien * it = g;
		while ((it->nast != NULL) && (it->nast->data < d))
			it = it->nast;
		if (it->nast == NULL)
		{
			it->nast = temp; for (int i = 0; i<3; i++)dodajgs(temp->lista, rand() % 10);
		}
		else
		{
			temp->nast = it->nast;
			it->nast = temp;  for (int i = 0; i<4; i++)dodajgs(temp->lista, rand() % 10);
		}
	}
}





void wypiszg(godzina*g)
{
	while (g != NULL)
	{
		cout << "     "<< g->godz<< endl;
		g = g->nast;
	}
}
void wypiszd(dzien*g)
{
	while (g != NULL)
	{
		cout << g->data << endl; wypiszg(g->lista);
		g = g->nast;
	}
}



int main()
{
	srand(time(NULL));
	dzien*glowa = NULL;
	for (int i = 0; i < 5; i++)
	{
		dodajds(glowa, rand() % 100+10);
		
	}
	wypiszd(glowa);
	cin.get();
	return 0; 
}