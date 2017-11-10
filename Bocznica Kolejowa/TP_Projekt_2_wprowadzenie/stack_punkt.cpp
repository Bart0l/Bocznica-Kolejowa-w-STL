#include<iostream>
#include<iomanip>
#include<stack>
using namespace std;

struct punkt
{
       float wspX;
       float wspY;
};

void writePktStack  (stack<punkt>);
void writePktStack2 (stack<punkt>);

int main(void)
{
     stack<punkt> PktStack;
     int n;

     cin >> n;

     for (int k = 1; k<=n; k++)
        {
          punkt p;
          p.wspX = k*0.1;
          p.wspY = k*0.2;
          PktStack.push(p);
        }  

     writePktStack(PktStack);

     system("pause");
     return 0;
}

void writePktStack (stack<punkt> PktStack)
{
   int ss = PktStack.size();

   for (int i = 0; i < ss; i++) {
         cout << setw(4) << "(" << PktStack.top().wspX << " , ";
         cout << setw(4) <<        PktStack.top().wspY << ")" << endl;
         PktStack.pop();
   }
   cout << endl;
}

void writePktStack2 (stack<punkt> PktStack)
{
   while ( not PktStack.empty())
   {
         cout << setw(4) << "(" << PktStack.top().wspX << " , ";
         cout << setw(4) <<        PktStack.top().wspY << ")" << endl;
         PktStack.pop();
   }
   cout << endl;
}
