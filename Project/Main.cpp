#include <iostream>
#include <fstream>
#include <string>
#include "List.h"
using namespace std;

int main() 
{
    List l1;
    List l2;
    List l3;
    ifstream in("put.txt");
    in >> l1;
    in >> l2;
    cout << l1 << endl;
    cout << l2 << endl;

    l3 = l1.merge(l2);
    cout << l3;
    return 0;
}
