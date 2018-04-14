#pragma once

#include <string>
#include <atlstr.h>
#include <sstream>


class ConvertConfig
{
public:
	template <typename T>
	static std::string T_to_string(T const &val)
	{
		std::ostringstream ostr;
		ostr << val;

		return ostr.str();
	}

	template <typename T>
	static T string_to_T(std::string const &val)
	{
		std::istringstream istr(val);
		T returnVal;
		if (!(istr >> returnVal))
			throw std::exception(("CFG: Not a valid " + (std::string)typeid(T).name() + " received!\n").c_str());
			//MessageBox(NULL, CStringW(("CFG: Not a valid " + (std::string)typeid(T).name() + " received!\n").c_str()), L"Conversion error", MB_OK);

		return returnVal;
	}

	template <>
	static std::string string_to_T(std::string const &val)
	{
		return val;
	}
};
