
#include <iostream>
#include<fstream>
#include<string>
using namespace std;

//2
bool isVowel(char c) {
    char vowels[] = "AEIOUaeiou";
    for (int i = 0; vowels[i] != '\0'; ++i) {
        if (c == vowels[i]) return true;
    }
    return false;
}

bool isConsonant(char c) {
    return isalpha(c) && !isVowel(c);
}


//3
char shiftChar(char c, int key) {
    if (c >= 'A' && c <= 'Z') {
        return 'A' + (c - 'A' + key) % 26;
    }
    else if (c >= 'a' && c <= 'z') {
        return 'a' + (c - 'a' + key) % 26;
    }
    else {
        return c;
    }
}

void caesarCipher(const string& inputFileName, const string& outputFileName, int key) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Cannot open file" << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        for (size_t i = 0; i < line.size(); ++i) {
            line[i] = shiftChar(line[i], key);
        }
        outputFile << line << endl;
    }

    inputFile.close();
    outputFile.close();
}

void displayFileContent(const string& fileName) {
    ifstream file(fileName);

    if (!file.is_open()) {
        cout << "Cannot open file: " << fileName << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

int main()
{
    //1

    ifstream file1 ("line1.txt");
    ifstream file2("line2.txt");

    if (!file1.is_open() or !file2.is_open()) {
        cout << "File not found" << endl;
        return 1;
    }
    string line1, line2;
    bool filesMatch = true;

    cout << "=================Read file==============" << endl;
    cout << endl;
    while (getline(file1, line1) && getline(file2, line2)) {
        if (line1 != line2) {
            cout << "Mismatch found:" << endl;
            cout << "File1: " << line1 << endl;
            cout << "File2: " << line2 << endl;
            filesMatch = false;
        }
    }

  
    if ((getline(file1, line1) && !file1.eof()) || (getline(file2, line2) && !file2.eof())) {
        cout << "Files have different number of lines." << endl;
        filesMatch = false;
    }

    if (filesMatch) {
        cout << "Files match." << endl;
    }

    file1.close();
    file2.close();

    //2

    ofstream inputFile("input.txt");
    ifstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open())  {
        cout << "Cannot open input file" << endl;
        return 1;
    }

    int charCount = 0;
    int lineCount = 0;
    int vowelCount = 0;
    int consonantCount = 0;
    int digitCount = 0;

    string line;
    while (getline(outputFile, line)) {
        lineCount++;
        for (size_t i = 0; i < line.size(); ++i) {
            char c = line[i];
            if (!isspace(c)) {
                charCount++;
                if (isdigit(c)) {
                    digitCount++;
                }
                else if (isVowel(c)) {
                    vowelCount++;
                }
                else if (isConsonant(c)) {
                    consonantCount++;
                }
            }
        }
    }
    

    inputFile << "Number of characters: " << charCount << endl;
    inputFile << "Number of lines: " << lineCount << endl;
    inputFile << "Number of vowels: " << vowelCount << endl;
    inputFile << "Number of consonants: " << consonantCount << endl;
    inputFile << "Number of digits: " << digitCount << endl;

    inputFile.close();
    outputFile.close();
		
    //3
    string inputFileName = "TextOrigin.txt";
    string outputFileName = "TextShift.txt";
    int key = 3; 

    caesarCipher(inputFileName, outputFileName, key);
    cout << "===================================================" << endl;
    cout << "Original File Content:" << endl;
    displayFileContent(inputFileName);

    cout << "\nEncrypted File Content:" << endl;
    displayFileContent(outputFileName);






    
}

