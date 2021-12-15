/**********************************************************
* Name: Xuewei Sheng
* Student ID : 061745121
* Seneca email : xsheng3@myseneca.ca
* Section: NCC
* *********************************************************/
#ifndef STRINGSET_H
#define STRINGSET_H

namespace sdds {
	class StringSet {
		unsigned noOfStrings{ 0u };
		std::string* m_strings{ nullptr };
		std::string dummy = "";
	public:
		StringSet() {};
		StringSet(const char* filename);
		StringSet(const StringSet& src);
		StringSet& operator=(const StringSet& src);
		StringSet(StringSet&& src)noexcept;
		StringSet& operator=(StringSet&& src)noexcept;
		~StringSet();
		size_t size()const;
		std::string operator[](size_t idx)const;
	};

}
#endif // !STRINGSET_H

