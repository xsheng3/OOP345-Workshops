/***********************************************************
* Name: Xuewei Sheng
* Student ID : 061745121
* Seneca email : xsheng3@myseneca.ca
* Section: NCC
* *********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"event.h"
using namespace std;
unsigned int g_sysClock = 0u;
namespace sdds {
	void Event::setEmpty() {
		m_desc = nullptr;
		m_time = 0u;			
	}
	Event::Event(const char* desc, unsigned int time) : m_time{ time } {
		if (desc)
		{
			m_desc = new char[strlen(desc) + 1];
			strcpy(m_desc, desc);
		}			
		else
			m_desc = nullptr;
	}
	Event::Event(const Event& src) {
		this->setEmpty();
		*this = src;
	}
	
	Event& Event::operator=(const Event& src)
	{
		if (this != &src)
		{
			if (m_desc != nullptr)
			{
				delete[] m_desc;
				m_desc = nullptr;
			}
			if (src.m_desc != nullptr)
			{
				m_desc = new char[strlen(src.m_desc) + 1];
				strcpy(m_desc, src.m_desc);
			}
			m_time = src.m_time;
		}
		return *this;
	}

	Event::~Event() {
		delete[] m_desc;
		m_desc = nullptr;
	}

	void Event::display()const {
		static unsigned int COUNTER = 0u;
		cout.fill(' ');
		cout.width(2);
		cout << ++COUNTER << ". ";
		if (m_desc)
		{
			unsigned hour = 0, min = 0, sec = 0;
			hour = m_time / 3600;
			min = m_time % 3600 / 60;
			sec = m_time % 3600 % 60;			
			cout.fill('0');
			cout.width(2);
			cout << hour << ":";
			cout.width(2);
			cout << min << ":";
			cout.width(2);
			cout << sec << " => " << m_desc << endl;
		}
		else
		{
			cout << "| No Event |" << endl;
		}
	}
	void Event::set(char* desc) {
		if (desc)
		{
			if (m_desc != nullptr)
			{
				delete[] m_desc;
			}
			m_desc = new char[strlen(desc) + 1];
			strcpy(m_desc, desc);
			m_time = g_sysClock;
		}
		else
		{
			if (m_desc != nullptr)
			{
				delete[] m_desc;
			}
			setEmpty();
		}
	}
}
