#include "Random.h"
#include <cmath>

# define MATH_PI           3.14159265358979323846  /* pi */

float Random::MoroInverseCumulativeNormal(float x)
{
    //Computes the inverse cumulative normal function with Moros method
    //TODO: x has to be between zero and one. How can I throw an error?

    const float a [4] = {2.50662823884, -18.61500062529, 41.39119773534, -25.44106049637};
    const float b [4] = {-8.47351093090, 23.08336743743, -21.06224101826, 3.13082909833};
    const float c [9] = {0.3374754822726147, 0.9761690190917186, 0.1607979714918209, 0.0276438810333863,
        0.0038405729373609, 0.0003951896511919, 0.0000321767881768, 0.0000002888167364, 0.0000003960315187};
        //these are the constants from the algorithm
    float y = x - 0.5;
    if (std::abs(y) < 0.42)
    {
        float r = y*y;
        float numerator = 0;
        float denominator = 1;
        //evaluate the sum in the numerator
        for (int i=0;i<=3;i++)
        {
            numerator = numerator+a[i]*std::pow(r,i);
        }
        numerator = y * numerator;

        //evaluate the sum in the denominator
        for (int j=0;j<=3;j++)
        {
            denominator = denominator + b[j]*std::pow(r,j+1);
        }

        return(numerator/denominator);
    }
    else
    {
        float r;
        if(y < 0)
        {
            r = x;
        }
        else
        {
            r = 1-x;
        }
        float s = std::log(-std::log(r));
        float t = 0;
        for(int j=0;j<=8;j++)
        {
            t = t+c[j]*std::pow(s,j);
        }
        if(x>0.5)
        {
            return t;
        }
        else
        {
            return -t;
        }
    }
}

float Random::CumulativeNormal(float x)
//Computes the cumulative normal function
{
    if(x >= 0)
    {
        float k = 1/(1+0.2316419*x);
        return(1 - 1/std::sqrt(2*MATH_PI) * std::exp(- std::pow(x,2)/2) * k*(0.319381530 + k*(-0.356563782 + k*(1.781477937 + k*(-1.821255978 + 1.330274429*k)))));
    }
    else
    {
        return 1-CumulativeNormal(-x);
    }
}
