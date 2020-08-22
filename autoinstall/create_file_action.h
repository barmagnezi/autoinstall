#pragma once
#include "install_action.h"
#include "windows_exception.h"

#include <string>

class CopyFileException : public WindowsException
{
	std::string prefix_message();
};


class CreateFileAction : public InstallAction
{
private:
	std::wstring dst_path_;
public:
	CreateFileAction(std::wstring src_path, std::wstring dst_path);
	~CreateFileAction();
};
