#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VALUES 100
FILE *tr_gestiona_vector;

// FUNCIONS AUXILIARS
int llegir_valors(const char* nom_fitxer, int* valors, int max_valors) {
    FILE *fitxer;
    int i = 0;

    fitxer = fopen(nom_fitxer, "r");
    if (fitxer == NULL) {
        printf("No s'ha pogut obrir el fitxer.\n");
        return -1;
    }

    while (i < max_valors && fscanf(fitxer, "%d", &valors[i]) == 1) {
        i++;
        fprintf(tr_gestiona_vector, "%d %p\n", 2,&max_valors);
        fprintf(tr_gestiona_vector, "%d %p\n", 2,&valors[i]);
        fprintf(tr_gestiona_vector, "%d %p\n", 2,&i);
        fprintf(tr_gestiona_vector, "%d %p\n", 2,&fitxer);
        fprintf(tr_gestiona_vector, "%d %p\n", 3,&i);
    }

    fclose(fitxer);

    return i;
}
int* ordenar_valors(const int* valors, int n) {
    int* array_ordenat = malloc(n * sizeof(int)); // Crea nou array per a ordenar
    fprintf(tr_gestiona_vector, "%d %p\n", 2,&n);
    fprintf(tr_gestiona_vector, "%d %p\n", 3,&array_ordenat);

    for (int i = 0; i < n; i++) {
        array_ordenat[i] = valors[i]; // Copiar elements de valors al nou array
        fprintf(tr_gestiona_vector, "%d %p\n", 2,&i);
        fprintf(tr_gestiona_vector, "%d %p\n", 2,&valors[i]);
        fprintf(tr_gestiona_vector, "%d %p\n", 3,&array_ordenat[i]);
        fprintf(tr_gestiona_vector, "%d %p\n", 3,&i);
    }

    for (int i = 0; i < n-1; i++) {
        int min = i;
        fprintf(tr_gestiona_vector, "%d %p\n", 2,&i);
        fprintf(tr_gestiona_vector, "%d %p\n", 3,&min);

        for (int j = i + 1; j < n; j++) {
            fprintf(tr_gestiona_vector, "%d %p\n", 2,&i);
            fprintf(tr_gestiona_vector, "%d %p\n", 3,&j);
            fprintf(tr_gestiona_vector, "%d %p\n", 2,&n);

            if (array_ordenat[j] < array_ordenat[min]) {
                min = j;
                fprintf(tr_gestiona_vector, "%d %p\n", 2,&array_ordenat);
                fprintf(tr_gestiona_vector, "%d %p\n", 3,&min);
                fprintf(tr_gestiona_vector, "%d %p\n", 2,&j);
            }
        }

        if (min != i) {
            int temp = array_ordenat[i];
            array_ordenat[i] = array_ordenat[min];
            array_ordenat[min] = temp;
            fprintf(tr_gestiona_vector, "%d %p\n", 2,&array_ordenat);
            fprintf(tr_gestiona_vector, "%d %p\n", 3,&array_ordenat);
        }
        fprintf(tr_gestiona_vector, "%d %p\n", 3,&i);
    }

    return array_ordenat; // Retornar el array ordenado
}

void eliminar_repetits(int* array_ordenat, int num_values, int* nou_num_values) {
    int j = 0;

    for (int i = 0; i < num_values; i++) {
        fprintf(tr_gestiona_vector, "%d %p\n", 2,&i);
        fprintf(tr_gestiona_vector, "%d %p\n", 2,&num_values);

        if (i == 0 || array_ordenat[i] != array_ordenat[i-1]) { // Si l'element actual es diferent del anterior
            array_ordenat[j] = array_ordenat[i]; // Sobrescriure l'array d'entrada amb el nou element únic
            j++;
            fprintf(tr_gestiona_vector, "%d %p\n", 2,&i);
            fprintf(tr_gestiona_vector, "%d %p\n", 2,&array_ordenat[i]);
            fprintf(tr_gestiona_vector, "%d %p\n", 3,&array_ordenat[j]);
        }
        fprintf(tr_gestiona_vector, "%d %p\n", 3,&i);
    }

    *nou_num_values = j; // Actualitzar la longitud del array resultant
    fprintf(tr_gestiona_vector, "%d %p\n", 3,&nou_num_values);
    fprintf(tr_gestiona_vector, "%d %p\n", 2,&j);
}

