#include <iostream>
#include <limits>
#include <cmath>


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
        cerr << "Invalid input. Please enter a valid positive number of values to add." << endl; // Display an error message
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
            cerr << "Invalid input. Please enter a valid numeric value." << endl; // Display an error message
            return;
        }

        sum += number; // Add the entered number to the sum
    }
   
    // Display the sum of the entered numbers
    cout << "\nSum of the numbers = " << sum << endl;
    
}

void sub()
{
    int num1, num2, result;

    // Prompt the user to enter the first number
    cout << "Enter the First number: ";

    // Check if the input is not a valid numeric value
    if (!(cin >> num1))
    {
        cin.clear(); // Clear the error state of cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the input line
        cerr << "Invalid input. Please enter a valid numeric value." << endl; // Display an error message
        return; 
    }

    // Prompt the user to enter the second number
    cout << "Enter the Second number: ";

    // Check if the input is not a valid numeric value
    if (!(cin >> num2))
    {
        cin.clear(); // Clear the error state of cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the input line
        cerr << "Invalid input. Please enter a valid numeric value." << endl; // Display an error message
        return;
    }

    // Calculate the subtraction of the two numbers
    result = num1 - num2;

    // Display the result of the subtraction
    cout << "Subtraction of the numbers = " << result << endl;
}

void multi()
{
    int num1, num2, result;

    // Prompt the user to enter the first number
    cout << "Enter the First number: ";

    // Check if the input is not a valid numeric value
    if (!(cin >> num1))
    {
        cin.clear(); // Clear the error state of cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the input line
        cerr << "Invalid input. Please enter a valid numeric value." << endl; // Display an error message
        return; 
    }

    // Prompt the user to enter the second number
    cout << "Enter the Second number: ";

    // Check if the input is not a valid numeric value
    if (!(cin >> num2))
    {
        cin.clear(); // Clear the error state of cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the input line
        cerr << "Invalid input. Please enter a valid numeric value." << endl; // Display an error message
        return; 
    }

    // Calculate the multiplication of the two numbers
    result = num1 * num2;

    // Display the result of the multiplication
    cout << "Multiplication of two numbers = " << result << endl;
}


void division()
{
    int num1, num2;

    // Prompt the user to enter the first number
    cout << "Enter the First number: ";

    // Check if the input is not a valid numeric value
    if (!(cin >> num1))
    {
        cin.clear(); // Clear the error state of cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the input line
        cerr << "Invalid input. Please enter a valid numeric value." << endl; // Display an error message
        return; 
    }

    // Prompt the user to enter the second number
    cout << "Enter the Second number: ";

    // Check if the input is not a valid numeric value
    if (!(cin >> num2))
    {
        cin.clear(); // Clear the error state of cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the input line
        cerr << "Invalid input. Please enter a valid numeric value." << endl; // Display an error message
        return; 
    }

    // Check if the second number is zero (division by zero)
    if (num2 == 0)
    {
        cerr << "Error: Division by zero is not allowed." << endl;
        return; // Division by zero is not allowed
    }

    // Calculate the division of the two numbers
    float result = static_cast<float>(num1) / num2;

    // Display the result of the division
    cout << "Division of two numbers = " << result << endl;
}

void sqr()
{
    int num1;
    cout << "Enter a number to find the Square: ";

    if (!(cin >> num1))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Invalid input. Please enter a valid numeric value." << endl;
        return;
    }

    int square = num1 * num1;
    string expression = "Square of " + to_string(num1) + " is: " + to_string(square);
    cout << expression << endl;

    
}

void srt()
{
    float num1;
    cout << "Enter the number to find the Square Root: ";

    if (!(cin >> num1))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Invalid input. Please enter a valid numeric value." << endl;
        return;
    }

    if (num1 < 0)
    {
        cerr << "Error: Square root of a negative number is not allowed." << endl;
        return;
    }

    float squareRoot = sqrt(num1);
    string expression = "Square Root of " + to_string(num1) + " is: " + to_string(squareRoot);
    cout << expression << endl;

    
}

