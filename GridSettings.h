#pragma once

class GridSettings
{
    double m_grid_length_x;
    double m_grid_length_y;
    double m_grid_length_z;

    int m_grid_count_x;
    int m_grid_count_y;
    int m_grid_count_z;

public:
    GridSettings();

    void SetDefaults();

    double GetGridLengthX() const;
    double GetGridLengthY() const;
    double GetGridLengthZ() const;

    int GetGridCountX() const;
    int GetGridCountY() const;
    int GetGridCountZ() const;
};
