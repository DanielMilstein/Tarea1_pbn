#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include<time.h>
#define GRID_SIZE 10

//1 -> true 
//0 -> false

int tipo_juego(char tipo[2]){
	if (tipo[1] == 'a') return 0;
	else
		if (tipo[1] == 'v') return 1;
	else return 9;

}
// arr es array que guarda tablero
char *arr[GRID_SIZE][GRID_SIZE], *datos[100], dato[100];

//srand(time(NULL));

//Jugador 1
char* tablaBarcosJ1[GRID_SIZE][GRID_SIZE] = {"__________","__________","__________","__________","__________",
									  		"__________","__________","__________","__________","__________"};

//Jugador 2 o automatico
char* tablaBarcosJ2[GRID_SIZE][GRID_SIZE] = {"__________","__________","__________","__________","__________",
									  		"__________","__________","__________","__________","__________"};

// transformacion de char a indice para lista
//a->97 0 ->48
//... 'a'-49


// Cuenta las lineas del archivo para saber cuantos barcos hay
int contar_lineas(char* nombre){
	char nombre_archivo[15];
	sprintf(nombre_archivo, "./%s.txt", nombre);
	FILE* archivo;
	int lineas = 0;
	char ch;

	archivo = fopen(nombre_archivo, "r");
	while (!feof(archivo)){
		ch = fgetc(archivo);
  		if(ch == '\n'){
		    lineas++;
  		}
	}
	fclose(archivo);
	return lineas;
}

int letra_a_numero(char letra){ //revisar, no corre 
	char letra = coord[0] -49;
	int lnum = letra;
	return lnum;
}

int check_no_overlap(int x, int y, char* tabla[GRID_SIZE][GRID_SIZE]){
	for (int i=0; i<GRID_SIZE; i++){
		for (int j=0; j<GRID_SIZE; i++){
			if (*tabla[i][j] != '_') return 0;
		}
	}
	return 1;
}

void add_ship_coord(char coord[3], char* tabla[GRID_SIZE][GRID_SIZE], char ship){
	int letra, numero;
	letra = letra_a_numero(coord[0]);
	numero = coord[1];
	if (check_no_overlap(letra, numero, tabla)){
		*tabla[letra][numero] = ship;
	}
	else{
		printf("Archivo contiene coordenadas incorrectas, hay un barco encima de otro\n");
	}
}


void parse_tablero(char* nombre, char* tabla[GRID_SIZE][GRID_SIZE]){
	// Parte archivo
	char nombre_archivo[15];
	sprintf(nombre_archivo, "./%s.txt", nombre);
	printf("%s\n", nombre_archivo);
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
	char** barco;
	char *token;
	int porte;
	for (int x=0; x < lineas;x++){
		//Primer token (nombre del barco)
		token = strtok(datos[x], s);
		int f = 0;
		while (token != NULL){
			barco[f] = token;
			f++;
			token = strtok(NULL, s);
		}
		
		//Tengo que hacer una sumatoria de los largos de los barcos para la condicion de termino (s)
		
		if (strcmp(barco[4], "h\0")==0){ //No estoy seguro del 0
			porte = atoi(barco[1]);

			for (int c=0; c<porte; c++){
				char coordenadaL; //Coordenada letra
				char coordenadaN; //Coordenada numero
				char coordenada[3];
				char quito = 'A';

				coordenadaL = barco[2][0] + c;
				coordenadaN = barco[3][0];
				coordenada[0] = coordenadaL;
				coordenada[1] = coordenadaN;
				coordenada[2] = '\0';
				//add_ship_coord();


			}
		}
		else if (strcmp(barco[4], "v\0")==0){ //No estoy seguro del 0
			porte = atoi(barco[1]);

			for (int c=0; c<porte; c++){
				char coordenadaL; //Coordenada letra
				char coordenadaN; //Coordenada numero
				char coordenada[3];

				coordenadaL = barco[2][0];
				coordenadaN = barco[3][0] + c;
				coordenada[0] = coordenadaL;
				coordenada[1] = coordenadaN;
				coordenada[2] = '\0';
				


			}
		}
	}
	return;

}

void crear_tablero() {
    for (int a = 0; a < GRID_SIZE; a++) {
        for (int b = 0; b < GRID_SIZE; b++) {
			arr[a][b] = "[_]";
        }
    }
}

