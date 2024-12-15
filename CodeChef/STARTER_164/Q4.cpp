#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'steadyGene' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING gene as parameter.
 */

bool f(int x, string gene){ //will tell if it is possible to replace that length of the sub sequence to make it steady
    int n = gene.length();
    if(x >= n){
        return true;
    }
    int countA = 0, countT = 0, count
    
}

int steadyGene(string gene) {

    
    int lo = 0, hi = 1e6;
    while(lo < hi){
        int mid = (lo + hi)/2;
        if(f(mid, gene)){ // it is possible with this length
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    return hi; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string gene;
    getline(cin, gene);

    int result = steadyGene(gene);

    fout << result << "\n";

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
