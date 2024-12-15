#pragma once
#include <fstream>
#include <string>
#include <codecvt>

class Config
{
	static std::wstring			m_LocateFile;

	static void					PooP(std::string* string);
	static void					PooP(std::wstring* string);

public:

	static void					SetLocate(std::wstring locateFile);

	static std::wstring			GetLocate();


	static std::wstring			Read(std::wstring settingName);
	static std::wstring			Read(std::wstring locateFile, std::wstring settingName);

	static void					Write(std::wstring settingName, std::wstring value);
	static void					Write(std::wstring locateFile, std::wstring settingName, std::wstring value);


	static void					CreateConfig(std::wstring locateFile, bool visible = true);

	static void					CopyConfig(std::wstring locateFile, std::wstring copyingFile);

	static void					DeleteConfig(std::string locateFile);


	static void					Create(std::wstring settingName, std::wstring value);
	static void					Create(std::wstring locateFile, std::wstring settingName, std::wstring value);

	static void					Delete(std::wstring settingName);
	static void					Delete(std::wstring locateFile, std::wstring settingName);

};
