/*Monte Roybal
Magazine Class Header File*/

/*Link Section*/
#ifndef magazine_hpp 
#define magazine_hpp
#include "item.hpp"
#include <iostream>
using namespace std;

class Magazine : public Item//Public Inheritance From Item Class
{
	private://Private Access Modifier Declaration
		string contributor;//Private Data Member Declaration
	public://Public Access Modifier Declaration
		Magazine(string,string,string,float);//Constructor Member Function Declaration
		string getArtist();//Virtual Member Function Get Artist Declaration
		string getType(int c);//Virtual Member Function Get Object Type Declaration
		/*Using Inherited Member Functions Declarations*/
		using Item::getTitle;
		using Item::getGenre;
		using Item::getPrice;
};
#endif