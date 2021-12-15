/**********************************************************
* Name: Xuewei Sheng
* Student ID : 061745121
* Seneca email : xsheng3@myseneca.ca
* Section: NCC
* Date: 2021-06-20
* *********************************************************/
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#ifndef RESTAURANT_H
#define RESTAURANT_H
//#include <iostream>
//#include "Reservation.h"

namespace sdds {
	class Reservation;
	class Restaurant {
		Reservation* m_resvs{ nullptr };
		size_t noOfRes{ 0u };
		size_t size()const;	
	public:
		Restaurant(const Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& src);
		Restaurant& operator=(const Restaurant& src);
		Restaurant(Restaurant&& src)noexcept;
		Restaurant& operator=(Restaurant&& src)noexcept;
		~Restaurant();
		
		friend std::ostream& operator<<(std::ostream& os, Restaurant rest);
	};
}
#endif // !RESTAURANT_H
