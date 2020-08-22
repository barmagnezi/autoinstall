#pragma once
#include "install_action.h"
#include "windows_exception.h"

/**
* Exception represent that CopyFileException failed with some windows error.
* This class only override prefix_message function from prefix_message;
*/
class CopyFileException : public WindowsException
{
	std::string prefix_message() const override;
};

/**
* Implementation of single copy file for installation.
* The class copy file on constructor and delete it automatically if installation failed (read more about InstallAction object)
*/
class CreateFileAction : public InstallAction
{
private:
	const std::wstring dst_path_;
public:
	CreateFileAction(const std::wstring& src_path, const std::wstring& dst_path);
	~CreateFileAction();
};
