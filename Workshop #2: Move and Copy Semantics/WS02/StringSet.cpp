/**********************************************************
* Name: Xuewei Sheng
* Student ID : 061745121
* Seneca email : xsheng3@myseneca.ca
* Section: NCC
* *********************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "StringSet.h"
using namespace std;

namespace sdds {
	StringSet::StringSet(const char* filename) {
		if (filename)
		{
			ifstream fin(filename);
			string str;
			getline(fin, str, ' ');
			for (unsigned i = 0; fin; i++)
			{
				str.clear();
				getline(fin, str, ' ');
				noOfStrings++;
			}
			m_strings = new string[noOfStrings];
			//ifstream f(filename); --don't reopen the file, rewind it
			fin.clear();
			fin.seekg(0);
			for (unsigned i = 0; i < noOfStrings; i++)
			{
				str.clear();
				getline(fin, str, ' ');
				m_strings[i] = str;
			}
		}
	}

	StringSet::StringSet(const StringSet& src) {
		*this = src;
	}

	StringSet& StringSet::operator=(const StringSet& src) {
		if (this != &src)
		{
    		delete[] m_strings;		
			m_strings = new string[src.noOfStrings];
			for (unsigned i = 0; i < src.noOfStrings; i++)
			{
				m_strings[i] = src.m_strings[i];
			}
			noOfStrings = src.noOfStrings;		
		}
		return *this;
	}

	StringSet::StringSet(StringSet&& src)noexcept {
		*this = std::move(src);
	}

	StringSet& StringSet::operator=(StringSet&& src)noexcept {
		if (this != &src)
		{
			delete[] m_strings;
			m_strings = src.m_strings;
			src.m_strings = nullptr;
			noOfStrings = src.noOfStrings;
			dummy = src.dummy;
			src.noOfStrings = 0u;
			src.dummy = "";
		}
		return *this;
	}

	StringSet::~StringSet() {
		delete[] m_strings;
		m_strings = nullptr;
	}

	size_t StringSet::size()const {
		return noOfStrings;
	}
	string StringSet::operator[](size_t idx)const {		
		return idx < noOfStrings ? m_strings[idx] : dummy;
	}
}