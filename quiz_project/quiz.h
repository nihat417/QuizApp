#pragma once
class Quiz {
private:
    string text;
    string answer1;
    string answer2;
    string answer3 = "null";
    string answer4 = "null";
    char correct;
public:

    Quiz() = default;

    void add_new_question(string name)
    {
        fstream fout(name, ios::app);

        Quiz question;
        short size;
        cin.ignore();
        cout << "Enter question text: ";
        getline(cin, question.text);
        cout << "how many questions Do you want to addÆ ";
        cin >> size;

        cout << "Enter answer 1: ";
        cin >> question.answer1;
        cout << "Enter answer 2: ";
        cin >> question.answer2;

        if (size == 3) {
            cout << "Enter answer 3: ";
            cin >> question.answer3;
        }
        else if (size == 4) {
            cout << "Enter answer 3: ";
            cin >> question.answer3;
            cout << "Enter answer 4: ";
            cin >> question.answer4;
        }

        cout << "which is right? ";
        cin >> question.correct;

        question.write_file(fout);
    }

    void write_file(fstream& fs) {
        fs << text << endl;
        fs << answer1 << endl;
        fs << answer2 << endl;
        fs << answer3 << endl;
        fs << answer4 << endl;
        fs << correct << endl;
    }
};