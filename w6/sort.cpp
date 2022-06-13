#include <iostream>
#include <vector>
#include <algorithm>

// TASK
// Create a custom sort function that:
//      Sort all words in reverse alphabetical order based on their first letter, regardless of case
//      If two words start with the same letter, then the shorter one should appear second.
//      In the case that two words have the same starting letter AND have the same length,
//      they can appear in any order.
bool my_custom_sort_function(std::string a, std::string b) {
    return a[0] < b[0];
}

// CHALLENGE
// Create a custom sort function that:
//      Sort all words in reverse alphabetical order based on the whole word, regardless of case
//      If one word is the suffix of another (e.g. ice & icecream) then the shorter one should appear second.
bool my_challenge_sort_function();

void custom_sort(std::vector<std::string> & words){
    sort(words.begin(), words.end(), my_custom_sort_function);
}
