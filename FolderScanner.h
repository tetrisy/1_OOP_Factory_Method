#pragma once

#include "FileInfo.h"

#include <string>
#include <windows.h>
#include <vector>

class FolderScanner {
private:
	std::uint64_t calculateFileSize(DWORD lowPart, DWORD highPart) const;
	std::string convertTimeToString(const FILETIME& fileTime) const;
	std::string convertAccessToString(const DWORD attributes) const;

public:
	std::vector<FileInfo> scanFolder(const std::string& folderPath) const;
};