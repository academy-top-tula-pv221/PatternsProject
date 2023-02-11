#include <iostream>
#include <map>

using namespace std;

//IExpression ::= NumberExpression | Constant | AddExpr | SubstractExpr
//
//AddExpr ::= IExpression + IExpression
//SubstractExpr :: = IExpression - IExpression
//
//NumberExpression ::= [A-Z,a-z]+
//Constant ::= [0-9]+

class Context
{
    map<string, int> variables;
public:
    int GetVariable(string key)
    {
        return variables[key];
    }

    void SetVariable(string key, int value)
    {
        if (variables.contains(key))
            variables[key] = value;
        else
            variables.insert({ key, value });
    }
};

class IExpression
{
public:
    virtual int Iterpret(Context* context) = 0;
};

class NumberExpression : public IExpression
{
    string name;
public:
    NumberExpression(string name) : name{ name } {}
    int Iterpret(Context* context) override
    {
        return context->GetVariable(name);
    }
};

class AddExpression : public IExpression
{
    IExpression* expressionLeft;
    IExpression* expressionRight;
public:
    AddExpression(IExpression* expressionLeft, IExpression* expressionRight)
        : expressionLeft{ expressionLeft }, expressionRight{ expressionRight } {}
    int Iterpret(Context* context) override
    {
        return expressionLeft->Iterpret(context) + expressionRight->Iterpret(context);
    }
};

class SubExpression : public IExpression
{
    IExpression* expressionLeft;
    IExpression* expressionRight;
public:
    SubExpression(IExpression* expressionLeft, IExpression* expressionRight)
        : expressionLeft{ expressionLeft }, expressionRight{ expressionRight } {}
    int Iterpret(Context* context) override
    {
        return expressionLeft->Iterpret(context) - expressionRight->Iterpret(context);
    }
};