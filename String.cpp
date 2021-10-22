#include <iostream>
#include <cctype>
using namespace std;

int main() {
	
	string s1 = "al infinito y mas alla";
	
	//a partir de la posicion 3, mostrar 8 caracteres 
	string s2 = s1.substr(3,8); //muestra 'infinito'
	cout <<  s2 << endl;
	
	//puedo aclarar solo la posicion de inicio
	string s3 = s1.substr(14); //desde 14 hasta el final 
	cout << s3 << endl; //muestra 'mas alla'
	
	cout << s1 << endl; //muestra 'al infinito y mas alla'
	
	//borrar una parte intermedia
	string s4 = "Me gustan los ravioles";
	s4.erase(3,7);
	cout << s4 << endl; //muestra me los ravioles
	
	//borrar todo
	string s5 = "Persi te amo";
	s5.clear();
	cout << s5 << endl; //muestra ' '
	
	//reemplazar un fragmento por otro
	string s6 = "Hola a todos, yo soy el leon";
	s6.replace(5,8,"mundo!");
	cout << s6 << endl;
	
	//insertar un string en medio de otro
	string s7 = "Maderas de nogal";
	s7.insert(11,"viejo ");
	cout << s7 << endl;
	
	
	return 0;
}

