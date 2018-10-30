/*Monte Roybal
Book Class*/

/*Link Section*/
#include <iostream>
#include <typeinfo>
#include "book.hpp"
using namespace std;

/*Book Class Constructor Member Function Definition with Parameters*/
Book::Book(string t,string a,string g,int p)
{
	title = t;	
	author = a;
	genre = g;
	price = p;
}
/*Virtual Member Function to Get Artist*/
string Book::getArtist()
{
	return(author);
}
/*Virtual Member Function to Get Object Type*/
string Book::getType(int c)
{
	return(typeid(Book).name());
}
