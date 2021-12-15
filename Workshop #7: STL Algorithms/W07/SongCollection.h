/**********************************************************
* Name: Xuewei Sheng
* Student ID : 061745121
* Seneca email : xsheng3@myseneca.ca
* Section: NCC
* Date: 2021-07-15
* *********************************************************/
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#ifndef SONGCOLLECTION_H
#define SONGCOLLECTION_H
#include <vector>
#include <list>
namespace sdds{
	struct Song {
		std::string m_artist{};
		std::string m_title{};
		std::string m_album{};
		double m_price{ 0.0 };
		unsigned m_year{ 0 };
		unsigned m_length{ 0 };
	};
	class SongCollection
	{
		std::vector<Song> m_songs;
		std::string getToken(std::string record, int pos, int len);
	public:
		SongCollection(std::string filename);
		void display(std::ostream& out) const;
		void sort(const std::string& filed);
		void cleanAlbum();
		bool inCollection(const std::string& artist)const;
		std::list<Song> getSongsForArtist(const std::string artist)const;
		//~SongCollection();
	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}

#endif // !SONGCOLLECTION_H


