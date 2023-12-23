#pragma once

#include <string>
#include <vector>

template <typename T>
__interface IRepository
{
public:
    std::vector<T> getAll() const;
    /*virtual*/ void add(const T& user); // you can omit virtual ... = 0; because __interface automatically sets all methods as virtual and abstract
    void Remove(const T& user);
    void update(const T& user);
};
