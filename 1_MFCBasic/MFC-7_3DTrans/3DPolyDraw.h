#pragma once

#include "3DStuctions.h"

class PolyDraw3D
{
    public:
    PolyDraw3D(float a = 100.0f);
    void OnDraw(CDC* pDC, int scale = 1);

    private:
    POINT3 points[8];
    EDGE4 faces[6];

    void matrix_operation(float transform[4][4]);
    void rotation_z();
    void translation(float x, float y, float z);
    void project_xOy(POINT3 viewer, float screen_distance);
};