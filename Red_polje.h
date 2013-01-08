#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <ctime>
#include <Windows.h>
using namespace std;



struct klijent
{
  string ime, prezime, ci, di;
	int godinaR, ai, bi;
	int tekRacun;
	int devRacun;
	int starost;
	string stanje;
	string transakcija;

};

int IZ=0;
klijent * kutija=new klijent[200];
klijent * kutija2=new klijent[200];
int pocetak = 0, kraj = 0, brojac=0;


int randomN ()
{
	int Rbroj;
	srand ( time(NULL) );
	 Rbroj = rand() % 400 + 100;

	 return Rbroj;
}

int randomN2 ()
{
top:
	Sleep(1000);
	int Rbroj2;
	srand ( time(NULL) );
	 Rbroj2 = rand() % 100 + 100;
	 Rbroj2+= rand() % 100 + 1;
	 Rbroj2+= rand() % 100 + 1;
	 Rbroj2+= rand() % 100 + 1;
	 if(Rbroj2>500)
		 goto top;
	 else
	 return Rbroj2;
}

int prioritet ()
{
	int prio;
	srand ( time(NULL) );
	 prio = rand() % 6 + 1;

	 return prio;
}

int transakcija ()
{
	int trans;
	srand ( time(NULL) );
	 trans = rand() % 4 + 1;

	 return trans;
}

static void InitQ ()
{
	pocetak=0;
	kraj=0;
	
}

static void EnQueueQ ()
{
	
	klijent x;
	cout<<"Ime: ";
	cin>>x.ime;
	cout<<"Prezime: ";
	cin>>x.prezime;
	cout<<"Godina rodjenja: ";
	cin>>x.godinaR;
	x.starost=2013-x.godinaR;
	x.ai=randomN();
	x.bi=randomN2();
	opet:
	prioritet();
	if (prioritet()==1)
	{
		x.ci="umirovljeni";
	}
	else if (prioritet()==2)
	{
		x.ci="invalid";
	}
	else if (prioritet()==3)
	{
		x.ci="trudnica";
	}
	else if (prioritet()==4)
	{
		x.ci="VIP";
	}
	else if (prioritet()==5)
	{
		x.ci="obican klijent";
	}
	else if (prioritet()==6)
	{
		x.ci="nije klijent";
	}


	transakcija();
	if (transakcija()==1)
	{
		x.di="uplata";
	}
	else if (transakcija()==2 && prioritet()!=6)
	{
		x.di="isplata";
	}
	else if (transakcija()==3)
	{
		x.di="placanje";
	}
	else if (transakcija()==4)
	{
		x.di="kredit";
	}
	else goto opet;
	
	cout<<"Stanje tekuceg racuna: ";
	cin>>x.tekRacun;

	cout<<"Stanje deviznog racuna: ";
	cin>>x.devRacun;

	kutija[kraj]=x;
	kraj ++;
}

static void FrontQ ()
{
	cout<<"Ime: "<<kutija[pocetak].ime<<endl;
	cout<<"Prezime: "<<kutija[pocetak].prezime<<endl;
	cout<<"Starost: "<<kutija[pocetak].starost<<endl;
	cout<<"Stanje klijenta: "<<kutija[pocetak].ci<<endl;
	cout<<"Transakcija: "<<kutija[pocetak].di<<endl;
	cout<<"Tekuci racun klijenta: "<<kutija[pocetak].tekRacun<<endl;
	cout<<"Devizni racun klijenta: "<<kutija[pocetak].devRacun<<" USD"<<endl;

	cout<<"ISPIS: "<<" ai: "<<kutija[pocetak].ai<<" bi: "<<kutija[pocetak].bi<<endl;
}

static void IspisKl ()
{
	float kn;
	for(int i=0; i<kraj; i++)
	{
		kn=kutija[pocetak].devRacun*6;
		if(kn>10000)
		{
			FrontQ ();
			pocetak++;
		}
		else cout<<endl;
	}
	pocetak=0;
}

