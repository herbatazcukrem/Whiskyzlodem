#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
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
	sgodz godz;
	string opis;
	godzina* nast;	
};

struct dzien {
	sdzien data;
	dzien*nast;
	godzina*lista;
};
//...................................................................................................
bool porwnajd(sdzien k1, sdzien k2)
{
	if (k1.rok == k2.rok)
		if (k1.mies == k2.mies)
		{
			if (k1.dz > k2.dz)
			{return true;}
			else
			{
				if (k1.dz > k2.dz)
				{
					return true;}
				else {
					return false; }
			}
		}
		else
		{
			if (k1.mies > k2.mies)
			{
				return true;}
			else { 
				return false; }
		}


	else if (k1.rok > k2.rok)
	{
		
		return true;
	}
	else {
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
sgodz wczytajg()
{
	sgodz k;
	cout << "godzina: ";  cin >> k.godz;
	cout << "minutyc: ";  cin >> k.min;

	return k;
}


void dodajgs(godzina*&g, sgodz d)
{
	godzina*temp = new godzina;
	temp->godz = d;
	temp->nast = NULL; //cin.get();
	cout << "wydarzenie:";// getline (cin, temp->opis);
	if (g == NULL)
	{
		g = temp;
		return;
	}
	if (porwnajg(g->godz, d))
	{
		temp->nast = g;
		g = temp;
		return;
	}
	else
	{
		godzina * it = g;
		while ((it->nast != NULL) && (!porwnajg(it->nast->godz, d)))
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
		g = temp;  dodajgs(g->lista, wczytajg());
		return;
	}
	if (porwnajd(g->data, d))
	{
		temp->nast = g;
		g = temp; dodajgs(g->lista, wczytajg());
		return;
	}
	else
	{
		dzien * it = g;
		while ((it->nast != NULL) && (!porwnajd(it->nast->data , d)))
			it = it->nast;
		if (it->nast == NULL)
		{
			it->nast = temp; dodajgs(temp->lista, wczytajg());
		}
		else
		{
			temp->nast = it->nast;
			it->nast = temp; dodajgs(temp->lista, wczytajg());
		}
	}
}




void wypiszg(godzina*g, fstream & plik)
{
	
	while (g != NULL)
	{
		cout << g->godz.godz << ":" << g->godz.min << " " << g->opis << endl;
		//plik << g->godz.godz << " " << g->godz.min << " " << g->opis << endl;
		g = g->nast;
	}
}




void wypiszds(sdzien k, fstream & plik)
{
	cout << k.dz << "." << k.mies << "." << k.rok << " ";
//	plik << k.dz << " " << k.mies << " " << k.rok << " ";
}
void wypiszd(dzien*g, fstream & plik)
{

	while (g != NULL)
	{
		
		wypiszds(g->data, plik);
		
		wypiszg(g->lista, plik);

		g = g->nast;
	}plik.close();
}


void czytajgs(godzina*&g, fstream &plik)
{
	godzina*temp = new godzina;  
	sgodz d;
	plik >> d.godz >> d.min; //cout << d.godz << d.min;
	//cout << "wydarzenie:"; getline(plik, temp->opis); 
	temp->godz = d;
	temp->nast = NULL; cin.get(); 
	if (g == NULL)
	{
		g = temp;
		return;
	}
	if (porwnajg(g->godz, d))
	{
		temp->nast = g;

		g = temp;
		return;
	}
	else
	{
		godzina * it = g;
		while ((it->nast != NULL) && (!porwnajg(it->nast->godz, d)))
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


void czytaj(dzien*&g, fstream & plik)
{
	

	string s; while (!(plik.eof()))
	{
		dzien*temp = new dzien; sdzien d;
		getline(plik, s); 

		temp->data = d;
		temp->nast = NULL;
		temp->lista = NULL;

	/*	if (g == NULL)
			g = temp; czytajgs(temp->lista, plik);
		dzien*it = g;
		while (it->nast != NULL)
			it = it->nast;
		it->nast = temp;
	*/
		temp->data = d;
		temp->nast = g;
		g = temp;
		
	}
	


	
	





}




int main()
{
	dzien*glowa = NULL;
	fstream plik;
	string s;
	
	cout << "TERMINARZ" << endl; cout << "wybierz opcje:" << endl; cout << "1.wyswietlenie " << "2. dopisanie " << "3. usuniecie " << endl;
	
	int wybor;
	cin >> wybor;
	switch (wybor)
	{
	case 1:
		cout << "jeden" << endl; 
		plik.open("kk.txt", ios_base::in | ios_base::out | ios_base::app); czytaj(glowa, plik);
		plik.seekg(0, ios_base::beg);
		while (getline(plik, s))
		{
			cout << s << endl;
		}
		wypiszd(glowa, plik);
		break;
	case 2:
		cout << "dwa" <<endl; plik.open("kk.txt", ios_base::in | ios_base::out | ios_base::app);  dodajds(glowa, wczytajs());	wypiszd(glowa, plik);
		break;
	case 3:
		cout << "trzy" <<endl;
		break;
	default:
		cout << "ani jeden, ani dwa, ani trzy" << endl;
		break;
	}

	

	
	//if (!plik.good())
//	{
	//	ofstream plik("kk.txt"); plik.open("kk.txt");	 cout << "nowy plik" << endl;
//	} 
	
	

	
	
	
		//dodajds(glowa, wczytajs());
	
		
	
		cin.get(); cin.get(); cin.get(); cin.get();
	cin.get(); cin.get(); plik.close();
	return 0;
}
