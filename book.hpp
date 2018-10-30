/*Monte Roybal
Book Class Header File*/

/*Link Section*/
#ifndef book_hpp 
#define book_hpp
#include "item.hpp"
#include <iostream>
using namespace std;

class Book : public Item//Public Inheritance From Item Class
{
	private://Private Access Modifier Declaration
		string author;//Private Data Member Declaration
	public://Public Access Modifier Declaration
		Book(string,string,string,int);//Constructor Member Function Declaration
		string getArtist();//Virtual Member Function Get Artist Declaration
		string getType(int c);//Virtual Member Function Get Object Type Declaration
		/*Using Inherited Member Functions Declarations*/
		using Item::getTitle;
		using Item::getGenre;
		using Item::getPrice;
};
#endif