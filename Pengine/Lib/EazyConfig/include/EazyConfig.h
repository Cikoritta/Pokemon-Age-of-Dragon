#pragma once
#include <fstream>
#include <string>
#include <codecvt>

class Config
{
	static std::string			m_LocateFile;

	static bool					m_log;

	static void					chechLocate();
	static void					chechLocate(std::wstring locateFile);

	static void					chechOpen(std::wfstream& wfstream);
	static void					chechOpen(std::wfstream& wfstream, std::wstring locateFile);

public:

	static void					OnLog(bool value);

	static void					SetLocate(std::string locateFile);

	static std::string			GetLocate();


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
