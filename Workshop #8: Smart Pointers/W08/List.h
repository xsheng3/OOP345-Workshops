/**********************************************************
* Name: Xuewei Sheng
* Student ID : 061745121
* Seneca email : xsheng3@myseneca.ca
* Section: NCC
* Date: 2021-07-20
* *********************************************************/
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
#ifndef SDDS_LIST_H
#define SDDS_LIST_H
// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
    template <typename T>
    class List {
		std::vector<T> list;
	public:
		List() { }
		List(const char* fn) {
			std::ifstream file(fn);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(fn) + std::string(" ***");
            while (file) {
                T e;
                if (e.load(file))
                    list.push_back(T(e));
            }
		}
		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		// Overload the += operator with a smart pointer
		//       as a second operand.
		// the copy constructor for unique_ptr template is deleted
		// make sure have reference (unique_ptr<T>&) as argument
		void operator+=(const std::unique_ptr<T>& elmt)
		{
			list.push_back(*elmt);
		}

		//Overload the += operator with a raw pointer
		//       as a second operand.
		void operator+=(const T* elmt) {			
			list.push_back(*elmt);
			//be careful delete the object after pushing it into the vector, 
			//or it will cause memory leaking-- 
			//src is copied to this and the this is not deleted any where.
			delete elmt; 
			elmt = nullptr;
		}

		void display(std::ostream& os) const {
            os << std::fixed << std::setprecision(2);
            for (auto& e : list)
                e.display(os);
        }
	};

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const List<T>& l) {
		l.display(os);
		return os;
	}
}
#endif