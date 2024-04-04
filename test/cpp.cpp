#include <iostream>

using namespace std;

int main() {
    string input;
    cout << "Input expression of form <operator> <operation> <operator>:\n";
    getline(cin, input);

    int a, b;
    char eva;

    auto space = input.find(' ');
    a = stoi(input.substr(0, space));
    input = input.substr(space + 1);

    eva = input[0];
    b = stoi(input.substr(2));

    switch (eva)
    {
        case '+':
            cout << a + b << '\n';
            break;
        case '-':
            cout << a - b << '\n';
            break;
        case 'x':
            cout << a * b << '\n';
            break;
        case '/':
            switch (b)
            {
                case 0:
                    cout << "INVALID EXPRESSION\n";
                    break;
                
                default:
                    cout << a / b << '\n';
                    break;
            } 
        default:
            break;
    }

    return 0;
}