#include<iostream>
#include<string>
using namespace std; 


struct administrar 
{
    int id;
    string perfil, nombre_user;
};


administrar solicitarDatos(void) 
{
    administrar p;
    cout << "Ingrese el id: ";
    cin >> p.id;
    cin.ignore('\n');
    cout << "Ingrese su name: ";
    getline (cin, p.nombre_user);
    cout << "Ingrese un perfil (administrador, cliente o trabajador): ";
    getline (cin, p.perfil);   
    
    return p;
}

void mostrarDatos(administrar d)
{
    cout << endl;
    cout << "id: " << d.id << endl;
    cout << "Name: " << d.nombre_user << endl;
    cout << "Perfil: " << d.perfil << endl;
}


typedef administrar T;
const T noValido = {0};

//STRUCT
struct nodo
{
    T dato;
    nodo *sig;
    nodo *ant;
};

class ListaDoble
{
    private:
        nodo *pPrincipio;

    public:
        ListaDoble();
        ~ListaDoble();
        void InsInicio(T);
        void InsFinal(T);
        void mostrarLista(void);
        void mostrarListaReversa(void);
       
};

//constructor
ListaDoble::ListaDoble(void)
{
    pPrincipio = NULL;
}

//destructor
ListaDoble::~ListaDoble()
{
    cout << "Ejecutándose el destructor" << endl;
    nodo *p;
    while(pPrincipio){
        p = pPrincipio;
        pPrincipio = pPrincipio->sig;
        delete p;
    }
}

void ListaDoble::InsInicio(T dato)
{
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = pPrincipio;
    if(pPrincipio != NULL)
        pPrincipio->ant = nuevo;
    pPrincipio = nuevo;
}


void ListaDoble::InsFinal(T dato)
{
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    if(!pPrincipio){
        pPrincipio = nuevo;
        pPrincipio->sig = pPrincipio->ant = NULL;
    }
    else{
        nodo *saltarin = pPrincipio;
        while(saltarin->sig != NULL)
            saltarin = saltarin->sig;
        saltarin->sig = nuevo;
        nuevo->ant = saltarin;
        nuevo->sig = NULL;
    }
}


void ListaDoble::mostrarLista(void)
{
    nodo *saltarin = pPrincipio;
    while(saltarin != NULL)
    {
        mostrarDatos(saltarin->dato);
        saltarin = saltarin->sig;
    }
}

void ListaDoble::mostrarListaReversa(void)
{
    if(!pPrincipio)
        return;
    nodo *p = pPrincipio;
    nodo *z = NULL;
    while(p)
    {
        z = p;
        p = p->sig;
    }
    while(z)
    {
        mostrarDatos(z->dato);
        z = z->ant;
    }
}