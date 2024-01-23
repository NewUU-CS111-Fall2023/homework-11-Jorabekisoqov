#include <iostream>
#include <unordered_map>

using namespace std;
class Problem5{
string decodeMessage(const string& key, const string& message) {
    // Create a substitution table
    unordered_map<char, char> substitutionTable;
    int keyIndex = 0;

    for (char c : key) {
        if (isalpha(c)) {
            if (isupper(c)) {
                substitutionTable[c] = 'A' + keyIndex;
            } else {
                substitutionTable[c] = 'a' + keyIndex;
            }
            keyIndex++;
        }
    }

    // Create a mapping for the remaining characters in the alphabet
    for (char c = 'a'; c <= 'z'; c++) {
        if (substitutionTable.find(c) == substitutionTable.end()) {
            substitutionTable[c] = c;
        }
    }

    // Decode the message using the substitution table
    string decodedMessage;
    for (char c : message) {
        if (isalpha(c)) {
            decodedMessage += substitutionTable[c];
        } else {
            decodedMessage += c;
        }
    }

    return decodedMessage;
}


};