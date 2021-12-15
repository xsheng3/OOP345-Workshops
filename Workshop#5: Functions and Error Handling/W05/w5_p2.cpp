// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel
// 2021/01/19 - Chris
// 2021/02/12 - Cornel


/**********************************************************
* Name: Xuewei Sheng
* Student ID : 061745121
* Seneca email : xsheng3@myseneca.ca
* Section: NCC
* Date: 2021-06-27
* *********************************************************/
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Collection.h"
#include "Collection.h"
#include "Book.h"
#include "Book.h"
#include "Movie.h"
#include "Movie.h"
#include "SpellChecker.h"
#include "SpellChecker.h"

using namespace sdds;

enum AppErrors
{
	CannotOpenFile = 1, // An input file cannot be opened
	BadArgumentCount = 2, // The application didn't receive anough parameters
};

// The observer function for adding books to the collection:
//   should be called every time a new book is added to the collection
void bookAddedObserver(const Collection<Book>& theCollection,
	const Book& theBook)
{
	std::cout << "Book \"" << theBook.title() << "\" added!\n";
}

// The observer function for adding movies to the collection:
//   should be called every time a new movie is added to the collection
void movieAddedObserver(const Collection<Movie>& theCollection,
	const Movie& theMovie)
{
	std::cout << "Movie \"" << theMovie.title()
		<< "\" added to collection \"" << theCollection.name()
		<< "\" (" << theCollection.size() << " items).\n";
}

