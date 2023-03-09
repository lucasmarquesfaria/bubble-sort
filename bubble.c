#include <stdio.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

void bubble_sort(vector<int> &arr, int &count)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
                count++;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}

int main()
{
    int n, choice;
    printf("Informe a quantidade de posições do vetor: ");
    scanf("%d", &n);
    vector<int> arr(n);
    printf("Informe o estado inicial do vetor: \n");
    printf("1 - Preenchido de forma aleatória\n");
    printf("2 - Preenchido de forma decrescente\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(0, 99);
        for (int i = 0; i < n; i++)
        {
            arr[i] = distrib(gen);
        }
    }
    else if (choice == 2)
    {
        for (int i = 0; i < n; i++)
        {
            arr[i] = n - i;
        }
    }
    else
    {
        printf("Opção inválida!\n");
        return 0;
    }
    printf("Vetor inicial: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int count = 0;
    auto start_time = chrono::high_resolution_clock::now();
    bubble_sort(arr, count);
    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> total_time = end_time - start_time;
    printf("Vetor ordenado: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Quantidade de trocas: %d\n", count);
    printf("Tempo de ordenação: %.6lf segundos\n", total_time.count());
    return 0;
}