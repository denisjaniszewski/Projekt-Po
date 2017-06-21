#include <iostream>
#include <string>
#include <fstream>

using namespace std;
 
struct Pilkarz
{       
    string imie;
    string nazwisko;
    string pozycja;
    int numer, ilosc_m, bramki;                 
    int cena, wiek, ilosc_mp;
    int bramki_p, dosw, czerw;
    int zolte, kontuzje;
}; 
 
const int n=20;
Pilkarz tab [n];
 
int rozmiar()
{
    string nazwisko; 
	string imie;
	string pozycja;
	int numer, ilosc_m, bramki;
    int cena, wiek, ilosc_mp;
    int bramki_p, dosw, czerw;
    int zolte, kontuzje;
    
    int rozm=0;
 
    ifstream plik;
    plik.open("baza.txt");
 
    while(!plik.eof())
    {
        plik>>numer;
        plik>>imie;
        plik>>nazwisko;
        plik>>wiek;
        plik>>dosw;
        plik>>pozycja;
        plik>>ilosc_mp;
        plik>>bramki_p;
        plik>>ilosc_m;
        plik>>bramki;
        plik>>zolte;
        plik>>czerw;
        plik>>kontuzje;
        plik>>cena;
 
        rozm+=1;
    }
 
    plik.close();
    return rozm-1;
}
 
void odczyt(int n)
{
    ifstream plik;
    plik.open("baza.txt");
 
    for(int i=0;i<n;i++)
    {
        plik>>tab[i].numer;
        plik>>tab[i].imie;
        plik>>tab[i].nazwisko;
        plik>>tab[i].wiek;
        plik>>tab[i].dosw;
        plik>>tab[i].pozycja;
        plik>>tab[i].ilosc_mp;
        plik>>tab[i].bramki_p;
        plik>>tab[i].ilosc_m;
        plik>>tab[i].bramki;
        plik>>tab[i].zolte;
        plik>>tab[i].czerw;
        plik>>tab[i].kontuzje;
        plik>>tab[i].cena;
    }
    plik.close();
}
 
void zapis(int n)
{
        ofstream plik;
        plik.open("baza.txt");
        
        for(int i=0;i<n;i++)
        {
        plik<<tab[i].numer<<endl;
        plik<<tab[i].imie<<endl;
        plik<<tab[i].nazwisko<<endl;
        plik<<tab[i].wiek<<endl;
        plik<<tab[i].dosw<<endl;
        plik<<tab[i].pozycja<<endl;
        plik<<tab[i].ilosc_mp<<endl;
        plik<<tab[i].bramki_p<<endl;
        plik<<tab[i].ilosc_m<<endl;
        plik<<tab[i].bramki<<endl;
        plik<<tab[i].zolte<<endl;
        plik<<tab[i].czerw<<endl;
        plik<<tab[i].kontuzje<<endl;
        plik<<tab[i].cena<<endl;
        plik<<endl;
    }
        plik.close(); 
 }
 
 
