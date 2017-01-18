#include <iostream>
#include <string>
#include <cctype>
#include <stdlib.h> 
#include <unistd.h>

using namespace std;
string TekstNaMorsa(string, string[]);
string MorsNaTekst(string, string[]);


int main ()
{
    string mors[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    string tekst, morskod;
    int w; //wybór
    char powtorz='t';
 
while (powtorz=='t')	//powtarzaj, póki u¿ywkownik zgadza siê na powtórzenie
{
    cout <<"Menu: "<< endl;
    cout <<"1 - Tekst do Morse \n"<< endl;
    cout <<"2 - Morse do Tekst \n"<< endl;
    cin >> w;

	system( "cls" );	//czyszczenie ekranu
	switch( w )
    {
    case 1 :
		cout << "TEKST DO MORSE \n Wpisz tekst: ";
        cin.get();
        getline(cin,tekst);
        cout << "WPISANY TEKST : " << tekst << endl;
        cout << "TEKST PO KODOWANIU : " << TekstNaMorsa(tekst, mors) << endl;
        break;
    case 2:
    	cout << "MORSE DO TEKST \n Wpisz tekst: ";
        cin.get();
        getline(cin,tekst);
        cout << "WPISANY TEKST : " << tekst << endl;
        cout << "TEKST PO KODOWANIU : " << MorsNaTekst(tekst, mors) << endl;
        break;
    }

    
    cout << "\n Powtozyc program ? \n t-TAK n-NIE";
    cin >> powtorz;
    system( "cls" );
}
return 0;
}    

//--------------------------------------------------------------------------------

string TekstNaMorsa(string tekst, string mors[])
{
    int dltekst = tekst.length(); //d³ugosc tekstu
    
    string morse;
    
    string miedzylit= " ";
    string miedzyslow = "  ";
    
    for (int i=0; i<dltekst; i++)
    {
        if (tekst[i]!= ' ') //je¿eli znak nie jest spacj¹
        {   tekst[i]=toupper(tekst[i]); //toupper() zamienia ma³¹ literê na du¿¹
            morse=miedzylit+=mors[tekst[i]-'A']+" "; //slowo: piotr - dla i[0] -> morse=" "+(80-65=15).--.+" "
        }
        if (tekst[i]==' ')	//je¿eli znak jest spacj¹
        {
            miedzylit+=miedzyslow;
        }
    } 
return morse; 
}

//----------------------------------------------------------------------------------

string MorsNaTekst(string morskod, string mors[]) //morskod - wpisany kod morsa        mors[]-tablica znaków morsa
{
    string tekst = ""; 
    
    int i = 0;
    int const dl = morskod.length();
    
    while(i < dl)
    {
        string litera = "";
        while(morskod[i] != ' ' && i < dl) //dopóki znak morsa nie jest spacj¹ i ilosc obrotów jest mniejsza niz dlugosc s³owa morsa
        {
            litera += morskod[i]; //przepisanie kodu morsa do zmiennej litera
            i++;
        }

      
        int j = 0;
        while(mors[j] != litera && j < 26)
        {
            ++j;                          
        }
        if ('A'+j==91) //A=65 je¿eli A+j == 91 to stawiamy spacje bo 91 to w ASCII juz nie litera
        {
        	  tekst += ' ';  //konic wyrazu, stawiamy spacje
              ++i;
		} 
        else
        {
		      tekst += 'A' + j;
               ++i; 
   	    }
    }

    return tekst;
}

