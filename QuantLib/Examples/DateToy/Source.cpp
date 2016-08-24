#include <iostream>
#include <ql/quantlib.hpp>
#include <math.h>

using namespace QuantLib;

void main()
{
	//create a zero coupon bond

	Date issueDate(2, October, 2014);
	Natural settlementDays = 2;
	Calendar calendar = Germany(Germany::Settlement);
	BusinessDayConvention paymentConvention = Following;
	Real faceAmount = 100;
	Real redemption = 100;
	Date maturityDate(2, October, 2016);
	ZeroCouponBond zeroBond(settlementDays, calendar, faceAmount,maturityDate, paymentConvention, redemption, issueDate);

	//calcualte yield

	Real cleanPrice = 97.5;
	DayCounter DayCounter = ActualActual(ActualActual::ISDA);
	Compounding compounding = Compounded;
	Frequency frequency = Annual;
	Real accuracy = 1.0e-15;
	Size maxEvaluations = 10000;
	Rate yield = zeroBond.yield(cleanPrice, DayCounter, compounding, frequency, zeroBond.settlementDate(issueDate), accuracy, maxEvaluations);
		std::cout << "yield from QuantLib   "<< (double)yield << "\n";
}




