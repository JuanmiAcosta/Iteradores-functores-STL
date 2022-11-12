#include <iostream>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

bool myfunction (stack<int> &i,stack<int> &j) { 
	if(!i.empty()&&!j.empty()){
		return (i.top()<j.top());	
	}
	return (-1); 
} //Este ser�a el funtor a aniadir, pero justo es el de por defecto

void Borrar(list<stack<int> > & L, int elemento){ // el m�todo borra el top de las pilas de enteros que coincidad con elemento y ordena de menor a mayor la lista (por defecto)
	list<stack<int> >::iterator it;
	list<stack<int> >::iterator it2;
	it = L.begin();
	
	for (it=L.begin(); it!=L.end(); ++it){
		if ((*it).top() == elemento){
			(*it).pop();			
		}	
		if((*it).empty()){
			it=L.erase(it);
		}				
	}
		
	L.sort(myfunction);	
}

ostream& operator<<(ostream &flujo, const stack<int> &pila){ // Sobrecargamos el operador "<<" para que muestre solo el top de las pilas de enteros de la lista
	stack<int> aux=pila;
	while(aux.size()!=0){
		flujo << aux.top() << "\t";
		aux.pop();
	}
	flujo<< "\n";
    
    return flujo;
}

int main (){
	
	const int MAX_1=2, MAX_2=4, MAX_3=6;
	
	list<stack<int> > lista;
	list<stack<int> >::iterator it; // Generamos un iterador sobre la estructura lineal "list" lista para recorrerla
	
	stack<int> pila1;
	stack<int> pila2;
	stack<int> pila3;
	stack<int> pila4;
	stack<int> pila5;
	stack<int> pila6;
	
	
	pila1.push(1);	pila1.push(9);	pila1.push(2);	
	pila2.push(0);	pila2.push(1);	pila2.push(2);	
	pila3.push(2);	
	pila4.push(7);	pila4.push(10);	pila4.push(9);	pila4.push(3);		
	pila5.push(2);	pila5.push(4);	
	pila6.push(2);	pila6.push(8);	

	it = lista.begin(); //Colocamos el iterador al principio de la lista
	
	lista.push_back(pila1); // 0 , 1 (top 1)
	lista.push_back(pila2); // 8 , 7 , 6 , 5 (top 5)
	lista.push_back(pila3); // 0 , 1 , 2 , 3 , 4 , 5 (top 5)
	lista.push_back(pila4);
	lista.push_back(pila5);
	lista.push_back(pila6);
	cout << "La lista es: \n";
	
	for (it=lista.begin(); it!=lista.end(); ++it){ // 1 , 5 , 5
		cout << ' ' << (*it);
	}
	
	cout << "\n";
	cout << "El elemento a borrar es el 2\n"; //Borramos los top que sean 5 y ordenamos de menor a mayor
	
	Borrar(lista, 2); // 1, 6 , 4 y se ordena 1 , 4 , 6

	
	cout << "Borrado los top 5; Los top ordenados son: \n";
	
	for (it=lista.begin(); it!=lista.end(); ++it){ // 1 , 4 , 6
		cout << ' ' << *it;
	}
	
}
