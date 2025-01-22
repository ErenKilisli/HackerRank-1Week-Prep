#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int input;
    std::cin >> input;
    
    string s = "";
    vector<string>history;
    
    while (input--) {
        int switcher;
        cin >> switcher;
        
        switch(switcher) {
            case 1: {
            string newEntry;
            std::cin >> newEntry;
            history.push_back(s);
            s += newEntry;
            break;
        }
        

            case 2: {
            int deleteEntry;
            std::cin >> deleteEntry;
            history.push_back(s);
            s = s.substr(0, s.length() - deleteEntry);
            break;
        }
        

            case 3: {
            int print;
            std::cin >> print;
            std::cout << s[print - 1] << endl;
            break;
        }
            case 4: {
            if(!history.empty()) {
            s = history.back();  
            history.pop_back();  
            }
            break;
        }
        }
    }
    return 0;
}
