/* Dado un Numero mayor y menor, obtenga el MCD por el método de Euclides. */
#include <iostream>
using namespace std;


int mcd(int NumMen, int NumMay ){ //Definicion de variables

    if( NumMay == 0){ //creamos la condicion para formar nuestro maximo comundivisor
        return NumMen;
    } return mcd(NumMay, NumMen%NumMay); // Minimo comun divisor
}


int main(){ 
    cout << endl;

    int NumMay, NumMen; //definimos las mismas, asi como estan en el if

    cout << "Este es un programa para calcular el Maximo comun divisor por el algoritmo de EUCLIDES"<< endl;

    cout<< "Introduce el  numero menor: " << endl;
    cin >> NumMen; //introducimos el primer numero a evaluar(menor)
   
    cout<< "Introduce el numero mayor: " << endl; 
    cin >> NumMay; //introducimos el segundo numero a evaluar(mayor)

    cout <<"El MAXIMO COMUN DIVISOR DE: " << NumMen <<" y "<< NumMay << " es: " << mcd(NumMay, NumMen); //Aqui imprimimos el MCD

    cout << endl;

    return 0;

 

