//Wype³nianie tablicy xnax liczbami w kó³eczko

#include<iostream>
using namespace std;



int main()
{
	int t[10][10];
	int q,k,w,l;
	 k=w=0;
	 q = 100;
	for (k = 0; k < 10; k++)
		for ( w = 0; w < 10; w++)
			t[w][k] = 0; 	
	k = w = 0;
	l = 10;
	for (int r = 0; r < 6; r++)
	{
		w = k = r;
		for (k; k < l; k++)
		{
			t[w][k] = q;
			q++;
		}

		--k;											// 1) licznik z pêtli wychodzi zwiêkszony o 1
		w++;											//przejœcie do nastêpnego wersu

		for (w; w < l; w++)
		{
			t[w][k] = q;
			q++;
		}
		--w;											// 1)
		k--;											//przejœcie do nastêpnej kolumny
		
		for (k; k > r-1; k--)
		{
			t[w][k] = q;
			q++;
		}
		k = r;											//przeniesienie dla nastêpnej kolumny
		w--;											//przejœcie do nastêpnego wersu
		
		for (w; w> r; w--)
		{
			t[w][k] = q;
			q++;
		}
														//zmniejszenie  iloœci liczb 
		l = l - 1;
	

	}
	
	

	for (w = 0; w < 10; w++)
		{for (k= 0; k < 10; k++)
			cout << t[w][k] << " ";
		cout << endl;}

	cin.get();
	return 0;
}

