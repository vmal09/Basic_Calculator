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
             << "\n \nMake a choice: ";

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

void add()
{
    int n, sum = 0, number;

    // Prompt the user to enter the number of values they want to add
    cout << "\nHow many numbers you want to add: ";

    // Check if the input is not a positive integer
    if (!(cin >> n) || n <= 0)
    {
        cin.clear(); // Clear the error state of cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the input line
        cerr << "Invalid input. Please enter a valid positive number of values to add." << endl;
        return;
    }
        // Prompt the user to enter the numbers
        cout << "\nEnter numbers:\n";

    // Loop to input and add numbers
    for (int i = 1; i <= n; i++)
    {
        if (!(cin >> number)) 
        {
            cin.clear(); // Clear the error state of cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the input line
            cerr << "Invalid input. Please enter a valid numeric value." << endl;
            return;
        }

        sum += number; // Add the entered number to the sum
    }
   
    // Display the sum of the entered numbers
    cout << "\nSum of the numbers = " << sum << endl;
    
}