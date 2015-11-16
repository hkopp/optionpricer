#include "MonteCarlo.h"
#include "AbstractDerivative.h"
#include "AbstractRNG.h"
#include <cmath>

double MonteCarlo::SimulatePrice(const AbstractDerivative& Derivative, unsigned int numberRuns, double rater, double dividend, double spot, double sigma, AbstractRNG& RNG)
{
	double expiration = Derivative.GetExpiry();
	double variancewExpiry = sigma*sigma*expiration;
	double rootVariancewexpiry = sqrt(variancewExpiry);
	double itoCorrection = -0.5*variancewExpiry;
	double movedSpot = spot*std::exp((rater-dividend)*expiration + itoCorrection);
	double thisSpot;
	double runningSum=0;
	for (unsigned int i=0; i < numberRuns; i++)
	{
		double thisGaussian = RNG.GetGaussian();
		thisSpot = movedSpot*std::exp(rootVariancewexpiry*thisGaussian);
		double thisPayoff = Derivative.Payoff(thisSpot);
		runningSum += thisPayoff;
	}
	double mean=runningSum/numberRuns;
	mean *= std::exp(-rater*expiration); //remember interest rates
	return mean;

return 0;
}
