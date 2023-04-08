#include <iostream>
#include <sstream>
#include <memory>
#include <map>
using namespace std;

/* SINGLETON */
class Counter {
private:
    int _count;
    //special pointer to check once called
    inline static shared_ptr<Counter> _inst = NULL;
    //hide constructor
    Counter(){_count=0;}
public:
    //once called, it changes value only one time
    static shared_ptr<Counter> inst(){
        if (_inst==NULL){
            Counter*temp=new Counter();
            _inst = make_shared<Counter>(*temp);
        } 
        return _inst;
    } int count() { return _count; }
    void increase() {_count++;}
};

/* FACTORY */
class car{
    //Create a clone product giving to customers
    public: virtual shared_ptr<car> clone() = 0;
    //Virtual constructor and destructor
    public: car();
    public: virtual ~car();
};
class Ferrari: virtual public car{
    public: shared_ptr<car> clone(){return make_shared<Ferrari>();}
};
class Ford: virtual public car{
    public: shared_ptr<car> clone(){return make_shared<Ford>();}
};
class Factory{
    private: map<string, shared_ptr<car>> _prototypes;
    public:
        Factory(){
        //Create model to be on the shell for displaying
        _prototypes.insert({ "A", make_shared<Ferrari>()});
        _prototypes.insert({ "B", make_shared<Ford>()});
        }
        shared_ptr<car> create(string choice){
            //Treating the choice of user an return responsive products
            shared_ptr<car> result = NULL;
            auto item = _prototypes[choice];
            result = item->clone();
            return result;
        }
        ~Factory();
};


int main(){
    //SINGLETON
    //Regardless of number of calling times, this constructor just construct only one
    auto c1 = Counter::inst();
    for (int i = 0; i < 10; i++) {
        c1->increase();
    } cout << c1->count() << endl;
    return 0;
}