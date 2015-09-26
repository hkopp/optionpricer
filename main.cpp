#include <iostream>
#include "include/Random.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    cout << Random::MoroInverseCumulativeNormal(0.1) << endl;
    cout << Random::MoroInverseCumulativeNormal(0.5) << endl;
    cout << Random::MoroInverseCumulativeNormal(0.8) << endl;
    cout << Random::CumulativeNormal(0) << endl;
    cout << Random::CumulativeNormal(1) << endl;
    cout << Random::CumulativeNormal(2) << endl;
    cout << Random::CumulativeNormal(3) << endl;
    cout << Random::CumulativeNormal(10) << endl;
    return 0;
}
