#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include<time.h>
#define GRID_SIZE 10

//1 -> true 
//0 -> false
// Falta chequear hundido.

int tipo_juego(char tipo[2]){
	if (tipo[1] == 'a') return 0;
	else
		if (tipo[1] == 'v') return 1;
	else return 9;

}
// arr es array que guarda tablero
char arr1[10][11];
char arr2[10][11];
char *datos[100];
char dato[100];


//Jugador 1
char tablaBarcosJ1[10][11];

//Jugador 2 o automatico
char tablaBarcosJ2[10][11];

// transformacion de char a indice para lista
//a->97 0 ->48
//... 'a'-49
//A->65 ... -17


// Cuenta las lineas del archivo para saber cuantos barcos hay
int contar_lineas(char* nombre){//ready
	char nombre_archivo[15];
	sprintf(nombre_archivo, "./%s.txt", nombre);
	FILE* archivo;
	int lineas = 0;
	char ch;

	archivo = fopen(nombre_archivo, "r");
	while (!feof(archivo)){
		ch = fgetc(archivo);
  		if(ch == '\n' || ch == EOF){
		    lineas++;
  		}
	}
	fclose(archivo);
	return lineas;
}

int letra_a_numero(char letra){//ready
	char coord = letra -49;
	int lnum = coord-'0';
	return lnum;
}

int letraMAYUS_a_numero(char letra){//ready
	char coord = letra -17;
	int lnum = coord-'0';
	return lnum;
}


int check_no_overlap(int x, int y, char tabla[GRID_SIZE][GRID_SIZE+1]){
	// No se porque la hice asi, la comento por si me acuerdo xd
	// for (int i=0; i<GRID_SIZE; i++){
	// 	for (int j=0; j<GRID_SIZE; i++){
	// 		if (tabla[i][j] != '_') return 0;
	// 	}
	// }
	// return 1;
	if (tabla[x][y] != '_') return 0;
	else return 1;
}

int add_ship_coord(char coord[3], char tabla[10][11], char ship){
	int letra, numero;
	letra = letraMAYUS_a_numero(coord[0]);
	numero = coord[1]-'0';
	printf("%d, %d\n", letra, numero);
	if (1){ //check_no_overlap(letra, numero, tabla)
		tabla[numero][letra] = ship;
		return 1;
	}
	else{
		printf("Archivo contiene coordenadas incorrectas, hay un barco encima de otro\n");
		return 0;
	}
}

int longitud_barcos=0;

int parse_tablero(char* nombre, char tabla[10][11]){
	// Parte archivo
	char nombre_archivo[15];
	sprintf(nombre_archivo, "./%s.txt", nombre);
	
	FILE* archivo;
	
	archivo = fopen(nombre_archivo, "r");

 	if (archivo == NULL) {
    		printf("No se pudo abrir el archivo\n");
    	} 
    else {
  		int i=0;
  		while(!feof(archivo)){

 			fscanf(archivo, "%s", dato);
 			datos[i] = dato;
 			i++;
			}
		
		
	fclose(archivo);

	}
	//Hasta aqui abrimos el archivo solamente y lo pasamos a un array todo junto.
	// Parte separar linea


	const char s[] = ";\n";
	int lineas = contar_lineas(nombre);
	char *barco[200];
	char *token;
	int porte;

	for (int x=0; x < lineas;x++){
		//Primer token (nombre del barco)
		token = strtok(datos[x], s);
		int f = 0;
		while (token != NULL){
			barco[f] = token;
			printf("%s\n", token);
			f++;
			token = strtok(NULL, s);
			
		}
		
		// for(int i=0; i< lineas; i++){
		// 	longitud= atoi(barco[1]);
		// 	longitud_barcos= longitud_barcos + longitud;
		// }
		
		if (barco[4][0] == 'h'){
			porte = atoi(barco[1]);
			
			for (int c=0; c<porte; c++){
				char coordenadaL; //Coordenada letra
				char coordenadaN; //Coordenada numero
				char coordenada[3];


				coordenadaL = barco[2][0] + c;
				coordenadaN = barco[3][0];
				coordenada[0] = coordenadaL;
				coordenada[1] = coordenadaN;
				coordenada[2] = '\0';
				printf("%s\n", coordenada);
				if (!add_ship_coord(coordenada, tabla, 65 + x)) return 0;
			}
		}
		else if (barco[4][0] == 'v'){
			porte = atoi(barco[1]);

			for (int d=0; d<porte; d++){
				char coordenadaL; //Coordenada letra
				char coordenadaN; //Coordenada numero
				char coordenada[3];

				coordenadaL = barco[2][0];
				coordenadaN = barco[3][0] + d;
				coordenada[0] = coordenadaL;
				coordenada[1] = coordenadaN;
				coordenada[2] = '\0';

				if (!add_ship_coord(coordenada, tabla, 65 + x)) return 0;
			}
		}
	}
	return 1;

}

