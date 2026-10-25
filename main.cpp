#include "FolderScanner.h"
#include "IReportGeneratorFactory.h"
#include "ReportGeneratorFactory.h"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

void createAndWriteReport(const IReportGeneratorFactory& factory, const std::vector<FileInfo>& files, std::ostream& outputStream) {
    std::unique_ptr<IReportGenerator> reportGenerator = factory.createGenerator();
    reportGenerator->generateReport(files, outputStream);
}

void saveReportToFile(const IReportGeneratorFactory& factory, const std::vector<FileInfo>& files, const std::string& fileName) {
    std::ofstream outputFile(fileName);

    if (!outputFile.is_open()) {
        throw std::runtime_error("Couldn't open a file");
    }

    createAndWriteReport(factory, files, outputFile);
}

int main()
{
    std::cout << "Enter full folder path: ";
    try {
        std::string folderPath{};

        std::getline(std::cin, folderPath);
        
        FolderScanner folderScanner;
        const std::vector<FileInfo> files = folderScanner.scanFolder(folderPath);

        TxtReportGeneratorFactory txtReportGeneratorFactory;
        CsvReportGeneratorFactory csvReportGeneratorFactory;
        XmlReportGeneratorFactory xmlReportGeneratorFactory;
        JsonReportGeneratorFactory jsonReportGeneratorFactory;

        saveReportToFile(txtReportGeneratorFactory, files, "report.txt");
        saveReportToFile(csvReportGeneratorFactory, files, "report.csv");
        saveReportToFile(xmlReportGeneratorFactory, files, "report.xml");
        saveReportToFile(jsonReportGeneratorFactory, files, "report.json");

        createAndWriteReport(txtReportGeneratorFactory, files, std::cout);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    catch (...) {
        std::cerr << "Unknown error." << "\n";
        return 1;
    }
    
    return 0;
}
