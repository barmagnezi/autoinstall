#include "installer.h"


int main()
{
	Installer installer(L"c:\\temp\\temp", 
	{
		{ L"c:\\windows\\system32\\cmd.exe", L"safe_cmd.exe" },
		{ L"c:\\windows\\system32\\notepad.exe", L"safe_notepad.exe" },
		{ L"c:\\windows\\system32\\notepad1.exe", L"safe1_notepad.exe" }
	}
	);
	installer.install();
}

