#include "File.h"

int File::Read::int_read(std::string locate_file, std::string setting_name)
{
	std::fstream file(locate_file);

	std::string current_line;

	while (current_line.substr(0, setting_name.length()) != setting_name)
	{
		std::getline(file, current_line);
	}

	return std::stoi(current_line.substr(setting_name.length() + 4, current_line.find_last_of("\"") - (setting_name.length() + 4)));
}

float File::Read::float_read(std::string locate_file, std::string setting_name)
{
	std::fstream file(locate_file);

	std::string current_line;

	while (current_line.substr(0, setting_name.length()) != setting_name)
	{
		std::getline(file, current_line);
	}

	return std::stof(current_line.substr(setting_name.length() + 4, current_line.find_last_of("\"") - (setting_name.length() + 4)));
}

bool File::Read::bool_read(std::string locate_file, std::string setting_name)
{
	std::fstream file(locate_file);

	std::string current_line;

	while (current_line.substr(0, setting_name.length()) != setting_name)
	{
		std::getline(file, current_line);
	}

	if (current_line.substr(setting_name.length() + 4, current_line.find_last_of("\"") - (setting_name.length() + 4)) == "true")
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::wstring File::Read::wstring_read(std::wstring locate_file, std::wstring setting_name)
{
	std::wfstream file(locate_file);

	std::wstring current_line;

	file.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));

	while (current_line.substr(0, setting_name.length()) != setting_name)
	{
		std::getline(file, current_line);
	}

	return current_line.substr(setting_name.length() + 4, current_line.find_last_of(L"\"") - (setting_name.length() + 4));
}


void File::Write::int_write(std::string locate_file, std::string setting_name, int value)
{
	std::ifstream file(locate_file);

	std::string current_line;

	std::string current_text;

	while (std::getline(file, current_line))
	{
		if (current_line.substr(0, setting_name.length()) == setting_name)
		{
			current_line.replace(setting_name.length() + 4, current_line.find_last_of("\"") - (setting_name.length() + 4), std::to_string(value));
		}

		current_text += current_line + "\n";
	}

	file.close();

	std::ofstream new_file(locate_file);

	new_file << current_text;

	new_file.close();
}

void File::Write::float_write(std::string locate_file, std::string setting_name, float value)
{
	std::ifstream file(locate_file);

	std::string current_line;

	std::string current_text;

	while (std::getline(file, current_line))
	{
		if (current_line.substr(0, setting_name.length()) == setting_name)
		{
			current_line.replace(setting_name.length() + 4, current_line.find_last_of("\"") - (setting_name.length() + 4), std::to_string(value));
		}

		current_text += current_line + "\n";
	}

	file.close();

	std::ofstream new_file(locate_file);

	new_file << current_text;

	new_file.close();
}

void File::Write::bool_write(std::string locate_file, std::string setting_name, bool value)
{
	std::ifstream file(locate_file);

	std::string current_line;

	std::string current_text;

	while (std::getline(file, current_line))
	{
		if (current_line.substr(0, setting_name.length()) == setting_name)
		{
			if (value)
			{
				current_line.replace(setting_name.length() + 4, current_line.find_last_of("\"") - (setting_name.length() + 4), "true");
			}
			else
			{
				current_line.replace(setting_name.length() + 4, current_line.find_last_of("\"") - (setting_name.length() + 4), "false");
			}
		}

		current_text += current_line + "\n";
	}

	file.close();

	std::ofstream new_file(locate_file);

	new_file << current_text;

	new_file.close();
}

void File::Write::wstring_write(std::wstring locate_file, std::wstring setting_name, std::wstring value)
{
	std::wifstream file(locate_file);

	std::wstring current_line;

	std::wstring current_text;

	file.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));

	while (std::getline(file, current_line))
	{
		if (current_line.substr(0, setting_name.length()) == setting_name)
		{
			current_line.replace(setting_name.length() + 4, current_line.find_last_of(L"\"") - (setting_name.length() + 4), value);
		}

		current_text += current_line + L"\n";
	}

	file.close();

	std::wofstream new_file(locate_file);

	new_file.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));

	new_file << current_text;

	new_file.close();
}
