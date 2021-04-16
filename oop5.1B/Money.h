#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>
#include <exception>

using namespace std;

class Money 
{
private:
	double g1000, g500, g200, g100, g50, g20, g10, g5, g2, g1, c50, c10;
public:
	Money();
	Money(double, double, double, double, double, double, double, double, double, double, double, double);
	Money(const Money&);
	~Money();

	double GetG1000() const { return g1000; }
	double GetG500() const { return g500; }
	double GetG200() const { return g200; }
	double GetG100() const { return g100; }
	double GetG50() const { return g50; }
	double GetG20() const { return g20; }
	double GetG10() const { return g10; }
	double GetG5() const { return g5; }
	double GetG2() const { return g2; }
	double GetG1() const { return g1; }
	double GetC50() const { return c50; }
	double GetC10() const { return c10; }

	void SetG1000(double value) { g1000 = value; }
	void SetG500(double value) { g500 = value; }
	void SetG200(double value) { g200 = value; }
	void SetG100(double value) { g100 = value; }
	void SetG50(double value) { g50 = value; }
	void SetG20(double value) { g20 = value; }
	void SetG10(double value) { g10 = value; }
	void SetG5(double value) { g5 = value; }
	void SetG2(double value) { g2 = value; }
	void SetG1(double value) { g1 = value; }
	void SetC10(double value) { c10 = value; }
	void SetC50(double value) { c50 = value; }

	bool Init(double gg1000, double gg500, double gg200, double gg100, double gg50, double gg20, double gg10, double gg5, double gg2, double gg1, double cc50, double cc10);
	double get_sum();

	Money& operator = (const Money&);
	operator string() const;
	friend ostream& operator << (ostream&, const Money&);
	friend istream& operator >> (istream&, Money&);
	friend double operator / (Money&, Money&);
	friend bool operator > (Money& a, Money& b);
	friend bool operator < (Money& a, Money& b);
	friend bool operator == (Money& a, Money& b);
	double Divide(double sum1, double sum2);
};

