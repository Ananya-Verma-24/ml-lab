#include <iostream>
#include <vector>
#include <cmath>

#define alpha 0.00000001
#define desired_error 0.10
#define no_of_samples 10

using namespace std;

void testing();
float calculate_prediction(int i);

// Training data: {area (m²), number of bedrooms}
vector<vector<int>> features = {
    {1000, 2}, {2000, 4}, {500, 1}, {3000, 6}, {1500, 3},
    {3500, 7}, {4500, 9}, {5000, 10}, {5500, 11}, {6000, 12}
};

// Test data: Only the specified house
vector<int> test_data = {2500, 5}; // Prediction for 2500 m² and 5 bedrooms

// Target house prices in lakhs
vector<float> prices = {24, 48, 12, 72, 36, 84, 108, 120, 132, 144};

vector<float> weights(3); // Three weights including bias
vector<float> predicted_prices(no_of_samples);
int epoch = 0;

int main() {
    float error = 1;
    weights[0] = 0.002010;
    weights[1] = 0.023;
    weights[2] = 0.004045;

    cout << "\nFor the Learning rate alpha=" << alpha << "\n";
    cout << "Initial Weights are: w[0]=" << weights[0] << ", w[1]=" << weights[1] << ", w[2]=" << weights[2] << "\n";

    while (error > desired_error) {
        cout << "\nFor Epoch " << ++epoch << "\n";
        for (int i = 0; i < no_of_samples && error > desired_error; i++) {                     
            cout << "\nHypothesis for Training sample " << i + 1 << " = " << calculate_prediction(i);
            error = 0.5 * pow((predicted_prices[i] - prices[i]), 2);
            cout << "\nCost = " << error;

            // Weight update rule
            for (int j = 0; j < 3; j++) {
                if (j == 0) {
                    weights[0] = weights[0] + alpha * (prices[i] - predicted_prices[i]) * 1;
                } else {
                    weights[j] = weights[j] + alpha * (prices[i] - predicted_prices[i]) * features[i][j - 1];
                }
                cout << "\nWeight Updated: w[" << j << "] = " << weights[j];
            }
        }
    }
    testing();
    return 0;
}

void testing() {
    float predicted_price = weights[0];

    for (int j = 0; j < 2; j++) {
        predicted_price += weights[j + 1] * test_data[j];
    }
    
    cout << "\n\nPredicted price for house with {" << test_data[0] << " m², " << test_data[1] << " bedrooms} = " << predicted_price << " lakhs\n";
}

float calculate_prediction(int i) {
    float prediction = weights[0]; // Start with the bias term

    for (int j = 1; j < 3; j++) {
        prediction += weights[j] * features[i][j - 1];
    }

    predicted_prices[i] = prediction;
    return predicted_prices[i];
}