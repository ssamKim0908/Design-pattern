#include "interface.hpp"
#include <mutex>


class subject : public ISubject, enable_shared_from_this<subject>
{
private:
    mutex mtx;
    vector<weak_ptr<IObserver>> obj;
    
public:
    subject();

    void registerObserver   (const shared_ptr<IObserver> obj)   override;
    void notifyObservers    (int number) override;

    ~subject();
};