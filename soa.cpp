#include <bits/stdc++.h>

using namespace std;

int* soa() {

    int M, N;
    FILE *in = fopen("data.txt", "r");
    fscanf(in, "%d %d", &N, &M);
    
    int* particulas = new int[4 * N * M];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < M * N; ++j)
        {
            fscanf(in, "%d", &particulas[(i * M * N) + j]);
        }
    }

    fclose(in);
    return particulas;
} 

int main(int argc, char const *argv[])
{
    int* particulas = soa();
    printf("%d\n", particulas[4]);
    return 0;
}