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
  ~ResourceManager(){
  }

    ResourceManager(const ResourceManager& rs) // copying constructor
    {
        cout << "copying_constr" << endl;
        res = rs.res;
    }

    ResourceManager& operator=(const ResourceManager& rs)
    {
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
        cout << "moving_operator" << endl;
        res = move(rs.res); // wywola konstruktor przenoszacy
        return *this;
    }

    ~ResourceManager()
    {
        cout << "deconst" << endl;
        delete res;
    }

  double get()
  {
    return res->get();
  }

private:
    Resource* res = nullptr;
};
