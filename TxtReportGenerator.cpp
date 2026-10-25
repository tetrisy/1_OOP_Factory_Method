#include "TxtReportGenerator.h"

#include <stdexcept>

void TxtReportGenerator::generateReport(const std::vector<FileInfo>& filesInfo, std::ostream& outputStream) const {
	for (const FileInfo& file : filesInfo) {
		outputStream << "File Name: " << file.getFileName()
			<< " | Size: " << file.getFileSize() 
			<< " | Created: " << file.getCreationTime()
			<< " | Modified: " << file.getLastModified()
			<< " | Access: " << file.getAccessType() << '\n';
	}

	if (outputStream.fail()) {
		throw std::runtime_error("Error, there was a problem with output stream.");
	}
};