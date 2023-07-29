#pragma once
class Users {
private:
    string _name;
    string _password;


public:
    Users() = default;
    Users(string name, string password) {
        set_name(name);
        set_password(password);
    }


    void set_name(string name) {
        if (name.length() <= 0)
            throw"wrong name length!\n";
        else
            _name = name;
    }

    void set_password(string password) {
        if (password.length() <= 0)
            throw"wrong password length!\n";
        else
            _password = password;
    }

    string get_name() { return _name; }
    string get_password() { return _password; }


    void sing_up() {
        ofstream fout("Users.txt", ios_base::app);

        if (!fout) {
            throw new exception("File can not be created");
        }

        if (!fout.is_open()) {
            fout.close();
            throw new exception("File can not be opened");
        }

        fout << _name << "," << _password << "," << endl;

        fout.close();
    }


    bool login_chek(string name, string password) {
        return name == _name && _password == password;
    }
};
