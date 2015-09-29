#include "EuropeanCallOption.h"
#include "Random.h"
#include <cmath>
#include <algorithm>

/*EuropeanCallOption::EuropeanCallOption()
{
    //ctor
}
*/

EuropeanCallOption::EuropeanCallOption(double strikeK)
{
    this->strikeK = strikeK;
}

double EuropeanCallOption::GetPrice(double expiryT, double rater, double dividend, double spot, double sigma) const
{
	double d1=(std::log(spot/strikeK)+(rater-dividend+1/2*std::pow(sigma,2))*expiryT)/(sigma*std::sqrt(expiryT));
	double d2=d1-sigma*std::sqrt(expiryT);
//	double d2=(std::log(spot/strikeK)+(rater-dividend-1/2*std::pow(sigma,2))*expiryT)/(sigma*std::sqrt(expiryT));
	return spot*std::exp(-dividend*expiryT)*Random::CumulativeNormal(d1) - strikeK*std::exp(-rater*expiryT)*Random::CumulativeNormal(d2);
    
}

double EuropeanCallOption::Payoff(double currentspot)
{
	return std::max(0.0,currentspot-strikeK);
}
