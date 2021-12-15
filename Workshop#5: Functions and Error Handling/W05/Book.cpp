/**********************************************************
* Name: Xuewei Sheng
* Student ID : 061745121
* Seneca email : xsheng3@myseneca.ca
* Section: NCC
* Date: 2021-06-27
* *********************************************************/
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#include <string>
#include <iomanip>
#include "Book.h"

namespace sdds {
	std::string Book::clrSpace(const std::string strin) {
		std::string strcleared = strin.substr(0, strin.find_first_of(','));
		strcleared.erase(0, strcleared.find_first_not_of(' '));
		strcleared.erase(strcleared.find_last_not_of(' ') + 1);
		return strcleared;
	}

	const std::string& Book::title()const {
		return m_title;
	}
	const std::string& Book::country()const {
		return m_country;
	}
	const size_t& Book::year()const {
		return m_year;
	}

	double& Book::price() {
		return m_price;
	}

	Book::Book(const std::string& strBook) {
		if (!strBook.empty())
		{
			std::string info = strBook;
			m_author = clrSpace(info);

			info.erase(0, info.find_first_of(',') + 1);
			m_title = clrSpace(info);

			info.erase(0, info.find_first_of(',') + 1);
			m_country = clrSpace(info);

			info.erase(0, info.find_first_of(',') + 1);
			m_price = stod(info.substr(0, info.find_first_of(',')));

			info.erase(0, info.find_first_of(',') + 1);
			m_year = stoi(info.substr(0, info.find_first_of(',')));

			info.erase(0, info.find_first_of(',') + 1);		
			m_description = info.substr(info.find_first_not_of(' '));
		}
	}

	std::ostream& operator<<(std::ostream& os, const Book& book) {
		os << std::setw(20) << book.m_author << " | " << std::setw(22) << book.m_title << " | "  << std::setw(5) << book.m_country << " | "  << std::setw(4) << book.m_year << " | "  << std::setw(6) << std::fixed << std::setprecision(2) << book.m_price << " | "  << book.m_description << std::endl;
		return os;
	}
}