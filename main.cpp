#include <iostream>
#include "include/Random.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
//    Random rand;
 //   cout << rand.MoroInverseCumulativeNormal(0.5) << endl;
    cout << Random::MoroInverseCumulativeNormal(0.1) << endl;
    cout << Random::MoroInverseCumulativeNormal(0.5) << endl;
    cout << Random::MoroInverseCumulativeNormal(0.8) << endl;
    return 0;
}
