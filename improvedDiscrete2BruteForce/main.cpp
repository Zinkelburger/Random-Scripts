#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cctype>
using namespace std;

// removed the heapify operation. I only need the words of frequency 1, I don't need to sort anything
bool isAllLowercase(const std::string& str) {
    return std::all_of(str.begin(), str.end(), [](char c){ return islower(c); });
}

int main(){
    //read the input, sort it from smallest to largest. cout the words to bash so the bash script can run qpdf on them
    string input;

    //decltype and passing compare to wordQueue comes from bing chat debugging. 
    //"decltype can be used to inspect the declared type of an entity or the type and value category of an expression."
    //priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(compare)> wordQueue(compare);
    std::unordered_map<std::string, int> wordMap;

    //read the input into the map. Insert if it doesn't contain the input, otherwise increment
    while(cin >> input){
        //the word is always an all lowercase alphanumeric word, so don't add it if it is not
        if(isAllLowercase(input)){
            unordered_map<std::string, int>::iterator exists = wordMap.find(input);
            if(exists == wordMap.end()){
                wordMap.insert({input, 1});
            } else {
                (exists->second)++;
            }
        }
    }

    for (auto& e : wordMap) {
        if (e.second == 1) {
            // the string is the first part of e
            std::cout << e.first << "\n";
        }
    }

    return 0;    
}
