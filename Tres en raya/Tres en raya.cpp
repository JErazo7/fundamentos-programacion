#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
void ingresar(char mat[3][3]);
void imprimir_horizontal(int a);
void imprimir_vertical(int a);
int validar(char mat[3][3],char letra, int turno, int j, int i, int x, int y);
int ganador(char mat[3][3]);

int main()
{
	char mat[3][3];
	imprimir_horizontal(3);
	imprimir_vertical(3);
	ingresar(mat);
}

void posicion(float x, float y)
{
	 
	HANDLE posicion; 
	COORD cordenada; 
	posicion = GetStdHandle (STD_OUTPUT_HANDLE); 	 
	cordenada.X = x; cordenada.Y = y; 
	SetConsoleCursorPosition (posicion, cordenada);	
}

void imprimir_horizontal(int a)
{
	int i, j, n, x, y, aux;
	n=5*(a+1);
	y=5;
	for(aux=1; aux<a; aux++)
	{
		for(j=6; j<n ;j++)
		{
			posicion(j,y+3);printf("_");
		}
		y+=3;	
	}		
}

void imprimir_vertical(int a)
{
	int j, n, x ,aux;
	n=(a*3)+5;
	x=5;
	for(aux=1; aux<a; aux++)
	{
		for(j=6; j<=n ;j++)
		{
			posicion(x+5,j);printf("|");
		}
		x+=5;	
	}		
}


void ingresar(char mat[3][3])
{
	int i, j, x, y, aux,turno=0, s;
	char letra1='o', letra2='x';
	do
	{
		y=7;
		for(i=0;i<3;i++)
		{
			x=7;
			for(j=0;j<3;j++)
			{
				if(mat[i][j]!='o'&& mat[i][j]!='x')
				{
					if (turno==0)
						turno=validar(mat, letra1, turno, j,  i,  x,  y);
					else
						turno=validar(mat, letra2, turno, j,  i,  x,  y);
				}								
				s=ganador(mat);
				if(s==1)
				{
					posicion(5,20);printf("Haz ganado en horizonal\n");					
				}
				else
				{
					if(s==2)
					{
						posicion(5,20);printf("Haz ganado en vertical\n");
					}
					else
					{
						if(s==3)
						{
							posicion(5,20);printf("Haz ganado en diagonal\n");
						}							
					}									
				}
				if (s==1 || s==2 || s==3)
				{
					j=3;
					i=3;
				}				
				x+=5;
			}		
			y+=3;
		}	
	}while(ganador(mat)==0);
}

int validar(char mat[3][3],char letra, int turno, int j, int i, int x, int y)
{
	int aux, enter;
	posicion(5,18);printf("Turno de %c",letra);
	do
	{
		aux=0;
		fflush(stdin);
		posicion(x,y);scanf("%c",&mat[i][j]);
		if(mat[i][j]!=letra && mat[i][j]!='\n')
		{
			aux=1;
			posicion(5,20);printf("Error, caracter invalido");
			posicion(5,22);system("pause");
			posicion(5,20);printf("                        ");
			posicion(5,22);printf("                                       ");
		}							
	}while(aux==1);
	if (turno==0 && mat[i][j]=='\n') 
		return 0;
	else if (turno==0 && mat[i][j]!='\n')
		return 1;
	else if	(turno==1 && mat[i][j]=='\n')
		return 1;
	else
		return 0;	
	
}

int ganador(char mat[3][3])
{
	int f,aux=0;
	for(f=0; f<3; f++)
		if (mat[f][0]== mat[f][1] && mat[f][0]==mat[f][2] && (mat[f][0]=='o'|| mat[f][0]=='x'))
		{
			aux=1;
			f=3;				
		}
	if(aux==0)
	{
		for(f=0; f<3; f++)
			if ((mat[0][f]==mat[1][f]) && (mat[1][f]==mat[2][f])&& (mat[0][f]=='o'|| mat[0][f]=='x'))
			{
				aux=2;
				f=3;
			}
	}	
	if (aux==0)
	{
		if ((mat[0][0]==mat[1][1] && mat[1][1]==mat[2][2])||(mat[0][2]==mat[1][1] && mat[1][1]==mat[2][0]) && (mat[1][1]=='o' || mat[1][1]=='x' ))
			aux=3;
			
	}	
	return aux;	
}	

