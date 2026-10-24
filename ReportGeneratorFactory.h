#pragma once

#include "CsvReportGenerator.h"
#include "IReportGeneratorFactory.h"
#include "JsonReportGenerator.h"
#include "TxtReportGenerator.h"
#include "XmlReportGenerator.h"

#include <memory>

class CsvReportGeneratorFactory : public IReportGeneratorFactory {
public:
	std::unique_ptr<IReportGenerator> createGenerator() const override {
		return std::make_unique<CsvReportGenerator>();
	}
};

class JsonReportGeneratorFactory : public IReportGeneratorFactory {
public:
	std::unique_ptr<IReportGenerator> createGenerator() const override {
		return std::make_unique<JsonReportGenerator>();
	}
};

class TxtReportGeneratorFactory : public IReportGeneratorFactory {
public:
	std::unique_ptr<IReportGenerator> createGenerator() const override {
		return std::make_unique<TxtReportGenerator>();
	}
};

class XmlReportGeneratorFactory : public IReportGeneratorFactory {
public:
	std::unique_ptr<IReportGenerator> createGenerator() const override {
		return std::make_unique<XmlReportGenerator>();
	}
};