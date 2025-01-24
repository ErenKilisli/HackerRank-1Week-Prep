#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'legoBlocks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 */

int legoBlocks(int height, int width)
{
    int modulo = 1000000007;
    vector<long long> row(width + 1, 0);
    vector<long long> total(width + 1, 0);
    vector<long long> solid (width + 1, 0);

    if (width >= 1) row[1] = 1;
    if (width >= 2) row[2] = 2;
    if (width >= 3) row[3] = 4;
    if (width >= 4) row[4] = 8;
    if (width >= 5)
    {
        for (int i = 5; i < width + 1; i++)
        {
            row[i] = (row[i - 1] + row[i - 2] + row[i - 3] + row[i - 4]) % modulo;
        }
    }

    total = row;
    
    for (int h = 2; h <= height; h++) 
    {
        for (int i = 0; i <= width; i++) 
        {
            total[i] = (row[i] * total[i]) % modulo;
        }
    }
    
    solid[1] = 1;
    
    for (int ww = 2; ww <= width; ww++) 
    {
        long long unsolid_sum = 0;
        for (int i = 1; i < ww; i++) 
        {
            unsolid_sum = (unsolid_sum + (solid[i] * total[ww-i]) % modulo) % modulo;
        }
        solid[ww] = (total[ww] - unsolid_sum + modulo) % modulo;
    }
    
    return solid[width];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int result = legoBlocks(n, m);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
