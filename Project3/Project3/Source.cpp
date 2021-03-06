#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

struct sgodz {				//struktura przechowujaca dane odnosnie godziny
	int godz;
	int min;
};
struct sdzien {				//struktura przechowujace dane odnosnie daty
	int dz;
	int mies;
	int rok;
};
struct godzina {			//struktura do listy podwieszanej, przechowuje dane odnosnie godziny, opis wydarzenia i wskaznik na kolejny
	sgodz godz; 
	string opis;
	godzina* nast;	
};
struct dzien {				//struktura do listy glownej, przechowuje dane odnosnie daty, wskaznik na kolejny i wskaznik na liste podwieszana
	sdzien data;
	dzien*nast;
	godzina*lista;
};
//...................................................................................................
bool porwnajd(sdzien k1, sdzien k2)					//funkcja do porownywanie struktur sdzien, zwraca true gdy pierwsza struktura jest wieksza
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
bool porwnajg(sgodz k1, sgodz k2)				//funkcja do porownywanie struktur sgodz, zwraca true gdy pierwsza struktura jest wieksza
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
{												// funkcja wczytuje dane do struktury sdzien(uzywane w liscie glownej)									
												//zabezpiezpieczone przed wpisaniem blednych znakow i danych nie majacych sensu (np. data 45.14.2000)
	sdzien k;  
	do {
		cout << "Dzien: ";
	cin >> k.dz;
	if (cin.fail() || k.dz > 31 || k.dz < 1)
	{
		cout << "Podales bledne dane .Sprobuj jeszcze raz." << endl; 
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		k.dz = 0;
	}
	} while (!k.dz);
	
	do {
		cout << "Miesiac: ";
		cin >> k.mies;
		if (cin.fail() || k.mies > 12 || k.mies < 1)
		{
			cout << "Podales bledne dane. Sprobuj jeszcze raz." << endl; 
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			k.mies = 0;
		}
	} while (!k.mies);
	  

	do {
		cout << "Rok [rrrr]: ";
		cin >> k.rok;
		if (cin.fail() || k.rok > 2100 || k.rok < 2000)
		{
			cout << "Podales bledne dane. Sprobuj jeszcze raz." << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			k.rok = 0;
		}
	} while (!k.rok);
	
	return k;
}
sgodz wczytajg()					//funkcja wczytuje dane do struktury godzina (uzywane w liscie podwieszanej)
{									//zabezpiezpieczone przed wpisaniem blednych znakow i danych nie majacych sensu (np. godzina 25:80)
	sgodz k;

	do {
		cout << "Godzina: ";
		cin >> k.godz;
		if (cin.fail() || k.godz > 24 || k.godz < 1)
		{
			cout << "Podales bledne dane. Sprobuj jeszcze raz." << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			k.godz = 0;
		}
	} while (!k.godz);


	do {
		cout << "Minuty: ";
		cin >> k.min;
		if (cin.fail() || k.min > 60 || k.min < 0)
		{
			cout << "Podales bledne dane. Sprobuj jeszcze raz." << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			k.min = 0;
		}
	} while (!k.min);
	

	return k;
}


void dodajgs(godzina*&g, sgodz d)									//funkcja dodaje elementy do listy podwieszanej
{
	godzina*temp = new godzina;
	temp->godz = d;
	temp->nast = NULL; cin.get();
	cout << "wydarzenie:";  getline (cin, temp->opis);
	if (g == NULL)														//dodanie pierwszego elementu
	{
		g = temp;
		return;
	}
	
	if (porwnajg(g->godz, d))											//dodanie na poczatek
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
		if (it->godz.godz == d.godz && it->godz.min == d.min)			//zabezpieczenie na dodanie elementu ktory juz istnieje
		{
			cout << "Na dana godzine jest juz wydarzenie."; return;
		}
		if (it->nast == NULL)											//dodanie na koniec
		{
			it->nast = temp;
		}
		else
		{
			temp->nast = it->nast;										//dodanie do srodka
			it->nast = temp;
		}
	}
}

void dodajds(dzien*&g, sdzien d)		//funkcja dodaje nowa elemet listy, od razu sortujac 
{

	dzien*temp = new dzien;
	temp->data = d;
	temp->nast = NULL;
	

	if (g == NULL)									//dodanie pierwszego elementu
	{
		temp->lista = NULL;
		g = temp;  dodajgs(g->lista, wczytajg());
		return;
	}
	
	if (porwnajd(g->data, d))						//dodanie na gore (nowa glowa)
	{
		temp->lista = NULL;
		temp->nast = g;
		g = temp; dodajgs(g->lista, wczytajg());
		return;
	}
	else
	{
		
		dzien * it = g;
		
		
		while ((it->nast != NULL) && (!porwnajd(it->nast->data, d)))
		{
			it = it->nast; 
		}	
		
		if (it->data.dz == d.dz && it->data.rok == d.rok && it->data.mies == d.mies) //dodanie nowego elementu listy podwieszanej gdy element listy glownej juz istnieje 
			{dodajgs(it->lista, wczytajg()); return; }
		

		temp->lista = NULL;
		if (it->nast == NULL)											//dodanie na koniec listy
		{
			it->nast = temp; dodajgs(temp->lista, wczytajg());
		}
		else															//dodanie do srodka listy
		{
			temp->nast = it->nast;
			it->nast = temp; dodajgs(temp->lista, wczytajg());
		}
	}
}


