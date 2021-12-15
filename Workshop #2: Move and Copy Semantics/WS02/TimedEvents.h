/**********************************************************
* Name: Xuewei Sheng
* Student ID : 061745121
* Seneca email : xsheng3@myseneca.ca
* Section: NCC
* *********************************************************/
#ifndef TIMEDEVENTS_H
#define TIMEDEVENTS_H
#include <iostream>
#include <chrono>

namespace sdds {
	class TimedEvents {
	    struct Event {
			std::string m_eventName{ "" };
			std::string m_timeUnit{ "" };
			std::chrono::duration<double> m_duration;
		} events[10];
		unsigned noOfRecords{ 0u };
		std::chrono::time_point<std::chrono::steady_clock> m_startTime;
		std::chrono::time_point<std::chrono::steady_clock> m_stopTime;
	public:
		TimedEvents() {};
		void startClock();
		void stopClock();
		void addEvent(const char* name);
		friend std::ostream& operator<<(std::ostream& os, const TimedEvents& te);
	};

}
#endif // !1

