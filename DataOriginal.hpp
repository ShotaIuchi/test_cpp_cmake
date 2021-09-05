#pragma once

struct DataTypeA
{
    int x = 1;
    float y = 2;
};

struct DataTypeB
{
    struct AAA
    {
        int a = 3;
    };
    struct BBB
    {
        int a = 4;
        int b = 5;
    };
    AAA aaa;
    BBB bbb[4];
};

struct DataOriginal
{
    DataTypeA dataA;
    DataTypeB dataB;
};