/**********************************************************
* Name: Xuewei Sheng
* Student ID : 061745121
* Seneca email : xsheng3@myseneca.ca
* Section: NCC
* Date: 2021-06-27
* *********************************************************/
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#ifndef MOVIE_H
#define MOVIE_H

namespace sdds {
	class Movie {
		std::string m_movTitle{};
		size_t m_releaseYear{ 0 };
		std::string m_movDescription{};
		std::string clrSpace(const std::string strin);
	public:
		Movie() {};
		const std::string& title()const;
		Movie(const std::string& strMovie);
		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_movTitle);
			spellChecker(m_movDescription);
		}
		friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
	};

}
#endif // !MOVIE_H

