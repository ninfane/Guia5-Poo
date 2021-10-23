#include <iostream>
#include <fstream>
using namespace std;

string mayusculas(string x){
	for(size_t i=0;i<x.length();i++)
		x[i]=toupper(x[i]);
	return x;
}

string minusculas(string x){
	for(size_t i=0;i<x.length();i++)
		x[i]=tolower(x[i]);
	return x;
}
		
int main(int argc, char *argv[]) {
	ifstream archi("molino.txt");
	cout<<"........... espere..........";
	
	string s="",linea;
	int g=0;
	while(getline(archi,linea)){
		s=s+linea+" ";
		g++;
    }
	archi.close();
	cout<<"\nLineas: "<<g<<endl;
	s=minusculas(s);
	
	int p=s.find("molinos de viento",0);
	int c=0;
	while(p != string::npos){
		c++;
		p=s.find("molinos de viento",p+17);
	}
	
	cout<<"\nse encontraron "<<c<<" veces";
	
	return 0;
}

