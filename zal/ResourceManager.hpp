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
    delete res;
  }


  double get()
  {
    return res->get();
  }

private:
    Resource* res = nullptr;
};
