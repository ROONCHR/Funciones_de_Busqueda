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
    string nombres;
    Fecha fechaNacimiento; 
};
void mostrarPersonas(Persona personas[], int tam) {
    for (int i = 0; i < tam; i++) {
        cout << "Persona " << i + 1 << ":\n";
        cout << "DNI: " << personas[i].DNI << endl;
        cout << "Nombre: " << personas[i].nombres << endl;
        cout << "Fecha de Nacimiento: " << personas[i].fechaNacimiento.dia << "/"
             << personas[i].fechaNacimiento.mes << "/" << personas[i].fechaNacimiento.anio << endl;
        cout << "-----------------------------\n";
    }
}
bool ComparaFechas(Persona PERSON[],Fecha  fecha,int i){
	int cont=0;
	int retorna=false;
	if(PERSON[i].fechaNacimiento.anio>fecha.anio){
		retorna= true;
	}else if(PERSON[i].fechaNacimiento.anio==fecha.anio&&PERSON[i].fechaNacimiento.mes>fecha.mes){
		retorna=true;
	}else if(PERSON[i].fechaNacimiento.anio==fecha.anio&&PERSON[i].fechaNacimiento.mes==fecha.mes&&PERSON[i].fechaNacimiento.dia>fecha.dia){
		retorna = true;
	}
		
	return retorna;
	
	
}
void OrdenaArreglo(Persona PERSON[],Persona NUEVO[],int &n){
	
	int i=n;
	Fecha AUX=NUEVO[0].fechaNacimiento;
	if(n>0){
		
		while(i>=0 && ComparaFechas(PERSON,AUX,i)==true ){
			PERSON[i+1]=PERSON[i];
			i--;
			
		}
		PERSON[i+1]=NUEVO[0];
		
	}else{
		PERSON[0]=NUEVO[0];
	}
	n++;
	
	
}
void BusquedaBinaria(Persona PERSON[],Fecha f,int n){
	int izq=0;
	int der=n;
	int cen=0;
	int m;
	while(izq<=der&& cen==0){
		m=(izq+der)/2;
		if(PERSON[m].fechaNacimiento.anio==f.anio&&PERSON[m].fechaNacimiento.mes==f.mes&&PERSON[m].fechaNacimiento.dia==f.dia){
			cen=1;
		}else if(ComparaFechas(PERSON,f,m)==false){
			izq=m+1;
		}else{
			der=m-1;
		}
	}
	if(cen==1){
		cout << "Persona " << m + 1 << ":\n";
        cout << "DNI: " << PERSON[m].DNI << endl;
        cout << "Nombre: " << PERSON[m].nombres << endl;
        cout << "Fecha de Nacimiento: " <<PERSON[m].fechaNacimiento.dia << "/"
             << PERSON[m].fechaNacimiento.mes << "/" << PERSON[m].fechaNacimiento.anio << endl;
        cout << "-----------------------------\n";
    }else{
    	cout<<"La fecha no coincide con ningun dato del arreglo.\n";
	}
	
	 
	
}

int main() {
    int cantper=0;
    int resp;
    Persona PERSON[100];
    Persona NUEVO[1];
	
	do{
	
	cout<<"Que desea hacer?:";
	
	cout<<"\n1)Agregar Personas."<<"\n2)Busqueda"<<"\n3)Mostrar personas"<<"\n0)Salir"<<"\nresp: ";
	cin>>resp;
	cout << "-----------------------------------------\n";
	if(resp==1){
		
		cin.ignore();
		cout<<"Nombre: ";getline(cin,NUEVO[0].nombres);
		cout<<"DNI: ";getline(cin,NUEVO[0].DNI);
		cout<<"Fecha de nacimiento: \n"<<"Dia: ";cin>>NUEVO[0].fechaNacimiento.dia;
		cout<<"Mes: ";cin>>NUEVO[0].fechaNacimiento.mes;
		cout<<"Anio: ";cin>>NUEVO[0].fechaNacimiento.anio;
		
		OrdenaArreglo(PERSON,NUEVO,cantper);
		cout << "-------------------------------------------\n";
	}else if(resp==2){
		Fecha BUSCAR;
		cout<<"Fecha de nacimiento: \n"<<"Dia: ";cin>>BUSCAR.dia;
		cout<<"Mes: ";cin>>BUSCAR.mes;
		cout<<"Anio";cin>>BUSCAR.anio;
		BusquedaBinaria(PERSON,BUSCAR,cantper);
		cout << "-----------------------------------------\n";
    
	}else if(resp==3){
		mostrarPersonas(PERSON,cantper);
		cout << "---------------------------------------\n";
	}
	
	}while(resp!=0);
    
    return 0;
}

