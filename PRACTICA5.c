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
struct usuario {
   char username[20];
   char password[20];
};

//funciones a implementar!!!!!!!!!!
char menu();
int esDigitoValido(char caracter);
int esLetraValida(char caracter[]);
int esMatriculaValida(char matricula[]);
void mayuscula (char *caracter);
int existeUsuario(struct usuario usuarioValido, char username[], char password[]);

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
	//nuevo
	int matriculavalida;
	// usuarios
	struct usuario miUsuario = {"admin", "1234"};
		
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
	
	
	
do
	{
		system("color b3");
	printf("--------LOGIN USUARIO--------\n");
		printf("-----------------------------\n");
		
	printf("Introducir nombre:");
	gets(nombre);
	printf("Introducir Password:");
	gets(clave);
	
	ingreso=existeUsuario(miUsuario,nombre, clave);
	
	if (ingreso==0)
	{contadorentrada++;
	printf ("El Usuario y/o Password son incorrectos\n");
	system("pause");
	system("cls");
		}	
	}while(ingreso==0 && contadorentrada<3 );

	printf("BIENVENIDO AL PROGRAMA\n");
	system("pause");
	
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
	
	/*
	printf ("********MENU OPCIONES********\n");
	printf("R-Reservar Plaza:\n");
	printf("A-Abandonar Plaza:\n");
	printf("E-Estado del Aparcamiento:\n");
	printf("B-Buscar Vehiculo por matricula:\n");
	printf("S-Salir del Programa:\n");
	scanf("%s",&opcion);
	
	*/
	opcion=menu();
	
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
				printf("Ingrese el numero de Matricula .. %d (NNNNAAA)\n",i+1);
				scanf("%s",&aparcamientos[i].matricula);
		printf("%s",aparcamientos[i].matricula);		
				
				matriculavalida=esMatriculaValida(&aparcamientos[i].matricula);
				
				printf("%s",aparcamientos[i].matricula);
				
				if(matriculavalida==1){
					aparcamientos[i].estado=1;
					printf("MATRICULA CORRECTA..\n");
					aparcamientolleno++;
					system("pause");
				}
				else
				{printf("MATRICULA INCORRECTA..\n");
					aparcamientos[i].bandera=0;
					for(k=0;k<7;k++)
					{
						aparcamientos[i].matricula[k]=0;
					}
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

char menu()
{
	char opcion;
	printf ("********MENU OPCIONES********\n");
	printf("R-Reservar Plaza:\n");
	printf("A-Abandonar Plaza:\n");
	printf("E-Estado del Aparcamiento:\n");
	printf("B-Buscar Vehiculo por matricula:\n");
	printf("S-Salir del Programa:\n");
	scanf("%s",&opcion);
	return opcion;
	
	}	
int esMatriculaValida(char matricula[]){
	int j;
	int digitovalido;
	int letravalida;
	for(j=0;j<4;j++)
					{digitovalido=esDigitoValido(matricula[j]);
					
					}
	
	for(j=4;j<7;j++)
					{letravalida=esLetraValida(matricula[j]);
					}
	if (digitovalido==1 && letravalida==1)
	{return 1;
	}
	else
	{return 0;
	}	
}	
int esDigitoValido(char caracter)
{	
		if (caracter>48 && caracter<58){
			//printf("DIGITO VALIDO..\n");
			return 1;
			}
			else
			{
				//printf("DIGITO INVALIDO..\n");
			return 0;		
						
			}		
}
	
int esLetraValida(char caracter[])
{	
					if (caracter>64 && caracter<123)
					{
						if(caracter>96 && caracter<123)
						{if(caracter=='a'||caracter=='e'||caracter=='i'||caracter=='o'||caracter=='u'||
						caracter=='A'||caracter=='E'||caracter=='I'||caracter=='O'||caracter=='U')
						{//printf("LETRA INVALIDO..\n");
						return 0;
						}
						//printf("LETRA VALIDO..\n");
						mayuscula(&caracter);
					return 1;
						}		
					}
					else
					{
					//printf("LETRA INVALIDO..\n");
					return 0;
							
					}

}	
//aqui hay un problema con la mayuscula
void mayuscula (char *caracter)
{
	caracter=_strupr(caracter);
//printf("caracter_: %s..\n",caracter);
}
//funcion de comprobacion de usuario y contrasena
int existeUsuario(struct usuario usuarioValido, char username[], char password[])
{
	int i;
	int orden1,orden2;
	
	
	//comprobar que el usuario es correcto
	for (i=0; username[i]!='\0'; i++) {
		if (username[i]<'A' || (username[i] > 'Z' && username[i] < 'a') || username[i]>'z')
			{	return 0;
			}
	}
	orden1=strcmp(username,usuarioValido.username);	
	
	// comprobar que la contrasena es correcta
	
	for (i=0; password[i]!='\0'; i++) {
		if (password[i]<'0' || password[i]>'9' )
			return 0;
		}
	orden2=strcmp(password,usuarioValido.password);
	
	if (orden1==0 && orden2==0)
	{return 1;
	}
	else
	{return 0;
	}
	
}
	

