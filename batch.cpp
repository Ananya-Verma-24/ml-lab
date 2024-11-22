#include <iostream> // For input/output
#include <cmath>    // For mathematical functions like pow()
#include <iomanip>
using namespace std;

#define alpha 0.00000001
#define desired_error 0.1
#define no_of_sample 10

float h[no_of_sample];
float w[3];
float cal_h(int);
// Initialise the training set
int x[no_of_sample][2] = {{500, 1}, {3000, 6}, {2000, 4}, {1500, 3}, {3500, 7}, {5000, 10}, {6000, 12}, {4500, 9}, {5500, 11}};
float y[no_of_sample] = {12, 72, 48, 36, 84, 120, 144, 108, 132};
int test[no_of_sample][2] = {{1000, 2}, {4000, 8}};
int e = 0;
void testing()
{
    float test_y = 0.0;
    for (int i = 0; i < 2; i++)
    {
        float test_x1 = test[i][0];
        float test_x2 = test[i][1];
        test_y = w[0] + w[1] * test_x1 + w[2] * test_x2;
        cout << "Predicted y for " << fixed << setprecision(2) 
          << test_x1 << " " << test_x2 << " = " << test_y << endl;
    }
}
float cal_h(int i)
{
    float temp = w[0];
    for (int j = 0; j < 3; j++)
    {
       temp += w[j] * x[i][j - 1];
    }
    h[i] = temp;
    cout << "\n\ncal_h = " << fixed << setprecision(6) << temp << " " << h[i] << "........." << endl;
    return h[i];
}
int main()
{
    
    w[0] = 0.002010;
    w[1] = 0.023;
    w[2] = 0.004045;
    float error = 1;
    cout<<"\n For the Learning rate alpha= "<<alpha;
    cout << "\nInitial Weights are: w[0]=" << w[0]
          << ", w[1]=" << w[1]
          << ", w[2]=" << w[2] << endl;
    while (error > desired_error)
    {
        cout<<"\n For Epoch "<< ++e;
        error = 0;

        for (int i = 0; i < no_of_sample; i++)
        {
            cout << "\n\nHypothesis for Training sample " << (i + 1) 
          << " = " << cal_h(i) << endl;
            error += 0.5 * pow((h[i] - y[i]), 2);
        }
        for (int i = 0; i < no_of_sample; i++)
        {
            w[0] += alpha * (y[i] - h[i]) * 1;
            w[1] += alpha * (y[i] - h[i]) * x[i][0];
            w[2] += alpha * (y[i] - h[i]) * x[i][1];
        }
        error = error / 10;
        cout << "\nCost = " << error << "\nw0 = " 
          << fixed << setprecision(6) << w[0]
          << "\nw1 = " << fixed << setprecision(6) << w[1]
          << "\nw2 = " << fixed << setprecision(6) << w[2]
          << endl;
    }
    testing();
    return 0;
}