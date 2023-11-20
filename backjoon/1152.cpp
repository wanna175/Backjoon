#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int Split(string str, char splitChar)
{
    int result = 0;
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, splitChar))
        if(temp!="")
            ++result;

    return result;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    getline(cin, str);
    cout << Split(str, ' ');
    return 0;
}