static void unosUred ()
{
	
	brojac=0;
	for (int i = 0; i < kraj; i++)
	{
		if (kutija[i].ci=="umirovljeni")
		{
			kutija2[brojac].ime = kutija[i].ime;
			kutija2[brojac].prezime = kutija[i].prezime;
			kutija2[brojac].starost = kutija[i].starost;
			kutija2[brojac].ci = kutija[i].ci;
			kutija2[brojac].di = kutija[i].di;
			kutija2[brojac].tekRacun = kutija[i].tekRacun;
			kutija2[brojac].devRacun = kutija[i].devRacun;

			kutija2[brojac].ai = kutija[i].ai;
			kutija2[brojac].bi = kutija[i].bi;
			brojac++;
		}
	}
	for (int i = 0; i < kraj; i++)
	{
		if (kutija[i].ci=="invalid")
		{
			kutija2[brojac].ime = kutija[i].ime;
			kutija2[brojac].prezime = kutija[i].prezime;
			kutija2[brojac].starost = kutija[i].starost;
			kutija2[brojac].ci = kutija[i].ci;
			kutija2[brojac].di = kutija[i].di;
			kutija2[brojac].tekRacun = kutija[i].tekRacun;
			kutija2[brojac].devRacun = kutija[i].devRacun;

			kutija2[brojac].ai = kutija[i].ai;
			kutija2[brojac].bi = kutija[i].bi;
			brojac++;
		}
	}
	for (int i = 0; i < kraj; i++)
	{
		if (kutija[i].ci=="trudnica")
		{
			kutija2[brojac].ime = kutija[i].ime;
			kutija2[brojac].prezime = kutija[i].prezime;
			kutija2[brojac].starost = kutija[i].starost;
			kutija2[brojac].ci = kutija[i].ci;
			kutija2[brojac].di = kutija[i].di;
			kutija2[brojac].tekRacun = kutija[i].tekRacun;
			kutija2[brojac].devRacun = kutija[i].devRacun;

			kutija2[brojac].ai = kutija[i].ai;
			kutija2[brojac].bi = kutija[i].bi;
			brojac++;
		}
	}
	for (int i = 0; i < kraj; i++)
	{
		if (kutija[i].ci=="VIP")
		{
			kutija2[brojac].ime = kutija[i].ime;
			kutija2[brojac].prezime = kutija[i].prezime;
			kutija2[brojac].starost = kutija[i].starost;
			kutija2[brojac].ci = kutija[i].ci;
			kutija2[brojac].di = kutija[i].di;
			kutija2[brojac].tekRacun = kutija[i].tekRacun;
			kutija2[brojac].devRacun = kutija[i].devRacun;

			kutija2[brojac].ai = kutija[i].ai;
			kutija2[brojac].bi = kutija[i].bi;
			brojac++;
		}
	}
	for (int i = 0; i < kraj; i++)
	{
		if (kutija[i].ci=="obican klijent")
		{
			kutija2[brojac].ime = kutija[i].ime;
			kutija2[brojac].prezime = kutija[i].prezime;
			kutija2[brojac].starost = kutija[i].starost;
			kutija2[brojac].ci = kutija[i].ci;
			kutija2[brojac].di = kutija[i].di;
			kutija2[brojac].tekRacun = kutija[i].tekRacun;
			kutija2[brojac].devRacun = kutija[i].devRacun;

			kutija2[brojac].ai = kutija[i].ai;
			kutija2[brojac].bi = kutija[i].bi;
			brojac++;
		}
	}
	for (int i = 0; i < kraj; i++)
	{
		if (kutija[i].ci=="nije klijent")
		{
			kutija2[brojac].ime = kutija[i].ime;
			kutija2[brojac].prezime = kutija[i].prezime;
			kutija2[brojac].starost = kutija[i].starost;
			kutija2[brojac].ci = kutija[i].ci;
			kutija2[brojac].di = kutija[i].di;
			kutija2[brojac].tekRacun = kutija[i].tekRacun;
			kutija2[brojac].devRacun = kutija[i].devRacun;

			kutija2[brojac].ai = kutija[i].ai;
			kutija2[brojac].bi = kutija[i].bi;
			brojac++;
		}
	}
}

static void ispisReda ()
{
	unosUred();
	for (int i = 0; i < brojac; i++)
	{
		cout<<"Broj u redu: "<<i+1<<". "<<endl;
		cout<<"Ime: "<<kutija2[i].ime<<endl;
		cout<<"Prezime: "<<kutija2[i].prezime<<endl;
		cout<<"Starost: "<<kutija2[i].starost<<endl;
		cout<<"Stanje klijenta: "<<kutija2[i].ci<<endl;
		cout<<"Transakcija: "<<kutija2[i].di<<endl;
		cout<<"Tekuci racun klijenta: "<<kutija2[i].tekRacun<<endl;
		cout<<"Devizni racun klijenta: "<<kutija2[i].devRacun<<" USD"<<endl;
			
	}
}

