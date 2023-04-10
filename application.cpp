#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// here in this function we are shifting the character position in the alphabet.
char shiftChar(char character, int number_of_shift, const string& alphabet) {
    int position = alphabet.find(character);
    if (position == string::npos) {
        return character;
    } else {
        int shift_position = (position + number_of_shift + alphabet.size()) % alphabet.size();
        return alphabet[shift_position];
    }
}

// here it encrypts and decrypts using by shifts
string EncryptDecrypt(const string& msg, int number_of_shift, const string& alphabet, bool encrypt) {
    string result = "";
    int sign = encrypt ? 1 : -1;
    for (char character : msg) {
        result += shiftChar(character, sign * number_of_shift, alphabet);
    }
    return result;
}

// in this code reading the input and return the output as an array.
const int MAX_LINES = 100;
int readInputFile(const string& filename, string lines[]) {
    int line_count = 0;
    ifstream input(filename);
    if (input.is_open()) {
        string line;
        while (getline(input, line)) {
            if (line_count == MAX_LINES) {
                break;
            }
            lines[line_count++] = line;
        }
        input.close();
    } else {
        cerr << "Error: Unable to open file" << endl;
    }
    return line_count;
}

// we are using this switch for language selection based on the input file.
string getAlphabet(int language_choice) {
    switch (language_choice) {
        case 0: // English // here we use like this because both the languages has same alphabets.
        case 1: // French
            return "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        case 2: // Spanish
            return "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
        case 3: // Turkish
            return "ABCÇDEFGĞHIİJKLMNOÖPRSŞTUÜVYZ";
        default:
            cout << "Unknown language type: " << language_choice << endl;
            return "";
    }
}

int main() {

    const int MAX_LINES = 100;
    string lines[MAX_LINES];
    int line_count = readInputFile("input.txt", lines);

    // here it Process each line of input
    for (int i = 0; i < line_count; i++) {
        // Parse input line
        int number_of_shift, encrypt_decrypt, language_choice;
        char message[1000000];
        if (sscanf(lines[i].c_str(), "%d:%d:%d:%[^\n]", &number_of_shift, &encrypt_decrypt, &language_choice, message) != 4) {
            cout << "Error parsing input line: " << lines[i] << endl;
            continue;
        }

        string alphabet = getAlphabet(language_choice);
        if (alphabet.empty()) {
            continue;
        }

        bool encrypt_mode;
        switch (encrypt_decrypt) {
            case 0:
                encrypt_mode = true;
                break;
            case 1:
                encrypt_mode = false;
                break;
            default:
                cout << "Invalid encrypt/decrypt choice: " << encrypt_decrypt << endl;
                continue;
        }

        string output = EncryptDecrypt(message, number_of_shift, alphabet, encrypt_mode);

        cout << output << endl;
    }

    return 0;
}
