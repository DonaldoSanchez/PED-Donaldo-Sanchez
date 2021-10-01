/*Ingresar la cantidad de pupusas que los clientes desean,
 si quiere que sean de arroz o de maíz, si las quieren con Coca-Cola o no, 
 y de que ingredientes las quieren, que permita agregarlas a las lista y mostrar las ordenes. */
#include <iostream>
using namespace std ;

struct nodo
{
    int pupusa;
    string ingrediente, maizOarroz, bebida;
    nodo *sig;
};



class Cola{
    private: nodo *pCola;
           
    public:
        Cola();
        ~Cola();
        Cola(int,string, string, string);
        void insertar(int,string, string, string);
        void mostrarColaRec(void);
        void mostrarColaRecAux(nodo *);
        void mostrarColaRecAux2(nodo *);
    };

Cola::Cola(void)
{
    pCola = NULL;
}

Cola::~Cola()
{
    cout << "Destructor ejecutandose" << endl;
    nodo *p;
    while(pCola){
        //cout << "Estoy en la iteración para destruir" << endl;
        p = pCola;
        pCola = pCola->sig;
        delete p;
    }
}
Cola::Cola(int pupusa,string maizOarroz,string ingredientes, string bebida){
    pCola = NULL;
    insertar(pupusa, maizOarroz, ingredientes, bebida);

}
void Cola::insertar(int pupusa,string maizOarroz,string ingredientes, string bebida)
{
    nodo *nuevo;

    nuevo = new nodo;
    nuevo->pupusa = pupusa;
    nuevo->maizOarroz = maizOarroz;
    nuevo->ingrediente = ingredientes;
    nuevo->bebida = bebida;
    nuevo->sig = pCola;
    pCola = nuevo;
}


void Cola::mostrarColaRec(void)
{
    mostrarColaRecAux2(pCola);
}



void Cola::mostrarColaRecAux2(nodo *saltarin)
{
    if(saltarin){
        mostrarColaRecAux2(saltarin->sig);
        cout << "Total de pupusas pedidas: " << saltarin->pupusa<< endl;
        cout << "Especialidad de las pupusas: " << saltarin->maizOarroz<< endl;
        cout << "Ingredientes: " << saltarin->ingrediente<< endl;
        cout << "Bebida: " << saltarin->bebida<< endl;
   
    }
}



int menu(){
        int opcion = 0;
        cout << "LOS BOOMWALOS \n"<< endl;
        cout << "1) Ordenar mis pupusas" << endl;
        cout << "2) Mostrar mi orden" << endl;
        cout << "3) Salir" << endl;
        cin >> opcion;cin.ignore();
        return opcion;
}


int main (void){

    cout << endl;   
    Cola Ordenes;
    bool continuar = true;

    string maizOarroz= "", ingredientes= "", bebida = "";
    int pupusa = 0;
    cout << endl; 
   
do{
    switch (menu()){        
        case 1://Hacer mi orden de pupusas
             cout << "Cuantas pupusas desea ordenar: ";
             cin >> pupusa; cin.ignore();

             cout << "De que especialidad desea sus pupusas:(maiz o arroz) "; 
             getline(cin,maizOarroz);

             cout << "Que ingredientes desea para sus pupusas: "; 
             getline(cin,ingredientes);


             cout << "¿Desea agregar coca cola a su pedido ?: "; 
             getline(cin,bebida);

           
                Ordenes.insertar(pupusa, maizOarroz, ingredientes, bebida);
                break;

        case 2://Mostrar orden
                cout << "\tMI ORDEN" <<endl;
                Ordenes.mostrarColaRec();
            break;
        case 3://Salir
                continuar = false;

                cout << "Muchas gracias, vuelva pronto!!"<< endl;
            break;

        default: //Dato ingresado erroneo
        cout << "El dato que usted ingreso no es valido."<< endl ;
           break;
        }

    } while (continuar); 
    cout << endl;
    return 0;
}

  

