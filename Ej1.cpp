#include<iostream>
#include<stack>
#include<list>
#include<algorithm>

using namespace std;

//bool myfunction (int i,int j) { return (i<j); } //Este sería el funtor a aniadir, pero justo es el de por defecto

void Borrar(list<stack<int> > & L, int elemento){
	list<stack<int> >::iterator it;
	it = L.begin();
	
	for (it=L.begin(); it!=L.end(); ++it){
		if ((*it).top() == elemento)
			L.erase(it);		
	}	
}

ostream& operator<<(ostream &flujo, const stack<int> &pila){
	
	flujo << pila.top() << "\n";
    
    return flujo;
}

int main (){
	
	const int MAX_1=2, MAX_2=4, MAX_3=6;
	
	list<stack<int> > lista;
	list<stack<int> >::iterator it;
	
	stack<int> pila1;
	stack<int> pila2;
	stack<int> pila3;
	
	
	for (int i=0; i<MAX_1; i++){
		pila1.push(i);
	}
	
	for (int i=8; i>MAX_2; i--){
		pila2.push(i);
	}
	
	for (int i=0; i<MAX_3; i++){
		pila3.push(i);
	}
	
	it = lista.begin();
	lista.push_back(pila1); // 0 , 1 (top 1)
	lista.push_back(pila2); // 8 , 7 , 6 , 5 (top 5)
	lista.push_back(pila3); // 0 , 1 , 2 , 3 , 4 , 5 (top 5)
	
	cout << "Los top sin orden son: \n";
	
	for (it=lista.begin(); it!=lista.end(); ++it){ // 1 , 5 , 5
		cout << ' ' << *it;
	}
	
	cout << "\n";
	cout << "El elemento a borrar es el 5\n";
	
	Borrar(lista, 5);
	lista.sort();
	
	cout << "Borrado los top 5; Los top ordenados son: \n";
	
	for (it=lista.begin(); it!=lista.end(); ++it){ // 1 , 4 , 6
		cout << ' ' << *it;
	}
	
}
