/**********************************************************
* Name: Xuewei Sheng
* Student ID : 061745121
* Seneca email : xsheng3@myseneca.ca
* Section: NCC
* Date: 2021-07-08
* *********************************************************/
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#include "Autoshop.h"

namespace sdds {
	Autoshop& Autoshop::operator +=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	void Autoshop::display(std::ostream& out)const
	{
		out << "--------------------------------" << std::endl;
		out << "| Cars in the autoshop!        |" << std::endl;
		out << "--------------------------------" << std::endl;
		for (auto v : m_vehicles)
		{
			v->display(out);
			out << std::endl;
		}			
		out << "--------------------------------" << std::endl;
	}
    
	Autoshop::~Autoshop() {		
		for (auto v : m_vehicles)
		{
			delete v;
			v = nullptr;
		}
		//shirk does not working, still have 9 blocks of memory leaking
		//clear and shirk only remove the elements from the vector but not free the memory
		//m_vehicles.clear();
		//m_vehicles.shrink_to_fit();
	}

}