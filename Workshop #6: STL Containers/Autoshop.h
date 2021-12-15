/**********************************************************
* Name: Xuewei Sheng
* Student ID : 061745121
* Seneca email : xsheng3@myseneca.ca
* Section: NCC
* Date: 2021-07-08
* *********************************************************/
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#ifndef AUTOSHOP_H
#define AUTOSHOP_H
#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out)const;
		~Autoshop();

		template <typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (auto v : m_vehicles)
			{
				if (test(v))
				{
					vehicles.push_back(v);
				}					
			}	
		}
	};
}

#endif // !AUTOSHOP_H