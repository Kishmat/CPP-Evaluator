#include <iostream>
#include <string>
#include <stack>
#include <iomanip>
#include <cmath>
#include <cctype>

#define showError(text) std::cerr << "Error: \033[31m" << text << "\033[0m\n"

void asciiART() { // generated from https://patorjk.com/software/taag/#p=display&f=Graffiti&t=Type%20Something%20
    std::cout << R"(
 _____ ______ ______          _____                _                _                
/  __ \| ___ \| ___ \        |  ___|              | |              | |               
| /  \/| |_/ /| |_/ / ______ | |__  __   __  __ _ | | _   _   __ _ | |_   ___   _ __ 
| |    |  __/ |  __/ |______||  __| \ \ / / / _` || || | | | / _` || __| / _ \ | '__|
| \__/\| |    | |            | |___  \ V / | (_| || || |_| || (_| || |_ | (_) || |   
 \____/\_|    \_|            \____/   \_/   \__,_||_| \__,_| \__,_| \__| \___/ |_|                          
)";
    std::cout << "\nWelcome to CPP-Evaluator, your arithmetic evaluator written in C++!\n";
    std::cout << "This simple yet powerful program evaluates your mathematical expressions.\n";
    std::cout << "Type your expression below, or type 'exit' to quit anytime.\n\n";
}

int priority(char op) {
    if (op == '+' || op == '-') return 1;
    else if (op == '*' || op == '/') return 2;
    return 0;
}

double actualMath(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b != 0 ? a / b : throw std::runtime_error("Division by zero");
        default: return 0;
    }
}

bool isValidExpression(const std::string& expression) {
    int parenthesesCount = 0;

    for (size_t i = 0; i < expression.length(); ++i) {
        char c = expression[i];

        if (!isdigit(c) && c != '+' && c != '-' && c != '*' && c != '/' && c != '(' && c != ')' && c != ' ' && c != '.') {
            std::string errorMessage = std::string("Invalid character ")+c+std::string(" in the expression.");
            showError(errorMessage);
            return false;
        }

        if (i > 0 && ((expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') &&
                      (expression[i - 1] == '+' || expression[i - 1] == '-' || expression[i - 1] == '*' || expression[i - 1] == '/'))) {
            showError("Consecutive operators are not allowed.");
            return false;
        }
        if (c == '(') parenthesesCount++;
        else if (c == ')') parenthesesCount--;

        if (parenthesesCount < 0) {
            showError("Mismatched parentheses.");
            return false;
        }
    }

    if (parenthesesCount != 0) {
        showError("Mismatched parentheses.");
        return false;
    }

    return true;
}

double evaluateExpression(const std::string& expression) {
    std::stack<double> numbers;
    std::stack<char> operators;

    for (size_t i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ') continue;

        if (isdigit(expression[i]) || expression[i] == '.') {
            double num = 0;
            double decimalFactor = 1;
            bool isDecimal = false;

            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                if (expression[i] == '.') {
                    isDecimal = true;
                    i++;
                    continue;
                }
                if (!isDecimal) {
                    num = num * 10 + (expression[i] - '0');
                } else {
                    decimalFactor /= 10;
                    num += (expression[i] - '0') * decimalFactor;
                }
                i++;
            }
            numbers.push(num);
            i--;
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            while (!operators.empty() && priority(operators.top()) >= priority(expression[i])) {
                double value2 = numbers.top(); numbers.pop();
                double value1 = numbers.top(); numbers.pop();
                char op = operators.top(); operators.pop();
                numbers.push(actualMath(value1, value2, op));
            }
            operators.push(expression[i]);
        } else if (expression[i] == '(') {
            operators.push(expression[i]);
        } else if (expression[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                double value2 = numbers.top(); numbers.pop();
                double value1 = numbers.top(); numbers.pop();
                char op = operators.top(); operators.pop();
                numbers.push(actualMath(value1, value2, op));
            }
            operators.pop();
        }
    }

    while (!operators.empty()) {
        double value2 = numbers.top(); numbers.pop();
        double value1 = numbers.top(); numbers.pop();
        char op = operators.top(); operators.pop();
        numbers.push(actualMath(value1, value2, op));
    }

    return numbers.top();
}

int main() {
    asciiART();

    std::string expression;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, expression);

        if (expression == "exit") {
            std::cout << "Goodbye! Thanks for using CPP-Evaluator!" << std::endl;
            break;
        }

        if (isValidExpression(expression)) {
            try {
                double result = evaluateExpression(expression);
                std::cout << "= " << result << std::endl;
            } catch (const std::exception& e) {
                showError(e.what());
            }
        }
    }

    return 0;
}