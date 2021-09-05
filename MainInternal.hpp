#pragma once
#include <memory>

class XXFramework;
class MainInternal
{
    std::shared_ptr<XXFramework> mFramework;

public:
    MainInternal();
    void init();
    void loop();
};