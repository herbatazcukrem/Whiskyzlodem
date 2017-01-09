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


int main()
{
	sdzien k1;
	sdzien k2;
	cin >> k1.dz >> k1.mies >> k1.rok;
	cin >> k2.dz >> k2.mies >> k2.rok;
	cout << k1.dz << "." << k1.mies << "." << k1.rok<<endl;
	cout << k2.dz << "." << k2.mies << "." << k2.rok<<endl;
	
	if (k1.rok == k2.rok)
	
		
		if (k1.mies = k2.mies)
		{
			if (k1.dz > k2.dz)
			{
				
				cout << k1.dz << "." << k1.mies << "." << k1.rok << "k1.dz = k2.dz";
			}
			else
			{
				if (k1.dz > k2.dz)
					cout << k1.dz << "." << k1.mies << "." << k1.rok<<"k1.dz > k2.dz)";
				else cout << k2.dz << "." << k2.mies << "." << k2.rok<<"else k1.dz > k2.dz";

			}
		}
		else
			{
				if (k1.mies > k2.mies)
					cout << k1.dz << "." << k1.mies << "." << k1.rok<<"k1.mies > k2.mies";
				else cout << k2.dz << "." << k2.mies << "." << k2.rok<<" else k1.mies > k2.mies" ;
			}
		
	
	else if (k1.rok > k2.rok)
		cout << k1.dz << "." << k1.mies << "." << k1.rok<<"k1.rok > k2.rok";
		else  cout << k2.dz << "." << k2.mies << "." << k2.rok << "else k1.rok > k2.rok";
	
	cin.get(); cin.get();
	return 0;
}