/*Monte Roybal
Shopping Cart Functions*/

/*Link Section*/
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "functions.hpp"
using namespace std;

/*Add Single Item Function*/
int addSingItems(Cart *s,Item *i,Item *i1,Item *i2,int c,int a,string m)
{
	if(a==0)//Check if Item Count is 0 to Purchase 1st Item
    {
    	s->addItem(i,c);
    	cout<<"PURCHASHED: "<<s->dispTitle(c)<<" By "<<s->dispArtist(c)<<" For $"<<i->getPrice()<<endl;
    	c+=1;//Increment Total Item Count
        a+=1;//Increment Individual Item Count
        return(a);
    }
    else if(a==1)//Check if Item Count is 1 to Purchase 2nd Item
    {
    	s->addItem(i1,c);
    	cout<<"PURCHASHED: "<<s->dispTitle(c)<<" By "<<s->dispArtist(c)<<" For $"<<i1->getPrice()<<endl;
    	c+=1;//Increment Total Item Count
        a+=1;//Increment Individual Item Count
        return(a);
    }
    else if(a==2)//Check if Item Count is 2 to Purchase 3rd Item
    {
        s->addItem(i2,c);
    	cout<<"PURCHASHED: "<<s->dispTitle(c)<<" By "<<s->dispArtist(c)<<" For $"<<i2->getPrice()<<endl;
        c+=1;//Increment Total Item Count
        a+=1;//Increment Individual Item Count
        return(a);
    }
    else//Check if 3 Items have Already been Purchased
    {
    	cout<<m<<endl;//Display Message String
    	return(99);
    }
}
/*Add Multiple Items Function*/
int addMultItems(Cart *s,Item *i,Item *i1,Item *i2,int c,int a)
{
	s->addItem(i,c);
    cout<<"PURCHASHED: "<<s->dispTitle(c)<<" By "<<s->dispArtist(c)<<" For $"<<i->getPrice()<<endl;
	c++;
	s->addItem(i1,c);
    cout<<"PURCHASHED: "<<s->dispTitle(c)<<" By "<<s->dispArtist(c)<<" For $"<<i->getPrice()<<endl;
	c++;
	if(a>=3)
	{
		s->addItem(i2,c);
        cout<<"PURCHASHED: "<<s->dispTitle(c)<<" By "<<s->dispArtist(c)<<" For $"<<i->getPrice()<<endl;
		c++;
	}
	return(c);
}
/*Print Cart Contents to File Function*/
int printToFile(Cart *s,int c)
{
	ofstream cartOut;
	cartOut.open("shopping_cart.txt");//Open file variable
	if(cartOut!=NULL)//Check for file variable existense
	{
		cartOut<<"CART CONTENTS:\n";
		for(int i=0;i<c;i++)
		{
	        cartOut<<s->dispGenre(i)<<" "<<s->dispType(i)<<": "<<s->dispTitle(i)<<" By "<<s->dispArtist(i)<<"| $"<<s->dispPrice(i)<<endl;//Write Cart Contents/Summary Out to File
		}
		cartOut<<"\n"<<c<<" ITEMS"<<"\nTOTAL: $"<<s->totalPrice<<"\n\nThank You For Shopping at Monte's Virtual Shopping Cart!"<<endl;
	}
	cartOut.close();//Close file variable
	return(0);
}