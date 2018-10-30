/*Monte Roybal
CD Class*/

/*Link Section*/
#include <iostream>
#include <typeinfo>
#include "cd.hpp"
using namespace std;

/*CD Class Constructor Member Function Definition with Parameters*/
CD::CD(string t,string a,string g,int p)
{
	title = t;	
	artist = a;
	genre = g;
	price = p;
}
/*Virtual Member Function to Get Artist*/
string CD::getArtist()
{
	return(artist);
}
/*Virtual Member Function to Get Object Type*/
string CD::getType(int c)
{
	return(typeid(CD).name());
}
