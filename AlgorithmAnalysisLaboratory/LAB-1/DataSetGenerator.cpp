#include <iostream>
#include <random>
#include <fstream>
using namespace std;

bool normalDistributionGenerator(int pow2, float mean, float sd, unsigned seed)
{
    default_random_engine generator(seed);

    normal_distribution<float> distribution(mean, sd);

    ofstream nrml;
    string file;
    cout << "Enter File Name NRML: - " << endl;
    cin >> file;

    nrml.open(file);

    for (int i = 0; i < pow(2, pow2); i++)
    {
        nrml << distribution(generator) << " ";
    }

    return true;
}

bool uniformDistributionGenerator(int pow2, int low, int high, unsigned seed)
{
    default_random_engine generator(seed);

    uniform_real_distribution<float> distribution(low, high);

    ofstream unf;
    string file;
    cout << "Enter File Name UNF: - " << endl;
    cin >> file;

    unf.open(file);

    for (int i = 0; i < pow(2, pow2); i++)
    {
        unf << distribution(generator) << " ";
    }

    return true;
}

int main()
{
    int pow2 = 19;
    normalDistributionGenerator(pow2, 1000000, 1000, 17);
    uniformDistributionGenerator(pow2, 1000, 1000000, 17);
}