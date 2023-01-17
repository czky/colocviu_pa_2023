#include <stdio.h>
#include <stdlib.h>

// generare de partitii in functie de un n. partitiile au maxim n numere si trebuie sa fie formate din elemente ale caror
// suma da n

// struct pentru a salva partitiile
struct partitie {
    int *v; // vectorul de elemente din partitie
    int n; // numarul de elemente din partitie
};

// functia de generare a partitiilor folosind backtrack, partitiile pot avea numere cuprinse intre 1 si n, iar suma elementelor sa dea n
void partitii(int n, int k, int *v, struct partitie *p, int *nr_partitii) { // nr_partitii este un pointer pentru a putea fi modificat in functie de numarul de partitii
    int i;
    if (n == 0) {
        // daca suma elementelor din partitie este egala cu n, atunci salvam partitia
        p[*nr_partitii].v = (int *) malloc(k * sizeof(int));
        p[*nr_partitii].n = k; // salvam numarul de elemente din partitie
        for (i = 0; i < k; i++)
            p[*nr_partitii].v[i] = v[i];
        (*nr_partitii)++;
    } else {
        // daca suma elementelor din partitie este mai mica decat n, atunci continuam generarea partitiilor
        for (i = 1; i <= n; i++) {
            v[k] = i;
            partitii(n - i, k + 1, v, p, nr_partitii);
        }
    }
}



int main() {
    FILE *f = fopen("/Users/thomaszareczky/Desktop/Zareczky.Thomas_Andrei/numar.dat", "r");
    int n, i, j, *v, nr_partitii = 0;
    struct partitie *p;

    // citim numarul n
    fscanf(f, "%d", &n);

    // alocam memorie pentru vectorul de partitii
    p = (struct partitie *) malloc(n * sizeof(struct partitie));

    // alocam memorie pentru vectorul de elemente din partitie
    v = (int *) malloc(n * sizeof(int));

    // generam partitiile
    partitii(n, 0, v, p, &nr_partitii);

    // afisam partitiile
    for (i = 0; i < nr_partitii; i++) {
        if (p[i].n == n / 2) {
            for (j = 0; j < p[i].n; j++)
                printf("%d ", p[i].v[j]);
            printf("\n");
        }
    }
}