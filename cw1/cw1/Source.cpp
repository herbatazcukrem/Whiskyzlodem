//Wype�nianie tablicy xnax liczbami w k�eczko

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

		--k;											// 1) licznik z p�tli wychodzi zwi�kszony o 1
		w++;											//przej�cie do nast�pnego wersu

		for (w; w < l; w++)
		{
			t[w][k] = q;
			q++;
		}
		--w;											// 1)
		k--;											//przej�cie do nast�pnej kolumny
		
		for (k; k > r-1; k--)
		{
			t[w][k] = q;
			q++;
		}
		k = r;											//przeniesienie dla nast�pnej kolumny
		w--;											//przej�cie do nast�pnego wersu
		
		for (w; w> r; w--)
		{
			t[w][k] = q;
			q++;
		}
														//zmniejszenie  ilo�ci liczb 
		l = l - 1;
	

	}
	
	

	for (w = 0; w < 10; w++)
		{for (k= 0; k < 10; k++)
			cout << t[w][k] << " ";
		cout << endl;}

	cin.get();
	return 0;
}

