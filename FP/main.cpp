
//Inicio

#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<direct.h>

using namespace std;

//Inicio de clases



class hotel
{

int habitacion_no;
char nombre[30];
char direccion[50];
char telefono[10];

public:

void main_menu();		//muestra el menu principal
void reservacion();			//reserva una habitacion
void registro_cliente(); 		//muestra el registro del cliente
void habitaciones();			//muestra las habitaciones
void edit_cliente();			//editar el hitsorial de un cliente
int estado(int);			//verificar estado de las habitaciones
void modificar(int);		//modifica el registro
void del_registro(int);		//elimina el registro
void factura(int);                 //factura de un registro
     };
    //fin de las clases



//Muestra el menu principal



void hotel::main_menu()
{

int opcion;
while(opcion!=5)
{

  system("cls");
cout<<"\n\t\t\t\t*************************";
cout<<"\n\t\t\t\t Hotel AnBy ";
cout<<"\n\t\t\t\t      * MENU PRINCIPAL *";
cout<<"\n\t\t\t\t*************************";
cout<<"\n\n\n\t\t\t1.Reservar una habitacion";
cout<<"\n\t\t\t2.Historial del cliente";
cout<<"\n\t\t\t3.Habitaciones";
cout<<"\n\t\t\t4.Editar un registro";
cout<<"\n\t\t\t5.Salir";
cout<<"\n\n\t\t\tElija una opcion: ";
cin>>opcion;

switch(opcion)
{

case 1:	reservacion();
break;

case 2: registro_cliente();
break;

case 3: habitaciones();
break;

case 4:	edit_cliente();
break;

case 5: break;

default:
{

cout<<"\n\n\t\t\tOpcion invalida";
cout<<"\n\t\t\tPulse una tecla para continuar";
getch();

}

}

}

}


//fin de la funcion de menu


//funcion para una reservacion


void hotel::reservacion()
{

  system("cls");
int r,flag;
ofstream fout("Record.dat",ios::app);

cout<<"\n Ingrese los datos del cliente ";
cout<<"\n ----------------------";
cout<<"\n\n Numero de Habitacion: ";
cout<<"\n Total de habitaciones - 40";
cout<<"\n Sencillas 1 - 15........75.00";
cout<<"\n Dobles 16 - 30.........125.00";
cout<<"\n Triples 31 - 40........175.00";
cout <<"\n Elija el numero de habitacion que desea:- "<<endl;
cin>>r;

flag=estado(r);

if(flag)
cout<<"\n Lo sentimos, esa habitacion noesta disponible";

else
{

habitacion_no=r;
cout<<" Nombre: ";
cin>>nombre;
cout<<" Direccion de correo electronico: ";
cin>>direccion;
cout<<" Numero de telefono: ";
cin>>telefono;

fout.write((char*)this,sizeof(hotel));
cout<<"\n Ha selceccionado una habitacion";

}

cout<<"\n Pulse una tecla para continuar!";

getch();
fout.close();

}


//termina la funcion de reserva


//funcion para mostrar el registro del cliente





void hotel::registro_cliente()
{

  system("cls");

ifstream fin("Record.dat",ios::in);
int r,flag;

cout<<"\n Ingrese el numero de habitacion del cliente :- "<<endl;
cin>>r;

while(!fin.eof())
{

fin.read((char*)this,sizeof(hotel));
if(habitacion_no==r)
{

  system("cls");
cout<<"\n Datos del cliente";
cout<<"\n ----------------";
cout<<"\n\n Numero de habitacion: "<<habitacion_no;
cout<<"\n Nombre: "<<nombre;
cout<<"\n Direccion de correo electronico: "<<direccion;
cout<<"\n Numero de telefono: "<<telefono;
flag=1;
break;

}

}

if(flag==0)
cout<<"\n Lo sentimos, esta habitacion no esxiste o no esta disponible!";
cout<<"\n\n Pulse una tecla para continuar";

getch();
fin.close();
}


//fin de la funcion del registro del cliente

//funcion para mostrar las habitaciones ocupadas

void hotel::habitaciones()
{

  system("cls");

ifstream fin("Record.dat",ios::in);
cout<<"\n\t\t\t    Habitaciones asignadas";
cout<<"\n\t\t\t    ----------------------";
cout<<"\n\n Numero de Habitacion.\tNombre\t\tDireccion de correo electronico\t\t\t\tNumero de telefono\n";

while(!fin.eof())
{

fin.read((char*)this,sizeof(hotel));
cout<<"\n\n "<<habitacion_no<<"\t\t"<<nombre;
cout<<"\t\t"<<direccion<<"\t\t"<<telefono;

}

cout<<"\n\n\n\t\t\tPulse una tecla para continuar";
getch();
fin.close();

}


