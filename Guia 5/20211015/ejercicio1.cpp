#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
	ifstream archi("palabras.txt");
	vector<string> lista;
	string pal;
	if(archi.is_open()){
		while (archi>>pal){
			lista.push_back(pal);
			cout<<pal<<endl;
		}
		archi.close();
		
		sort(lista.begin(),lista.end());
		cout<<"\nLista Ordenada:\n";
		for(string p:lista){
			cout<<p<<endl;
		}
		// actualizo ael archivo
		ofstream archi2("palabras.txt",ios::trunc);
		for(string p:lista){
			archi2<<p<<endl;
		}
		archi2.close();

	} else
		cout<<"No se pudo abrir el archivo\n";
	
	return 0;
}

