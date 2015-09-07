#include "Display.h"
#include <iostream>

using namespace std;

void Display::displayadmin(int spots)

{
	
    char car = '.';
    int rows = 0;
	int extra = 0;
	int wide = 20;

	cout << "\nAdmin Lot: " << spots << " Cars parked.\n";
    cout<<" ____________________";
    cout << endl;

    rows = (spots / wide);// sets row width
	if (spots < wide)
		extra = spots;
	if(rows > 0)
		extra = spots - (rows * wide);// stores how many extras cars to park after all full rows

	if (rows > 0)
	{
		for (int i = 0; i < rows; i++)
		{
			cout << "|";

	        for(int j=0;j<wide;j++)
	        {     
                cout << car;
            }//end for
        cout << "|";
        cout << endl;

		}//end for
	}//end if
   
	if (extra > 0)
	{
		cout << "|";
		for (int i = 0; i < extra; i++)
			cout << car;
		cout << endl;
	}
	cout << "|____________________|"<<endl;
    cout << endl << endl;
}


void Display::displayLot1(int spots)

{
	char car = '.';
    int rows = 0;
	int extra = 0;
    int wide = 100;

	cout << "\nLot 1: " << spots << " Cars parked.\n";
    cout<<" ____________________________________________________________________________________________________";
    cout << endl;

    rows = (spots / wide);// sets row width
	if (spots < wide)
		extra = spots;
	if(rows > 0)
		extra = spots - (rows * wide);// stores how many extras cars to park after all full rows

	if (rows > 0)
	{
		for (int i = 0; i < rows; i++)
		{
			cout << "|";

	        for(int j=0;j<wide;j++)
	        {     
                cout << car;
            }//end for
        cout << "|";
        cout << endl;

		}//end for
	}//end if
   
	if (extra > 0)
	{
		cout << "|";
		for (int i = 0; i < extra; i++)
			cout << car;
		cout << endl;
	}
	cout<<"|____________________________________________________________________________________________________|"<<endl;
    cout << endl << endl;
}


void Display::displayLot2(int spots)

{
	char car = '.';
    int rows = 0;
	int extra = 0;
    int wide = 100;

	cout << "\nLot 2: " << spots << " Cars parked.\n";
    cout<<" ____________________________________________________________________________________________________";
    cout << endl;

    rows = (spots / wide);// sets row width
	if (spots < wide)
		extra = spots;
	if(rows > 0)
		extra = spots - (rows * wide);// stores how many extras cars to park after all full rows

	if (rows > 0)
	{
		for (int i = 0; i < rows; i++)
		{
			cout << "|";

	        for(int j=0;j<wide;j++)
	        {     
                cout << car;
            }//end for
        cout << "|";
        cout << endl;

		}//end for
	}//end if
   
	if (extra > 0)
	{
		cout << "|";
		for (int i = 0; i < extra; i++)
			cout << car;
		cout << endl;
	}
	cout<<"|____________________________________________________________________________________________________|"<<endl;
    cout << endl << endl;
}


void Display::displayLot3(int spots)

{		
    char car = '.';
    int rows = 0;
	int extra = 0;
    int wide = 50;

	cout << "\nLot 3: " << spots << " Cars parked.\n";
    cout<<" __________________________________________________";
    cout << endl;

    rows = (spots / wide);// sets row width
	if (spots < wide)
		extra = spots;
	if(rows > 0)
		extra = spots - (rows * wide);// stores how many extras cars to park after all full rows

	if (rows > 0)
	{
		for (int i = 0; i < rows; i++)
		{
			cout << "|";

	        for(int j=0;j<wide;j++)
	        {     
                cout << car;
            }//end for
        cout << "|";
        cout << endl;

		}//end for
	}//end if
   
	if (extra > 0)
	{
		cout << "|";
		for (int i = 0; i < extra; i++)
			cout << car;
		cout << endl;
	}
	cout<<"|__________________________________________________|"<<endl;
    cout << endl << endl;
}


