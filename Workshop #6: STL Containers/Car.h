/**********************************************************
* Name: Xuewei Sheng
* Student ID : 061745121
* Seneca email : xsheng3@myseneca.ca
* Section: NCC
* Date: 2021-07-08
* *********************************************************/
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#ifndef CAR_H
#define CAR_H
#include <iostream>
#include "Vehicle.h"

extern char tag; //declare a external linkage for checking type of vehicles in Utilities

namespace sdds {	
	enum class Condition {
		newc,
		used,
		broken
	};
	class Car : public Vehicle {
		std::string m_maker{};
		Condition m_condition{Condition::newc};
		double m_topSpeed{ 0.0 };
	public:
		Car(std::istream& in);
		std::string condition()const;
		double topSpeed()const;
		void display(std::ostream& out) const;
};
}
#endif // !CAR_H

