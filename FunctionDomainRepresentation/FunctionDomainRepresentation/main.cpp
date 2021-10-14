#include <iostream>
#include <vector>
#include <string>


struct IIntervalValue
{
	virtual std::string to_string() = 0;
};

class Value : public IIntervalValue
{
public:
	Value(const long double& value)
	{
		this->value = value;
	}

	virtual std::string to_string()
	{
		return std::to_string(value);
	}
private:
	long double value;
};

class ExtremeValue : public IIntervalValue
{
public:
	ExtremeValue(bool isPositive)
	{
		this->isPositive = isPositive;
	}

	virtual std::string to_string()
	{
		if (isPositive) return "+Infinity";
		else		    return "-Infinity";
	}
private:
	bool isPositive;
};

class Interval
{
public:
	Interval(IIntervalValue* min, IIntervalValue* max)
	{
		this->min = min;
		this->max = max;
	}

	~Interval()
	{
		if (min) delete min;
		if (max) delete max;
	}

	std::string to_string()
	{
		return "[" + min->to_string() + "," + max->to_string() + "]";
	}
private:
	IIntervalValue* min;
	IIntervalValue* max;
};

class FunctionDomain 
{
public:
	void add(Interval interval)
	{
		domain.push_back(interval);
	}

	std::string to_string()
	{
		std::string output;
		for (unsigned i = 0;i < domain.size() - 1;i++)
		{
			output += domain.at(i).to_string() + ", ";
		}
		output += domain.at(domain.size() - 1).to_string();
		return output;
	}
private:
	std::vector<Interval> domain;
};

struct A
{
	float& getValue()
	{
		return value;
	}

	float value;
};


int main()
{
	A a = { 32 };
	a.getValue() = 45;
	std::cout << a.value << std::endl;




	/*
	FunctionDomain functionDomain;

	Interval i1 = Interval(new ExtremeValue(false), new Value(10));
	Interval i2 = Interval(new Value(12), new Value(15));
	Interval i3 = Interval(new Value(20), new ExtremeValue(true));

	functionDomain.add(i1);
	functionDomain.add(i2);
	functionDomain.add(i3);
	std::cout << functionDomain.to_string() << std::endl;
	*/
}