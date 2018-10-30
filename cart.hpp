/*Monte Roybal
Shopping Cart Class Header File*/

/*Link Section*/
#ifndef cart_hpp 
#define cart_hpp
#include <iostream>
#include "item.hpp"
using namespace std;

class Cart{
    public://Public Access Modifier Declaration
    	/*Public Data Members Declarations*/
        Item *cart[40];
        int totalPrice;
        Cart();//Constructor Member Function without Parameters
        int addItem(Item *i,int j);//Member Function Add Item Declaration
        int dispPrice(int c);//Member Function Display Price Declaration
        string dispTitle(int c);//Member Function Display Title Declaration
        string dispArtist(int c);//Member Function Display Artist Declaration
        string dispGenre(int c);//Member Function Display Genre Declaration
        string dispType(int c);//Member Function Display Type Declaration
        void dispInfo(int c);//Member Function Display Information/Contents Declaration
        void sumContents(int c);//Member Function Summarize Contents Declaration
};
#endif
