//TP_2017_04_05
//Code::Blocks IDE 16.01
//=== TDM-GCC Compiler Suite for Windows ===
//---           GCC 4.9 Series           ---
//***   Standard MinGW 32-bit Edition    ***


#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <cstdio>
#include <cstdlib>

using namespace std;

void bocznica_kolejowa(vector<vector<char> > &, vector <char> &,vector <char> &,vector<vector<char> > &, int, int[],int&);
void wybierz_rozjazd(vector<vector<char> > &, vector <char> &,vector <char> &,vector<vector<char> > &, int, int[], int[],int&);
void zwolnij_wagon(vector<vector<char> > &, vector <char> &,vector <char> &,vector<vector<char> > &, int, int[], int[],int&);

int main()
{
    cout<<"Techniki Programowania - PROJEKT 2. zad. 6. | Jan Michalik | Bartlomiej Borzyszkowski | AiR 1 ETI |"<<endl<<endl;
    cout<<"Witamy w programie sterujacym bocznica kolejowa."<<endl<<"Ustaw wagony pociagu w kolejnosci sugerowanej z prawej strony."<<endl;
    cout<<"Za poprawne uzupelnienie toru otrzymujesz 15 punktow."<<endl<<"Za bledne rozstawienie wagonow lub przekroczenie wymaganej dlugosci tracisz 5 punktow."<<endl;
    cout<<"Aby wygrac zdobadz 50 punktow."<<endl<<endl;
    int tablica [5]={0,0,0,0,0};
    int punkty [5]={4,4,3,4,3};
    int znak, wynik=0;
    vector<char> zwolniony_tor;
    vector<vector<char> > vector_dwuwymiarowy;

	char pociag[18] = {'A','A','C','B','A','C','B','D','D','A','B','A','D','B','C','D','B','B'}; // poci1g o sta3ej kolejnooci wagonów
	vector<char>wagony;

	for(int i=0;i<18;i++) // wpisywanie kolejnych wagonow do wektora
		wagony.push_back(pociag[i]);

    char kolejnosc[5][4] = {{'A','A','B','B'},{'A','B','A','B'},{'C','D','D'},{'A','B','B','C'},{'C','D','D',}};

	vector <vector< char > > tory_prawidlowe; // wektor dwuwymiarowy torów prawdilowych
	tory_prawidlowe.resize( 5 );

	for(int k=0;k<5;k++){
		for(int l=0;l<4;l++){
		tory_prawidlowe[ k ].push_back( kolejnosc[k ][ l ] );
		}};

	bocznica_kolejowa(vector_dwuwymiarowy, wagony,zwolniony_tor, tory_prawidlowe, znak, tablica,wynik);
	wybierz_rozjazd(vector_dwuwymiarowy, wagony,zwolniony_tor, tory_prawidlowe,  znak, tablica, punkty,wynik);

	return 0;
}

void bocznica_kolejowa( vector<vector<char> > &vector_dwuwymiarowy, vector <char> &wagony, vector <char> &zwolniony_tor,vector<vector<char> > &tory_prawidlowe, int znak, int tablica[],  int &wynik){
	//pociag
	for(int j=0;j<wagony.size();j++)
        cout << wagony[j];
    cout<<"   ";

    //tor1
	for(int j=0;j<18-wagony.size();j++)
        cout <<"=";
	for(int j=0;j<40-tablica[0];j++)
        cout << "=";
    for(int l=tablica[0]-1;l>=0;l--)
		cout<<vector_dwuwymiarowy[0][l];
    cout << " Tor 1: [";
		for(int l=0;l<4;l++){
		cout << tory_prawidlowe[0][l];}; cout<<"]"<<endl;

    //tor2
	cout <<" " << setw(33)<<"\\\\\  (2)" << endl;
	cout << setw(31)<<"\\\\\ ";
	for(int j=0;j<30-tablica[1];j++)
    cout << "=";
    for(int l=tablica[1]-1;l>=0;l--)
		cout<<vector_dwuwymiarowy[1][l];
    cout<<" Tor 2: [";
    for(int l=0;l<4;l++){
		cout << tory_prawidlowe[1][l];}; cout<<"]"<<endl;

    //tor3
	cout << setw(36)<<"\\\\\  (3)" << endl;
	cout << setw(33)<<"\\\\\ ";
	for(int j=0;j<28-tablica[2];j++)
    cout << "=";
    for(int l=tablica[2]-1;l>=0;l--)
		cout<<vector_dwuwymiarowy[2][l];
	cout<<" Tor 3: [";
	for(int l=0;l<3;l++){
		cout << tory_prawidlowe[2][l];}; cout<<"]"<<endl;

	//tor4
	cout << setw(38)<<"\\\\\  (4)" << endl;
	cout << setw(35)<<"\\\\\ ";
	for(int j=0;j<26-tablica[3];j++)
    cout << "=";
    for(int l=tablica[3]-1;l>=0;l--)
		cout<<vector_dwuwymiarowy[3][l];
	cout<<" Tor 4: [";
	for(int l=0;l<4;l++){
		cout << tory_prawidlowe[3][l];}; cout<<"]"<<endl;

	//tor5
	cout << setw(40)<<"\\\\\  (5)" << endl;
	cout << setw(37)<<"\\\\\ ";
	for(int j=0;j<24-tablica[4];j++)
	cout<<"=";
	for(int l=tablica[4]-1;l>=0;l--)
		cout<<vector_dwuwymiarowy[4][l];
	cout<<" Tor 5: [";
	for(int l=0;l<3;l++){
		cout << tory_prawidlowe[4][l];}; cout<<"]"<<endl;
}

