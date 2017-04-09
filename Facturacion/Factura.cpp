#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
#include<time.h>
#include<string.h>


int valida_entre(int a, int b);
long long int valida_positivo(char men[20]);
void facturar(long long int ci, struct Persona per, struct Factura fac, struct Carro car);
void imprimir_datos(struct Persona per, long long int ci);
int imprimir_datos_fac(struct Factura fac);
void fecha_fac(char fec[128]);
void ubicaxy(int x, int y);
void horizontal ();
void vertical();
void textos_carros();
void textos_persona();
void textos_vendedor();

struct Persona{
	long long int ci;
	char nombre[20], apellido[20], direccion[15], telefono[10];
};

struct Factura{
	int num_fac;
	long long int ci_cli, ci_ven;
	float total;
	char fecha[128];
};

struct Detalle{
	int num_fac, can, cod;
	float subtotal;	
};

struct Carro{
	int stock,cod,tip;
	char placa[10], marca[15], modelo[10], color[10], estado[10];
	float v_compra, v_venta;
};

void consulta_mas_vendido()
{
	
	
}

void consulta_marca_especifico()
{
	Persona per;Carro car; Detalle det; Factura fac;
	int tip;
	char marca[15];
	long long int ci;
	FILE *datos, *factura, *carros, *detalle;
	int aux=0;	
	printf("Ingrese la marca: ");
	scanf("%s",&marca);
	carros=fopen("datos_vehiculo.txt","r");
	while(feof(carros)==0)
	{
		fscanf(carros,"%d",&car.cod);
		fscanf(carros,"%d",&car.tip);
		fscanf(carros, "%s",&car.placa);
		fscanf(carros, "%s",&car.marca);
		fscanf(carros, "%s",&car.modelo);
		fscanf(carros, "%s",&car.color);
		fscanf(carros, "%s",&car.estado);
		fscanf(carros,"%d",&car.stock);
		fscanf(carros,"%f",&car.v_compra);
		fscanf(carros,"%f",&car.v_venta);
		if(strcmp(marca,car.marca)==0)
		{
			detalle=fopen("datos_detalle.txt","r");	
			while(feof(detalle)==0)
			{				
				fscanf(detalle,"%d",&det.num_fac);
				fscanf(detalle,"%d",&det.cod);
				fscanf(detalle,"%d",&det.can);
				fscanf(detalle,"%f",&det.subtotal);
				if (det.cod == car.cod)
				{
					factura=fopen("Datos_factura.txt","r");
					while(feof(factura)==0)
					{
						fscanf(factura,"%d",&fac.num_fac);	
						fscanf(factura,"%s",&fac.fecha);
						fscanf(factura,"%lli",&fac.ci_ven);
						fscanf(factura,"%lli",&fac.ci_cli);	
						fscanf(factura,"%f",&fac.total);
						if (fac.num_fac==det.num_fac)
						{
							datos=fopen("datos_personales.txt","r");
							while(feof(datos)==0)
							{
								fscanf(datos,"%lli",&per.ci);
								fscanf(datos,"%d",&tip);
								fscanf(datos, "%s",&per.apellido);
								fscanf(datos, "%s",&per.nombre);
								fscanf(datos, "%s",&per.direccion );
								fscanf(datos, "%s",&per.telefono);
								if (fac.ci_cli==per.ci)
								{
									printf("%lli\t",per.ci);
									printf("%s\t",per.nombre);
									printf("%s\t",per.apellido);
									printf("%s\n",per.direccion);
									per.ci=0;
								}
							}
							fclose(datos);
						}
						fac.num_fac=0;
					}
					fclose(factura);
				}
				det.cod=0;
			}
			fclose(detalle);
		}
		strcpy(car.marca,"");					
	}
	fclose(carros);
		
}
void consulta_todo_comprado()
{
	Persona per;Carro car; Detalle det; Factura fac;
	FILE *datos, *factura, *carros, *detalle;
	long long int ci;
	factura=fopen("Datos_factura.txt","r");
	printf("Ci: ");scanf("%lli",&ci);
	while(feof(factura)==0)
	{
		fscanf(factura,"%d",&fac.num_fac);	
		fscanf(factura,"%s",&fac.fecha);
		fscanf(factura,"%lli",&fac.ci_ven);
		fscanf(factura,"%lli",&fac.ci_cli);	
		fscanf(factura,"%f",&fac.total);
		if (ci==fac.ci_cli)
		{
			detalle=fopen("datos_detalle.txt","r");	
			while(feof(detalle)==0)
			{
				
				fscanf(detalle,"%d",&det.num_fac);
				fscanf(detalle,"%d",&det.cod);
				fscanf(detalle,"%d",&det.can);
				fscanf(detalle,"%f",&det.subtotal);
				if (det.num_fac == fac.num_fac)
				{
					carros=fopen("datos_vehiculo.txt","r");
					while(feof(carros)==0)
					{
						fscanf(carros,"%d",&car.cod);
						fscanf(carros,"%d",&car.tip);
						fscanf(carros, "%s",&car.placa);
						fscanf(carros, "%s",&car.marca);
						fscanf(carros, "%s",&car.modelo);
						fscanf(carros, "%s",&car.color);
						fscanf(carros, "%s",&car.estado);
						fscanf(carros,"%d",&car.stock);
						fscanf(carros,"%f",&car.v_compra);
						fscanf(carros,"%f",&car.v_venta);
						if(det.cod==car.cod)
						{
							printf("%d\t",car.cod);
							printf("%s\t",car.marca);
							printf("%s\t",car.modelo);
							printf("%f\t\n",car.v_venta);
							car.cod=0;
						}
					}
					fclose(carros);
				}
				det.num_fac=0;
			}
			fclose(detalle);
		}
		fac.ci_cli=0;
	}
	fclose(factura);			
}
void consulta_examen()
{
	
	Persona per;Carro car; Detalle det; Factura fac;
	int tip, can;
	long long int ci;
	FILE *datos, *factura, *carros, *detalle;
	int aux=0;	
	detalle=fopen("datos_detalle.txt","r");
	can=valida_positivo("Cantidad:");	
	while(feof(detalle)==0)
	{
		
		fscanf(detalle,"%d",&det.num_fac);
		fscanf(detalle,"%d",&det.cod);
		fscanf(detalle,"%d",&det.can);
		fscanf(detalle,"%f",&det.subtotal);
		if (det.can >= can)
		{
			factura=fopen("Datos_factura.txt","r");
			while(feof(factura)==0)
			{
				fscanf(factura,"%d",&fac.num_fac);	
				fscanf(factura,"%s",&fac.fecha);
				fscanf(factura,"%lli",&fac.ci_ven);
				fscanf(factura,"%lli",&fac.ci_cli);	
				fscanf(factura,"%f",&fac.total);
				if (fac.num_fac==det.num_fac)
				{
					datos=fopen("datos_personales.txt","r");
					while(feof(datos)==0)
					{
						fscanf(datos,"%lli",&per.ci);
						fscanf(datos,"%d",&tip);
						fscanf(datos, "%s",&per.apellido);
						fscanf(datos, "%s",&per.nombre);
						fscanf(datos, "%s",&per.direccion );
						fscanf(datos, "%s",&per.telefono);
						if (fac.ci_cli==per.ci)
						{
							printf("%d\t",det.cod);
							printf("%d\t",det.can);
							printf("%s %s\n",per.nombre,per.apellido);
							per.ci=0;	
						}				
					}
					fclose(datos);
				}
				fac.num_fac=0;
			}
			fclose(factura);
		}
		det.can=0;
	}
	fclose(detalle);
}
void modificar_personas(long long int cod)
{
	Persona per;
	int aux=0,op;
	FILE *datos,*temp;
	datos=fopen("datos_personales.txt","r");
	temp=fopen("temp.txt","a");
	while(!feof(datos))
	{
		fscanf(datos,"%lli",&per.ci);
		fscanf(datos,"%d",&op);
		fscanf(datos, "%s",&per.apellido);
		fscanf(datos, "%s",&per.nombre);
		fscanf(datos, "%s",&per.direccion );
		fscanf(datos, "%s",&per.telefono);
		if(cod!=per.ci )
		{		
			fprintf(temp,"%lli\t",per.ci);
			fprintf(temp,"%d\t",op);
			fprintf(temp, "%s\t",per.apellido);
			fprintf(temp, "%s\t",per.nombre);
			fprintf(temp, "%s\t",per.direccion );
			fprintf(temp, "%s\n",per.telefono);
			per.ci=cod;			
		}
		else
		{
			aux++;
			if (aux==2)
			{
				textos_vendedor();
				fprintf(temp, "%lli\t",cod);
				fprintf(temp, "%d\t",op);
				ubicaxy(12,4);printf("%lli",cod);				
				fflush(stdin);
				ubicaxy(15,6);gets(per.apellido);fprintf(temp, "%s\t",per.apellido);
				ubicaxy(23,6);gets(per.nombre);fprintf(temp, "%s\t",per.nombre);
				ubicaxy(47,4);gets(per.direccion);fprintf(temp, "%s\t",per.direccion );
				ubicaxy(45,6);gets(per.telefono);fprintf(temp, "%s\n",per.telefono );
			}
			
		}
			
	}
	if(aux==1 || aux==0)
		printf("\n\tNo encontrando\n\t");
	else 
		printf("\n\tRegistro modificado\n\t");		
	system("pause");
	fclose(datos);
	fclose(temp);
	remove("datos_personales.txt");
	rename("temp.txt","datos_personales.txt");
}
void modificar_vehiculos(int cod)
{
	Carro car;
	int aux=0;
	FILE *carros,*temp;
	carros=fopen("datos_vehiculo.txt","r");
	temp=fopen("temp.txt","a");
	while(feof(carros)==0)
	{
		fscanf(carros,"%d",&car.cod);
		fscanf(carros,"%d",&car.tip);
		fscanf(carros, "%s",&car.placa);
		fscanf(carros, "%s",&car.marca);
		fscanf(carros, "%s",&car.modelo);
		fscanf(carros, "%s",&car.color);
		fscanf(carros, "%s",&car.estado);
		fscanf(carros,"%d",&car.stock);
		fscanf(carros,"%f",&car.v_compra);
		fscanf(carros,"%f",&car.v_venta);
		if(cod!=car.cod)
		{
			fprintf(temp,"%d\t",car.cod);
			fprintf(temp,"%d\t",car.tip);
			fprintf(temp,"%s\t",car.placa);
			fprintf(temp,"%s\t",car.marca);
			fprintf(temp,"%s\t",car.modelo);
			fprintf(temp,"%s\t",car.color);
			fprintf(temp,"%s\t",car.estado);
			fprintf(temp,"%d\t",car.stock);
			fprintf(temp,"%f\t",car.v_compra);
			fprintf(temp,"%f\n",car.v_venta);
			car.cod=cod;
		}
		else
		{
			aux++;
			if (aux==2)
			{
				textos_carros();
				fprintf(temp, "%d\t",cod);
				ubicaxy(6,12);printf("%d",cod);
				ubicaxy(20,12);scanf("%d",&car.tip);fprintf(temp, "%d\t",car.tip);
				fflush(stdin);
				ubicaxy(30,12);gets(car.placa);fprintf(temp, "%s\t",car.placa);
				ubicaxy(40,12);gets(car.marca);fprintf(temp, "%s\t",car.marca);
				ubicaxy(50,12);gets(car.modelo);fprintf(temp, "%s\t",car.modelo);
				ubicaxy(6,15);gets(car.color);fprintf(temp, "%s\t",car.color);
				ubicaxy(20,15);gets(car.estado);fprintf(temp, "%s\t",car.estado);
				ubicaxy(30,15);scanf("%d",&car.stock);fprintf(temp,"%d\t",car.stock);
				ubicaxy(40,15);scanf("%f",&car.v_compra);fprintf(temp,"%f\t",car.v_compra);
				ubicaxy(50,15);scanf("%f",&car.v_venta);fprintf(temp,"%f\n",car.v_venta);	
			}
			
		}
			
	}
	if(aux==1 || aux==0)
		printf("\n\tNo encontrando\n\t");
	else 
		printf("\n\tRegistro modificado\n\t");		
	system("pause");
	fclose(carros);
	fclose(temp);
	remove("datos_vehiculo.txt");
	rename("temp.txt","datos_vehiculo.txt");
}		
void eliminar_vehiculos(int cod)
{
	Carro car;
	int aux=0;
	FILE *carros,*temp;
	carros=fopen("datos_vehiculo.txt","r");
	temp=fopen("temp.txt","a");
	while(feof(carros)==0)
	{
		fscanf(carros,"%d",&car.cod);
		fscanf(carros,"%d",&car.tip);
		fscanf(carros, "%s",&car.placa);
		fscanf(carros, "%s",&car.marca);
		fscanf(carros, "%s",&car.modelo);
		fscanf(carros, "%s",&car.color);
		fscanf(carros, "%s",&car.estado);
		fscanf(carros,"%d",&car.stock);
		fscanf(carros,"%f",&car.v_compra);
		fscanf(carros,"%f",&car.v_venta);
		if(cod!=car.cod)
		{
			fprintf(temp,"%d\t",car.cod);
			fprintf(temp,"%d\t",car.tip);
			fprintf(temp,"%s\t",car.placa);
			fprintf(temp,"%s\t",car.marca);
			fprintf(temp,"%s\t",car.modelo);
			fprintf(temp,"%s\t",car.color);
			fprintf(temp,"%s\t",car.estado);
			fprintf(temp,"%d\t",car.stock);
			fprintf(temp,"%f\t",car.v_compra);
			fprintf(temp,"%f\n",car.v_venta);
			car.cod=cod;
		}
		else
			aux++;
	}
	if(aux==1 || aux==0)
		printf("\n\tNo encontrando\n\t");
	else 
		printf("\n\tRegistro eliminado\n\t");		
	system("pause");
	fclose(carros);
	fclose(temp);
	remove("datos_vehiculo.txt");
	rename("temp.txt","datos_vehiculo.txt");
}
void eliminar_persons(long long int cod)
{
	Persona per;
	int aux=0,op;
	FILE *datos,*temp;
	datos=fopen("datos_personales.txt","r");
	temp=fopen("temp.txt","a");
	while(!feof(datos))
	{
		fscanf(datos,"%lli",&per.ci);
		fscanf(datos,"%d",&op);
		fscanf(datos, "%s",&per.apellido);
		fscanf(datos, "%s",&per.nombre);
		fscanf(datos, "%s",&per.direccion );
		fscanf(datos, "%s",&per.telefono);
		if(cod!=per.ci )
		{		
			fprintf(temp,"%lli\t",per.ci);
			fprintf(temp,"%d\t",op);
			fprintf(temp, "%s\t",per.apellido);
			fprintf(temp, "%s\t",per.nombre);
			fprintf(temp, "%s\t",per.direccion );
			fprintf(temp, "%s\n",per.telefono);
			per.ci=cod;			
		}
		else
			aux++;
	}
	if(aux==1 || aux==0)
		printf("\n\tNo encontrando\n\t");
	else 
		printf("\n\tRegistro eliminado\n\t");		
	system("pause");
	fclose(datos);
	fclose(temp);
	remove("datos_personales.txt");
	rename("temp.txt","datos_personales.txt");
}		
void imprimir_personas(int men, long long int cod)
{
	Persona per;
	int aux=0,op;
	FILE *datos;
	datos=fopen("datos_personales.txt","r");
	while(feof(datos)==aux)
	{
		
		fscanf(datos,"%lli",&per.ci);
		fscanf(datos,"%d",&op);
		fscanf(datos, "%s",&per.apellido);
		fscanf(datos, "%s",&per.nombre);
		fscanf(datos, "%s",&per.direccion );
		fscanf(datos, "%s",&per.telefono);
		if(men==1 && cod==per.ci)
		{
			men=0;
			aux=1;
		}
		if(men==0 && per.ci!=0)
		{
			printf("\t%lli\t",per.ci);
			printf( "%s\t",per.nombre);
			printf("%s\t",per.apellido);
			printf( "%s\t",per.direccion );
			printf( "%s\n",per.telefono );
		}
		per.ci=cod;
		
	}
	if(aux==0 && men==1)
		printf("\n\tNo existe");
	fclose(datos);
	
}					
void imprimir_vehiculos(int men, int cod)
{
	
	Carro car;
	int aux=0;
	FILE *carros;
	carros=fopen("datos_vehiculo.txt","r");
	while(feof(carros)==aux)
	{
		
		fscanf(carros,"%d",&car.cod);
		fscanf(carros,"%d",&car.tip);
		fscanf(carros, "%s",&car.placa);
		fscanf(carros, "%s",&car.marca);
		fscanf(carros, "%s",&car.modelo);
		fscanf(carros, "%s",&car.color);
		fscanf(carros, "%s",&car.estado);
		fscanf(carros,"%d",&car.stock);
		fscanf(carros,"%f",&car.v_compra);
		fscanf(carros,"%f",&car.v_venta);
		if(men==1 && cod==car.cod)
		{
			men=0;
			aux=1;
		}
		if(men==0 && car.cod!=0)
		{
			printf("\t%d\t",car.cod);
			printf("%d\t",car.tip);
			printf("%s\t",car.placa);
			printf("%s\t",car.marca);
			printf("%s\t",car.modelo);
			printf("%s\t",car.color);
			printf( "%s\t",car.estado);
			printf("%d\t",car.stock);
			printf("%f\t",car.v_compra);
			printf("%f\n",car.v_venta);	
		}	
		car.cod=cod;		
	}
	if(aux==0 && men==1)
		printf("\n\tNo existe");
	fclose(carros);
	
}


