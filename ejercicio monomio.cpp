#include <iostream>
using namespace std;
struct Monomio {
    int coef;
    int exp;
};

bool  Busca(Monomio MON[],int n,int coef,int exp){
	int cen =false;
	int i=0;
	while(i<n ){
		if(MON[i].coef==coef && MON[i].exp==exp){
			cen = true;
		}
		i=i+1;
	}
	
	return cen;
	
	
}
int main() {
    int tam=0;
    cout<<"Ingrese la cantidad de terminos: ";cin>>tam;
    Monomio MON[tam];
    for(int i=0; i<tam;i++){
    	cout<<"TERMINO"<<i+1<<endl<<"coeficiente: ";cin>>MON[i].coef;
    	cout<<"exponente: ";cin>>MON[i].exp;

	}

    cout<<"Polinomio: ";
    for (int i = 0; i < tam; i++) {
    	if(i<tam-1){
    		cout << MON[i].coef<< "x^" << MON[i].exp <<"  +  ";
		}else{
			cout << MON[i].coef<< "x^" << MON[i].exp ;
		}
        
    }
    int coef;
    int exp;
    cout<<"\nPROBAR LA BUSQUEDA: "<<endl<<"Ingrese el Coeficiente: ";cin>>coef;
    cout<<"Ingrese el exponente: ";cin>>exp;
    
    
    if (Busca(MON,tam,coef,exp)) {
        cout << "El monomio " << coef<< "x^" << exp << " se encuentra en el polinomio." << endl;
    } else {
        cout << "El monomio " << coef<< "x^" << exp << " NO se encuentra en el polinomio." << endl;
    }

    return 0;
}

	
	
