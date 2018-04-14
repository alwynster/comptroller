#pragma once
#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include "Convert.h"
#include "../LED/LED.h"
#include <msclr\marshal_cppstd.h>

class ConfigFile
{
private:
	std::map<std::string, std::string> contents;
	std::string fName;

	void removeComment(std::string &line) const
	{
		if (line.find(';') != line.npos)
			line.erase(line.find(';'));
	}

	bool onlyWhitespace(const std::string &line) const
	{
		return (line.find_first_not_of(' ') == line.npos);
	}
	bool validLine(const std::string &line) const
	{
		std::string temp = line;
		temp.erase(0, temp.find_first_not_of("\t "));
		if (temp[0] == '=')
			return false;

		for (size_t i = temp.find('=') + 1; i < temp.length(); i++)
			if (temp[i] != ' ')
				return true;

		return false;
	}

	void extractKey(std::string &key, size_t const &sepPos, const std::string &line) const
	{
		key = line.substr(0, sepPos);
		if (key.find('\t') != line.npos || key.find(' ') != line.npos)
			key.erase(key.find_first_of("\t "));
	}
	void extractValue(std::string &value, size_t const &sepPos, const std::string &line) const
	{
		value = line.substr(sepPos + 1);
		value.erase(0, value.find_first_not_of("\t "));
		value.erase(value.find_last_not_of("\t ") + 1);
	}

	void extractContents(const std::string &line)
	{
		std::string temp = line;
		temp.erase(0, temp.find_first_not_of("\t "));
		size_t sepPos = temp.find('=');

		std::string key, value;
		extractKey(key, sepPos, temp);
		extractValue(value, sepPos, temp);

		if (!keyExists(key))
			contents.insert(std::pair<std::string, std::string>(key, value));
		else
			exitWithError("CFG: Can only have unique key names!\n");
	}

	void parseLine(const std::string &line, size_t const lineNo)
	{
		if (line.find('=') == line.npos)
			exitWithError("CFG: Couldn't find separator on line: " + ConvertConfig::T_to_string(lineNo) + "\n");

		if (!validLine(line))
			exitWithError("CFG: Bad format for line: " + ConvertConfig::T_to_string(lineNo) + "\n");

		extractContents(line);
	}

	void ExtractKeys(void)
	{
		std::ifstream file(this->fName.c_str());
		if (!file)
		//	exitWithError("CFG: File " + fName + " couldn't be found!\n");
		//else
			file.open("default.cfg");

		std::string line;
		size_t lineNo = 0;
		while (std::getline(file, line))
		{
			lineNo++;
			std::string temp = line;

			if (temp.empty())
				continue;

			removeComment(temp);
			if (onlyWhitespace(temp))
				continue;

			parseLine(temp, lineNo);
		}

		file.close();
	}
public:
	ConfigFile(const std::string &fName)
	{
		this->fName = fName;
		ExtractKeys();
	}

	bool keyExists(const std::string &key) const
	{
		return contents.find(key) != contents.end();
	}

	template <typename ValueType>
	ValueType getValueOfKey(const std::string &key, ValueType const &defaultValue = ValueType()) const
	{
		if (!keyExists(key))
			return defaultValue;

		return ConvertConfig::string_to_T<ValueType>(contents.find(key)->second);
	}

private:
	std::ofstream output;

public:
	void openWriteConfig()
	{
		output = std::ofstream(this->fName);
		if (!output)
			MessageBox(NULL, L"Could not open output config file", L"Config Error", MB_OK);
	}

public:
	void putBooleanConfig(std::string key, bool value)
	{
		std::string str = key + " = ";
		if (value)
			str += "1";
		else
			str += "0";
		this->output << str << std::endl;
	}


public:
	bool getBooleanConfig(std::string str)
	{
		return this->getValueOfKey<int>(str) != 0;
	}

public:
	Colour ^getColourConfig(std::string str)
	{
		return Colour::FromInt(std::stoul(this->getValueOfKey<std::string>(str), nullptr, 16));
	}

	void putColourConfig(std::string key, Colour ^col)
	{
		std::string str = key + " = ";
		this->output << str << std::hex << col->getColourCode() << std::endl;
	}

	int getIntConfig(std::string str)
	{
		return this->getValueOfKey<int>(str);
	}

	void putIntConfig(std::string key, int value)
	{
		std::string str = key + " = ";
		msclr::interop::marshal_context context;
		str += context.marshal_as<std::string>(value.ToString());
		this->output << str << std::endl;
	}

private:

	void exitWithError(const std::string &error)
	{
		MessageBox(NULL, CStringW(error.c_str()), L"Error in configuration", MB_OK);
		//std::cout << error;
		//std::cin.ignore();
		//std::cin.get();

		exit(EXIT_FAILURE);
	}
};
