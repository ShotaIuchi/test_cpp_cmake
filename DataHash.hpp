#pragma onec

#include <vector>
#include <functional>
#include "DataOriginal.hpp"

template <class T>
using DataTypeGetter = std::function<T *(DataOriginal *src)>;

class DataTypeHashBase
{
public:
    virtual std::string path() const = 0;
    virtual std::string name() const = 0;
    virtual void *get(DataOriginal *src) const = 0;
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
    void *get(DataOriginal *src) const override
    {
        return this->mGetter(src);
    }
    const std::type_info &type() const override
    {
        return typeid(T);
    }
};

struct DataTypeA_Hash
{
    std::vector<const DataTypeHashBase *> values;

    DataTypeHash<int> x;
    DataTypeHash<float> y;

    DataTypeA_Hash()
        : x("x", [=](DataOriginal *src)
            { return &src->dataA.x; }),
          y("y", [=](DataOriginal *src)
            { return &src->dataA.y; })
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
            : a("a", [=](DataOriginal *src)
                { return &src->dataB.aaa.a; })
        {
            this->values.push_back(&a);
        }
    };
    struct BBB_Hash
    {
        std::vector<const DataTypeHashBase *> values;
        DataTypeHash<int> a;
        DataTypeHash<int> b;
        BBB_Hash(int index)
            : a("a", [=](DataOriginal *src)
                { return &src->dataB.bbb[index].a; }),
              b("b", [=](DataOriginal *src)
                { return &src->dataB.bbb[index].b; })
        {
            this->values.push_back(&a);
            this->values.push_back(&b);
        }
    };

    AAA_Hash aaa;
    BBB_Hash bbb[4];
    DataTypeB_Hash()
        : aaa(),
          bbb{
              BBB_Hash(0),
              BBB_Hash(1),
              BBB_Hash(2),
              BBB_Hash(3)}
    {
    }
};

struct DataHash
{
    DataTypeA_Hash dataA;
    DataTypeB_Hash dataB;
    DataHash()
        : dataA(),
          dataB()
    {
    }
};