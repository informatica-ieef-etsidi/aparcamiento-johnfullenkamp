#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define NPLAZAS 4
#define NPLAZASC 1

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
//FUNCION PRACTICA6
void inicializar(struct plaza aparcamiento[], int dim);
int buscarPlazaLibre(struct plaza aparcamiento[], int dim, char tipo);
int buscarVehiculo(struct plaza aparcamiento[], int dim, char matricula []);
void recuento(struct plaza aparcamiento[], int dim, int *nLibresCoches, int *nLibresMotos);

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
	int busqueda;
	//nuevo
	int matriculavalida;
	// usuarios
	struct usuario miUsuario = {"admin", "1234"};
	//NUEVO
	char vehiculo;
	int resultado;
	int nLibresCoches=0;
	int nLibresMotos=0;
	
	
	inicializar(aparcamientos,NPLAZAS);


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
	
	opcion=menu();
	
	switch(opcion)
	{
		case 'R': 
		case 'r':
					for(i=0;i<NPLAZAS;i++)
	{
		printf("%c\n",aparcamientos[i].tipo);
		printf("%d\n",aparcamientos[i].estado);
		printf("%s\n",aparcamientos[i].matricula);
	}
			
				fflush(stdin);
				printf("Ingrese TIPO DE VEHICULO ..\n");
				printf("C-COCHE\n");
				printf("M-MOTO\n");
				scanf("%c",&vehiculo);
				resultado=buscarPlazaLibre(aparcamientos,NPLAZAS,vehiculo);
				printf("%d..\n",resultado);
				system("pause");
				
				
				switch(vehiculo)
			{
				case 'C': 
				case 'c':		
				if(resultado==-1)
					{	printf("NO HAY PLAZAS DISPONIBLES DE COCHE\n");
						system("pause");
					}
					else
					{
						printf(" HAY VACANTES DE %c :%d\n",vehiculo,resultado);
						system("pause");
						do
							{
							system("cls");
							printf("INGRESE MATRICULA ..  (NNNNAAA)\n");
							scanf("%s",&aparcamientos[resultado-1].matricula);
							printf("%s",aparcamientos[resultado-1].matricula);
							matriculavalida=esMatriculaValida(&aparcamientos[resultado-1].matricula);
							
							if(matriculavalida==1)
								{
								aparcamientos[resultado-1].estado=1;
								aparcamientos[resultado-1].tipo=vehiculo;
								aparcamientos[resultado-1].tiempoingreso+=mitiempo->tm_hour*3600;
								aparcamientos[resultado-1].tiempoingreso+=mitiempo->tm_min*60;
								aparcamientos[resultado-1].tiempoingreso+=mitiempo->tm_sec;
								printf("total tiempo: %d\n",aparcamientos[resultado-1].tiempoingreso);
								printf("MATRICULA REGISTRADA CORRECTAMENTE..\n");	
								system("pause");
								}
							else
								{printf("MATRICULA INCORRECTA..\n");
								aparcamientos[resultado-1].estado=0;
								for(k=0;k<7;k++)
								{
								aparcamientos[resultado-1].matricula[k]=0;
								}
								system("pause");		
								}
									
							}while (aparcamientos[resultado-1].estado!=1);

					}
					break;
				
			case 'M': 
			case 'm':		
				if(resultado==-1)
					{	printf("NO HAY PLAZAS DISPONIBLES DE MOTO\n");
						system("pause");
					}
					else
					{
						printf(" HAY VACANTES DE %c :%d\n",vehiculo,resultado);
						system("pause");
						do
							{fflush(stdin);
							system("cls");
							printf("INGRESE MATRICULA ..  (NNNNAAA)\n");
							scanf("%s",&aparcamientos[resultado+NPLAZASC-1].matricula);
							printf("%s",aparcamientos[resultado+NPLAZASC-1].matricula);
							matriculavalida=esMatriculaValida(&aparcamientos[resultado+NPLAZASC-1].matricula);
							
							if(matriculavalida==1)
								{
								aparcamientos[resultado+NPLAZASC-1].estado=1;
								aparcamientos[resultado+NPLAZASC-1].tipo=vehiculo;
								aparcamientos[resultado+NPLAZASC-1].tiempoingreso+=mitiempo->tm_hour*3600;
								aparcamientos[resultado+NPLAZASC-1].tiempoingreso+=mitiempo->tm_min*60;
								aparcamientos[resultado+NPLAZASC-1].tiempoingreso+=mitiempo->tm_sec;
								printf("total tiempo: %d\n",aparcamientos[resultado+NPLAZASC-1].tiempoingreso);
								printf("MATRICULA REGISTRADA CORRECTAMENTE..\n");	
								system("pause");
								}
							else
								{printf("MATRICULA INCORRECTA..\n");
								aparcamientos[resultado+NPLAZASC-1].estado=0;
								for(k=0;k<7;k++)
								{
								aparcamientos[resultado+NPLAZASC-1].matricula[k]=0;
								}
								system("pause");		
								}
									
							}while (aparcamientos[resultado+NPLAZASC-1].estado!=1);

					}break;
					
				
				
				default:
						break;
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

			recuento(aparcamientos,NPLAZAS,&nLibresCoches,&nLibresMotos);
			printf("PLAZAS LIBRES DE COCHES: %d\n ",nLibresCoches);
			printf("PLAZAS LIBRES DE MOTOS: %d\n ",nLibresMotos);
			system("Pause");
			
			
			for (i=0;i<NPLAZAS;i++)
						{
							printf ("PLAZA %d ",i+1);
							printf ("TIPO %c ",aparcamientos[i].tipo);
							if (aparcamientos[i].estado==1)
							  printf ("OCUPADA - Matricula %s\n",aparcamientos[i].matricula);
							else
							  printf ("LIBRE\n");
						}
			system("Pause");
			break;
		/*	
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
		*/
		
		
		
		case 'b': 
		case 'B':
					fflush(stdin);	
						system("cls");
						printf("Ingrese Matricula que desea Buscar\n");	
						scanf("%s",&matriculaaux);
						matriculavalida=esMatriculaValida(&matriculaaux);
				
					if(matriculavalida==1)
					{busqueda=buscarVehiculo(aparcamientos,NPLAZAS,matriculaaux);
					printf("%d",busqueda);
					system("pause");
					if(busqueda==-1)
					{printf("NO SE HA ENCONTRADO MATRICULA: %s",matriculaaux);
					system("pause");
					}
					else
					{
					printf("SE HA ENCONTRADO MATRICULA: %s\n",matriculaaux);
					printf("APARCADO: Plaza %d\n",busqueda+1);	
					system("pause");
					}						
					}
					else
					{
						printf("MATRICULA INVALIDA\n");		
						system("pause");
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
	scanf("%c",&opcion);
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
void inicializar(struct plaza aparcamientos[], int dim)
{
	int i;
	for(i=0;i<NPLAZASC;i++)
	{
		
		aparcamientos[i].estado=0;
		aparcamientos[i].tiempoingreso=0;
		aparcamientos[i].tiemposalida=0;
		aparcamientos[i].bandera=0;
		aparcamientos[i].tipo='C';
			}
	for(i=NPLAZASC;i<dim;i++)
	{
		
		aparcamientos[i].estado=0;
		aparcamientos[i].tiempoingreso=0;
		aparcamientos[i].tiemposalida=0;
		aparcamientos[i].bandera=0;
		aparcamientos[i].tipo='M';
			}
	
}
int buscarPlazaLibre(struct plaza aparcamiento[], int dim, char tipo)
{
	int i,resultado=0;
	
	for (i=0;i<dim;i++)
	{
		if (aparcamiento[i].estado==0)
		if(aparcamiento[i].tipo==tipo)
		   resultado++;
	}
	if(resultado==0)
	return -1;
	return resultado;
}
	
int buscarVehiculo(struct plaza aparcamiento[], int dim, char matricula [])
{
	int orden,i;
	for(i=0;i<dim;i++)
		{
			orden=strcmp(matricula, aparcamiento[i].matricula);	
			if(orden==0)
			return i;
		}
	return -1;
	
}	
void recuento(struct plaza aparcamientos[], int dim, int *nLibresCoches, int *nLibresMotos)
{
	int i;
	*nLibresMotos=0;
	*nLibresCoches=0;
	
	for(i=0;i<dim;i++)
	{
		if(aparcamientos[i].tipo=='M' && aparcamientos[i].estado==0)
		(*nLibresMotos)++;
		if(aparcamientos[i].tipo=='C' && aparcamientos[i].estado==0)
		(*nLibresCoches)++;
	}
	
}

