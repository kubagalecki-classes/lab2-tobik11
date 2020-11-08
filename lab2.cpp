
#include "zal/include/Resource.hpp"
#include <iostream>

using namespace std;

class ResourceManager
{
public:
    ResourceManager() { res = new Resource; }

    ResourceManager(const ResourceManager& rs) // copying constructor
    {
        cout << "copying_constr" << endl;
        res = new Resource{*rs.res};
    }

    ResourceManager& operator=(const ResourceManager& rs)
    {
        if (&rs == this) // prevent self-copying
        {
            return *this;
        }
        cout << "copying_operator" << endl;
        // res = rs.res;

        res = new Resource{*rs.res};

        cout << "eloaaaaaaaaaaaaaaaaaaaaaaaa" << endl;
        cout << res << endl;
        cout << rs.res << endl;
        return *this;
    }

    ResourceManager(ResourceManager&& rs) // moving constructor
    {
        cout << "moving_constr" << endl;
        res    = move(rs.res); // wywola konstruktor przenoszacy
        rs.res = nullptr;
    }

    ResourceManager& operator=(ResourceManager&& rs)
    {
        if (&rs == this) // prevent self-copying
        {
            cout << "selfMoving" << endl;
            return *this;
        }
        else if (!(res == nullptr)) {
            cout << "deleting" << endl;
            delete res;
        }
        cout << "moving_operator" << endl;
        res    = move(rs.res); // wywola konstruktor przenoszacy
        rs.res = nullptr;
        return *this;
    }

    ~ResourceManager()
    {
        cout << "deconst" << endl;
        cout << res << endl;
        cout << this << endl;

        if (!(res == nullptr)) {
            cout << res->get() << endl;
            cout << "xd1" << endl;
            delete res;
        }
        else {
            cout << "xd2" << endl;
        }
    }

    double get() { return res->get(); }

private:
    int       me;
    Resource* res = nullptr;
};

int main()
{
    ResourceManager a{};
    cout << a.get() << endl;

    ResourceManager b{a};
    ResourceManager c;
    c = a;
    cout << "printing other values" << endl;
    // cout << a.get() << endl;
    cout << b.get() << endl;
    cout << c.get() << endl;
}
