//
//  TestaPrimo.c
//  TestaPrimo
//
//  Created by Ricardo de Carvalho Destro on 12/08/20.
//  Copyright © 2020 Ricardo de Carvalho Destro. All rights reserved.
//

#include "TestaPrimo.h"

/* Convencao: EhPrimo = 1 se o numero dado 'e primo */
/*  EhPrimo = 0 se o numero dado nao 'e primo       */



int TestaPrimo(long int n) 
{
    int EhPrimo = 1,
        d=2;
    if (n <= 1)
    EhPrimo = 0;

    while (EhPrimo == 1 && d <= n /2) {
    if (n % d  == 0)
        EhPrimo = 0;
    d = d + 1;
    }
    return EhPrimo;
}

double desvioPadrao(double x[15], double _x, int n)
{
    double dp = 0;
    double soma = 0;
    for (int j = 0; j < n; j++)
    {
        soma = pow(x[j] - _x, 2);
    }
    dp = sqrt(soma / n);

    return dp;

}

//Algoritmo 2

int main()
{

    clock_t tempo;
    double media = 0;
    double mediaTotal = 0;
    double soma = 0;
    double tempos[15];
    //int x = 0;
    //int temp = 0;
    int isprime = 0;
    double dp = 0;
    

    long int v[] = {7, 37, 8431, 13033, 524287, 664283, 3531271, 2147483647};

    printf("Variaveis\n");
    printf("T = tempo medio de execucao\t");
    printf("Dp = desvio padrao\n\n");
    printf("Calculando...\n");

    for (char j = 0; j < 8; j++) 
    {
        for (int i = 0; i < 15; i++) 
        {
            tempo = clock();
            isprime = TestaPrimo(v[j]);
            tempo = clock() - tempo;
            soma += ((double)tempo / CLOCKS_PER_SEC) * 1000;
            //printf("\ntempo acumulado: %f\n", soma);
            tempos[i] = tempo;
        
        //temp++;
        }
        media = soma / 15;
        //mediaTotal = media;
        dp = desvioPadrao(tempos, media, 15);
        
        printf("\nO numero %d %s. \nT = %f ms\nDp = %f \n", v[j], ((isprime) ? " eh primo" : " nao eh primo"), media, dp);
    }


    return 0;
}

