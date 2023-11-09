#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class Pytanie{

public:
string pytanie;
string a, b, c;
string poprawnaOdp;

void wczytaj(int liczbaPyt);
void wyswietl(int liczbaPyt);
int start(int liczbaPyt);

};

Pytanie pytania[100];


void Pytanie::wczytaj(int liczbaPyt){
    
    string elo;

    ifstream myfile("pytania.txt");
	if (myfile.is_open())
	{
        for (int i = 0; i<liczbaPyt; i++){
        getline(myfile, pytania[i].pytanie);
        getline(myfile, pytania[i].a);
        getline(myfile, pytania[i].b);
        getline(myfile, pytania[i].c);
        getline(myfile, pytania[i].poprawnaOdp);
        }
    }
    else cout<<"nie ma takiego pliku";
}

void Pytanie::wyswietl(int numerPyt){
    
        cout<<pytania[numerPyt].pytanie<<endl;
        cout<<"a) "<<pytania[numerPyt].a<<endl;
        cout<<"b) "<<pytania[numerPyt].b<<endl;
        cout<<"c) "<<pytania[numerPyt].c<<endl;
}

int Pytanie::start(int liczbaPyt){

    string odp;
    int punkty = 0;

    wczytaj(liczbaPyt);
    
    for (int i = 0; i<liczbaPyt; i++){
        start:
        wyswietl(i);
        cin>>odp;
        system( "cls" );
        if (odp != "a" && odp!="b" && odp!="c"){
             cout<<endl<<"Niepoprawnie wprowadzony znak, sprobuj jeszcze raz"<<endl<<endl;
             goto start;
        }
        else {

              if (odp == pytania[i].poprawnaOdp){
                punkty++;
            }
        }
    }
    cout<<"Koniec testu! Liczba punktow: "<<punkty<<"/"<<liczbaPyt;
    
    return (punkty);
}









int main(){

Pytanie test;
test.start(3);

}