float calcular_totalfac(struct Factura fac, struct Detalle det, int fact)
{
	FILE *detalle;
	float suma=0, total,iva;
	detalle=fopen("datos_detalle.txt","r");
	while(feof(detalle)==0)
	{
		fscanf(detalle,"%d",&det.num_fac);
		fscanf(detalle,"%d",&det.cod);
		fscanf(detalle,"%d",&det.can);
		fscanf(detalle,"%f",&det.subtotal);
		if(det.num_fac==fact)
		{
			suma+=det.subtotal;
		}
	}
	suma-=det.subtotal;
	ubicaxy(64,21);printf("%.2f",suma);
	iva=suma*0.14;ubicaxy(64,23);printf("%.2f",iva);
	total=suma+iva;ubicaxy(64,26);printf("%.2f",total);
	return total;
}
void ingresar_datos(struct Persona per, long long int ci, int tp)
{
	FILE *datos;
	datos=fopen("datos_personales.txt","a");
	textos_vendedor();
	ubicaxy(10,4);fprintf(datos, "%lli\t",ci);
	fprintf(datos, "%d\t",tp);
	fflush(stdin);
	ubicaxy(15,6);gets(per.apellido);fprintf(datos, "%s\t",per.apellido);
	ubicaxy(23,6);gets(per.nombre);fprintf(datos, "%s\t",per.nombre);
	ubicaxy(47,4);gets(per.direccion);fprintf(datos, "%s\t",per.direccion );
	ubicaxy(45,6);gets(per.telefono);fprintf(datos, "%s\n",per.telefono );
	fclose(datos);
	
}


