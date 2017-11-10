#include<iostream>
using namespace std;

class Para
{
       public:
              Para();                     
              Para(int,int);
              int pobierz1();
              int pobierz2();
       private:
             int suma;
             int el;
};

Para::Para(int a, int b)
{
  suma = a + b;
  el = b;             
}

int Para::pobierz1()
{
   return(suma - el);
}

int Para::pobierz2()
{
    return(el);
}

int main()
{
    Para P(2,3);
    cout << "element 1 = " << P.pobierz1() << endl
         << "element 2 = " << P.pobierz2() << endl;
    system("pause");
}