static void unosUredbrzi ()
{
	
	brojac=0;
	for (int i = 0; i < kraj; i++)
	{
		if (kutija[i].ci=="umirovljeni")
			if(kutija[i].di!="placanje")
		{
			kutija2[brojac].ime = kutija[i].ime;
			kutija2[brojac].prezime = kutija[i].prezime;
			kutija2[brojac].starost = kutija[i].starost;
			kutija2[brojac].ci = kutija[i].ci;
			kutija2[brojac].di = kutija[i].di;
			kutija2[brojac].tekRacun = kutija[i].tekRacun;
			kutija2[brojac].devRacun = kutija[i].devRacun;

			kutija2[brojac].ai = kutija[i].ai;
			kutija2[brojac].bi = kutija[i].bi;
			brojac++;
		}
	}
	for (int i = 0; i < kraj; i++)
	{
		if (kutija[i].ci=="invalid")
			if(kutija[i].di!="placanje")
		{
			kutija2[brojac].ime = kutija[i].ime;
			kutija2[brojac].prezime = kutija[i].prezime;
			kutija2[brojac].starost = kutija[i].starost;
			kutija2[brojac].ci = kutija[i].ci;
			kutija2[brojac].di = kutija[i].di;
			kutija2[brojac].tekRacun = kutija[i].tekRacun;
			kutija2[brojac].devRacun = kutija[i].devRacun;

			kutija2[brojac].ai = kutija[i].ai;
			kutija2[brojac].bi = kutija[i].bi;
			brojac++;
		}
	}
	for (int i = 0; i < kraj; i++)
	{
		if (kutija[i].ci=="trudnica")
			if(kutija[i].di!="placanje")
		{
			kutija2[brojac].ime = kutija[i].ime;
			kutija2[brojac].prezime = kutija[i].prezime;
			kutija2[brojac].starost = kutija[i].starost;
			kutija2[brojac].ci = kutija[i].ci;
			kutija2[brojac].di = kutija[i].di;
			kutija2[brojac].tekRacun = kutija[i].tekRacun;
			kutija2[brojac].devRacun = kutija[i].devRacun;

			kutija2[brojac].ai = kutija[i].ai;
			kutija2[brojac].bi = kutija[i].bi;
			brojac++;
		}
	}
	for (int i = 0; i < kraj; i++)
	{
		if (kutija[i].ci=="VIP")
			if(kutija[i].di!="placanje")
		{
			kutija2[brojac].ime = kutija[i].ime;
			kutija2[brojac].prezime = kutija[i].prezime;
			kutija2[brojac].starost = kutija[i].starost;
			kutija2[brojac].ci = kutija[i].ci;
			kutija2[brojac].di = kutija[i].di;
			kutija2[brojac].tekRacun = kutija[i].tekRacun;
			kutija2[brojac].devRacun = kutija[i].devRacun;

			kutija2[brojac].ai = kutija[i].ai;
			kutija2[brojac].bi = kutija[i].bi;
			brojac++;
		}
	}
	for (int i = 0; i < kraj; i++)
	{
		if (kutija[i].ci=="obican klijent")
			if(kutija[i].di!="placanje")
		{
			kutija2[brojac].ime = kutija[i].ime;
			kutija2[brojac].prezime = kutija[i].prezime;
			kutija2[brojac].starost = kutija[i].starost;
			kutija2[brojac].ci = kutija[i].ci;
			kutija2[brojac].di = kutija[i].di;
			kutija2[brojac].tekRacun = kutija[i].tekRacun;
			kutija2[brojac].devRacun = kutija[i].devRacun;

			kutija2[brojac].ai = kutija[i].ai;
			kutija2[brojac].bi = kutija[i].bi;
			brojac++;
		}
	}
	for (int i = 0; i < kraj; i++)
	{
		if (kutija[i].ci=="nije klijent")
			if(kutija[i].di!="placanje")
		{
			kutija2[brojac].ime = kutija[i].ime;
			kutija2[brojac].prezime = kutija[i].prezime;
			kutija2[brojac].starost = kutija[i].starost;
			kutija2[brojac].ci = kutija[i].ci;
			kutija2[brojac].di = kutija[i].di;
			kutija2[brojac].tekRacun = kutija[i].tekRacun;
			kutija2[brojac].devRacun = kutija[i].devRacun;

			kutija2[brojac].ai = kutija[i].ai;
			kutija2[brojac].bi = kutija[i].bi;
			brojac++;
		}
	}
}