void ingresar_datos_vehiculo(struct Carro car, int cod )
{
	FILE *carros;
	carros=fopen("datos_vehiculo.txt","a+");	
	textos_carros();
	fprintf(carros, "%d\t",cod);
	ubicaxy(20,12);scanf("%d",&car.tip);fprintf(carros, "%d\t",car.tip);
	fflush(stdin);
	ubicaxy(30,12);gets(car.placa);fprintf(carros, "%s\t",car.placa);
	ubicaxy(40,12);gets(car.marca);fprintf(carros, "%s\t",car.marca);
	ubicaxy(50,12);gets(car.modelo);fprintf(carros, "%s\t",car.modelo);
	ubicaxy(6,15);gets(car.color);fprintf(carros, "%s\t",car.color);
	ubicaxy(20,15);gets(car.estado);fprintf(carros, "%s\t",car.estado);
	ubicaxy(30,15);scanf("%d",&car.stock);fprintf(carros,"%d\t",car.stock);
	ubicaxy(40,15);scanf("%f",&car.v_compra);fprintf(carros,"%f\t",car.v_compra);
	ubicaxy(50,15);scanf("%f",&car.v_venta);fprintf(carros,"%f\n",car.v_venta);	
	fclose(carros);
	
}

int buscar_datos_carros(struct Carro car, int cod, int men, int x, int fac)
{
	FILE *carros, *detalle;
	int aux=0, codd, can;
	float venta;
	carros=fopen("datos_vehiculo.txt","a+");		
	while(feof(carros)==aux)
	{
		fscanf(carros,"%d",&codd);
		fscanf(carros,"%d",&car.tip);
		fscanf(carros, "%s",&car.placa);
		fscanf(carros, "%s",&car.marca);
		fscanf(carros, "%s",&car.modelo);
		fscanf(carros, "%s",&car.color);
		fscanf(carros, "%s",&car.estado);
		fscanf(carros,"%d",&car.stock);
		fscanf(carros,"%f",&car.v_compra);
		fscanf(carros,"%f",&car.v_venta);				
		if(cod==codd && men==1)
		{
			detalle=fopen("datos_detalle.txt","a+");
			fprintf(detalle,"%d\t",fac);
			ubicaxy(6,x);printf("%d",cod);fprintf(detalle,"%d\t",cod);
			ubicaxy(20,x);printf("%s ",car.marca);printf("%s",car.modelo);
			ubicaxy(50,x);printf("%.2f",car.v_venta);
			ubicaxy(38,x);scanf("%d",&can);fprintf(detalle,"%d\t",can);
			venta=can*car.v_venta;ubicaxy(64,x);printf("%.2f",venta);fprintf(detalle,"%f\n",venta);
			fclose(detalle);
			aux=2;
					
		}
		else if(codd==cod && men==0)
			aux=1;
	}
	if (aux==1)
	{
		ubicaxy(6,22);printf("Error, el codigo ya existe");
	}
						
	fclose(carros);
	return aux;
}


