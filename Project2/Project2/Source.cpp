#include <time.h>
#include <iostream>
#include <windows.h>

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


bool porwnajd(sdzien k1, sdzien k2)
{
	if (k1.rok == k2.rok)
		if (k1.mies == k2.mies)
		{
			if (k1.dz > k2.dz)
			{cout << k1.dz << "." << k1.mies << "." << k1.rok << "k1.dz = k2.dz"; return true;}
			else
			{
				if (k1.dz > k2.dz)
				{cout << k1.dz << "." << k1.mies << "." << k1.rok << "k1.dz > k2.dz)"; return true;}
				else { cout << k2.dz << "." << k2.mies << "." << k2.rok << "else k1.dz > k2.dz"; return false; }
			}
		}
		else
		{
			if (k1.mies > k2.mies)
			{cout << k1.dz << "." << k1.mies << "." << k1.rok << "k1.mies > k2.mies"; return true;}
			else { cout << k2.dz << "." << k2.mies << "." << k2.rok << " else k1.mies > k2.mies"; return false; }
		}


	else if (k1.rok > k2.rok)
	{cout << k1.dz << "." << k1.mies << "." << k1.rok << "k1.rok > k2.rok"; return true;}
	else { cout << k2.dz << "." << k2.mies << "." << k2.rok << "else k1.rok > k2.rok"; return false; }


}


bool porwnajg(sgodz k1, sgodz k2)
{
	
		if (k1.godz == k2.godz)
		{
			if (k1.min > k2.min)
			{

				cout << k1.godz << ":" << k1.min ; return true;
			}
			else
			{
				if (k1.min > k2.min)
				{
					cout << k1.godz << ":" << k1.min; return true;
				}
				else { cout << k2.godz << ":" << k2.min ; return false; }

			}
		}
		else
		{
			if (k1.godz > k2.godz)
			{
				cout << k1.godz<< ":" << k1.min; return true;
			}
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


void wypiszd(sdzien k)
{
	cout << k.dz << "." << k.mies << "." << k.rok << endl;
}


sgodz wczytajg()
{
	sgodz k;
	cout << "godzina: ";  cin >> k.godz;
	cout << "minuty: ";  cin >> k.min;
	
	return k;
}


void wypiszg(sgodz k)
{
	cout << k.godz << ":" << k.min <<  endl;
}
int main()
{
	sdzien k1;
	sdzien k2;
	sgodz p1;
	sgodz p2;
//	cin >> k1.dz>> k1.mies >> k1.rok;
	//cin >> k2.dz >> k2.mies >> k2.rok;
	//cout << k1.dz << "." << k1.mies << "." << k1.rok<<endl;
	//cout << k2.dz << "." << k2.mies << "." << k2.rok<<endl;
	k1=wczytajs();
	wypiszd(k1);
	k2 = wczytajs();
	wypiszd(k2);
//	cin >> p1.godz >> p1.min;
//	cin >> p2.godz >> p2.min;
//	if (porwnajg(p1, p2))
//		cout << "wieksza k1";
//	else cout << "mniejsza k1";

	
	if (porwnajd(k1, k2))
		cout << "wieksza k1";
	else cout << "mniejsza k1";


	cin.get(); cin.get();
	return 0;
}