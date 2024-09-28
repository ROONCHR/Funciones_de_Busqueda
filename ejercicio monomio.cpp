#include <iostream>
using namespace std;
struct Monomio {
    int coeficiente;
    int exponente;
};

bool  BusquedaSecDes(Monomio MON[],int n,int coef,int exp){
	int cen =false;
	int i=0;
	while(i<n ){
		if(MON[i].coeficiente==coef && MON[i].exponente==exp){
			cen = true;
		}
		i=i+1;
	}
	
	return cen;
	
	
}
int main() {
    int tam=5;
    Monomio monomios[tam] = {
        {3, 2},  
        {5, 4},  
        {-2, 3}, 
        {1, 1},  
        {7, 0}  
    };

    cout<<"Polinomio: ";
    for (int i = 0; i < tam; i++) {
    	if(i<tam-1){
    		cout << monomios[i].coeficiente << "x^" << monomios[i].exponente <<"  +  ";
		}else{
			cout << monomios[i].coeficiente << "x^" << monomios[i].exponente ;
		}
        
    }
    int coef;
    int exp;
    cout<<"PROBAR LA BUSQUEDA: "<<endl<<"Ingrese el Coeficiente: ";cin>>coef;
    cout<<"Ingrese el exponente: ";cin>>exp;
    
    
    if (BusquedaSecDes(monomios,tam,coef,exp)) {
        cout << "El monomio " << coef<< "x^" << exp << " se encuentra en el polinomio." << endl;
    } else {
        cout << "El monomio " << coef<< "x^" << exp << " NO se encuentra en el polinomio." << endl;
    }

    return 0;
}

	
	
