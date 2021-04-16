#include "Money.h"
#include "MyException.h"
Money::Money()
{
	g1000 = 0;
	g500 = 0;
	g200 = 0;
	g100 = 0;
	g50 = 0;
	g20 = 0;
	g10 = 0;
	g5 = 0;
	g2 = 0;
	g1 = 0;
	c50 = 0;
	c10 = 0;
}
Money::Money(double gg1000, double gg500, double gg200, double gg100, double gg50, double gg20, double gg10, double gg5, double gg2, double gg1, double cc50, double cc10)
{
	g1000 = gg1000;
	g500 = gg500;
	g200 = gg200;
	g100 = gg100;
	g50 = gg50;
	g20 = gg20;
	g10 = gg10;
	g5 = gg5;
	g2 = gg2;
	g1 = gg1;
	c50 = cc50;
	c10 = cc10;
}
Money::Money(const Money& r)
{
	g1000 = r.g1000;
	g500 = r.g500;
	g200 = r.g200;
	g100 = r.g100;
	g50 = r.g50;
	g20 = r.g20;
	g10 = r.g10;
	g5 = r.g5;
	g2 = r.g2;
	g1 = r.g1;
	c50 = r.c50;
	c10 = r.c10;
}
Money::~Money() {}

Money& Money::operator = (const Money& r)
{
	Money t(r.GetG1000(), r.GetG500(), r.GetG200(), r.GetG100(), r.GetG50(), r.GetG20(), r.GetG10(), r.GetG5(), r.GetG2(), r.GetG1(), r.GetC50(), r.GetC10());
	return *this;
}

bool Money::Init(double gg1000, double gg500, double gg200, double gg100, double gg50, double gg20, double gg10, double gg5, double gg2, double gg1, double cc50, double cc10)
{
	if (gg1000 > 0)
	{
		SetG1000(gg1000);
		return true;
	}
	else
		return false;
	if (gg500 > 0)
	{
		SetG500(gg500);
		return true;
	}
	else
		return false;
	if (gg200 > 0)
	{
		SetG200(gg200);
		return true;
	}
	else
		return false;
	if (gg100 > 0)
	{
		SetG100(gg100);
		return true;
	}
	else
		return false;
	if (gg50 > 0)
	{
		SetG50(gg50);
		return true;
	}
	else
		return false;
	if (gg20 > 0)
	{
		SetG20(gg20);
		return true;
	}
	else
		return false;
	if (gg10 > 0)
	{
		SetG10(gg10);
		return true;
	}
	else
		return false;
	if (gg5 > 0)
	{
		SetG5(gg5);
		return true;
	}
	else
		return false;
	if (gg2 > 0)
	{
		SetG2(gg2);
		return true;
	}
	else
		return false;
	if (gg1 > 0)
	{
		SetG1(gg1);
		return true;
	}
	else
		return false;
	if (cc50 > 0)
	{
		SetC50(cc50);
		return true;
	}
	else
		return false;
	if (cc10 > 0)
	{
		SetC10(cc10);
		return true;
	}
	else
		return false;
}

istream& operator >> (istream& in, Money& a)
{
	double gg1000, gg500, gg200, gg100, gg50, gg20, gg10, gg5, gg2, gg1, cc50, cc10;
	do {
		cout << " 1000 - ? "; in >> gg1000;
		cout << " 500 - ? "; in >> gg500;
		cout << " 200 - ? "; in >> gg200;
		cout << " 100 - ? "; in >> gg100;
		cout << " 50 - ? "; in >> gg50;
		cout << " 20 - ? "; in >> gg20;
		cout << " 10 - ? "; in >> gg10;
		cout << " 5 - ? "; in >> gg5;
		cout << " 2 - ? "; in >> gg2;
		cout << " 1 - ? "; in >> gg1;
		cout << " 0.50 - ? "; in >> cc50;
		cout << " 0.10 - ? "; in >> cc10;
		if (!a.Init(gg1000, gg500, gg200, gg100, gg50, gg20, gg10, gg5, gg2, gg1, cc50, cc10))
		{
			cout << endl << " Error! Enter right number. " << endl;
		}
		cout << endl;
	} while (!a.Init(gg1000, gg500, gg200, gg100, gg50, gg20, gg10, gg5, gg2, gg1, cc50, cc10));
	a.SetG1000(gg1000); a.SetG500(gg500); a.SetG200(gg200); a.SetG100(gg100); a.SetG50(gg50);
	a.SetG20(gg20); a.SetG10(gg10); a.SetG5(gg5); a.SetG2(gg2); a.SetG1(gg1); a.SetC50(cc50); a.SetC10(cc10);
	cout << endl;
	return in;
}

Money::operator string () const
{
	stringstream sstr;
	sstr << " 1000 - " << GetG1000() * 1000. << endl;
	sstr << " 500 - " << GetG500() * 500. << endl;
	sstr << " 200 - " << GetG200() * 200. << endl;
	sstr << " 100 - " << GetG100() * 100. << endl;
	sstr << " 50 - " << GetG50() * 50. << endl;
	sstr << " 20 - " << GetG20() * 20. << endl;
	sstr << " 10 - " << GetG10() * 10. << endl;
	sstr << " 5 - " << GetG5() * 5. << endl;
	sstr << " 2 - " << GetG2() * 2. << endl;
	sstr << " 1 - " << GetG1() * 1. << endl;
	sstr << " 0.50 - " << GetC50() * 0.5 << endl;
	sstr << " 0.10 - " << GetC10() * 0.1 << endl;
	return sstr.str();
}

ostream& operator << (ostream& out, const Money& r)
{
	out << string(r);
	return out;
}

double Money::get_sum()
{
	return (GetG1000() * 1000. + GetG500() * 500. + GetG200() * 200. + GetG100() * 100. + GetG50() * 50. +
		GetG20() * 20. + GetG10() * 10. + GetG5() * 5. + GetG2() * 2. + GetG1() * 1. + GetC50() * 0.50 + GetC10() * 0.1);
}

double operator / (Money& a, Money& b)
{
	if (a > b)
		return a.get_sum() / b.get_sum();
	else
		if (a < b)
			return  b.get_sum() / a.get_sum();
}

double Money::Divide(double sum1, double sum2)
{
	if (sum2 == 0)
		throw bad_exception();
	if (sum1 < 0)
		throw MyException(" Error [0]  MyException ");
	bad_exception* t = new bad_exception;
	if (sum2 < 0)
		throw t;
	return sum1 / sum2;
}

bool operator > (Money& a, Money& b)
{
	if (a.get_sum() > b.get_sum())
		return true;
	else
		return false;
}

bool operator < (Money& a, Money& b)
{
	if (a.get_sum() < b.get_sum())
		return true;
	else
		return false;
}

bool operator == (Money& a, Money& b)
{
	if (a.get_sum() == b.get_sum())
		return true;
	else
		return false;
}