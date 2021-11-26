#include <iostream>
#include <string.h>
#include <iomanip>
#define maxchar 20
using namespace std;
    struct nodo
{
    char correo[maxchar];
     int edad;  
      char nombre[maxchar];
    char apellido[maxchar];
    int telefono;
    int carnet;
    
    struct nodo *sgte;

};

typedef struct nodo *PLista;

void menu(void);
void mostrar(PLista );
void registrar(PLista &);
void eliminar(PLista &);



int main(void)
{

    PLista lista = NULL;
    int opcion;

    do
    {
         menu();
        cin >> opcion;
        switch (opcion)
        {

        case 1:
            registrar(lista);
            break;

        case 2:
            if (lista == NULL)
            {

                cout << "disculpe no hay persona registrada\n";
            }
            else
            {

                mostrar(lista);
            }
            break;

        case 3:
            if (lista == NULL)
            {
                cout << "disculpe no hay persona registrada\n";
            }
            else
            {
                eliminar(lista);
            }
            break;

        case 4:
            return 0;
        default:
            cout << "INGRESE ALGO VALIDO \n";
            break;
        }

        system("pause");

        system("cls");

    } while (opcion != 6);
    system("pause");

    return 0;
}

void registrar(PLista &lista)
{
    PLista o, p = new (struct nodo);

    cout << "registro personal"<<endl;
    cin.ignore();

    cout << "su nombre:";
    cin.getline(p->nombre, maxchar);
    cin.ignore();


    cout << "su apellido:";
    cin.getline(p->apellido, maxchar);
    cin.ignore();
    cout << "suedad:";
    cin >> p->edad;
    cin.ignore();
    cout << "su carnet:";
    cin >> p->carnet;
    cin.ignore();
    cout << "su correo:";
    cin.getline(p->correo, maxchar);
    cin.ignore();
    cout << "su numero telefonico :";
    cin >> p->telefono;

    system("cls");
    p->sgte = NULL;

    if (lista == NULL)
    {

        lista = p;
    }
    else
    {
        o = lista;

    
        while (o->sgte != NULL)
        {

            o = o->sgte;
        }

        o->sgte = p;
    }
}

void menu(void)
{

    cout <<"1. ingrese los datos" << endl;
    cout <<"2. registro de personas" << endl;
    cout <<"3. eliminaar" << endl;
    cout <<"4. salir" << endl;

    cout << "seleccine una opcion: ";
}

void mostrar(PLista p)
{
    int i = 1;

    while (p != NULL)
    {
        cout << "registro [" << i << "] "<<endl;
        cout << "sus nombres: " << p->nombre << endl;
        cout << "sus apellidos: " << p->apellido << endl;

        cout << "su edad: " << p->edad << endl;
        cout << "se carne: "<< setfill('0')<<setw(8) << p->carnet << endl;
        cout << "su correo: " << p->correo << endl;

        cout << "sutelefono: "<< setfill('0')<<setw(8) << p->telefono << endl;

        p = p->sgte;

        i++;
    }
}



void eliminar(PLista &lista)
{
    string elimi;

    PLista p, o;

    p = lista;

    cout << "borrar"<<endl<<endl;
    cout << "a quien desea borrar?:";
    cin >> elimi;

    while (p != NULL)
    {

        if (p->nombre == elimi)
        {

            if (p == lista)
                lista = lista->sgte;

            else
                o->sgte = p->sgte;

            delete (p);
            cout << "borrado\n";

            return;
        }
        else
        {
            o = p;
            p = p->sgte;
        }
    }
    if (p == NULL)
        cout << "el nunca estuvo en la lista\n";
}