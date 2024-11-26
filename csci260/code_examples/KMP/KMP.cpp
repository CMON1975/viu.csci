#include <iostream>
#include <string>
using namespace std;

// f[j] is the length of the longest prefix of p
// that is a suffix of p[1..j], f[0] = 0
// Bootstrapping Method
void failure(int f[], const string & p)
{
    f[0] = 0;
    int i = 1; int j = 0;
    int lenp = p.length();
    
    while (i < lenp) {
        if (p[j] == p[i]) {
            f[i] = j+1;
            i++; j++;
        } else if (j > 0) {
            j = f[j-1];
        } else {
            f[i] = 0;
            i++;
        }
    }

    // print the failure function
    cout << "Failure function for pattern \"" << p << "\": ";
    for (int k = 0; k < lenp; ++k) {
        cout << f[k] << " ";
    }
    cout << endl;
}

int KMPSearch(const string & s, const string & p)
{
    int lens = s.length();
    int lenp = p.length();
    int f[lenp]; 
    failure(f, p);
    int i = 0;
    int j = 0;
    while (i < lens) {
        if (s[i] == p[j]) {
            if (j == lenp -1)
                return i-lenp+1;
            else {
                i++; j++;
            }
        } else if (j > 0) {
            j = f[j-1];
        } else {
            i++;
        }
    }
    return -1;
}

int main() {
    string pattern;
    
    cout << "Enter the pattern: ";
    getline(cin, pattern);

    // failure array
    int lenp = pattern.length();
    int f[lenp];

    // compute and display the failure function
    failure(f, pattern);

    return 0;    
}