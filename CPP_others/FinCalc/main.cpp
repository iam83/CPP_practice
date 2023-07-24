/*
        Calculate bank deposit
*/

#include <iostream>
#include <iomanip> //for monetary output
#include <string>
#include "check.h" //check if enter is valid
#include "ccolor.h" //for OSX terminal color


void clearScreen(){

    #ifdef _WIN32
        system("cls");
    #endif
    #ifdef __APPLE__
        system("clear");
    #endif 

}

void printResult(double overall_income, double month_income, int count){
    #ifdef _WIN32
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    #endif
    //SetConsoleTextAttribute(hConsole, CColor::Grey); // for Windows console

    std::cout << std::showbase << "Month " << std::right << std::setw(2) << count+1 << ":   "
            << setColor(CColor::Green) << std::put_money(overall_income * 100) << setColor(CColor::Reset)
            << "    profit per month:  " << setColor(CColor::Cyan) << std::put_money(month_income * 100) << setColor(CColor::Reset) << "\n";
}

int main(){
    #ifdef _WIN32
        HANDLE  hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    #endif

<<<<<<< HEAD
    double overall_income{0.0};
    double const interest = 15.0;
=======
    clearScreen();

    double overall_income{0.0};
    //double const interest = 15.0;
>>>>>>> 8579c96a31411db3431cc52df729d58dadbf5211
    double month_income{0.0};

    double start_amount = EnterValues("Enter your deposit:> ");
    double month_amount = EnterValues("How many month(s)?> ");
    double interest = EnterValues("At what interest %?> ");

    //for test purpose
    // double start_amount = 1000000.0;
    // double month_amount = 12.0;

    std::cout << std::fixed << std::setprecision(2);
    std::cout.imbue(std::locale("ru_RU.UTF-8"));
    std::cout << std::showbase << "\nStart amount: " << std::put_money(start_amount * 100) << "\n";
    std::cout << "Interest rate: " << interest << "%\n\n";

    for (int i = 0; i < month_amount; ++i){

        //for the first month
        if (i == 0){
            month_income = (start_amount * (interest / 12.0)) / 100.0;
            overall_income = month_income + start_amount;
            printResult(overall_income, month_income, i);
            continue;
        }

        //calculate for the rest of months
        month_income += ((month_income * (interest / 12.0))) / 100.0;
        overall_income += month_income;
        printResult(overall_income, month_income, i);
        
    }

    #ifdef _WIN32
    std::cout << "\nYour overall income for " << month_amount
              << " month(s) is: " << overall_income;

    std::cout << "\nYour net income for " << month_amount
              << " month(s) is: " << overall_income - sum_start << "\n\n";
    #endif

    #ifdef __APPLE__

<<<<<<< HEAD
    std::cout << "\nYour net income for " << month_amount
              << " month(s) is: " << "\033[32m" << overall_income - sum_start << "\032[0m\n";
=======
    std::cout << "\nYour overall income for " << setColor(CColor::Cyan) << static_cast<int>(month_amount)
              << setColor(CColor::Reset) << " month(s) at " << setColor(CColor::Magenta) << interest << "%"
              << setColor(CColor::Reset) << " is: " << setColor(CColor::Green)
              << std::put_money(overall_income * 100) << setColor(CColor::Reset);

    std::cout << "\nYour income for " << setColor(CColor::Cyan) << static_cast<int>(month_amount)
              << setColor(CColor::Reset)
              << " month(s) is: " << setColor(CColor::Green) << std::put_money((overall_income - start_amount) * 100)
              << setColor(CColor::Reset);
>>>>>>> 8579c96a31411db3431cc52df729d58dadbf5211
    std::cout << "\n\n";

    #endif

    return 0;

}