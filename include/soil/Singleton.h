/* 
 * File:   Singleton.h
 * Author: marco
 */

#ifndef SOIL_SINGLETON_H
#define SOIL_SINGLETON_H

namespace soil
{

template <class T>
class Singleton
{
protected:
    Singleton() {}
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);

public:
    static T& get()
    {
        static T instance;
        return instance;
    }
};

} // namespace soil

#endif // SOIL_SINGLETON_H

