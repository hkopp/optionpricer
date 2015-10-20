#ifndef BOND_H
#define BOND_H

class Bond : public AbstractDerivative
{
    public:
		Bond(double strikeK, double expiryT);
        double GetPrice(double rater) const;
        double Payoff() const;
        double GetExpiry() const;
    protected:
    private:
        double strikeK;
        double expiryT;
};

#endif // BOND_H
