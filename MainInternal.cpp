#include <iostream>
#include "external/imgui/imgui.h"
#include "MainInternal.hpp"
#include "XXFramework.hpp"
#include "DataOriginal.hpp"
#include "DataHash.hpp"

void MIInit(DataTypeA_Hash *data, DataOriginal *src)
{
    // std::cout << "DataTypeA" << std::endl;
    // for (const auto &item : data->values)
    // {
    //     std::cout << item->name() << std::endl;
    // }
    //
    // ImGui::Text("DataTypeA");
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
        // ImGui::Unindent();
    }
}
void MIInit(DataTypeB_Hash::AAA_Hash *data, DataOriginal *src)
{
    // std::cout << "AAA_Hash" << std::endl;
    // for (const auto &item : data->values)
    // {
    //     std::cout << item->name() << std::endl;
    // }
    //
    // ImGui::Text("AAA_Hash");
    ImGui::SetNextItemOpen(true);
    if (ImGui::TreeNode("AAA"))
    {
        // ImGui::Indent();
        for (const auto &item : data->values)
        {
            bool isCheck = false;
            ImGui::Checkbox(item->name().c_str(), &isCheck);
            if (isCheck)
            {
                std::cout << item->name() << " >> " << *(double *)item->get(src) << std::endl;
            }
        }
        // ImGui::Unindent();
        ImGui::TreePop();
    }
}
void MIInit(DataTypeB_Hash::BBB_Hash *data, int index, DataOriginal *src)
{
    // std::cout << "BBB_Hash[" + std::to_string(index) + "]" << std::endl;
    // for (const auto &item : data->values)
    // {
    //     std::cout << item->name() << std::endl;
    // }
    //
    // ImGui::Text(("BBB_Hash[" + std::to_string(index) + "]").c_str());
    ImGui::SetNextItemOpen(true);
    if (ImGui::TreeNode(("BBB[" + std::to_string(index) + "]").c_str()))
    {
        // ImGui::Indent();
        for (const auto &item : data->values)
        {
            bool isCheck = false;
            ImGui::Checkbox(item->name().c_str(), &isCheck);
            if (isCheck)
            {
                std::cout << item->name() << " >> " << *(double *)item->get(src) << std::endl;
            }
        }
        // ImGui::Unindent();
        ImGui::TreePop();
    }
}
void MIInit(DataTypeB_Hash *data, DataOriginal *src)
{
    // std::cout << "DataTypeB" << std::endl;
    //
    // ImGui::Text("DataTypeB");
    ImGui::SetNextItemOpen(true);
    if (ImGui::TreeNode("DataTypeB"))
    {
        // ImGui::Indent();
        MIInit(&data->aaa, src);
        MIInit(&data->bbb[0], 0, src);
        MIInit(&data->bbb[1], 1, src);
        MIInit(&data->bbb[2], 2, src);
        MIInit(&data->bbb[3], 3, src);
        // ImGui::Unindent();
        // ImGui::Unindent();
        ImGui::TreePop();
    }
}

MainInternal::MainInternal()
    : mFramework(std::shared_ptr<XXFramework>(new XXFramework()))
// : mFramework(std::unique_ptr<XXFramework>(new XXFramework()))
// : mFramework(new XXFramework())
{
    DataOriginal o;
    DataTypeA_Hash ta;
    ta.x.get(&(o));
    ta.y.get(&(o));

    std::cout << ta.x.type().name() << std::endl;
    std::cout << ta.y.type().name() << std::endl;

    // DataTypeB_Hash tb;
    // std::cout << tb.aaa.type().name() << std::endl;
    // std::cout << *((int *)tb.aaa.get(&o.dataB)) << std::endl;

    // std::cout << static_cast_typeinfo(tb.aaa.get(&o.dataB), tb.aaa.type) << std::endl;
    // int = static_cast_typeinfo<int>(tb.aaa.get(&o.dataB), tb.aaa.type());

    // DataHash hash;
    //std::cout << hash.dataA.
    // MIInit(&hash.dataA);
    // MIInit(&hash.dataB);
}

void MainInternal::init()
{
    // std::cout << "MainInternal::init" << std::endl;
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
    // bool isCheck = false;
    // ImGui::SetNextItemOpen(true);
    // if (ImGui::TreeNode("treeA"))
    // {
    //     isCheck = false;
    //     ImGui::Checkbox("i", &isCheck);
    //     if (isCheck)
    //     {
    //         std::cout << "i1" << std::endl;
    //     }
    //     isCheck = false;
    //     ImGui::Checkbox("j", &isCheck);
    //     if (isCheck)
    //     {
    //         std::cout << "j1" << std::endl;
    //     }

    //     if (ImGui::TreeNode("treeA-2"))
    //     {
    //         isCheck = false;
    //         ImGui::Checkbox("i", &isCheck);
    //         if (isCheck)
    //         {
    //             std::cout << "i1" << std::endl;
    //         }
    //         isCheck = false;
    //         ImGui::Checkbox("j", &isCheck);
    //         if (isCheck)
    //         {
    //             std::cout << "j1" << std::endl;
    //         }
    //         ImGui::TreePop();
    //     }

    //     ImGui::TreePop();
    // }
    // ImGui::SetNextItemOpen(true);
    // if (ImGui::TreeNode("treeB"))
    // {
    //     isCheck = false;
    //     ImGui::Checkbox("i", &isCheck);
    //     if (isCheck)
    //     {
    //         std::cout << "i2" << std::endl;
    //     }
    //     isCheck = false;
    //     ImGui::Checkbox("j", &isCheck);
    //     if (isCheck)
    //     {
    //         std::cout << "j2" << std::endl;
    //     }
    //     ImGui::TreePop();
    // }

    ImGui::End();

    // mFramework->update();
    // std::cout << "MainInternal::update" << std::endl;
}