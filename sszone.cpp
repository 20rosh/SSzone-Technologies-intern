#include <iostream>
#include <stdexcept>

using namespace std;

class Calculator {
public:
    void run() {
        char choice;
        do {
            float num1, num2, result;
            char op;

            cout << "SSZONE TECHNOLOGY - Simple Calculator Program\n";
            cout << "--------------------------------------------\n";

            num1 = getOperand("first");
            op = getOperator();
            num2 = getOperand("second");

            try {
                result = calculate(op, num1, num2);
                displayResult(result);
            } catch (const invalid_argument& e) {
                cout << "Error: " << e.what() << endl;
            }

            cout << "Do you want to perform another calculation? (y/n): ";
            cin >> choice;
        } while (choice == 'y' || choice == 'Y');
    }

private:
    char getOperator() {
        char op;
        cout << "Enter operator (+, -, *, /): ";
        cin >> op;

        if (op != '+' && op != '-' && op != '*' && op != '/') {
            throw invalid_argument("Invalid operator entered. Please enter one of the following: +, -, *, /");
        }

        return op;
    }

    float getOperand(const string& position) {
        float num;
        cout << "Enter the " << position << " number: ";
        cin >> num;
        return num;
    }

    float calculate(char op, float num1, float num2) {
        switch(op) {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '*':
                return num1 * num2;
            case '/':
                if (num2 == 0) {
                    throw invalid_argument("Division by zero is not allowed.");
                }
                return num1 / num2;
        }
    }

    void displayResult(float result) {
        cout << "Result: " << result << endl;
    }
};

int main() {
    Calculator calculator;
    calculator.run();
    return 0;
}
