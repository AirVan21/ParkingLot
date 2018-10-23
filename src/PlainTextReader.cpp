#include "PlainTextReader.h"

PlainTextReader::PlainTextReader(const std::string& pathToFile)
    : m_pathToFile(pathToFile)
{}

std::vector<Segment> PlainTextReader::GetSchedule()
{
    return std::vector<Segment>();
}
