#include"tarea4LABPED.hpp" 


int menu(){

    int opcion = 0;
    cout << endl;
    cout << "DATOS DE USUARIO"<< endl;
    cout <<" 1) Ingresar datos" <<endl;
    cout <<" 2) Ingresar datos al final" <<endl;
    cout <<" 3) Mostrar datos"<<endl;
    cout <<" 5) Mostrar datos al reves " <<endl;
    cout <<" 4) Salir" << endl;

    cin >> opcion; cin.ignore();

    return opcion;
}


int main (void){
  

    ListaDoble datos;

    bool continuar = true;
    administrar p;
    do{
        switch (menu()){
            case 1://Ingresar datos
                    p = solicitarDatos();
                    datos.InsInicio(p);
                    break;
            case 2: // ingresar datos al final
                    p = solicitarDatos();
                    datos.InsFinal(p);
                    break;
            case 3: //imprimir de inicio a final
                    datos.mostrarLista();
                    break;
            case 4: //imprimir de final a inicio
                    datos.mostrarListaReversa();
                    break;

            case 5: 
                   continuar = false;
                   cout <<"Vuelva pronto!!"<<endl;
                   break;
        default:
            cout <<"Ingrese una opcion valida por favor!!" << endl;
            break;
        }
    } while (continuar);
    
    return 0;

}