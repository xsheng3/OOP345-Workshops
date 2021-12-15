/**********************************************************
* Name: Xuewei Sheng
* Student ID : 061745121
* Seneca email : xsheng3@myseneca.ca
* Section: NCC
* Date: 2021-07-08
* *********************************************************/
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#include"Utilities.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in) {
		Vehicle* vehicle = nullptr; //create a temporary pointer of Vehicle object
		
		//extract tpye of vehicle, store the type in the external linkage "tag"
		//create a proper type of new Vehicle 
		//if the tag is invalid, throw an exeption with message
		char type = '\0';
		in >> type;
		in.ignore(1000, ',');		
		if (type == 'c' || type == 'C')
		{
			tag = 'c';
			vehicle = new Car(in);			
		}
		else if (type == 'r' || type == 'R')
		{
			tag = 'r';
			vehicle = new Racecar(in);
		}
		else
		{
			in.ignore(1000, '\n');
			std::string msg = "Unrecognized record type: [";
			msg += type;
			msg += "]";
			throw std::out_of_range(msg);
		}
		return vehicle;
	}
}