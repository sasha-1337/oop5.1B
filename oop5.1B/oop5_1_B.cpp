#include "Money.h"
#include "MyException.h"

double Divide(Money& sum1, Money& sum2)
{
	if (sum1 == sum2)
		throw "sum1 = sum2 ARE_EQUAL";
	return sum1 / sum2;
}

int main()
{
	Money sum1, sum2, x;
	cout << " -------- FIRST SUMM -------- " << endl;
	cin >> sum1;
	cout << " -------- SECOND SUMM -------- " << endl;
	cin >> sum2;

	cout << " -------- FIRST SUMM -------- " << endl;
	cout << sum1;
	cout << " TOTAL - " << sum1.get_sum() << endl << endl;

	cout << " -------- SECOND SUMM -------- " << endl;
	cout << sum2;
	cout << " TOTAL - " << sum2.get_sum() << endl << endl;

	if (sum1 > sum2)
		cout << " SUMM1 > SUMM2 " << endl;
	else
		if (sum1 < sum2)
			cout << " SUMM1 < SUMM2 " << endl;
		else
			if (sum1 == sum2)
				cout << " SUMM1 == SUMM2 " << endl;
	try
	{
		cout << " DIVIDE = " << setprecision(3) << Divide(sum1, sum2) << endl;
	}
	catch (const char* div)
	{
		cout << div << endl;
	}
	try
	{
		x.Divide(-2, 20);
	}
	catch (MyException e)
	{
		cout << e.What() << endl;
	}

	try
	{
		x.Divide(20, 0);
	}
	catch (bad_exception& e)
	{
		cout << " Error [1] & " << e.what() << endl;
	}

	try
	{
		x.Divide(20, -2);
	}
	catch (bad_exception* e)
	{
		cout << " Error [2] * " << e->what() << endl;
	}

	return 0;
}