#include<iostream>
using namespace std;


class Kot
{
       public:
              Kot();                     
              ~Kot();                         
              int PobierzWiek() const;      
              void UstawWiek(int wiek);
              int PobierzWage() const;      
              void UstawWage(int waga);
       private:
             int *jegoWiek;
             int *jegoWaga;
};


Kot::Kot()
{
   cout << "Konstruktor kota." << endl;
   jegoWiek = new int(5);    // utworzenie inta i inicjalizacja
   jegoWaga = new int(10);   
}


Kot::~Kot()
{
     cout << "Destruktor kota."<< endl;
     delete jegoWiek;
     delete jegoWaga;
}


int Kot::PobierzWiek() const
{
   return(*jegoWiek); 
}


void Kot::UstawWiek(int wiek)
{
    *jegoWiek = wiek;
}


int Kot::PobierzWage() const
{
   return(*jegoWaga); 
}


void Kot::UstawWage(int waga)
{
    *jegoWaga = waga;
}


int main()
{
    cout << "-------- Stworzymy GARFIELDA" << endl;
    Kot Garfield;
    cout << "Garfield jest zwyklym kotem na plocie " << endl
         << "Garfield ma " << Garfield.PobierzWiek() << " lat" << endl
         << "i wazy " << Garfield.PobierzWage() << " kilogramow." << endl;;
    
    
    cout << endl;
    cout <<"-------- Stworzymy FILEMONA" << endl;
    Kot* wskFilemona = new Kot;
    cout << "Filemon jest dynamicznym kotem na stercie " << endl
         << "Filemon ma " << (*wskFilemona).PobierzWiek() << " lat" << endl
         << "i wazy " << wskFilemona->PobierzWage() << " kilogramow." << endl;
    
    cout << "FILEMONOWI dziekujemy " << endl;
    delete wskFilemona;
                  
    system("pause");
}
