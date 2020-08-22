#include "create_file_action.h"
#include <iostream>

#define FAILED_IF_EXISTS TRUE


std::string CopyFileException::prefix_message() const {
	return "Copy file failed failed with error code:";
}

/**
* Constructor will create copy file to installation folder.
* If there is some "windows" problem to copy the file CopyFileException exception will be raised.
* The function will failed if destination path exists.
*/
CreateFileAction::CreateFileAction(const std::wstring& src_path, const std::wstring& dst_path) : dst_path_(dst_path)
{
	// Copy file will be failed if file already exists in dst_path.
	if (CopyFile(src_path.c_str(), dst_path_.c_str(), FAILED_IF_EXISTS))
	{
		std::wcout << L"File " << dst_path_ << L" Created" << std::endl;
	}
	else
	{
		throw CopyFileException();
	}
}

/**
* Destructor will delete file if installation failed.
* If there is some "windows" problem to delete file, the function will write log and continue.
*/
CreateFileAction::~CreateFileAction()
{
	if (!is_install_success())
	{
		if (!DeleteFile(dst_path_.c_str()))
		{
			std::wcout << L"Error deleting file " << dst_path_ << L", continue." << std::endl;
		}
		else
		{
			std::wcout << L"File " << dst_path_ << L" deleted." << std::endl;
		}
	}
}
