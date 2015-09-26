#include <iostream>
#include "include/Forward.h"
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
    Forward f (1.0,2.0,3.0,4.0,5.0,1.0);
    cout << f.GetPrice() << endl;
    return 0;
}