int leer_datos_vehiculo(struct Carro car,int can, int men, int fac)
{
	
	int i, aux,tpp,x=13;
	int cod;	
	for(i=0; i < can; i++)
	{
		do
		{
			ubicaxy(6,11);printf("Codigo: ");
			
			if (men==0)
			{
				
				ubicaxy(6,12);scanf("%d",&car.cod);
			}				
			else
			{
				ubicaxy(6,x);scanf("%d",&car.cod);
			}				
			
			if (car.cod==0)
			{
				i=4;
				break;
			}	
			aux=buscar_datos_carros( car, car.cod, men, x,fac);
						
		}while(aux==1 || (men==1 && aux==0));	
		if (aux==0 && men==0)
			ingresar_datos_vehiculo(car,car.cod);
		x+=2;	
	}		
	return can;
}



long long int leer_datos_persona(struct Persona per,int can, int tp)
{
	FILE *datos;
	int i, aux,tpp;
	long long int ci;	
	for(i=0; i < can; i++)
	{
		do
		{
			aux=0;		
			datos=fopen("datos_personales.txt","a+");		
			per.ci=valida_positivo("Cedula");
			while(feof(datos)==aux)
			{
				fscanf(datos,"%lli",&ci);
				fscanf(datos,"%d",&tpp);
				fscanf(datos, "%s",&per.apellido);
				fscanf(datos, "%s",&per.nombre);
				fscanf(datos, "%s",&per.direccion );
				fscanf(datos, "%s",&per.telefono);
				if(ci==per.ci && tp==1)
				{
					imprimir_datos(per,ci);
					aux=3;
				}
				else if(ci==per.ci && tp==0)
					aux=1;						
			}
			if (aux==1)
				printf("\n\tError, el Ci ya existe");				
			fclose(datos);
		}while(aux==1);	
		if (aux==0)
			ingresar_datos(per, per.ci, tp);	
	}	
	fclose(datos);	
	return per.ci;
}



