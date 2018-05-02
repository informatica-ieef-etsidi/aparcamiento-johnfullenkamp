#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define NPLAZAS 2
struct plaza {
	
	int estado; //0 - libre 1:ocupado
	char tipo;	//m-moto c-coche
	char matricula[8]; //formato nnnnlll
	int tiempoingreso;
	int tiemposalida;
	int bandera;

};

main() {
	struct plaza aparcamientos[NPLAZAS];	
	char repetir='S';
	char matriculaaux[8];
	time_t tiempoahora,tiempodespues;
	char opcion;
	int i=0,j,k,n;
	int bandera1;
	int orden=1;
	int aparcamientolleno=0;
	int longmatricula;
	
		
	for(i=0;i<NPLAZAS;i++)
	{
		aparcamientos[i].estado=0;
		aparcamientos[i].tiempoingreso=0;
		aparcamientos[i].tiemposalida=0;
		aparcamientos[i].bandera=0;
	}
	

// Variables Programa Entrada
	char nombre[50],clave[50];
	char usuario[50]="admin", password[50]="1234";
	int orden1,orden2;
	int errorNombre=0,errorPassword=0;
	int contadorentrada=0,ingreso=0;
	
	
	

do {
	system("color b3");
	printf("--------LOGIN USUARIO--------\n");
		printf("-----------------------------\n");
	
	do {
		
	if (errorNombre == 1)
		{system("cls");
		printf("El nombre solo puede contener letras.\n");
		}
	errorNombre = 0;
	
	printf("Introducir nombre:");
	gets(nombre);

	for (i=0; nombre[i]!='\0'; i++) {
		if (nombre[i]<'A' || (nombre[i] > 'Z' && nombre[i] < 'a') || nombre[i]>'z')
			errorNombre = 1;
	}
	} while (errorNombre == 1);
	system("pause");
		orden1=strcmp(nombre,usuario);		
	do {
	if (errorPassword == 1)
		printf("El Paswword solo puede contener numeros.\n");
	
	errorPassword = 0;
	
	printf("Introducir Password:");
	gets(clave);

	for (i=0; clave[i]!='\0'; i++) {
		if (clave[i]<'0' || clave[i]>'9' )
			errorPassword = 1;
	}
	} while (errorPassword == 1);
		orden2=strcmp(clave,password);
		system("pause");	
	if (orden1==0 && orden2==0)
	{ingreso=1;
	}
	else
	{contadorentrada++;
	printf ("El Usuario y/o Password son incorrectos\n");
	system("pause");
	system("cls");
	}

	}while(ingreso==0 && contadorentrada<3 );
	
	if (ingreso == 0)
	{	
	printf("Usted No puede ingresar al Programa. Gracias\n");	
	}
	else{
	printf("BIENVENIDO AL PROGRAMA\n");	
	while(repetir!='N')
  {
 	system("cls");
	system("color b4");
	
	time(&tiempoahora);
	struct tm *mitiempo = localtime(&tiempoahora);
	printf ("Hora Actual %d:%d:%d\n", mitiempo->tm_hour,mitiempo->tm_min,mitiempo->tm_sec);
	
	
	printf ("********MENU OPCIONES********\n");
	printf("R-Reservar Plaza:\n");
	printf("A-Abandonar Plaza:\n");
	printf("E-Estado del Aparcamiento:\n");
	printf("B-Buscar Vehiculo por matricula:\n");
	printf("S-Salir del Programa:\n");
	scanf("%s",&opcion);
	
	
	switch(opcion)
	{
		case 'R': 
		case 'r':
					
					if(aparcamientolleno==NPLAZAS)
			{
			system("cls");
			printf("NO HAY PLAZAS DISPONIBLES\n");
			system("pause");
			break;
			}
					
					
					for(i=0;i<NPLAZAS;i++)
					{
						system("cls");		

					printf("Ingrese TIPO DE VEHICULO %d..\n",i+1);
					printf("1-COCHE\n");
					printf("2-MOTO\n");
					scanf("%s",&aparcamientos[i].tipo);
					while (aparcamientos[i].estado!=1)
				{
				system("cls");
				printf("Ingrese el numero de Matricula %d..(NNNNAAA)\n",i+1);
				scanf("%s",&aparcamientos[i].matricula);
		
				for(j=0;j<4;j++){
					if (aparcamientos[i].matricula[j]>48 && aparcamientos[i].matricula[j]<58){
					aparcamientos[i].bandera=1;
					}
					else{
					printf("MATRICULA INCORRECTA..\n");
					aparcamientos[i].bandera=0;
					for(k=0;k<7;k++){
					aparcamientos[i].matricula[k]=0;
					}
					system("pause");
					break;	
					}
					}
				for(j=4;j<7;j++)
					{
					if (aparcamientos[i].matricula[j]>64 && aparcamientos[i].matricula[j]<123)
					{
						if(aparcamientos[i].matricula[j]>96 && aparcamientos[i].matricula[j]<123)
						{	_strupr(aparcamientos[i].matricula);
					aparcamientos[i].bandera=1;
						}
			
					}
					else
					{
					printf("MATRICULA INCORRECTA..\n");
					aparcamientos[i].bandera=0;
					for(k=0;k<7;k++)
					{
						aparcamientos[i].matricula[k]=0;
					}
					system("pause");	
					}
					}
					if (aparcamientos[i].bandera==1)
					{
					printf("Matricula %s Registrada Con Exito\n",&aparcamientos[i].matricula);
					aparcamientos[i].tiempoingreso+=mitiempo->tm_hour*3600;
					aparcamientos[i].tiempoingreso+=mitiempo->tm_min*60;
					aparcamientos[i].tiempoingreso+=mitiempo->tm_sec;
					printf("total tiempo: %d",aparcamientos[i].tiempoingreso);
					aparcamientos[i].estado=1;
					aparcamientolleno++;
					system("pause");
					}
				}	
		
					}
			
		
		
		break;
		
		
		
	
		case 'A': 
		case 'a':
			
			if(aparcamientolleno==0)
			{
			system("cls");
			printf("NO HAY PLAZAS UTILIZADAS\n");
			system("pause");
			break;
			}
			else
			{
			system("cls");
			for(i=0;i<NPLAZAS;i++)
			{
				if(aparcamientos[i].estado==1)
				{printf("%d- Abandonar Plaza %d Matricula %s \n",i,i,aparcamientos[i].matricula);
				}
				else
				{printf("%d- Plaza %d LIBRE \n",i,i);	
				}
				
			}
			system("pause");
			
			printf("Eliga opcion Abandonar\n"); 
			scanf("%d",&i);
			
				time(&tiempodespues);
			localtime(&tiempodespues);
			printf ("Hora Actual %d:%d:%d\n", mitiempo->tm_hour,mitiempo->tm_min,mitiempo->tm_sec);	
			aparcamientos[i].tiemposalida+=mitiempo->tm_hour*3600;
			aparcamientos[i].tiemposalida+=mitiempo->tm_min*60;
			aparcamientos[i].tiemposalida+=mitiempo->tm_sec;
			printf("total tiempo: %d\n",aparcamientos[i].tiemposalida);
			printf("TOTAL TIEMPO TRANSCURRIDO: %d\n",aparcamientos[i].tiemposalida-aparcamientos[i].tiempoingreso);
			printf("TOTAL A PAGAR: %d\n",(aparcamientos[i].tiemposalida-aparcamientos[i].tiempoingreso)*100);
			aparcamientos[i].tiempoingreso=0;
			
			aparcamientos[i].bandera=0;
			aparcamientos[i].estado=0;
			aparcamientolleno--;
			for(k=0;k<=7;k++)
			{
			aparcamientos[i].matricula[k]='0';	
			}
			printf("PLAZA %d DESOCUPADA",i);
			system("Pause");
			
			}
		case 'e': 
		case 'E':
		system("cls");	
			for(i=0;i<NPLAZAS;i++)
			{
				
			if(aparcamientos[i].estado==1)
				{printf("%d- Abandonar Plaza %d Matricula %s \n",i,i,aparcamientos[i].matricula);
				}
				else
				{printf("%d- Plaza %d LIBRE \n",i,i);	
				}	

			}
			system("pause");
			break;
			
			
			
		break;	
		
		case 'b': 
		case 'B':
	
		while(bandera1!=1)
		{
		
		system("cls");	
		printf("Ingrese Matricula que desea Buscar\n");	
		scanf("%s",matriculaaux);
		
		for(i=0;i<4;i++){
			if (matriculaaux[i]>48 && matriculaaux[i]<58){
							
				bandera1=1;
			}
			else
			{
			printf("MATRICULA INCORRECTA..\n");
			bandera1=0;
			for(i=0;i<7;i++)
			{
			matriculaaux[i]=0;
			}	
			}
			}
			for(i=4;i<7;i++){
			if (matriculaaux[i]>64 && matriculaaux[i]<123)
			{
			if(matriculaaux[i]>96 && matriculaaux[i]<123)
				_strupr(matriculaaux);
			bandera1=1;
			}
			else{
			printf("MATRICULA INCORRECTA..\n");
			bandera1=0;
			system("pause");
			for(i=0;i<7;i++){
				matriculaaux[i]=0;
			}
			}
			}
		}
		printf("Matricula %s Registrada Con Exito\n",&matriculaaux);
		system("pause");
		i=0;
		bandera1=0;
		for(i=0;i<NPLAZAS;i++)
		{
			orden=strcmp(matriculaaux, aparcamientos[i].matricula);
			if(orden==0)
			{
			printf("Vehiculo con matricula: %s APARCADO: Plaza %d\n",aparcamientos[i].matricula,i);
			system ("pause");
			orden=1;
			for(i=1;i<7;i++){
				matriculaaux[i]=0;
			}
			break;
		    }
		    else 
		    {
		    printf("No Existe Vehiculo con Matricula: %s APARCADO PLAZA %d\n",matriculaaux,i);
		   	system("pause");
			}
		}

		break;

		case 's': 
		case 'S':
		repetir='N';
		system("cls");
		printf("***Gracias por Utilizar el Programa Aparcamiento Beta***\n");
		break;	
				
		
			
		default: 
		printf("Opcion Incorrecta\n");
		system("pause");
		break;
			
	system ("pause");
	system("cls");
	
	}	
  }
	
	}
	
}

	

