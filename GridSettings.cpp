#include "GridSettings.h"

GridSettings::GridSettings()
{
    SetDefaults();
}

void GridSettings::SetDefaults()
{
    m_grid_length_x = 1.0;
    m_grid_length_y = 1.0;
    m_grid_length_z = 1.0;
    m_grid_count_x = 5;
    m_grid_count_y = 5;
    m_grid_count_z = 0;
}

double GridSettings::GetGridLengthX() const
{
    return m_grid_length_x;
}

double GridSettings::GetGridLengthY() const
{
    return m_grid_length_y;
}

double GridSettings::GetGridLengthZ() const
{
    return m_grid_length_z;
}

int GridSettings::GetGridCountX() const
{
    return m_grid_count_x;
}

int GridSettings::GetGridCountY() const
{
    return m_grid_count_y;
}

int GridSettings::GetGridCountZ() const
{
    return m_grid_count_z;
}