void print_tablero(char** array){

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

int main(int argc, char** argv){
	//board();
	
	//parse_tablero(argv[1], arr);


	// char* tabla[] = {"__________","__________","__________","__________",
	// "__________","__________","__________","__________","__________","__________"};

	// print_tablero(tabla);
	
	
	char coordenadas[3];
	int fila;
	int columna;
	int aciertosj1=0;
	int aciertosj2=0;
	bool gano= false;
	int turno= 0;
	
	if(argv[1]=="-v"){
	
		while (gano== false){
		printf("Ingrese la coordenada de ataque: "); //pido las coordenadas de ataque
		scanf("%s", coordenadas);
	
		if(strlen(coordenadas)>3){
			printf("Coordenadas invalidas\n"); //valido el largo
		} else if(strlen(coordenadas)==3){
			fila= (int) coordenadas[2]; 
		}
	
		columna = letra_a_numero(coordenadas[0]);
	
		if( columna > 9 || fila > 9){
			printf("Coordenadas invalidas\n"); //verifico que esten dentro del tablero
		}else if(tablaBarcosJ1[fila][columna]== "[_]"){
			printf("Al Agua!\n");
			arr[fila][columna]= "[.]";
			print_tablero(arr);
		} else if(tablaBarcosJ1[fila][columna]!="[_]" && tablaBarcosJ1[fila][columna]!= "[.]" && tablaBarcosJ1[fila][columna]!= "[X]"){
			arr[fila][columna]="[X]";
			printf("Impacto!\n");
			print_tablero(arr);
			aciertosj1++;
			}
			turno++;
		printf("Ingrese la coordenada de ataque: "); //pido las coordenadas de ataque
		scanf("%s", coordenadas);
	
		if(strlen(coordenadas)>3){
			printf("Coordenadas invalidas\n"); //valido el largo
		} else if(strlen(coordenadas)==3){
			fila= (int) coordenadas[2]; 
		}
	
		columna = letra_a_numero(coordenadas[0]);
	
		if( columna > 9 || fila > 9){
			printf("Coordenadas invalidas\n"); //verifico que esten dentro del tablero
		}else if(tablaBarcosJ2[fila][columna]== "[_]"){
			printf("Al Agua!\n");
			arr[fila][columna]= "[.]";
			print_tablero(arr);
		} else if(tablaBarcosJ2[fila][columna]!="[_]" && tablaBarcosJ2[fila][columna]!= "[.]" && tablaBarcosJ2[fila][columna]!= "[X]"){
			arr[fila][columna]="[X]";
			printf("Impacto!\n");
			print_tablero(arr);
			aciertosj1++;
			}
		turno++;
		/*
		if (longitud_barcos=aciertosj1){
			gano== true;
			printf("Gana jugador 1\n");
			break;
		}else if(longitus_barcos=aciertosj2){
			gano== true;
			printf("Gana jugador 2\n");
			break;}*/
		}
	}else if(argv[1]=="-a"){
	
	while (gano== false){
	
		printf("Ingrese la coordenada de ataque: "); //pido las coordenadas de ataque
		scanf("%s", coordenadas);
	
		if(strlen(coordenadas)>3){
			printf("Coordenadas invalidas\n"); //valido el largo
		} else if(strlen(coordenadas)==3){
			fila= (int) coordenadas[2]; 
		}
	
		columna = letra_a_numero(coordenadas[0]);
	
		if( columna > 9 || fila > 9){
			printf("Coordenadas invalidas\n"); //verifico que esten dentro del tablero
		}else if(tablaBarcosJ1[fila][columna]== "[_]"){
			printf("Al Agua!\n");
			arr[fila][columna]= "[.]";
			print_tablero(arr);
		} else if(tablaBarcosJ1[fila][columna]!="[_]" && tablaBarcosJ1[fila][columna]!= "[.]" && tablaBarcosJ1[fila][columna]!= "[X]"){
			arr[fila][columna]="[X]";
			printf("Impacto!\n");
			print_tablero(arr);
			aciertosj1++;
			}
		turno++;
		/*
		if (longitud_barcos=aciertosj1){
			gano== true;
			printf("Gana jugador 1\n");
			break;
			}*/
		}
	
	}

	// //Si no se le pasan los argumentos al programa, termina solo.
	// if (argc<4){
	// 	printf("Faltan argumentos\n");
	// 	return 0;
	// }



	// //Si es 1 (true) el modo es versus
	// if (tipo_juego(argv[1])){




	// }

	// else //Si es 0 el modo es automatizado
	// 	if (tipo_juego(argv[1]) == 0){




	// 	}


	// else printf("Modo de juego no valido.\n");

	return 0;	
}	

