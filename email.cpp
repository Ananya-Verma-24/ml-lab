#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <string>
using namespace std;

// Function to load words from a file and update the vector and vocabulary set.
void loadWords(const string &filename, vector<string> &words, set<string> &vocabulary) {
    ifstream file(filename);  // Open the file for reading
    string word;
    // Read each word from the file and add it to the vector and vocabulary set
    while (file >> word) {
        words.push_back(word);  // Add word to vector
        vocabulary.insert(word);  // Add word to vocabulary set (unique words)
    }
    file.close();  // Close the file after reading
}

int main() {
    vector<string> spam_file, ham_file, test_words;
    set<string> vocabulary;

    // Load words from files into vectors and vocabulary set
    loadWords("spam.txt", spam_file, vocabulary);
    loadWords("ham.txt", ham_file, vocabulary);
    loadWords("test.txt", test_words, vocabulary);

    // Output the size of the vocabulary and number of words in spam and ham files
    cout << "Vocabulary size is " << vocabulary.size() << "\n";
    cout << "No of words in spam files: " << spam_file.size() << "\n";
    cout << "No of words in ham files: " << ham_file.size() << "\n";

    // Calculate prior probability of spam based on file sizes
    double Pspam = (double)spam_file.size() / (spam_file.size() + ham_file.size());
    
    // Initialize counters for words of interest
    double cntget = 0, cntjob = 0, cntnotes = 0, cntevent = 0, cntoffer = 0;

    // Count occurrences of specific words in the spam file
    for (int i=0; i<spam_file.size(); i++) {
        if (spam_file[i] == "today") cntget++;
        if (spam_file[i] == "output") cntjob++;
        if (spam_file[i] == "input") cntnotes++;
        if (spam_file[i] == "forward") cntevent++;
        if (spam_file[i] == "inward") cntoffer++;
    }

    // Output the counts of specific words in the spam file
    cout << "Counts in spam class: " << cntget << " " << cntjob << " " 
         << cntnotes << " " << cntevent << " " << cntoffer << endl;

    // Calculate likelihood probabilities for specific words in spam
    double Pget_spam = (cntget + 1) / (spam_file.size() + vocabulary.size());
    double Pjob_spam = (cntjob + 1) / (spam_file.size() + vocabulary.size());
    double Pnotes_spam = (cntnotes + 1) / (spam_file.size() + vocabulary.size());
    double Pevent_spam = (cntevent + 1) / (spam_file.size() + vocabulary.size());
    double Poffer_spam = (cntoffer + 1) / (spam_file.size() + vocabulary.size());

    // Compute posterior probability for spam class
    double Posterior_spam = Pspam * Pget_spam * Pjob_spam * Pnotes_spam * Pevent_spam * Poffer_spam;

    // Output the posterior probability for spam
    cout << "Posterior values of spam: " << Posterior_spam << endl;

    // Reset counters for the ham file analysis
    cntget = cntjob = cntnotes = cntevent = cntoffer = 0;
    
    // Count occurrences of specific words in the ham file
    for (int i=0; i<ham_file.size(); i++) {
        if (ham_file[i] == "today") cntget++;
        if (ham_file[i] == "output") cntjob++;
        if (ham_file[i] == "input") cntnotes++;
        if (ham_file[i] == "forward") cntevent++;
        if (ham_file[i] == "inward") cntoffer++;
    }

    // Output the counts of specific words in the ham file
    cout << "Counts in ham class: " << cntget << " " << cntjob << " "
         << cntnotes << " " << cntevent << " " << cntoffer << endl;

    // Calculate prior probability of ham based on file sizes
    double Pham = (double)ham_file.size() / (spam_file.size() + ham_file.size());

    // Calculate likelihood probabilities for specific words in ham
    double Pget_ham = (cntget + 1) / (ham_file.size() + vocabulary.size());
    double Pjob_ham = (cntjob + 1) / (ham_file.size() + vocabulary.size());
    double Pnotes_ham = (cntnotes + 1) / (ham_file.size() + vocabulary.size());
    double Pevent_ham = (cntevent + 1) / (ham_file.size() + vocabulary.size());
    double Poffer_ham = (cntoffer + 1) / (ham_file.size() + vocabulary.size());

    // Compute posterior probability for ham class
    double Posterior_ham = Pham * Pget_ham * Pjob_ham * Pnotes_ham * Pevent_ham * Poffer_ham;

    // Output the posterior probability for ham
    cout << "Posterior Values of Ham: " << Posterior_ham << endl;

    // Classify the test word as spam or ham based on posterior probabilities
    if (Posterior_spam > Posterior_ham) {
        cout << "Test word is classified as spam.\n";
    } else {
        cout << "Test word is classified as ham.\n";
    }

    return 0;
}