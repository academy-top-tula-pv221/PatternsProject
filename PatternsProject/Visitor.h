#pragma once
#include <iostream>
#include <string>

using namespace std;

class Person;
class Company;

class IVisitor
{
public:
	virtual void VisitPerson(Person* account) = 0;
	virtual void VisitCompany(Company* account) = 0;
};




class IAccount
{
public:
	virtual void Accept(IVisitor* visitor) = 0;
};

class Person : public IAccount
{
public:
	string name;
	string accNumber;
	int amount;

	// 
	void Accept(IVisitor* visiter)
	{
		visiter->VisitPerson(this);
	}
};

class Company : public IAccount
{
public:
	string title;
	string accNumber;
	string license;
	int amount;

	// 
	void Accept(IVisitor* visitor)
	{
		visitor->VisitCompany(this);
	}
};

class XmlVisitor : public IVisitor
{
	void VisitPerson(Person* account) override
	{
		string result = "<person>";
		result += "<name>" + account->name + "</name>";
		result += "<number>" + account->accNumber + "</number>";
		result += "<amount>" + to_string(account->amount) + "</amount>";
		result += "</person>";

		cout << result << "\n";
	}

	void VisitCompany(Company* account) override
	{
		string result = "<company>";
		result += "<title>" + account->title + "</title>";
		result += "<number>" + account->accNumber + "</number>";
		result += "<license>" + account->license + "</license>";
		result += "<amount>" + to_string(account->amount) + "</amount>";
		result += "</company>";

		cout << result << "\n";
	}
};

class JsonVisitor : public IVisitor
{
	void VisitPerson(Person* account) override
	{
		string result = "{";
		result += "name:" + account->name + ",";
		result += "number:" + account->accNumber + ",";
		result += "amount:" + to_string(account->amount) + ",";
		result += "}";

		cout << result << "\n";
	}

	void VisitCompany(Company* account) override
	{
		string result = "<company>";
		result += "<title>" + account->title + "</title>";
		result += "<number>" + account->accNumber + "</number>";
		result += "<license>" + account->license + "</license>";
		result += "<amount>" + to_string(account->amount) + "</amount>";
		result += "</company>";

		cout << result << "\n";
	}
};