static void brziRed ()
{
	brojac=0;
	for (int i = 0; i < kraj; i++)
	{
		if (kutija[i].di=="placanje")
		{
			kutija2[brojac].ime = kutija[i].ime;
			kutija2[brojac].prezime = kutija[i].prezime;
			kutija2[brojac].starost = kutija[i].starost;
			kutija2[brojac].ci = kutija[i].ci;
			kutija2[brojac].di = kutija[i].di;
			kutija2[brojac].tekRacun = kutija[i].tekRacun;
			kutija2[brojac].devRacun = kutija[i].devRacun;

			kutija2[brojac].ai = kutija[i].ai;
			kutija2[brojac].bi = kutija[i].bi;
			brojac++;
		}
	}
	for (int i = 0; i < brojac; i++)
	{
		cout<<"Broj u redu: "<<i+1<<". "<<endl;
		cout<<"Ime: "<<kutija2[i].ime<<endl;
		cout<<"Prezime: "<<kutija2[i].prezime<<endl;
		cout<<"Starost: "<<kutija2[i].starost<<endl;
		cout<<"Stanje klijenta: "<<kutija2[i].ci<<endl;
		cout<<"Transakcija: "<<kutija2[i].di<<endl;
		cout<<"Tekuci racun klijenta: "<<kutija2[i].tekRacun<<endl;
		cout<<"Devizni racun klijenta: "<<kutija2[i].devRacun<<" USD"<<endl;
			
	}

	unosUredbrzi();
	cout<<"---| Stanje uredu |---"<<endl;
	for (int i = 0; i < brojac; i++)
	{
		cout<<"Broj u redu: "<<i+1<<". "<<endl;
		cout<<"Ime: "<<kutija2[i].ime<<endl;
		cout<<"Prezime: "<<kutija2[i].prezime<<endl;
		cout<<"Starost: "<<kutija2[i].starost<<endl;
		cout<<"Stanje klijenta: "<<kutija2[i].ci<<endl;
		cout<<"Transakcija: "<<kutija2[i].di<<endl;
		cout<<"Tekuci racun klijenta: "<<kutija2[i].tekRacun<<endl;
		cout<<"Devizni racun klijenta: "<<kutija2[i].devRacun<<" USD"<<endl;
			
	}
}

