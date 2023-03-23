#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream input("instrukcje.txt");
    string command;
    char letter;
    string result = "";

    while (input >> command >> letter) {
        if (command == "DOPISZ") {
            result += letter;
        }
        else if (command == "ZMIEN") {
            result[result.size() - 1] = letter;
        }
        else if (command == "USUN") {
            result.pop_back();
        }
        else if (command == "PRZESUN") {
            for (int i = 0; i < result.size(); i++) {
                if (result[i] == letter) {
                    if (letter == 'Z') {
                        result[i] = 'A';
                    }
                    else {
                        result[i]++;
                    }
                    break;
                }
            }
        }
    }

    cout << result << endl;

    return 0;
}