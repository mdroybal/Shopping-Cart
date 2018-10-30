/*Monte Roybal
Shopping Cart Main Function*/

/*Link Section*/
#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include <fstream>
#include "item.hpp"
#include "cart.hpp"
#include "cd.hpp"
#include "book.hpp"
#include "magazine.hpp"
#include "functions.hpp"
using namespace std;

int cdCount,bookCount,magCount = 0;
/*Main Function*/
int main()
{
	/*Local variable's declarations and definitions*/
	int uIn = 1;
	int count = 0;
	int costs[9];
	string bookTitles[3] = {"Do Androids Dream of Electric Sheep","The Man Without Qualities","Where The Wild Things Are"};
	string cdTitles[3] = {"Rockin The 80s","Hit Country","90's Pop"};
	string magTitles[3] = {"Forbes","National Geographic","Time Magazine"};
	string artists[9] = {"Johnny Mash","Buck Bowens","Lavagna Johns","Jim Nicholson","Hash Mays","Alice Crown","Wayne Nelson","Jessie Gold","Maya Hauss"}; 
	int tLen = sizeof(bookTitles)/sizeof(bookTitles[0]);
    /*Iteratively Generate Random Numbers for Item Prices*/
    for(int i=0;i<9;i++)
    {
	    costs[i] = rand() % 29 + 12;
    }
    /*CD, Book and Magazine Object's Instantiations*/
	Book book1(bookTitles[count%tLen],artists[count%tLen],"Fiction",costs[0]);
    count+=1;//Keep count of Number of Objects for Modular Arithmetic for Title Arrays
	Book book2(bookTitles[count%tLen],artists[count%tLen],"Non-Fiction",costs[1]);
	count+=1;
	Book book3(bookTitles[count%tLen],artists[count%tLen],"Fantasy",costs[2]);
	count+=1;
	Magazine mag1(magTitles[count%tLen],artists[count%tLen],"Zine",costs[3]);
    count+=1;
	Magazine mag2(magTitles[count%tLen],artists[count%tLen],"Comic",costs[4]);
	count+=1;
	Magazine mag3(magTitles[count%tLen],artists[count%tLen],"Pulp",costs[5]);
	count+=1;
	CD cd1(cdTitles[count%tLen],artists[count%tLen],"Country",costs[6]);
	count+=1;
	CD cd2(cdTitles[count%tLen],artists[count%tLen],"Rock",costs[7]);
	count+=1;
	CD cd3(cdTitles[count%tLen],artists[count%tLen],"Pop",costs[8]);
	count+=1;
    /*Instantiate Cart Object*/
    Cart c1;
    cout<<"Welcome To Monte's Virtual Shopping Cart!\nAt Any Time Enter\n(0) to quit\n(3) to Display Contents of Cart\n(4) to Checkout\n(5) to Write Cart Contents to File\n";

    count = 0;//Reset Count
    /*Infinite Menu Loop*/
    while(uIn!=0)//loop until user enters integer 0
    {
    	cout<<"\nPlease Enter:\n(1) to buy one item\nor\n(2) to buy several items"<<endl;
    	cin>>uIn;
		if(uIn==1)//Check if user input singleChoice is equivalent to 1 to Purchase Single Item
	    {
	    	int sCh;
            cout<<"\nWould you like to purchase a:\n(1) Book\n(2) CD\n(3) Magazine"<<endl;
            cin>>sCh;
            if(sCh==1)//Check if user input singleChoice is equivalent to 1 to Purchase Book Object
            {
                bookCount = addSingItems(&c1,&book1,&book2,&book3,count,bookCount,"Sorry You have already purchased all the Books!");	
                if(bookCount!=99)
                {
                    count+=1;//Keep count of Objects Purchased
                }
            }	    
		    else if(sCh==2)//Check if user input singelChoice is equivalent to 2 to Purchase CD Object
            {
                cdCount = addSingItems(&c1,&cd1,&cd2,&cd3,count,cdCount,"Sorry You have already purchased all the CDs!");	
                if(cdCount!=99)
                {
                    count+=1;
                }
            }
            else if(sCh==3)//Check if user input singleChoice is equivalent to 3 to Purchase Magazine Object
            {
                magCount = addSingItems(&c1,&mag1,&mag2,&mag3,count,magCount,"Sorry You have already purchased all the Magazines!");	
                if(magCount!=99)
                {
                    count+=1;
                }
            }
            else if(sCh==0)
            {
            	uIn = 0;//Break Loop
            }
	    }

        else if (uIn==2)//Check if user input is equivalent to 2 to Purchase Multiple Items
        {
            int amt;
            int mCh;
            cout<<"How many Items Would You Like to Purchase: ";
            cin>>amt;
            if(amt>1)//Check if user input Amount is greater than 1
        	{
        		if(amt>=4)//Check if user input Amount is greater than 4, Only 3 or less Objects can be purchased simultaneously
        		{
        			cout<<"Sorry you Cannot Purchase more than 3 Items at Once!!"<<endl;
        		}
        		else if(count<=6)//Check if Most the Items Have Been purchased
        		{	
	        		if(amt>=2)//Check if user input Amount is greater than 2 to purchase multiple Objects
	        		{
		        		cout<<"Would like to purchase\n(1) CDs\n(2) Books\n(3) Magazines\n(4) Multiple Items"<<endl;
		        		cin>>mCh;
		        		if(mCh==1 && cdCount==0)//Check if user input multChoice is 1 for CDs and none have been purchased
		        		{	
	                        count = addMultItems(&c1,&cd1,&cd2,&cd3,count,amt);//Keep Count of Object Purchases with returned Count
		        		    cdCount=+2; 
		        		}
		        		else if(mCh==2 && bookCount==0)//Check if user input multChoice is 2 for Books and none have been purchased
		        		{
	                        count = addMultItems(&c1,&book1,&book2,&book3,count,amt);
		        		    bookCount=+2; 		        		}
		        		else if(mCh==3 && magCount==0)//Check if user input multChoice is 3 for Magazines and none have been purchased
		        		{
	                        count = addMultItems(&c1,&mag1,&mag2,&mag3,count,amt);	        			        			
	                        magCount=+2;		        		
		        		}
		        		else if(mCh==4 && cdCount==0 && bookCount ==0 && magCount==0)//Check if user input multChoice is 4 for different type Objects and none have been purchased
		        		{
	                        count = addMultItems(&c1,&cd1,&book2,&mag3,count,amt);	
	                        cdCount=+1;
	                        bookCount=+1;
	                        magCount=+1;	                        
		        		}
		        		else if(mCh==0)
		        		{
		        			uIn = 0;//Break Loop
		        		}
		        		else
		        		{
		        			cout<<"Sorry you have already purchased Nearly All Those Items!!"<<endl;
		        		}
	        	    }
		        }
		        else//Output to Console Message if Most Items Have Been purchased
		        {
		        	cout<<"Sorry you Have Already Purchased Nearly All the Items!!"<<endl;

		        }
        	}
		    else//More Than One Item Must Be purchased
    	    {
    	    	cout<<"You Must Purchase More Than One Item!"<<endl;
    	    }
        }
	    else if(uIn==3)//Check if user input is equivalent to 3 to Display Cart Information/Contents
	    {
	    	c1.dispInfo(count);
	    }
	    else if(uIn==4)//Check if user input is equivalent to 4 to Summarize Cart Contents and Display Information
	    {
	    	c1.sumContents(count);
	    	cout<<"CART CONTENTS:"<<endl;
	    	c1.dispInfo(count);	    
	    }
	    else if(uIn==5)//Check if user input is equivalent to 5 to Print Cart Contents and Summary to File
	    {
	    	printToFile(&c1,count);
	    }
        else if(uIn==0)
        {
        	uIn = 0;//Break Loop
        }	 
    }
    return(0);//Return 0 for Successful Execution
}
