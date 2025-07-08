#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Question {
    string text;
    vector<string> options;
    string correct;
    string difficulty;
};

// Load questions from the questions.txt file
vector<Question> loadQuestions(const string& filename) {
    vector<Question> questions;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Could not open " << filename << endl;
        return questions;
    }

    cout << "Questions file loaded successfully." << endl;

    string line;
    int lineNum = 0;

    while (getline(file, line)) {
        lineNum++;
        stringstream ss(line);
        string part;
        vector<string> parts;

        while (getline(ss, part, '|')) {
            parts.push_back(part);
        }

        if (parts.size() == 7) {
            Question q;
            q.text = parts[0];
            q.options = {parts[1], parts[2], parts[3], parts[4]};
            q.correct = parts[5];
            q.difficulty = parts[6];

            // Trim spaces from all parts
            for (auto& opt : q.options) {
                opt.erase(0, opt.find_first_not_of(" \t"));
                opt.erase(opt.find_last_not_of(" \t") + 1);
            }
            q.correct.erase(0, q.correct.find_first_not_of(" \t"));
            q.correct.erase(q.correct.find_last_not_of(" \t") + 1);

            questions.push_back(q);
        } else {
            cerr << "Skipped line " << lineNum << " due to invalid format." << endl;
        }
    }

    return questions;
}

// Ask a single question and update score
void askQuestion(const Question& q, int& score) {
    cout << endl << q.text << endl;
    char labels[] = {'A', 'B', 'C', 'D'};
    for (int i = 0; i < 4; ++i) {
        cout << labels[i] << ") " << q.options[i] << endl;
    }

    cout << "Your answer (A/B/C/D): ";
    char userChoice;
    cin >> userChoice;
    userChoice = toupper(userChoice);

    int index = userChoice - 'A';
    if (index >= 0 && index < 4) {
        if (q.options[index] == q.correct) {
            cout << "Correct!" << endl;
            score++;
        } else {
            cout << "Incorrect! Correct answer: " << q.correct << endl;
        }
    } else {
        cout << "Invalid choice. Skipping question." << endl;
    }
}

// Main function
int main() {
    cout << "Welcome to DSA Quizzo " << endl;
    cout << "Enter your name: ";
    string name;
    getline(cin, name);

    vector<Question> questions = loadQuestions("questions.txt");

    if (questions.empty()) {
        cerr << "No questions loaded. Please check questions.txt." << endl;
        return 1;
    }

    int score = 0;

    for (size_t i = 0; i < questions.size(); ++i) {
        askQuestion(questions[i], score);

        if (i < questions.size() - 1) {
            cout << "\nDo you want to continue to next question? (y/n): ";
            char choice;
            cin >> choice;
            cin.ignore();  // Clear newline character
            if (tolower(choice) != 'y') break;
        }
    }

    cout << "\nQuiz Complete, " << name << "! Your final score: " << score << " / " << questions.size() << endl;
    return 0;
}
