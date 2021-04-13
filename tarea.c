#include<stdio.h>
#include <stdlib.h>
#include <string.h>
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
char *arr[GRID_SIZE][GRID_SIZE], *datos[100], dato[100], *datos_clean[100];

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


void parse_tablero(char* nombre){
	// Parte archivo
	char nombre_archivo[15];
	sprintf(nombre_archivo, "./%s.txt", nombre);
	printf("%s\n", nombre_archivo);
	FILE* archivo;
	
	archivo = fopen(nombre_archivo, "r");

 	if (0) {
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
	char** barcos[lineas];
	char** barco;
	barco = malloc(5*sizeof(char));
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

		if (strcmp(barco[4], "h")==0){ 
			porte = atoi(barco[1]);
			char * quito[porte]; //Array de strings para cada coordenada
			//quito = malloc(3*porte*sizeof(char));


			for (int c=0; c<porte; c++){
				char coordenadaL; //Coordenada letra
				char coordenadaN; //Coordenada numero
				char coordenada[3];

				coordenadaL = barco[2][0] + c;
				coordenadaN = barco[3][0];
				coordenada[0] = coordenadaL;
				coordenada[1] = coordenadaN;
				coordenada[2] = '\0';
				 
				//strcpy(quito[c], coordenada);
				quito[c] = coordenada;
				printf("%s\n", coordenada);

			}
			// Agrego coordenadas de barco a barcos
			barcos[x] = quito;


		}


	}

	printf("%s\n", barcos[0][0]);
	printf("%s\n", barcos[0][1]);
	printf("%s\n", barcos[0][2]);

	return;

}



void board() {
    for (int a = 0; a < GRID_SIZE; a++) {
        for (int b = 0; b < GRID_SIZE; b++) {
			arr[a][b] = "[_]";
        }
    }

    printf("\n");

    for (int a = 0; a < GRID_SIZE; a++) {
        for (int b = 0; b < GRID_SIZE; b++) {
            	printf("%s", arr[a][b]);
        }
        printf("\n");
    }
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




int main(int argc, char** argv)
{
	//board();
	
	parse_tablero(argv[1]);


	// char* tabla[] = {"__________","__________","__________","__________",
	// "__________","__________","__________","__________","__________","__________"};

	// print_tablero(tabla);



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
