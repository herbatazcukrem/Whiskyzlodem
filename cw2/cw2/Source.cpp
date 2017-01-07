#include <iostream>
#include <time.h>
#include<math.h>
using namespace std;

struct s
{
	s* next;
	int w;
};


s* Dodaj(s*h, int i)
{
	s*temp = new s;
	temp->w = i;
	temp->next = h;
	
	return temp;
}

s* DodajKoniec(s*h, int i)
{
	s*temp1 = new s;
	
	temp1->w = i;
	temp1->next = NULL;

	if (h == NULL)
		return temp1;
	s*temp2 = h;
	while (temp2->next != NULL)
		temp2 = temp2->next;
	temp2->next = temp1;
	return h;

}


s*DodajSort(s*h, int i)
{
	s*temp1 = new s;
	temp1->w = i;
	s*temp2 = h;
	s*temp3;
	bool  bylazmiana = false;
	
	if (h == NULL) 
		return temp1;
	
	//cout << temp1->w << " " << temp2->w << endl;
	while (!bylazmiana)
	{
		bylazmiana = false;
		//while (temp2->next != NULL)
		//{
			if ((temp1->w) < (temp2->w))
			{
				temp3 = temp2;
				temp2 = temp1;
				temp1 = temp3;
				bylazmiana = true;
			
			//}//	cout << temp1->w << " " << temp2->w << endl;
				if (temp2->next != NULL) temp2 = temp2->next; else break;
		}
		

			//cout << temp1->w << " " << temp2->w << endl;
	}
	return temp1;
}

void Wypisz(s*h)
{
	while (h) {

		cout << h->w << endl;
		h = h->next;
	}
}


int main()
{
	srand(time(NULL));
	s*head = NULL;
	for (int i = 0; i < 4; i++)
		head = DodajSort(head, rand()%100);
	Wypisz(head);

	
	//head= Dodaj(head, 15);
	//Wypisz(head);
	//head= DodajKoniec(head, 100); cout << endl; 
	//Wypisz(head);
	cin.get();
	return 1;
}
