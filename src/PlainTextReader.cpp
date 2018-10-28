#include <iostream>

#include "PlainTextReader.h"

PlainTextReader::PlainTextReader(const std::string& pathToFile)
    : m_textFile(pathToFile, std::ifstream::in)
{
    ParseSchedule();
}

PlainTextReader::~PlainTextReader()
{
    m_textFile.close();
}

const std::vector<Segment>& PlainTextReader::GetSchedule()
{
    return m_schedule;
}

void PlainTextReader::ParseSchedule()
{
    // Default parsing pattern is h:m h:m
    size_t hourStart = 0;
    size_t minuteStart = 0;
    size_t hourEnd = 0;
    size_t minuteEnd = 0;
    char delimeter = ':';
    // Parses all time segments
    while (m_textFile >> hourStart >> delimeter >> minuteStart >> hourEnd >> delimeter >> minuteEnd)
    {
        std::cout << hourStart << minuteStart << "  " << hourEnd << minuteEnd << std::endl;
        size_t saveStart = hourStart * 60 + minuteStart;
        size_t saveEnd = hourEnd * 60 + minuteEnd;
        m_schedule.push_back(Segment(saveStart, saveEnd));
    }
}
