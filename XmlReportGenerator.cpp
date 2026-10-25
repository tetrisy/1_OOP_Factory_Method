#include "XmlReportGenerator.h"

#include <stdexcept>

void XmlReportGenerator::generateReport(const std::vector<FileInfo>& filesInfo, std::ostream& outputStream) const {
	outputStream << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
	outputStream << "<Files>\n";

	for (const FileInfo& file : filesInfo) {
		outputStream << "\t<File>\n"
			<< "\t\t<FileName>" << file.getFileName() << "</FileName>\n"
			<< "\t\t<Size>" << file.getFileSize() << "</Size>\n"
			<< "\t\t<Created>" << file.getCreationTime() << "</Created>\n"
			<< "\t\t<Modified>" << file.getLastModified() << "</Modified>\n"
			<< "\t\t<Access>" << file.getAccessType() << "</Access>\n"
			<< "\t</File>\n";
	}
	
	outputStream << "</Files>\n";

	if (outputStream.fail()) {
		throw std::runtime_error("Error, there was a problem with output stream.");
	}
}