int validar_vendedor(int tp, long long int *ci)
{
	Persona per;
	int aux=0,tpp;
	char ced[20]="Cedula";
	long long int ven,cii;
	FILE *datos;
	datos=fopen("datos_personales.txt","rt");	
		*ci=valida_positivo(ced);
		rewind(datos);
		while(feof(datos)==aux)
		{
			fscanf(datos,"%lli",&ven);
			fscanf(datos,"%d",&tpp);
			fscanf(datos, "%s",&per.apellido);
			fscanf(datos, "%s",&per.nombre);
			fscanf(datos, "%s",&per.direccion );
			fscanf(datos, "%s",&per.telefono);
			if(tpp==0 && *ci==ven )
				aux=1;		
		}
		if (aux==1 && tpp==0)
			printf("\n\tBienvenido %s, validacion correcta\n\t",per.nombre);
		else if(tpp!=0)
			printf("\n\tError, si no esta registado, acceda al apartado de administrar\n\t");
				
	system("pause");
	fclose(datos);
	return aux;
}

int valida_entre(int a, int b)
{
	int op;
	do
	{		
		printf("\n\t**Opcion a ejecutar: ");
		scanf("%d",&op);
		if(op<a || op >b)
			printf("\n\tError, opcion invalida");	
	}while(op<a || op >b);
	return op;	
}

