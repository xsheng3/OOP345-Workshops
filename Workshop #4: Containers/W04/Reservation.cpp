/**********************************************************
* Name: Xuewei Sheng
* Student ID : 061745121
* Seneca email : xsheng3@myseneca.ca
* Section: NCC
* Date: 2021-06-20
* *********************************************************/
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#include <string>
#include <iomanip>
#include "Reservation.h"

namespace sdds {
	//clear the leading and trailing space for each string element
	std::string Reservation::clrSpace(const std::string strin, char sym) {
		std::string strcleared = strin.substr(0, strin.find_first_of(sym));
		strcleared.erase(0, strcleared.find_first_not_of(' '));
		strcleared.erase(strcleared.find_last_not_of(' ') + 1);
		return strcleared;
	}

	Reservation::Reservation(const std::string& res) {
		std::string info = res;
		m_id = clrSpace(info, ':');

		info.erase(0, info.find_first_of(':') + 1);
		m_name = clrSpace(info, ',');

		info.erase(0, info.find_first_of(',') + 1);
		m_email = clrSpace(info, ',');
		m_email = '<' + m_email +'>';

		info.erase(0, info.find_first_of(',') + 1);
		m_noOfPeople= stoi(info.substr(0, info.find_first_of(',')));

		//m_day
		info.erase(0, info.find_first_of(',') + 1);
		m_day = stoi(info.substr(0, info.find_first_of(',')));

		//m_hour
		info.erase(0, info.find_first_of(',') + 1);
		m_hour = stoi(info.substr(0, info.find_first_of(',')));
	}
	Reservation& Reservation::operator=(const Reservation& src) {
		if (this != &src)
		{
			m_id = src.m_id;
		    m_name = src.m_name;
			m_email = src.m_email;
			m_noOfPeople = src.m_noOfPeople;
			m_day = src.m_day;
			m_hour = src.m_hour;
		}
		return *this;
	}

	//Reservation::~Reservation() {
		//m_id = nullptr;
	//}

	std::ostream& operator<<(std::ostream& os, const Reservation& res) {
		//don't understand the method of enum class the professor mentioned very well, have no time to do search and code in that way and submit the workshop on time. Do it later.
		os << "Reservation " << std::setw(10) << std::right << res.m_id << ": " << std::setw(20)   << std::right << res.m_name << "  " << std::setw(20) << std::left << res.m_email;
		if (res.m_hour >= 6 && res.m_hour <= 9)
		{
			os << "    Breakfast on day ";
		}
		else if (res.m_hour >= 11 && res.m_hour <=15)
		{
			os << "    Lunch on day ";
		}
		else if (res.m_hour >= 17 && res.m_hour <= 21)
		{
			os << "    Dinner on day ";
		}
		else
		{
			os << "    Drinks on day ";
		}

		os << res.m_day << " @ " << res.m_hour << ":00 for " << res.m_noOfPeople;

		if (res.m_noOfPeople == 1)
		{
			os << " person." << std::endl;
		}
		else
		{
			os << " people." << std::endl;
		}

		return os;
	}
}
