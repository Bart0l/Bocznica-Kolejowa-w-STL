#include<iostream>
using namespace std;

class Kot
{
       public:
              Kot();                     // konstruktor domyslny 
              ~Kot();                    // destruktor  domyslny
              Kot(int wiek);             // konstruktor zdefiniowany, z parametrem
              int PobierzWiek() const;      // const tzn. nie bedzie zmieniac wartosci zmiennych wewnetrznych
              void UstawWiek(int wiek);     // ani publicznych, ani prywatnych
              void Miaucz() const;
       private:
             int jegoWiek;
};

Kot::Kot(int wiek)
{
     cout << "Konstruktor kota." << endl;
     UstawWiek(wiek);
}

Kot::Kot()
{
  cout << "Kot sie rodzi domyslnie." << endl;
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

void Kot::Miaucz() const
{
    cout << " Miau " << endl;
}


int main()
{
    Kot Garfield;
    Garfield.UstawWiek(5);
    Garfield.Miaucz();
    cout << "Garfield jest kotem ktory ma " 
         << Garfield.PobierzWiek() << " lat" << endl;
    
    Kot Filemon(2);
    cout << "Filemon jest kotem ktory ma " 
         << Filemon.PobierzWiek() << " lat" << endl;    
       
     Filemon.~Kot();
     
     Filemon.UstawWiek(3);  
       
    cout << "Filemon jest kotem ktory ma " 
         << Filemon.PobierzWiek() << " lat" << endl;    
       
    system("pause");
}
