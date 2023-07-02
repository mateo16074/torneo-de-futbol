#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ingreso.h"
#include "resultados.h"

#define MAX_EQUIPOS 10

char nombresEquipos[MAX_EQUIPOS][50];
int nequip = 0;
int puntos[MAX_EQUIPOS];

void ingresarEquipos() {
  printf("Ingrese los nombres de los equipos que van a participar\n");
  printf("Si desea finalizar, escriba 'terminar'\n");

  while (nequip < MAX_EQUIPOS) {
    printf("Equipo %d: ", nequip + 1);
    scanf("%s", nombresEquipos[nequip]);

    if (strcmp(nombresEquipos[nequip], "terminar") == 0) {
      break;
    }

    nequip++;
  }
}
void guardarEquiposEnArchivo() {
  FILE *archivoEquipos = fopen("equipos.txt", "w");
  if (archivoEquipos == NULL) {
    printf("Error al abrir el archivo equipos.txt\n");
    return;
  }

  for (int i = 0; i < nequip; i++) {
    fprintf(archivoEquipos, "%s\n", nombresEquipos[i]);
  }

  fclose(archivoEquipos);
}