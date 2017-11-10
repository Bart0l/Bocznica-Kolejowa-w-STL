#include<iostream>
#include<iomanip>
#include<vector>
using namespace std; 

void writeIntVector (vector<int>);
void rev_writeIntVector (vector<int>);

int main(void)
{
     vector<int> IntVector;
     vector<int>::iterator it;
     int n;
     
     cout << "n = ";
     cin >> n;
     
     for (int k = 1; k<=n; k++)
        IntVector.push_back(2*k);
     
     writeIntVector(IntVector);
        
     IntVector[0] = 99;
     IntVector[1] = 99;
     
     writeIntVector(IntVector);
     
     rev_writeIntVector(IntVector);
         
      // dotyczy kontenerow sekwencyjnych
         
     cout << "sort " << endl;    
     sort(++IntVector.begin(), IntVector.end());
     writeIntVector(IntVector);     

     for (int i=1; i<=3; i++)
     {
        cout << "random_shuffle " << i << endl;
        random_shuffle(IntVector.begin(), IntVector.end());
        writeIntVector(IntVector);     
     } 
     
     cout << "min = " << *min_element(IntVector.begin(), IntVector.end()) << endl;

     cout << "max = " << *max_element(IntVector.begin(), IntVector.end()) << endl;

     cout << "reverse " << endl;    
     reverse(IntVector.begin(), IntVector.end());
     writeIntVector(IntVector);     

     cout << "reverse w zakresie " << endl;
     reverse(++IntVector.begin(), --IntVector.end());
     writeIntVector(IntVector);     

     cout << "replace 99 with 22 " << endl;
     replace(IntVector.begin(),IntVector.end(),99, 22);
     writeIntVector(IntVector);

     system("pause");
     return 0;
     
}


void writeIntVector (vector<int> IntVector)
{
   vector<int>::iterator it;
   
   for (it = IntVector.begin(); it != IntVector.end(); it++)
        cout << setw(4) << *it;
   cout << endl;
}    


void rev_writeIntVector (vector<int> IntVector)
{
   vector<int>::reverse_iterator rit;
   
   for (rit = IntVector.rbegin(); rit != IntVector.rend(); rit++)
        cout << setw(4) << *rit;
   cout << endl;
}    

