#pragma once

#include <iostream>
#include <string>

using namespace std;


class separate_the_numbers
{
public:
    bool dfs(string& s, string& target) {

        if (s.size() < target.size())
            return false;

        if (s == target)
            return true;

        for (int i = 0; i < target.size(); i++) {
            if (s[i] != target[i])
                return false;
        }

        string new_s = s.substr(target.size());
        long long nt = stoll(target) + 1;
        string new_target = to_string(nt);
        return dfs(new_s, new_target);
    }

    void separateNumbers(string s) {
        int n = s.size();
        if (n == 1) {
            cout << "NO" << endl;
            return;
        }

        for (int len = 1; len <= n / 2; len++) {
            string f = s.substr(0, len);
            bool res = dfs(s, f);
            if (res) {
                cout << "YES " << f << endl;
                return;
            }
        }

        cout << "NO" << endl;
    }

    void do_test(separate_the_numbers* sol) {
        
        sol->separateNumbers("1234");
        // Output: YES 1

        sol->separateNumbers("91011");
        // Output: YES 9

        sol->separateNumbers("99100");
        // Output: YES 99

        sol->separateNumbers("101103");
        // Output: NO

        sol->separateNumbers("010203");
        // Output: NO

        sol->separateNumbers("13");
        // Output: NO

        sol->separateNumbers("1");
        // Output: NO

        sol->separateNumbers("73747576777879808182838485868788");
        // Output: YES 73

        sol->separateNumbers("73747576777879808182838485868778");
        // Output: NO

        sol->separateNumbers("29303132333435363738394041424344");
        // Output: YES 29

        sol->separateNumbers("29303132333435363738394041424244");
        // Output: NO

        sol->separateNumbers("16171819202122232425262728293031");
        // Output: YES 16

        sol->separateNumbers("16171819202122232425262728292031");
        // Output: NO

        sol->separateNumbers("60616263646566676869707172737475");
        // Output: YES 60

        sol->separateNumbers("60616263646566676869707172727475");
        // Output: NO

        sol->separateNumbers("90919293949596979899100101102103");
        // Output: YES 90

        sol->separateNumbers("90919293949596979899100101002103");
        // Output: NO
    }
};
