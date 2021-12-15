/**********************************************************
* Name: Xuewei Sheng
* Student ID : 061745121
* Seneca email : xsheng3@myseneca.ca
* Section: NCC
* Date: 2021-06-12
* *********************************************************/

// I have done all the coding by myself and only copied the code that 
// my professor provided to complete my workshops and assignments.


#ifndef SETSUMMABLE_H
#define SETSUMMABLE_H
#include "Set.h"

namespace sdds {
	template <unsigned N, typename T>
	class SetSummable : public Set<N, T> {
	public:
		T accumulate(const std::string& filter) const {
			T accumulator(filter);
			for (unsigned i = 0; i < this->size(); i++) {
				//compare the key of current T object with the key of accumulator object (string filter)
				//if match, add current T to accumulator.
				if (this->get(i).isCompatibleWith(accumulator)) 
				{
					accumulator += this->get(i);
				}
			}
			return accumulator;
		}
	};

}

#endif // !SETSUMMABLE_H
