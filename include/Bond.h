#ifndef BOND_H
#define BOND_H

//! A class for Bonds
/*!
 * This class provides an implementation of Bonds
 */
class Bond
{
    public:
		//! Constructor. Creates a Bond who has value facevalue at time expiryT.
		Bond(double facevalue, double expiryT);
		//! Computes the price of the bond.
        double GetPrice(double rater) const;
        //! Returns the face value of the Bond, i.e., the payoff at expiry.
        double Payoff() const;
        //! Returns the expiry time.
        double GetExpiry() const;
    protected:
    private:
        double facevalue;
        double expiryT;
};

#endif // BOND_H
