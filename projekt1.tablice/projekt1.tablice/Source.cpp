#include <iostream>
#include <time.h>

using namespace std;

const int roz = 1000;

const int roz2 = 2000;
int t1[roz], t2[roz], t3[roz], t4[2 * roz] = { 0 };

void Wypisz(int t[], int roz)						// dopisaæ niewypisywanie nieznacz¹cych zer z przodu
{

	for (int i = 0; i < roz; i++)
		
		cout << t[i] << " ";
	cout << endl;
}

void Stworz(int t[], int roz)						//OK
{
	t[0] = rand() % 9 + 1;
	for (int i = 1; i < roz; i++)
	{
		t[i] = rand() % 10;	
	}

	for (int i = 0; i < roz; i++)
		cout << t[i] << " ";
	cout << endl;
}


void Dodawanie(int t1[], int t2[], int t3[], int roz)	//OK
{

	int q=0;
	for (int i = roz - 1; i >= 0; i--)
	{
		t3[i] =q + t1[i] + t2[i];
		if ((t3[i] > 9)&&(i!=0))
		{
			q = t3[i] / 10;
			t3[i] = t3[i] % 10;
		}
		else q = 0;
		
	}

} 



void Odejmowanie(int t1[], int t2[], int t3[], int roz)			//
{
	
	
	for (int i = roz - 1; i >= 0; i--)
	{
		if ((t2[i] > t1[i]) && (i!=0))
		{
			t1[i] += 10; 
			--t1[i - 1]; 			
		}
		
		t3[i] = t1[i] - t2[i];

	}
}


void Mnozenie(int t1[], int t2[], int t3[])
{
	
	int t[roz2] = { 0 };
	cout << "roz " << roz << "    roz2 " << roz2<<endl;
	int k = roz2-1; int u = roz2-1; int l = 0; int p = 0;
	for (int i = roz - 1; i >= 0; i--)
	{
		
		for (int j = roz - 1; j >= 0; j--)
		{

			//k =cout << k << "   ";
			t[u] = t2[i] * t1[j]; // k; cout << t[u] << endl;
			u--;
		}
	
	//	Wypisz(t, roz2);
		Dodawanie(t, t3, t3, roz2);
		t[k]=0;
		k--;
		u = k;
		
	}

	cout << "ble" << endl;


}


int main()
{
//	const int *rozmiar = &roz;
	srand(time(NULL));
	cout << "tablica 1: ";
	Stworz(t1, roz);
	cout << "tablica 2: ";
	Stworz(t2, roz);
	//Dodawanie(t1, t2,t3, roz);
	//cout << "tablica 3: ";
	//Wypisz(t3, roz);
	//Odejmowanie(t1, t2, t3, roz);
	Mnozenie(t1, t2, t4);
	cout << "tablica 3: ";
	Wypisz(t4, 2*roz);
	cin.get();
	return 1;
}
