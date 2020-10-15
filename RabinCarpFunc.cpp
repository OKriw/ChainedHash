#include <string.h>
#include <iostream>
#include <string>
using namespace std;
#define d 10 //actually for alphabet it is 26, but to reduce it i use first 10 letters of alphabet

void rabinKarp(string &pattern, string &text, int q) {
    int m = pattern.size()-1;
    int n = text.size()-1;
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate hash value for pattern and text
    for (i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q; //q may be any number - it is uset to get rid of overfloating anf from falsepositive result
        t = (d * t + text[i]) % q;
    }
    // Find the match
    for (i = 0; i <= n - m; i++) {
        if (p == t) {
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) //check that it is ok
                    break;
            }
            if (j == m)
                cout << "Pattern is found at position: " << i + 1 << endl;
        }
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            if (t < 0)
                t = (t + q);
        }
    }
}
