#include <iostream>
#include<conio.h>
using namespace std;

struct Pilas{
    string dato;
    Pilas *siguiente;
};

struct Nodo{
    string dato;
    Nodo *siguiente;
};

void insertarLista(Nodo *&, string);
void mostrarLista(Nodo*);
//prototipo de funcion
void agregarpila(Pilas *&, string);
void sacarpila(Pilas *&, string &);
int operando(string);

int main(){
    Nodo *lista = NULL;
    Pilas *pila=NULL;
    string cadena,d,dato;
    int valor,valor_aux;
    cout << "dame la expresione que deceas: ";
    cin >> cadena;//4*(5+6-(8/2^3)-7)-1
    for(int i=0; i<cadena.size(); i++){
            d=cadena[i];
            if(d<="0" || d>="9"){//este if es donde valora solo signos;
                if(pila!=NULL){
                    valor=operando(d);//aqui le damos un valor a el signo actual
                    if(valor==0||valor==5){// 4=( ; 5=) ...esto es para cuando hay parentesis
                            if(valor==0){
                                agregarpila(pila,d);//agregamos a la pila (
                            }
                            if(valor==5){
                                do{
                                    sacarpila(pila,dato);//aqui sacamos el ultimo signo insertado en la pila
                                    valor_aux=operando(dato);//aqui le damos un valor al signo que sacamos de la pila
                                    if(valor!=0){//mientras no sea ( se insertaran los signos en la pila
                                        insertarLista(lista,dato);//insertamos en la lista el signo de la pila
                                    }
                                }while(valor_aux!=0);//cuando saquemos un ( significa que cerro el parentesis y dejamos de sacar elementos;
                            }
                    }
                    else{//cuando los signos no son parentesis...
                        sacarpila(pila,dato);//aqui sacamos el ultimo signo insertado en la pila
                        valor_aux=operando(dato);//aqui le damos un valor al signo que sacamos de la pila
                        if(valor<=valor_aux){//el signo en la pila es mayor o igual que el signo que se quiere insertar
                            insertarLista(lista,dato);//insertamos en la lista el signo de la pila
                            agregarpila(pila,d);//agregamos a la pila el signo que estamos revisando
                        }
                        else{
                            agregarpila(pila,dato);//se agrega a la pila nuevamente el signo de la pila
                            agregarpila(pila,d);//se agrega a la pila el sino que se esta revisando
                        }
                    }
                }
                else{//cuando la pila rste vacia y no hay nada con que comparar,se agrega directamente a la pila
                    agregarpila(pila,d);
                }
            }
            else{//cuando son numeros se agregan directamente a la lista
                insertarLista(lista,d);
            }
    }
    while(pila!=NULL)
    {
        sacarpila(pila,dato);
        insertarLista(lista,dato);
    }
    cout << endl;
    mostrarLista(lista);
return 0;
};

int operando(string d){
    int valor;
    if(d=="+" || d=="-"){
        valor=1;
    }
    if(d=="*" || d=="/"){
        valor=2;
    }
    if(d=="^"){
        valor=3;
    }
    if(d=="("){//"("tiene que ser menor para que cuando se haga la comparacion se inserte cualquier signo escepto ")"
        valor=0;
    }
    if(d==")"){
        valor=5;
    }
    return valor;
}

void agregarpila(Pilas *&pila, string n)
{
    Pilas *nuevonodo=new Pilas();
    nuevonodo->dato=n;
    nuevonodo->siguiente=pila;
    pila=nuevonodo;
    //cout << "\tElemento " << n << " agregado correctamente" << endl;
}

void sacarpila(Pilas *&pila, string &n){
    Pilas
     *aux=pila;
    n = aux->dato;
    pila = aux->siguiente;
    //cout << "\tElemento " << aux->dato << " extraido correctamente" << endl;
    delete aux;
}

void insertarLista(Nodo *&lista, string n){
    if(n=="("){
        return;
    }
    Nodo *nuevo_nodo=new Nodo();
    nuevo_nodo->dato=n;

    Nodo *aux1=lista;
    Nodo *aux2;

    while(aux1 != NULL){
        aux2=aux1;
        aux1=aux1->siguiente;
    }

    if(lista==aux1){
            lista=nuevo_nodo;
    }
    else{
        aux2->siguiente=nuevo_nodo;
    }
    nuevo_nodo->siguiente=aux1;
    //cout << "\t\t Elemento " << n << " insertado correctamente" << endl;
}

void mostrarLista(Nodo *lista){
    Nodo *actual =new Nodo();
    actual=lista;

    while(actual!=NULL){
        cout <<actual -> dato;
        actual=actual->siguiente;
    }
}
