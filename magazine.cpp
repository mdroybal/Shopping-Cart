/*Monte Roybal
Magaize Class*/

/*Link Section*/
#include <iostream>
#include <typeinfo>
#include "magazine.hpp"
using namespace std;

/*Magazine Class Constructor Member Function Definition with Parameters*/
Magazine::Magazine(string t,string c,string g,float p)
{
	title = t;	
	contributor = c;
	genre = g;
	price = p;
}
/*Virtual Member Function to Get Artist*/
string Magazine::getArtist()
{
	return(contributor);
}
/*Virtual Member Function to Get Object Type*/
string Magazine::getType(int c)
{
	return(typeid(Magazine).name());
}