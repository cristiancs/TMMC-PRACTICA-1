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

    cout << *N << " " << *M << " " << endl;

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

int main(int argc, char const *argv[])
{

    int M, N;

    int *AoS = CalcularAoS("prueba.txt", &M, &N);

    for (int i = 0; i < M * N * 4; i++)
    {
        cout << AoS[i];
    }
    return 0;
}