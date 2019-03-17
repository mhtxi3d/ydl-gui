/**=============================================================================+
 * file name  : Main.cpp
 * created    : 2019.03.03
 * author     : sam
 * copyright  : Copyright(C) I3D Technology Inc. All rights reserved.
+=============================================================================*/
#include "../JuceLibraryCode/JuceHeader.h"

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

const char kTestVideoURL[] = "https://youtu.be/OYMUL48fHH4";

TEST_CASE("Really download video", "[.]")
{
	const auto ydl_exe = File::getSpecialLocation(File::currentExecutableFile)
		.getParentDirectory()
		.getChildFile("youtube-dl.exe");
	// youtube-dl.exe URL
	const auto cmd = ydl_exe.getFullPathName() + " " + "--newline " + kTestVideoURL;
	ChildProcess cp;
	REQUIRE(cp.start(cmd));
}
