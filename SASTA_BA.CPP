#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

class Account
{
	private:
		unsigned int acc;
		char *pass;
	public:
		float balance;
		float wd;
		float dep;
		char name[20];
		char *logpass;
		unsigned int logacc;
		int i;

		void start(void);
		void withdrawl(void);
		void deposit(void);
		void details(void);
		void signup(void);
		void login(void);

};
void Account::start(void)
{
	balance=0;
	i=0;
}
void Account::withdrawl(void)
{
	if(balance>5000)
	{       cout<<"\nEnter the Withdrawl Amount";
		cin>>wd;
		balance=balance-wd;
		cout<<"\n"<<wd<<" is Withdrawn From balance,Your current balnce is "<<balance;
	}
	else
	{
		cout<<"\ninsufficient Minimum Balance,Please Deposit cash before Withdrawl";
	}
}
void Account::deposit(void)
{
	cout<<"\nEnter Amount To be deposited ";
	cin>>dep;
	balance=balance+dep;
	cout<<"\n"<<dep<<" is added in balance successfully";
}
void Account::details(void)
{
	cout<<"\n\t\t SASTA BANK";
	cout<<"\n\t\t **********";
	cout<<"\nAccount No.\tName\t\tBalance ";
	cout<<"\n"<<acc<<"\t"<<name<<"\t"<<balance;
}
void Account::signup(void)
{
	cout<<"\nWelcome to SASTA BANK Account creation portal";
	cout<<"\n*********************************************";
	cout<<"\n\nENTER your Name:\t";
	cin>>name;
	cout<<"\nEnter your 9 digit account code you want for account";
	cout<<"\n-----------------------------------------------------";
	cout<<"\nNOTE:REMEMBER THIS AS YOU'LL REQUIRE IT WHILE LOGING IN ACCOUNT";
	cout<<"\nAccount NO:\t";
	cin>>acc;
      Renterpass:cout<<"\nEnter your password atleast 9 digit account password you want for account";
	cout<<"\n-----------------------------------------------------";
	cout<<"\nNOTE:REMEMBER THIS AS YOU'LL REQUIRE IT WHILE LOGING IN ACCOUNT";
	cout<<"\nPASSWORD:\t";
	cin>>pass;
	i=strlen(pass);
	if(i<9)
	{       cout<<"Insuffient length of password";
		cout<<"\nRe-enter your Password atleast 9 digit account password you want for account";
		cout<<"\n-----------------------------------------------------";
		cout<<"\nNOTE:REMEMBER THIS AS YOU'LL REQUIRE IT WHILE LOGING IN ACCOUNT";
		goto Renterpass;

	}
	cout<<"\nYou have to keep minimum balance of 5000 in Account before using Our services";
	cout<<"\nWant to Add Minimum balance now if Yes press 1 Else 2\n";
	cin>>i;
	if(i==1)
	{
		deposit();
	}
	else
	{
		cout<<"\nITS Ok But don't forget to Add it Later ;)";
	}

}
void Account::login(void)
{       i=0;
       Renter:	cout<<"\nENTER Correct ACCOUNT NO. and Password Combination For Accessing or Services";
	cout<<"\nAccount no:\t";
	cin>>logacc;
	cout<<"\nPassword:\t";
	cin>>logpass;
	while((logacc!=acc)&&(0!=strcmp(logpass,pass)))
	{
		if((logacc!=acc)&&(0!=strcmp(logpass,pass)))
		{
			i=+1;
			if(i==3)
			{
				cout<<"\nDid you Forget Password press 1 if yes 2 if you remember";
				cin>>i;
				if(i==1)
				{
					break;
				}
				else
				{
					goto Renter;
				}

			}
		}
	 }
	 if(i==1)
	 {
		cout<<"\nEnter your 9 digit account code you want for account";
		cout<<"\n-----------------------------------------------------";
		cout<<"\nNOTE:REMEMBER THIS AS YOU'LL REQUIRE IT WHILE LOGING IN ACCOUNT";
		cout<<"\nAccount No:\t";
		cin>>acc;
		Renterpass:cout<<"\nEnter your password atleast 9 digit account password you want for account";
		cout<<"\n-----------------------------------------------------";
		cout<<"\nNOTE:REMEMBER THIS AS YOU'LL REQUIRE IT WHILE LOGING IN ACCOUNT";
		cout<<"\nPassword:\t";
		cin>>pass;
		i=strlen(pass);
		if(i<9)
		{       cout<<"\nInsuffient length of password ";
			cout<<"\nRe-enter your Password atleast 9 digit account password you want for account";
			cout<<"\n-----------------------------------------------------";
			cout<<"\nNOTE:REMEMBER THIS AS YOU'LL REQUIRE IT WHILE LOGING IN ACCOUNT";
			goto Renterpass;

		}

	 }
}

void main()
{
		Account a;
		int j=0,y=0;
		char x;
		clrscr();
		a.start();
		cout<<"\n\t\tWelcome TO Sasta Bank";
		cout<<"\n\t\t---------------------";
		do
		{
			cout<<"\nCHOOSE Option from the given menu ";
			cout<<"\n1:Create Account(Ignore IF created Already created)";
			cout<<"\n2:Login(necessarry to use the other services";
			cout<<"\nonly Add option no. associated With action";
			cout<<"\nEnter Your Choice:\t";
			cin>>j;
			switch(j)
			{
				case 1:
				{      	y=0;
					a.signup();
					y=+1;
					break;
				}
				case 2:
				{     if(y!=0)
					{
						a.login();

						do
						{       j=0;
							cout<<"\nLogin Succesful ENjoy your Services";
							cout<<"\nCHOOSE Option from the given menu ";
							cout<<"\n1:Withdrawl";
							cout<<"\n2:Deposit";
							cout<<"\n3:Details";
							cout<<"\n4:exit";
							cout<<"\nonly Add option no. associated With action";
							cout<<"\nEnter Your Choice:\t";
							cin>>j;
							switch(j)
								{
									case 1:
									{
										a.withdrawl();
										break;

									}
									case 2:
									{
										a.deposit();
										break;
									}
									case 3:
									{
										a.details();
										break;

									}
								}
								cout<<"\nWant to Continue[y/n]:\t";
								cin>>x;
						}
						while((x=='Y')||(x=='y'));

					}
					else
					{
						cout<<"\nFirst Create Account before Loging in and try again";
					}
					break;
				}
			}
		cout<<"\nWant to continue[y/n]:\t";
		cin>>x;

		}
	while((x=='y')||(x=='Y'));
	getch();

}