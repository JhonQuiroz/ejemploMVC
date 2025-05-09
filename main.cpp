#include <iostream>
#include <vector>
#include "headers/Automovil.h"
#include "headers/Moto.h"
#include "headers/Bicicleta.h"
#include "headers/VehiculoElectrico.h"

int main() {
    std::vector<VehiculoElectrico*> vehiculos;
    int opcion;

    do {
        std::cout << "\n=== Gestion de Vehiculos Electricos ===\n";
        std::cout << "1. Registrar automovil\n2. Registrar moto electrica\n3. Registrar bicicleta electrica\n4. Mostrar todos los vehiculos\n5. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Entrada invalida. Intenta de nuevo.\n";
            continue;
        }

        std::string marca, modelo, traccion, freno, tipoBateria;
        int autonomia, bateria, puertas, cilindrada;
        bool asistencia;

        switch (opcion) {
        case 1:
            std::cout << "Marca: "; std::cin >> marca;
            std::cout << "Modelo: "; std::cin >> modelo;

            std::cout << "Autonomia: "; std::cin >> autonomia;
            if(std::cin.fail()) { std::cin.clear(); std::cin.ignore(1000, '\n'); std::cout << "Autonomía inválida.\n"; break; }

            std::cout << "Nivel de bateria: "; std::cin >> bateria;
            if(std::cin.fail()) { std::cin.clear(); std::cin.ignore(1000, '\n'); std::cout << "Batería inválida.\n"; break; }

            std::cout << "Numero de puertas: "; std::cin >> puertas;
            if(std::cin.fail()) { std::cin.clear(); std::cin.ignore(1000, '\n'); std::cout << "Número de puertas inválido.\n"; break; }

            std::cout << "Tipo de traccion: "; std::cin >> traccion;

            vehiculos.push_back(new Automovil(marca, modelo, autonomia, bateria, puertas, traccion));
            break;

        case 2:
            std::cout << "Marca: "; std::cin >> marca;
            std::cout << "Modelo: "; std::cin >> modelo;

            std::cout << "Autonomia: "; std::cin >> autonomia;
            if(std::cin.fail()) { std::cin.clear(); std::cin.ignore(1000, '\n'); std::cout << "Autonomía inválida.\n"; break; }

            std::cout << "Nivel de bateria: "; std::cin >> bateria;
            if(std::cin.fail()) { std::cin.clear(); std::cin.ignore(1000, '\n'); std::cout << "Batería inválida.\n"; break; }

            std::cout << "Cilindrada electrica: "; std::cin >> cilindrada;
            if(std::cin.fail()) { std::cin.clear(); std::cin.ignore(1000, '\n'); std::cout << "Cilindrada inválida.\n"; break; }

            std::cout << "Tipo de freno: "; std::cin >> freno;

            vehiculos.push_back(new Moto(marca, modelo, autonomia, bateria, cilindrada, freno));
            break;

        case 3:
            std::cout << "Marca: "; std::cin >> marca;
            std::cout << "Modelo: "; std::cin >> modelo;

            std::cout << "Autonomia: "; std::cin >> autonomia;
            if(std::cin.fail()) { std::cin.clear(); std::cin.ignore(1000, '\n'); std::cout << "Autonomía inválida.\n"; break; }

            std::cout << "Nivel de bateria: "; std::cin >> bateria;
            if(std::cin.fail()) { std::cin.clear(); std::cin.ignore(1000, '\n'); std::cout << "Batería inválida.\n"; break; }

            std::cout << "Tipo de bateria: "; std::cin >> tipoBateria;

            std::cout << "¿Asistencia al pedaleo (1: Sí, 0: No)?: "; std::cin >> asistencia;
            if(std::cin.fail()) { std::cin.clear(); std::cin.ignore(1000, '\n'); std::cout << "Opción inválida.\n"; break; }

            vehiculos.push_back(new Bicicleta(marca, modelo, autonomia, bateria, tipoBateria, asistencia));
            break;

        case 4:
            if (vehiculos.empty()) {
                std::cout << "No hay vehiculos registrados.\n";
            } else {
                for (VehiculoElectrico* v : vehiculos) {
                    v->mostrarInformacion();
                    v->mostrarTipoCarga();
                    std::cout << "--------------------------\n";
                }
            }
            break;

        case 5:
            std::cout << "Saliendo del sistema...\n";
            break;

        default:
            std::cout << "Opcion no valida.\n";
        }
    } while (opcion != 5);

    for (VehiculoElectrico* v : vehiculos)
        delete v;

    return 0;
}
