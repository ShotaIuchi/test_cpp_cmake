#include <iostream>
#include "external/imgui/imgui.h"
#include "MainInternal.hpp"
#include "XXFramework.hpp"
#include "DataOriginal.hpp"
#include "DataHash.hpp"

void MIInit(DataTypeA_Hash *data, DataOriginal *src)
{
    ImGui::SetNextItemOpen(true);
    if (ImGui::TreeNode("DataTypeA"))
    {
        // ImGui::Indent();
        for (const auto &item : data->values)
        {
            bool isCheck = false;
            ImGui::Checkbox(item->name().c_str(), &isCheck);
            if (isCheck)
            {
                std::cout << item->name() << *(double *)item->get(src) << std::endl;
            }
        }
        ImGui::TreePop();
    }
}
void MIInit(DataTypeB_Hash::AAA_Hash *data, DataOriginal *src)
{
    ImGui::SetNextItemOpen(true);
    if (ImGui::TreeNode("AAA"))
    {
        for (const auto &item : data->values)
        {
            bool isCheck = false;
            ImGui::Checkbox(item->name().c_str(), &isCheck);
            if (isCheck)
            {
                std::cout << item->name() << " >> " << *(double *)item->get(src) << std::endl;
            }
        }
        ImGui::TreePop();
    }
}
void MIInit(DataTypeB_Hash::BBB_Hash *data, int index, DataOriginal *src)
{
    ImGui::SetNextItemOpen(true);
    if (ImGui::TreeNode(("BBB[" + std::to_string(index) + "]").c_str()))
    {
        for (const auto &item : data->values)
        {
            bool isCheck = false;
            ImGui::Checkbox(item->name().c_str(), &isCheck);
            if (isCheck)
            {
                std::cout << item->name() << " >> " << *(double *)item->get(src) << std::endl;
            }
        }
        ImGui::TreePop();
    }
}
void MIInit(DataTypeB_Hash *data, DataOriginal *src)
{
    ImGui::SetNextItemOpen(true);
    if (ImGui::TreeNode("DataTypeB"))
    {
        MIInit(&data->aaa, src);
        MIInit(&data->bbb[0], 0, src);
        MIInit(&data->bbb[1], 1, src);
        MIInit(&data->bbb[2], 2, src);
        MIInit(&data->bbb[3], 3, src);
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
    DataHash hash;
    DataOriginal o;

    ImGui::Begin("aaaa");
    MIInit(&hash.dataA, &o);
    MIInit(&hash.dataB, &o);

    ImGui::Separator();
    MIInit(&hash.dataB.bbb[0], 0, &o);
    ImGui::End();
}