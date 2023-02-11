#include <iostream>

using namespace std;

/*
#include "Interpreter.h"
void InterpreterExample()
{
    Context* context = new Context();
    context->SetVariable("a", 50);
    context->SetVariable("b", 20);
    context->SetVariable("c", 30);

    IExpression* expression = new SubExpression(
        new AddExpression(new NumberExpression("a"), new NumberExpression("b")),
        new NumberExpression("c")
    );

    int result = expression->Iterpret(context);

    cout << result;
}
*/

/*
#include "Observer.h"
void ObserverExample()
{
    Market* market = new Market();
    Bank* bank = new Bank("SberBank", market);
    Broker* broker = new Broker("Jhon Smith", market);

    market->Bidding();
    cout << "\n";

    market->Bidding();
    cout << "\n";

    broker->StopMarket();

    market->Bidding();
    cout << "\n";
}
*/

/*
#include "Memento.h"
void MementoExample()
{
    Player* player = new Player();
    GameHistory* gameHistory = new GameHistory();

    player->Play();

    gameHistory->Save(player->Save());

    player->Play();

    gameHistory->Save(player->Save());

    player->Play();

    player->Load(gameHistory->Load());

    player->Play();
}
*/

/*
#include "TemplateMethod.h"
void TemplateMethodExample()
{
    Education* education = new School();
    education->Learn();
    cout << "\n";

    education = new Universitet();
    education->Learn();
}
*/

#include "Visitor.h"

int main()
{
    Person* bob = new Person();
    bob->name = "Bob";
    bob->accNumber = "12345ASD";
    bob->amount = 50000;

    IAccount* account = bob;
    account->Accept(new XmlVisitor());

    account->Accept(new JsonVisitor());
}

