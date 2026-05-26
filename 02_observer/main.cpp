#include "../common_header.hpp"
#include "observer.hpp"
#include "subject.hpp"

int main() 
{
    shared_ptr<ISubject> sub = make_shared<subject>();

    shared_ptr<ObserverThread> a = make_shared<ObserverThreadFirstClassImpl>(string("qwer"), 10);
    shared_ptr<ObserverThread> b = make_shared<ObserverThreadSecondClassImpl>(string("asdf"), 20);
    shared_ptr<ObserverThread> c = make_shared<ObserverThreadThirdClassImpl>(string("zxcv"), 30);
    a->startThread();
    b->startThread();
    c->startThread();

    sub->registerObserver(a);
    sub->registerObserver(b);
    sub->registerObserver(c);

    int x;
    for(cin >> x; x != 0; cin >> x)
    {
        sub->notifyObservers(x);
    }
    return 0;
}