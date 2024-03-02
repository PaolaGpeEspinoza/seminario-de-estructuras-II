#include <iostream>
#include <iomanip>
#include <fstream>
#include "Deportista.h"

using namespace std;

void altas(fstream& archivoDeportistasComb) {
    int numeroDeSocio;
    char nombre[15];
    int edad;
    char deporte[15];
    string genero;
    Deportista d;
        cout << "Escriba el numero de socio (de 1 a 100, 0 para terminar la entrada)\n?";
            cin >> numeroDeSocio;
            d.establecerNumeroDeSocio(numeroDeSocio);

            while (d.obtenerNumeroDeSocio() >= 1 && d.obtenerNumeroDeSocio() <= 100) {
                cout << "Teclea nombre, edad, deporte y genero (Masculino o Femenino)\n?";
                cin >> setw(15) >> nombre;
                cin >> edad;
                cin >> setw(15) >> deporte;
                cin >> genero;
                d.establecerNombre(nombre);
                d.establecerEdad(edad);
                d.establecerDeporte(deporte);
                d.establecerGenero(genero);

                archivoDeportistasComb.seekp((d.obtenerNumeroDeSocio() - 1) * sizeof(Deportista));
                archivoDeportistasComb.write(reinterpret_cast<const char*>(&d), sizeof(Deportista));

                cout << "Escriba el numero de socio (de 1 a 100, 0 para terminar la entrada)\n?";
                cin >> numeroDeSocio;
                d.establecerNumeroDeSocio(numeroDeSocio);
            }
}

void consulta_individual(fstream& archivoDeportistasComb) {
    int numeroDeSocio;
    Deportista d;
    cout << "Escriba el numero de socio (de 1 a 100)\n";
            cin >> numeroDeSocio;
            d.establecerNumeroDeSocio(numeroDeSocio);

            archivoDeportistasComb.clear();
            archivoDeportistasComb.seekg((d.obtenerNumeroDeSocio() - 1) * sizeof(Deportista));
            archivoDeportistasComb.read(reinterpret_cast<char*>(&d), sizeof(Deportista));

            if (numeroDeSocio != d.obtenerNumeroDeSocio()) {
                cerr << "No se encuentra socio asociado al numero dado.";
            }

            cout << "Datos de Deportista \n";
            cout << "Numero de Socio: ";
            cout << d.obtenerNumeroDeSocio() << "\n";
            cout << "Nombre: ";
            cout << d.obtenerNombre() << "\n";
            cout << "Edad: ";
            cout << d.obtenerEdad() << "\n";
            cout << "Deporte: ";
            cout << d.obtenerDeporte() << "\n";
            cout << "Genero: ";
            cout << d.obtenerGenero() << "\n";
            archivoDeportistasComb.clear();
}

void consultas_generales(fstream& archivoDeportistasComb) {
    int numeroDeSocio;
    char nombre[15];
    int edad;
    char deporte[15];
    string genero;
    Deportista d;
    cout << left << setw(17) << "Numero De Socio" << setw(17) << "Nombre" << setw(17) << "Edad"<<setw(17) << "Deporte" <<"Genero"<< endl;

            int totalRegistros = 0;
            int totalHombres = 0;
            int totalMujeres = 0;

            archivoDeportistasComb.clear();
            archivoDeportistasComb.seekg(0, ios::beg);

            while (archivoDeportistasComb.read(reinterpret_cast<char*>(&d), sizeof(Deportista))) {
                if (d.obtenerNumeroDeSocio() != 0) {
                    cout << left << setw(17) << d.obtenerNumeroDeSocio() << setw(17) << d.obtenerNombre() << setw(17) << d.obtenerEdad() << setw(17)<< d.obtenerDeporte() << d.obtenerGenero()<<endl;
                    totalRegistros++;

                    // Obtener el genero
                    string genero = d.obtenerGenero();
                    if (genero == "Masculino") {
                        totalHombres++;
                    } else if (genero == "Femenino") {
                        totalMujeres++;
                    }
                }
            }

            cout << "Total de registros: " << totalRegistros << endl;
            cout << "Total de hombres: " << totalHombres << endl;
            cout << "Total de mujeres: " << totalMujeres << endl;
            archivoDeportistasComb.clear();
}

void cambios(fstream& archivoDeportistasComb) {
    int numeroDeSocio;
    Deportista d;

    cout << "Escriba el numero de socio que desea modificar (de 1 a 100)\n";
    cin >> numeroDeSocio;
    d.establecerNumeroDeSocio(numeroDeSocio);

    archivoDeportistasComb.clear();
    archivoDeportistasComb.seekg((d.obtenerNumeroDeSocio() - 1) * sizeof(Deportista));
    archivoDeportistasComb.read(reinterpret_cast<char*>(&d), sizeof(Deportista));

    if (numeroDeSocio != d.obtenerNumeroDeSocio()) {
        cerr << "No se encuentra socio asociado al numero dado.";
        return;
    }

    cout << "Datos actuales del Deportista \n";
    cout << "Numero de Socio: " << d.obtenerNumeroDeSocio() << "\n";
    cout << "Nombre: " << d.obtenerNombre() << "\n";
    cout << "Edad: " << d.obtenerEdad() << "\n";
    cout << "Deporte: " << d.obtenerDeporte() << "\n";
    cout << "Genero: " << d.obtenerGenero() << "\n";

    char nuevoNombre[15];
    int nuevaEdad;
    char nuevoDeporte[15];
    string nuevoGenero;

    cout << "Ingrese los nuevos datos del deportista:\n";
    cout << "Nombre: ";
    cin >> setw(15) >> nuevoNombre;
    cout << "Edad: ";
    cin >> nuevaEdad;
    cout << "Deporte: ";
    cin >> setw(15) >> nuevoDeporte;
    cout << "Genero (Masculino o Femenino): ";
    cin >> nuevoGenero;

    d.establecerNombre(nuevoNombre);
    d.establecerEdad(nuevaEdad);
    d.establecerDeporte(nuevoDeporte);
    d.establecerGenero(nuevoGenero);

    archivoDeportistasComb.seekp((numeroDeSocio - 1) * sizeof(Deportista));
    archivoDeportistasComb.write(reinterpret_cast<const char*>(&d), sizeof(Deportista));

    cout << "Deportista modificado exitosamente.\n";
    archivoDeportistasComb.clear();
}
