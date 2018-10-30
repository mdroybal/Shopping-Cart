/*Monte Roybal
Item Class*/

/*Link Section*/
#include <iostream>
#include "item.hpp"
using namespace std;

/*Member Function to Get Item Title*/
string Item::getTitle()
{
	return(title);
}
/*Member Function to Get Item Genre*/
string Item::getGenre()
{
	return(genre);
}
/*Member Function to Get Item Price*/
int Item::getPrice()
{
	return(price);
}
/*Virtual Member Function to Get Artist,Author or Contributor*/
string Item::getArtist() 
{
	return 0;
}
/*Virtual Member Function to Get Type*/    	
string Item::getType(int) 
{
	return 0;
}
