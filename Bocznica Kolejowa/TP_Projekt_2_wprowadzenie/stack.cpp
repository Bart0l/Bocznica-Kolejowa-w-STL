#include<iostream>
#include<iomanip>
#include<stack>
using namespace std;

void writeIntStack  (stack<int>);
void writeIntStack2 (stack<int>);

int main(void)
{
     stack<int> IntStack;
     int n;

     cin >> n;

     for (int k = 1; k<=n; k++)
        IntStack.push(2*k);

     writeIntStack2(IntStack);

     system("pause");
     return 0;
}

void writeIntStack (stack<int> IntStack)
{
   int ss = IntStack.size();
   for (int i = 0; i < ss; i++) {
         cout << setw(4) << IntStack.top();
         IntStack.pop();
   }
   cout << endl;
}

void writeIntStack2 (stack<int> IntStack)
{
   while ( not IntStack.empty())
   {
         cout << setw(4) << IntStack.top();
         IntStack.pop();
   }
   cout << endl;
}
