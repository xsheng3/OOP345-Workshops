#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
	string text = "The quick brown fox jumps over the lazy fox.";
	string bad = "fox";
	string good = "monkey";

	int counter = 0;

	do
	{
		cout << text.find(bad)<< " " << endl;
		text.replace(text.find(bad), bad.size(), good);
		counter++;
	} while (text.find(bad) < text.size());

	cout << text<<endl;
	cout << "counter: " << counter << endl;
	
	
	
	/*string a[6], b[6];
	int counter = 0;
	ifstream fin(argv[1]);
	while (fin >> a[counter] >> b[counter])
	{
		counter++;
	}
	for (int i = 0; i < 6; i++)
	{
		cout << a[i] << b[i] << endl;
	}*/


	/*string a[7], b[7], c[7], f[7];
	int d[7], counter = 0;
	double e[7];
	ifstream fin(argv[1]);
		while (fin >> a[counter] >> b[counter] >> c[counter] >> d[counter] >> e[counter] >> f[counter])
	{
		counter++;
	}
	for (int i = 0; i < 7; i++)
	{
		cout << a[counter] << b[counter] << c[counter] << d[counter] << e[counter] << f[counter] << endl;
	}
	*/

}