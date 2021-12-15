/**********************************************************
* Name: Xuewei Sheng
* Student ID : 061745121
* Seneca email : xsheng3@myseneca.ca
* Section: NCC
* Date: 2021-06-20
* *********************************************************/
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#include <iostream>
#include <string>
#include "Restaurant.h"
#include "Reservation.h"
namespace sdds {
	size_t Restaurant::size()const {
		return noOfRes;
	}

	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) :noOfRes{ cnt } {
		m_resvs = new Reservation[cnt];
		
		for (unsigned i = 0; i < cnt; i++)
		{
			m_resvs[i] = *reservations[i];
		}
	}

	Restaurant::Restaurant(const Restaurant& src) {
		*this = src;
	}

	Restaurant& Restaurant::operator=(const Restaurant& src) {
		if (this != &src)
		{
			if (m_resvs != nullptr)
				delete []m_resvs;
			noOfRes = src.noOfRes;
			m_resvs = new Reservation[noOfRes];
			for (unsigned i = 0; i < src.noOfRes; i++)
			{
				m_resvs[i] = src.m_resvs[i];
			}			
		}
		return *this;
	}

	Restaurant::Restaurant(Restaurant&& src)noexcept {
		*this = std::move(src);
	}
	Restaurant& Restaurant::operator=(Restaurant&& src)noexcept {
		if (this != &src)
		{
			delete[] m_resvs;
			noOfRes = src.noOfRes;
			m_resvs = src.m_resvs;
			src.m_resvs = nullptr;
			src.noOfRes = 0u;
		}
		return *this;
	}

	Restaurant::~Restaurant() {
		if (m_resvs != nullptr)
		{
			delete[] m_resvs;
			m_resvs = nullptr;
		}

	}

	std::ostream& operator<<(std::ostream& os, Restaurant rest) {
		static unsigned COUNTER = 0u;
		os << "--------------------------" << std::endl;
		os << "Fancy Restaurant (" << ++COUNTER << ")" << std::endl;
		os << "--------------------------" << std::endl;
		if (rest.size())
		{			
			for (unsigned i = 0; i < rest.size(); i++)
			{
				os << rest.m_resvs[i];
			}
			
		}
		else
		{
			os << "This restaurant is empty!" << std::endl;
		}
		os << "--------------------------" << std::endl;
		return os;
	}
}
