#include <iostream>
#include <time.h>

using namespace std;

const int roz = 10;
int t1[roz], t2[roz], t3[roz];


void Wypisz(int t[], int roz)
{
	for (int i = 0; i < roz; i++)
		cout << t[i] << " ";
	cout << endl;
}

void Stworz(int t[], int roz)
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


void Dodawanie(int t1[], int t2[], int t3[], int roz)
{
	int q=0;
	for (int i = roz - 1; i >= 0; i--)
	{
		t3[i] =q + t1[i] + t2[i];
		if ((t3[i] > 9)&&(!t3[0]))
		{
			q = t3[i] / 10;
			t3[i] = t3[i] % 10;
		}
		else q = 0;
		
	}

} 



void Odejmowanie(int t1[], int t2[], int t3[], int roz)
{
	int q = 0;
	for (int i = roz - 1; i >= 0; i--)
	{
		if (t2[i] > t1[i])
		{
			t1[i] += 10;
			--t1[i - 1];
			
		}
		t3[i] = t1[i] - t2[i];

	}
}





int main()
{
	srand(time(NULL));
	cout << "tablica 1: ";
	Stworz(t1, roz);
	cout << "tablica 2: ";
	Stworz(t2, roz);
	//Dodawanie(t1, t2,t3, roz);
	cout << "tablica 3: ";
	//Wypisz(t3, roz);
	Odejmowanie(t1, t2, t3, roz);
	Wypisz(t3, roz);
	cin.get();
	return 1;
}
