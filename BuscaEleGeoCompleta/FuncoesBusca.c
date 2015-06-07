/***********************************************************

    Nome: B�rbara Coelho.
    IFSC
    Engenharia Eletr�nica
    Programa��o de Computadores II

                    Atividade Busca Completa

***********************************************************/

#include "FuncoesBusca.h"

/* Fun��o usada para criar vetores de tamanho N */
void cria_vetor (Circulo* vet, int N)
{
    int i;
    for(i=0;i<N;i++)
    {
        vet[i].nome = "SemNome";
        vet[i].cx = i;
        vet[i].cy = i;
    }
}

/* Fun��o que compara pelo centro os valores do vetor para saber qual � maior */
int comp_circ_centro (const void * p1, const void * p2)
{
    const Circulo *f1 = p1;
    const Circulo *f2 = p2;
    if      (f1->cy < f2->cy) return -1;
    else if (f1->cy > f2->cy) return 1;
    else if (f1->cx < f2->cx) return -1;
    else if (f1->cx > f2->cx) return 1;
    else return 0;
}

/* Fun��o de busca linear */
int busca_linear(int n, Circulo* vet, Circulo elem)
{
    int i;
    for (i=0; i<n; i++)
    {
        if (elem.cy == vet[i].cy){
            if (elem.cx == vet[i].cx) return i; /* elemento encontrado */
        }
    }/* percorreu todo o vetor e n�o encontrou elemento */
    return -1;
}

/* Fun��o que compara o nome */
int  comp_circ_nome (const void *p1, const void *p2)
{
    const Circulo *f1 = p1;
    const Circulo *f2 = p2;
    if      (f1->nome < f2->nome) return -1;
    else if (f1->nome > f2->nome) return 1;
    else return 0;
}
