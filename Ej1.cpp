#include <iostream>
#include <stack>
#include <list>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

bool compareTops (const stack<int> &first, const stack<int> &second){
	return (first.top() < second.top());	
}


void Borrar(list<stack<int> > & L, int elemento){ // el método borra el top de las pilas de enteros que coincidad con elemento y ordena de menor a mayor la lista (por defecto)
	list<stack<int> >::iterator it;
	it = L.begin();
	
	for (it=L.begin(); it!=L.end(); ++it){
		if ((*it).top() == elemento){
			(*it).pop();
		}				
	}
	
	L.sort(); 
}

ostream& operator<<(ostream &flujo, const stack<int> &pila){ // Sobrecargamos el operador "<<" para que muestre solo el top de las pilas de enteros de la lista
	if (pila.size() != 0){
		flujo << pila.top() << "\n";		
	}
    return flujo;
}

int main (){
	
	list<stack<int> > lista;
	list<stack<int> >::iterator it; // Generamos un iterador sobre la estructura lineal "list" lista para recorrerla
	
	stack<int> pila1;
	stack<int> pila2;
	stack<int> pila3;
	stack<int> pila4;
	stack<int> pila5;
	stack<int> pila6;
	
	pila1.push(1);
	pila1.push(9);
	pila1.push(2);
	
	pila2.push(0);
	pila2.push(1);
	pila2.push(2);
	
	pila3.push(2);
	
	pila4.push(7);
	pila4.push(10);
	pila4.push(9);
	pila4.push(3);
	
	pila5.push(2);
	pila5.push(4);
	
	pila6.push(2);
	pila6.push(8);
	
	it = lista.begin(); //Colocamos el iterador al principio de la lista
	
	lista.push_back(pila1); 
	lista.push_back(pila2); 
	lista.push_back(pila3);
	lista.push_back(pila4);
	lista.push_back(pila5);
	lista.push_back(pila6);
	
	cout << "Los top sin orden son: \n";
	
	for (it=lista.begin(); it!=lista.end(); ++it){ 
		cout << "\t" << *it << endl;
	}
	
	cout << "\n";
	cout << "El elemento a borrar es el 2\n"; //Borramos los top que sean 2 y ordenamos de menor a mayor
	
	Borrar(lista, 2); 
	
	cout << "Borrado los top 2; \nLos top ordenados son: \n";
	cout << endl;
	
	for (it=lista.begin(); it!=lista.end(); ++it){
		cout << "\t" << *it << endl;
	}
	
	return(0);
	
}
