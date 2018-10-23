#pragma once
#include <string>

#include "ISegmentReader.h"

class PlainTextReader : public ISegmentReader
{
public:
    PlainTextReader(const std::string& pathToFile);
    PlainTextReader(const PlainTextReader& other) = delete;
    PlainTextReader& operator=(const PlainTextReader& other) = delete;
    virtual ~PlainTextReader() = default;

public:
    virtual std::vector<Segment> GetSchedule() override;

private:
    std::string m_pathToFile;
};
