#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <cstring>

#include <stdlib.h>
using namespace std;

int *CalcularAoS(string filename, int *M, int *N)
{
    char cstr[filename.size() + 1];
    strcpy(cstr, filename.c_str());
    FILE *in = fopen(cstr, "r");
    fscanf(in, "%d %d", M, N);

    int *AoS = new int[4 * *M * *N];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < *M * *N; j++)
        {
            fscanf(in, "%d", &AoS[i + (j * 4)]);
        }
    }
    
    fclose(in);
    return AoS;
}

int *CalcularSoA(string filename, int *M, int *N)
{
    char cstr[filename.size() + 1];
    strcpy(cstr, filename.c_str());
    FILE *in = fopen(cstr, "r");
    fscanf(in, "%d %d", M, N);

    int *SoA = new int[4 * *M * *N];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < *M * *N; j++)
        {
            fscanf(in, "%d", &SoA[(i * *M * *N) + j]);
        }
    }
    
    fclose(in);
    return SoA;
}

int main(int argc, char const *argv[])
{

    int M, N;
    int *AoS = CalcularAoS("prueba.txt", &M, &N);
    int *SoA = CalcularSoA("prueba.txt", &M, &N);
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < M * N; ++j)
        {
            printf("%d ", AoS[(i * M * N) + j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < M * N; ++j)
        {
            printf("%d ", SoA[(i * M * N) + j]);
        }
        printf("\n");
    }


    return 0;
}