#include <iostream>
#include <vector>
using namespace std;

// Initializing the weights and bias for the perceptron
double w1 = 0.1; // Weight for the first input
double w2 = 0.5; // Weight for the second input
double b = -0.8; // Bias term

// Activation function: it returns 1 if the input is greater than 0, otherwise 0
int activate(double x) {
    return (x > 0) ? 1 : 0;
}

// Function to train the perceptron
// inputs: list of input pairs (x1, x2)
// desiredOutputs: expected outputs for each input pair
// learningRate: the rate at which the weights are updated
// epochs: number of training iterations
void trainPerceptron(vector<pair<double, double>> inputs, vector<int> desiredOutputs, double learningRate, int epochs) {
    // Loop through the number of epochs (training iterations)
    for (int epoch = 0; epoch < epochs; epoch++) {
        cout << "Epoch number " << epoch + 1 << endl;
        int totalError = 0;  // Initialize total error for this epoch

        // Display the headers for the table that shows updates for each input
        cout << "x1" << "\t" << "x2" << "\t" << "T" << "\t" << "O" << "\t" << "dw1" << "\t" << "w1" << "\t" << "dw2" << "\t" << "w2" << "\t" << "dw0" << "\t" << "w0" << endl;

        // Loop through each input pair and their corresponding desired output
        for (int i = 0; i < inputs.size(); i++) {
            double A = inputs[i].first;  // First input value (x1)
            double B = inputs[i].second; // Second input value (x2)
            int targetOutput = desiredOutputs[i]; // Expected output for this input pair
            int output = activate(w1 * A + w2 * B + b); // Calculate the perceptron output using weights and bias
            int error = targetOutput - output; // Calculate the error (difference between desired and actual output)

            // Update the weights and bias using the perceptron learning rule
            w1 += learningRate * error * A;
            w2 += learningRate * error * B;
            b += learningRate * error;

            totalError += abs(error); // Accumulate the absolute error for this epoch

            // Output the values for this iteration: inputs, desired output, actual output, weight updates, and updated weights
            cout << A << "\t" << B << "\t" << targetOutput << "\t" << output << "\t" 
                 << learningRate * error * A << "\t" << w1 << "\t" 
                 << learningRate * error * B << "\t" << w2 << "\t" 
                 << learningRate * error << "\t" << b << endl;
        }

        // If no errors occurred during this epoch, stop training
        if (totalError == 0) {
            break;
        }
    }
}

// Main function
int main() {
    // Define the inputs and desired outputs for the AND gate logic
    vector<pair<double, double>> inputs = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    vector<int> desiredOutputs = {0, 0, 0, 1}; // Expected outputs for AND gate

    // Define the learning rate and number of epochs
    double learningRate = 0.2;
    int epochs = 100;

    // Train the perceptron with the given inputs, outputs, learning rate, and epochs
    trainPerceptron(inputs, desiredOutputs, learningRate, epochs);

    // After training, test the perceptron on all input combinations
    for (int i = 0; i < inputs.size(); i++) {
        double A = inputs[i].first;  // First input value
        double B = inputs[i].second; // Second input value
        int output = activate(w1 * A + w2 * B + b); // Calculate the output using trained weights and bias
        cout << "Input: (" << A << ", " << B << ") Output: " << output << endl;
    }

    return 0; // End of the program
}
