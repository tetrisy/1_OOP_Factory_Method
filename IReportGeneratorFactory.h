#pragma once

#include "IReportGenerator.h"
#include <memory>

class IReportGeneratorFactory {
public:
	virtual std::unique_ptr<IReportGenerator> createGenerator() const = 0;

	virtual ~IReportGeneratorFactory() = default;
};