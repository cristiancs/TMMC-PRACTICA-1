#include <bits/stdc++.h>

using namespace std;

int* soa(FILE* in, int N, int M) {
    int* particulas = new int[4 * N * M];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < M * N; ++j)
        {
            fscanf(in, "%d", &particulas[(i * M * N) + j]);
        }
    }

    return particulas;
} 

int main(int argc, char const *argv[])
{
    int M, N;
    FILE *in = fopen("data.txt", "r");
    fscanf(in, "%d %d", &N, &M);

    int* particulas = soa(in, N, M);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < M * N; ++j)
        {
            printf("%d ", particulas[(i * M * N) + j]);
        }
        printf("\n");
    }

    fclose(in);

    return 0;
}