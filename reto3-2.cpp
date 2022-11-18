#include <iostream>
#include <stack>
#include <list>
#include <vector>
#include <algorithm>

/**
* @file reto3-2.cpp
* @Author Juan Miguel Acosta Ortega y Luis Soto Torres
* @date 18/11/2022
* @brief Reto 3.2 
*/

using namespace std;

/**
      @brief 
	  @param <em>datos</em> 
      @param <em>tope</em> 
      @param <em>base</em>
      @param <em>numPila</em>
      @param <em>num</em>
      @pre 
      @post 
      @return 
*/

void push(vector<stack<int>> &datos,stack<int *> &tope,stack<int *> &base,int numPila, int num){
    stack<int *> aux,aux2;
    bool vacio=false;
    if(datos.at(numPila).empty()){
        vacio=true;
    }
    datos.at(numPila).push(num);    
    bool sigue=true;

    for(int i=0;i<datos.size()&&sigue;i++){
        
        if(i==numPila){
            
            tope.top()=&datos.at(numPila).top();
            if(vacio==true){
                base.top()=tope.top();
            }
            sigue=false;
        }else{
            if(vacio==true){
                aux2.push(base.top());
                base.pop();
            }
            aux.push(tope.top());
            tope.pop();
        }
    }
    int numAux=aux.size();
    for(int i=0;i<numAux;i++){
        if(vacio==true){
         
            base.push(aux2.top());
            aux2.pop();   
        }
        tope.push(aux.top());
        aux.pop();
    }
    
    

}

/**
      @brief 
	  @param <em>datos</em> 
      @param <em>tope</em> 
      @param <em>base</em>
      @param <em>numPila</em>
      @pre 
      @post 
      @return 
*/

void pop(vector<stack<int>> &datos,stack<int *> &tope,stack<int *> &base,int numPila){
    stack<int *> aux,aux2;
    bool vacio=false;
    bool sigue=true;
    if(datos.at(numPila).empty()){
        vacio=true;
    }else{
        datos.at(numPila).pop();    
        
    }
    

    for(int i=0;i<datos.size()&&sigue&&!vacio;i++){
        
        if(i==numPila){            
            tope.top()=&datos.at(numPila).top();
            if(vacio==true){
                base.top()=tope.top();
            }
            sigue=false;
        }else{
            if(vacio==true){
                aux2.push(base.top());
                base.pop();
            }
            aux.push(tope.top());
            tope.pop();
        }
    }
    int numAux=aux.size();
    for(int i=0;i<numAux;i++){
        if(vacio==true){
         
            base.push(aux2.top());
            aux2.pop();   
        }
        tope.push(aux.top());
        aux.pop();
    }
    


    
}

/**
      @brief Método creado para mostrar la información del vector de pilas de enteros.
	  @param <em>datos</em> 
      @param <em>tope</em> 
      @param <em>base</em>
      @pre 
      @post 
      @return 
*/

void mostrarInfo(vector<stack<int>> &datos,stack<int *> &tope,stack<int *> &base){
vector<stack<int>> datos2=datos;
stack<int *> tope2=tope;
stack<int *> base2=base;
//MOSTRAR TODA LA INFORMACIÓN
    int numAux = datos2.size();    
    cout << "Base :\t";
    for (int j = 0; j < numAux; j++)
    {

        cout << *(base2.top()) << "\t";
        base2.pop();
    }
    cout << endl;

    cout << "Tope:\t";
    for (int j = 0; j < numAux; j++)
    {

        cout << *(tope2.top()) << "\t";
        tope2.pop();
    }
    cout << endl;
    for (int i = 0; i < numAux; i++)
    {
        cout << "Pila " << i << " : ";
        int numAux2=datos2.at(i).size();
        for (int j = 0; j < numAux2; j++)
        {
            cout << (datos2.at(i).top()) << "\t";
            datos2.at(i).pop();
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;

    
}

/**
      @brief Sobrecarga del operador de salida para mostrar las pilas según su top por la salida estándar.
	  @param <em>flujo</em> es el flujo del operador de salida.
      @param <em>pila</em> la pìla de la que se "extraerá" el top.
      @return Devuelve por referencia el flujo del operador de salida.
*/

ostream &operator<<(ostream &flujo, const stack<int> &pila)
{ // Sobrecargamos el operador "<<" para que muestre solo el top de las pilas de enteros de la lista

    flujo << pila.top() << "\n";

    return flujo;
}

/**
      @brief En el main se crean las pilas necesarias para el ejemplo, y además la pila base y la pila tope. Se hace uso de los métodos implementados.
*/

int main()
{

    stack<int *> tope;
    stack<int *> base;

    int tam = 3;

    vector<stack<int>> datos(tam);
    stack<int> aux;
    //CREO 3 PILAS CON LOS SIGUIENTES VALORES: 0 1 2
    //CREO TAMBIÉN LA PILA BASE Y TOPE Y ASIGNO LOS VALORES CORRESPONDIENTES: 0 0 0 Y 2 2 2 PARA UNA MAYOR FACILIDAD DE LECTURA
    for (int j = 0; j < tam; j++)
    {

        int numero = 0;
        int *puntAux, *puntAux2;
        for (int i = 0; i < tam; i++)
        {
            aux.push(numero);
            if (numero == 0)
            {
                puntAux = &aux.top();
                base.push(puntAux);
            }
            else if (numero == 2)
            {
                puntAux2 = &aux.top();
                tope.push(puntAux2);
            }
            numero++;
        }
        datos.at(j) = aux;  
        int numAux=aux.size();      
        for(int i=0;i<numAux;i++){
            aux.pop();
        }
        
        
    }

    //MUESTRO VALORES ORIGINALES
    mostrarInfo(datos,tope,base);

    //BORRO VALORES DE LAS PILAS DEL VECTOR DATOS
    pop(datos,tope,base,0);
    pop(datos,tope,base,1);
    pop(datos,tope,base,2);
    mostrarInfo(datos,tope,base);

    //METO VALORES A LAS PILAS DEL VECTOR DATOS
    push(datos,tope,base,0,5);
    push(datos,tope,base,1,6);
    push(datos,tope,base,2,7);
    mostrarInfo(datos,tope,base);

}
