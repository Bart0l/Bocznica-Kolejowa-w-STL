// Uwaga: Poniewa¿ nie znamy jeszcze naturalnych mechanizmów dziedziczenia
//        oferowanych przez C++ prezentowane jest rozwi¹zanie, które z nich
//        nie korzysta. Ma ono pewne wady --- zalecam dalsz¹ lekturê
//        na temat dziedziczenia, interfejsów oraz szablonów klas, itp.  

#include<iostream>
#include<iomanip>
#include<stack>
using namespace std;

class myStack {
      public:
            myStack():weight(0),capacity(0){}
            myStack(int c){weight = 0; capacity = c;}
            ~myStack(){};
           // int getWeight(){return weight;}
           // int getCapacity(){return capacity;}
            void pop() {
                    if (s.size() > 0) {
                        weight -= s.top();
                        s.pop();
                    } else cerr << "Empty" << endl;
            }
            void push(int x) {
                    if (weight + x <= capacity) {
                        weight += x; 
                        s.push(x);
                        cout << "push" << x << endl;
                    } else cerr << "Full"<< endl;
            } 
            int& top() { return s.top();}
            bool empty() {return s.empty();}
            size_t size() {return s.size();}
      private:
           stack<int> s; 
           int weight;
           int capacity;
      };

void writeStack (myStack*);
void writeStack (myStack);

int main(void)
{
     myStack st(10);
     int n;

     cin >> n;

     for (int k = 1; k<=n; k++)
        st.push(k);

     writeStack(st);
     st.pop();
     writeStack(st);

     writeStack(&st);
     cout << st.size() << endl;

     system("pause");
     return 0;
}


void writeStack (myStack st) 
{
   while ( not st.empty())
   {
         cout << setw(4) << st.top();
         st.pop();                   // operuje na kopii - nie zmienia oryginalu
   }
   cout << endl;
}



void writeStack (myStack *st) 
{
   while ( not (*st).empty())
   {
         cout << setw(4) << (*st).top();
         (*st).pop();                   // operuje na oryginale - oproznia stos 
   }
   cout << endl;
}
