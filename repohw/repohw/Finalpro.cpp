#include <iostream>
using namespace std;
int main()
{
	int month, date;
	cout<< "enter your birth month:";cin>>month;
   cout<< endl;
    cout<< "enter your day that you were born:";cin>>date;
    cout<< endl;
    if(month==3 && date >= 21 ||  month == 4 && date <=20)
    	{cout<<"Your astrology sign is a Aries!";cout<<endl;}
    else if (month == 4 && date >= 21 || month == 5 && date <= 21)
    	{cout<<"Your astrology sign is a Taurus!"; cout<<endl;}
    else if (month == 5 && date >= 22 || month == 6 && date <=22)
    	{cout<<"Your astrology sign is a Gemini!"; cout<<endl;}
    else if (month == 6 && date >= 23 || month== 7 && date <=23)
    	{cout<<"your astrology sign is a Cancer!"; cout<<endl;}
    else if (month == 7 && date >=24 || month == 8 && date <=23)
    	{cout<<"Your astrology sign is a Leo!"; cout<<endl;}
    else if (month == 8 && date >= 24 || month == 9 && date <=23)
    	{cout<<"Your astrology sign is a Virgo!"; cout<<endl;}
    else if (month == 9 && date >= 24 || month == 10 && date <=23)
    	{cout<<"Your astrology sign is a Libra!"; cout<<endl;}
    else if (month == 10 && date >= 24 || month == 11 && date <=22)
    	{cout<<"Your astrology sign is a Scoripio!"; cout<<endl;}
    else if (month == 11 && date >= 24 || month == 12 && date <=21)
    	{cout<<"Your astrology sign is a Saguittarious!"; cout<<endl;}
    else if (month == 12 && date >= 22 || month == 1 && date <= 20)
    	{cout<<"Your astrology sign is a Capricorn!"; cout<<endl;}
    else if (month == 1 && date >= 21 || month == 2 && date <=19)
    	{cout<<"Your astrology sign a Aquarious"; cout<<endl;}
    else if (month ==2 && date >= 20 || month == 3 && date <= 20)
    	{cout<<"Your astrology sign is a Pieces"; cout<<endl;}
    cout<<endl;
    ("pause");
}
