#pragma onec

#include <vector>
#include <functional>
#include "DataOriginal.hpp"

template <class T>
using DataTypeGetter = std::function<T *(void *src)>;

class DataTypeHashBase
{
public:
    virtual std::string path() const = 0;
    virtual std::string name() const = 0;
    virtual void *get(void *src) const = 0;
    virtual const std::type_info &type() const = 0;
};

template <class T>
class DataTypeHash : public DataTypeHashBase
{
private:
    std::string mName;
    DataTypeGetter<T> mGetter;

public:
    DataTypeHash(std::string name, DataTypeGetter<T> getter)
        : mName(name), mGetter(getter)
    {
    }
    std::string path() const override
    {
        return "";
    }
    std::string name() const override
    {
        return this->mName;
    }
    void *get(void *src) const override
    {
        return this->mGetter(src);
    }
    const std::type_info &type() const override
    {
        return typeid(T);
    }
};

struct DataHash
{
    struct DataTypeA_Hash
    {
        std::vector<const DataTypeHashBase *> values;

        DataTypeHash<int> x;
        DataTypeHash<float> y;

        DataTypeA_Hash()
            : x("x", [=](void *src)
                { return &static_cast<DataTypeA *>(src)->x; }),
              y("y", [=](void *src)
                { return &static_cast<DataTypeA *>(src)->y; })
        {
            this->values.push_back(&x);
            this->values.push_back(&y);
        }
    };

    struct DataTypeB_Hash
    {
        struct AAA_Hash
        {
            std::vector<const DataTypeHashBase *> values;
            DataTypeHash<int> a;
            AAA_Hash()
                : a("a", [=](void *src)
                    { return &static_cast<DataTypeB::AAA *>(src)->a; })
            {
                this->values.push_back(&a);
            }
        };
        struct BBB_Hash
        {
            std::vector<const DataTypeHashBase *> values;
            DataTypeHash<int> a;
            DataTypeHash<int> b;
            BBB_Hash()
                : a("a", [=](void *src)
                    { return &static_cast<DataTypeB::BBB *>(src)->a; }),
                  b("b", [=](void *src)
                    { return &static_cast<DataTypeB::BBB *>(src)->b; })
            {
                this->values.push_back(&a);
                this->values.push_back(&b);
            }
        };
    };
};