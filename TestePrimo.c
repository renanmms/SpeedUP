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


//Algoritmo 1
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

//Algoritmo 2
//Teorema de Wilson que valida se os números são primos ou não
int TestePrimo2(int x) 
{
    int flag = 0;
    int i = 0;
    for (i = 2; i <= x / 2; ++i) {

        // condition for non-prime
        if (x % i == 0) {
            flag = 1;
            break;
        }
    }

    return flag;
}


//Algoritmo 3
//Pequeno Teorema de Fermat
//estarei utilizando o maior número primo informado 2147483647 para o valor n, para validar se a é ou não primo
int TestePrimo3(int num)
{
    if (num <= 3) {
        return num > 1;
    }


    if ((num % 2 == 0) || (num % 3 == 0)) {
        return num;
    }

    
    int contador = 5;
    while (pow(contador, 2) <= num) {
        if (num % contador == 0 ||  num % (contador + 2) == 0) {
            return 0;
        }

        contador += 6;
    }

    return 1;
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
            isprime = TestePrimo3(v[j]);
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

