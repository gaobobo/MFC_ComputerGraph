#include "pch.h"
#include "3DPolyDraw.h"

#include <cmath>

PolyDraw3D::PolyDraw3D(float a)
{
    POINT3 points[] = {
        {-a, -a, -a},
        {a, -a, -a},
        {a, a, -a},
        {-a, a, -a},
        {-a, -a, a},
        {a, -a, a},
        {a, a, a},
        {-a, a, a},
    };

    EDGE4 faces[] = {
        {4, 5, 6, 7}, // front
        {0, 3, 2, 1}, // back
        {0, 4, 7, 3}, // left
        {1, 2, 6, 5}, // right
        {2, 3, 7, 6}, // top
        {0, 1, 5, 4}, // bottom
    };


    memcpy(this->points, points, sizeof(points));
    memcpy(this->faces, faces, sizeof(faces));
}

void PolyDraw3D::OnDraw(CDC* pDC, int scale)
{
    this->rotation_z();
    this->translation(200.0f, 200.0f, 0.0f);
    this->project_xOy(POINT3{0, 0, 400}, 500.0f);

    CPen* pPen = new CPen(PS_SOLID, 1, RGB(0, 0, 0));
    pDC->SelectObject(pPen);
    
    for (int i = 0; i < 6; i++)
    {
        pDC->MoveTo(this->points[this->faces[i].e[0]].x, this->points[this->faces[i].e[0]].y);
        pDC->LineTo(this->points[this->faces[i].e[1]].x, this->points[this->faces[i].e[1]].y);
        pDC->LineTo(this->points[this->faces[i].e[2]].x, this->points[this->faces[i].e[2]].y);
        pDC->LineTo(this->points[this->faces[i].e[3]].x, this->points[this->faces[i].e[3]].y);
        pDC->LineTo(this->points[this->faces[i].e[0]].x, this->points[this->faces[i].e[0]].y);
    }

    pPen->DeleteObject();
}

void PolyDraw3D::matrix_operation(float transform[4][4])
{
    POINT3 pt[8];

    for (int i = 0; i < 8; i++)
    {
        pt[i].x = this->points[i].x * transform[0][0]
                + this->points[i].y * transform[1][0]
                + this->points[i].z * transform[2][0]
                + this->points[i].c * transform[3][0];

        pt[i].y = this->points[i].x * transform[0][1]
                + this->points[i].y * transform[1][1]
                + this->points[i].z * transform[2][1]
                + this->points[i].c * transform[3][1];

        pt[i].z = this->points[i].x * transform[0][2]
                + this->points[i].y * transform[1][2]
                + this->points[i].z * transform[2][2]
                + this->points[i].c * transform[3][2];

        pt[i].c = this->points[i].x * transform[0][3]
                + this->points[i].y * transform[1][3]
                + this->points[i].z * transform[2][3]
                + this->points[i].c * transform[3][3];

        pt[i].x /= pt[i].c;
        pt[i].y /= pt[i].c;
        pt[i].z /= pt[i].c;
        pt[i].c = 1.0f;
    }

    memcpy(this->points, pt, sizeof(pt));
}

void PolyDraw3D::rotation_z()
{
    const float angle_sin = 0.25881904510252;
    const float angle_cos = 0.96592582628907;
    
    float matrix[4][4] = {
        {angle_cos, angle_sin, 0, 0},
        {-angle_sin, angle_cos, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    this->matrix_operation(matrix);
}

void PolyDraw3D::translation(float x, float y, float z)
{
    float matrix[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {x, y, z, 1}
    };

    this->matrix_operation(matrix);
}

void PolyDraw3D::project_xOy(POINT3 viewer, float screen_distance)
{
    auto distance = [](POINT3 point1, POINT3 point2 = POINT3{0, 0, 0}) -> float
    {
        float dx = point2.x - point1.x;
        float dy = point2.y - point1.y;
        float dz = point2.z - point1.z;
        return sqrt(dx * dx + dy * dy + dz * dz);
    };
    
    float origin_distance = distance(viewer);

    float phi_sin = distance(POINT3{0, viewer.y, 0}, viewer) / origin_distance;
    float phi_cos = viewer.y / origin_distance;

    float theta_sin = viewer.x / distance(POINT3{viewer.x, 0, viewer.z});
    float theta_cos = viewer.z / distance(POINT3{viewer.x, 0, viewer.z});

    float matrix[4][4] = {
        {theta_cos, -phi_cos * theta_sin, 0, -phi_sin * theta_sin / screen_distance},
        {0, phi_sin, 0, -phi_cos / screen_distance},
        {-theta_sin, -phi_cos * theta_cos, 0, -phi_sin * theta_cos / screen_distance},
        {0, 0, 0, origin_distance / screen_distance}
    };

    this->matrix_operation(matrix);
}