long long int valida_positivo(char men[20])
{
	long long int can;
	do
	{
		ubicaxy(4,4);printf("%s:",men);
		scanf("%lli", &can);
		
	}while(can <1);
	return can;
}

main()
{
	Persona cli,ven; Factura fac; Carro car;
	int op, can, np=0, nv=0, tip;
	do{		
			system("cls");
			printf("\t\t\t***MENU PRINCIPAL***\n");
			printf("\n\t1)Administrar\n");
			printf("\n\t2)Facturar\n");
			printf("\n\t3)Salir\n");
			op=valida_entre(1,3);
			switch(op)
			{
				case 1:{
					do{
					//Menu de administrador
					system("cls");
					printf("\t\t\t***ADMINNISTRADOR***\n");
					printf("\n\t1)Ingresar\n");
					printf("\n\t2)Consultar\n");
					printf("\n\t3)Modificar\n");
					printf("\n\t4)Regresar\n");
					op=valida_entre(1,4);
					switch(op){
						case 1:{
							do
							{
								system("cls");
								printf("\t\t\t***INGRESAR***\n");
								printf("\n\t1)Registrar vendedor\n");
								printf("\n\t2)Vehiculos\n");
								printf("\n\t3)Regresar\n");
								op=valida_entre(1,3);
								switch(op)
								{
									case 1:{
										tip=0;
										system("cls");
										printf("\t\t\t***VENDEDOR***");
										printf("\n\n\tCuantos personas ingresara: ");scanf("%d",&can);
										nv=leer_datos_persona(ven, can, tip);
										break;
									}
									case 2:{
										system("cls");
										printf("\t\t\t***VEHICULOS***\n");
										can=valida_positivo("Cantidad de vehiculos:");
										leer_datos_vehiculo(car,can,0,0);								
										break;
									}	
									case 3:{										
										break;
									}
								}	
							}while(op!=3);
							break;
						}
						case 2:{
							do
							{
							system("cls");
							printf("\t\t\t***CONSULTAS***\n");
							printf("\n\t1)Autos\n");
							printf("\n\t2)Personas\n");
							printf("\n\t3)Consultas Especificas\n");
							printf("\n\t4)Regresar\n");
							op=valida_entre(1,4);
								switch(op){
									case 1: {
										system("cls");
										printf("\t\t\t***AUTOS***\n");
										printf("\n\t1)General\n");
										printf("\n\t2)Por Codigo\n");
										printf("\n\t3)Regresar\n");
										op=valida_entre(1,3);
										switch(op){
											case 1:{
												system("cls");
												imprimir_vehiculos(0, 0);
												break;
											}
											case 2:{
												system("cls");
												int cod;
												printf("\n\tIngrese el codigo: ");
												scanf("%d",&cod);
												imprimir_vehiculos(1, cod);
												break;
											}
										}	
										printf("\n\t");
										system("pause");										
										break;
										}
									case 2: {
										system("cls");
										printf("\t\t\t***PERSONAS***\n");
										printf("\n\t1)General\n");
										printf("\n\t2)Por Ci\n");
										printf("\n\t3)Regresar\n");
										op=valida_entre(1,3);
										switch(op){
											case 1:{
												system("cls");
												imprimir_personas(0, 0);
												break;
											}
											case 2:{
												system("cls");
												long long int cod;
												printf("\n\tIngrese el Ci: ");
												scanf("%d",&cod);
												imprimir_personas(1, cod);
												break;
											}
										}
										printf("\n\t");
										system("pause");									
										break;
									}
									case 3: {
										system("cls");
										printf("\t\t\t***ESPECIFICAS***\n");
										printf("\n\t1)Del examen\n");
										printf("\n\t2)Todos los vehiculos adquirido por un usuario\n");
										printf("\n\t3)Vehiculo mas vendido\n");
										printf("\n\t4)Todos los usuarios que adquirieron una marca en espefico\n");
										printf("\n\t5)Regresar\n");
										op=valida_entre(1,5);
										switch(op){
											case 1:{
												system("cls");		
												consulta_examen();
												system("pause");
												break;
											}
											case 2:{
												system("cls");
												consulta_todo_comprado();
												system("pause");
												break;
											}
											case 4:{
												system("cls");
												consulta_marca_especifico();
												system("pause");
												break;
											}
											
										}
										
										
									
								
									}
							}
							}while(op!=4);					
							break;							
						}
						case 3:{
							do
							{
							system("cls");
							printf("\t\t\t***MODIDICAR***\n");
							printf("\n\t1)Eliminar\n");
							printf("\n\t2)Actualizar\n");
							printf("\n\t3)Regresar\n");
							op=valida_entre(1,3);
							switch(op){
								case 1: {
									system("cls");
									printf("\t\t\t***ELIMINAR***\n");
									printf("\n\t1)Personas\n");
									printf("\n\t2)Autos\n");
									printf("\n\t3)Regresar\n");
									op=valida_entre(1,3);			
									switch(op){
										case 1:{
											system("cls");
											long long int cod;
											printf("\t\t\t***ELIMINAR PERSONAS***\n");
											printf("\n\tIngrese el Ci: ");
											scanf("%d",&cod);
											eliminar_persons(cod);
											break;
										}
										case 2:{
											system("cls");
											long long int cod;
											printf("\t\t\t***ELIMINAR VEHICULOS***\n");
											printf("\n\tIngrese el codigo: ");
											scanf("%d",&cod);
											eliminar_vehiculos(cod);
											break;
										}
									}
									break;
									}
								case 2: {
									system("cls");
									printf("\t\t\t***ACTUALIZAR***\n");
									printf("\n\t1)Personas\n");
									printf("\n\t2)Autos\n");
									printf("\n\t3)Regresar\n");
									op=valida_entre(1,3);	
									switch(op){
										case 1:{
											system("cls");
											long long int cod;
											printf("\t\t\t***ACTUALIZAR PERSONAS***\n");
											printf("\n\tIngrese el Ci: ");
											scanf("%d",&cod);
											modificar_personas(cod);
											break;
										}
										case 2:{
											system("cls");
											long long int cod;
											printf("\t\t\t***ACTUALIZAR VEHICULOS***\n");
											printf("\n\tIngrese el codigo: ");
											scanf("%d",&cod);
											modificar_vehiculos(cod);
											break;
										}
									}
									
									break;
									}
									
								}
							
							}while(op!=3);
							break;
						}
						case 4:{
							break;
						}
					}
								
					}while(op!=4);
					break;
				}
				case 2:{
						int n,  x=0;
						long long int *ptr, cii;
						ptr=&cii;
						do
						{
							system("cls");
							printf("\t\t\t***FACTURACION***\n");
							printf("\n\tIdentificacion del vendedor");						
							n=validar_vendedor(0,ptr);
							if (n!=1)
								x++;	
						}while(n!=1 && x <3);
						if (n==1)
						{
							
							facturar(cii,cli,fac,car);
							ubicaxy(2,32);system("pause");	
						}
												
									
					break;
				}
			
			}
	}while(op!=3);
	
}

