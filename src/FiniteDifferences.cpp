#include "FiniteDifferences.h"
#include "AbstractDerivative.h"
#include "BlackScholesFormulas.h"

//double FiniteDifferences::Delta(const AbstractDerivative& Derivative, double rater, double dividend, double spot, double sigma, double epsilon)
template <class Derivative_Type> double FiniteDifferences<Derivative_Type>::Delta(Derivative_Type Derivative, double rater, double dividend, double spot, double sigma, double epsilon)
{
	double price_left = BlackScholesFormulas::GetPrice(rater, dividend, spot-epsilon, sigma, Derivative);
	double price_right= BlackScholesFormulas::GetPrice(rater, dividend, spot+epsilon, sigma, Derivative);
	return (price_right-price_left)/(2*epsilon);
}
