#include <iostream>
#include <locale.h>

using namespace std;

int main(int argc, char ** argv)
{
    setlocale(LC_ALL, "");
    string inpStr;
    cout << "�rj be egy sz�veget: ";
    cin >> inpStr;
    // vagy getline(cin, inpStr);
    cout << "Be�rt sz�veg: " << inpStr << endl;
    return 0;
}
