#include <iostream>
#include <string.h>
#include <cmath>
#include <iomanip>
#include <ctime>
using namespace std;

double agregar(){
    string cancel,pago,numtarjeta;
    float total, cama;
    int op;
    cout<<"Desea una cama extra? (1 si o 2 No) (Se cobra un cargo extra de 50.00 por noche) "<<endl;
    cin>>op;
    if(op == 1){
        total+=50.00;
    }
    if(op == 2){
        return 0;
    }
    cout<<"Desea una factura de cancelacion? (Si o No)"<<endl;
    cin>>cancel;
    if(cancel == "Si"){
        total+=75.00;
    }
    else{
        return 0;
    }

    cout<<endl;
    cout<<"Ingrese su forma de pago (Visa o MasterCard)"<<endl;
    cin>>pago;
    if(pago == "Visa"){
        cout<<"Ingrese su numero de tarjeta: "<<endl;
        cin>>numtarjeta;
    }
    if(pago == "MasterCard"){
        cout<<"Ingrese su numero de tarjeta: "<<endl;
        cin>>numtarjeta;
    }
    cama = cama * 50.00;
    total = total + cama;
    cout<<total<<endl;

}

void pago(double sum,double extraf,string nombre,string numero,string direccion,int habitacion,int personas,int day1,int month1,int year1,int day2,int month2,int year2,int dias){
double tax = 0;
double total = 0;
tax = (sum+extraf)*0.1;
string tipo_habitacion;
if(habitacion == 1){
    tipo_habitacion = "Sencilla";
}
if(habitacion == 2){
    tipo_habitacion = "Doble";
}
if(habitacion == 3){
    tipo_habitacion = "Triple";
}
}


double fecha (int day1, int month1, int year, int day2, int month2, int year4){
int i;
 month1-=1;
 month2-=1;
  struct std::tm a = {0,0,0,day1,month1,year}; /* June 24, 2004 */
    struct std::tm b = {0,0,0,day2,month2,year4}; /* July 5, 2004 */
    std::time_t x = std::mktime(&a);
    std::time_t y = std::mktime(&b);
    if ( x != (std::time_t)(-1) && y != (std::time_t)(-1) )
    {
        double difference = std::difftime(y, x) / (60 * 60 * 24);
        std::cout << std::ctime(&x);
        std::cout << std::ctime(&y);
        std::cout << "difference = " << difference << " days" << std::endl;
    time_t days = difference;
    return days;
}
}
int main(){
    string nombre;
    string direccion;
    string numero;
    string extra;
    int habitacion;
    int personas;
    int day1,month1,year1;
    int day2,month2,year2;
    int dias;
    int i,year,year4;

    start:

    cout<<"-----Bienvenido al Hotel AnBy-----"<<endl;
    cout<<endl;

    cout<<"Ingrese su fecha de llegada: "<<endl;
    cin>>day1>>month1>>year1;
    year = year1 - 1900;
    system("cls");

    cout<<day1<<"/"<<month1<<"/"<<year1<<endl;
    cout<<"Ingrese su nombre completo: "<<endl;
    cin>>nombre;
    cout<<"Ingrese su direccion de correo electronico: "<<endl;
    cin>>direccion;
    cout<<"Ingrese su nunero telefonico: "<<endl;
    cin>>numero;

    cout<<"Para cuantas personas sera la reservacion? (Solo admitimos cuatro personas por habitacion)"<<endl;
    p1:
    cin>>personas;
    if(personas >=4){
        goto p1;
    }
    cout<<"Ingrese el tipo de habitacion de que le gustaria: "<<endl;
    p2:
    cout<<"Tipo de habitaciones y precios"<<endl;
    cout<<"1. Sencilla ----------- $75.00"<<endl;
    cout<<"2. Doble -------------- $125.00"<<endl;
    cout<<"3. Triple ------------- $175.00"<<endl;
    cout<<endl;
    cout<<"Elija una habitacion: "<<endl;
    cin>>habitacion;

    cout<<"Ingrese su fecha de salida: "<<endl;
    cin>>day2>>month2>>year2;
    cout<<day2<<"/"<<month2<<"/"<<year2<<endl;
    year4=year2 - 1900;
    dias = fecha(day1,month1, year, day2,month2, year4);
    system("cls");

    double sum = 0;
    double extraf = 0;

    if(personas<=2&&personas>0){
        if(habitacion == 1){
            sum+=75.00;
            for(i=2; i<=dias; i++){
                sum+=30.00;
            }
        }
        if(habitacion == 2){
            sum+=125.00;
            for(i=2; i<=dias; i++){
                sum+=40.00;
            }
        }
        if(habitacion == 3){
            sum+=175.00;
            for(i=2; i<=dias; i++){
                sum+=50.00;
            }
        }
    }
    else if(personas <= 4 && personas > 2){
        if(habitacion == 1){
            sum+=100.00;
            for(i=2; i<= dias; i++){
                sum+=50.00;
            }
        }
        if(habitacion == 2){
            sum+=175.00;
            for(i=2; i<= dias; i++){
                sum+=55.00;
            }
        }
        if(habitacion == 3){
            sum+=200.00;
            for(i=2; i<= dias; i++){
                sum+=60.00;
            }
        }

    }

    cout<<sum<<endl;
    pago(sum, extraf, nombre, numero, direccion, habitacion, personas, day1, month1, year1, day2, month2, year2, dias);
    double total = agregar();
    string decision;

    cout<<"Desea reservar otra habitacion? (Si o No)"<<endl;
    cin>>decision;
    if(decision == "Si"){
        goto p2;
    }
    return 0;
}
