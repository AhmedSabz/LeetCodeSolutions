#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to check if a character is a vowel
bool isVowel(char c) {
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    for (char vowel : vowels) {
        if (c == vowel) {
            return true;
        }
    }
    return false;
}

// Recursive function to generate combinations of consonants
void backtrack(const string &s, string &curr_str, int curr_start, vector<string> &combinations) {
    // Base case: If the current start position exceeds the length of the string
    if (curr_start == s.length()) {
        return;
    }
    for (int i = curr_start; i < s.length(); i++) {
        if (isVowel(s[i])) {
            continue;
        }
        curr_str += s[i];
        combinations.push_back(curr_str);
        backtrack(s, curr_str, i + 1, combinations);
        curr_str.pop_back();
    }
}

// Function to get all consonant combinations
vector<string> getConsonantCombinations(const string &s) {
    if (s.empty()) {
        return {};
    }
    vector<string> combinations;
    string start_str = "";
    backtrack(s, start_str, 0, combinations);
    return combinations;
}

int main() {
    string input = "str";
    vector<string> result = getConsonantCombinations(input);

    for (const string &comb : result) {
        cout << comb << endl;
    }

    return 0;
}
