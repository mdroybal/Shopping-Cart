/*Monte Roybal
Item Class Header File*/

/*Link Section*/
#ifndef item_hpp 
#define item_hpp
#include <iostream>
using namespace std;

class Item{
    public://Public Access Modifier Declaration
    	/*Public Data Members Declarations*/
    	string title;
    	string genre;
    	int price;
		string getTitle();//Member Function Get Item Title Declaration
        string getGenre();//Member Function Get Item Genre Declaration
		int getPrice();//Member Function Get Price Genre Declaration
    	virtual string getArtist();//Virtual Member Function Get Artist Declaration
    	virtual string getType(int);//Virtual Member Function Get Type Declaration
};
#endif