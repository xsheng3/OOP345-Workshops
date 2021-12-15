/**********************************************************
* Name: Xuewei Sheng
* Student ID : 061745121
* Seneca email : xsheng3@myseneca.ca
* Section: NCC
* Date: 2021-07-29
* *********************************************************/
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.


// Workshop 9 - Multi-Threading
// SecureData.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include "SecureData.h"

using namespace std;

namespace w9 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs)
	{
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		nbytes = i;
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key)
	{
		//rewrite this function to use at least two threads
		// to encrypt/decrypt the text.

		//original code
		//converter(text, key, nbytes, Cryptor());
		/* solution for workshop9, part1:
		char* temp = &text[nbytes / 2];
		thread t1(converter, text, key, nbytes / 2, Cryptor());
		thread t2(converter, temp, key, nbytes / 2 + 1, Cryptor());
		t1.join();
		t2.join();
		*/
		//solution for workshop9, part2:
		/*using namespace std::placeholders;
		//auto fn = std::bind(converter, text, key, _1, Cryptor());
		fn(nbytes / 4);*/
		std::thread t2(std::bind(converter, text, key, nbytes / 4, Cryptor()));
		std::thread t3(std::bind(converter, text, key, nbytes / 2, Cryptor()));
		std::thread t4(std::bind(converter, text, key, nbytes / 4 + nbytes / 2, Cryptor()));		
		t2.join();
		t3.join();
		t4.join();
		encoded = !encoded;
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
			// open a binary file for writing
			std::ofstream fout(file, std::ios::binary);			

			// write data into the binary file
			//         and close the file
			fout << text;
			fout.close();
		}
	}

	void SecureData::restore(const char* file, char key) {
		// TODO: open binary file for reading
		std::ifstream fin(file, std::ios::binary);
		// TODO: - allocate memory here for the file content
		fin.seekg(0, std::ios::end);
		int bytesNo = (int)fin.tellg() + 1;
		if (text != nullptr)
		{
			delete[] text;
			text = nullptr;
		}
		text = new char[bytesNo];
		// TODO: - read the content of the binary file
		fin.seekg(0);
		int i = 0;
		fin >> noskipws;
		while (fin.good())
		{
			fin >> text[i++];
		}
		text[bytesNo - 1] = '\0';

		*ofs << "\n" << nbytes << " bytes copied from binary file "
			<< file << " into memory.\n";
		encoded = true;

		// decode using key
		code(key);

		*ofs << "Data decrypted in memory\n\n";
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}
