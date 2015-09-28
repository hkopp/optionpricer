#ifndef ABSTRACTDERIVATIVE_H
#define ABSTRACTDERIVATIVE_H


class AbstractDerivative
{
    public:
        AbstractDerivative();
        virtual float GetPrice(float expiryT, float rater, float dividend, float spot, float sigma) = 0; //pure virtual function which has to be implemented
        virtual float Payoff(float currentspot) = 0;
    protected:
    private:
};

#endif // ABSTRACTDERIVATIVE_H
