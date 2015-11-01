#ifndef BOND_H
#define BOND_H

class Bond
{
    public:
		Bond(double facevalue, double expiryT);
        double GetPrice(double rater) const;
        double Payoff() const;
        double GetExpiry() const;
    protected:
    private:
        double facevalue;
        double expiryT;
};

#endif // BOND_H
