#pragma once

struct DataTypeA
{
    int x;
    float y;
};

struct DataTypeB
{
    struct AAA
    {
        int a;
    };
    struct BBB
    {
        int a;
        int b;
    };
    AAA aaa;
    BBB bbb[4];
};

struct DataOriginal
{
    DataTypeA dataA;
    DataTypeB dataB;
};