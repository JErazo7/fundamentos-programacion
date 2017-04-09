#include<iostream>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

//Estructura
struct datos{
	char palb[20];
};

int main()
{
	//DECLARACION DE VARIBLES
	int op, op1, num, sw, i, azar, longi, inten, x=0, acer, fall;
	char pal[20], temp[20], palb, op2, op3, letra;
	datos palabra[20];
	srand(time(NULL));
	system("color 80");
	for(i=0; i <20; i++)
		strcpy(palabra[i].palb, "");

	//MENU PRINCIPAL
	do{		
		do{
			printf("\t\t\t***MENU PRINCIPAL***\n");
			printf("\n\t1)ADMINISTRAR\n");
			printf("\n\t2)JUGAR\n");
			printf("\n\t3)SALIR\n");
			printf("\n\t**Opcion a ejecutar: ");
			//lectura de opción elegida
			scanf("%d",&op);
			if(op<1 || op >3)			
			{
				printf("\n\tError, opcion invalida\n");
				printf("\t");
				system("pause");
				system("cls");
			}					
		}while(op <1 || op >3);
		
		switch(op){
			case 1:{
				do{
					//Menu de administrador
					system("cls");
					printf("\t\t\t***ADMINNISTRADOR DE PALABRAS***\n");
					printf("\n\t1)INGRESAR\n");
					printf("\n\t2)ELIMINAR\n");
					printf("\n\t3)LISTADO COMPLETO\n");
					printf("\n\t4)REGRESAR\n");					
					printf("\n\n\t**Opcion a ejecutar: ");
					scanf("%d",&op1);
					if(op1<1 || op1 >4)			
					{
					//lectura de ingreso 
						printf("\n\tError, opcion invalida\n");
						printf("\t");
						system("pause");
					}
					else if( op1==4)						
						break;																	
				}while(op1 <1 || op1 >4);	
				switch(op1)
				{
					case 1:{				
						printf("\t\t%d",x);
						do
						{	//Ingresar palabras
							system("cls");						
							printf("\t\t\t***ADMINNISTRADOR DE INGRESO***\n");
							printf("\n\t1)PALABRA A INGRESAR: ");
							
							for(i=0; i < 20; i++)
								{	//Posicionamiento de la palabra ingresada
									if(strcmp(palabra[i].palb,"")==0)
									{
										fflush(stdin);
										gets(palabra[i].palb);
										if (i > x)
											x++;
										break;		
									} 	
								}
							do
							{
								// Validar nuevo ingreso 
								sw=0;
								printf("\n\tDESEA INGRESAR OTRA PALABRA S/N: ");
								fflush(stdin);
								scanf("%c",&op3);								
								if(op3!='s' && op3!='S' && op3!='n' && op3!='N')
								{
									printf("\n\tERROR, OPCION INVALIDA\n");
									sw=1;
								}										
							}while(sw==1);
															
						}while(op3=='s' || op3=='S');
						break;					
					}			
					case 2:{
						do{
							//Opción de Eliminación
							system("cls");						
							printf("\t\t\t***ADMINNISTRADOR DE ELIMINACION***\n");
							printf("\n\tPALABRA A ELIMINAR: ");
							fflush(stdin);
							gets(pal);
							sw=0;
							for (i=0; i< 20; i++)
							{								
								if (strcmp(pal,palabra[i].palb)==0)
								{
									sw=1;									
									do
									{
										//Validar la eliminación
										printf("\n\tESTA SEGURO QUE DESEA ELIMINARLA S/N: ");
										fflush(stdin);
										scanf("%c",&op2);
										if(op2!='s' && op2!='S' && op2 !='N' && op2!='n')
											printf("\n\tERROR, OPCION INVALIDA\n");									
											
									}while(op2!='s' && op2!='S' && op2 !='N' && op2!='n');
									
									if(op2=='s'|| op2=='S' )
									{
										strcpy(palabra[i].palb, "");
										printf("\n\tPALABRA ELMINIDA\n");
										
									}											
									else if(op2=='n' || op2=='N')
										printf("\n\tPALABRA NO ELIMINADA\n");										
								}
							}							
							if(sw==0)
								printf("\n\tPALABRA NO ENCONTRADA\n");
							do
							{
								//Nueva eliminación
								sw=0;
								printf("\n\tDESEA ELIMINAR OTRA PALABRA S/N: ");
								fflush(stdin);
								scanf("%c",&op3);
								if(op3!='<<s' & op3!='S' & op3!='n' & op3!='N')
								{
									printf("\n\tERROR, OPCION INVALIDA\n");
									sw=1;
								}
										
							}while(sw==1);	
																
						}while(op3=='s' || op3=='S');
						
						break;
				 	}
				 	
				 	case 3:{
				 		//Visualizar palabras ingresadas anteriormente
				 		system("cls");						
						printf("\t\t\t***LISTADO DE PALABRAS***\n\n");
						for(i=0; i<20 ; i++)
							printf("\t%d) %s\n",i+1, palabra[i].palb);
						printf("\n\t");
						system("pause");
						break;
						
					 }
					
					default:{
						break;
					}				
				}
				system("cls");
				break;
			}
			
			case 2: { //Opción de Jugar
				do
				{
					do{
						//Elección de palabra al azar
						azar=rand()%(x+1);							
					}while(strcmp(palabra[azar].palb,"")==0);		
					
					longi=strlen(palabra[azar].palb);
					for(i = 0; i < longi; i++)
						temp[i]='_';
					inten=5;	
					acer=0;
					fall=0;
					do
					{
						//Inicio del juego
						system("cls");						
						printf("\t\t\t***AHORCADO v1.0***\n\n\t");
						for(i = 0; i < longi; i++)
							printf ("%c ",temp[i]);
							//Menu de Datos Ingresados	
						printf ("\n\n\tLETRAS ACERTADAS: %d",acer);
						printf("\n\tINTENTOS RESTANTES: %d",inten);
						printf("\n\tINGRESE UNA LETRA: ");
						if (acer==longi)
						{
							printf("\n\n\tHAZ GANADO\n");
							break;
						}
						fflush(stdin);	
						//Lectura de letra ingresada
						scanf("%c",&letra);	
						sw=0;	
						for( i=0; i< longi; i++)
							if(palabra[azar].palb[i]==letra)
							{
								if(temp[i]!=letra)
								{
									temp[i]=letra;
									acer++;
									sw=1;
								}								
							}
						if(sw==0)
						{//Perdida de extremidades
							fall++;
							inten--;
							if(fall==1)
								printf("\n\tHAZ PERDIDO EL BRAZO DERECHO\n");
							else if (fall==2)
								printf("\n\tHAZ PERDIDO EL BRAZO IZQUIERDO\n");
							else if (fall==3)
								printf("\n\tHAZ PERDIDO LA PIERNA IZQUIERDA\n");
							else if (fall==4)
								printf("\n\tHAZ PERDIDO LA PIERNA DERECHA\n");
							else if (fall==5)
							{
								printf("\n\tHAZ PERDIDO LA CABEZA\n");
								printf("\n\tFIN DEL JUEGO\n");
								break;
							}
							printf("\n\t");
							system("pause");									
						}
								
					}while(acer<=longi && fall <=longi);
					
					do
					{	//Validación de un nuevo juego
						sw=0;
						printf("\n\tDESEA JUGAR NUEVAMENTE S/N: ");
						fflush(stdin);
						scanf("%c",&op3);								
						if(op3!='s' && op3!='S' && op3!='n' && op3!='N')
						{
							printf("\n\tERROR, OPCION INVALIDA\n");
							sw=1;
						}										
					}while(sw==1);					
				}while(op3=='s' || op3=='S');	
				system("cls");
				break;			
			}
			
			default:{				
				break;
			}		
		}  
	}while(op!=3);	
}
