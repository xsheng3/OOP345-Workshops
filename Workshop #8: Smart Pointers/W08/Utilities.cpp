/**********************************************************
* Name: Xuewei Sheng
* Student ID : 061745121
* Seneca email : xsheng3@myseneca.ca
* Section: NCC
* Date: 2021-07-20
* *********************************************************/
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

#include <iostream>
#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// Build a list of products using raw pointers		
		for (long unsigned i = 0; i < desc.size(); i++)
		{
			bool match = false;
			
			for (long unsigned j = 0; j < price.size() && !match; j++) {
				if (desc[i].code == price[j].code)
				{
					Product* p = new Product(desc[i].desc, price[j].price);
					p->validate();
					//wrap the validate() in an exception try-catch block is the way to slove 
					//the memory leaking for raw pointer--catch the exception, delete the object
					//then continue throw the exception 
					//this not requested in this workshop
					/*try
					{
						p->validate();
					}
					catch (...) {
						delete p;
						throw;
					}*/
					priceList += p;
					match = true;
				}
			}
		}
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		//Build a list of products using smart pointers
		for (long unsigned i = 0; i < desc.size(); i++)
		{
			bool match = false;

			for (long unsigned j = 0; j < price.size() && !match; j++) {
				if (desc[i].code == price[j].code)
				{
					//smart pointer treat the dynamic allocated memory automatically, 
					//no memory leaking when validate() throw an exception
					std::unique_ptr<Product> sp(new Product(desc[i].desc, price[j].price));
					sp->validate();
					priceList += sp;
					match = true;
				}
			}
		}

		return priceList;
	}
}