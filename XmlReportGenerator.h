#pragma once

#include "IReportGenerator.h"

class XmlReportGenerator : public IReportGenerator {
public:
	void generateReport(const std::vector<FileInfo>& filesInfo, std::ostream& outputStream) const override;
};