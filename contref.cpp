#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct Mem{
    void *endereco;
    int cont;
}Mem;

void *malloc2(Mem *vet, int vetTam){
    int i;
    void *p;
    if(vet != NULL){
        p = malloc(sizeof(int));
        for(i =0; i < vetTam; i++){
            if(vet[i].cont == 0){
                vet[i].endereco = p;
                vet[i].cont++;
                return p;
            }
        }
    }
    return NULL;
}

void *atrib(Mem *vet, int vetTam, void *ori, void *dest){

    int i;

    if (vet != NULL){
        if(ori != NULL){
            for(i = 0; i < vetTam; i++){
                if(ori == vet[i].endereco){
                    vet[i].cont--;
                    if(vet[i].cont == 0){
                        free(vet[i].endereco);
                        vet[i].endereco = NULL;
                    }
                    break;
                }
            }
        }
        if(dest != NULL){
            for(i = 0; i < vetTam; i++){
                if(dest == vet[i].endereco){
                    vet[i].cont++;
                }
            }
        }
        return dest;
    }
    return NULL;
}

void imprimeMem(Mem *vet, int vetTam){
    int i;
    printf("Estado da memória\n");
    for(i = 0; i < vetTam; ++i){
        printf("& - %p, Contador - %d\n", vet[i].endereco, vet[i].cont);
    }
}

int main()
{
    int *p, *v = NULL;
    system("chcp 1252 > nil");
    Mem *vet = (Mem*)calloc(MAX, sizeof(Mem));

    p = (int*)malloc2(vet, MAX);
    v = (int*)malloc2(vet, MAX);
    *v = 1;
    *p = 2;
    printf("*v - %d, *p - %d\n", *v, *p);
    imprimeMem(vet, MAX);
    v = (int*)atrib(vet, MAX, v, p);
    printf("*v - %d, *p - %d\n", *v, *p);
    imprimeMem(vet, MAX);
    v = (int*)atrib(vet, MAX, v, NULL);
    imprimeMem(vet, MAX);
    p = (int*)atrib(vet, MAX, p, NULL);
    imprimeMem(vet, MAX);
    return 0;
}
