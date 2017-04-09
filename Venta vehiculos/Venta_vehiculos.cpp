#include<iostream>
#include<string.h>
using namespace std;
class Vehiculos{
	private:
		string color, marca, modelo, placa;
		int stock;
		float precio;
	public:
		void set_marca(string marc)
		{
			marca=marc;
		}
		string get_marca()
		{
			return marca;
		}
		void ingresar_datos_general()
		{
			cout << "\tModelo: "; cin >> modelo;
			cout << "\tPlaca: "; cin >> placa;
			cout << "\tColor: "; cin >> color;
			cout << "\tStock: "; cin >> stock;
			cout << "\tPrecio: "; cin >> precio;		
		}
		void imprimir_datos_general()
		{
			cout <<marca << "\t";
			cout <<modelo << "\t";
			cout <<placa << "\t";
			cout <<color << "\t";
			cout <<stock << "\t";
			cout <<precio << "\t";
		}
		void imprimir_marca()
		{
			cout <<marca << endl;
		}

		void imprimir_color_precio()
		{
			cout <<modelo << "\t";
			cout <<color << "\t";
			cout << stock << "\t";
			cout <<"$"<<precio << "\t";
		}	
		void set_stock(int n)
		{
			stock=n;
		}
		string get_modelo()
		{
			return modelo;
		}
		int get_stock()
		{
			return stock;
		}
		float get_precio()
		{
			return precio;
		}
		string get_placa()
		{
			return placa;
		}
		
};
class busetas:public Vehiculos
{
	private:
		int pasajeros;
	public:
		void set_pasajeros(int pasa)
		{
			pasajeros=pasa;
		}
		int get_pasajeros()
		{
			return pasajeros;
		}
		void imprimir_pasajeros()
		{
			cout << pasajeros << "\n";
		}	
};
class trailers:public Vehiculos
{
	private:
		int cap_carga;
	public:
		void set_capacidad(int carga)
		{
			cap_carga=carga;
		}
		int get_capacidad()
		{
			return cap_carga;
		}
		void imprimir_capacidad()
		{
			cout << cap_carga << endl;
		}	
};	
class  cliente{
	private:
		string nombre,apellido,id,direccion,email,telf;
	public:
		void ingreso_datos()
		{
			cout <<"\tNombre: ";
			cin>>nombre;
			cout <<"\tApellido: ";
			cin>>apellido;
			cout <<"\tDireccion: ";
			cin>>direccion;
			cout <<"\tEmail: ";
			cin>>email;
			cout <<"\tTelf: ";
			cin>>telf;
		}
		void imprimir_id()
		{
			cout << "\n\t"<< id <<"\t";
		}
		void set_id(string ci)
		{
			id=ci;
		}
		string get_id()
		{
			return id;
		}
		void imprimir_datos()
		{
			cout << "\t"<<nombre << "\t";
			cout <<apellido << "\t";
			cout <<id << "\t";
			cout <<direccion << "\t";
			cout <<email << "\t";
			cout <<telf ;
		}
		
};
class factura{
	private:
		string idfac;
		int num_fac,dia,mes,ano, canti;
		float total;
	public:
		void ingresar_fecha()
		{
				cout << "\tAno: ";
				cin >> ano;
				cout <<"\tMes: ";
				cin >> mes;
				cout <<"\tDia: ";
				cin >> dia;
		}
		void set_idfac(string ci)
		{
			idfac=ci;
		}
		string get_idfac()
		{
			return idfac;
		}

		int get_ano()
		{
			return ano;
		}
		
		void set_cantidad(int can)
		{
			canti=can;
		}
		int get_cantidad()
		{
			return canti;
		}
		void set_numfac(int nufa)
		{
			num_fac=nufa;
		}
		int get_numfac()
		{
			return num_fac;
		}
		void set_total(float tot)
		{
			total=tot;
		}
};

class detalle{
	private:
		string dplaca,dmarca;
		int num_fac;
	public:
		void set_placa(string plac)
		{
			dplaca=plac;
		}
		string get_placa()
		{
			return dplaca;
		}
		void set_marca(string marc)
		{
			dmarca=marc;
		}
		string get_dmarca()
		{
			return dmarca;
		}
		void set_numfac(int fac)
		{
			num_fac=fac;
		}
		int get_numfac()
		{
			return num_fac;
		}		
};
int valida_entre(int a, int b);
void buscar_cliente_marca(class detalle det[], class factura fac[],class cliente per[], string marc, int c_det, int c_fac, int c_cli);
void buscar_cliente_ano(class factura fac[], class cliente per[],int an, int c_cli, int c_det,int c_fac);
int valida_positivo(char men[40]);

