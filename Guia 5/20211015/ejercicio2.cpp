#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

struct Alumno{
	string nombre;
	int n1,n2;
};

void modifica(Alumno x){
	vector<Alumno> al;
	ifstream archi("lista.txt");
	if (archi.is_open()){
		Alumno aux;
		while( getline(archi, aux.nombre) && archi>>aux.n1>>aux.n2){
			al.push_back(aux);
			archi.ignore();
		}
		archi.close();
		/*
		for(Alumno a:al)
			  cout<<a.nombre<<"  "<<a.n1<<" "<<a.n2<<endl;
		*/
		
		for(size_t i=0;i<al.size();i++) { 
			if(al[i].nombre==x.nombre){
				al[i].n1=x.n1;
				al[i].n2=x.n2;
				break;
			}
		}
		
		/*cout<<"\nLista modificada:\n";
		for(Alumno a:al)
			cout<<a.nombre<<"  "<<a.n1<<" "<<a.n2<<endl;
		*/
		ofstream archi2("lista.txt",ios::trunc);
		for(Alumno a:al){
			archi2<<a.nombre<<endl;
			archi2<<a.n1<<" "<<a.n2<<endl;
		}
		archi2.close();
	}
}

	
void promedios(){
	vector<Alumno> al;
	ifstream archi("lista.txt");
	if (archi.is_open()){
		Alumno aux;
		while( getline(archi, aux.nombre)  && archi>>aux.n1>>aux.n2){
			al.push_back(aux);
			archi.ignore();
		}
		archi.close();
			
		ofstream archi2("promedios.txt",ios::trunc);
		for(Alumno a:al){
			archi2<<setw(20)<<left<<a.nombre;
			float p=(a.n1+a.n2)/2.0;
			archi2<<left<<setw(10)<<p;
			archi2<<left<<setw(10);
			if(p>=70) archi2<<"Promocionado\n";
		  	else if(p<40) archi2<<"Libre\n";
				else archi2<<"Regular\n";
			}
		archi2.close();
	}
}
		
	
	

int main(int argc, char *argv[]) {
	Alumno aux;
	cout<<"Ingrese Alumno y 2 notas:  ";
	getline(cin,aux.nombre);
	cin>>aux.n1>>aux.n2;
	modifica(aux);
	
	promedios();	
	return 0;
}

