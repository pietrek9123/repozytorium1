#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
    char znak;
    int a,b,wynik;
    cout<<"Podaj pierwsza liczbe "<<endl;
    cin>>a;
    cout<<"Podaj druga liczbe "<<endl;
    cin>>b;
    cout<<"Wybierz znak: "<<endl;
    cin>>znak;
    if(znak=='+')
                 wynik=a+b;
    else if(znak=='-')
                 wynik=a-b;
    else if(znak=='*')
                 wynik=a*b;
    else if(znak=='/')
                 wynik=a/b;
    else if(znak=='^')
                 wynik=pow(a,b);
    cout<<"Wynik dzialania: "<<wynik;
    
    
    
    cout<<endl;
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
