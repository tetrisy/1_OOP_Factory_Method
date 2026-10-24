#pragma once

#include "FileInfo.h"
#include <ostream>
#include <vector>

class IReportGenerator {
public:
	virtual void generateReport(const std::vector<FileInfo>& filesInfo, std::ostream& outputStream) const = 0;

	virtual ~IReportGenerator() = default;
};