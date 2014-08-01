/* 
 * File: Singleton.h
 *
 * Copyright (c) 2014 Marco Ambu
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
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

