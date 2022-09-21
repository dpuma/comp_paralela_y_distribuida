#include<iostream>
#include<vector>
#include <chrono>
using namespace std;

vector<vector<int>> crearMatriz(int fil, int col)
{
    vector<int> vecCeros(col, 0);
    vector<vector<int>> matCeros;

    for(int i = 0; i < fil; i++)
        matCeros.push_back(vecCeros);

    return matCeros;
}

void llenarMatRan(vector<vector<int>> &mat)
{
    for(int i = 0; i < mat.size(); i++)
        for(int j = 0; j < mat[0].size(); j++)
            mat[i][j] = rand()%1000;
}

void imprimirVector(vector<int> vec)
{
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

void imprimirMatriz(vector<vector<int>> mat)
{
    for(int i = 0; i < mat.size(); i++)
        imprimirVector(mat[i]);
    cout << endl;
}

int main()
{
    srand(100);
    int MAX[] = {200, 400, 600, 800, 1000, 1200};
    unsigned int a, i, j, k;

    cout << "datos\ttiempo" << endl;
    for(k = 0; k < 6; k++)
    {
        vector<vector<int>> A, B, C;
        A = crearMatriz(MAX[k], MAX[k]);
        B = crearMatriz(MAX[k], MAX[k]);
        C = crearMatriz(MAX[k], MAX[k]);
        llenarMatRan(A);
        llenarMatRan(B);

        auto start_time = std::chrono::high_resolution_clock::now();
        for (a = 0; a < MAX[k]; a++) {
            for (i = 0; i < MAX[k]; i++) {
                int suma = 0;
                for (j = 0; j < MAX[k]; j++) {
                    suma += A[i][j] * B[j][a];
                }
                C[i][a] = suma;
            }
        }
        auto end_time = std::chrono::high_resolution_clock::now();
        auto time = end_time - start_time;
        cout << MAX[k] << "\t" << time/chrono::milliseconds(1) << endl;
    }

    return 0;
}
