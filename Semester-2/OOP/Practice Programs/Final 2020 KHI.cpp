#include <iostream>
using namespace std;


class Membership
{
protected:
	string name;
	float trans_limit,
		loan_l;

public:

	float getTransLimit()
	{
		return trans_limit;
	}
	float getLoanLimit()
	{
		return loan_l;
	}
	string getName()
	{
		return name;
	}


};

class Diamond :public Membership
{
private:


public:
	Diamond()
	{
		trans_limit = 250000;
		loan_l = 10000000;
		name = "diamond";
	}
};

class Gold :public Membership
{
private:


public:
	Gold()
	{
		trans_limit = 150000;
		loan_l = 5000000;
		name = "gold";
	}

};

class Silver :public Membership
{
private:


public:
	Silver()
	{
		trans_limit = 100000;
		loan_l = 1000000;
		name = "silver";
	}

};

class Basic :public Membership
{
private:


public:
	Basic()
	{
		trans_limit = 50000;
		loan_l = 500000;
		name = "basic";
	}

};


class Bank
{
protected:
	float m_income,
		t_limit,
		balance,
		mob_balance,
		loan,
		loan_lim;
	int bonus_pt,
		member_no;
	Membership* membership = NULL;

public:
	Bank(float in = 0, float bal = 0, float mob_bal = 0)
	{
		m_income = in;
		t_limit = 0; // membership->getTransLimit();
		balance = bal;
		mob_balance = mob_bal;
		loan_lim = 0;
		member_no = check_membership();
	}

	void setTransLimit(int lim)
	{
		t_limit = lim;
	}

	int check_membership()
	{
		if (m_income >= 200000 && balance >= 50000)
			member_no = 1;
		else if (m_income >= 100000 && balance >= 10000)
			member_no = 2;
		else if (m_income >= 20000 && balance >= 10000)
			member_no = 3;
		else
			member_no = 4;

		return member_no;
	}

	void update_membership()
	{
		check_membership();

		if(membership!=NULL)
			delete membership;

		if (member_no == 1)
		{
			membership = new Diamond();
		}
		else if (member_no == 2)
		{
			membership = new Gold();
		}
		else if (member_no == 3)
		{
			membership = new Silver();
		}
		else
		{
			membership = new Basic();
		}
	}

	void withdraw_cash()
	{
		int withdraw;
		t_limit = membership->getTransLimit();

		cout << "Enter amount of cash to withdraw: ";
		while (1)
		{
			cin >> withdraw;
			if (withdraw > balance)
			{
				cout << "Enter cash under balance" << balance << ": ";
			}
			else if (withdraw <= t_limit)
				break;
			else
				cout << "Enter cash under " << t_limit << ": ";
		}
		balance -= withdraw;
		cout << "Cash withdrawn\n";

		check_posTransaction(withdraw);
	}

	void check_posTransaction(int trans)
	{
		if (member_no >= 1 && member_no <= 3)
		{
			if (trans >= 100000)
			{
				mob_balance += trans * 0.01;
				bonus_pt += 1000;
			}
			else if (trans >= 10000 && trans <= 100000)
			{
				bonus_pt += 100;
			}
		}
	}

	void take_loan()
	{
		int l = 0;
		loan_lim = membership->getLoanLimit();

		cout << "Enter loan ammount: ";
		while (1)
		{
			cin >> l;
			if (l <= loan_lim)
				break;
			else
				cout << "Enter below loan limit " << loan_lim << ": ";
		}
		loan = l;
		cout << "Loan taken\n";
	}

	void Display()
	{
		cout << "Membership: " << membership->getName() << endl
			<< "Balance: " << balance << endl
			<< "Mobile Balance: " << mob_balance << endl
			<< "Loan: " << loan << endl
			<< "Income: " << m_income << endl;
	}
};


//int main()
//{
//	Bank abc(200000, 100000, 1000);
//
//	abc.update_membership();
//
//	abc.withdraw_cash();
//	abc.take_loan();
//
//	abc.Display();
//
//	return 0;
//}