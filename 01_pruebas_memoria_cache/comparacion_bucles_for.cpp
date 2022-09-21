#include <iostream>
#include <vector>
#include <chrono>


using namespace std;

vector<vector<double>> crearMatriz(int fil, int col)
{
    vector<double> vecCeros(col, 0);
    vector<vector<double>> matCeros;

    for(int i = 0; i < fil; i++)
        matCeros.push_back(vecCeros);

    return matCeros;
}

void llenarVecRan(vector<double> &vec)
{
    for(int i = 0; i < vec.size(); i++)
        vec[i] = rand();
}

void llenarMatRan(vector<vector<double>> &mat)
{
    for(int i = 0; i < mat.size(); i++)
        for(int j = 0; j < mat[0].size(); j++)
            mat[i][j] = rand();
}

void llenarVecCeros(vector<double> &vec)
{
    for(int i = 0; i < vec.size(); i++)
        vec[i] = 0;
}

void imprimirVector(vector<double> vec)
{
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

void imprimirMatriz(vector<vector<double>> mat)
{
    for(int i = 0; i < mat.size(); i++)
        imprimirVector(mat[i]);
}

int main()
{
    srand(100);
    //const int MAX = 1000;
    int MAX[] = {1000, 3000, 5000, 7000, 9000, 11000, 13000, 15000};
    unsigned i, j;

    cout << "datos\tfor1.ms\tfor2.ms" << endl;
    for(int k = 0; k < 8; k++)
    {
        //double A[MAX][MAX], x[MAX], y[MAX];
        vector<vector<double>> A = crearMatriz(MAX[k], MAX[k]);
        vector<double> x(MAX[k], 0);
        vector<double> y(MAX[k], 0);

        /* Initialize A and x, assign y = 0 */
        llenarVecRan(x);
        llenarMatRan(A);

        /* First pair of loops */
        auto start_time = std::chrono::high_resolution_clock::now();

        for (i = 0; i < MAX[k]; i++)
            for (j = 0; j < MAX[k]; j++)
                y[i] += A[i][j]*x[j];

        auto end_time = std::chrono::high_resolution_clock::now();
        auto time = end_time - start_time;
        cout << MAX[k] << "\t" << time/chrono::milliseconds(1) << "\t";

        /* Assign y = 0 */
        llenarVecCeros(y);

        /* Second pair of loops */
        start_time = std::chrono::high_resolution_clock::now();

        for (j = 0; j < MAX[k]; j++)
            for (i = 0; i < MAX[k]; i++)
                y[i] += A[i][j]*x[j];

        end_time = std::chrono::high_resolution_clock::now();
        time = end_time - start_time;
        cout << time/chrono::milliseconds(1) << endl;
    }
}
