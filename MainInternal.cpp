#include <iostream>
#include "external/imgui/imgui.h"
#include "MainInternal.hpp"
#include "XXFramework.hpp"
#include "DataOriginal.hpp"
#include "DataHash.hpp"

template <class T>
void MIItem(T *src, const DataTypeHashBase *const item)
{
    bool isCheck = false;
    ImGui::Checkbox(item->name().c_str(), &isCheck);
    if (isCheck)
    {
        if (item->type() == typeid(int))
        {
            std::cout << item->name() << " >> " << *(int *)item->get(src) << std::endl;
        }
        else if (item->type() == typeid(float))
        {
            std::cout << item->name() << " >> " << *(float *)item->get(src) << std::endl;
        }
        else if (item->type() == typeid(short))
        {
            std::cout << item->name() << " >> " << *(short *)item->get(src) << std::endl;
        }
    }
}

void MIInit(DataTypeA *src)
{
    DataHash::DataTypeA_Hash data;
    ImGui::SetNextItemOpen(true);
    if (ImGui::TreeNode("DataTypeA"))
    {
        for (const auto &item : data.values)
        {
            MIItem(src, item);
        }
        ImGui::TreePop();
    }
}
void MIInit(DataTypeB::AAA *src)
{
    DataHash::DataTypeB_Hash::AAA_Hash data;
    ImGui::SetNextItemOpen(true);
    if (ImGui::TreeNode("AAA"))
    {
        for (const auto &item : data.values)
        {
            MIItem(src, item);
        }
        ImGui::TreePop();
    }
}
void MIInit(DataTypeB::BBB *src, int index)
{
    DataHash::DataTypeB_Hash::BBB_Hash data;
    ImGui::SetNextItemOpen(true);
    if (ImGui::TreeNode(("BBB[" + std::to_string(index) + "]").c_str()))
    {
        for (const auto &item : data.values)
        {
            MIItem(src, item);
        }
        ImGui::TreePop();
    }
}
void MIInit(DataTypeB *src)
{
    ImGui::SetNextItemOpen(true);
    if (ImGui::TreeNode("DataTypeB"))
    {
        MIInit(&src->aaa);
        MIInit(&src->bbb[0], 0);
        MIInit(&src->bbb[1], 1);
        MIInit(&src->bbb[2], 2);
        MIInit(&src->bbb[3], 3);
        ImGui::TreePop();
    }
}

MainInternal::MainInternal()
    : mFramework(std::shared_ptr<XXFramework>(new XXFramework()))
{
}

void MainInternal::init()
{
}

void MainInternal::loop()
{
    DataOriginal o;
    ImGui::Begin("aaaa");
    MIInit(&o.dataA);
    MIInit(&o.dataB);
    ImGui::End();
}