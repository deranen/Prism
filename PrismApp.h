#pragma once

#include "Document.h"
#include <memory>

class PrismInstance
{
    static std::unique_ptr<PrismInstance> s_instance;

    Document m_doc;

public:
    static PrismInstance& instance();
};

PrismInstance& PrismApp()
{
    return PrismInstance::instance();
}
