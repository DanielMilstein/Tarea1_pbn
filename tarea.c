#include<stdio.h>
#include <stdlib.h>
#include <string.h>

//1 -> true 
//0 -> false

int tipo_juego(char tipo[2]){
	if (tipo[1] == 'a') return 0;
	else
		if (tipo[1] == 'v') return 1;
	else return 9;

}


void parse_tablero(char* nombre_archivo){

	FILE* archivo;
	archivo = fopen(nombre_archivo, "r");





	fclose(archivo);
	return;

}


int main(int argc, char** argv)
{

	//Si no se le pasan los argumentos al programa, termina solo.
	if (argc<4){
		printf("Faltan argumentos\n");
		return 0;
	}



	//Si es 1 (true) el modo es versus
	if (tipo_juego(argv[1])){




	}

	else //Si es 0 el modo es automatizado
		if (tipo_juego(argv[1]) == 0){




		}


	else printf("Modo de juego no valido.\n");

	return 0;
}
