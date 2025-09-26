#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inpFile;
    ofstream outFile;

    inpFile.open("test.txt");
    outFile.open("sao_csv.csv");

    string tempStr;
    char lastChar = 'a';
    bool atStart = 1;

    while(getline(inpFile, tempStr)) {
        for(char tempChar : tempStr) {
            if(tempChar != ' '  && lastChar == ' ') {
                if(!atStart) {
                    outFile << "," << tempChar;
                }
                else {
                    atStart = 0;
                    outFile << tempChar;
                }
            }
            else if(tempChar != ' ') {
                outFile << tempChar;
            }
            lastChar = tempChar;
        }
        outFile << endl;
        atStart = 1;
    }

    inpFile.close();
    outFile.close();

}