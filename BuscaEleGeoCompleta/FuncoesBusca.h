/***********************************************************

    Nome: Bárbara Coelho.
    IFSC
    Engenharia Eletrônica
    Programação de Computadores II

                    Atividade Busca Completa

***********************************************************/

#ifndef FUNCOESBUSCA_H_INCLUDED
#define FUNCOESBUSCA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura Circulo
typedef struct circulo Circulo;
struct circulo
{
    char *nome;
    int cx;
    int cy;
};

/* Prototipos de funções */
void cria_vetor (Circulo* vet, int N);
int comp_circ_centro (const void * p1, const void * p2);
int busca_linear(int n, Circulo* vet, Circulo elem);
int comp_circ_nome (const void *p1, const void *p2);

#endif // FUNCOESBUSCA_H_INCLUDED
