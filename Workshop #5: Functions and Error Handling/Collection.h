/**********************************************************
* Name: Xuewei Sheng
* Student ID : 061745121
* Seneca email : xsheng3@myseneca.ca
* Section: NCC
* Date: 2021-06-27
* *********************************************************/
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#ifndef COLLECTION_H
#define COLLECTION_H
#include <iostream>
#include <string>
namespace sdds {
	template <typename T>
	class Collection {
		std::string m_collectionName{};
		T* m_items{ nullptr };
		size_t arrSize{ 0 };
		void (*m_observer)(const Collection<T>&, const T&) { nullptr };
		
	public:
		Collection() {}
		Collection(const std::string& name) {
			if (!name.empty()) {
				m_collectionName = name;
			}
		}

		Collection(const Collection& src) = delete;
		Collection& operator=(const Collection& src) = delete;
		Collection(Collection&& src) = delete;
		Collection& operator=(Collection&& src) = delete;
		~Collection() {
			if(m_items != nullptr)
			{
				delete[]m_items;
				m_items = nullptr;
			}
		}

		const std::string& name()const {
			return m_collectionName;
		}

		size_t size()const {
			return arrSize;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			m_observer = observer;
		}

		Collection<T>& operator+=(const T& item) {
			bool isExist = false;
			for (size_t i = 0; i < arrSize && !isExist; i++)
			{
				if (m_items[i].title() == item.title())
					isExist = true;
			}
			if (!isExist)
			{
				Collection temp;
				temp.arrSize = arrSize + 1;
				temp.m_items = new T[temp.arrSize];
				for (size_t i = 0; i < arrSize; i++)
				{
					temp.m_items[i] = m_items[i];
				}
				temp.m_items[arrSize] = item;

				if (m_items != nullptr)
				{
					delete[] m_items;
					m_items = nullptr;
				}					
				arrSize++;
				m_items = new T[arrSize];
				for(size_t i = 0; i < arrSize; i++)
				{
				    m_items[i] = temp.m_items[i];
				}
				delete[] temp.m_items;
				temp.m_items = nullptr;

				//call back the obsever function if item addtion is successful and the observation registered
				if (m_observer != nullptr)
				{
					m_observer(*this, item);
				}
			}
			
			return *this;
		}

		T& operator[](size_t idx)const {
			//if idx out of range, throw an out_of_range exception with msg
			if (idx >= arrSize)
			{
				std::string msg = "Bad index [";
				msg += std::to_string(idx);
				msg += "]. Collection has [";
				msg += std::to_string(arrSize);
				msg += "] items.";
				throw std::out_of_range(msg);
			}
			return m_items[idx];
		}

		T* operator[](const std::string& title)const {
			size_t i = 0;
			bool found = false;
			for (; i < arrSize && !found; i++)
			{
				if (m_items[i].title() == title)
				{
					found = true;
				}
			}
			return found? &m_items[i -1] : nullptr;
		}

	};
	template <typename T>
    std::ostream& operator<<(std::ostream& os, const Collection<T>& collection) {
		for (size_t i = 0; i < collection.size(); i++) 
		{
			os << collection[i];
		}
		return os;
	}
}
#endif // !COLLECTION_H

