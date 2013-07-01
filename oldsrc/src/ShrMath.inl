
//----------------------------------------------------------------------------
template <typename Real>
Real Math<Real>::ACos (Real value)
{
    if (-(Real)1 < value)
    {
        if (value < (Real)1)
        {
            return acos(value);
        }
        else
        {
            return (Real)0;
        }
    }
    else
    {
        return PI;
    }
}
//----------------------------------------------------------------------------
template <typename Real>
Real Math<Real>::ASin (Real value)
{
    if (-(Real)1 < value)
    {
        if (value < (Real)1)
        {
            return asin(value);
        }
        else
        {
            return HALF_PI;
        }
    }
    else
    {
        return -HALF_PI;
    }
}
//----------------------------------------------------------------------------
template <typename Real>
Real Math<Real>::ATan (Real value)
{
    return atan(value);
}
//----------------------------------------------------------------------------
template <typename Real>
Real Math<Real>::ATan2 (Real y, Real x)
{
    if (x != (Real)0 || y != (Real)0)
    {
        return atan2(y, x);
    }
    else
    {
        // Mathematically, ATan2(0,0) is undefined, but ANSI standards
        // require the function to return 0.
        return (Real)0;
    }
}
//----------------------------------------------------------------------------
template <typename Real>
Real Math<Real>::Ceil (Real value)
{
    return ceil(value);
}
//----------------------------------------------------------------------------
template <typename Real>
Real Math<Real>::Cos (Real value)
{
    return cos(value);
}
//----------------------------------------------------------------------------
template <typename Real>
Real Math<Real>::Exp (Real value)
{
    return exp(value);
}
//----------------------------------------------------------------------------
template <typename Real>
Real Math<Real>::FAbs (Real value)
{
    return fabs(value);
}
//----------------------------------------------------------------------------
template <typename Real>
Real Math<Real>::Floor (Real value)
{
    return floor(value);
}
//----------------------------------------------------------------------------
template <typename Real>
Real Math<Real>::FMod (Real x, Real y)
{
    if (y != (Real)0)
    {
        return fmod(x, y);
    }
    else
    {
        assertion(false, "Zero input to FMod\n");
        return (Real)0;
    }
}
//----------------------------------------------------------------------------
template <typename Real>
Real Math<Real>::InvSqrt (Real value)
{
    if (value != (Real)0)
    {
        return ((Real)1)/sqrt(value);
    }
    else
    {
        assertion(false, "Division by zero in InvSqr\n");
        return (Real)0;
    }
}
//----------------------------------------------------------------------------
template <typename Real>
Real Math<Real>::Log (Real value)
{
    if (value > (Real)0)
    {
        return log(value);
    }
    else
    {
        assertion(false, "Nonpositive input to Log\n");
        return (Real)0;
    }
}
//----------------------------------------------------------------------------
template <typename Real>
Real Math<Real>::Log2 (Real value)
{
    if (value > (Real)0)
    {
        return Math<Real>::INV_LN_2 * log(value);
    }
    else
    {
        assertion(false, "Nonpositive input to Log2\n");
        return (Real)0;
    }
}
//----------------------------------------------------------------------------
template <typename Real>
Real Math<Real>::Log10 (Real value)
{
    if (value > (Real)0)
    {
        return Math<Real>::INV_LN_10 * log(value);
    }
    else
    {
        assertion(false, "Nonpositive input to Log10\n");
        return (Real)0;
    }
}
//----------------------------------------------------------------------------
template <typename Real>
Real Math<Real>::Pow (Real base, Real exponent)
{
    if (base >= (Real)0)
    {
        return pow(base, exponent);
    }
    else
    {
        assertion(false, "Negative base not allowed in Pow\n");
        return Math<Real>::MAX_REAL;
    }
}
//----------------------------------------------------------------------------
template <typename Real>
Real Math<Real>::Sin (Real value)
{
    return sin(value);
}
//----------------------------------------------------------------------------
template <typename Real>
Real Math<Real>::Sqr (Real value)
{
    return value*value;
}
//----------------------------------------------------------------------------
template <typename Real>
Real Math<Real>::Sqrt (Real value)
{
    if (value >= (Real)0)
    {
        return sqrt(value);
    }
    else
    {
        assertion(false, "Negative input to Sqrt\n");
        return (Real)0;
    }
}
//----------------------------------------------------------------------------
template <typename Real>
Real Math<Real>::Tan (Real value)
{
    return tan(value);
}
//----------------------------------------------------------------------------
template <typename Real>
int Math<Real>::Sign (int value)
{
    if (value > 0)
    {
        return 1;
    }

    if (value < 0)
    {
        return -1;
    }

    return 0;
}
//----------------------------------------------------------------------------
template <typename Real>
Real Math<Real>::Sign (Real value)
{
    if (value > (Real)0)
    {
        return (Real)1;
    }

    if (value < (Real)0)
    {
        return (Real)-1;
    }

    return (Real)0;
}
//----------------------------------------------------------------------------