void nombres_primers(int* array_ordenat, int num_values, int* nou_num_values) {
    int j = 0;
    fprintf(tr_gestiona_vector, "%d %p\n", 3,&j);

    for (int i = 0; i < num_values; i++) {
        bool es_primer = true;
        fprintf(tr_gestiona_vector, "%d %p\n", 2,&i);
        fprintf(tr_gestiona_vector, "%d %p\n", 2,&num_values);
        fprintf(tr_gestiona_vector, "%d %p\n", 3,&es_primer);

        for (int k = 2; (k <= array_ordenat[i] / 2) && es_primer; k++) {
            fprintf(tr_gestiona_vector, "%d %p\n", 3,&k);
            fprintf(tr_gestiona_vector, "%d %p\n", 2,&array_ordenat[i]);
            fprintf(tr_gestiona_vector, "%d %p\n", 2,&es_primer);

            if (array_ordenat[i] % k == 0) {
                es_primer = false;
                fprintf(tr_gestiona_vector, "%d %p\n", 2,&array_ordenat[i]);
                fprintf(tr_gestiona_vector, "%d %p\n", 2,&k);
                fprintf(tr_gestiona_vector, "%d %p\n", 3,&es_primer);
            }
        }

        if (es_primer) { // Si el nombre ès primer, sobrescribim l'array original amb el nombre
            array_ordenat[j] = array_ordenat[i];
            j++;
            fprintf(tr_gestiona_vector, "%d %p\n", 2,&es_primer);
            fprintf(tr_gestiona_vector, "%d %p\n", 3,&array_ordenat[j]);
            fprintf(tr_gestiona_vector, "%d %p\n", 2,&array_ordenat[i]);
            fprintf(tr_gestiona_vector, "%d %p\n", 3,&j);
            fprintf(tr_gestiona_vector, "%d %p\n", 2,&j);
        }

        fprintf(tr_gestiona_vector, "%d %p\n", 3,&i);
    }

    *nou_num_values = j; // Actualitzar la longitud del nou array
    fprintf(tr_gestiona_vector, "%d %p\n", 2,&j);
    fprintf(tr_gestiona_vector, "%d %p\n", 3,&nou_num_values);
}

void claus_criptografiques(const int* array_ordenat, int num_values, int* claus) {
    int j = 0;
    fprintf(tr_gestiona_vector, "%d %p\n", 3,&j);

    for (int i = 0; i < num_values / 2; i++) {
        claus[j] = array_ordenat[i] * array_ordenat[num_values - i - 1];
        j++;
        claus[j] = array_ordenat[i + 1] * array_ordenat[num_values - i - 2];
        j++;
        fprintf(tr_gestiona_vector, "%d %p\n", 3,&i);
        fprintf(tr_gestiona_vector, "%d %p\n", 2,&num_values);
        fprintf(tr_gestiona_vector, "%d %p\n", 3,&claus[j]);
        fprintf(tr_gestiona_vector, "%d %p\n", 2,&array_ordenat[i]);
        fprintf(tr_gestiona_vector, "%d %p\n", 2,&array_ordenat[num_values - i - 1]);
        fprintf(tr_gestiona_vector, "%d %p\n", 2,&array_ordenat[i + 1]);
        fprintf(tr_gestiona_vector, "%d %p\n", 2,&array_ordenat[num_values - i - 2]);
    }
}
void imprimir_array(const int* array, int num_values) {
    for (int j = 0; j < num_values; j++) {
        printf("%d\n", array[j]);
        fprintf(tr_gestiona_vector, "%d %p\n", 2,&num_values);
        fprintf(tr_gestiona_vector, "%d %p\n", 3,&j);
        fprintf(tr_gestiona_vector, "%d %p\n", 2,array[j]);

    }
    printf("\n");

}

// Funcions traça
void obrir_trasa() {
    tr_gestiona_vector = fopen("C:\\Users\\marcg\\OneDrive\\Documents\\Visual Studio Code\\C\\Arquitectura_de_Computadors\\Practica_1\\tr_gestiona_vector.prg", "w");
}

// FUNCIÓ PRINCIPAL
int main() {
    obrir_trasa();
    int array_valors[MAX_VALUES];
    int num_values, nou_num_values;

    num_values = llegir_valors("C:\\Users\\marcg\\OneDrive\\Documents\\Visual Studio Code\\C\\Arquitectura_de_Computadors\\Practica_1\\valors.txt",
                               array_valors, MAX_VALUES);
    fprintf(tr_gestiona_vector, "%d %p\n", 3,&num_values);

    if (num_values == -1) {
        return 1;
    }

    // Ordenar valors
    int* array_ordenat = ordenar_valors(array_valors, num_values);
    fprintf(tr_gestiona_vector, "%d %p\n", 3,&array_ordenat);

    // Eliminar repetits
    eliminar_repetits(array_ordenat, num_values, &nou_num_values);
    num_values = nou_num_values;
    fprintf(tr_gestiona_vector, "%d %p\n", 3,&num_values);
    fprintf(tr_gestiona_vector, "%d %p\n", 2,&nou_num_values);
    printf("Array Ordenat sense repeticions:\n");
    imprimir_array(array_ordenat, num_values);

    // Array de nombres primers
    nombres_primers(array_ordenat, num_values, &nou_num_values);
    num_values = nou_num_values;
    fprintf(tr_gestiona_vector, "%d %p\n", 3,&num_values);
    fprintf(tr_gestiona_vector, "%d %p\n", 2,&nou_num_values);
    printf("Nombres primers:\n");
    imprimir_array(array_ordenat, num_values);

    // Claus criptogràfiques
    int array_claus[num_values * 2];
    claus_criptografiques(array_ordenat, num_values, array_claus);
    printf("Claus Criptografiques:\n");
    imprimir_array(array_claus, num_values);

    /*
    // Imprimir els valors llegits
    for (int j = 0; j < num_values; j++) {
        printf("%d\n", array_claus[j]);
    } */
    fclose(tr_gestiona_vector);
    return 0;
}