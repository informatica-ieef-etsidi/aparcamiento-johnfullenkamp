/*el programa solo tiene dos plazas hasta el momento, con tipo
moto y coche. Luego se puede agregar más coches y plazas*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

main()	
{
	int tiempoingreso[2];
	int tiemposalida[2];
	int pago[2];
	int verificacion=0;
	int	aux1=1, aux2=1;
	int bandera1=0;		
	int i=0,orden=1;
	int cont[2]={0};
	char opcion,plaza1[7]={0},plaza2[7]={0},repetir='s',matriculaaux[7];
	char tipovehiculo={0};
	char opcion2={0};
	time_t tiempoahora,tiempodespues;
	
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
		
		for(i=0;i<=7;i++)
		{
			if (plaza1[i]!=0)
			{aux1=0;
			}
					
		}
		if (aux1!=0)
		{
		system("cls");		
		
		//aqui inicio lo nuevo
		
		printf("Ingrese TIPO DE VEHICULO 1..\n");
		printf("1-COCHE\n");
		printf("2-moto\n");
		scanf("%s",&tipovehiculo);
		
		switch(tipovehiculo)
		{
		
		case '1':
		if(cont[0]==0)
		{
			
			printf("Ingrese el numero de Matricula 1..\n");
		scanf("%s",&plaza1);
		
		for(i=0;i<4;i++){
			if (plaza1[i]>48 && plaza1[i]<58){
				bandera1=1;
			}
			else{
			printf("MATRICULA INCORRECTA..\n");
			aux1=1;
			bandera1=0;
			for(i=0;i<7;i++){
			plaza1[i]=0;
			}
			break;	
			}
			}
			for(i=4;i<7;i++){
			if (plaza1[i]>64 && plaza1[i]<123)
			{
				if(plaza1[i]>96 && plaza1[i]<123)
				_strupr(plaza1);
			bandera1=1;
			}
			else{
			printf("MATRICULA INCORRECTA..\n");
			bandera1=0;
			aux1=1;
			for(i=0;i<7;i++){
				plaza1[i]=0;
			}
			break;	
			}
			
			};
		if (bandera1==1){
			printf("Matricula %s Registrada Con Exito\n",&plaza1);
			aux1=0;
			tiempoingreso[0]+=mitiempo->tm_hour*3600;
			tiempoingreso[0]+=mitiempo->tm_min*60;
			tiempoingreso[0]+=mitiempo->tm_sec;
			printf("total tiempo: %d",tiempoingreso[0]);
			cont[0]=1;

		}	
			
		
		
		
		system ("pause");
		break;
			
			
		}
			
			
			break;
		
			
		case '2':
		if(cont[1]==0)
		{
			
			printf("Ingrese el numero de Matricula 1..\n");
		scanf("%s",&plaza1);
		
		for(i=0;i<4;i++){
			if (plaza1[i]>48 && plaza1[i]<58){
				bandera1=1;
			}
			else{
			printf("MATRICULA INCORRECTA..\n");
			aux1=1;
			bandera1=0;
			for(i=0;i<7;i++){
			plaza1[i]=0;
			}
			break;	
			}
			}
			for(i=4;i<7;i++){
			if (plaza1[i]>64 && plaza1[i]<123)
			{
				if(plaza1[i]>96 && plaza1[i]<123)
				_strupr(plaza1);
			bandera1=1;
			}
			else{
			printf("MATRICULA INCORRECTA..\n");
			bandera1=0;
			aux1=1;
			for(i=0;i<7;i++){
				plaza1[i]=0;
			}
			break;	
			}
			
			};
		if (bandera1==1){
			printf("Matricula %s Registrada Con Exito\n",&plaza1);
			aux1=0;
			tiempoingreso[0]+=mitiempo->tm_hour*3600;
			tiempoingreso[0]+=mitiempo->tm_min*60;
			tiempoingreso[0]+=mitiempo->tm_sec;
			printf("total tiempo: %d",tiempoingreso[0]);
			cont[1]=1;

		}	
			
		
		
		
		system ("pause");
		break;
			
			
		}
	
		break;
		}
	
	system("pause");
		
		break;

		}//fin del primer if	
		
		for(i=0;i<=7;i++)
		{
			if (plaza2[i]!=0)
			{aux2=0;
			}
					
		}
				if (aux2!=0)
		{
		system("cls");		
		
		//aqui inicio lo nuevo
		
		printf("Ingrese TIPO DE VEHICULO 2..\n");
		printf("1-COCHE\n");
		printf("2-moto\n");
		scanf("%s",&tipovehiculo);
		
		switch(tipovehiculo)
		{
		
		case '1':
		if(cont[0]==0)
		{
			
			printf("Ingrese el numero de Matricula 2..\n");
		scanf("%s",&plaza2);
		
		for(i=0;i<4;i++){
			if (plaza2[i]>48 && plaza2[i]<58){
				bandera1=1;
			}
			else{
			printf("MATRICULA INCORRECTA..\n");
			aux2=1;
			bandera1=0;
			for(i=0;i<7;i++){
			plaza2[i]=0;
			}
			break;	
			}
			}
			for(i=4;i<7;i++){
			if (plaza2[i]>64 && plaza2[i]<123)
			{
				if(plaza2[i]>96 && plaza2[i]<123)
				_strupr(plaza2);
			bandera1=1;
			}
			else{
			printf("MATRICULA INCORRECTA..\n");
			bandera1=0;
			aux2=1;
			for(i=0;i<7;i++){
				plaza2[i]=0;
			}
			break;	
			}
			
			};
		if (bandera1==1){
			printf("Matricula %s Registrada Con Exito\n",&plaza2);
			aux2=0;
			tiempoingreso[1]+=mitiempo->tm_hour*3600;
			tiempoingreso[1]+=mitiempo->tm_min*60;
			tiempoingreso[1]+=mitiempo->tm_sec;
			printf("total tiempo: %d",tiempoingreso[1]);
			cont[0]=1;

		}	
			
		
		
		
		system ("pause");
		break;
			
			
		}
		else
		{
			printf("NO HAY PLAZAS DISPONIBLES: COCHES\n");
		}
			
			
			break;
		
			
		case '2':
		if(cont[1]==0)
		{
			
			printf("Ingrese el numero de Matricula 2..\n");
		scanf("%s",&plaza2);
		
		for(i=0;i<4;i++){
			if (plaza2[i]>48 && plaza2[i]<58){
				bandera1=1;
			}
			else{
			printf("MATRICULA INCORRECTA..\n");
			aux2=1;
			bandera1=0;
			for(i=0;i<7;i++){
			plaza2[i]=0;
			}
			break;	
			}
			}
			for(i=4;i<7;i++){
			if (plaza2[i]>64 && plaza2[i]<123)
			{
				if(plaza2[i]>96 && plaza2[i]<123)
				_strupr(plaza2);
			bandera1=1;
			}
			else{
			printf("MATRICULA INCORRECTA..\n");
			bandera1=0;
			aux2=1;
			for(i=0;i<7;i++){
				plaza2[i]=0;
			}
			break;	
			}
			
			};
		if (bandera1==1){
			printf("Matricula %s Registrada Con Exito\n",&plaza2);
			aux2=0;
			tiempoingreso[1]+=mitiempo->tm_hour*3600;
			tiempoingreso[1]+=mitiempo->tm_min*60;
			tiempoingreso[1]+=mitiempo->tm_sec;
			printf("total tiempo: %d",tiempoingreso[1]);
			cont[1]=1;

		}	
			
		
		
		
		system ("pause");
		break;
			
			
		}
		else
		{
		 printf("NO HAY PLAZAS DISPONIBLES: MOTOS\n");
		 
		}
	
		break;
		}
	
	system("pause");
		
		
		
		break;
			
		
		
		
		
		
		//aqui termina lo nuevo
		
		
		
		}
			
		if(cont[0]==1 && cont[1]==1){
			printf("NO HAY PLAZAS DISPONIBLES");
			break;
		}	
			
		
		
		case 'A':
		case 'a':
			
			if(aux1==1 ){
				if(aux2==1)	{system("cls");
			printf("NO EXISTEN PLAZAS OCUPADAS\n");
			system("pause");
			break;
			}
				
				
			}
			
		
					
			
			printf("Eliga opcion Abandonar\n");
			if (aux1==0)
				{	
				
				printf("1- Abandonar Plaza 1 - Matricula %s\n",&plaza1);
				
				}
			else
				{
				printf("Plaza 1 - LIBRE-\n");
				
				
				}		
			if(aux2==0)
				{
				
				printf("2- Abandonar Plaza 2 - Matricula %s\n",&plaza2);
				}
			else
				{
				printf("Plaza 2 - LIBRE-\n");
				
				}
				printf("3-VOLVER MENU\n");
				
			
		scanf("%s",&opcion2);	
			//aqui el switch
			switch (opcion2)
			{
			
			case '3':
				break;
			case '1':
				
			system("cls");
			aux1=1;
			printf("Plaza 1 - LIBRE-\n");
			
			time(&tiempodespues);
			localtime(&tiempodespues);
			printf ("Hora Actual %d:%d:%d\n", mitiempo->tm_hour,mitiempo->tm_min,mitiempo->tm_sec);	
			tiemposalida[0]=0;
			tiemposalida[0]+=mitiempo->tm_hour*3600;
			tiemposalida[0]+=mitiempo->tm_min*60;
			tiemposalida[0]+=mitiempo->tm_sec;
			printf("total tiempo: %d\n",tiemposalida[0]);
			printf("TOTAL TIEMPO TRANSCURRIDO: %d\n",tiemposalida[0]-tiempoingreso[0]);
			pago[0]=(tiemposalida[0]-tiempoingreso[0])*100;
			printf("TOTAL A PAGAR: %d\n",pago[0]);
			tiempoingreso[0]=0;
			
			
			for(i=0;i<=7;i++)
			{
			plaza1[i]=0;	
			}
			system ("pause");
			break;
			
			
			case '2':
			system("cls");	
			aux2=1;
			printf("Plaza 2 - LIBRE-\n");
			time(&tiempodespues);
			localtime(&tiempodespues);
			printf ("Hora Actual %d:%d:%d\n", mitiempo->tm_hour,mitiempo->tm_min,mitiempo->tm_sec);
			
			tiemposalida[1]=0;
			tiemposalida[1]+=mitiempo->tm_hour*3600;
			tiemposalida[1]+=mitiempo->tm_min*60;
			tiemposalida[1]+=mitiempo->tm_sec;
			printf("total tiempo: %d\n",tiemposalida[1]);
			printf("TOTAL TIEMPO TRANSCURRIDO: %d\n",tiemposalida[1]-tiempoingreso[1]);
			pago[1]=(tiemposalida[1]-tiempoingreso[1])*100;
			printf("TOTAL A PAGAR: %d\n",pago[1]);			
			tiempoingreso[1]=0;
			for(i=0;i<=7;i++)
			{
			plaza2[i]=0;	
			}
			system ("pause");
			break;

			
			
		break;
	}		
			
		case 'E': 
		case 'e':
		
			if (aux1==1)
			{
				printf("Plaza 1 - LIBRE-\n");
			}
			else
			{
				printf("Plaza 1 - OCUPADA- Matricula %s\n",&plaza1);
					if(cont[0]==1){
				printf("Plaza 1 - TIPO- COCHE\n");	
				}
				else{
				printf("Plaza 1 - TIPO- MOTO\n");	
				}
			}
		     if (aux2==1)
			{
				printf("Plaza 2 - LIBRE-\n");
			}
			else
			{
				printf("Plaza 2 - OCUPADA- Matricula %s\n",&plaza2);
				if(cont[1]==1){
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
			{system("cls");
			
		printf("Ingrese Matricula que desea Buscar\n");	
		scanf("%s",matriculaaux);								//si lo que ingresa está correcto o no															
				
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
			for(i=0;i<7;i++){
				matriculaaux[i]=0;
			}
			break;	
			}
			
			};
		if (bandera1==1){
			printf("Matricula %s Registrada Con Exito\n",&matriculaaux);
			
			orden=strcmp(matriculaaux,plaza1);
			if(orden==0)
			{
			printf("Vehiculo con matricula: %s APARCADO: Plaza1\n",plaza1);
			system ("pause");
			orden=1;
			for(i=1;i<7;i++){
				matriculaaux[i]=0;
			}
		    }
			
			orden=strcmp(matriculaaux,plaza2);
			if(orden==0)
			{
			printf("Vehiculo con matricula: %s APARCADO: Plaza2\n",plaza2);
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
			
		break;	
					
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
