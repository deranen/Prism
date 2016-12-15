#include "PrismApp.h"

std::unique_ptr<PrismInstance> PrismInstance::s_instance;

PrismInstance& PrismInstance::instance()
{
    if(!s_instance)
    {
        s_instance = std::make_unique<PrismInstance>();
    }

    return *s_instance;
}



