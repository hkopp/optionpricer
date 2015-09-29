#ifndef ABSTRACTDERIVATIVE_H
#define ABSTRACTDERIVATIVE_H


class AbstractDerivative
{
    public:
        AbstractDerivative();
        virtual double GetPrice(double expiryT, double rater, double dividend, double spot, double sigma) const = 0; //pure virtual function which has to be implemented
        virtual double Payoff(double currentspot) = 0;
    protected:
    private:
};

#endif // ABSTRACTDERIVATIVE_H
