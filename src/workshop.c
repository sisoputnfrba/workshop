#include <stdio.h>
#include <stdlib.h>
#include <commons/collections/list.h>

typedef struct {
	int edad;
	char nombre[10];
} Usuario ;

void imprimir_usuario(Usuario* aImprimir){
	printf("El usuario tiene nombre: %s\n",
			aImprimir->nombre);
	printf("El usuario tiene edad: %i\n",
			aImprimir->edad);
}

void cargarUsuario(Usuario* usr, int edad) {
	usr->edad = edad;
	strcpy(usr->nombre, "joaquin");
}

int main(void) {
	t_list* variosUsuarios;
	variosUsuarios = list_create();

	int i;
	for (i = 0; i < 10; ++i) {
		Usuario* joaquin = malloc(sizeof(Usuario));
		cargarUsuario(joaquin, 15+i);
		list_add(variosUsuarios, joaquin);
	}

	int totalEdad = 0;
	void sumarEdades(Usuario* p){
		totalEdad += p->edad;
	}
	_Bool esMayor(Usuario* p){
		return p->edad >= 18;
	}

	list_iterate(
			list_filter(variosUsuarios, esMayor),
			sumarEdades);

	list_destroy_and_destroy_elements(variosUsuarios, free);

	printf("la edad total es: %i", totalEdad);

	return EXIT_SUCCESS;
}





