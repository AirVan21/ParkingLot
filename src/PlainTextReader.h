#pragma once

#include <string>
#include <iostream>
#include <fstream>

#include "ISegmentReader.h"

/**
 * PlainTextReader - class which processes scedule from plain text file
 */
class PlainTextReader : public ISegmentReader
{
public:
    PlainTextReader(const std::string& pathToFile);
    virtual ~PlainTextReader();

    PlainTextReader(const PlainTextReader& other) = delete;
    PlainTextReader& operator=(const PlainTextReader& other) = delete;

public:
    // Implements ISegmentReader
    virtual const std::vector<Segment>& GetSchedule() override;

private:
    void ParseSchedule();

private:
    std::ifstream        m_textFile;
    std::vector<Segment> m_schedule;
};
