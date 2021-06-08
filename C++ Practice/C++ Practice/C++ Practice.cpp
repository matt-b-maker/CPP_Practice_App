#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int main();

bool IsValid(vector<char> choices, char input);
char DisplayMenu(string message);
void AddNumber(vector<int> &numbers, string &message);
void DisplayMean(vector<int>& numbers, string& message);
void DisplaySmallest(vector<int>& numbers, string& message);
void DisplayLargest(vector<int>& numbers, string& message);

int main()
{
    vector<int> numbers = { 7,43,6,22,1,2,3,98,564,32,34 };
    string message{};
    char choice = DisplayMenu(message);

    do {
        switch (toupper(choice)) {
        case 'P':
            message += "\n[";
            for (int num : numbers) {
                message += ' ' + to_string(num) + ' ';
            }
            message += "]";
            choice = DisplayMenu(message);
            message = {};
            break;
        case 'A':
            AddNumber(numbers, message);
            choice = DisplayMenu(message);
            message = {};
            break;
        case 'M':
            DisplayMean(numbers, message);
            choice = DisplayMenu(message);
            message = {}; 
            break;
        case 'S':
            DisplaySmallest(numbers, message);
            choice = DisplayMenu(message);
            message = {};
            break;
        case 'L':
            DisplayLargest(numbers, message);
            choice = DisplayMenu(message);
            message = {};
            break;
        case 'Q':
            do {
                cout << "\nAre you sure you want to quit? Y/N : ";
                cin >> choice;
                if (toupper(choice) == 'Y') {
                    cout << "\nSee ya, DOOSH.\n";
                    return 0;
                }
                else if (toupper(choice) == 'N') {
                    message = "\nGo on and get back at it, then";
                    choice = DisplayMenu(message);
                    message = {};
                    break;
                }
                else
                    cout << "That's not a Y or an N";
            } while (toupper(choice) != 'Y' || toupper(choice) != 'N');
            break;
        }
    } while (true);

    return 0;
}

bool IsValid(vector<char> choices, char input) {
    for (char letter : choices) {
        if (toupper(input) == letter) {
            return true;
        }
    }
    return false;
}

char DisplayMenu(string message) {

    if (!message.empty()) {
        cout << message << "\n\n";
    }

    bool validSelection = false;
    char choice{};
    vector<char> choices = { 'P', 'A', 'M', 'S', 'L', 'Q' };

    do {
        cout << "P - Print numbers\n";
        cout << "A - Add a number to the list\n";
        cout << "M - Display the mean of the numbers\n";
        cout << "S - Display the smallest number\n";
        cout << "L - Display the largest number\n";
        cout << "Q - Quit\n\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (!isalpha(toupper(choice)) || !IsValid(choices, choice)) {
            system("CLS");
            cout << "Invalid choice. Look at the list, ya donkey.\n\n";
        }
        else {
            validSelection = true;
        }
    } while (!validSelection);

    return choice;
}

void AddNumber(vector<int> &numbers, string &message) {

    bool isValid = false;
    int newNumber{};

    cout << "Enter the number you want to add to the list: ";
    cin >> newNumber;

    message = "\n" + to_string(newNumber) + " added to the list";

    numbers.push_back(newNumber);
}

void DisplayMean(vector<int>& numbers, string& message) {

    int mean{};

    for (int number : numbers) {
        mean += number;
    }
    mean = abs(mean) / numbers.size();

    message = "\nThe mean is " + to_string(mean);
}

void DisplaySmallest(vector<int>& numbers, string& message) {
    
    int smallest{numbers.at(0)};

    for (int number : numbers) {
        if (number < smallest) {
            smallest = number;
        }
    }

    message = "\n" + to_string(smallest) + " is the smallest number in the list";
}

void DisplayLargest(vector<int>& numbers, string& message) {

    int largest{ numbers.at(0) };

    for (int number : numbers) {
        if (number > largest) {
            largest = number;
        }
    }

    message = "\n" + to_string(largest) + " is the largest number in the list";
}



