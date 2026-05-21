#include "subject.hpp"

subject::subject()
{

}

subject::~subject()
{
    obj.clear();
}

void subject::registerObserver(const shared_ptr<IObserver> obj)
{
    lock_guard<mutex> Lock(mtx);
    this->obj.push_back(obj);
}

void subject::notifyObservers(int number)
{
    lock_guard<mutex> Lock(mtx);
    for(const auto& element : obj)
    {
        if(element.expired())
        {
            auto ptr = element.lock();
            ptr->update(number);
        }
    }
}