void wypisz(dzien*g)				//funkcja wypisuje liste na ekran
{
	if (g == NULL) { cout << "Brak wydarzen" << endl; return; }

	while (g != NULL)
	{
		cout<<g->data.dz<<"." << g->data.mies << "." << g->data.rok << endl;
		while (g->lista != NULL)
		{
			cout << "     " << g->lista->godz.godz << ":" << g->lista->godz.min << " " << g->lista->opis << endl;
			g->lista = g->lista->nast;
		}
		g = g->nast;	
	}
}


void czytajgs(godzina*&g, fstream &plik)		//funkcja pobiera elementy z pliku i wczytuje do listy podwieszanej
{												//funkcja ta jest analogiczna do nastepnej (czytaj)
	godzina*temp = new godzina;  
	sgodz d;
	plik >> d.godz >> d.min;
   getline(plik, temp->opis); 
   temp->godz = d;
   temp->nast = NULL;
   if (g == NULL)
   {
	   g = temp;
	   return;
   }
   godzina *it = g;
   while (it->nast != NULL)
	   it = it->nast;
   it->nast = temp; 
   temp=g;  

}

void czytaj(dzien*&g, fstream & plik)			//funkcja pobiera elementy pliku i wczytuje do listy
{
	string s; 
	
		dzien*temp = new dzien; sdzien d; 
		plik >> d.dz >> d.mies >> d.rok; 
		if (d.dz == -858993460)return;			//warunek na pobranie entera z pliku
		 temp->data = d;	 
		temp->nast = NULL;
		
		if(g==NULL)								//dodanie pierwszego elementu z pliku
		{
			temp->lista = NULL;
			g = temp;
			czytajgs(g->lista, plik);
			return;
		}
	
		temp->lista = NULL;
	
		dzien *it=g;							//dane w pliku sa posortowane, aby uzyslac taka sama kolejnosc w liscie
		while (it->nast != NULL)				// dodaje elementy na koniec listy
		{
			it = it->nast; 
		}
		if (it->data.dz == d.dz && it->data.mies == d.mies && it->data.rok == d.rok)
		{
			czytajgs(it->lista, plik);
			return;
		}
		
		it->nast = temp; czytajgs(temp->lista, plik);
		temp = g; 
		
}

void zapisz(dzien*&g, fstream & plik)			//funkja zapisuje do pliku z jednnoczesnym usuwaniem z pamieci calej listy
{
	plik.open("kk.txt",  ios_base::trunc | ios_base::out);
	godzina*temp; dzien*tempd;
	while (g != NULL)
	{
		
		while (g->lista != NULL)
		{
			plik << g->data.dz << " " << g->data.mies << " " << g->data.rok << " ";
			plik << g->lista->godz.godz << " " << g->lista->godz.min << " " << g->lista->opis <<endl;
			temp = g->lista->nast;
			delete g->lista;
			g->lista = temp;
		}

		tempd = g->nast;
		delete g;
		g = tempd;
		
	}

	
	plik.close();
}


