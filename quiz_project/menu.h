#pragma once
class menuall {
private:
    int choise = 0;
    int numQuestions;
    bool start = true;
    string filename;
    string adminname;
    string adminpassword;
    string player_name;
    string player_password;
    string name_player_new;
    string password_player_new;

    vector<Users>users;
    load_data_file f;
    Quiz quiz;

public:menuall() = default;

    void userdata() {
        ifstream fin("Users.txt", ios::in);

        if (!fin) {
            throw new exception("File can not be found");
        }

        if (!fin.is_open()) {
            throw new exception("File can not be opened");
        }

        string data;
        while (getline(fin, data)) {
            size_t pos1 = data.find(",");
            size_t pos2 = data.find(",", pos1 + 1);

            string username = data.substr(0, pos1);
            string password = data.substr(pos1 + 1, pos2 - pos1 - 1);

            Users user(username, password);
            users.push_back(user);
        }
        fin.close();
    }

    void allfiles() {
        int c = 8;
        WIN32_FIND_DATA findFileData;
        HANDLE hFind = FindFirstFile(L"*.txt", &findFileData);

        if (hFind != INVALID_HANDLE_VALUE) {
            do {
                SetCursor(40, c++);
                std::wcout << findFileData.cFileName << std::endl;
            } while (FindNextFile(hFind, &findFileData) != 0);

            FindClose(hFind);
        }
    }
    
