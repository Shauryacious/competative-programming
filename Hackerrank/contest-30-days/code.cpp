#include <bits/stdc++.h>
using namespace std;

const int TOTAL_TEST_CASES = 26;  
const int MAX_N = 100000, MAX_D = 100000, MAX_A = 1e9;

void compute_answer(const string &test_input, string &output) {
    stringstream ss(test_input);
    int n, d;
    ss >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        ss >> a[i];
    }

    int k = *max_element(a.begin(), a.end());
    int max_count = 0, count = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == k) count++;
        else count = 0;
        max_count = max(max_count, count);
    }

    output = to_string(max_count + d) + "\n";
}

void generate_test_case(int tc_number, int n, int d, function<void(vector<int>&)> fill_array) {
    vector<int> a(n);
    fill_array(a);

    stringstream input_ss;
    input_ss << n << " " << d << "\n";
    for (int num : a) input_ss << num << " ";
    input_ss << "\n";

    string test_input = input_ss.str();
    string output;

    compute_answer(test_input, output);

    // ✅ Proper zero-padded filenames (00, 01, 02, ..., 25)
    char input_filename[20], output_filename[20];
    sprintf(input_filename, "input%02d.txt", tc_number);
    sprintf(output_filename, "output%02d.txt", tc_number);

    ofstream input_file(input_filename);
    input_file << test_input;
    input_file.close();

    ofstream output_file(output_filename);
    output_file << output;
    output_file.close();
}

int main() {
    srand(time(0));

    int tc = 0;

    // ✅ First predefined test case
    generate_test_case(tc++, 3, 2, [](vector<int> &a) { a = {3, 2, 1}; });

    // ✅ 15 Structured test cases (Edge, small, large)
    generate_test_case(tc++, 1, 1, [](vector<int> &a) { a[0] = 1; });
    generate_test_case(tc++, 5, 3, [](vector<int> &a) { for (int &x : a) x = rand() % 10 + 1; });
    generate_test_case(tc++, 500, 50, [](vector<int> &a) { iota(a.begin(), a.end(), 1); });
    generate_test_case(tc++, 500, 50, [](vector<int> &a) { for (int i = 0; i < a.size(); i++) a[i] = 500 - i; });
    generate_test_case(tc++, 10000, 1000, [](vector<int> &a) { for (int &x : a) x = rand() % MAX_A + 1; });
    generate_test_case(tc++, 10000, 500, [](vector<int> &a) { fill(a.begin(), a.end(), MAX_A); });
    generate_test_case(tc++, 10000, 500, [](vector<int> &a) { fill(a.begin(), a.end(), MAX_A - 1); });
    generate_test_case(tc++, 10000, 1000, [](vector<int> &a) { for (int i = 0; i < a.size(); i++) a[i] = (i % 2 == 0) ? 1 : MAX_A; });
    generate_test_case(tc++, 10000, 500, [](vector<int> &a) { fill(a.begin(), a.begin() + a.size()/2, MAX_A); fill(a.begin() + a.size()/2, a.end(), 1); });
    generate_test_case(tc++, 10000, 500, [](vector<int> &a) { for (int i = 0; i < 5000; i++) a[i] = MAX_A; });
    generate_test_case(tc++, 10000, 1000, [](vector<int> &a) {
        for (int &x : a) x = rand() % MAX_A + 1;
        for (int i = 0; i < a.size(); i += (rand() % 10 + 1)) a[i] = MAX_A;
    });
    generate_test_case(tc++, MAX_N, MAX_D, [](vector<int> &a) { for (int &x : a) x = MAX_A; });
    generate_test_case(tc++, MAX_N, 1, [](vector<int> &a) { for (int &x : a) x = rand() % MAX_A + 1; });
    generate_test_case(tc++, 10, MAX_D, [](vector<int> &a) { for (int &x : a) x = rand() % MAX_A + 1; });
    generate_test_case(tc++, 10000, 1000, [](vector<int> &a) { fill(a.begin(), a.end(), 1); a[a.size() - 1] = MAX_A; });

    // ✅ 10 Randomized test cases
    for (int i = 0; i < 10; i++) {
        int n = rand() % MAX_N + 1;  
        int d = rand() % MAX_D + 1;  
        generate_test_case(tc++, n, d, [](vector<int> &a) { for (int &x : a) x = rand() % MAX_A + 1; });
    }

    cout << "All 26 test cases generated successfully (input00.txt to input25.txt).\n";
    return 0;
}


1 1 1 1 1 1 1 1 -1  

