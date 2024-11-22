#include <iostream>
#include <cmath>
using namespace std;

#define N 4

int main()
{
    double HMale[] = {6, 5.92, 5.58, 5.92};
    double HFemale[] = {5, 5.5, 5.42, 5.75};
    double WMale[] = {180, 190, 170, 165};
    double WFemale[] = {100, 150, 130, 150};
    double FMale[] = {12, 11, 12, 10};
    double FFemale[] = {6, 8, 7, 9};
    double th[] = {6};
    double tw[] = {130};
    double tf[] = {8};

    // Calculate mean and variance for male height
    double meanHMale = 0, varianceHMale = 0, sumHMale = 0, sum1 = 0;
    for (int i = 0; i < N; i++)
    {
        sumHMale += HMale[i];
    }
    meanHMale = sumHMale / N;
    for (int i = 0; i < N; i++)
    {
        sum1 += pow((HMale[i] - meanHMale), 2);
    }
    varianceHMale = sum1 / (N - 1);
    cout << "Mean of male height is : " << meanHMale << endl;
    cout << "Variance of male height is : " << varianceHMale << endl;

    // Calculate mean and variance for female height
    double meanHFemale = 0, varianceHFemale = 0, sumHFemale = 0, sum2 = 0;
    for (int i = 0; i < N; i++)
    {
        sumHFemale += HFemale[i];
    }
    meanHFemale = sumHFemale / N;
    for (int i = 0; i < N; i++)
    {
        sum2 += pow((HFemale[i] - meanHFemale), 2);
    }
    varianceHFemale = sum2 / (N - 1);
    cout << "Mean of female height is : " << meanHFemale << endl;
    cout << "Variance of female height is : " << varianceHFemale << endl;

    // Calculate mean and variance for male weight
    double meanWMale = 0, varianceWMale = 0, sumWMale = 0, sum3 = 0;
    for (int i = 0; i < N; i++)
    {
        sumWMale += WMale[i];
    }
    meanWMale = sumWMale / N;
    for (int i = 0; i < N; i++)
    {
        sum3 += pow((WMale[i] - meanWMale), 2);
    }
    varianceWMale = sum3 / (N - 1);
    cout << "Mean of male weight is : " << meanWMale << endl;
    cout << "Variance of male weight is : " << varianceWMale << endl;

    // Calculate mean and variance for female weight
    double meanWFemale = 0, varianceWFemale = 0, sumWFemale = 0, sum4 = 0;
    for (int i = 0; i < N; i++)
    {
        sumWFemale += WFemale[i];
    }
    meanWFemale = sumWFemale / N;
    for (int i = 0; i < N; i++)
    {
        sum4 += pow((WFemale[i] - meanWFemale), 2);
    }
    varianceWFemale = sum4 / (N - 1);
    cout << "Mean of female weight is : " << meanWFemale << endl;
    cout << "Variance of female weight is : " << varianceWFemale << endl;

    // Calculate mean and variance for male footsize
    double meanFMale = 0, varianceFMale = 0, sumFMale = 0, sum5 = 0;
    for (int i = 0; i < N; i++)
    {
        sumFMale += FMale[i];
    }
    meanFMale = sumFMale / N;
    for (int i = 0; i < N; i++)
    {
        sum5 += pow((FMale[i] - meanFMale), 2);
    }
    varianceFMale = sum5 / (N - 1);
    cout << "Mean of male footsize is : " << meanFMale << endl;
    cout << "Variance of male footsize is : " << varianceFMale << endl;

    // Calculate mean and variance for female footsize
    double meanFFemale = 0, varianceFFemale = 0, sumFFemale = 0, sum6 = 0;
    for (int i = 0; i < N; i++)
    {
        sumFFemale += FFemale[i];
    }
    meanFFemale = sumFFemale / N;
    for (int i = 0; i < N; i++)
    {
        sum6 += pow((FFemale[i] - meanFFemale), 2);
    }
    varianceFFemale = sum6 / (N - 1);
    cout << "Mean of female footsize is : " << meanFFemale << endl;
    cout << "Variance of female footsize is : " << varianceFFemale << endl;

    // Calculate probabilities and posterior for test data
    int testsize = sizeof(th) / sizeof(double);
    
    for (int i = 0; i < testsize; i++)
    {
        double probHeight = (1 / (sqrt(2 * 3.14 * varianceHMale))) * exp(-pow((th[i] - meanHMale), 2) / (2 * varianceHMale));
        cout << "Prob of height of male: " << probHeight << endl;

        double probWeight = (1 / (sqrt(2 * 3.14 * varianceWMale))) * exp(-pow((tw[i] - meanWMale), 2) / (2 * varianceWMale));
        cout << "Prob of weight of male: " << probWeight << endl;

        double probFootsize = (1 / (sqrt(2 * 3.14 * varianceFMale))) * exp(-pow((tf[i] - meanFMale), 2) / (2 * varianceFMale));
        cout << "Prob of footsize of male: " << probFootsize << endl;

        double probHeightF = (1 / (sqrt(2 * 3.14 * varianceHFemale))) * exp(-pow((th[i] - meanHFemale), 2) / (2 * varianceHFemale));
        cout << "Prob of height of female: " << probHeightF << endl;

        double probWeightF = (1 / (sqrt(2 * 3.14 * varianceWFemale))) * exp(-pow((tw[i] - meanWFemale), 2) / (2 * varianceWFemale));
        cout << "Prob of weight of female: " << probWeightF << endl;

        double probFootsizeF = (1 / (sqrt(2 * 3.14 * varianceFFemale))) * exp(-pow((tf[i] - meanFFemale), 2) / (2 * varianceFFemale));
        cout << "Prob of footsize of female: " << probFootsizeF << endl;

        double Male = 0.5;
        double Female = 0.5;
        double posteriorMale = 0.5 * probHeight * probWeight * probFootsize;
        double posteriorFemale = 0.5 * probHeightF * probWeightF * probFootsizeF;

        cout << "Posterior of male is: " << posteriorMale << endl;
        cout << "Posterior of female is: " << posteriorFemale << endl;

        if (posteriorMale > posteriorFemale)
        {
            cout << "The test data is male" << endl;
        }
        else
        {
            cout << "The test data is female" << endl;
        }
    }

    return 0;
}
