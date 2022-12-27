#include <string>
#include <iostream>
using namespace std;

int main()
{
    string s = "hello";
    if (s.length())
        cout << "s is not empty" << endl;
    else
        cout << "s is empty" << endl;

    cout << s[0] << endl;
    return 0;
}