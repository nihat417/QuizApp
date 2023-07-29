#pragma once
class load_data_file
{
private:
    vector<string> quiz;
    size_t correct_count = 0;
    size_t wrong = 0;
    string filename;
    int pointer = 0;
public:

    void result_game(size_t correct, size_t wrong) {
        SetCursor(50, 5);
        cout << "finish!" << endl;
        setColor(Green, Black);
        SetCursor(50, 6);
        cout << "Correct: " << correct;
        setColor(Red, Black);
        SetCursor(50, 7);
        cout << "Wrong: " << wrong;
        setColor(White, Black);

        exit(0);
    }


    void load() {
        SetCursor(60, 8);
        cin.get();
        fstream f;
        cout << "Filename: ";
        getline(cin, filename);
        if (filename == "0") {
            system("cls");
            return;
        }
        filename.append(".txt");
        system("cls");
        f.open(filename, ios::in);
        if (!f.is_open())
        {
            cout << "file isn't open " << endl;
        }
        else
        {
            string line;
            char choose;
            char correct;
            int c = 5;
            int l = 3;

            while (!f.eof())
            {
                getline(f, line);
                SetCursor(25, l);
                cout << "\t" << line << endl;
                char a = 65;
                for (size_t i = 0; i < 4; i++)
                {
                    getline(f, line);
                    if (line == "null")
                        break;
                    cout << a++ << ")" << line << endl;
                }
                if (f.eof())
                    break;

                cin >> choose;
                getline(f, line);
                correct = line[0];

                if (correct == choose) {
                    correct_count++;
                    system("cls");
                }
                else if (correct != choose) {
                    wrong++;
                    system("cls");
                }

                char option;
                cout << "Next (n) / Previous (p) / Finish (f): ";
                cin >> option;

                if (option == 'n') {
                    system("cls");
                    continue;
                }
                else if (option == 'p') {
                    if (pointer > 0) {
                        pointer -= 2;
                        system("cls");
                    }
                    continue;
                }
                else if (option == 'f') {
                    result_game(correct_count, wrong);
                    break;
                }
                else {
                    cout << "Invalid option. Try again." << endl;
                }
            }
        }
        f.close();
        result_game(correct_count, wrong);
        system("pause");
        system("cls");
    }
};