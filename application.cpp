#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    string filename = "input.txt"; 
    string input_value;

//    cout << "Enter your input: " << endl;
//    getline(cin, input_value);


 ifstream input_file(filename);
    if (input_file.is_open()) {

        while (getline(input_file, input_value)) {
            cout << input_value << endl;
        }
        input_file.close();
    } else {
        cout << "Error: Unable to open file" << endl;
    }




//    cout << "The Result: " << input_value << endl;

    return 0;
}



