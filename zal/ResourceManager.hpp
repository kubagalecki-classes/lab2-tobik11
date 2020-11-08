#pragma once

#include "Resource.hpp"
#include <iostream>

using namespace std;


class ResourceManager
{
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
    Resource* res = nullptr;
};
