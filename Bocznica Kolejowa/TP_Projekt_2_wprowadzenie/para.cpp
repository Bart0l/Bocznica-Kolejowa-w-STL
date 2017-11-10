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
             int el1;
             int el2;
};

Para::Para(int a, int b)
{
  el1 = a;
  el2 = b;             
}

int Para::pobierz1()
{
   return(el1);
}

int Para::pobierz2()
{
    return(el2);
}

int main()
{
    Para P(2,3);
    cout << "element 1 = " << P.pobierz1() << endl
         << "element 2 = " << P.pobierz2() << endl;
    system("pause");
}
