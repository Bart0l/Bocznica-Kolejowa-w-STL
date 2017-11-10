#include<iostream>
using namespace std;

class Kot
{
       public:
              Kot();                     
              ~Kot();                         
              int PobierzWiek() const;      
              void UstawWiek(int wiek);
       private:
             int jegoWiek;
};

Kot::Kot()
{
   cout << "Konstruktor kota." << endl;
   jegoWiek = 6;
}

Kot::~Kot()
{
     cout << "Destruktor kota."<< endl;
}

int Kot::PobierzWiek() const
{
   return(jegoWiek); 
}

void Kot::UstawWiek(int wiek)
{
    jegoWiek = wiek;
}

int main()
{
    cout << "Stworzymy GARFIELDA" << endl;
    Kot Garfield;
    cout << "Garfield jest zwyklym kotem na plocie " << endl
         << "Garfield ma " << Garfield.PobierzWiek() << " lat" << endl;
    
    
    cout << "Stworzymy FILEMONA" << endl;
    Kot* wskFilemona = new Kot;
    cout << "Filemon jest dynamicznym kotem na stercie " << endl
         << "Filemon ma " << (*wskFilemona).PobierzWiek() << " lat" << endl;
    cout << "FILEMONOWI dziekujemy " << endl;
   delete wskFilemona;
                  
    system("pause");
}
