#include "FileInfo.h"
#include "FolderScanner.h"
#include "HandleGuard.h"

#include <format>
#include <stdexcept>

std::uint64_t FolderScanner::calculateFileSize(DWORD lowPart, DWORD highPart) const {
	ULARGE_INTEGER calculate;
	calculate.LowPart = lowPart;
	calculate.HighPart = highPart;

	return calculate.QuadPart;
}

std::string FolderScanner::convertTimeToString(const FILETIME& fileTime) const {
	SYSTEMTIME systemTime{};
	if (FileTimeToSystemTime(&fileTime, &systemTime) == 0) {
		throw std::runtime_error("Error while converting to time string.");
	}

	std::string time = std::format("{}/{}/{} {}:{:02}", systemTime.wDay, systemTime.wMonth, systemTime.wYear, systemTime.wHour, systemTime.wMinute);

	return time;
}

std::string FolderScanner::convertAccessToString(const DWORD attributes) const {
	if ((attributes & FILE_ATTRIBUTE_READONLY) != 0) {
		return "Read-Only";
	}
	else {
		return "Read-Write";
	}
}

std::vector<FileInfo> FolderScanner::scanFolder(const std::string& folderPath) const {
	if (folderPath.empty()) {
		throw std::invalid_argument("Invalid file path.");
	}

	std::string searchPath{};

	if (folderPath.back() == '\\' || folderPath.back() == '/') {
		searchPath = folderPath + "*";
	}
	else {
		searchPath = folderPath + "\\*";
	}

	

	WIN32_FIND_DATAA findData{};

	FindHandleGuard handleGuard(FindFirstFileA(searchPath.c_str(), &findData));

	std::vector<FileInfo> fileInfos{};

	if (!handleGuard.isValid()) {
		throw std::runtime_error("Failed to read from folder.");
	}

	do {
		if ((findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0) {
			FileInfo file(
				findData.cFileName, 
				calculateFileSize(findData.nFileSizeLow, 
				findData.nFileSizeHigh), 
				convertTimeToString(findData.ftCreationTime), 
				convertTimeToString(findData.ftLastWriteTime),
				convertAccessToString(findData.dwFileAttributes)
				);

			fileInfos.push_back(file);
		}
	} while (FindNextFileA(handleGuard.getHandle(), &findData) != 0);

	if (GetLastError() != ERROR_NO_MORE_FILES) {
		throw std::runtime_error("There was an error while scanning files.");
	}

	return fileInfos;
}