#include "Fraction.h"

Fraction::Fraction(const float& _num, const float& _den)
{
	this->m_num = _num;
	this->m_den = _den;
}

Fraction::Fraction(const Fraction& _fraction)
{
	this->m_num = _fraction.m_num;
	this->m_den = _fraction.m_den;
}

bool Fraction::operator==(const Fraction& _rhs)
{
	return (_rhs.m_num / this->m_num == _rhs.m_den / this->m_den);
}

Fraction Fraction::operator+(const Fraction& _rhs)
{
	if (this->m_den == _rhs.m_den)
		return Fraction(this->m_num + _rhs.m_num, this->m_den);
	return Fraction(this->m_num*_rhs.m_den + _rhs.m_num*this->m_den, this->m_den * _rhs.m_den);
}

std::ostream& operator<<(std::ostream& os, const Fraction& _rhs)
{
	return os << _rhs.m_num << "/" << _rhs.m_den << std::endl;
}