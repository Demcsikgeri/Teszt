#include <iostream>
#include <locale.h>

using namespace std;

int main(int argc, char ** argv)
{
    setlocale(LC_ALL, "");
    cout << "Szia Vil�g!\n";
    cerr << "Hello World!" << endl;
    return 0;
}
