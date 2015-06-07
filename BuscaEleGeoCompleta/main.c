/***********************************************************

    Nome: Bárbara Coelho.
    IFSC
    Engenharia Eletrônica
    Programação de Computadores II

                    Atividade Busca Completa

*** time.h *** ainda não funcionando

***********************************************************/

#include "FuncoesBusca.h"

int main()
{
    int i;

    clock_t start1, end1;   // usado no vetor 50
    clock_t start2, end2;   // usado no vetor 500
    clock_t start3, end3;   // usado no vetor 5000
    double total1, total2, total3;

    //Ponteiros usados como retorno para a função bsearch

    Circulo *p;         // usado no vetor v[3]
    Circulo *rbusca1;   // usado no vetor 50
    Circulo *rbusca2;   // usado no vetor 500
    Circulo *rbusca3;   // usado no vetor 5000

    // Usados como retorno da Busca Linear

    int BL1;            // usado no vetor 50
    int BL2;            // usado no vetor 500
    int BL3;            // usado no vetor 5000

    //Valores usados para buscar nos vetores

    Circulo buscanome = {"c1",2,2};           // usado para buscar no vetor v[3]
    Circulo busca1 = {"SemNome",30,30};       // usado para buscar no vetor 50
    Circulo busca2 = {"SemNome",300,300};     // usado para buscar no vetor 500
    Circulo busca3 = {"SemNome",3000,3000};   // usado para buscar no vetor 5000

    // Criação dos Vetores 50, 500 e 5000

    Circulo v[3]={{"c2",20,10},{"c3",5,60},{"c1",2,2}};

    Circulo VetorBusca1[50];
    cria_vetor(VetorBusca1,50);     // cria o vetor 50

    Circulo VetorBusca2[500];
    cria_vetor(VetorBusca2,500);    // cria o vetor 500

    Circulo VetorBusca3[5000];
    cria_vetor(VetorBusca3,5000);   // cria o vetor 5000

    /////////////////Ordenação dos circulos/////////////////

    qsort(VetorBusca1,50,sizeof(Circulo),comp_circ_centro);
    qsort(VetorBusca2,500,sizeof(Circulo),comp_circ_centro);
    qsort(VetorBusca3,5000,sizeof(Circulo),comp_circ_centro);
    qsort(v,3,sizeof(Circulo),comp_circ_nome);

    printf("Vetor 'v' ordenado por nome:  ");
    for (i=0; i<3; i++)
        printf("(%s) ",v[i].nome);
    printf("\n");

    /////////////////////Busca Circulo/////////////////////

    p = bsearch(&buscanome,v,3,sizeof(Circulo),comp_circ_nome);
    if (p == NULL)
        printf("Elemento nao encontrado.\n");
    else
        printf("Elemento encontrado no indice: %d\n", p-v);

    ////////////////////Busca Circulo 1////////////////////

    printf("\nBusca para o vetor 50\n\n");
    start1 = clock();
    rbusca1 = bsearch(&busca1,VetorBusca1,50,sizeof(Circulo),comp_circ_centro);
    end1 = clock();
    total1 = (double)(end1 - start1)/CLOCKS_PER_SEC;
    if (rbusca1 == NULL)
        printf("Elemento nao encontrado.\n");
    else
        printf("Elemento encontrado no indice: %d\n", rbusca1-VetorBusca1);
    printf("Tempo total1 bsearch: %g ns.\n",total1*1000000);

   /////////////////////Busca Linear 1/////////////////////

    start1 = clock();
    BL1 = busca_linear(50,VetorBusca1,busca1);
    end1 = clock();
    total1 = (double)(end1 - start1)/CLOCKS_PER_SEC;
    if (BL1 == -1)
        printf("Elemento nao encontrado.\n");
    else
        printf("Elemento encontrado no indice: %d\n", BL1);
    printf("Tempo total1 Linear: %g ns.\n",total1*1000000);

    ////////////////////Busca Circulo 2////////////////////

    printf("\nBusca para o vetor 500\n\n");
    start2 = clock();
    rbusca2 = bsearch(&busca2,VetorBusca2,500,sizeof(Circulo),comp_circ_centro);
    end2 = clock();
    total2 = (double)(end2 - start2)/CLOCKS_PER_SEC;
    if (rbusca2 == NULL)
        printf("Elemento nao encontrado.\n");
    else
        printf("Elemento encontrado no indice: %d\n", rbusca2-VetorBusca2);
    printf("Tempo total2 bsearch: %g ns.\n",total2*1000000);

   /////////////////////Busca Linear 2/////////////////////

    start2 = clock();
    BL2 = busca_linear(500,VetorBusca2,busca2);
    end2 = clock();
    total2 = (double)(end2 - start2)/CLOCKS_PER_SEC;
    if (BL2 == -1)
        printf("Elemento nao encontrado.\n");
    else
        printf("Elemento encontrado no indice: %d\n", BL2);
    printf("Tempo total2 Linear: %g ns.\n",total2*1000000);

    ////////////////////Busca Circulo 2////////////////////

    printf("\nBusca para o vetor 5000\n\n");
    start3 = clock();
    rbusca3 = bsearch(&busca3,VetorBusca3,5000,sizeof(Circulo),comp_circ_centro);
    end3 = clock();
    total3 = (double)(end3 - start3)/CLOCKS_PER_SEC;
    if (rbusca3 == NULL)
        printf("Elemento nao encontrado.\n");
    else
        printf("Elemento encontrado no indice: %d\n", rbusca3-VetorBusca3);
    printf("Tempo total3 bsearch: %g ns.\n",total3*1000000);

    /////////////////////Busca Linear 3/////////////////////

    start3 = clock();
    BL3 = busca_linear(5000,VetorBusca3,busca3);
    end3 = clock();
    total3 = (double)(end3 - start3)/CLOCKS_PER_SEC;
    if (BL3 == -1)
        printf("Elemento nao encontrado.\n");
    else
        printf("Elemento encontrado no indice: %d\n", BL3);
    printf("Tempo total3 Linear: %g ns.\n",total3*1000000);

    return 0;
}
