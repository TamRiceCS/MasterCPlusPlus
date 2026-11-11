#include <iostream>
class Fraction
{
    int numerator = 0;
    int denominator = 0;
    bool validity = false;

public:
    Fraction() = default;
    Fraction(int n, int d) : Fraction{n, d, false}
    {
        if (d != 0)
        {
            validity = true;
        }
    }
    Fraction(int n, int d, bool v) : numerator{n}, denominator{d}, validity{v}
    {
        if (d != 0)
        {
            validity = true;
        }
    }

    // overload cout, make it const not changing anything
    friend std::ostream &operator<<(std::ostream &out, const Fraction base);
    // can define a friend here, not a member
    friend std::istream &operator>>(std::istream &in, Fraction &base)
    {

        int a = 0;
        int b = 0;
        if (in >> a >> b)
        {
            base = Fraction(a, b);
        }
        return in;
    }

    // Not true fraction addition
    Fraction operator+(const Fraction &other)
    {
        return Fraction(this->numerator + other.numerator, this->denominator + other.denominator);
    }

    friend bool operator==(const Fraction &lhs, const Fraction &rhs);

    // ++Instance
    Fraction &operator++()
    {
        numerator += 1;
        return *this;
    }

    // Instance++
    Fraction operator++(int)
    {
        Fraction temp = *this; // make a copy
        ++(this->numerator);
        return temp; // return copy before add, while the original is incremented up
    }

    operator double const()
    {
        if (validity)
        {
            return (double)numerator / (double)denominator;
        }
        return (double)-1.0;
    }
};

std::ostream &operator<<(std::ostream &out, const Fraction base)
{
    out << base.numerator << "/" << base.denominator;

    if (base.validity)
    {
        out << " and is valid" << std::endl;
    }
    else
    {
        out << " and isn't valid" << std::endl;
    }

    return out;
}

bool operator==(const Fraction &lhs, const Fraction &rhs)
{
    if (lhs.numerator == rhs.numerator && lhs.denominator == rhs.denominator)
    {
        return true;
    }
    return false;
}
