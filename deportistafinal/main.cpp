/*
Equipo 1

Andres Hernandez Abel
Espinoza Serrano Paola Guadalupe
Ivan Garcia Nuño
Seccion D19
Calendario 2024 A
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "Deportista.h"
#include "funcionesmain.h"

using namespace std;

int main() {
    int opc = 0;

    fstream archivoDeportistasComb;
    archivoDeportistasComb.open("deportistas.dat", ios::out | ios::in | ios::binary);

    if (!archivoDeportistasComb) {
        cerr << "No se pudo abrir el archivo.";
        exit(1);
    }

    cout << "MENU - ASOCIACION DE DEPORTISTAS TAPATIOS \n";
    do {
        cout << "1. Altas \n";
        cout << "2. Bajas \n";
        cout << "3. Cambios \n";
        cout << "4. Consulta individual (numero de socio) \n";
        cout << "5. Consultas generales (formato de tabla) \n";
        cout << "6. Salir \n";
        cout << "Elige tu opcion: \n";
        cin >> opc;

        switch (opc) {
        case 1: {
            altas(archivoDeportistasComb);
            break;
        }

        case 3: {
            cambios(archivoDeportistasComb);
            break;
        }

        case 4: {
            consulta_individual(archivoDeportistasComb);
            break;
        }

        case 5: {
            consultas_generales(archivoDeportistasComb);
            break;
        }

        case 6: {
            cout << "Gracias por usar nuestro menu";
            exit(EXIT_SUCCESS);
        }

        default:
            cout << "\nLa opcion elegida no es valida, intente de nuevo\n\n" << endl;
        }
    } while (opc != 6);

    archivoDeportistasComb.close();
    return 0;
}


