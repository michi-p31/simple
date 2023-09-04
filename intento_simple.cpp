#include <iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct Nodo{
	int dato;
      Nodo*siguiente;
 	
 }*primero,*ultimo;
void insertarLista(Nodo*&,int);

void mostrarLista(Nodo*);

void buscarLista(Nodo*,int);

void menu();

void borrarNodo(Nodo *&,int);

void actualizarNodo(Nodo*&,int);

	Nodo *lista=NULL;


int main() {


	
	menu();
	getch();
	return 0;
}

void menu(){
	int opcion,dato;
	do {
		
		cout<<"\n*MENU\n";
		cout<<"1.Quieres Insertar un Elemento?\n";
		cout<<"2.Quieres Buscar un Elemento\n";
		cout<<"3.Quieres Eliminar un Elemento\n";
		cout<<"4.Quieres Actualizar un Elemento\n";
		cout<<"5.SALIR \n";
		cout<<"Deseo: ";
		cin>>opcion;
		
		switch(opcion){
			case 1:
			
			  cout<<"Digite numero  ";
            	cin>>dato;
		    	insertarLista(lista,dato);
              break;		 
		 	case 2:
			    	cout<<"Digite numero a buscar  ";
                 	cin>>dato;
                 	buscarLista(lista,dato);
			 	mostrarLista(lista);

			 break;
			case 3:
			cout<<"Elemento que voy a borrar es: ";
			cin>>dato;
			borrarNodo(lista,dato);
						mostrarLista(lista);

			break;
			case 4:
			cout<<"Elemento que a modificar es: ";
			cin>>dato;
			actualizarNodo(lista,dato);
			        mostrarLista(lista);
			break;
			
		}
		
		
	}while(opcion!=5);
	
}

void insertarLista(Nodo*&lista,int n){
    Nodo*nuevo_nodo=new Nodo();
    nuevo_nodo->dato=n;
    
    Nodo*aux1=lista;
    Nodo*aux2;
    
    while ((aux1!=NULL)&&(aux1->dato<n))
{
	
	 aux2=aux1;
	 aux1->siguiente=aux1;
}
    if(lista==aux1){
    	lista=nuevo_nodo;
	}
	else{
		aux2->siguiente=nuevo_nodo;
		nuevo_nodo->siguiente=aux1;
		aux2=nuevo_nodo;
	}
	nuevo_nodo->siguiente=aux1;
	cout<<"\tElemento insertado "<<n<<" a lista\n";
}
void mostrarLista(Nodo*lista){
	
	Nodo*actual=new Nodo();
	actual=lista;
	while (actual!=NULL){
		
		cout<<actual->dato<<"->";
		actual=actual->siguiente;
	}
	
}
void buscarLista(Nodo*lista,int n){
	bool band =false;
	Nodo*actual=new Nodo();
	actual=lista;
	while((actual!=NULL)&&(actual->dato)<=n){
	   if(actual->dato==n){
	   band=true;
	   }
	actual=actual->siguiente;
	}
	if(band==true){
		cout<<"Numero "<<n<< " si a sido encontrado en lista\n";
	}
	else{
		cout<<"Numero "<<n<<" no a sido encontrado\n";
	}
}


void borrarNodo(Nodo*&Lista,int n){
	
	if(lista!=NULL){
		
		Nodo* aux_borrar;
		Nodo *anterior=NULL;
		aux_borrar=lista;
		
		while((aux_borrar!=NULL)&&(aux_borrar->dato!=n)){
			anterior=aux_borrar;
			aux_borrar=aux_borrar->siguiente;
		}
		if(aux_borrar==NULL){
			cout<<"No existe en lista ";
		}
		else if(anterior==NULL){
			lista=lista->siguiente;
			delete aux_borrar;
			cout<<"Elemento borrado ";
		}
		else{
			anterior->siguiente=aux_borrar->siguiente;
			delete aux_borrar;
			cout<<"Elemento borrado ";
		}
	}
		
}
void actualizarNodo(Nodo*&Lista,int n){
	
	if(lista!=NULL){
		
		Nodo* aux_borrar;
		Nodo *anterior=NULL;
		aux_borrar=lista;
		
		while((aux_borrar!=NULL)&&(aux_borrar->dato!=n)){
			anterior=aux_borrar;
			aux_borrar=aux_borrar->siguiente;
		}
		if(aux_borrar==NULL){
			cout<<"No existe en lista ";
		}
		else if(anterior==NULL){
			lista=lista->siguiente;
			delete aux_borrar;
			cout<<"Elemento borrado ";
		}
		else{
			anterior->siguiente=aux_borrar->siguiente;
			delete aux_borrar;
			cout<<"Elemento borrado ";
		}
	}
	
	cout<<"\nIngrese nuevo elemento: ";
	cin>>n;
	Nodo*nuevo_nodo=new Nodo();
    nuevo_nodo->dato=n;
    
    Nodo*aux1=lista;
    Nodo*aux2;
    
    while ((aux1!=NULL)&&(aux1->dato<n))
{
	
	 aux2=aux1;
	 aux1->siguiente=aux1;
}
    if(lista==aux1){
    	lista=nuevo_nodo;
	}
	else{
		aux2->siguiente=nuevo_nodo;
		nuevo_nodo->siguiente=aux1;
		aux2=nuevo_nodo;
	}
	nuevo_nodo->siguiente=aux1;
	cout<<"\tElemento insertado "<<n<<" a lista\n";
	
	
}

