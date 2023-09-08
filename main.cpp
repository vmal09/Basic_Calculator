#include <iostream>
#include <limits>

using namespace std;

void add();
void sub();
void multi();
void division();
void sqr();
void srt();
void exp();
void showHistory();
void exitProgram();

int main(){
    int opr;
    do
    {
        cout << "Select any operation from the C++ Calculator"
             << "\n1 = Addition"
             << "\n2 = Subtraction"
             << "\n3 = Multiplication"
             << "\n4 = Division"
             << "\n5 = Square"
             << "\n6 = Square Root"
             << "\n7 = Exponentiation"
             << "\n8 = Show Calculation History"
             << "\n9 = Exit"
             << "\n \n Make a choice: ";

        if (!(cin >> opr))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Invalid input. Please enter a valid numeric choice." << endl;
            continue;
        }

        switch (opr)
        {
        case 1:
            add();
            break;
        case 2:
            sub();
            break;
        case 3:
            multi();
            break;
        case 4:
            division();
            break;
        case 5:
            sqr();
            break;
        case 6:
            srt();
            break;
        case 7:
            exp();
            break;
        case 8:
            showHistory();
            break;
        case 9:
            exitProgram();
            break;
        default:
            cerr << "Invalid choice. Please select a valid operation." << endl;
            break;
        }

        cout << "\n------------------------------\n";
    } while (opr != 9);

     return 0;
}