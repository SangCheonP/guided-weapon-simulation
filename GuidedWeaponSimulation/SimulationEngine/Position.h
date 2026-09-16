#pragma once

// 가상 공간의 위치. 모든 좌표의 단위는 미터(m).
// x, y: 수평 좌표
// z: 고정 기준면으로부터의 높이(위쪽이 양수)
struct Position
{
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
};