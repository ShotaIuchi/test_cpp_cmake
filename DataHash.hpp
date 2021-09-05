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
    virtual size_t size() const = 0;
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
    size_t size() const override
    {
        return sizeof(T);
    }
};

struct HashBalse
{
    std::vector<const DataTypeHashBase *> values;
    size_t size = 0;

protected:
    template <class T>
    void addList(T value)
    {
        this->values.push_back(value);
        size += value->size();
    }
};

struct DataHash
{
    struct DataTypeA_Hash final : public HashBalse
    {
        DataTypeHash<int> x;
        DataTypeHash<float> y;

        DataTypeA_Hash()
            : x("x", [=](void *src)
                { return &static_cast<DataTypeA *>(src)->x; }),
              y("y", [=](void *src)
                { return &static_cast<DataTypeA *>(src)->y; })
        {
            addList(&x);
            addList(&y);
        }
    };

    struct DataTypeB_Hash
    {
        struct AAA_Hash
        {
            std::vector<const DataTypeHashBase *> values;
            size_t size = 0;

            DataTypeHash<int> a;
            AAA_Hash()
                : a("a", [=](void *src)
                    { return &static_cast<DataTypeB::AAA *>(src)->a; })
            {
                this->values.push_back(&a);
                size += a.size();
            }
        };
        struct BBB_Hash
        {
            std::vector<const DataTypeHashBase *> values;
            size_t size = 0;
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
                size += a.size();
                size += b.size();
            }
        };
        size_t size = 0;
        DataTypeB_Hash()
        {
            size += (AAA_Hash().size);
            size += (BBB_Hash().size * 4);
        }
    };

    size_t size = 0;
    DataHash()
    {
        size += (DataTypeA_Hash().size);
        size += (DataTypeB_Hash().size);

        assert(size == sizeof(DataOriginal));
    }
};