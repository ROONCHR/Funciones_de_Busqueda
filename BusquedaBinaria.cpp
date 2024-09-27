#include <iostream>
using namespace std;
int  BusquedaBinaria(int A[],int n,int dato){
	int izq=0;
	int der=n;
	int cen =0;
	int m;
	int pos;
	while(izq<der && cen==0){
		m=(izq+der)/2;
		if(A[m]==dato){
			cen =1;
		}else if(A[m]<dato){
			izq = m+1;	
		}else{
			der=m-1;
		}
		
	}
	if(cen==1){
		pos =m;
	}else{
		pos=-izq;
	}
	return pos;
	
	
}

int main(){
	
	int resp;
	int tam=10;
	int dato;
	cout<<"Tenemos los datos del arreglo de manera Ordenada(las posiciones se cuentan desde el cero) :"<<endl;
	int arreglo[tam]={10,15,20,23,29,48,56,58,60,64};
	cout<<"Arreglo: ( ";
	
		for(int i=0; i<tam;i++){
			if(i==tam-1){
				cout<<arreglo[i]<<" )";
			}else{
				cout<<arreglo[i]<<" , ";
			}	
		}
	
	cout<<"Ingrese el numero a buscar: " ;
	cin>>dato;
	cout<<endl;
	
	int posi= BusquedaBinaria(arreglo,tam,dato);
	
	if(posi==-1){
		cout<<"El numero no se encuentra en el arreglo";
		
	}else{
		cout<<"numero encontrado es : "<<arreglo[posi]<<" y esta en la posicion  "<<posi;
	}
	return 0;
}
	
