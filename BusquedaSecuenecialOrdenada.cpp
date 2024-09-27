#include <iostream>
using namespace std;
int  BusquedaSeOrd(int A[],int n,int dato){
	int pos;
	int i=0;
	while(i<n && A[i]<dato){
		i=i+1;
	}
	if(i>n || A[i]!=dato){
		pos = -i;
	}else{
		pos = i;
	}
	return pos;
	
	
}

int main(){
	
	int resp;
	int tam=10;
	int dato;
	cout<<"Tenemos los datos del arreglo de manera Ordenada (las posiciones se cuentan desde el cero):"<<endl;
	int arreglo[tam]={10,15,20,23,29,48,56,58,60,64};
	cout<<"Arreglo: ( ";
	
		for(int i=0; i<tam;i++){
			if(i==tam-1){
				cout<<arreglo[i]<<" )";
			}else{
				cout<<arreglo[i]<<" , ";
			}	
		}
	cout<<endl;
	cout<<"Ingrese el numero a buscar: " ;
	cin>>dato;
	cout<<endl;
	
	int posi= BusquedaSeOrd(arreglo,tam,dato);
	
	if(posi==-1){
		cout<<"El numero no se encuentra en el arreglo";
		
	}else{
		cout<<"numero encontrado es : "<<arreglo[posi]<<" y esta en la posicion  "<<posi;
	}
	return 0;
}
	
