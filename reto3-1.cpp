#include <iostream>
#include <stack>
#include <list>
#include <algorithm>

/**
* @file reto3-1.cpp
* @Author Juan Miguel Acosta Ortega y Luis Soto Torres
* @date 18/11/2022
* @brief Reto 3.1 (Borrar y ordenar una lista de pilas de enteros)
*/

using namespace std;

/**
      @brief El functor que solapará al que tiene por defecto el método sort de list, ordenará las pilas de menor a mayor según sus top.
	  @param <em>i</em> 1ª pila.
      @param <em>j</em> 2ª pila.
      @return Devuelve un booleano que indica cuál es el top menor.
*/

bool ordenaTopMenorMayor (stack<int> &i,stack<int> &j) { 
	if(!i.empty()&&!j.empty()){
		return (i.top()<j.top());	
	}
	return (-1); 
} 

/**
      @brief Borra los top de la lista que sea igual al elemento pasado, acto seguido ordena la lista según un functor pasado al método sort de list.
	  @param <em>L</em> es la lista de pilas de enteros con la que se trabajará.
      @param <em>elemento</em> es el entero a borrar de los top de las pilas de la lista.
      @pre No pasa nada si alguna pila se vacía, se controlará en el método
      @post Borra los top de las pilas que sean iguales al segundo parámetro pasado, y acto seguido ordena las pilas de menor a mayor según sus top.
      @return No devuelve una copia, trabaja con las pilas de la lista por referencia y no por valor.
*/

void Borrar(list<stack<int> > & L, int elemento){ 
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
		
	L.sort(ordenaTopMenorMayor);	
}

/**
      @brief Sobrecarga del operador de salida para mostrar las pilas según su top por la salida estándar.
	  @param <em>flujo</em> es el flujo del operador de salida.
      @param <em>pila</em> la pìla de la que se "extraerá" el top.
      @return Devuelve por referencia el flujo del operador de salida.
*/

ostream& operator<<(ostream &flujo, const stack<int> &pila){ // Sobrecargamos el operador "<<" para que muestre solo el top de las pilas de enteros de la lista
	stack<int> aux=pila;
	while(aux.size()!=0){
		flujo << aux.top() << "\t";
		aux.pop();
	}
	flujo<< "\n";
    
    return flujo;
}

/**
      @brief En el main simplemente llenamos una lista de pilas de enteros con las pilas del ejemplo y llamammos a la función Borrar() correspondiente.
*/

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
	
	lista.push_back(pila1); 
	lista.push_back(pila2); 
	lista.push_back(pila3); 
	lista.push_back(pila4);
	lista.push_back(pila5);
	lista.push_back(pila6);
	cout << "La lista es: \n";
	
	for (it=lista.begin(); it!=lista.end(); ++it){ 
		cout << ' ' << (*it);
	}
	
	cout << "\n";
	cout << "El elemento a borrar es el 2\n"; //Borramos los top que sean 2 y ordenamos de menor a mayor
	
	Borrar(lista, 2); 

	
	cout << "Borrado los top 2; Los top ordenados son: \n";
	
	for (it=lista.begin(); it!=lista.end(); ++it){ 
		cout << ' ' << *it;
	}
	
}
