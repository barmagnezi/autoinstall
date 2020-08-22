#pragma once
#include "install_action.h"

#include <list>
#include <tuple>


typedef std::tuple<std::wstring, std::wstring> src_dst;

class Installer {
	const std::wstring install_dir_;
	const std::list<src_dst> src_dst_files_;

public:
	Installer(const std::wstring& install_dir, const std::list<src_dst>& files);
	bool install() const;
};