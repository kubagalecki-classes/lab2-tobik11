#pragma once

#include "Resource.hpp"
#include <iostream>

using namespace std;


class ResourceManager
{
public:

  ResourceManager() {
    res = new Resource;
  }

    ResourceManager(const ResourceManager& rs) // copying constructor
    {
        cout << "copying_constr" << endl;
        res = new Resource{*rs.res};
        cout << res << endl;
    }

    ResourceManager& operator=(const ResourceManager& rs)
    {
        if (!(res == nullptr)) {
            cout << "selfDeleting" << endl;
            delete res;
        }
        cout << "copying_operator" << endl;
        res = new Resource{*rs.res};
        cout << res << endl;
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
            cout << "selfMoving!!!!!!!!!!!!!!!!!!!!!!!" << endl;
            return *this;
        }
        else if (!(res == nullptr)) {
            cout << "selfDeleting" << endl;
            delete res;
        }
        cout << "moving_operator" << endl;
        res = move(rs.res); // wywola konstruktor przenoszacy

        rs.res = nullptr;
        return *this;
    }

    ~ResourceManager()
    {
        cout << "deconst" << endl;
        cout << res << endl;
        delete res;
    }

  double get()
  {
    return res->get();
  }

private:
    Resource* res = nullptr;
};
