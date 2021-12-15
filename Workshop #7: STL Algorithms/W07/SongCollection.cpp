/**********************************************************
* Name: Xuewei Sheng
* Student ID : 061745121
* Seneca email : xsheng3@myseneca.ca
* Section: NCC
* Date: 2021-07-15
* *********************************************************/
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include "SongCollection.h"

namespace sdds {
	//get tokens from the extracted record of one song(one line string)
	//get the tokens of the song, and clear all the leading and trailing space  
	std::string SongCollection::getToken(std::string record, int pos, int len) {
		std::string temp;
		temp = record.substr(pos, len);
		if (temp.at(0) == ' ')
		{
			temp.erase(0, temp.find_first_not_of(' '));
		}		
		temp.erase(temp.find_last_not_of(' ') + 1, temp.size());
		return temp;
	}

	SongCollection::SongCollection(std::string filename) {
		std::ifstream fin(filename);
		if (!fin)
		{
			throw "Bad file name!";
		}
        
		//while extracting information of one song is successful, get tokens one by one.
		//store the tokens to a Song object, and push this object into the m_songs vector.
		std::string record;		
		while (getline(fin, record))
		{
			size_t pos = 0u;
			Song song;

			song.m_title = getToken(record, pos, 25);
			pos += 25;
			song.m_artist = getToken(record, pos, 25);
			pos += 25;
			song.m_album = getToken(record, pos, 25);
			pos += 25;

			std::string year = getToken(record, pos, 5);
			if (year != "")
			{
				song.m_year = stoi(year);
			}
			pos += 5;
			song.m_length = stoi(getToken(record, pos, 5));
			pos += 5;
			song.m_price = stod(getToken(record, pos, 5));
			m_songs.push_back(song);
		}
	}

	void SongCollection::display(std::ostream& out) const {
		//using for_each to go through the m_songs vector and print the songs in the vector one by one
		for_each(m_songs.begin(), m_songs.end(), [&](const Song s) {out << s << std::endl; });

		//using accumulate method to get the sum of the length of all the songs in vector m_songs
		int tlen = std::accumulate(m_songs.begin(), m_songs.end(), (int)0, [=](int x, const Song s) {return x + s.m_length; });

		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		out << "|" <<  std::setw(78) << std::setfill(' ') <<  "Total Listening Time: " 
			<< tlen / 3600 << ":" << tlen % 3600 / 60 << ":" << tlen % 3600 % 60 << " |" << std::endl;
	}

	void SongCollection::sort(const std::string& field) {
		//sort the objects in m_songs in three different condition
		if (field == "title")
		{
			std::sort(m_songs.begin(), m_songs.end(), [](const Song a, const Song b) {return a.m_title.compare(b.m_title) < 0; });
		}
		else if (field == "album")
		{
			std::sort(m_songs.begin(), m_songs.end(), [](const Song a, const Song b) {return a.m_album.compare(b.m_album) < 0; });
		}
		else if (field == "length")
		{
			std::sort(m_songs.begin(), m_songs.end(), [](const Song a, const Song b) {return a.m_length < b.m_length; });
		}	
	}
	
	void SongCollection::cleanAlbum() {		
		//find all the album are "None" form the m_songs, replace with a space and store the  new object backe to the m_songs
		std::transform(m_songs.begin(), m_songs.end(),  m_songs.begin(), [](Song s) {s.m_album = s.m_album == "[None]"? " ":
			s.m_album; return s; });
	}
	
	bool SongCollection::inCollection(const std::string& artist)const {
		return any_of(m_songs.begin(), m_songs.end(), [=](const Song& s) {return s.m_artist == artist; });
	}

	std::list<Song> SongCollection::getSongsForArtist(const std::string artist)const {
		std::list<Song> songs;
		std::vector<Song>::const_iterator it;
		size_t nextPos = 0;
		bool more = true;
		while (more) {
			//check if any more songs by this artist in the left of the vector(start from the position that find the last match)
			//if find, return the iterator and store the song into list songs
			//renew the next postion
			if (any_of(m_songs.begin() + nextPos, m_songs.end(), [=](const Song& s) {return s.m_artist == artist; }))
			{
				it = std::find_if(m_songs.begin() + nextPos, m_songs.end(), [=](const Song& s) {return s.m_artist == artist; });
				songs.push_back(*it);
				nextPos = it - m_songs.begin() + 1;
			}	
			else 
			{
				more = false;
			}			
		}		
		return songs;
	}

	
	std::ostream& operator<<(std::ostream& out, const Song& theSong) {
		//insert one Song object to the ostream
		out << "| " << std::left << std::setw(20) << theSong.m_title << " | " << std::setw(15) << theSong.m_artist << " | " << std::setw(20) << theSong.m_album << " | " << std::setw(6) << std::right;
		if (theSong.m_year == 0)
		{
			out  << " ";
		}
		else
		{
			out << theSong.m_year;
		}
		
		out << " | " << theSong.m_length / 60<< ":" << std::setw(2) << std::setfill('0') << theSong.m_length % 60 << std::setfill(' ') << " | " << theSong.m_price << " |";
		return out;
	}
}