static void ispisRedaBezVIP ()
{
	brojac=0;
	for (int i = 0; i < kraj; i++)
	{
		if (kutija[i].ci=="umirovljeni")
			if(kutija[i].ci!="VIP" && kutija[i].starost>30 && kutija[i].di!="uplata" && kutija[i].tekRacun>100)
				if(kutija[i].ci!="umirovljeni" && kutija[i].tekRacun<5000 && kutija[i].di!="isplata")
		{
			kutija2[brojac].ime = kutija[i].ime;
			kutija2[brojac].prezime = kutija[i].prezime;
			kutija2[brojac].starost = kutija[i].starost;
			kutija2[brojac].ci = kutija[i].ci;
			kutija2[brojac].di = kutija[i].di;
			kutija2[brojac].tekRacun = kutija[i].tekRacun;
			kutija2[brojac].devRacun = kutija[i].devRacun;

			kutija2[brojac].ai = kutija[i].ai;
			kutija2[brojac].bi = kutija[i].bi;
			brojac++;
		}
	}
	for (int i = 0; i < kraj; i++)
	{
		if (kutija[i].ci=="invalid")
			if(kutija[i].ci!="VIP" && kutija[i].starost>30 && kutija[i].di!="uplata" && kutija[i].tekRacun>100)
				if(kutija[i].ci!="umirovljeni" && kutija[i].tekRacun<5000 && kutija[i].di!="isplata")
		{
			kutija2[brojac].ime = kutija[i].ime;
			kutija2[brojac].prezime = kutija[i].prezime;
			kutija2[brojac].starost = kutija[i].starost;
			kutija2[brojac].ci = kutija[i].ci;
			kutija2[brojac].di = kutija[i].di;
			kutija2[brojac].tekRacun = kutija[i].tekRacun;
			kutija2[brojac].devRacun = kutija[i].devRacun;

			kutija2[brojac].ai = kutija[i].ai;
			kutija2[brojac].bi = kutija[i].bi;
			brojac++;
		}
	}
	for (int i = 0; i < kraj; i++)
	{
		if (kutija[i].ci=="trudnica")
			if(kutija[i].ci!="VIP" && kutija[i].starost>30 && kutija[i].di!="uplata" && kutija[i].tekRacun>100)
				if(kutija[i].ci!="umirovljeni" && kutija[i].tekRacun<5000 && kutija[i].di!="isplata")
		{
			kutija2[brojac].ime = kutija[i].ime;
			kutija2[brojac].prezime = kutija[i].prezime;
			kutija2[brojac].starost = kutija[i].starost;
			kutija2[brojac].ci = kutija[i].ci;
			kutija2[brojac].di = kutija[i].di;
			kutija2[brojac].tekRacun = kutija[i].tekRacun;
			kutija2[brojac].devRacun = kutija[i].devRacun;

			kutija2[brojac].ai = kutija[i].ai;
			kutija2[brojac].bi = kutija[i].bi;
			brojac++;
		}
	}
	for (int i = 0; i < kraj; i++)
	{
		if (kutija[i].ci=="VIP")
			if(kutija[i].ci!="VIP" && kutija[i].starost>30 && kutija[i].di!="uplata" && kutija[i].tekRacun>100)
				if(kutija[i].ci!="umirovljeni" && kutija[i].tekRacun<5000 && kutija[i].di!="isplata")
		{
			kutija2[brojac].ime = kutija[i].ime;
			kutija2[brojac].prezime = kutija[i].prezime;
			kutija2[brojac].starost = kutija[i].starost;
			kutija2[brojac].ci = kutija[i].ci;
			kutija2[brojac].di = kutija[i].di;
			kutija2[brojac].tekRacun = kutija[i].tekRacun;
			kutija2[brojac].devRacun = kutija[i].devRacun;

			kutija2[brojac].ai = kutija[i].ai;
			kutija2[brojac].bi = kutija[i].bi;
			brojac++;
		}
	}
	for (int i = 0; i < kraj; i++)
	{
		if (kutija[i].ci=="obican klijent")
			if(kutija[i].ci!="VIP" && kutija[i].starost>30 && kutija[i].di!="uplata" && kutija[i].tekRacun>100)
				if(kutija[i].ci!="umirovljeni" && kutija[i].tekRacun<5000 && kutija[i].di!="isplata")
		{
			kutija2[brojac].ime = kutija[i].ime;
			kutija2[brojac].prezime = kutija[i].prezime;
			kutija2[brojac].starost = kutija[i].starost;
			kutija2[brojac].ci = kutija[i].ci;
			kutija2[brojac].di = kutija[i].di;
			kutija2[brojac].tekRacun = kutija[i].tekRacun;
			kutija2[brojac].devRacun = kutija[i].devRacun;

			kutija2[brojac].ai = kutija[i].ai;
			kutija2[brojac].bi = kutija[i].bi;
			brojac++;
		}
	}
	for (int i = 0; i < kraj; i++)
	{
		if (kutija[i].ci=="nije klijent")
			if(kutija[i].ci!="VIP" && kutija[i].starost>30 && kutija[i].di!="uplata" && kutija[i].tekRacun>100)
				if(kutija[i].ci!="umirovljeni" && kutija[i].tekRacun<5000 && kutija[i].di!="isplata")
		{
			kutija2[brojac].ime = kutija[i].ime;
			kutija2[brojac].prezime = kutija[i].prezime;
			kutija2[brojac].starost = kutija[i].starost;
			kutija2[brojac].ci = kutija[i].ci;
			kutija2[brojac].di = kutija[i].di;
			kutija2[brojac].tekRacun = kutija[i].tekRacun;
			kutija2[brojac].devRacun = kutija[i].devRacun;

			kutija2[brojac].ai = kutija[i].ai;
			kutija2[brojac].bi = kutija[i].bi;
			brojac++;
		}
	}
}
