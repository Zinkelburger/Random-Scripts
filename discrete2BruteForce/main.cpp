#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cctype>
using namespace std;

bool isAllLowercase(const std::string& str) {
    return std::all_of(str.begin(), str.end(), [](char c){ return islower(c); });
}

int main(){
    //read the input, sort it from smallest to largest. cout the words to bash so the bash script can run qpdf on them
    string input;

    // Define a lambda function as the comparison function
    auto compare = [](const pair<string, int>& lhs, const pair<string, int>& rhs) {
        return lhs.second > rhs.second;
    };

    //decltype and passing compare to wordQueue comes from bing chat debugging. 
    //"decltype can be used to inspect the declared type of an entity or the type and value category of an expression."
    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(compare)> wordQueue(compare);
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
    
    //move the map into the priority queue
    for(auto& e: wordMap){
        //I am not using the map again, so I move instead of copy
        wordQueue.push(move(e));
    }

    //can't use range based for loop because queue does not have begin & end iterators
    while(wordQueue.size() > 0){
        //the bash script is outputing to a file, so the code outputs the strings to a file
        //in the order of smallest to largest
        cout << wordQueue.top().first << "\n";
        wordQueue.pop();
    }

    return 0;    
}
