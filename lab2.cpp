
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
        res = rs.res;
    }

    ResourceManager& operator=(const ResourceManager& rs)
    {
        if(&rs == this) // prevent self-copying
        {
          return *this;
        }
        cout << "copying_operator" << endl;
        res = rs.res;
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
      if(&rs == this) // prevent self-copying
      {
        return *this;
      }
      cout << "moving_operator" << endl;
      res = move(rs.res); // wywola konstruktor przenoszacy
      return *this;
    }

    ~ResourceManager()
    {
        cout << "deconst" << endl;
        delete res;
    }

    double get() { return res->get(); }

private:
    int       me;
    Resource* res = nullptr;
};

int main()
{
    ResourceManager a{};

    // ResourceManager b{move(a)};

    ResourceManager c = a;
    cout << "printing values" << endl;
    // cout << a.get() << endl;
    // cout << b.get() << endl;
    cout << c.get() << endl;
}
