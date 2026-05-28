#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream fout("data.txt");

    fout << "Hello Pakistan\n";
    fout << "File Handling Easy Hai";

    fout.close();

    return 0;
}
