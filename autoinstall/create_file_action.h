#pragma once
#include "install_action.h"
#include "windows_exception.h"

class CopyFileException : public WindowsException
{
	std::string prefix_message()  const;
};


class CreateFileAction : public InstallAction
{
private:
	const std::wstring dst_path_;
public:
	CreateFileAction(const std::wstring& src_path, const std::wstring& dst_path);
	~CreateFileAction();
};
