#pragma once
#include <fstream>
#include <string>
#include <codecvt>

class File
{
public:

	class Read
	{
	public:

		static int				int_read(std::string locate_file, std::string setting_name);

		static float			float_read(std::string locate_file, std::string setting_name);

		static bool				bool_read(std::string locate_file, std::string setting_name);

		static std::wstring		wstring_read(std::wstring locate_file, std::wstring setting_name);
	};

	class Write
	{
	public:

		static void				int_write(std::string locate_file, std::string setting_name, int value);

		static void				float_write(std::string locate_file, std::string setting_name, float value);

		static void				bool_write(std::string locate_file, std::string setting_name, bool value);

		static void				wstring_write(std::wstring locate_file, std::wstring setting_name, std::wstring value);
	};
};
