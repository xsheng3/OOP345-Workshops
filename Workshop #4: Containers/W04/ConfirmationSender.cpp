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
#include "ConfirmationSender.h"
#include "Reservation.h"

namespace sdds {
	bool ConfirmationSender::isexist(const Reservation& res) {
		bool isexist = false;
		for (unsigned i = 0; i < noOfPts && !isexist; i++)
		{
			if (m_presvs[i] == &res)
			{
				isexist = true;
			}
		}
		return isexist;
	}

	size_t ConfirmationSender::size()const {
		return noOfPts;
	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src) {
		*this = src;
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src) {
		if (this != &src)
		{
			m_presvs = new const Reservation* [src.noOfPts];
			noOfPts = src.noOfPts;
			for (unsigned i = 0; i < noOfPts; i++)
			{
				//only copy the address of m_presve[i] in src to current. do not manage the memory allocating for the object itself
				m_presvs[i] = src.m_presvs[i];
				
			}
		}
		return *this;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src)noexcept {
		*this = std::move(src);
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src) noexcept{
		if (this != &src)
		{
			if (m_presvs != nullptr)
			{
				delete[] m_presvs;
			}			
			noOfPts = src.noOfPts;
			m_presvs = src.m_presvs;
			src.m_presvs = nullptr;
			src.noOfPts = 0u;
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		//check if the res is already in the array, if exist do nothing
		if (!isexist(res))//if not exist
		{
			//check if the pointer array is full
			bool isfull = true;
			for (unsigned i = 0; i < noOfPts && isfull; i++)
			{
				if (m_presvs[i] == nullptr)//if not full, copy res to the empty elemnet (nullptr)
				{
					isfull = false;
					m_presvs[i] = &res;
				}
			}

			if (isfull)//if is full, move this to a temp, delete this, create a new array of pointers with one more in size
			{   
				//create a new ConfirmationSender with the size that one bigger than current one
				ConfirmationSender temp;
				temp.noOfPts = noOfPts + 1;
				temp.m_presvs = new const Reservation * [temp.noOfPts];

				//copy all the object in the current ConfirmationSender to temp, then add res on the end of the array
				for (size_t i = 0; i < noOfPts; i++)
				{
					temp.m_presvs[i] = m_presvs[i];
				}
				temp.m_presvs[noOfPts] = &res;

				//deallocate this
                delete[] m_presvs;
				m_presvs = nullptr;

				//copy the address of temp to this
				*this = std::move(temp);
			}
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		//check if res is in the array, do nothing if not
		bool isexist = false;
		unsigned i;
		for (i = 0; i < noOfPts && !isexist; i++)
		{
			if (m_presvs[i] == &res)
			{
				isexist = true;
			}
		}
		//if res is in the array
		if (isexist)
		{
			//Create a new array of pointers, the size is one less than current one
			ConfirmationSender temp;
			temp.noOfPts = noOfPts - 1;
			temp.m_presvs = new const Reservation * [temp.noOfPts];
			//copy the address of Reservations in current ConfirmationSender, skip the one matched res
			unsigned j;
			for (j= 0; j < i - 1; j++)
			{
				temp.m_presvs[j] = m_presvs[j];
			}
			for (j = i - 1; j < temp.noOfPts; j++)
			{
				temp.m_presvs[j] = m_presvs[j + 1];
			}
			//delete m_presvs[i-1]; 
			//m_presvs[i - 1] = nullptr;
			//--this Reservation should not be deleted here. they are the elements of ppReservations in the main, here only the pointer point to that data, if deleted here, ppReservations will lost them and have error when deallocate in main
	
			//deallocate this, then move temp to this
			//delete[] m_presvs;---do not remove, just set removed address to nulltpr
			m_presvs = nullptr;
			*this = std::move(temp);
		}

		return *this;
	}
	ConfirmationSender::~ConfirmationSender() {
		delete[] m_presvs;	
	}

	std::ostream& operator<<(std::ostream& os, ConfirmationSender& con) {
		os << "--------------------------" << std::endl;
		os << "Confirmations to Send" << std::endl;
		os << "--------------------------" << std::endl;
		if (con.size())
		{
			for (unsigned i = 0; i < con.size(); i++)
			{
				//if this reservation pointer is nullptr, do not call operator<< in Reservation
				if (con.m_presvs[i])
				{
					os << *con.m_presvs[i];
				}				
			}
		}
		else
		{
			os << "There are no confirmations to send!" << std::endl;
		}
		os << "--------------------------" << std::endl;
		return os;
	}
}