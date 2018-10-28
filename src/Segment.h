#pragma once

struct Segment
{
    Segment(size_t minuteStart, size_t minuteEnd)
        : m_minuteStart(minuteStart)
        , m_minuteEnd(minuteEnd)
    {}

    size_t m_minuteStart;
    size_t m_minuteEnd;
};
