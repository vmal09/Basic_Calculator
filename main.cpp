#include <iostream>
#include <limits>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <string>

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

struct Calculation {
    string operation;
    string expression;
    double result;
};

vector<Calculation> history; // To store calculation history

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
    string expression = "";

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
        expression += to_string(number) + " + ";

    }
   
    expression = expression.substr(0, expression.length() - 2); // Remove the trailing " + "
    expression += " = " + to_string(sum);

    // Display the sum of the entered numbers
    cout << "\nSum of the numbers = " << sum << endl;
    
    Calculation calc = { "Addition", expression, static_cast<double>(sum) };
    history.push_back(calc);
}

void sub()
{
    int num1, num2, result;

    // Prompt the user to enter the first number
    cout << "\nEnter the First number: ";

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

    string expression = to_string(num1) + " - " + to_string(num2) + " = " + to_string(result);

    // Display the result of the subtraction
    cout << "\nSubtraction of the numbers = " << result << endl;
    
    Calculation calc = { "Subtraction", expression, static_cast<double>(result) };
    history.push_back(calc);

}

void multi()
{
    int num1, num2, result;

    // Prompt the user to enter the first number
    cout << "\nEnter the First number: ";

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

    string expression = to_string(num1) + " * " + to_string(num2) + " = " + to_string(result);

    // Display the result of the multiplication
    cout << "\nMultiplication of the numbers = " << result << endl;

    Calculation calc = { "Multiplication", expression, static_cast<double>(result) };
    history.push_back(calc);
}


void division()
{
    int num1, num2;

    // Prompt the user to enter the first number
    cout << "\nEnter the First number: ";

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

    string expression = to_string(num1) + " / " + to_string(num2) + " = " + to_string(result);

    // Display the result of the division
    cout << "\nDivision of the numbers = " << result << endl;
    
    Calculation calc = { "Division", expression, static_cast<double>(result) };
    history.push_back(calc);
}

void sqr()
{
    int num1;

    // Prompt the user to enter a number
    cout << "\nEnter a number to find the Square: ";

    // Check if the input is not a valid numeric value
    if (!(cin >> num1))
    {
        cin.clear(); // Clear the error state of cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the input line
        cerr << "Invalid input. Please enter a valid numeric value." << endl;
        return;
    }

    // Calculate the square of the entered number
    int square = num1 * num1;
    
    // Create a string that contains the expression for the square
    string expression = "Square of " + to_string(num1) + " is: " + to_string(square);
    
    // Display the expression and the result (square)
    cout << expression << endl;

    Calculation calc = { "Square", expression, static_cast<double>(square) };
    history.push_back(calc);
    
}

void srt()
{
    float num1;

    // Prompt the user to enter a number
    cout << "\nEnter the number to find the Square Root: ";

    // Check if the input is not a valid numeric value
    if (!(cin >> num1))
    {
        cin.clear(); // Clear the error state of cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the input line
        cerr << "Invalid input. Please enter a valid numeric value." << endl;
        return;
    }

    // Check if the entered number is negative
    if (num1 < 0)
    {
        cerr << "Error: Square root of a negative number is not allowed." << endl; // Display an error message
        return; // Exit the function to avoid taking the square root of a negative number
    }

    // Calculate the square root of the entered number
    float squareRoot = sqrt(num1);
    
    // Create a string that contains the expression for the square root
    string expression = "Square Root of " + to_string(num1) + " is: " + to_string(squareRoot);
    
    // Display the expression and the result (square root)
    cout << expression << endl;
    
    Calculation calc = { "Square Root", expression, squareRoot };
    history.push_back(calc);

}

void exp()
{
    double base, exponent;

    // Prompt the user to enter the base
    cout << "\nEnter the base: ";

    // Check if the input is not a valid numeric value for the base
    if (!(cin >> base))
    {
        cin.clear(); // Clear the error state of cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the input line
        cerr << "Invalid input. Please enter a valid numeric value for the base." << endl; // Display an error message
        return; 
    }

    // Prompt the user to enter the exponent
    cout << "Enter the exponent: ";

    // Check if the input is not a valid numeric value for the exponent
    if (!(cin >> exponent))
    {
        cin.clear(); // Clear the error state of cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the input line
        cerr << "Invalid input. Please enter a valid numeric value for the exponent." << endl; // Display an error message
        return; 
    }

    // Calculate the result of exponentiation using the pow() function
    double result = pow(base, exponent);

    // Create a string that contains the expression for the exponentiation
    string expression = to_string(base) + " ^ " + to_string(exponent) + " = " + to_string(result);

    // Display the result of the exponentiation
    cout << "\nExponentiation result = " << result << endl;
    
    Calculation calc = { "Exponentiation", expression, result };
    history.push_back(calc);

}

void showHistory()
{
    
    // Check if the history vector is empty
    if (history.empty())
    {
        cout << "\nCalculation history is empty." << endl;
        return;
    }

    cout << "\nCalculation History:\n" << endl;

    // Iterate through each Calculation object in the history vector
    for (const Calculation &calc : history)
    {
        // Display the expression and operation for each calculation
        cout << calc.expression << " [" << calc.operation << "]" << endl;
    }
}

void exitProgram()
{
    cout << "Exiting the program." << endl;
    exit(0);
}
