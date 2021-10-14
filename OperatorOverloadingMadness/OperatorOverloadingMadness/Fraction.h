#include <iostream>

class Fraction
{
public:
	Fraction(const float& _num,const float& _den);
	Fraction(const Fraction& _fraction);

	bool operator==(const Fraction& _rhs);
	Fraction operator+(const Fraction& _rhs);
	friend std::ostream& operator<<(std::ostream& os, const Fraction& _rhs);
private:
	float m_num;
	float m_den;
};