#include <iostream>
#include "MainInternal.hpp"
#include "XXFramework.hpp"

MainInternal::MainInternal()
    : mFramework(std::shared_ptr<XXFramework>(new XXFramework()))
// : mFramework(std::unique_ptr<XXFramework>(new XXFramework()))
// : mFramework(new XXFramework())
{
}

void MainInternal::init()
{
    std::cout << "MainInternal::init" << std::endl;
}

void MainInternal::loop()
{
    mFramework->update();
    std::cout << "MainInternal::update" << std::endl;
}