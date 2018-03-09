#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

main()	
{
	
	int verificacion=0;
	int	aux1=1, aux2=1;		
	int i=0;
	char opcion,plaza1[7]={0},plaza2[7]={0};
	int opcion2;
	while(1)
 {
 	
	
	printf ("Eliga la Opcion:\n");
	printf("R-Reservar Plaza:\n");
	printf("A-Abandonar Plaza:\n");
	printf("E-Estado del Aparcamiento:\n");
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
		
		printf("Ingrese el numero de Matricula 1..\n");
		scanf("%s",&plaza1);
		
		printf("Matricula %s Registrada Con Exito\n",&plaza1);
		aux1=0;
		break;
		}	
		
		for(i=0;i<=7;i++)
		{
			if (plaza2[i]!=0)
			{aux2=0;
			}
		}
		
		if (aux2!=0)
		{
				
		printf("Ingrese el numero de Matricula 2..\n");
		scanf("%s",&plaza2);
			printf("Matricula %s Registrada Con Exito\n",&plaza2);
			aux2=0;
			break;
		}		
					
		if (aux1==0 && aux2==0) 
		{
		printf("No existen Plazas Disponibles\n");
			break;	
		}
		break;
		
		case 'A':
		case 'a':
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
				
				scanf("%s",&opcion2);	
				
			switch (opcion2)
			{
			
			
			case '1':
			aux1=1;
			printf("Plaza 1 - LIBRE-\n");
			for(i=0;i<=7;i++)
			{
			plaza1[i]=0;	
			}
			break;
			case '2':	
			aux2=1;
			printf("Plaza 1 - LIBRE-\n");
			for(i=0;i<=7;i++)
			{
			plaza2[i]=0;	
			}
			break;
			
			
			}
			
				
			break;
			
			
		case 'E': 
		case 'e':
		
			if (aux1==1)
			{
				printf("Plaza 1 - LIBRE-\n");
			}
			else
			{
				printf("Plaza 1 - OCUPADA- Matricula %s\n",&plaza1);
			}
		     if (aux2==1)
			{
				printf("Plaza 2 - LIBRE-\n");
			}
			else
			{
				printf("Plaza 2 - OCUPADA- Matricula %s\n",&plaza2);
			}
			break;
			
					
		default: printf("Opcion Incorrecta\n");
		break;
	
		
	}
	system ("pause");
	system("cls");
	i++;
 }
}
