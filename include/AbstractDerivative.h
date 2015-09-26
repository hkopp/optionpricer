#ifndef ABSTRACTDERIVATIVE_H
#define ABSTRACTDERIVATIVE_H


class AbstractDerivative
{
    public:
        AbstractDerivative();
        float T; //expiry
        float r; //continuously compounding rate
        float d; //dividend rate
        float K; //strike price
        float S; //spot
        float sigma; //volatility
        virtual float GetPrice() = 0; //pure virtual function which has to be implemented
        virtual float Payoff(float S) = 0;
    protected:
    private:
};

#endif // ABSTRACTDERIVATIVE_H
