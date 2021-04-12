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
char *arr[GRID_SIZE][GRID_SIZE], *datos[100], dato[100];




void parse_tablero(char* nombre){

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
 			printf("%s\n", datos[i]);
 			i++;
			}
		
		
	fclose(archivo);
	}
	return;

}



void board() {
    for (int a = 0; a < GRID_SIZE; a++) {
        for (int b = 0; b < GRID_SIZE; b++) {
			arr[a][b] = "[_]";
        }
    }
/*	arr[0][0]= " ";
	arr[1][0]= "0";
	arr[2][0]= "1";
	arr[3][0]= "2";
	arr[4][0]= "3";
	arr[5][0]= "4";
	arr[6][0]= "5";
	arr[7][0]= "6";
	arr[8][0]= "7";
	arr[9][0]= "8";
	arr[10][0]= "9";
	
	char x;
	for(int i=1; i< GRID_SIZE-1; i++){
		x= i + '0';
		arr[i][0]= x;

		}
		
		
	arr[0][1]= " a ";
	arr[0][2]= " b ";
	arr[0][3]= " c ";
	arr[0][4]= " d ";
	arr[0][5]= " e ";
	arr[0][6]= " f ";
	arr[0][7]= " g ";
	arr[0][8]= " h ";
	arr[0][9]= " i ";
	arr[0][10]=" j ";
*/
	
	
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
	
	//parse_tablero(argv[2]);


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
