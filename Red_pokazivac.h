#include "stdafx.h"
#include <iostream>
#include <cstring>

using namespace  std;

struct klijent
{
  string ime;
	string datum;
	int tekRacun;
	int devRacun;
	int ai, bi, ci, di;
	klijent * next;
};

klijent * root;
klijent * pocetak;
klijent * kraj;

static klijent* pocetakQ()
{
	
	 if (pocetak!=kraj)
	 {
		 klijent * temp = root;
		 while (temp->next!=root) temp=temp->next;
		 return temp;

	 }
	 else 
	 {
		 cout<<"\nRed prazan."<<endl;
		 exit (0);
	 }

}

static void EnQueue(klijent novi)
{
	if (pocetak!=kraj)
	{
		novi.next = root;
		klijent * temp = root;
		while (temp->next!=root) temp=temp->next;
		temp->next = &novi;

	}
	else 
	cout<<"\nRed prazan"<<endl;

}

static void DeQueue()
{
	if (pocetak!=kraj)
	{
		klijent * temp = root;
		while (temp->next->next!=root) temp=temp->next;
		temp->next = root;

	}
	else 
	cout<<"\nRed prazan"<<endl;

}

static void InitQ()
{
	pocetak=kraj;

}

