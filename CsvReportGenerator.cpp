#include "CsvReportGenerator.h"

#include <stdexcept>

void CsvReportGenerator::generateReport(const std::vector<FileInfo>& filesInfo, std::ostream& outputStream) const {
	outputStream << "FileName,Size,Created,Modified,Access\n";

	for (const FileInfo& file : filesInfo) {
		outputStream << file.getFileName()
			<< "," << file.getFileSize()
			<< "," << file.getCreationTime()
			<< "," << file.getLastModified()
			<< "," << file.getAccessType() << '\n';
	}

	if (outputStream.fail()) {
		throw std::runtime_error("Error, there was a problem with output stream.");
	}
}