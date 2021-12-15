/**********************************************************
* Name: Xuewei Sheng
* Student ID : 061745121
* Seneca email : xsheng3@myseneca.ca
* Section: NCC
* *********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <chrono>
#include "TimedEvents.h"

namespace sdds {
	void TimedEvents::startClock() {
		m_startTime = std::chrono::steady_clock::now();
	}
	void TimedEvents::stopClock() {
		m_stopTime = std::chrono::steady_clock::now();
	}
	void TimedEvents::addEvent(const char* eventName) {
		if (eventName)
		{
			events[noOfRecords].m_eventName = eventName;
			events[noOfRecords].m_timeUnit = "nanoseconds";
			events[noOfRecords].m_duration = m_stopTime - m_startTime;
			noOfRecords++;
		}
	}

	std::ostream& operator<<(std::ostream& os, const TimedEvents& te){
		os << "--------------------------" << std::endl;
		os << "Execution Times:" << std::endl;
		os << "--------------------------" << std::endl;
		for (unsigned int i = 0; i < te.noOfRecords; i++)
		{
			os.fill(' ');
			os << std::setw(21) << std::left << te.events[i].m_eventName;
			os << std::setw(13) << std::right <<std::setprecision(13) <<std::chrono::duration_cast<std::chrono::nanoseconds>(te.events[i].m_duration).count() << " " <<te.events[i].m_timeUnit << std::endl;
		}
		os << "--------------------------" << std::endl;
		return os;
	}


}