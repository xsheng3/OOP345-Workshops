#include <iostream>
#include <sstream>
#include <iomanip>
#include "Car.h"

char tag = '\0';
namespace sdds {
	Car::Car(std::istream& in) {			
			//extract m_maker & erase spaces
			getline(in, m_maker, ',');
			m_maker.erase(m_maker.find_last_not_of(' ') + 1);

			//extract condition
			char condition;
			in >> condition;
			if (condition == ',')   //if empty, set to new
			{
				condition = 'n';
			}
			else if (condition == ' ')  //if space, set to new, and clear the any left space and the comma
			{
				condition = 'n';
				in.ignore(1000, ',');
			}
			else
			{
				in.ignore(1000, ',');  //extract condtion for all other charactors
			}

			if (condition != 'n' && condition != 'u' && condition != 'b') //check condition if exception
			{
				in.ignore(1000, '\n');
				throw std::out_of_range("Invalid record!");
			}

			//extract m_topSeed.
			//if successful, discard all remaining informaiton of the record for Car, 
			//discard information until comma, but left m_booster in stream for Racecar 
			//if not successful(invalid data, not double), discard the whole record and throw an exception
			if(in >> m_topSpeed)
			{
				if (tag == 'c')
				{
					in.ignore(1000, '\n');
				}
				else if (tag == 'r')
				{
					in.ignore(1000, ',');
				}
			}
	        
			else
			{
				in.clear();
				in.ignore(1000, '\n');
				throw std::out_of_range("Invalid record!");
			}
			
			//mapping for m_condition
			switch(condition) {
				case 'n':
					m_condition = Condition::newc;
					break;
				case 'u':					
					m_condition = Condition::used;
					break;
				case 'b':
					m_condition = Condition::broken;
					break;
				default:
					break;
			}		
	}

	std::string Car::condition()const {
		std::string condition;
		switch (m_condition) {
		case Condition::newc:
			condition = "new";
			break;
		case Condition::used:
		    condition = "used"; 
			break;			
		case Condition::broken:
			condition = "broken";
			break;
		default:
			break;
		}
		return condition;
	}

	double Car::topSpeed()const {
		return m_topSpeed;
	}
	void Car::display(std::ostream& out) const {
		out << "| " << std::setw(10) << std::right << m_maker << " | " << std::setw(6) << std::left << this->condition() << " | " << std::setw(6) << std::fixed << std::setprecision(2) << this->topSpeed() << " |";
		//notice, the topSpeed in Car and Racecar calculated differentely, use member funtion instead of member data "m_topSpeed"
	}
}