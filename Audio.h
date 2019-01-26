//Engine52 v1.09 Audio Handler
//Audio.h Contains the function and variable declerations for Audio Handler
#pragma once
#include <String>
#include"HAPI_lib.h"

using namespace HAPISPACE;

class Audio
{
public:
	
	Audio();
	static Audio& GetInstance();
	static void DeleteInstance();
	~Audio();
	bool LoadAudio(const std::string& rFilename);
	bool PlayAudio(const std::string& rFilename);
	bool PlayAudio(const std::string& rFilename, const HAPI_TSoundOptions &options);
	bool PlayAudio(const std::string& rFilename, const HAPI_TSoundOptions &options, int& rInstanceID);
private:
	static Audio *_mpInstanceA;

};
#define AUDIO Audio::GetInstance()