void Display::displayopen(int spots)


{
	char car = '.';
    int rows = 0;
	int extra = 0;
    int wide = 100;

	cout << "\nOpen Lot: " << spots << " Cars parked.\n";
    cout<<" ____________________________________________________________________________________________________";
    cout << endl;

    rows = (spots / wide);// sets row width
	if (spots < wide)
		extra = spots;
	if(rows > 0)
		extra = spots - (rows * wide);// stores how many extras cars to park after all full rows

	if (rows > 0)
	{
		for (int i = 0; i < rows; i++)
		{
			cout << "|";

	        for(int j=0;j<wide;j++)
	        {     
                cout << car;
            }//end for
        cout << "|";
        cout << endl;

		}//end for
	}//end if
   
	if (extra > 0)
	{
		cout << "|";
		for (int i = 0; i < extra; i++)
			cout << car;
		cout << endl;
	}
	cout<<"|____________________________________________________________________________________________________|"<<endl;
    cout << endl << endl;
}


void Display::displaymaint(int spots)

{
    char car = '.';
    int rows = 0;
	int extra = 0;
    int wide = 50;

	cout << "\nMaintance: " << spots << " Cars parked.\n";
    cout<<" __________________________________________________";
    cout << endl;

    rows = (spots / wide);// sets row width
	if (spots < wide)
		extra = spots;
	if(rows > 0)
		extra = spots - (rows * wide);// stores how many extras cars to park after all full rows

	if (rows > 0)
	{
		for (int i = 0; i < rows; i++)
		{
			cout << "|";

	        for(int j=0;j<wide;j++)
	        {     
                cout << car;
            }//end for
        cout << "|";
        cout << endl;

		}//end for
	}//end if
   
	if (extra > 0)
	{
		cout << "|";
		for (int i = 0; i < extra; i++)
			cout << car;
		cout << endl;
	}
    cout<<"|__________________________________________________|"<<endl;
	cout << endl << endl;
	
}


void Display::displayoverflow(int spots)

{
	char car = '.';
    int rows = 0;
	int extra = 0;
    int wide = 100;

	cout << "\nOverflow: " << spots << " Cars parked.\n";
    cout<<" ____________________________________________________________________________________________________";
    cout << endl;

    rows = (spots / wide);// sets row width
	if (spots < wide)
		extra = spots;
	if(rows > 0)
		extra = spots - (rows * wide);// stores how many extras cars to park after all full rows

	if (rows > 0)
	{
		for (int i = 0; i < rows; i++)
		{
			cout << "|";

	        for(int j=0;j<wide;j++)
	        {     
                cout << car;
            }//end for
        cout << "|";
        cout << endl;

		}//end for
	}//end if
   
	if (extra > 0)
	{
		cout << "|";
		for (int i = 0; i < extra; i++)
			cout << car;
		cout << endl;
	}
    cout<<"|____________________________________________________________________________________________________|"<<endl;
	cout << endl << endl;
}	


void Display::displayDorm(int spots)
		{
				
    char car = '.';
    int rows = 0;
	int extra = 0;
    int wide = 50;

	cout << "\nDorm: " << spots << " Cars parked.\n";
    cout<<" __________________________________________________";
    cout << endl;

    rows = (spots / wide);// sets row width
	if (spots < wide)
		extra = spots;
	if(rows > 0)
		extra = spots - (rows * wide);// stores how many extras cars to park after all full rows

	if (rows > 0)
	{
		for (int i = 0; i < rows; i++)
		{
			cout << "|";

	        for(int j=0;j<wide;j++)
	        {     
                cout << car;
            }//end for
        cout << "|";
        cout << endl;

		}//end for
	}//end if
   
	if (extra > 0)
	{
		cout << "|";
		for (int i = 0; i < extra; i++)
			cout << car;
		cout << endl;
	}
    cout<<"|__________________________________________________|";
    cout << endl << endl;
}
		