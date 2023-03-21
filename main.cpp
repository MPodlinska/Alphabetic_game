//POP 2020-12-17 projekt 1 Podlinska Magdalena EIT 3 184441 Code::Blocks 20.03
#include <iostream>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <cmath>

using namespace std;

const int MAX_L=4;
const int MAX_W=17;
const int MAX_R=8;

//Funkcja wyswietla plansze
void plansza(char **gra)
{
    cout<<".-------.-------.-------.-------."<<endl;
    cout<<"|"<<setw(2)<<gra[0][0]<<setw(6)<<"|"<<setw(2)<<gra[0][1]<<setw(6)<<"|"<<setw(2)<<gra[0][2]<<setw(6)<<"|"<<
        setw(2)<<gra[0][3]<<setw(6)<<"|"<<endl;
    cout<<"|"<<setw(6)<<gra[0][0]<<setw(2)<<"|"<<setw(6)<<gra[0][1]<<setw(2)<<"|"<<setw(6)<<gra[0][2]<<setw(2)<<"|"<<
        setw(6)<<gra[0][3]<<setw(2)<<"|"<<endl;
    cout<<"|-------1-------+-------2-------|"<<endl;
    cout<<"|"<<setw(2)<<gra[1][0]<<setw(6)<<"|"<<setw(2)<<gra[1][1]<<setw(6)<<"|"<<setw(2)<<gra[1][2]<<setw(6)<<"|"<<
        setw(2)<<gra[1][3]<<setw(6)<<"|"<<endl;
    cout<<"|"<<setw(6)<<gra[1][0]<<setw(2)<<"|"<<setw(6)<<gra[1][1]<<setw(2)<<"|"<<setw(6)<<gra[1][2]<<setw(2)<<"|"<<
        setw(6)<<gra[1][3]<<setw(2)<<"|"<<endl;
    cout<<"|-------+-------5-------+-------|"<<endl;
    cout<<"|"<<setw(2)<<gra[2][0]<<setw(6)<<"|"<<setw(2)<<gra[2][1]<<setw(6)<<"|"<<setw(2)<<gra[2][2]<<setw(6)<<"|"<<
        setw(2)<<gra[2][3]<<setw(6)<<"|"<<endl;
    cout<<"|"<<setw(6)<<gra[2][0]<<setw(2)<<"|"<<setw(6)<<gra[2][1]<<setw(2)<<"|"<<setw(6)<<gra[2][2]<<setw(2)<<"|"<<
        setw(6)<<gra[2][3]<<setw(2)<<"|"<<endl;
    cout<<"|-------3-------+-------4-------|"<<endl;
    cout<<"|"<<setw(2)<<gra[3][0]<<setw(6)<<"|"<<setw(2)<<gra[3][1]<<setw(6)<<"|"<<setw(2)<<gra[3][2]<<setw(6)<<"|"<<
        setw(2)<<gra[3][3]<<setw(6)<<"|"<<endl;
    cout<<"|"<<setw(6)<<gra[3][0]<<setw(2)<<"|"<<setw(6)<<gra[3][1]<<setw(2)<<"|"<<setw(6)<<gra[3][2]<<setw(2)<<"|"<<
        setw(6)<<gra[3][3]<<setw(2)<<"|"<<endl;
    cout<<"'-------'-------'-------'-------'"<<endl;
}

//Funkcja sprawdza czy tabliczka jest ulozona alfabetycznie
bool warunek(char **gra)
{
    int licz=0;
    int p=0;
    char war[MAX_W]="ABCDEFGHIJKLMNOP";

    for(int i=0;i<MAX_L;i++)
    {
        for(int j=0;j<MAX_L;j++)
        {
                if(gra[i][j]==war[p]) licz++; //jezli litera na swoim miejscu (ulozona alfabetycznie)
                p++;
        }
    }

    if((licz+1)==MAX_W) return true;    //jezli wszytkie na swoim miejscu (ulozone alfabetycznie)
    else return false;
}

//Funkcja wykonuje ruch nr 1
char jeden(char **gra)
{
    char c;
    c=gra[0][0];        //zmienna pomocnicza, aby nie utracic wartosci
    gra[0][0]=gra[1][0];
    gra[1][0]=gra[1][1];
    gra[1][1]=gra[0][1];
    gra[0][1]=c;
    return **gra;
}

//Funkcja wykonuje ruch nr 2
char dwa(char **gra)
{
    char c;
    c=gra[0][2];        //zmienna pomocnicza, aby nie utracic wartosci
    gra[0][2]=gra[1][2];
    gra[1][2]=gra[1][3];
    gra[1][3]=gra[0][3];
    gra[0][3]=c;
    return **gra;
}

//Funkcja wykonuje ruch nr 3
char trzy(char **gra)
{
    char c;
    c=gra[2][0];        //zmienna pomocnicza, aby nie utracic wartosci
    gra[2][0]=gra[3][0];
    gra[3][0]=gra[3][1];
    gra[3][1]=gra[2][1];
    gra[2][1]=c;
    return **gra;
}

//Funkcja wykonuje ruch nr 4
char cztery(char **gra)
{
    char c;
    c=gra[2][2];        //zmienna pomocnicza, aby nie utracic wartosci
    gra[2][2]=gra[3][2];
    gra[3][2]=gra[3][3];
    gra[3][3]=gra[2][3];
    gra[2][3]=c;
    return **gra;
}