void imprimir_datos(struct Persona per, long long int ci)
{
	FILE *datos;
	int aux,op;
		aux=0;		
		datos=fopen("datos_personales.txt","r");		
		while(feof(datos)==aux)
		{
			fscanf(datos,"%lli",&ci);
			fscanf(datos,"%d",&op);
			fscanf(datos, "%s",&per.apellido);
			fscanf(datos, "%s",&per.nombre);
			fscanf(datos, "%s",&per.direccion );
			fscanf(datos, "%s",&per.telefono);
			if(ci==per.ci)
				aux=1;					
		}
		if (aux==1)
		{
			//!feof(pe);
			ubicaxy(15,6);printf( "%s ",per.nombre);printf("%s",per.apellido);
		
			ubicaxy(47,4);printf( "%s",per.direccion );
						
			ubicaxy(45,6);printf( "%s",per.telefono );
					
		}		
		fclose(datos);
}

int imprimir_datos_fac(struct Factura fac)
{
	FILE *factura;
	factura=fopen("Datos_factura.txt","r");
	while(feof(factura)==0)
	{
		fscanf(factura,"%d",&fac.num_fac);
		fscanf(factura,"%s",&fac.fecha);
		fscanf(factura,"%lii",&fac.ci_ven);
		fscanf(factura,"%lii",&fac.ci_cli);		
	}
	fclose(factura);
	return fac.num_fac;
}

void facturar(long long int ci, struct Persona per, struct Factura fac, struct Carro car )
{
	FILE *factura;
	Detalle det;
	long long int cii;
	factura=fopen("Datos_factura.txt","a");
	system("cls");
	textos_persona();
	horizontal();
	vertical();		
	ubicaxy(15,2);printf("%lli",ci);
	fac.num_fac= imprimir_datos_fac(fac)+1;fprintf(factura,"%d\t",fac.num_fac);	
	ubicaxy(48,2);printf("%d",fac.num_fac);
	fecha_fac(fac.fecha);fprintf(factura,"%s\t",fac.fecha);
	fac.ci_ven=ci;fprintf(factura,"%lli\t",fac.ci_ven);
	cii=leer_datos_persona(per,1, 1);	
	fac.ci_cli=cii;fprintf(factura,"%lli\t",fac.ci_cli);	
	leer_datos_vehiculo(car,4,1,fac.num_fac);
	fac.total= calcular_totalfac(fac, det,fac.num_fac);fprintf(factura,"%f\n",fac.total);	
	fclose(factura);
	
}

