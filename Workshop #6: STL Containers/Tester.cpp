#include <iostream>
#include <vector>

int main() {
	class person {
	public:
		std::string m_name{};
		int m_age{ 0 };
	};

	std::vector <person*> m_person;
	
	person thePerson;
	thePerson.m_name = "sheng";
	thePerson.m_age = 10;

	m_person.push_back(thePerson);

}