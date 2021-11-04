#include <iostream>
#include <string>
using namespace std;
/*Con el uso de una lista circular:
Hacer una administración de una veterinaria, en donde se pida el id, name del dueño, raza, peso, edad de la mascota
que pueda agregar, mostrar por id, y borrar.*/


struct Mascota{
    int id, edad, peso;
    string name, raza;
};
struct nodo{
    Mascota dato;
    nodo *sig;
    nodo *back;
    
}*prim, *ulti ;


int idM;


void agregarnodo(void){
 
   nodo *nuevo = new nodo();
   Mascota mascota;
   idM++;
   mascota.id = idM;
   cout <<"ID usuario: "<< mascota.id<< endl;
   cout <<"Ingrese nombre del duenio: ";
   getline(cin,mascota.name);
   cout <<"Ingrese raza de la mascota: ";
   getline(cin,mascota.raza);
   cout <<"Ingrese peso de la mascota: ";
   cin>> mascota.peso; cin.ignore();
   cout <<"Ingrese edad de la mascota: ";
   cin>> mascota.edad; cin.ignore();
   cout <<"Datos almacenados!!"<<endl;
 
   nuevo->dato = mascota;
   
   if (prim == NULL){
     prim = nuevo;
     ulti = nuevo;
     prim->sig = prim;
     prim->back = ulti;

   }else{
    ulti->sig = nuevo;
    nuevo->back = ulti;
    nuevo->sig =prim;
    ulti = nuevo;
    prim->back = ulti;
   
   }


}

void mostrar(void){


        nodo *saltarin= new nodo();
        saltarin = prim;
        bool encontrado = false;
        int nodobuscado = 0;
        cout <<"Ingrese el ID del usuario que quiere mostrar: ";
        cin >>  nodobuscado;
        cout << endl;
        cin.ignore();

        if (prim != NULL){
        do
        {  if (saltarin->dato.id ==nodobuscado){
            cout <<"ID ("<<saltarin->dato.id<<")"<<endl;
            cout <<"Nombre del duenio: "<<saltarin->dato.name<<endl;
            cout <<"Raza de la mascota es: "<<saltarin->dato.raza<<endl;
            cout <<"Peso: "<<saltarin->dato.peso<<" libras" <<endl;
            cout <<"Edad: " <<saltarin->dato.edad <<" anios"<<endl;

            encontrado = true;
            }

            saltarin = saltarin->sig;

        } while (saltarin != prim && encontrado!= true);
        

        if(!encontrado){
            cout <<"ID no encontrado."<<endl;
            }

        }else{
            cout <<"La lista esta vacia. Vuelva a intentarlo cuando haya agregado al menos un cliente "<<endl;
        }

       
   } 

void eliminarPersona(void)
{
	int id = 0;
	nodo *p = prim;
	nodo *q = NULL;

    
	cout<<"Ingrese el ID: "; cin>>id;

    while ((p != NULL) && (p->dato.id != id))
	{
		q = p;
		p = p->sig;
	}
	if (p == NULL)
	{
		cout << "No existe la persona con el ID ingresado" << endl;
		return;
	}

	if (prim->dato.id == id)
	{
		prim = prim->sig;

		delete (p);
		cout<<"\t*Persona eliminada*\n";
		return;
	}

	if (q == NULL)
		p = p->sig;
	else
		q->sig = p->sig;
	delete (p);
	cout<<"\t*Persona eliminada*\n";
}

void eliminarnodo(){

    nodo* actual = new nodo();
	actual = prim;
	nodo* anterior = new nodo();
	anterior = NULL;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << "Ingrese ID a borrar: ";
	cin >> nodoBuscado;
	if(prim!=NULL){
		do{
			
			if(actual->dato.id == nodoBuscado){
				cout <<"Usuario con el ID [" << nodoBuscado << "] Encontrado"<<endl;
				
				if(actual==prim){
					prim = prim->sig;
					ulti->sig = prim;
                    delete actual;
				}else if(actual==ulti){
					anterior->sig = prim;
					ulti = anterior;
                    delete actual;
				}else{
					anterior->sig = actual->sig;
                    delete actual;
				}
				
				cout << "Usuario Eliminado";
				encontrado = true;
			}
			anterior = actual;
			actual = actual->sig;
		}while(actual!=prim && encontrado != true);
		if(!encontrado){
			cout << "Usuario NO Encontrado";
		}
	}else{
		cout << "La lista de clientes esta vacia";
	}
}



int main(){

    int opcion = 0;

    do
    {
        
		cout << "\n| 1. Agregar       |";
		cout << "\n| 2. Buscar por ID |";
		cout << "\n| 3. Borrar        |";
        cout << "\n| 4. Salir         |";
		cout << "\nEscoja una Opcion: ";
        cin>> opcion; cin.ignore();

        switch (opcion)
        {
        case 1:
            cout <<"Registrar usuario"<<endl;
            agregarnodo();
            break;
        case 2:
            cout <<"Usuarios registrados"<<endl;
            mostrar();
            break;
        case 3:
            cout <<"Borrar"<<endl;
            eliminarPersona();
            break;
        case 4:
            opcion = 4;
            cout <<"\n\nVuelva pronto pet!!" <<endl;
            break;
        default:
            cout <<"\n\nOpcion no valida, intente de nuevo"<<endl;
            break;
        }
    } while (opcion !=4);
    









    return 0;
}