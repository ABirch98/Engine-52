//Engine52 v1.09 Audio handler 
//Audio.cpp contains Audio class function implementations for Engine52
#include "Audio.h"

Audio *Audio::_mpInstanceA{ nullptr };

Audio& Audio::GetInstance()
{
	if (_mpInstanceA == nullptr)
	{
		_mpInstanceA = new Audio;
		return *_mpInstanceA;
	}
	else
		return *_mpInstanceA;

}

void Audio::DeleteInstance()
{
	delete _mpInstanceA;
}

Audio::Audio()
{
}


Audio::~Audio()
{
}

bool Audio::LoadAudio(const std::string& rFilename)
{
	if (!HAPI.LoadSound(rFilename))
	{
		HAPI.UserMessage("Failed to load"+rFilename, "ERROR", HAPI_ButtonType::eButtonTypeOk, 0);
		return false;
	}
	return true;

}

bool Audio::PlayAudio(const std::string& rFilename)
{
	if (!HAPI.PlaySound(rFilename))
	{
		HAPI.UserMessage("Failed to play"+rFilename, "ERROR", HAPI_ButtonType::eButtonTypeOk, 0);
		return false;
	}
		
	return true;
}

bool Audio::PlayAudio(const std::string& rFilename, const HAPI_TSoundOptions& rOptions)
{
	if (!HAPI.PlaySound(rFilename,rOptions))
	{
		HAPI.UserMessage("Failed to play" + rFilename, "ERROR", HAPI_ButtonType::eButtonTypeOk, 0);
		return false;
	}

	return true;
}

bool Audio::PlayAudio(const std::string& rFilename, const HAPI_TSoundOptions& rOptions, int& rInstanceID)
{
	if (!HAPI.PlaySound(rFilename, rOptions, rInstanceID))
	{
		HAPI.UserMessage("Failed to play"+rFilename, "ERROR", HAPI_ButtonType::eButtonTypeOk, 0);
		return false;
	}

	return true;
}
