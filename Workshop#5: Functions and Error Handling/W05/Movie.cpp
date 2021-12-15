/**********************************************************
* Name: Xuewei Sheng
* Student ID : 061745121
* Seneca email : xsheng3@myseneca.ca
* Section: NCC
* Date: 2021-06-27
* *********************************************************/
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#include <iostream>
#include <iomanip>
#include <string>
#include "Movie.h"

namespace sdds {
	std::string Movie::clrSpace(const std::string strin) {
		std::string strcleared = strin.substr(0, strin.find_first_of(','));
		strcleared.erase(0, strcleared.find_first_not_of(' '));
		strcleared.erase(strcleared.find_last_not_of(' ') + 1);
		return strcleared;
	}

	const std::string& Movie::title()const {
		return m_movTitle;
	}

	Movie::Movie(const std::string& strMovie) {
		if (!strMovie.empty()) 
		{
			std::string info = strMovie;
			m_movTitle = clrSpace(info);

			info.erase(0, info.find_first_of(',') + 1);
			m_releaseYear = stoi(info.substr(0, info.find_first_of(',')));

			info.erase(0, info.find_first_of(',') + 1);
			m_movDescription = info.substr(info.find_first_not_of(' '));
		}
	}

	std::ostream& operator<<(std::ostream& os, const Movie& movie) {
		os << std::setw(40) << movie.m_movTitle << " | " << movie.m_releaseYear << " | " << movie.m_movDescription << std::endl;
		return os;
	}
}