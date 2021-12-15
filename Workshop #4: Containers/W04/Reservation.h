/**********************************************************
* Name: Xuewei Sheng
* Student ID : 061745121
* Seneca email : xsheng3@myseneca.ca
* Section: NCC
* Date: 2021-06-20
* *********************************************************/
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#ifndef RESERVATION_H
#define RESERVATION_H

namespace sdds {
	class Reservation {
		std::string m_id{};
		std::string m_name{};
		std::string m_email{};
		unsigned m_noOfPeople{ 0u };
		unsigned m_day{ 0u };
		unsigned m_hour{ 0u };
		std::string clrSpace(const std::string strin, char sym);
	public:
		Reservation(){}
		Reservation(const std::string& res);
		Reservation& operator=(const Reservation& src);
		friend std::ostream& operator<<(std::ostream& os, const Reservation& res);

	};
	

}
#endif // !RESERVATION_H