    void startquiz() {
        setColor(Yellow, Black);
        SetCursor(50, 5);
        cout << "oxlari terpedin davam etmek ucun...";
        while (start) {
            switch (_getch()) {
            case 72:
                if (choise != 0)
                    choise--;
                system("cls");
                break;
            case 80:
                if (choise + 1 < 5)
                    choise++;
                system("cls");
                break;
            case '\r':
                if (choise == 5)
                    exit(0);
                else
                    start = false;
                break;
            default:
                system("cls");
                break;
            }
            if (start) {
                if (choise == 0) {
                    SetCursor(50, 5);
                    setColor(LightGreen, Black);
                    cout << ">> Login  <<\n";
                    setColor(Green, Black);
                    SetCursor(50, 6);
                    cout << "   Sign UP\n";
                    setColor(Green, Black);
                    SetCursor(50, 7);
                    cout << "   Play As Guest\n";
                    setColor(Green, Black);
                    SetCursor(50, 8);
                    cout << "   Admin Login\n";
                    SetCursor(50, 9);
                    setColor(Green, Black);
                    cout << "   Exit\n";
                }
                else if (choise == 1) {
                    SetCursor(50, 5);
                    setColor(Green, Black);
                    cout << "   Login \n";
                    SetCursor(50, 6);
                    setColor(LightGreen, Black);
                    cout << ">> Sign UP <<\n";
                    SetCursor(50, 7);
                    setColor(Green, Black);
                    cout << "   Play As Guest\n";
                    SetCursor(50, 8);
                    setColor(Green, Black);
                    cout << "   Admin Login\n";
                    SetCursor(50, 9);
                    setColor(Green, Black);
                    cout << "   Exit\n";
                }
                else if (choise == 2) {
                    SetCursor(50, 5);
                    setColor(Green, Black);
                    cout << "   Login \n";
                    SetCursor(50, 6);
                    setColor(Green, Black);
                    cout << "   Sign UP\n";
                    SetCursor(50, 7);
                    setColor(LightGreen, Black);
                    cout << ">> Play As Guest <<\n";
                    SetCursor(50, 8);
                    setColor(Green, Black);
                    cout << "   Admin Login\n";
                    SetCursor(50, 9);
                    setColor(Green, Black);
                    cout << "   Exit\n";
                }
                else if (choise == 3) {
                    SetCursor(50, 5);
                    setColor(Green, Black);
                    cout << "   Login \n";
                    SetCursor(50, 6);
                    setColor(Green, Black);
                    cout << "   Sign UP\n";
                    SetCursor(50, 7);
                    setColor(Green, Black);
                    cout << "   Play As Guest\n";
                    SetCursor(50, 8);
                    setColor(LightGreen, Black);
                    cout << ">> Admin Login <<\n";
                    SetCursor(50, 9);
                    setColor(Green, Black);
                    cout << "   Exit\n";
                }
                else if (choise == 4) {
                    SetCursor(50, 5);
                    setColor(Green, Black);
                    cout << "   Login \n";
                    SetCursor(50, 6);
                    setColor(Green, Black);
                    cout << "   Sign UP\n";
                    SetCursor(50, 7);
                    setColor(Green, Black);
                    cout << "   Play As Guest\n";
                    SetCursor(50, 8);
                    setColor(Green, Black);
                    cout << "   Admin Login  \n";
                    SetCursor(50, 9);
                    setColor(LightGreen, Black);
                    cout << ">>  Exit <<\n";
                }
            }
        }
        if (choise == 0)
        {
            userdata();
            system("cls");
            SetCursor(50, 5);
            setColor(White, Black);
            cout << "Enter name: ";
            cin >> player_name;
            SetCursor(50, 6);
            cout << "Enter Password: ";
            cin >> player_password;

            bool validUser = false;
            for (size_t i = 0; i < users.size(); i++) {
                if (users[i].login_chek(player_name, player_password)) {
                    validUser = true;
                    break;
                }
            }

            if (validUser) 
            {
                for (size_t i = 0; i < users.size(); i++)
                {
                    if (users[i].login_chek(player_name, player_password)) 
                    {    
                        system("cls");
                        setColor(Yellow, Black);
                        SetCursor(50, 5);
                        cout << "oxlari terpedin davam etmek ucun...";

                        SetCursor(50, 4);
                        setColor(Green, Black);
                        bool start1 = true;
                        int choise1 = 0;

                        while (start1) {
                            switch (_getch()) {
                            case 72:
                                if (choise1 != 0)
                                    choise1--;
                                system("cls");
                                break;
                            case 80:
                                if (choise1 + 1 < 4)
                                    choise1++;
                                system("cls");
                                break;
                            case '\r':
                                if (choise1 == 3) {
                                    system("cls");
                                }
                                else
                                    start1 = false;
                                break;
                            default:
                                system("cls");
                                break;
                            }
                            if (choise1 == 0) {
                                SetCursor(50, 5);
                                setColor(LightGreen, Black);
                                cout << ">> Start quiz  <<\n";
                                setColor(Green, Black);
                                SetCursor(50, 6);
                                cout << "   About Us\n";
                                setColor(Green, Black);
                                SetCursor(50, 7);
                                cout << "   Exit\n";
                            }
                            else if (choise1 == 1) {
                                SetCursor(50, 5);
                                setColor(Green, Black);
                                cout << "   Start quiz\n";
                                setColor(LightGreen, Black);
                                SetCursor(50, 6);
                                cout << ">> About Us <<\n";
                                setColor(Green, Black);
                                SetCursor(50, 7);
                                cout << "   Exit\n";
                            }
                            else if (choise1 == 2) {
                                SetCursor(50, 5);
                                setColor(Green, Black);
                                cout << "   Start quiz\n";
                                setColor(Green, Black);
                                SetCursor(50, 6);
                                cout << "   About Us \n";
                                setColor(LightGreen, Black);
                                SetCursor(50, 7);
                                cout << ">> Exit <<\n";
                            }
                        }
                        if (choise1 == 0) {
                            system("cls");
                            setColor(White, Black);
                            
                            allfiles();

                            f.load();
                        }
                        else if (choise1 == 1) {
                            system("cls");


                            FILE* fPtr;
                            fopen_s(&fPtr, "my_file.txt", "r");
                            char* buffer = new char[100];

                            if (fPtr != nullptr) {
                                SetCursor(10, 5);
                                while (fgets(buffer, 100, fPtr) != nullptr) {
                                    cout << buffer;
                                }
                                fclose(fPtr);
                            }
                        }
                        else {
                            exit(0);
                        }
                    }
                }
            }
            else {
                cout << "wrong";
            }
        }
        else if (choise == 1) {
            system("cls");
            SetCursor(50, 5);
            cout << "Enter name: ";
            cin >> name_player_new;
            SetCursor(50, 5);
            cout << "Enter Password: ";
            cin >> password_player_new;

            for (size_t i = 0; i < users.size(); i++)
            {
                if (users[i].get_name() == name_player_new)
                {
                    cout << "bu ad artiq movcuddur" << endl;
                    break;
                }
            }

            Users user(name_player_new, password_player_new);
            user.sing_up();
            users.push_back(user);
            SetCursor(50, 7);
            cout << "Succesfully Signed Up" << endl;
            Sleep(3000);
            system("cls");

           
        }
        else if (choise == 2)
        {
            system("cls");
            setColor(Yellow, Black);
            SetCursor(50, 5);
            cout << "Enter vurun davam etmek ucun...";
            allfiles();
            f.load();
        }
        else if (choise == 3) {
            system("cls");

            SetCursor(50, 5);
            cout << "admin name:";
            cin >> adminname;
            SetCursor(50, 6);
            cout << "admin parol:";
            cin >> adminpassword;
            system("cls");

            if (adminname == "admin" && adminpassword == "admin") {

                bool start2 = true;
                int choise2 = 0;

                while (start2) {
                    switch (_getch()) {
                    case 72:
                        if (choise2 != 0)
                            choise2--;
                        system("cls");
                        break;
                    case 80:
                        if (choise2 + 1 < 4)
                            choise2++;
                        system("cls");
                        break;
                    case '\r':
                        if (choise2 == 3) {
                            system("cls");
                        }
                        else
                            start2 = false;
                        break;
                    default:
                        system("cls");
                        break;
                    }
                    if (choise2 == 0) {
                        SetCursor(50, 5);
                        setColor(LightGreen, Black);
                        cout << ">> Creat quiz  <<\n";
                        setColor(Green, Black);
                        SetCursor(50, 6);
                        cout << "   Play quiz\n";
                        setColor(Green, Black);
                        SetCursor(50, 7);
                        cout << "   Exit\n";
                    }
                    else if (choise2 == 1) {
                        SetCursor(50, 5);
                        setColor(Green, Black);
                        cout << "   Creat quiz\n";
                        setColor(LightGreen, Black);
                        SetCursor(50, 6);
                        cout << ">> Play quiz <<\n";
                        setColor(Green, Black);
                        SetCursor(50, 7);
                        cout << "   Exit\n";
                    }
                    else if (choise2 == 2) {
                        SetCursor(50, 5);
                        setColor(Green, Black);
                        cout << "   Creat quiz\n";
                        setColor(Green, Black);
                        SetCursor(50, 6);
                        cout << "   Play quiz \n";
                        setColor(LightGreen, Black);
                        SetCursor(50, 7);
                        cout << ">> Exit <<\n";
                    }
                }
                if (choise2 == 0) {
                    system("cls");
                    setColor(White, Black);

                    cout << "Enter name of quiz: ";
                    cin >> filename;
                    filename.append(".txt");

                    cout << "How many questions do you want to add? ";
                    cin >> numQuestions;

                    cin.ignore();

                    for (int i = 0; i < numQuestions; ++i) {
                        quiz.add_new_question(filename);
                    }

                }
                else if (choise2 == 1) {
                    system("cls");
                    allfiles();
                    f.load();
                }
                else {
                    exit(0);
                }

            }


        }

    }
};