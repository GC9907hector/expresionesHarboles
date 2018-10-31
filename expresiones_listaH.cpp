#include <iostream>
#include <conio.h>
using namespace std;

struct Nodo{
    string dato;
    Nodo *siguiente;
};

//prototipo funciones
void insertarLista(Nodo *&, string);
void mostrarLista(Nodo*);

int main(){
    Nodo *lista = NULL;
    string dato;
    string d;

    cout << "dame la expresione que deceas: ";
    cin >> dato;
    cout << "\n\tel tamaño de la expresion es: " << dato.size() << endl;
    for(int i=0; i<dato.size(); i++){
            cout << endl << dato[i] << endl;
            d=dato[i];
            insertarLista(lista,d);
    }
    cout << endl;
    mostrarLista(lista);
    getch();
    return 0;
}

void insertarLista(Nodo *&lista, string n){
    Nodo *nuevo_nodo=new Nodo();
    nuevo_nodo->dato=n;

    Nodo *aux1=lista;
    Nodo *aux2;


    while((aux1 != NULL) /*&& (aux1->dato>n)*/){
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
    cout << "\t Elemento " << n << " insertado correctamente" << endl;
}

void mostrarLista(Nodo *lista){
    Nodo *actual =new Nodo();
    actual=lista;

    while(actual!=NULL){
        cout << "->" << actual -> dato << endl;
        actual=actual->siguiente;
    }
}
