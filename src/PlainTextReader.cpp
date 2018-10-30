#include <iostream>

#include "PlainTextReader.h"

PlainTextReader::PlainTextReader(const std::string& pathToFile)
    : m_textFile(pathToFile, std::ifstream::in)
{}

PlainTextReader::~PlainTextReader()
{
    m_textFile.close();
}

bool PlainTextReader::GetSegment(Segment& segment)
{
    // Default parsing pattern is h:m h:m
    size_t hourStart = 0;
    size_t minuteStart = 0;
    size_t hourEnd = 0;
    size_t minuteEnd = 0;
    char delimeter = ':';
    if (m_textFile >> hourStart >> delimeter >> minuteStart >> hourEnd >> delimeter >> minuteEnd)
    {
        size_t saveStart = hourStart * 60 + minuteStart;
        size_t saveEnd = hourEnd * 60 + minuteEnd;
        segment = Segment(saveStart, saveEnd);
        return true;
    }
    else
    {
        return false;
    }
}

bool PlainTextReader::IsOpen() const
{
    return m_textFile.is_open();
}
