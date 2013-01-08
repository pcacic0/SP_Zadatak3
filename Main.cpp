#include "stdafx.h"
#include <iostream>
#include "Red_Polje.h"
//#include "Red_Pokazivac.h"

using namespace std;

int main()
{
  int izbor;
	do
	{
		cout<<"----------------------------------| IZBORNIK |------------------------------"<<endl;
		cout<<"1. Generiraj red."<<endl;
		cout<<"2. Unesi osobne podatke klijenata."<<endl;
		cout<<"3. Ispisi sve koji imaju na racunu preko 10.000 kn."<<endl;
		cout<<"4. Simulacija reda brzih transakcija."<<endl;
		cout<<"5. Izbaci iz reda sve VIP korisnike koji imaju manje od 30 godina\n\ti zeljeli bi uplatiti novac, a imaju manje od 100 kn \n\tTe umirovljenike koji zele obaviti isplatu a imaju vise od 5000 kn."<<endl;
		cout<<"6. Ispisi stanje u redu."<<endl;
		cout<<"9. Kraj programa.\n\n"<<endl;
		cin>>izbor;

		switch (izbor)
		{
		case 1:
			InitQ ();
			cout<<"Generiran je red."<<endl;
			break;
		case 2:
			{
				char IZ;
				cout<<"Unesite podatke o klijentu na kraju reda:"<<endl;
				EnQueueQ ();
				cout<<"Klijent je u redu."<<endl;
				
				cout<<"Zelite li ispis prvog klijenta u redu? Y/N"<<endl;
				cin>>IZ;
				if (IZ=='y'||IZ=='Y')
				{
					cout<<"Prvi klijent je:\n ";
					FrontQ ();
				}else if (IZ=='n'||IZ=='N') cout<<"Ok..."<<endl;
				
				break;
			}
		case 3:
			{
				cout<<"Klijenti sa preko 10.000 kn na racunu su: "<<endl;
				IspisKl ();
				break;
			}
		case 4:
			{
				cout<<"---| Stanje brzog reda |---"<<endl;
				brziRed();
				break;
			}
		case 5:
			{
				cout<<"---| Stanje u redu |---"<<endl;
				ispisRedaBezVIP();
				break;
			}
		case 6:
			{
				cout<<"---| Stanje u redu |---"<<endl;
				ispisReda();
				break;
			}

		default:
			cout<<"Krivi izbor."<<endl;
			break;
		}
	}while(izbor!=9);

	return 0;
}