int main()
{
	busetas bus[100]; trailers tra[100]; cliente per[100]; detalle det[100];factura fac[100];
	int op, i, can, j, can_t=0, can_b=0,can_c=0,c_det=0, num_f=1,x, aux, n,vec[100],vec2[100],carga,pasa,an;
	float venta=0;
	string marc, ci;
	do{		
		system("cls");
		cout << "\t\t\t***MENU PRINCIPAL***\n";
		cout << "\n\t1)Vender\n";
		cout << "\n\t2)Ingresar Vehiculos\n";
		cout << "\n\t3)Consultar\n";
		cout << "\n\t0)Salir\n";
		op=valida_entre(0,3);
		switch(op)
		{
			case 1:{
				can=valida_positivo("\n\tNumero de vehiculos a vender: ");				
				system("cls");
				aux=-1;
				cout << "\t\tDatos del cliente";
				cout <<"\n\tN.Factura: "<<num_f;
			 	fac[num_f-1].ingresar_fecha();			
				cout << "\n\tCi: ";cin>> ci;
				for(i=0; i <can_c; i++)
				{
					if(ci==per[i].get_id())
					{
						aux=i;
						i=can_c;
					}				
				}
				if(aux!=-1)
				{
					per[aux].imprimir_datos();
					fac[num_f-1].set_idfac(per[aux].get_id());
					cout << "\n\t";
					system("pause");
				}
				else
				{
					per[can_c].set_id(ci);
					per[can_c].ingreso_datos();
					fac[num_f-1].set_idfac(per[can_c].get_id());
					can_c++;	
				}	
				fac[num_f-1].set_cantidad(can);
				fac[num_f-1].set_numfac(num_f);
				num_f++;			
				for(i=0; i<can; i++)
				{	
					system("cls");
					cout << "Tipo: " << endl;
					cout << "1)Trailers\t";
					cout << "2)Busetas\n";
					op=valida_entre(1,2);
					switch(op)
					{
						case 2:{
							n=0;
							for(j=0; j < can_b; j++)
							{
								aux=0;
								for(x=0; x < j; x++ )
								{
									if(bus[j].get_marca()==bus[x].get_marca())
										aux=1;
								}
								if (aux==0)
								{
									n++;
									cout << n <<") " << bus[j].get_marca()<<endl;
									vec[n-1]=j;
								}								
							}
							op=valida_entre(1,n);
							n=0;
							for(x=0; x < can_b; x++)
							{
								if(bus[vec[op-1]].get_marca()==bus[x].get_marca())
								{
									n++;
									cout <<n<<") ";bus[x].imprimir_color_precio();
									bus[x].imprimir_pasajeros();
									vec2[n-1]=x;
								}
							}
							op=valida_entre(1,n);
							det[c_det].set_numfac(num_f-1);
							det[c_det].set_placa(bus[vec2[op-1]].get_placa());
							det[c_det].set_marca(bus[vec2[op-1]].get_marca());
							n=bus[vec2[op-1]].get_stock()-1;
							bus[vec2[op-1]].set_stock(n);
							c_det++;							
							venta+=bus[vec2[op-1]].get_precio();
							break;
						}
						case 1:{
							n=0;
							for(j=0; j < can_t; j++)
							{
								aux=0;
								for(x=0; x < j; x++ )
								{
									if(tra[j].get_marca()==tra[x].get_marca())
										aux=1;
								}
								if (aux==0)
								{
									n++;
									cout << n <<") " << tra[j].get_marca()<<endl;
									vec[n-1]=j;
								}								
							}
							op=valida_entre(1,n);
							n=0;
							for(x=0; x < can_t; x++)
							{
								if(tra[vec[op-1]].get_marca()==tra[x].get_marca())
								{
									n++;
									cout <<n<<") ";tra[x].imprimir_color_precio();
									tra[x].imprimir_capacidad();
									vec2[n-1]=x;
								}
							}
							op=valida_entre(1,n);
							det[c_det].set_numfac(num_f-1);
							det[c_det].set_placa(tra[vec2[op-1]].get_placa());
							det[c_det].set_marca(tra[vec2[op-1]].get_marca());
							n=tra[vec2[op-1]].get_stock()-1;
							tra[vec2[op-1]].set_stock(n);
							c_det++;						
							venta+=tra[vec2[op-1]].get_precio();
							break;
						}
					}
									
				}
				fac[num_f-2].set_total(venta);
				cout << "El total a pagar es de: $" <<venta<<endl;
				venta=0;
				system("pause");	
				break;
			}
			case 2:{
				can=valida_positivo("\n\tVehiculos a ingresar: ");
				for(i=0; i<can; i++)
				{
					system("cls");
					cout << "\n\tTipo: " << endl;
					cout << "\t1)Trailers\t";
					cout << "\t2)Busetas";
					op=valida_entre(1,2);
					cout << "\n\tMarca: ";
					cin >> marc;
					switch(op)
					{
						case 1:
						{
							tra[can_t].set_marca(marc);
							tra[can_t].ingresar_datos_general();
							cout << "\tCapacidad de carga: ";
							cin >> carga;
							tra[can_t].set_capacidad(carga);
							can_t++;
							break;
						}
						case 2:
						{
							bus[can_b].set_marca(marc);
							bus[can_b].ingresar_datos_general();
							cout << "\tPasajeros max: ";
							cin >> pasa;
							bus[can_b].set_pasajeros(pasa);
							can_b++;
							break;
						}
					}
					cout << "\n\tVehiculo ingresado exitosamete\n\t";
					system("pause");
				}
				break;
			}
			case 3:{
				system("cls");
				cout << "\n\t\t****Consulta****"<< endl;
				cout << "\n\t1)Clientes\n";
				cout << "\n\t2)Trailers\n";
				cout << "\n\t3)Busetas\n";
				cout << "\n\t4)Marca\n";
				cout << "\n\t5)Año\n";
				cout << "\n\t6)Regresar";
				op=valida_entre(1,6);
				system("cls");
				switch(op)
				{
					case 1:
					{
						cout << "\n\t\t****Clientes****"<< endl;
						cout << "\t1)General\t";
						cout << "\t2)ID\n";
						op=valida_entre(1,2);
						system("cls");
						switch(op)
						{
							case 1:
							{
								for(i=0; i < can_c; i++)
								{
									per[i].imprimir_id();
									per[i].imprimir_datos();
								}
								cout<< "\n\t";
								system("pause");
								break;
								
							}
							case 2:
							{
								cout << "Ingrese el CI del cliente a consultar: ";
								cin>> ci;
								for(i=0; i < can_c; i++)
								{
									if(ci==per[i].get_id())
										per[i].imprimir_datos();
								}
								cout<< "\n";
								system("pause");
								break;
							}
						}
						break;
					}
					case 2:
					{
						for(i=0; i < can_t; i++)
						{
							tra[i].imprimir_datos_general();
							tra[i].imprimir_capacidad();
						}
						system("pause");
						break;
					}
					case 3:
					{
						for(i=0; i < can_b; i++)
						{
							bus[i].imprimir_datos_general();
							bus[i].imprimir_pasajeros();
						}
						system("pause");
						break;
					}
					case 4:
					{
						cout << "\ntIngrese la marca del vehiculo a consultar: ";
						cin >> marc;
						buscar_cliente_marca(det,fac, per, marc, c_det, num_f, can_c);
						cout << "\n";
						system("pause");
						break;
					}
					case 5:
					{
						cout << "\n\tIngrese el año a consultar: ";
						cin >> an;
						buscar_cliente_ano(fac, per, an,  can_c, c_det, num_f);
						cout << "\n";
						system("pause");
						break;
					}
					case 6:{
						
						break;
					}
					
				}
				
				
			}
			case 4:{
				
				break;
			}
		}
	}while(op!=0);
}
void buscar_cliente_marca(class detalle det[], class factura fac[],class cliente per[], string marc, int c_det, int c_fac, int c_cli)
{
	int i, aux, x, sw=0,j;
	for (i=0; i < c_det; i++ )
	{
		if (det[i].get_dmarca()==marc)
		{
			for(x=0; x < c_fac; x++)
			{
				if (det[i].get_numfac()== fac[x].get_numfac())
				{
					for(j=0; j<c_cli; j++)
					{
						if(fac[x].get_idfac()==per[j].get_id())
						{
							per[x].imprimir_datos();
							sw=1;	
						}	
					}
					
				}				
			}				
		}
	}
	if (sw==0)
		cout << "No existen clientes que han comprado esta marca\n";	
}
void buscar_cliente_ano(class factura fac[], class cliente per[],int an, int c_cli, int c_det,int c_fac)
{
	int x,i,aux,sw=0;
	for(x=0; x < c_cli; x++)
	{
		aux=0;
		for (i=0; i < c_fac; i++)
		{
			if(fac[i].get_idfac()==per[x].get_id() && an==fac[i].get_ano())
			{
				aux+=fac[i].get_cantidad();
			}
		}	
		if (aux >1)	
		{
			per[x].imprimir_datos();
			sw=1;
		}
	}
	if (sw==0)
		cout << "No existen persona que haya comprado mas de un auto en el año\n";
}
int valida_entre(int a, int b)
{
	
	int op;
	do
	{		
		cout << "\n\n\t**Opcion a ejecutar: ";
		cin >> op;
		if(op<a || op >b)
			cout << "\n\tError, opcion invalida";	
	}while(op<a || op >b);
	return op;	
}

int valida_positivo(char men[40])
{
	int can;
	do
	{
		cout <<men;
		cin >> can;
		if(can <1)
			cout << "Error, cantidad invalida\n";		
	}while(can <1);
	return can;
}

