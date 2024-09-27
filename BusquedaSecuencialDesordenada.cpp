#include <iostream>
using namespace std;
int  BusquedaSecDes(int A[],int n,int dato){
	int pos =-1;
	int i=0;
	while(i<n && A[i]!=dato){
		i=i+1;
	}
	if(i<=n){
		pos = i;
	}
	return pos;
	
	
}

int main(){
	
	int resp;
	int tam;
	int dato;
	cout<<"Ingrese el tamaño del arreglo: " ;
	cin>>tam;
	
	int arreglo[tam];
	cout<<"ingrese los datos del arreglo de manera desordenada(las posiciones se cuentan desde el cero)  :"<<endl;
	for(int i=0;i<tam;i++){
		cout<<"P"<<i<<": ";
		cin>>arreglo[i];
	}
	
	cout<<"Ingrese el numero a buscar: " ;
	cin>>dato;
	cout<<endl;
	
	int posi= BusquedaSecDes(arreglo,tam,dato);
	
	if(posi==-1){
		cout<<"El numero no se encuentra en el arreglo";
		
	}else{
		cout<<"numero encontrado es: "<<arreglo[posi]<<" y esta en la posicion  "<<posi;
	}
	return 0;
}
	