void usun(dzien*&g)				//funkcja umozliwia usuwanie calego elemetu dzien lub elementu listy podwieszanej  
{
	sgodz k;
	sdzien d; godzina*temp; 
	cout << "[1] Usun konkretne wydarzenie "<<endl; cout << "[2] Usun wydarzenia z calego dnia " << endl;
	
	int wybor;
	cin >> wybor;
	switch (wybor)
	{
	case 1:
		cout << "Usuwasz konkretne wydarzenie" << endl;
		d = wczytajs(); k = wczytajg();
		
			while ((g->data.dz != d.dz && g->data.mies != d.mies && g->data.rok != d.rok) && (g->nast != NULL))
			{
				g = g->nast;
			}

		if (g->data.dz == d.dz && g->data.mies == d.mies && g->data.rok == d.rok)
		{
			if (g->lista->nast == NULL)											//zabezpieczenie przed pozostawieniem struktury dzien bez elementow listy podwieszanej 
			{																	//wiazalo by sie to z bledami przy wcytywaniu
				cout << "Ten dzien ma tylko jedno wydarzenie, aby je usunac usun dzien." << endl; return;
			}

			if (g->lista->godz.godz == k.godz && g->lista->godz.min == k.min)	//usuniecie glowy listy podwieszanej
			{
				temp = g->lista->nast;
				delete g->lista;
				g->lista = temp;  return;
			}
			else if (g->lista->godz.godz != k.godz && g->lista->godz.min != k.min)	//usuniecie podanego elementu

			{
				godzina*pomocnicza = g->lista;
				dzien *i = g;
				while ((i->lista->nast != NULL) && ((i->lista->nast->godz.godz != k.godz) && (i->lista->nast->godz.min != k.min)))
				{
					i->lista = i->lista->nast;
				}

				temp = i->lista->nast->nast;
				delete i->lista->nast;
				i->lista->nast = temp;

				g->lista = pomocnicza; return;
			}

			cout << "Wydarzenie o podanej godzinie nie istnieje." << endl;
		}
		break;
	case 2:
		dzien*tempd;
		cout << "Usuwasz wydarzenia z calego dnia " << endl;
		
		d = wczytajs(); dzien*im = g;

		if(g==NULL || (g->nast==NULL && g->data.dz != d.dz && g->data.mies != d.mies && g->data.rok != d.rok)) //warunek na wpisanie blednych danych lub pustej glowy
		{
			cout << "Bledne dane" << endl; return;
		}
		if ((g->nast == NULL)&&(g->data.dz == d.dz && g->data.mies == d.mies && g->data.rok == d.rok))			//warunek na usuwanie gdy istnieje jeden element
		{
			while (g->lista != NULL)
			{
				temp = g->lista->nast;
				delete g->lista;
				g->lista = temp;
			}
			 tempd = g->nast;
			delete g;
			g = tempd;	return;
		}
		if (g->data.dz == d.dz && g->data.mies == d.mies && g->data.rok == d.rok)				//warunek na usuniecie dnia ktory jest glowa
		{
			
			while (g->lista != NULL)
			{
				temp = g->lista->nast;
				delete g->lista;
				g->lista = temp;
			}
			tempd = g->nast;
			delete g;
			g = tempd;
			return;
		}
		while ((im->nast->data.dz != d.dz && im->nast->data.mies != d.mies && im->nast->data.rok != d.rok) && (im->nast->nast != NULL))
		{
			im = im->nast;
		}

		if (im->nast->data.dz == d.dz && im->nast->data.mies == d.mies && im->nast->data.rok == d.rok)
		{
			while (im->nast->lista != NULL)											//usuniecie listy podwieszanej przed usunieciem calego elementu
			{
				temp = im->nast->lista->nast;
				delete im->nast->lista;
				im->nast->lista = temp;
			}

			tempd = im->nast->nast;													//usuniecie elementu
			delete im->nast;
			im->nast = tempd;
			return;
			
			
		}
		else
			cout << "Nie ma takiego dnia" << endl;


		break;
	}

	

}





int main()
{
	dzien*glowa = NULL;
	fstream plik;
	string s; 
	
	cout << "TERMINARZ" << endl; 
	cout << "Wybierz opcje:" << endl;
	cout << "[1].Wyswietl terminarz " << endl; cout << "[2].Dodaj wydarzenie " << endl; 
	cout << "[3].Usun wydarzenie " << endl; cout << "[0]. Wyscie z programu " << endl; cout << endl;
	

	plik.open("kk.txt", ios_base::in);		//otworznie pliku
	if(plik.good())
	{
		
		while (!plik.eof()) {
			czytaj(glowa, plik);			//wczytynie zawartosci pliku do pamieci

		} 
	}else 
	{
		cout << "Witaj w programie. Utworzono nowy plik" << endl; //informacja o stworzeniu pliku ktoru wczesniej nie istnial
	}
	
	
	
	int wybor1, wybor;
	do {
		cin >> wybor;
		switch (wybor)
		{
		case 1:
			wypisz(glowa); cout << endl; cout << endl;
			break;
		case 2:
			 dodajds(glowa, wczytajs()); cout << endl; cout << endl;
			break;
		case 3:
			usun(glowa);
			break;
		default:
			cout << "Nie wybrales zadnej opcji. Spobuj jeszcze raz" << endl;
			break;
		}
	  cin.clear();
	  cout << endl;
	  cout << "Wybierz opcje:" << endl;
	  cout << "[1].Wyswietl " << endl; cout << "[2]. Dodaj wydarzenie " << endl; 
	  cout << "[3]. Usun wydarzenie " << endl; cout<< "[0]. Wyscie z programu " << endl; cout << endl;

	} while (wybor != 0);


	zapisz(glowa, plik);		//zapisanie do pliku 
	
		
	 cin.get(); plik.close();
	return 0;
}