void textos_vendedor()
{
	ubicaxy(4,4);printf("Cedula: ");
	ubicaxy(4,6);printf("Cliente: ");	
	ubicaxy(36,4);printf("Direccion: ");
	ubicaxy(36,6);printf("Telefono: ");	
	
}

void ubicaxy(int x, int y)
{

	HANDLE pantalla; 
	COORD posicion; 
	pantalla = GetStdHandle (STD_OUTPUT_HANDLE); 

	posicion.X = x; posicion.Y = y; 
	SetConsoleCursorPosition (pantalla,posicion); 

}	

	
	
void horizontal ()
{
	int tamfil=77,cont,i;
	
	
	for(i=1;i<8;i+=2)
	{
		for(cont=2;cont<tamfil; cont++)
		{
			ubicaxy(cont,i); printf("_");
		}	
	}
	
	
	for(i=10;i<22;i+=2)
	{
		for(cont=4;cont < tamfil-3; cont++)
		{
			ubicaxy(cont,i); printf("_");
		}	
	}
	
	for(i=20;i<25;i+=2)
	{
		for(cont=46;cont < tamfil-3; cont++)
		{
			ubicaxy(cont,i); printf("_");
		}	
	}
	
	for(cont=4;cont < tamfil-3; cont++)
		{
			ubicaxy(cont,27); printf("_");
		}	
		
	for(i=1;i<30;i+=28)
	{
		for(cont=2;cont < tamfil; cont++)
		{
			ubicaxy(cont,i); printf("_");
		}
		
	}
}
void vertical()
{
	int tamcol=30,cont,i;
	
	
	for(i=4; i<74 ; i+=69)
	{
		for(cont=11;cont<28;cont++)
		{
			ubicaxy(i,cont);printf("|");
		}	
	}
	
	for(cont=11;cont<21;cont++)
	{
		ubicaxy(35,cont);printf("|");
	}	
		
	for(cont=11;cont<21;cont++)
	{
		ubicaxy(13,cont);printf("|");
	}
	
	for(cont=11;cont<28;cont++)
		{
			ubicaxy(60,cont);printf("|");
		}	
	for(cont=11;cont<28;cont++)
		{
			ubicaxy(45,cont);printf("|");
		}	
	for(cont=2;cont<8;cont++)
	{
		ubicaxy(34,cont);printf("|");
	}	
	for(cont=6;cont<8;cont++)
	{
		ubicaxy(55,cont);printf("|");
	}
	
	for(i=2; i<77 ; i+=74)
	{
		for(cont=2;cont<tamcol;cont++)
		{
			ubicaxy(i,cont);printf("|");
		}	
	}
}	

void textos_persona()
{
	
	ubicaxy(30,28);printf("EMPRESA PAPIS S.A");
	
	ubicaxy(4,2);printf("Vendedor: ");
	ubicaxy(4,4);printf("Cedula: ");
	ubicaxy(4,6);printf("Cliente: ");
	
	ubicaxy(36,2);printf("Factura No: ");
	ubicaxy(36,4);printf("Direccion: ");
	ubicaxy(36,6);printf("Telefono: ");
	ubicaxy(57,6);printf("Fecha: ");
	
	ubicaxy(6,11);printf("Codigo");
	ubicaxy(20,11);printf("Detalle");
	ubicaxy(38,11);printf("Cantidad");
	ubicaxy(50,11);printf("Precio");
	ubicaxy(64,11);printf("V.Total");
	
	ubicaxy(50,21);printf("Subtotal");
	ubicaxy(50,23);printf("Iva");
	ubicaxy(50,26);printf("TOTAL");
	
	
	ubicaxy(24,26);printf("Firma");
}

void textos_carros()
{
	ubicaxy(6,11);printf("Codigo: ");
	ubicaxy(20,11);printf("Tipo: ");
	ubicaxy(30,11);printf("Placa: ");
	ubicaxy(40,11);printf("Marca: ");
	ubicaxy(50,11);printf("Modelo: ");
	ubicaxy(6,14);printf("Color: ");
	ubicaxy(20,14);printf("Estado: ");
	ubicaxy(30,14);printf("Stock: ");
	ubicaxy(40,14);printf("V.Compra: ");
	ubicaxy(50,14);printf("V.Venta: ");	
}
void fecha_fac(char fec[128])
{
	time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
	strftime(fec, 128, "%d/%m/%y", tlocal);
    ubicaxy(65,6);printf("%s",fec); 
}