void crear_tablero(char tabla[10][11]) {//ready
    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
			tabla[a][b] = '_';
        }
        tabla[a][10] = '\0';
    }
}

void print_tablero(char array[10][11]){

	printf("   A  B  C  D  E  F  G  H  I  J\n");
	for (int a = 0; a < GRID_SIZE; a++) {
		printf("%d ", a);
		
	    for (int b = 0; b < GRID_SIZE; b++) {
			printf("[%c]", array[a][b]);
	    }
	    printf(" %d", a);
	    printf("\n");
	}
	printf("   A  B  C  D  E  F  G  H  I  J\n");
}

void ataque(char tablero[10][11], char arr[10][11], int aciertos, char coordenadas[4]){
	int fila;
	int columna;
	
		if(strlen(coordenadas)>3){
			printf("Coordenadas invalidas\n"); //valido el largo
		} else if(strlen(coordenadas)==3){
			fila= (coordenadas[2] - '0'); 
		}
		columna = letra_a_numero(coordenadas[0]);

		if( columna <= 9 && fila <= 9 && coordenadas[0]<=106 && coordenadas[0]>=97){
			
		 	if(tablero[fila][columna]== '_'){
				printf("Al Agua!\n");
				arr[fila][columna]= '.';
				print_tablero(arr);
			
			}
			else 
				if(tablero[fila][columna]!= '_' && tablero[fila][columna]!= '.' 
											&& tablero[fila][columna]!= 'X'){
					arr[fila][columna]='X';
					tablero[fila][columna] = '_';
					printf("Impacto!\n");
					print_tablero(arr);
					aciertos++;
			}

			}
			else printf("Coordenadas invalidas\n");
	return;
}

void coordenadasCPU(char res[4]){
	srand(time(0));
		
	int columna = rand()%10 + 'a';
	int fila= rand()%10 + '0';
	sprintf(res, "%c,%c", columna, fila);
	return;
}
		
	
int main(int argc, char** argv){
	

	
	crear_tablero(arr1);
	crear_tablero(arr2);
	crear_tablero(tablaBarcosJ1);
	crear_tablero(tablaBarcosJ2);
	if (!parse_tablero(argv[1], arr1)) return 0; // cambiar de vuelta a argv[2]
	if (!parse_tablero(argv[1], arr2)) return 0; // cambiar de vuelta a argv[3]

	print_tablero(arr1);
	print_tablero(arr2);


	
	char coordenadas[4];
	int aciertosj1=0;
	int aciertosj2=0;
	bool gano= false;

	// // //Si no se le pasan los argumentos al programa, termina solo.
	// if (argc<4){
	// 	printf("Faltan argumentos\n");
	// 	return 0;
	// }



	// //Si es 1 (true) el modo es versus
	// if (tipo_juego(argv[1])){
	// 		while(!gano){
	// 			printf("Ingrese la coordenada de ataque: "); //pido las coordenadas de ataque
	// 			scanf("%s", coordenadas);
	// 			ataque(tablaBarcosJ1, arr1, aciertosj1, coordenadas);
				
	// 			printf("Ingrese la coordenada de ataque: "); //pido las coordenadas de ataque
	// 			scanf("%s", coordenadas);
	// 			ataque(tablaBarcosJ2, arr2, aciertosj2, coordenadas);
			
	// 			if (longitud_barcos == aciertosj1){
	// 				gano = true;
	// 				printf("Gana jugador 1\n");
	// 				return 0;
	// 			}
	// 			else 
	// 				if(longitud_barcos == aciertosj2){
	// 					gano = true;
	// 					printf("Gana jugador 2\n");
	// 					return 0;
	// 				}
	// 		}
	// }

	// else //Si es 0 el modo es automatizado
	// 	if (tipo_juego(argv[1]) == 0){

	// 		while(!gano){
	// 			printf("Ingrese la coordenada de ataque: "); //pido las coordenadas de ataque
	// 			scanf("%s", coordenadas);
	// 			ataque(tablaBarcosJ1, arr1, aciertosj1, coordenadas);
	// 			coordenadasCPU(coordenadas);
	// 			ataque(tablaBarcosJ2, arr2, aciertosj2, coordenadas);
		
	// 			if (longitud_barcos == aciertosj1){
	// 				gano = true;
	// 				printf("Gana jugador 1\n");
	// 				return 0;
	// 			}
	// 			else 
	// 				if(longitud_barcos == aciertosj2){
	// 					gano = true;
	// 					printf("Gana jugador 2\n");
	// 					return 0;
	// 				}
	// 		}



	// }


	// else printf("Modo de juego no valido.\n");

	return 0;	
}	
