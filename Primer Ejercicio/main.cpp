#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

int n=0;
int nacimiento,edad,calificacion[3];
float materias[4],prom_califica[3];                                                      //= {"Matematica", "Español", "Ciencias", "Estudios Sociales"}; 
void ingrear(){
float admision=0,total_materias=0,prom_colegio=0,por_crit_colegio=0,por_exam_admision=0,prom_admision=0;
char cedulas[n][50],nombres[n][100];
char cedula[50],nombre[100];
bool resul=0;
    do{
	resul=false;
	memcpy(nombres[n],nombre, strlen(nombre)+1);	
    memcpy(cedulas[n],cedula, strlen(cedula)+1);
	n++;	
    cout<<"Digite el numero de identificacion del estudiante: ";
	cin >> cedula;
    for(int i=0; i<n; i++){
		if(strcmp(cedulas[i],cedula)==0){
		resul=true;	
	    system("cls");		
	    cout<<"Usted ya digito este numero de cedula digite otro\n";
	    system("pause");
		} else {
		}
    }
    }while(resul==1);	
	cout<<"\nDigite el nombre del estudiante: ";
    cin>>nombre;
	cout<<"\nDigite su nacimiento: ";
	cin>>nacimiento;
	for(int i=0; i<4; i++){
		if(i<=1){
		printf("\nDigite el promedio final de %s: ", (i==0 ? "Matematicas" : "Español"));
		cin>>materias[i];
		total_materias=total_materias+materias[i];
	    }
	    if(i>1){
	    printf("\nDigite el promedio final de %s: ", (i== 2 ? "Ciencias" : "Estudios Sociales"));
		cin>>materias[i];
		total_materias=total_materias+materias[i];	
	    }
   }
	cout<<"\nDigite su nota de admision realizado en la Universidad UTC: ";
	cin>>admision;
	system("cls");
	
	edad=2024-nacimiento;
	prom_colegio=total_materias/4;
	por_crit_colegio=prom_colegio*0.40;
	por_exam_admision=admision*0.60;
	prom_admision=por_crit_colegio+por_exam_admision;
	
	if(prom_admision>=85){
		calificacion[0]++;
    }else if((prom_admision>=75)&&(prom_admision<85)){
    	calificacion[1]++;
    }else if(prom_admision<75){
    	calificacion[2]++;
    }
	cout<<"\nCedula del estudiante: "<<cedula<<endl;
	cout<<"\nNombre del estudiante: "<<nombre<<endl;
	cout<<"\nNacimiento del estudiante: "<<nacimiento<<endl;
	cout<<"\nEdad del estudiante: "<<edad<<endl;
    for(int i=0; i<4; i++){
		if(i<=1){
		printf("\nLas calificaciones de %s son: %.2f ",(i== 0 ? "Matematicas" : "Espanol"),materias[i]);
	    }
	    if(i>1){
	    printf("\nLas calificaciones de %s son: %.2f ",(i== 2 ? "Ciencias" : "Estudios Sociales"),materias[i]);
	    }
   }
   
	cout<<"\nEl promedio del colegio es: "<<prom_colegio<<endl;
	cout<<"\nEl porcentaje de criterio colegio es: "<<por_crit_colegio<<endl;
    cout<<"\nEl porcentaje de examen de admision es: "<<por_exam_admision<<endl;
	cout<<"\nEl promedio de admision es: "<<prom_admision<<endl;
	
	if(prom_admision>=85){
		cout<<"\nLa calificacion es de: Admitido\n";
    }else if((prom_admision>=75)&&(prom_admision<85)){
    	cout<<"\nLa calificacion es de: En espera\n";
    }else if(prom_admision<75){
    	cout<<"\nLa calificacion es de: No admitido\n";
    }
    for(int i=0;i<3;i++){
	prom_califica[i]=calificacion[i]/n;
    }
	system("pause");
	system("cls");
}
void estadisticas(){
	
     for(int i=0; i<3; i++){
		if(i<=1){
		printf("\nLa cantidad de estudiantes %s es de: %i ",(i== 0 ? "Admitidos" : "En espera"),calificacion[i]);
		printf("\nEl promedio de estudiantes %s es de: %.2f \n",(i== 0 ? "Admitidos" : "En espera"),prom_califica[i]);
		cout<<"-------------------------------------------";
	    }
	    if(i>1){
	    printf("\nLa cantidad de estudiantes No admitidos es de: %i \n",calificacion[i]);
		printf("El promedio de estudiantes no admitidos es de: %.2f \n",prom_califica[i]);
		cout<<"---------------------------------------------\n";
	    }
     }
      system("pause");
	  system("cls");
}
void grafico(){
int cont=0;	
	for(int i=0;i<3;i++){
		if(i<=1){
		printf("\n%s ",(i== 0 ? "Admitidos" : "En espera"));
	    }
	    if(i>1){
	    printf("\nNo admitidos ");
	    }
	    cont=0;
		for(int j=0;j<=n;j++){
			if(cont<calificacion[i]){
				printf("%c",static_cast<char>(178));
			}else{
			}
		cont++;	
		}
			
	}
	cout<<"\n";
	system("pause");
	system("cls");
}
void salir(){
	cout<<"El programa a finalizado";
	exit(3);
}
void menu(){
  char seguir = 's';
  int opcion;
   do {
   	cout << "1- Ingresar Datos  \n";
   	cout << "2- Estadisticas  \n";
   	cout << "3- Grafico   \n";
   	cout << "4- salir                  \n";
   	cout << "Digite una opcion...    : \n" ;
   	cin >> opcion;
   	system("cls");
   
   	switch (opcion)
   	{
   		case 1: ingrear(); break;
   		case 2: estadisticas(); break;
   	    case 3: grafico(); break;
   	    case 4: salir();break;
   	    default : break;
   	}

   }while ((seguir=='s') || (seguir=='S'));
	
}
int main() {
std::cout << "El carácter es: " << static_cast<char>(178) << std::endl;
system("cls");
	
	menu();
	
	return 3;
}
