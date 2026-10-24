#pragma once

#include <cstdint>
#include <string>

class FileInfo {
private:
	std::string m_fileName;
	std::uint64_t m_fileSize;
	std::string m_creationTime;
	std::string m_lastModified;
	std::string m_accessType;

public:
	FileInfo(const std::string& fileName, std::uint64_t fileSize, const std::string& creationTime, const std::string& lastModified, const std::string& accessType)
		: m_fileName(fileName), m_fileSize(fileSize), m_creationTime(creationTime), m_lastModified(lastModified), m_accessType(accessType) {

	};

	const std::string& getFileName() const {
		return m_fileName;
	}

	std::uint64_t getFileSize() const {
		return m_fileSize;
	}

	const std::string& getCreationTime() const {
		return m_creationTime;
	}

	const std::string& getLastModified() const {
		return m_lastModified;
	}

	const std::string& getAccessType() const {
		return m_accessType;
	}
};