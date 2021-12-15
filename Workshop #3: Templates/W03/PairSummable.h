/**********************************************************
* Name: Xuewei Sheng
* Student ID : 061745121
* Seneca email : xsheng3@myseneca.ca
* Section: NCC
* Date: 2021-06-12
* *********************************************************/
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.


#ifndef PAIRSUMMABLE_H
#define PAIRSUMMABLE_H
#include "Pair.h"

namespace sdds {
	template <typename V, typename K>
	class PairSummable : public Pair<V,K> {
		static V initial;
		static size_t minFieldWidth;
	public:
		PairSummable() {}

		PairSummable(const K& key, const V& value = initial) :Pair<V, K>(key, value) { //careful: the order of parameters are opposite with typenames
			if (minFieldWidth < key.size())
			{
				minFieldWidth = key.size();
			}
		}

		bool isCompatibleWith(const PairSummable<V, K>& b)const {
			return this->key() == b.key() ? true : false;
		}

		//this->value() += item.value() is not working, because current V object is a const (in Pair.h)
		//create a new PairSummable object named "sum" with the V has sum of the values (this and item)
		//then copy sum to this.
		PairSummable<V, K>& operator+=(const PairSummable<V, K>& item) {
			PairSummable<V, K> sum(this->key(), this->value() + item.value());
			return *this = sum;
		}

		//virtual display function in Pair.h
		void display(std::ostream& os) const {
			os << std::left << std::setw(minFieldWidth);
			Pair<V, K>::display(os);
			os << std::right;
		}		
	};

	//static member initialize
	template <typename V, typename K>
	V PairSummable<V, K>::initial {};
	template <typename V, typename K>
	size_t PairSummable<V, K>::minFieldWidth{ 0u };

	//+= operator specialization
	template <>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+= (const PairSummable<std::string, std::string>& item) {
		if (this->value() == "")
		{
			PairSummable<std::string, std::string> sum(this->key(), item.value()); // the first string should not start with ","
			*this = sum;
		}
		else 
		{
			PairSummable<std::string, std::string> sum(this->key(), this->value() + ", " + item.value());
			*this = sum;
		}		
		return *this;
	}
}

#endif // !SETSUMMABLE_H
