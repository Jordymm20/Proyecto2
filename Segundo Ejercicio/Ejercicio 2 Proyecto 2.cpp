#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include <stdlib.h>
using namespace std;

struct Vehiculo {
    string placa;
    string marca;
    string modelo;
    int tipoVehiculo;
	/*1= Sencillo 2= 4*4 3=Camion*/
    int tipoLavado;
	/*1=Lavado 2=Completo*/
    int precio;        
	/*Precio por el servicio*/
};

vector<Vehiculo> vehiculos;
int factura = 1; /*Número de factura*/

void ingresarDatos() {
    char continuar = 'S';
    while (continuar == 'S' || continuar == 's') {
        Vehiculo veh;
        cout << "Ingrese el numero de placa: ";
        cin >> veh.placa;
        cout << "Ingrese la marca: ";
        cin >> veh.marca;
        cout << "Ingrese el modelo: ";
        cin >> veh.modelo;

        do {
            cout << "Ingrese el tipo de vehiculo (1= Sencillo, 2= 4x4, 3= Camion): ";
            cin >> veh.tipoVehiculo;
        } while (veh.tipoVehiculo < 1 || veh.tipoVehiculo > 3);
        do {
            cout << "Ingrese el tipo de lavado (1= Solo Lavado, 2= Completo): ";
            cin >> veh.tipoLavado;
        } while (veh.tipoLavado < 1 || veh.tipoLavado > 2);

        if (veh.tipoVehiculo == 1) {
            if (veh.tipoLavado == 1)
                veh.precio = 3000;
            else
                veh.precio = 5000;
        } else if (veh.tipoVehiculo == 2) {
            if (veh.tipoLavado == 1)
                veh.precio = 5000;
            else
                veh.precio = 7000;
        } else if (veh.tipoVehiculo == 3) {
            if (veh.tipoLavado == 1)
                veh.precio = 7000;
            else
                veh.precio = 12000;
        }
        cout << "\nFactura: " << factura++ << endl;
        cout << "Placa: " << veh.placa << endl;
        cout << "Marca: " << veh.marca << endl;
        cout << "Modelo: " << veh.modelo << endl;
        cout << "Tipo de vehiculo: " << (veh.tipoVehiculo == 1 ? "Sencillo" : (veh.tipoVehiculo == 2 ? "4x4" : "Camion")) << endl;
        cout << "Tipo de lavado: " << (veh.tipoLavado == 1 ? "Solo Lavado" : "Completo") << endl;
        cout << "Precio a pagar: " << veh.precio << " colones" << endl;
        vehiculos.push_back(veh);
        cout << "\n¿Desea continuar? (S/N): ";
        cin >> continuar;
    }
}
void verEstadisticasTipoVehiculo() {
    int cantidadSencillo = 0, cantidad4x4 = 0, cantidadCamion = 0;
    int totalSencillo = 0, total4x4 = 0, totalCamion = 0;
    for (size_t i = 0; i < vehiculos.size(); i++) {
        Vehiculo& veh = vehiculos[i];
        if (veh.tipoVehiculo == 1) {
            cantidadSencillo++;
            totalSencillo += veh.precio;
        } else if (veh.tipoVehiculo == 2) {
            cantidad4x4++;
            total4x4 += veh.precio;
        } else if (veh.tipoVehiculo == 3) {
            cantidadCamion++;
            totalCamion += veh.precio;
        }
    }

    cout << "\nEstadisticas de vehiculos lavados segun tipo de vehiculo\n";
    cout << "Cantidad de vehiculos tipo sencillos: " << cantidadSencillo << endl;
    cout << "Dinero recaudado por vehiculos tipo sencillos: " << totalSencillo << " colones" << endl;
    cout << "Cantidad de vehiculos tipo 4x4: " << cantidad4x4 << endl;
    cout << "Dinero recaudado por vehiculos tipo 4x4: " << total4x4 << " colones" << endl;
    cout << "Cantidad de vehiculos tipo camion: " << cantidadCamion << endl;
    cout << "Dinero recaudado por vehiculos tipo vamion: " << totalCamion << " colones" << endl;
}
void verEstadisticasTipoLavado() {
    int cantidadSoloLavado = 0, cantidadCompleto = 0;
    int totalSoloLavado = 0, totalCompleto = 0;
    for (size_t i = 0; i < vehiculos.size(); i++) {
        Vehiculo& veh = vehiculos[i];
        if (veh.tipoLavado == 1) {
            cantidadSoloLavado++;
            totalSoloLavado += veh.precio;
        } else if (veh.tipoLavado == 2) {
            cantidadCompleto++;
            totalCompleto += veh.precio;
        }
    }
    cout << "\nEstadisticas de vehiculos lavados segun tipo de lavado\n";
    cout << "Cantidad de vehiculos con solo lavado: " << cantidadSoloLavado << endl;
    cout << "Dinero recaudado por vehiculos con solo lavado: " << totalSoloLavado << " colones" << endl;
    if (cantidadSoloLavado > 0)
        cout << "Promedio dinero recaudado por vehiculos con solo lavado: " << totalSoloLavado / cantidadSoloLavado << " colones" << endl;
    cout << "Cantidad de vehiculos con lavado, espirado y encerado: " << cantidadCompleto << endl;
    cout << "Dinero recaudado por vehiculos con lavado, aspirado y encerado: " << totalCompleto << " colones" << endl;
    if (cantidadCompleto > 0)
        cout << "Promedio dinero recaudado por vehiculos con lavado, aspirado y encerado: " << totalCompleto / cantidadCompleto << " colones" << endl;
}
void verGraficoTipoVehiculo() {
    int tipoSencillo = 0, tipo4x4 = 0, tipoPesado = 0;
    for (size_t i = 0; i < vehiculos.size(); i++) {
        Vehiculo& veh = vehiculos[i];
        if (veh.tipoVehiculo == 1) tipoSencillo++;
        if (veh.tipoVehiculo == 2) tipo4x4++;
        if (veh.tipoVehiculo == 3) tipoPesado++;
    }

    cout << "\nGrafico vehiculos lavados por tipo de vehiculo\n";
    cout << "Vehiculos Sencillos " << string(tipoSencillo,static_cast<char>(178)) << endl;
    cout << "Vehiculos 4x4 " << string(tipo4x4,static_cast<char>(178)) << endl;
    cout << "Vehiculos Pesados " << string(tipoPesado, '*') << endl;
    cout << "<Pulse tecla para Abandonar>\n";
    cin.get(); cin.get();
}
void verGraficoTipoLavado() {
    int soloLavado = 0, completo = 0;
    for (size_t i = 0; i < vehiculos.size(); i++) {
        Vehiculo& veh = vehiculos[i];
        if (veh.tipoLavado == 1) soloLavado++;
        if (veh.tipoLavado == 2) completo++;
    }

    cout << "\nGrafico vehiculos lavados por tipo de lavado\n";
    cout << "Sencillo " << string(soloLavado,static_cast<char>(178)) << endl;
    cout << "Completo " << string(completo,static_cast<char>(178)) << endl;
    cout << "<Pulse tecla para Abandonar>\n";
    cin.get(); cin.get();
}
void mostrarMenu() {
    int opcion;
    do {
        cout << "\nMenu Principal\n";
        cout << "1- Ingresar datos vehiculos\n";
        cout << "2- Ver Estadisticas vehiculos lavados segun tipo de vehiculo\n";
        cout << "3- Ver Estadisticas vehiculos lavados segun tipo de lavado\n";
        cout << "4- Ver grafico vehiculos Lavados por tipo de vehiculo\n";
        cout << "5- Ver grafico vehiculos Lavados por tipo de lavado\n";
        cout << "6- Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: ingresarDatos(); break;
            case 2: verEstadisticasTipoVehiculo(); break;
            case 3: verEstadisticasTipoLavado(); break;
            case 4: verGraficoTipoVehiculo(); break;
            case 5: verGraficoTipoLavado(); break;
            case 6: cout << "Saliendo\n"; break;
            default: cout << "Opcion invalida.\n"; break;
        }
    } while (opcion != 6);
}

int main() {
std::cout << "El carácter es: " << static_cast<char>(178) << std::endl;
system("cls");
    mostrarMenu();
    return 0;
}

