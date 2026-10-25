#pragma once

#include <windows.h>

class FindHandleGuard {
private:
	HANDLE m_handle;
public:
	explicit FindHandleGuard(HANDLE handle) : m_handle(handle) {}
	FindHandleGuard(const FindHandleGuard&) = delete;
	FindHandleGuard& operator=(const FindHandleGuard&) = delete;

	HANDLE getHandle() const {
		return m_handle;
	}

	bool isValid() const {
		return (m_handle != INVALID_HANDLE_VALUE && m_handle != nullptr);
	}

	~FindHandleGuard() {
		if (isValid()) {
			FindClose(m_handle);
		}
	}
};