int main()
{   
    int i=0;
    int znak;
 
    int ile=rozmiar();
    odczyt(ile);
 
    do
    {
    	cout<<endl;
    	cout<<" Baza danych klubu pilkarskiego"<<endl;
    	cout<<" Wybierz numer aby wykonac dana czynnosc"<<endl; 
    	cout<<" -1 - Dopisanie nowego pilkarza"<<endl;
    	cout<<" -2 - Wypisanie wszystkich pilkarzy"<<endl; 
    	cout<<" -3 - Aktualizacja danych konkretnego pilkarza"<<endl;
    	cout<<" -4 - Wyswietlenie konkretnego pilkarza"<<endl;
    	cout<<" -5 - Usuniecie pilkarza"<<endl;
    	cout<<" -0 - Wyjscie z programu"<<endl; 
    	cout<<endl;
    	cout<<" Wybieram: ";   
    	cin>>znak;  
		cout<<endl;
		 
    switch(znak)
    {
        case 1:
        {
        	ile=ile+1;
        	i=ile-1;
        	tab[i].numer=ile;
        	
        	cout<<"Podaj imie: ";
        	cin>>tab[i].imie;
        	cout<<"Podaj nazwisko: ";
        	cin>>tab[i].nazwisko;
        	cout<<"Podaj wiek: ";
        	cin>>tab[i].wiek;
        	cout<<"Podaj ilosc lat w grze zawodowej: ";
        	cin>>tab[i].dosw;
        	cout<<"Podaj pozycje na boisku: ";
        	cin>>tab[i].pozycja;
        	cout<<"Podaj ilosc zagranych meczy w poprzednim sezonie: ";
        	cin>>tab[i].ilosc_mp;
        	cout<<"Podaj ilosc bramek w poprzednim sezonie: ";
        	cin>>tab[i].bramki_p;
        	cout<<"Podaj ilosc zagranych meczy w obecnym sezonie: ";
        	cin>>tab[i].ilosc_m;
        	cout<<"Podaj ilosc bramek w obecnym sezonie: ";
        	cin>>tab[i].bramki;
        	cout<<"Podaj ilosc zoltych kartek w ostatnich 3 sezonach: ";
        	cin>>tab[i].zolte;
        	cout<<"Podaj ilosc czerwonych kartek w ostatnich 3 sezonach: ";
        	cin>>tab[i].czerw;
        	cout<<"Podaj ilosc kontuzji w ostatnich 3 sezonach: ";
        	cin>>tab[i].kontuzje;
        	cout<<"Podaj wartosc pilkarza: ";
        	cin>>tab[i].cena;
 
        break;
        }
        case 2:
        {
           for(int i=0;i<ile;i++)
        	{
            	cout<<"Nr: "<<tab[i].numer<<" ";
            	
            	cout<<tab[i].imie<<" ";
            	cout<<tab[i].nazwisko<<" ";
            	cout<<tab[i].pozycja<<" ";
            	cout<<endl;
    	    }
             break;
        }
        case 3:
        {
            int j=0;
            cout<<"Podaj numer pilkarza do aktualizacji: ";
            cin>>j;
            j--;
            
            cout<<endl;
            cout<<"Podaj imie: ";
        	cin>>tab[j].imie;
        	cout<<"Podaj nazwisko: ";
        	cin>>tab[j].nazwisko;
        	cout<<"Podaj wiek: ";
        	cin>>tab[j].wiek;
        	cout<<"Podaj ilosc lat w grze zawodowej: ";
        	cin>>tab[j].dosw;
        	cout<<"Podaj pozycje na boisku: ";
        	cin>>tab[j].pozycja;
        	cout<<"Podaj ilosc zagranych meczy w poprzednim sezonie: ";
        	cin>>tab[j].ilosc_mp;
        	cout<<"Podaj ilosc bramek w poprzednim sezonie: ";
        	cin>>tab[j].bramki_p;
        	cout<<"Podaj ilosc zagranych meczy w obecnym sezonie: ";
        	cin>>tab[j].ilosc_m;
        	cout<<"Podaj ilosc bramek w obecnym sezonie: ";
        	cin>>tab[j].bramki;
        	cout<<"Podaj ilosc zoltych kartek w ostatnich 3 sezonach: ";
        	cin>>tab[j].zolte;
        	cout<<"Podaj ilosc czerwonych kartek w ostatnich 3 sezonach: ";
        	cin>>tab[j].czerw;
        	cout<<"Podaj ilosc kontuzji w ostatnich 3 sezonach: ";
        	cin>>tab[j].kontuzje;
        	cout<<"Podaj wartosc pilkarza: ";
        	cin>>tab[j].cena;
            break;
            }
        case 4:
        {
            int j=0;
            cout<<"Podaj numer pilkarza do wyswietlenia: ";
            cin>>j;
            j--;
            
			cout<<endl;   
			cout<<"Nr: "<<tab[j].numer<<endl;
            cout<<"Imie: "<<tab[j].imie<<endl;
            cout<<"Nazwisko: "<<tab[j].nazwisko<<endl;
            cout<<"Wiek: "<<tab[j].wiek<<endl;
            cout<<"Lata dosw.: "<<tab[j].dosw<<endl;
            cout<<"Pozycja: "<<tab[j].pozycja<<endl;
            cout<<"Mecze poprzedni sezon: "<<tab[j].ilosc_mp<<endl;
            cout<<"Bramki poprzedni sezon: "<<tab[j].bramki_p<<endl;
            cout<<"Mecze bierzacy sezon: "<<tab[j].ilosc_m<<endl;
            cout<<"Bramki bierzacy sezon: "<<tab[j].bramki<<endl;
            cout<<"Zolte kartki 3 sezony: "<<tab[j].zolte<<endl;
            cout<<"Czerwone kartki 3 sezony: "<<tab[j].czerw<<endl;
            cout<<"Kontuzje 3 sezony: "<<tab[j].kontuzje<<endl;
            cout<<"Cena: "<<tab[j].cena<<endl; 
            cout<<endl;
            break;
            }
        case 5:
        {
            int j=0;
            cout<<"Podaj numer pilkarza do usuniecia: ";
            cin>>j;
            j--;
                
            for(int i=j;i<ile-1;i++)
            {
                tab[i].imie=tab[i+1].imie;
                tab[i].nazwisko=tab[i+1].nazwisko;
                tab[i].wiek=tab[i+1].wiek;
				tab[i].dosw=tab[i+1].dosw;
                tab[i].pozycja=tab[i+1].pozycja;
                tab[i].ilosc_mp=tab[i+1].ilosc_mp;
                tab[i].bramki_p=tab[i+1].bramki_p;
                tab[i].ilosc_m=tab[i+1].ilosc_m;
                tab[i].bramki=tab[i+1].bramki;
                tab[i].zolte=tab[i+1].zolte;
                tab[i].czerw=tab[i+1].czerw;
                tab[i].kontuzje=tab[i+1].kontuzje;
                tab[i].cena=tab[i+1].cena;
            }
            ile--;
            break;
        } 
        case 0:
        {
            zapis(ile);
            cout<<"Skonczyles prace nad swoja baza druzyny."<<endl;
        }
    }
    }while(znak!=0);
 
    return 0;
}
