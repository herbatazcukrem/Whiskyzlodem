#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

struct sgodz {
	int godz;
	int min;
};
struct sdzien {
	int dz;
	int mies;
	int rok;
};

struct godzina {
	int godz;
	godzina* nast;
};

struct dzien {
	sdzien data;
	dzien*nast;
	godzina*lista;
};

bool porwnajd(sdzien k1, sdzien k2)
{
	if (k1.rok == k2.rok)
		if (k1.mies == k2.mies)
		{
			if (k1.dz > k2.dz)
			{//cout << k1.dz << "." << k1.mies << "." << k1.rok << "k1.dz = k2.dz"; 
				return true;}
			else
			{
				if (k1.dz > k2.dz)
				{//cout << k1.dz << "." << k1.mies << "." << k1.rok << "k1.dz > k2.dz)";
					return true;}
				else {// cout << k2.dz << "." << k2.mies << "." << k2.rok << "else k1.dz > k2.dz"; 
					return false; }
			}
		}
		else
		{
			if (k1.mies > k2.mies)
			{//cout << k1.dz << "." << k1.mies << "." << k1.rok << "k1.mies > k2.mies"; 
				return true;}
			else { //cout << k2.dz << "." << k2.mies << "." << k2.rok << " else k1.mies > k2.mies"; 
				return false; }
		}


	else if (k1.rok > k2.rok)
	{
		//cout << k1.dz << "." << k1.mies << "." << k1.rok << "k1.rok > k2.rok";
		return true;
	}
	else { //cout << k2.dz << "." << k2.mies << "." << k2.rok << "else k1.rok > k2.rok";
		return false; }
	

}


bool porwnajg(sgodz k1, sgodz k2)
{

	if (k1.godz == k2.godz)
	{
		if (k1.min > k2.min)
		{cout << k1.godz << ":" << k1.min; return true;}
		else
		{
			if (k1.min > k2.min)
			{cout << k1.godz << ":" << k1.min; return true;}
			else { cout << k2.godz << ":" << k2.min; return false; }

		}
	}
	else
	{
		if (k1.godz > k2.godz)
		{	cout << k1.godz << ":" << k1.min; return true;}
		else { cout << k2.godz << ":" << k2.min; return false; }
	}
}


sdzien wczytajs()
{
	sdzien k;
	cout << "dzien: ";  cin >> k.dz;
	cout << "miesiac: ";  cin >> k.mies;
	cout << "rok: "; cin >> k.rok;
	return k;
}


void wypiszds(sdzien k)
{
	cout << k.dz << "." << k.mies << "." << k.rok << endl;
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

void dodajds(dzien*&g, sdzien d)
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
	if (porwnajd(g->data, d))
	{
		temp->nast = g;
		g = temp; for (int i = 0; i<2; i++)dodajgs(g->lista, rand() % 10);
		return;
	}
	else
	{
		dzien * it = g;
		while ((it->nast != NULL) && (!porwnajd(it->nast->data , d)))
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



void wypiszg(godzina*g, fstream & plik)
{
	while (g != NULL)
	{
		plik << "     " << g->godz << endl;
		cout << "     " << g->godz << endl;
		g = g->nast;
	}
}
void wypiszd(dzien*g, fstream & plik)
{

	//plik.open("aaaaaaaaaaa.txt"); if (plik.good()) cout << "ok"; if (!plik.good()) cout << "buu";
	while (g != NULL)
	{
		wypiszds(g->data); wypiszg(g->lista, plik);
		//plik << g->data << endl; wypiszg(g->lista, plik);

		g = g->nast;
	}plik.close();
}


int main()
{
	dzien*glowa = NULL;
	fstream plik;
	
	plik.open("kk.txt");
	if (!plik.good())
	{
		ofstream plik;	plik.open("kk.txt"); cout << "nowy plik" << endl;
	} 
	
	
	
		dodajds(glowa, wczytajs());
		dodajds(glowa, wczytajs());
		dodajds(glowa, wczytajs());
	
	wypiszd(glowa, plik);
	 
	

	cin.get(); cin.get(); plik.close();
	return 0;
}
/*	uwaga do plików!!! plik nie chce sie stworzyc przy fstream, natomiast przy ofstream nie dziala reszta
gdy plik jest juz stworzony za pomoca ofstream to fstream juz dziala, 
nie zapisuje siê przy tworzeniu pliku
*/