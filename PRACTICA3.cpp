#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct plaza {
	
	int estado; //0 - libre 1:ocupado
	char tipo;	//m-moto c-coche
	char matricula[8]; //formato nnnnlll
	int tiempoingreso;
	int tiemposalida;
	int bandera;

};
main() {
	struct plaza plaza1,plaza2;	
	char repetir='S';
	char matriculaaux[8];
	time_t tiempoahora,tiempodespues;
	char opcion;
	int i;
	int bandera1;
	int orden=1;

	
	plaza1.estado=0;
	plaza2.estado=0;
	plaza1.tiempoingreso=0;
	plaza2.tiempoingreso=0;
	plaza1.tiemposalida=0;
	plaza2.tiemposalida=0;
	plaza1.bandera=0;
	plaza2.bandera=0;
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
	
	if (ingreso == 0){
	printf("Usted No puede ingresar al Programa. Gracias\n");	
	}else{
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
					
		if(plaza1.bandera==1 && plaza2.bandera==1)
		{
			system("cls");
			printf("NO HAY PLAZAS DISPONIBLES\n");
			system("pause");
			break;
		}
		
		if (plaza1.estado==0)
		{
		system("cls");		
		
															// AQUI INICIO DE MATRICULA 
		
		printf("Ingrese TIPO DE VEHICULO 1..\n");
		printf("1-COCHE\n");
		printf("2-MOTO\n");
		scanf("%s",&plaza1.estado);	
															// Comprobar si la matricula es correcta	
		
		while (plaza1.bandera!=1)
		{
		system("cls");
		printf("Ingrese el numero de Matricula 1..\n");
		scanf("%s",&plaza1.matricula);
		
		for(i=0;i<4;i++){
			if (plaza1.matricula[i]>48 && plaza1.matricula[i]<58){
			plaza1.bandera=1;
			}
			else{
			printf("MATRICULA INCORRECTA..\n");
			plaza1.bandera=0;
			
			
			for(i=0;i<7;i++){
			plaza1.matricula[i]=0;
			}
			system("pause");
			break;	
			}
			}
		for(i=4;i<7;i++){
			if (plaza1.matricula[i]>64 && plaza1.matricula[i]<123)
			{
				if(plaza1.matricula[i]>96 && plaza1.matricula[i]<123)
				_strupr(plaza1.matricula);
			plaza1.bandera=1;
			}
			else{
			printf("MATRICULA INCORRECTA..\n");
			plaza1.bandera=0;
			for(i=0;i<7;i++){
				plaza1.matricula[i]=0;
			}
			system("pause");
			break;	
			}
			
			}
				if (plaza1.bandera==1){
			printf("Matricula %s Registrada Con Exito\n",&plaza1.matricula);
			plaza1.tiempoingreso+=mitiempo->tm_hour*3600;
			plaza1.tiempoingreso+=mitiempo->tm_min*60;
			plaza1.tiempoingreso+=mitiempo->tm_sec;
			printf("total tiempo: %d",plaza1.tiempoingreso);
			plaza1.estado==1;
			system("pause");
			break;
		}	
			
	
			}
		break;
		}
		if (plaza2.estado==0)
		{
		system("cls");		
		
															// AQUI INICIO DE MATRICULA2
		
		printf("Ingrese TIPO DE VEHICULO 2..\n");
		printf("1-COCHE\n");
		printf("2-MOTO\n");
		scanf("%s",&plaza2.estado);	
															// Comprobar si la matricula es correcta	
		
		while (plaza2.bandera!=1)
		{
		system("cls");
		printf("Ingrese el numero de Matricula 2..\n");
		scanf("%s",&plaza2.matricula);
		
		for(i=0;i<4;i++){
			if (plaza2.matricula[i]>48 && plaza2.matricula[i]<58){
				plaza2.bandera=1;
			}
			else{
			printf("MATRICULA INCORRECTA..\n");
			plaza2.bandera=0;
			
			
			for(i=0;i<7;i++){
			plaza2.matricula[i]=0;
			}
			system("pause");
			break;	
			}
			}
		for(i=4;i<7;i++){
			if (plaza2.matricula[i]>64 && plaza2.matricula[i]<123)
			{
				if(plaza2.matricula[i]>96 && plaza2.matricula[i]<123)
				_strupr(plaza2.matricula);
			plaza2.bandera=1;
			}
			else{
			printf("MATRICULA INCORRECTA..\n");
			plaza2.bandera=0;
			for(i=0;i<7;i++){
				plaza2.matricula[i]=0;
			}
			system("pause");
			break;	
			}
			
			}
				if (plaza2.bandera==1){
			printf("Matricula %s Registrada Con Exito\n",&plaza2.matricula);
			plaza2.tiempoingreso+=mitiempo->tm_hour*3600;
			plaza2.tiempoingreso+=mitiempo->tm_min*60;
			plaza2.tiempoingreso+=mitiempo->tm_sec;
			printf("total tiempo: %d",plaza2.tiempoingreso);
			plaza2.estado==1;
			system("pause");
			break;
		}	
			
	
			}

		break;
		}

		break;
	
		
	
		
		case 'A': 
		case 'a':
			
				if((plaza1.bandera==0) && (plaza2.bandera==0))	
				{system("cls");
					printf("NO EXISTEN PLAZAS OCUPADAS\n");
					system("pause");
					break;
				}
			
				printf("Eliga opcion Abandonar\n");          // aqui serìa mejor con la opcion for y luego mostrar
				
				if(plaza1.bandera==1)
				{
					printf("1- Abandonar Plaza 1 - Matricula %s\n",&plaza1.matricula);			
				}
				else
				{
				printf("Plaza 1 - LIBRE-\n");	
				}	
				
				if(plaza2.bandera==1)
				{
				
				printf("2- Abandonar Plaza 2 - Matricula %s\n",&plaza2.matricula);
				}
			else
				{
				printf("Plaza 2 - LIBRE-\n");
				
				}
				printf("3-VOLVER MENU\n");
				
				
				scanf("%s",&opcion);	
			//aqui el switch
			switch (opcion)
			{
			
			case '3':
				break;
				
			case '1':
				
			system("cls");
			printf("Plaza 1 - LIBRE-\n");
			
			time(&tiempodespues);
			localtime(&tiempodespues);
			printf ("Hora Actual %d:%d:%d\n", mitiempo->tm_hour,mitiempo->tm_min,mitiempo->tm_sec);	
			plaza1.tiemposalida+=mitiempo->tm_hour*3600;
			plaza1.tiemposalida+=mitiempo->tm_min*60;
			plaza1.tiemposalida+=mitiempo->tm_sec;
			printf("total tiempo: %d\n",plaza1.tiemposalida);
			printf("TOTAL TIEMPO TRANSCURRIDO: %d\n",plaza1.tiemposalida-plaza1.tiempoingreso);
			printf("TOTAL A PAGAR: %d\n",(plaza1.tiemposalida-plaza1.tiempoingreso)*100);
			plaza1.tiempoingreso=0;
	
			for(i=0;i<=7;i++)
			{
			plaza1.matricula[i]=0;
			plaza1.bandera=0;	
			}
			system ("pause");
			break;
			
			//aqui va
			case '2':
				
			system("cls");
			printf("Plaza 2 - LIBRE-\n");
			
			time(&tiempodespues);
			localtime(&tiempodespues);
			printf ("Hora Actual %d:%d:%d\n", mitiempo->tm_hour,mitiempo->tm_min,mitiempo->tm_sec);	
			plaza2.tiemposalida+=mitiempo->tm_hour*3600;
			plaza2.tiemposalida+=mitiempo->tm_min*60;
			plaza2.tiemposalida+=mitiempo->tm_sec;
			printf("total tiempo: %d\n",plaza2.tiemposalida);
			printf("TOTAL TIEMPO TRANSCURRIDO: %d\n",plaza2.tiemposalida-plaza2.tiempoingreso);
			printf("TOTAL A PAGAR: %d\n",(plaza2.tiemposalida-plaza2.tiempoingreso)*100);
			plaza2.tiempoingreso=0;
	
			for(i=0;i<=7;i++)
			{
			plaza2.matricula[i]=0;
			plaza2.bandera=0;	
			}
			system ("pause");
			break;
			
			
			
			}
				
				
		break;		
				
		 
				
			
			
		case 'E': 
		case 'e':	
			if (plaza1.bandera==0)
			{
				printf("Plaza 1 - LIBRE-\n");
			}
			else
			{
				printf("Plaza 1 - OCUPADA- Matricula %s\n",&plaza1.matricula);
					if(plaza1.tipo=1)
				{
				printf("Plaza 1 - TIPO- COCHE\n");	
				}
				else{
				printf("Plaza 1 - TIPO- MOTO\n");	
				}
			}
		     if (plaza2.bandera==0)
			{
				printf("Plaza 2 - LIBRE-\n");
			}
			else
			{
				printf("Plaza 2 - OCUPADA- Matricula %s\n",&plaza2.matricula);
				if(plaza2.tipo=1)
				{
				printf("Plaza 2 - TIPO- COCHE\n");	
				}
				else{
				printf("Plaza 2 - TIPO- MOTO\n");	
				}
			}
			
			system("pause");
			break;
			
			
			
			
			
			
		case 'b': 
		case 'B':
		{
		
		while(bandera1!=1)
		{
		system("cls");	
		printf("Ingrese Matricula que desea Buscar\n");	
		scanf("%s",matriculaaux);	
															//COMPROBAR SI ESTA CORRECTA
		for(i=0;i<4;i++){
			if (matriculaaux[i]>48 && matriculaaux[i]<58){
							
				bandera1=1;
			}
			else{
			printf("MATRICULA INCORRECTA..\n");
			bandera1=0;
			for(i=0;i<7;i++){
			matriculaaux[i]=0;
			}
			system("pause");
			break;	
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
			break;	
			}
			
			};	
			
			
		}
		
		printf("Matricula %s Registrada Con Exito\n",&matriculaaux);
			
			orden=strcmp(matriculaaux, plaza1.matricula);
			if(orden==0)
			{
			printf("Vehiculo con matricula: %s APARCADO: Plaza1\n",plaza1.matricula);
			system ("pause");
			orden=1;
			for(i=1;i<7;i++){
				matriculaaux[i]=0;
			}
		    }
			
			orden=strcmp(matriculaaux,plaza2.matricula);
			if(orden==0)
			{
			printf("Vehiculo con matricula: %s APARCADO: Plaza2\n",plaza2.matricula);
			system ("pause");
			orden=1;
			for(i=1;i<7;i++){
				matriculaaux[i]=0;
			}
			
		    }
		    if(orden!=0)
		    {
		    printf("No Existe Vehiculo con Matricula: %s APARCADO\n",matriculaaux);
			system("pause");
			}
			
		system ("pause");
		break;
			
		}
			
	
		
		
		
		
		
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
	
	