// ws books.txt movies.txt file_missing.txt file_words.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the books
	sdds::Collection<sdds::Book> library("Bestsellers");
	if (argc == 5) {
		// load the first 4 books from the file "argv[1]".
		// - read one line at a time, and pass it to the Book constructor
		// - store each book read into the collection "library" (use the += operator)
		// - lines that start with "#" are considered comments and should be ignored
		// - if the file cannot be open, print a message to standard error console and
		//   exit from application with error code "AppErrors::CannotOpenFile"

		std::ifstream fin(argv[1]);
		size_t noOfBooks = 0;
		if (!fin)
		{
			std::cerr << "AppErrors::CannotOpenFile\n";
			return 1;
		}
		std::string strBook;
		do
		{
			std::getline(fin, strBook);
			if (fin)
			{
				if (strBook[0] != '#')
				{
					library += sdds::Book(strBook);
					noOfBooks++;
				}
			}
		} while (fin && noOfBooks < 4);

		/*
		 ♪ Hey, I just met you,      ♪
		 ♪ And this is crazy,        ♪
		 ♪ But here's my number.     ♪    (register the observer)
		 ♪ So, if something happens, ♪    (event)
		 ♪ Call me, maybe?           ♪    (callback)
		 */
		library.setObserver(bookAddedObserver);
	
		//add the rest of the books from the file.
		do
		{
			std::getline(fin, strBook);
			if (fin && noOfBooks < 7)
			{
				if (strBook[0] != '#')
				{
					library += sdds::Book(strBook);
					noOfBooks++;
				}
			}
		} while (fin);

	}
	else
	{
		std::cerr << "ERROR: Incorrect number of arguments.\n";
		exit(AppErrors::BadArgumentCount);
	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	//  create a lambda expression that fixes the price of a book accoding to the rules
	//  - the expression should receive a single parameter of type "Book&"
	//  - if the book was published in US, multiply the price with "usdToCadRate"
	//       and save the new price in the book object
	//  - if the book was published in UK between 1990 and 1999 (inclussive),
	//       multiply the price with "gbpToCadRate" and save the new price in the book object

	auto updatePirce = [=](Book& book) {
		if (book.country() == "US")
		{
			book.price() *= usdToCadRate;
		}
		else if (book.country() == "UK" && book.year() <= 1999 && book.year() >= 1990)
		{
			book.price() *= gbpToCadRate;
		}
		return book.price();
	};


	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";

	//  iterate over the library and update the price of each book
	//  using the lambda defined above.
	for (unsigned i = 0; i < library.size(); i++)
	{
		library[i].price() = updatePirce(library[i]);
	}

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";

	Collection<Movie> theCollection("Action Movies");

	// Process the file
	Movie movies[5];
	if (argc > 2) {
		//  load 5 movies from the file "argv[2]".
		//  - read one line at a time, and pass it to the Movie constructor
		//  - store each movie read into the array "movies"
		//  - lines that start with "#" are considered comments and should be ignored
		std::ifstream fin(argv[2]);
		size_t noOfMovies = 0;
		if (!fin)
		{
			std::cerr << "AppErrors::CannotOpenFile\n";
			return 1;
		}
		std::string strMovie;
		do
		{
			std::getline(fin, strMovie);
			if (fin && noOfMovies < 5)
			{
				if (strMovie[0] != '#')
				{
					movies[noOfMovies] = sdds::Movie(strMovie);
					noOfMovies++;
				}
			}
		} while (fin);
	}

	std::cout << "-----------------------------------------\n";
	std::cout << "Testing addition and callback function\n";
	std::cout << "-----------------------------------------\n";
	if (argc > 2) {
		// Add a few movies to collection; no observer is set
		((theCollection += movies[0]) += movies[1]) += movies[2];
		theCollection += movies[1];
		// add more movies; now we get a callback from the collection
		theCollection.setObserver(movieAddedObserver);
		theCollection += movies[3];
		theCollection += movies[3];
		theCollection += movies[4];
	}
	else {
		std::cout << "** No movies in the Collection\n";
	}
	std::cout << "-----------------------------------------\n\n";
	
	std::cout << "-----------------------------------------\n";
	std::cout << "Testing exceptions and operator[]\n";
	std::cout << "-----------------------------------------\n";


		//The following loop can generate generate an exception
		// write code to handle the exception
		//If an exception occurs print a message in the following format
		// ** EXCEPTION: ERROR_MESSAGE<endl>
		// where ERROR_MESSAGE is extracted from the exception object.
	bool goodidx = true;
	for (auto i = 0u; i < 10 && goodidx; ++i)
	{
		try
		{
			std::cout << theCollection[i];
		}
		catch (const std::out_of_range& oor) {
			std::cout << "** EXCEPTION: "<< oor.what() << std::endl;
			goodidx = false;
		}

	}			

	std::cout << "-----------------------------------------\n\n";

	std::cout << "-----------------------------------------\n";
	std::cout << "Testing the functor\n";
	std::cout << "-----------------------------------------\n";
	for (auto i = 3; i < argc; ++i)
	{
			// The following statement can generate generate an exception
			// write code to handle the exception
			// If an exception occurs print a message in the following format
			// ** EXCEPTION: ERROR_MESSAGE<endl>
			// where ERROR_MESSAGE is extracted from the exception object.
		try
		{
			SpellChecker sp(argv[i]);
			for (auto j = 0u; j < library.size(); ++j)
				library[j].fixSpelling(sp);
			sp.showStatistics(std::cout);

			for (auto j = 0u; j < theCollection.size(); ++j)
				theCollection[j].fixSpelling(sp);
			sp.showStatistics(std::cout);
		}
		catch (const char* msg) {
			std::cout << "** EXCEPTION: " << msg << std::endl;
		}
				

	}
	if (argc < 3) {
		std::cout << "** Spellchecker is empty\n";
		std::cout << "-----------------------------------------\n";
	}
	std::cout << "\n";

	std::cout << "=========================================\n";
	std::cout << "Wrapping up this workshop\n";
	std::cout << "--------------- Movies ------------------\n";
	std::cout << theCollection;
	std::cout << "--------------- Books -------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n";
	std::cout << "Testing operator[] (the other overload)\n";
	std::cout << "-----------------------------------------\n";
	const Movie* aMovie = theCollection["Terminator 2"];
	if (aMovie == nullptr)
		std::cout << "** Movie Terminator 2 not in collection.\n";
	aMovie = theCollection["Dark Phoenix"];
	if (aMovie != nullptr)
		std::cout << "In this collection:\n" << *aMovie;
	std::cout << "-----------------------------------------\n\n";

	return 0;
}
