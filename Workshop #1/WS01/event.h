/***********************************************************
* Name: Xuewei Sheng
* Student ID : 061745121
* Seneca email : xsheng3@myseneca.ca
* Section: NCC
* *********************************************************/

#ifndef EVENT_H
#define EVENT_H

extern unsigned int g_sysClock;
namespace sdds {	
	class Event {
		char* m_desc;
		unsigned int m_time;
		void setEmpty();
	public:
		Event(const char* desc = nullptr, unsigned int time = 0u);
		Event(const Event& src);
		Event& operator=(const Event& src);
		~Event();
		void display()const;
		void set(char* desc = nullptr);
	};
}
#endif