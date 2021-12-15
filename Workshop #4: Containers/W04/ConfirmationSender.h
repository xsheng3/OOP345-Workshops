/**********************************************************
* Name: Xuewei Sheng
* Student ID : 061745121
* Seneca email : xsheng3@myseneca.ca
* Section: NCC
* Date: 2021-06-20
* *********************************************************/
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#ifndef CONFIRMATIONSENDER_H
#define CONFIRMATIONSENDER_H

namespace sdds {
	class Reservation;
	class ConfirmationSender {
		const Reservation** m_presvs{ nullptr };
		size_t noOfPts{ 0 };
		bool isexist(const Reservation& res);
		size_t size()const;
	public:
		ConfirmationSender(){}
		ConfirmationSender(const ConfirmationSender& src);
		ConfirmationSender& operator=(const ConfirmationSender& src);
		ConfirmationSender(ConfirmationSender&& src)noexcept;
		ConfirmationSender& operator=(ConfirmationSender&& src)noexcept;
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		~ConfirmationSender();
		
		friend std::ostream& operator<<(std::ostream& os, ConfirmationSender& con);
	};


}
#endif // !CONFIRMATIONSENDER_H