void wybierz_rozjazd(vector<vector<char> > &vector_dwuwymiarowy, vector <char> &wagony, vector <char> &zwolniony_tor,vector<vector<char> > &tory_prawidlowe, int znak,int tablica[], int punkty[],  int &wynik){
	do{
	cout << "Wybierz rozjazd (1-5): " << endl;
	cin >> znak;

	switch(znak)
	{
	    case 1:
	        cout << "ROZJAZD NR 1" << endl;
	        tablica[0]+=1;
			zwolnij_wagon(vector_dwuwymiarowy, wagony,zwolniony_tor, tory_prawidlowe, znak, tablica, punkty, wynik);
			break;

		case 2:
			cout << "ROZJAZD NR 2" << endl;
			tablica[1]+=1;
			zwolnij_wagon(vector_dwuwymiarowy, wagony,zwolniony_tor,tory_prawidlowe,  znak,tablica, punkty, wynik);
			break;
		case 3:
			cout << "ROZJAZD NR 3" << endl;
			tablica[2]+=1;
			zwolnij_wagon(vector_dwuwymiarowy, wagony,zwolniony_tor,tory_prawidlowe,  znak,tablica, punkty, wynik);
			break;
		case 4:
			cout << "ROZJAZD NR 4" << endl;
			tablica[3]+=1;
			zwolnij_wagon(vector_dwuwymiarowy, wagony,zwolniony_tor, tory_prawidlowe, znak,tablica, punkty, wynik);
			break;
		case 5:
			cout << "ROZJAZD NR 5" << endl;
			tablica[4]+=1;
			zwolnij_wagon(vector_dwuwymiarowy, wagony,zwolniony_tor,tory_prawidlowe,  znak,tablica, punkty, wynik);
			break;
		default:
			cout << "BRAK TAKIEGO ROZJAZDU!" << endl;
			break;
		}	}while(znak!=2 ||znak!=3 ||znak!=4 ||znak!=5 );
}
void zwolnij_wagon(vector<vector<char> > &vector_dwuwymiarowy, vector <char> &wagony, vector <char> &zwolniony_tor,vector<vector<char> > &tory_prawidlowe, int znak, int tablica[], int punkty[],  int &wynik){
	cout << "Aby zwolnic wagon - wcisnij 'w'! " << endl;
	cin.get();
	if(getchar()==119){
		cout << "Zwolniono!" <<endl<<endl;
		wagony.pop_back();
		int p=wagony.size();


		zwolniony_tor.push_back(wagony[p]);

        vector_dwuwymiarowy.resize(5);

        vector_dwuwymiarowy[znak-1].push_back(wagony[p]);

		int licznik=0;
        if(tablica[znak-1]==punkty[znak-1]){
            int j=punkty[znak-1];
        for (int i=0; i<tablica[znak-1]; i++)
        {
            if(tory_prawidlowe[znak-1][j-1]==vector_dwuwymiarowy[znak-1][i])
            licznik+=1;
            j--;
        }
        if(licznik==tablica[znak-1])
            {wynik +=15;cout<<"POPRAWNIE ROZLADOWALES SKLAD POCIAGU. PUNKTY +15."<<endl<<"Posiadasz: "<<wynik<< " punktow."<<endl<<endl;}
        else {wynik-=5; cout<<"ZLE USTAWILES WAGONY! PUNKTY -5"<<endl<<"Posiadasz: "<<wynik<< " punktow."<<endl<<endl;}}

        if(tablica[znak-1]>punkty[znak-1])
          {wynik-=5; cout<<"ZLE USTAWILES WAGONY! PUNKTY -5"<<endl<<"Posiadasz: "<<wynik<< " punktow."<<endl<<endl;}

        if(wynik>=50){
            cout<<"BRAWO! WYGRALES!"<<endl;
            exit (1);
		}
        if(wynik<0){
            cout<<"TYM RAZEM PRZEGRALES"<<endl;
            cout<<"Zdobyles "<<wynik<< " punktow."<<endl;
            exit (1);
		}

		if(wagony.size()==0){
            cout<<"Koniec skladu!"<<endl;
            cout<<"TYM RAZEM PRZEGRALES"<<endl;
            cout<<"Zdobyles "<<wynik<< " punktow."<<endl;
            exit (1);
		}

		bocznica_kolejowa(vector_dwuwymiarowy, wagony,zwolniony_tor,tory_prawidlowe, znak, tablica, wynik);
        }
        else{
        cout << "Podano bledny znak!" << endl; tablica[znak-1]-=1;
        }
}
