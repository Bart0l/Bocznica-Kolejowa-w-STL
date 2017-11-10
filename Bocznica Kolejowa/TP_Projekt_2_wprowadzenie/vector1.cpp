#include<iostream>
#include<iomanip>
#include<vector>
using namespace std; 

void writeIntVector (vector<int>);

int main(void)
{
     vector<int> IntVector;
     int n;
     
     cin >> n;
     
     for (int k = 1; k<=n; k++)
        IntVector.push_back(2*k);
     
     writeIntVector(IntVector);
        
     IntVector[0] = 999;
     IntVector[1] = 999;
     
     writeIntVector(IntVector);
     
     IntVector.resize(2*n);          // rozszerzenie do 2n z inicjalizacja 
                                     // domyslna wartosc dla liczbowych 0
     writeIntVector(IntVector);
     
     IntVector.resize(n);            //  obciecie do n
     writeIntVector(IntVector);
     
     IntVector.resize(2*n,77);       //  rozszerzenie do 2n z inicjalizacja 77
     writeIntVector(IntVector);
     
     
     system("pause");
     return 0;
     
}


void writeIntVector (vector<int> IntVector)
{
   for (int i = 0; i < IntVector.size(); i++)
        cout << setw(4) << IntVector[i];
   cout << endl;
}    
