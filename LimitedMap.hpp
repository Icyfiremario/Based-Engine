#ifndef LimitedMap_hpp
#define LimitedMap_hpp

#include <map>
#include <string>
#include "plog/Log.h"

template<typename Key, typename Value>

class LimitedMap
{
    public:

        explicit LimitedMap(size_t maxSize) : maxSize(maxSize) {}

        void insert(const Key& key, const Value& value)
        {
            if(data.size() >= maxSize)
            {
                PLOGE << "Map size limit reached. Could not insert element: " << key;
                return;
            }

            data[key] = value
        }

        Value& operator[](const Key& key)
        {
            return data[key];
        }

        void erase(const Key& key)
        {
            data.erase(key);
        }

        size_t size() const
        {
            return data.size();
        }

    private:

        std::map<Key, Value> data;
        size_t maxSize;
};

#endif /* LimitedMap_hpp */