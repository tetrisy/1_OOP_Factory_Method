#include "JsonReportGenerator.h"

#include <stdexcept>

void JsonReportGenerator::generateReport(const std::vector<FileInfo>& filesInfo, std::ostream& outputStream) const {
	outputStream << "[\n";

	for (std::size_t i = 0; i < filesInfo.size(); ++i) {
		outputStream << "\t{\n"
			<< "\t\t\"fileName\": \"" << filesInfo[i].getFileName() << "\",\n"
			<< "\t\t\"size\": " << filesInfo[i].getFileSize() << ",\n"
			<< "\t\t\"created\": \"" << filesInfo[i].getCreationTime() << "\",\n"
			<< "\t\t\"modified\": \"" << filesInfo[i].getLastModified() << "\",\n"
			<< "\t\t\"access\": \"" << filesInfo[i].getAccessType() << "\"\n"
			<< "\t}";
		if (i + 1 < filesInfo.size()) {
			outputStream << ",";
		}
		outputStream << '\n';
	}

	outputStream << "]\n";

	if (outputStream.fail()) {
		throw std::runtime_error("Error, there was a problem with output stream.");
	}
}