#ifndef SHRPOLYNOMIAL1_H
#define SHRPOLYNOMIAL1_H

#include "ShrMathematicsLIB.h"
#include "ShrMath.h"
#include "ShrMemory.h"

namespace shr
{

template <typename Real>
class Polynomial1
{
public:
    // Construction and destruction.
    Polynomial1 (int degree = -1);
    Polynomial1 (const Polynomial1& poly);
    ~Polynomial1 ();

    // Member access.
    void SetDegree (int degree);
    inline int GetDegree () const;
    inline operator const Real* () const;
    inline operator Real* ();
    inline const Real& operator[] (int i) const;
    inline Real& operator[] (int i);

    // Assignment.
    Polynomial1& operator= (const Polynomial1& poly);

    // Evaluation of the polynomial, p(t).
    Real operator() (Real t) const;

    // Arithmetic operations.
    Polynomial1 operator+ (const Polynomial1& poly) const;
    Polynomial1 operator- (const Polynomial1& poly) const;
    Polynomial1 operator* (const Polynomial1& poly) const;
    Polynomial1 operator+ (Real scalar) const;  // input is degree 0 poly
    Polynomial1 operator- (Real scalar) const;  // input is degree 0 poly
    Polynomial1 operator* (Real scalar) const;
    Polynomial1 operator/ (Real scalar) const;
    Polynomial1 operator- () const;

    // scalar*poly
    friend Polynomial1<Real> operator* (Real scalar,
        const Polynomial1<Real>& poly)
    {
        return poly*scalar;
    }

    // Arithmetic updates.
    Polynomial1& operator += (const Polynomial1& poly);
    Polynomial1& operator -= (const Polynomial1& poly);
    Polynomial1& operator *= (const Polynomial1& poly);
    Polynomial1& operator += (Real scalar);  // input is degree 0 poly
    Polynomial1& operator -= (Real scalar);  // input is degree 0 poly
    Polynomial1& operator *= (Real scalar);
    Polynomial1& operator /= (Real scalar);

    // Compute the derivative of the polynomial.
    Polynomial1 GetDerivative () const;

    // Inversion ( invpoly[i] = poly[degree-i] for 0 <= i <= degree ).
    Polynomial1 GetInversion () const;

    // Reduce the degree by eliminating all (nearly) zero leading coefficients
    // and by making the leading coefficient one.  The input parameter is
    // the threshold for specifying that a coefficient is effectively zero.
    void Compress (Real epsilon);

    // If 'this' is P(t) and the divisor is D(t) with degree(P) >= degree(D),
    // then P(t) = Q(t)*D(t)+R(t) where Q(t) is the quotient with
    // degree(Q) = degree(P) - degree(D) and R(t) is the remainder with
    // degree(R) < degree(D).  If this routine is called with
    // degree(P) < degree(D), then Q = 0 and R = P are returned.  The value
    // of epsilon is used as a threshold on the coefficients of the remainder
    // polynomial.  If smaller, the coefficient is assumed to be zero.
    void Divide (const Polynomial1& divisor, Polynomial1& quotient,
        Polynomial1& remainder, Real epsilon) const;

protected:
    int mDegree;
    Real* mCoeff;
};

#include "ShrPolynomial1.inl"

typedef Polynomial1<float> Polynomial1f;
typedef Polynomial1<double> Polynomial1d;

}

#endif