//Funcion para editar registro y facturar


void hotel::edit_cliente()
{

  system("cls");

int opcion,r;
cout<<"\n Menu para editar";
cout<<"\n ---------";
cout<<"\n\n 1.Modificar el registro de un cliente";
cout<<"\n 2.Eliminar el registro de un cliente";
cout<<"\n 3. Factura de un cliente";
cout<<"\n Elija una opcion: ";

cin>>opcion;
  system("cls");

cout<<"\n Ingrese el numero de habitacion: " ;
cin>>r;

switch(opcion)
{

case 1:	modificar(r);
break;

case 2:	del_registro(r);
break;

case 3: factura(r);
break;

default: cout<<"\n Opcion invalida";

}
cout<<"\n Pulse una tecla para continuar";

getch();
}


int hotel::estado(int r)
{

int flag=0;

ifstream fin("Record.dat",ios::in);

while(!fin.eof())
{

fin.read((char*)this,sizeof(hotel));
if(habitacion_no==r)
{

flag=1;
break;

}

}

fin.close();
return(flag);

}


//Funcion para modificar el registro de un cliente


void hotel::modificar(int r)
{

long pos,flag=0;

fstream file("Record.dat",ios::in|ios::out|ios::binary);

while(!file.eof())
{

pos=file.tellg();
file.read((char*)this,sizeof(hotel));

if(habitacion_no==r)
{

cout<<"\n Ingrese nuevos datos";
cout<<"\n -----------------";
cout<<"\n Nombre: ";
cin>>nombre;
cout<<" Direccion de correo electronico: ";
cin>>direccion;
cout<<" Numero de telefono: ";
cin>>telefono;
file.seekg(pos);
file.write((char*)this,sizeof(hotel));
cout<<"\n El registro ha sido modificado";
flag=1;
break;

}

}

if(flag==0)
cout<<"\n Lo sentimos, esta habitacion no existe o ya esta ocupada!";
file.close();

}


//fin de la funcion para modificar


//Funcion para eliminar un registro


void hotel::del_registro(int r)
{

int flag=0;
char ch;
ifstream fin("Record.dat",ios::in);
ofstream fout("temp.dat",ios::out);

while(!fin.eof())
{

fin.read((char*)this,sizeof(hotel));
if(habitacion_no==r)

{

cout<<"\n Nombre: "<<nombre;
cout<<"\n Direccion de correo electronico: "<<direccion;
cout<<"\n Numero de telefono: "<<telefono;
cout<<"\n\n Desea eliminar este registro (s/n): ";
cin>>ch;

if(ch=='n')
fout.write((char*)this,sizeof(hotel));
flag=1;

}

else
fout.write((char*)this,sizeof(hotel));

}

fin.close();
fout.close();

if(flag==0)
cout<<"\n Lo sentimos, esta habitacion no esta disponible o no se encuentra!";

else
{

remove("Record.dat");
rename("temp.dat","Record.dat");

}

}


//fin de la funcion para eliminar el registro


//funcion para facturar

void hotel::factura(int r)
{

hotel h1;
ifstream f1;
 f1.open("record.dat",ios::in|ios::binary);

if(!f1)
 cout<<"No se puede abrir";

 else
 {

  f1.read((char*)&h1,sizeof (hotel));
  while(f1)

  {

  f1.read((char*)&h1,sizeof(hotel));

  }

  if (h1.habitacion_no == r)
  {

  if(h1.habitacion_no>=1&&h1.habitacion_no<=30)
  cout<<"Su total es de 75.00";

  else if (h1.habitacion_no>=35&&h1.habitacion_no<=45)
  cout<<"Su total es de 125.00" ;

  else
  cout<<"Su total es de 175.00";

  }

  else
  { cout<<"El numero de habitacion no ha sido encontrado";}

  }

  f1.close();
  getch();

}

//fin de la funcion para facturar

//inicio del programa


int main()
{

hotel h;

  system("cls");

cout<<"\n\t\t\t****************************";
cout<<"\n\t\t\t******** Hotel AnBy ********";
cout<<"\n\t\t\t****************************";
cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPulse una tecla para continuar";

getch();

h.main_menu();
return 0;
}

//fin del programa
