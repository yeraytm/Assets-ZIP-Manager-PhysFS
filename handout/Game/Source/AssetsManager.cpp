#include "AssetsManager.h"
#include "App.h"

#include "Defs.h"
#include "Log.h"

#include "External/PhysFS/include/physfsrwops.h"
#include "External/PhysFS/include/physfsrwops.c"

AssetsManager::AssetsManager() : Module()
{
	name.Create("assetsManager");
}

// Destructor
AssetsManager::~AssetsManager()
{
}

// Called before Assets Manager is available
bool AssetsManager::Awake(pugi::xml_node& config)
{
	LOG("Loading Assets Manager");
	bool ret = true;

	// TODO 0: Initialize the PhysFS API and mount the Assets file, return false to check if there is any error


	return ret;
}

SDL_RWops* AssetsManager::LoadAsset(const char* path)
{
	// TODO 1: Check if the file intended to load actually exists in the Assets ZIP

	// TODO 2: Open the file for reading using the RWops accessible structure by PhysFS, and save that structure for the function to return.

	return ret;
}

size_t AssetsManager::LoadXML(const char* path, char** buffer)
{
	// TODO 3: Repeat what you have done in the LoadAsset() method but instead of using a RWops structure, use a PHYSFS_file

	// TODO 4: Check if PhysFS has not ended to read the file and obtain the size of the file in bytes
	if ()
	{
		PHYSFS_sint64 size;

		// TODO 5: Allocate enough memory for the buffer to read the file (Be aware to modify the contents of the buffer)

		PHYSFS_sint64 numBytesRead;
		if (numBytesRead == -1)
			LOG("ERROR READING FROM FILEHANDLE: %s\n", PHYSFS_getErrorByCode(PHYSFS_getLastErrorCode()));

		// TODO 6: Close the file when finished and return its number of bytes
		// If the reading process is successful (has finished) it means that the number of byes read is equal to the size of the file.
		if (numBytesRead == size)
		{
			// Close filehandle

			return numBytesRead;
		}
		else
		{
			// Close filehandle
			RELEASE_ARRAY(buffer);
			return 0;
		}
	}
}

// Called before quitting
bool AssetsManager::Cleanup()
{
	LOG("Quitting Assets Manager");

	if (PHYSFS_deinit() == 0)
		LOG("ERROR DEINITIALIZING THE PHYSFS LIBRARY: %s\n", PHYSFS_getErrorByCode(PHYSFS_getLastErrorCode()));

	return true;
}