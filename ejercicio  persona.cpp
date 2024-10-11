#include <iostream>
#include <string>
using namespace std;


struct Fecha {
    int dia;
    int mes;
    int anio;
};


struct Persona {
    string DNI;
    string name;
    Fecha FN; 
};
void mostrarPersonas(Persona PER[], int tam) {
    for (int i = 0; i < tam; i++) {
        cout << "Persona " << i + 1 << ":\n";
        cout << "DNI: " << PER[i].DNI << endl;
        cout << "Nombre: " << PER[i].name << endl;
        cout << "Fecha de Nacimiento: " << PER[i].FN.dia << "/"
             << PER[i].FN.mes << "/" << PER[i].FN.anio << endl;
        cout << "-----------------------------\n";
    }
}
bool ComparaFechas(Persona PER[],Fecha  F,int i){
	
	int retorna=false;
	if(PER[i].FN.anio>F.anio){
		retorna= true;
	}else if(PER[i].FN.anio==F.anio&&PER[i].FN.mes>F.mes){
		retorna=true;
	}else if(PER[i].FN.anio==F.anio&&PER[i].FN.mes==F.mes&&PER[i].FN.dia>F.dia){
		retorna = true;
	}
		
	return retorna;
	
	
}
void OrdenaArreglo(Persona PER[],Persona NEW[],int &n){
	
	int i=n;
	Fecha F=NEW[0].FN;
	if(n>0){
		
		while(i>=0 && ComparaFechas(PER,F,i)==true ){
			PER[i+1]=PER[i];
			i--;
			
		}
		PER[i+1]=NEW[0];
		
	}else{
		PER[0]=NEW[0];
	}
	n++;
	
	
}
void  BusquedaBinaria(Persona PER[],Fecha F,int n){
	int izq=0;
	int der=n;
	int cen=0;
	int m;
	while(izq<=der&& cen==0){
		m=(izq+der)/2;
		if(PER[m].FN.anio==F.anio&&PER[m].FN.mes==F.mes&&PER[m].FN.dia==F.dia){
			cen=1;
		}else if(ComparaFechas(PER,F,m)==false){
			izq=m+1;
		}else{
			der=m-1;
		}
	}
	
	
	if(cen==1){
		cout << "Persona " << m + 1 << ":\n";
        cout << "DNI: " << PER[m].DNI << endl;
        cout << "Nombre: " << PER[m].name << endl;
        cout << "Fecha de Nacimiento: " <<PER[m].FN.dia << "/"
             << PER[m].FN.mes << "/" << PER[m].FN.anio << endl;
        cout << "-----------------------------\n";
    }else{
    	cout<<"La fecha no coincide con ningun dato del arreglo.\n";
	}
	
	 
	
}

int main() {
    int cantper=0;
    int resp;
    Persona PER[100];
    Persona NEW[1];
	
	do{
	
	cout<<"Que desea hacer?:";
	
	cout<<"\n1)Agregar Personas."<<"\n2)Busqueda"<<"\n3)Mostrar personas"<<"\n0)Salir"<<"\nresp: ";
	cin>>resp;
	cout << "-----------------------------------------\n";
	if(resp==1){
		
		cin.ignore();
		cout<<"Nombre: ";getline(cin,NEW[0].name);
		cout<<"DNI: ";getline(cin,NEW[0].DNI);
		cout<<"Fecha de nacimiento: \n"<<"Dia: ";cin>>NEW[0].FN.dia;
		cout<<"Mes: ";cin>>NEW[0].FN.mes;
		cout<<"Anio: ";cin>>NEW[0].FN.anio;
		
		OrdenaArreglo(PER,NEW,cantper);
		cout << "-------------------------------------------\n";
	}else if(resp==2){
		Fecha F;
		cout<<"Fecha de nacimiento: \n"<<"Dia: ";cin>>F.dia;
		cout<<"Mes: ";cin>>F.mes;
		cout<<"Anio: ";cin>>F.anio;
		BusquedaBinaria(PER,F,cantper);
		cout << "-----------------------------------------\n";
    
	}
	if(resp==3){
		mostrarPersonas(PER,cantper);
		cout << "---------------------------------------\n";
	}
	
	}while(resp!=0);
    
    return 0;
}

