#include <iostream>
#include <locale.h>

using namespace std;

int main(int argc, char ** argv)
{
    setlocale(LC_ALL, "");
    string inpStr;
    cout << "Írj be egy szöveget: ";
    cin >> inpStr;
    // vagy getline(cin, inpStr);
    cout << "Beírt szöveg: " << inpStr << endl;
    return 0;
}
