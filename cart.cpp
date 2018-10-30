/*Monte Roybal
Shopping Cart Class*/

/*Link Section*/
#include <iostream>
#include "cart.hpp"
using namespace std;

/*Cart Class Constructor Member Function Definition Set to Default Parameters*/
Cart::Cart()
{
	Item *cart[40];
	totalPrice = 0;
}
/*Member Function to Store Pointer to Single Item at Cart[Count]*/
int Cart::addItem(Item *i,int j)
{
	cart[j] = i;
	totalPrice+=dispPrice(j);
	return(0);  
}
/*Member Function to Display Price at Cart[Count] from Item Pointer with Arrow Operator*/
int Cart::dispPrice(int c)
{
	return cart[c]->getPrice();
}
/*Member Function to Get Item Title*/
string Cart::dispTitle(int c)
{
	return cart[c]->getTitle();
}
/*Member Function to Display Artist at Cart[Count] from Item Pointer with Arrow Operator*/
string Cart::dispArtist(int c)
{
	return cart[c]->getArtist();
}/*Member Function to Display Genre at Cart[Count] from Item Pointer with Arrow Operator*/
string Cart::dispGenre(int c)
{
	return cart[c]->getGenre();
}
/*Member Function to Display Object Type at Cart[Count] from Item Pointer with Arrow Operator*/
string Cart::dispType(int c)
{
	return cart[c]->getType(c);
}
/*Member Function to Display Information/Contents From Items in Cart*/
void Cart::dispInfo(int c)
{
	for(int i=0;i<c;i++)//Iterate to Count
	{
		cout<<"Item "<<i+1<<" "<<dispGenre(i)<<" "<<dispType(i)<<": "<<dispTitle(i)<<" By "<<dispArtist(i)<<" $"<<dispPrice(i)<<endl;
	}
}/*Member Function to Summarize Number of Items in Cart and Total Price*/
void Cart::sumContents(int c)
{
	cout<<"You have Purchased "<<c<<" Items\n"<<"The Total Is $"<<totalPrice<<endl;
}


