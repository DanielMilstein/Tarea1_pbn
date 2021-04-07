#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int tipo_juego(char tipo[2]){
	if (tipo[1] == 'a') return 0;
	else
		if (tipo[1] == 'v') return 1;
	else return 9;

}


int main(int argc, char** argv)
{
<<<<<<< HEAD
	//Si no se le pasan los argumentos al programa, termina solo.
	if (argc<4){
		printf("Faltan argumentos\n");
		return 0;
	}

	printf("%s\n", argv[0]);

	


	
=======
	printf("%s\n", argv[1]);
	printf("Hola\n");
>>>>>>> fd450ed106a30be88177e0670f8164222ea1aca8
	return 0;
}
