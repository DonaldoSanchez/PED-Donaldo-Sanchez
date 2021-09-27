/*Elabore una función que, dado un número entero que se obtiene desde teclado,realice un conteo como el siguiente: 
Suponiendo que el valor ingresado es 3:
                    1
                    2
                    3
                    1
                    2
*/

#include <iostream>

using namespace std;

int main (void)
{   
    int numero; // asignamos la variable para lista
    cout << "Este es un programa que realiza un conteo normal e inverso, centrado en un numero digitado desde teclado" << endl;
    cout << endl;
    cout << "Ingrese el numero al que quiere que se dirija el conteo" << endl;
    cin >> numero; // Digita el numero desde teclado 

    for(int i=1; i<=numero;i++) 
    cout << i << " "; // se realiza un incremento de la variable como limite del número digitado desde teclado

    for(int listaInversa = numero-1; 
    1 <= listaInversa;listaInversa--) cout << listaInversa << " "; // aqui es inverso del numero y el conteo regresa al inicio
    return 1; 
}