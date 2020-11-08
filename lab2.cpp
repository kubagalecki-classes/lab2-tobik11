
#include "zal/include/Resource.hpp"
#include <iostream>

using namespace std;

class ResourceManager
{
public:
    ResourceManager() { res = new Resource; }

    ResourceManager(const ResourceManager& rs) // copying constructor
    {
        // cout << "copy_constr" << endl;
        res = rs.res; // wywola konstruktor kopiujacy
    }

    ResourceManager& operator=(const ResourceManager& rs)
    {
        me = rs.me;
        return *this;
    }

    ResourceManager(ResourceManager&& rs) // moving constructor
    {
        me = rs.me;
    }

    ResourceManager& operator=(ResourceManager&& rs)
    {
        me = rs.me;
        return *this;
    }

    ~ResourceManager() { delete res; }

    double get() { return res->get(); }

private:
    int       me;
    Resource* res = nullptr;
};

int main()
{
    ResourceManager a{};

    ResourceManager b{a};

    cout << a.get() << endl;
    cout << b.get() << endl;
}
