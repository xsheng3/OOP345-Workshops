/**********************************************************
* Name: Xuewei Sheng
* Student ID : 061745121
* Seneca email : xsheng3@myseneca.ca
* Section: NCC
* Date: 2021-06-12
* *********************************************************/

// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.


#ifndef SET_H
#define SET_H

namespace sdds {
	template <unsigned N, typename T>
	class Set{
		T a[N];
		static unsigned counter;

	public:
		size_t size()const
		{
			return counter;
		}
		const T& get(size_t idx) const {
			return a[idx];
		}
		void operator+=(const T& item) {
			if (counter < N)
			{
				a[counter++] = item;
			}
		}
	};
	template <unsigned N, typename T>
	unsigned Set<N, T>::counter = 0u;
}

#endif // !SET_H
