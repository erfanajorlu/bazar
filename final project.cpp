#include<bits/stdc++.h>
using namespace std;
//tabdil string be double
double stoii(string s)
{
double ans = 0;
int cnt = 0;
for(int i =0;i < s.size() ;i++)
{
	if( s[i] == '.')
	cnt = i;
	else
	{
		ans *= 10;
		ans += s[i] - '0';
	}
}
for(int i =0;i < s.size() - cnt - 1;i++)
	ans /= 10;
return ans;
}
//tabdil string be double bedun ashar
double sm(string a)
{
	double ans;
	int cnt = 0;
	for(int i =0;i<a.size();i++)
	{
		ans *= 10;
		ans += a[i] - '0';
	}
	return ans;
}
class bazar{
	private:
		string symbol , name1;
		double gheymat , volume;
		public:
			void setsymbol(string a)
			{
				symbol = a;
			}
			string getsymbol()
			{
				return symbol;
			}
			void setnam(string a)
			{
				name1 = a;
			}
			string getnam()
			{
				return name1;
			}
			void setgheymat(double a)
			{
				gheymat = a;
			}
			double getgheymat()
			{
				return gheymat;
			}
			void setvolume(double a)
			{
				volume = a;
			}
			double getvolume()
			{
				return volume;
			}			
};
//gereftan list sahamha
bazar stocks[500];
class user{
	private:
		string username , name , lastname , password;
		string ID , shebanumber , codenumber;
		int  saham , tdsh;
		double debt , fund ;
		vector <string>ssymbol;
		vector<string>names;
		vector <double> ghey;
		vector <double> vol;
		public:
			void settd(int l)
			{
				tdsh = l;
			}
			int gettd()
			{
				return tdsh;
			}
			void setsaham(int k)
			{
				saham = k;
			}
			int getsaham()
			{
				return saham;
			}
			//ezafe kardan saham be wallet
			void setx(string x , int vol1)
			{
				ssymbol.push_back(x);
				vol.push_back(vol1);
				for(int i =0;i < 495;i++)
				{
					if(stocks[i].getsymbol() == x)
					{
						names.push_back(stocks[i].getnam());
						ghey.push_back(stocks[i].getgheymat());
						saham += stocks[i].getgheymat() * vol1;
						break;
					}
				}
			}
			//kharid saham
			void kharid(string s,int tedad)
			{
				int l;
				for(int i=0;i < 495;i++)
				{
					if(stocks[i].getsymbol() == s)
					{
						l = i;
						break;
					}
				}
				if(stocks[l].getgheymat() * tedad <= fund)
				{
					fund -= stocks[l].getgheymat() * tedad;
				ssymbol.push_back(stocks[l].getsymbol());
					names.push_back(stocks[l].getnam());
					ghey.push_back(stocks[l].getgheymat());
					vol.push_back(tedad);
					tdsh++;	
				}
				else
				{
					system("CLS");
					cout <<"you don't have money please charge your acount =)" << endl << endl;
				} 
			}  
			//forush saham
			void sell(string s,int tedad)
			{
				int l;
				for(int i=0;i < tdsh;i++)
				{
					if(ssymbol[i] == s)
					{
						l = i;
						break;
					}
				}
				
				if(tedad == vol[l])
				{
					ssymbol.erase(ssymbol.begin() + l);
					names.erase(names.begin() + l);
					fund += tedad * ghey[l];
					ghey.erase(ghey.begin() + l);
					vol.erase(vol.begin() + l);
					tdsh--;
				}
				else
				{
					vol[l] -= tedad;
					fund += tedad * ghey[l];
				}
			}
			// print saham hai ke dar wallet darim //
			void printsaham() const
			{
				system("CLS");
				for(int i = 0;i < tdsh;i++)
				{
					cout << ssymbol[i] << " "<<names[i] << " "<<ghey[i] << "             " << "you have " << vol[i] << "of these saham " <<  endl;
				}
				cout << endl;
			}
			string getsymbol(int h)
			{
				return ssymbol[h];
			}
			double getvol2(int h)
			{
				return vol[h];
			}
			void setuname(string a)
			{
				username = a;
			}
			string getuname()
			{
				return username;
			}
			void setname(string a)
			{
				name = a;
			}
			string getname()
			{
				return name ;
			}
			void setlname(string a)
			{
				lastname = a;
			}
			string getlname()
			{
				return lastname;
			}
			void setpass(string a)
			{
				password = a;
			}
			string getpass()
			{
				return password;
			}
			void setid(string a)
			{
				ID = a;
			}
			string getid()
			{
				return ID;
			}
			void setsheba(string a)
			{
				if(a[0] == 'I' && a[1] == 'R')
				shebanumber = a;
				else
				{
				string x = "IR";
				x += a;
				shebanumber = x;
				}
			}
			string getsheba(){
				return shebanumber;
			}
			void setcodenumber(string a)
			{
				codenumber = a;
			}
			string getcode()
			{
				return codenumber;
			}
			void setdebt(double a)
			{
				debt = a;
			}
			double getdebt()
			{
				return debt;
			}
			void setfund(double a)
			{
				fund = a;
			}
			double getfund()
			{
				return fund;
			}
};
int main()
{
	int y;
		ofstream f5("stock_market_data",ios::app);
					ifstream f4("stock_market_data");
    					string wholefile;
						//khundan tamamie saham excel    
	for(int i = 0;i < 500;i++)
	{
		string arr[5];
		int k = 0;
		int  index = 0;
		f4 >> y;
		getline(f4,wholefile);	
		for (int j = 0;j < wholefile.length();j++)
		{
			if(wholefile[j] == '?')
			{
				arr[k] = wholefile.substr(index +1, j-index - 1);
				index = j;
				k++;	
			}
		}
		double s3;
		stocks[i].setsymbol(arr[1]);
		stocks[i].setnam(arr[2]);
		s3 = stoii(arr[3]);
		stocks[i].setgheymat(s3);
		s3 = sm(arr[4]);
		stocks[i].setvolume(s3);
	}
	
	int num , x1;
	ofstream f1("fs" ,ios::app);
	ifstream f2("fs");	
	int jack;
	//khandan tedad accounts
	if(f2 >> x1)
	{
		num = x1;
	}
	else
	{
		x1 = 0;
		num = x1;
	}
	
	cout << "list = " << endl;
	cout << "1 = creat new account "<<endl << "2 = login" << endl << "3 = charge account" << endl;
	 cout << "4 = buy " << endl << "5 = sell" << endl << "6 = saw your wallet "<<endl;
	 cout << "7 = watch list of holding" << endl << "8 = exit" << endl;
	 int e = 99999;
	 string h;
	 	//tedad accountha ba yek jam mishavad ta code error nade
	  	user x[num + 1];
	  	//khandan information az file
	  	//save krdn information ha dar arrayei az class account
		 for(int i = 0;i < num;i++)
		 {
		 	string ss;
		 	string sa;
		 	int sas;
		 	double sfa;
		 	x[i].setsaham(0);
		 	f2 >> ss;
		 	x[i].setuname(ss);
		 	f2 >> ss;
		 	x[i].setpass(ss);
		 	f2 >> ss;
		 	x[i].setname(ss);
		 	f2 >> ss;
		 	x[i].setlname(ss);
		 	f2 >> sa;
		 	x[i].setid(sa);
		 	f2 >> sa;
		 	x[i].setcodenumber(sa);
		 	f2 >> sa;
		 	x[i].setsheba(sa);
		 	f2 >> sfa;
			x[i].setdebt(sfa);
			f2 >> sfa;
			x[i].setfund(sfa);
			 f2 >> sas;
			 x[i].settd(sas);
			 
			 for(int j = 0;j<sas; j++)
			 {
			 	int jak;
			 	f2 >> ss;
			 	f2 >> jak;
			 	x[i].setx(ss , jak);
			 } 
		 } 
		
		//pak kardan information haye ghabli
		 ofstream f3("fs",ios::out);
		 
			f3.close();
			string s;
		 
		cout << "enter number =";
		cin >> e;	 
		
		//creat new account
	 if(e == 1)
	 {
	 	num++;
	 	cout << "enter username =";
	 	cin >> s;
	 	x[num - 1].setuname(s);
	 		 cout << "enter password = ";
		 	cin >> s;
	 		x[num - 1 ].setpass(s);
	 		cout << "enter name = ";
	 	cin >> s;
	 	x[num - 1].setname(s);
	 	cout << "enter last name = ";
	 	cin >> s;
	 	x[num - 1].setlname(s);
	 	cout<<"enter ID number => ";
		 cin >> h;
	 	x[num - 1].setid(h);
		 cout << "enter code number =";
	 	cin >> h;
	 	x[num - 1].setcodenumber(h);
	 	cout << "enter shebanumber =  ";
	 	cin >> h;
	 	 x[num - 1].setsheba(h);
	 	x[num - 1].setdebt(0);
	 	x[num - 1].setfund(0);
	 	jack = num - 1;
		x[jack].settd(0);
		system("CLS");
	cout << "list = " << endl;
	cout << "1 = creat new account "<<endl << "2 = change your information" << endl << "3 = charge account" << endl;
	 cout << "4 = buy " << endl << "5 = sell" << endl << "6 = saw your wallet "<<endl;
	 cout << "7 = watch list of holding" << endl << "8 = exit" << endl;
	 }
	 //login krdn dr account
	 if (e == 2)
	 {
	 	cout << "enter username =";
	 	cin >> s;
		for(int i = 0;i < num;i++)
		{
			if(s == x[i].getuname())
			{
				
				jack = i;
				break;
			}
		}

			while(s != x[jack].getpass())
			{	
			cout <<"enter password = ";
			cin >> s;
			if(s == x[jack].getpass())
			break;
			else
				{
				cout << "your password incorrect =)" << endl;
				}
			}
		
			system("CLS");
			cout << "list = " << endl;
			cout << "1 = creat new account "<<endl << "2 = change your information" << endl << "3 = charge account" << endl;
	 		cout << "4 = buy " << endl << "5 = sell" << endl << "6 = saw your wallet "<<endl;
	 		cout << "7 = watch list of holding" << endl << "8 = exit" << endl;
	 	
}
		 while(e != 8)
		 {
		 	cout <<"enter number =";
	 		cin >> e;
	 		if(e == 2)	 		{
	 			int afl;  string poi; string kk;
				cout << "TO CHANGE YOUR INFORMATION ENTER NUMBER FROM LIST " << endl;
				cout << "1-name\n2-last name \n3-password \n4-ID \nenter number ==";
				 cin >> afl;
				 if(afl == 1)
			 {
				 	cout << "enter new name =";
				 	cin >> poi;
				 	x[jack].setname(poi);
				 }
				 if(afl == 2)
				 {
				 	cout << "enter new lastname =";
				 	cin >> poi;
				 	x[jack].setlname(poi);
				 }
				if(afl == 3)
				{
					cout << "enter new password =";
					cin >> poi;
					x[jack].setpass(poi);
				}
				if(afl == 4)
				{
				cout << "enter new ID number =";
				cin >> kk;
				x[jack].setid(kk);
				}
				system("CLS");
					cout << "list = " << endl;
				cout << "1 = creat new account "<<endl << "2 = change your information" << endl << "3 = charge account" << endl;
	 			cout << "4 = buy " << endl << "5 = sell" << endl << "6 = saw your wallet "<<endl;
			 	cout << "7 = watch list of holding" << endl << "8 = exit" << endl;
	 		}
	 		//charge kardan account 
	 if (e == 3)
	 {
	 	system("CLS");
	 	cout << "if you want to charge your acc enter 1 if you want to withdraw money enter 2 =)";
	 	cout << endl << "enter number 1 or 2 " << endl;
	 	int gg;
	 	double gg1;
	 	cin >> gg;
	 	if(gg == 1)
	 	{
	 		cout << "how much do you want charge ???";
	 		cin >> gg1;
	 		
	 		if(x[jack].getfund() >= 0)
	 		{
	 		gg1 += x[jack].getfund();
	 		x[jack].setfund(gg1);
			}
			else
			{
				if(gg1 > x[jack].getdebt())
				{
					gg1 -= x[jack].getdebt();
					x[jack].setdebt(0);
					x[jack].setfund(gg1);
				}
				else
				{
					double uu = x[jack].getdebt() - gg1;
					x[jack].setdebt(uu);
				}
			}
		 }
	 	else
	 	{
	 		cout << "how much do you want spent ???";
	 		cin >> gg1;
	 		
	 		if(x[jack].getdebt() > 0)
	 		{
	 		gg1 += x[jack].getdebt();
	 		x[jack].setdebt(gg1);
			}
			else
			{
				if(gg1 > x[jack].getfund())
				{
					gg1 -= x[jack].getfund();
					x[jack].setfund(0);
					x[jack].setdebt(gg1);
				}
				else
				{
					double uu = x[jack].getfund() - gg1;
					x[jack].setfund(uu);
				}
			}

			}
			system("CLS");
				cout << "list = " << endl;
	cout << "1 = creat new account "<<endl << "2 = change your information" << endl << "3 = charge account" << endl;
	 cout << "4 = buy " << endl << "5 = sell" << endl << "6 = saw your wallet "<<endl;
	 cout << "7 = watch list of holding" << endl << "8 = exit" << endl;
		 
		 
	 	}
	 	//kharid az bazar
	 		if(e == 4)
	 		{
	 			system("CLS");
	 			string lk;
	 			int k1;
	 			cout << "enter symbol =";  cin >> lk;
	 			cout << "how many??   "; cin >> k1;
	 			x[jack].kharid(lk,k1);
	 		
				cout << "list = " << endl;
	cout << "1 = creat new account "<<endl << "2 = change your information" << endl << "3 = charge account" << endl;
	 cout << "4 = buy " << endl << "5 = sell" << endl << "6 = saw your wallet "<<endl;
	 cout << "7 = watch list of holding" << endl << "8 = exit" << endl;
		 
			 }
			 ///forush account ha
				if(e == 5)
				{
					system("CLS");
					string na; int sa;
					cout << "what is name the symbol you want sell ????";
					cin >> na;
					cout << "how many ????";
					cin >> sa;
				x[jack].sell(na,sa);	
				system("CLS");
				cout << "list = " << endl;
	cout << "1 = creat new account "<<endl << "2 = change your information" << endl << "3 = charge account" << endl;
	 cout << "4 = buy " << endl << "5 = sell" << endl << "6 = saw your wallet "<<endl;
	 cout << "7 = watch list of holding" << endl << "8 = exit" << endl;
		 
				} 
			 if(e == 6)
			 {
			 x[jack].printsaham();
			 
			 cout << "list = " << endl;
	cout << "1 = creat new account "<<endl << "2 = change your information" << endl << "3 = charge account" << endl;
	 cout << "4 = buy " << endl << "5 = sell" << endl << "6 = saw your wallet "<<endl;
	 cout << "7 = watch list of holding" << endl << "8 = exit" << endl;
		 
			 }
			 if(e == 7)
	 	{
	 		system("CLS");
	 			for(int i = 0;i < 495;i++)
	 			{
	 				cout << stocks[i].getsymbol() << " "<< stocks[i].getnam() << " " << (double)stocks[i].getgheymat() << " " <<stocks[i].getvolume() << endl; 
	 			}
	
	 			cout << "list = " << endl;
	cout << "1 = creat new account "<<endl << "2 = change your information" << endl << "3 = charge account" << endl;
	 cout << "4 = buy " << endl << "5 = sell" << endl << "6 = saw your wallet "<<endl;
	 cout << "7 = watch list of holding" << endl << "8 = exit" << endl;
		 
	 	}
	
	if(e == 8)
			 break;	
	 }
	 
	 
	 
	 //save kardan information ha dr file
	 f1 << num << endl;
	 
	 for(int i = 0;i< num;i++)
	 {
	 	f1 << x[i].getuname() << ' ';
	 	f1 << x[i].getpass() << ' ';
	 	f1 << x[i].getname() << ' ';
	 	f1 << x[i].getlname() << ' ';
	 	f1 << x[i].getid() << ' ';
	 	f1 << x[i].getcode() << ' ';
	 	f1 << x[i].getsheba() << ' ';
	 	f1 << x[i].getdebt() << ' ';
	 	f1 << x[i].getfund() << ' ';
	 	f1 << x[i].gettd() << endl;
	 	for(int j = 0;j < x[i].gettd();j++)
	 	{
	 	 f1 << x[i].getsymbol(j) << ' ';
		  f1 << x[i].getvol2(j) << ' '; 
	 	}
	 	f1 << endl;
	 } 
	 
return 0;	
}
