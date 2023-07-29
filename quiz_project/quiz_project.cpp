#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<iomanip>
#include<windows.h>
#include<conio.h>
#include <filesystem>


using namespace std;

#include"design.h"
#include"loaddata.h"
#include"quiz.h"
#include"users.h"
#include"menu.h"


int main() {
    setColor(Yellow, Black);
    SetCursor(50, 5);
    cout << "oxlari terpedin davam etmek ucun...";
    setlocale(LC_ALL, "AZE");
    SetConsoleTitleA("Quiz");
    menuall a;
    a.startquiz();
}