//Funkcja wykonuje ruch nr 5
char piec(char **gra)
{
    char c;
    c=gra[1][1];        //zmienna pomocnicza, aby nie utracic wartosci
    gra[1][1]=gra[2][1];
    gra[2][1]=gra[2][2];
    gra[2][2]=gra[1][2];
    gra[1][2]=c;
    return **gra;
}

//Funkcja wykonuje ruch nr 6
char szesc(char **gra)
{
    char c;
    c=gra[0][0];        //zmienna pomocnicza, aby nie utracic wartosci
    gra[0][0]=gra[1][0];
    gra[1][0]=gra[2][0];
    gra[2][0]=gra[3][0];
    gra[3][0]=gra[3][1];
    gra[3][1]=gra[3][2];
    gra[3][2]=gra[3][3];
    gra[3][3]=gra[2][3];
    gra[2][3]=gra[1][3];
    gra[1][3]=gra[0][3];
    gra[0][3]=gra[0][2];
    gra[0][2]=gra[0][1];
    gra[0][1]=c;
    return **gra;
}

//Funkcja sprawdza czy litera zostala juz uzyta w losowaniu
bool czy(char *tab, char litera, int i)
{
    for(int j=0;j<i;j++)
    {
        if( tab[j] == litera )return true;
    }
    return false;
}

//Funkcja wyswietla instrukcje
void instrukcja()
{
    cout<<"INSTRUKCJA"<<endl;
        cout<<"UWAGA! Mozna wykonac pojedynczy ruch lub sekwencje kolejnych ruchow do 8 ruchow:"<<endl;
        cout<<"1.Obrot zgodnie z wskazowkami zegara pierwszej cwiartki."<<endl;
        cout<<"2.Obrot zgodnie z wskazowkami zegara drugiej cwiartki."<<endl;
        cout<<"3.Obrot zgodnie z wskazowkami zegara trzeciej cwiartki."<<endl;
        cout<<"4.Obrot zgodnie z wskazowkami zegara czwartej cwiartki."<<endl;
        cout<<"5.Obrot zgodnie z wskazowkami zegara wnetrza."<<endl;
        cout<<"6.Obrot zgodnie z wskazowkami zegara zewnetrza."<<endl;
}

//Funcja wywoluje pojedynczy ruch
char cyfry(char **gra, int x)
{
    switch(x)
        {
            case 1: jeden(gra); break;
            case 2: dwa(gra); break;
            case 3: trzy(gra); break;
            case 4: cztery(gra); break;
            case 5: piec(gra); break;
            case 6: szesc(gra); break;
            default : cout<<"Podales niepoprawny ruch!"<<endl; break;
        }
    return **gra;
}

//Funcja wywoluje sekwenje ruchow
char sekwencje(char **gra, int x)
{
    int tab[MAX_R];
    int n;

    n=(int)log10(x)+1; //sprawdzenie ile ruchow zostanie wykonanych

    for(int i=(n-1);i>=0;i--)
    {
        tab[i]=x%10;        //zapisanie pojedynczych ruchow sekwencji w tablicy
        x=(x-(x%10))/10; //oddzielenie pojedynczych ruchow z sekwencji
    }
    for(int i=0;i<n;i++)
    {
        switch(tab[i])
        {
            case 1: jeden(gra); break;
            case 2: dwa(gra); break;
            case 3: trzy(gra); break;
            case 4: cztery(gra); break;
            case 5: piec(gra); break;
            case 6: szesc(gra); break;
            default : break;
        }
    }
    return **gra;
}

int main()
{
    srand(time(NULL));
    char **gra = new char *[MAX_L];
    for(int i=0;i<MAX_L;i++)
        gra[i] = new char [MAX_L]; //generowanie tablicy do przechowania stanu gry

    //Uzupelnianie losowo tablicy literami od A do P
    char tab[MAX_L*MAX_L];
    int i=1;

    char a=(rand()%16)+65;
    char litera= static_cast<char>(a);
    tab[0]=litera;

    while(i<(MAX_L*MAX_L))
    {
        char a=(rand()%16)+65;
        char litera= static_cast<char>(a);
        if(czy(tab,litera,i)==false)        //jezeli litera sie nie powtorzyla
        {
            tab[i]=litera;
            i++;
        }
        else continue;
    }

    int p=0;
    for(int i=0;i<MAX_L;i++)
        {
            for(int j=0;j<MAX_L;j++)
            {
                gra[i][j]=tab[p];       //uzupelnienie tablicy stanu gry
                p++;
            }
        }

    plansza(gra);

    //Gra
    while(warunek(gra)==false)
    {
        instrukcja();

        int x;
        cout<<"Podaj numer instrukcji: ";
        cin>>x;

        if(x<10) cyfry(gra,x);      //jezeli uzyto pojedynczego ruchu
        else
        {
            if(x<100000000) sekwencje(gra,x); //jezeli uzyto sekwencji do 8 ruchow
            else
            {
                cout<<"Podano za duzo ruchow!"<<endl;
                plansza(gra);
                continue;
            }
        }
        plansza(gra);
    }
    cout<<"BRAWO, WYGRALES!"<<endl;
    return 0;
}
