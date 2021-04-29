# Introduction
In a general perspective, a file system also called filesystem or just fs, is the structure and logic norms used to manage groups of data. This system controls how data is stored and read, this way the different groups of information in a disk, drive or RAM have a determined location, size and name; and therefore they are usable for programs. Each of these groups of data is called a file.

There are different types of filesystems depending on their structure, logic, properties, security etc. They can be designed to work for a specific device, platform or application thus companies normally design their own to manage their files in a more optimised way. However, as we have seen there are numerous types and they can be used perfectly in a lot of cases.

Filesystems are present in different environments too, they are used in local data storage devices and through network protocols such as NFS (Network File System) developed by Sun Microsystems in 1984, SMB (Server Message Block) also known as Common Internet File System or 9P developed for the Plan 9 operating system that used Unix concepts by Bell Labs in the 1980’s.

## Types of Filesystems
Among all the types of filesystems that we can differentiate, we can identify the two most important: physical and virtual filesystems. 

### Physical Filesystem
The physical filesystem is responsible for the physical operations of the storage device; these operations are mechanical in case it is managing a disk, for example. All the computing processes to read and write physical chunks of data are managed by this type of filesystem, as well as the buffering and memory management to reserve space and place the data. The physical filesystem communicates directly with the device drivers or the specific channel used to transmit this information.

### Virtual Filesystem
On the other hand we have the virtual fileystem, which is a system that works with virtual files when they are requested by the computer. The virtual filesystem manages the access to the content of a file and its metadata but is still responsible for using the enough storage space, being efficient and reliable to guarantee a proper management of the physical storage.

However, while virtual filesystems are optional for the correct operation of a system, the physical one is always necessary to work.

## Filesystem API
Between the user application and the logical filesystem there is an API (Application Program Interface) to manage the file operations that may be required each time. A filesystem API is used by language specific libraries and user programs to make requests like transferring data, position it, manage directories etc.

The API can be called the medium layer between the raw files in the system and what the user sees as a result. This layer offers file access operations (open, read, write, close etc.) to the logical filesystem layer and some security and protection for the user and the program itself in order to avoid external or internal unwanted accesses. In this research our API works on top of the operating system’s virtual filesystem.

The operating system is in charge of providing abstraction to access the filesystem transparently in order to have a proper functioning. For example, Microsoft Windows uses APIs for NTFS (proprietary filesystem) and FAT (File Allocation Table), or Linux that uses them for ReiserFS (by Hans Reiser) and Btrfs (by Oracle Corporation) among others.

### Important Concepts
- Filenames: identifier for a storage location in the file system. They can be limited in length and can be case sensitive for the filesystem to differentiate them.

- Directory (or Folder): structures that allow the user to group files into collections. These collections can be made of a table of contents that contains filenames like in a Unix filesystem.

# Market Study
We can find several different file system APIs in the market that are being used in operating systems:

- Linux: implements a kernel-level API which means that the lowest-level instructions from the OS not only provide interfaces to develop the filesystems but it is where the filesystem code and logic is. There was the MS-DOS operating system developed by Microsoft that used this type of API too.

- Windows NT: the common Microsoft Windows OS that is present in the majority of personal computers uses a driver-based API, meaning that the filesystem code and logic doesn’t reside in the kernel but it is totally external. This allows Microsoft to keep their kernel closed to the public and modify the Windows filesystem via online.

## Filesystem APIs in Games
In video games, the filesystem API is in charge of loading the game assets stored on disk, like sprites, music, sound effects, fonts etc. To hardcode the paths for each asset will break the portability to other platforms as many games would need; so the proper way to manage multiple platforms is to use a virtual filesystem that mounts our assets folder that gets rid of any working directories issues.

The main benefit is that the game will load files from local directories without needing to specify each time the disk where it is. This removes any operating system differences and limitations from the game as dependencies, in trade of the virtual filesystem dependency.

The other great benefit is the run-time efficiency when using a filesystem API because the files loading will be done from a single archive (for example a .zip) with its own security processes and simple commands, so the operating system heavy-weight operations for security checks will be avoided.

As an extra feature, the virtual filesystem can handle duplicate aliases for a file, so changing the extension or instead of modifying a file, adding another one entirely that substitutes it is easier to do. This allows the developer to introduce patches to the game without deleting the old files in a faster way; nevertheless, bigger patches may require to modify the old files to avoid long downloads for players.

As an example of a proprietary filesystem in a game we have Doom. From Wolfenstein 3D (1992) they introduced the WAD files that stands for “Where’s All the Data” that the first Doom fully implemented. This file format is spreadly known in the industry because it gives flexibility not only for developers but also users, to create patches, mods and increase the security and more importantly, the performance. This is due to how the IdSoftware game used their filesystem, because it used few bigger binary files instead of smaller ones.

The Doom’s file format was used to release their assets files in the final version of the game, avoiding also that the user could manipulate them easily. However, this format can be kind of read by a Hex editor. The WAD file includes a file header containing a pointer to a series of directories at the end of the file and those directories point to where their data starts in the file. 

# Selected Approach
For this research, the chosen approach is done using the PhysicsFS API, the library that provides abstract access to archives. It was intended to use in video games and as its creator Ryan C. Gordon mentions; it was partially inspired by the Quake’s 3 file subsystem where he worked. 

As we are intended to see in this research, we will focus only on reading and loading assets’ files into our game. PhysicsFS or PhysFS as his creator calls it, implements a tool for reading using a search path specified by the programmer with the archives and directories of the assets. So it becomes a “transparent hierarchical file system” that allows us to access ZIP files in order to use the benefits of using a virtual filesystem as mentioned before. This API gets rid of the program accessing outside our determined archive as well as ‘ . ’ and ‘ .. ’ commands.  You can think of this as a filesystem within a filesystem. If (on Windows) you were to set the writing directory to "C:\MyGame\MyWritingDirectory", then no PHYSFS calls could touch anything above this directory, including the "C:\MyGame" and "C:\" directories. This gives an abstraction across all platforms. Specifying a file in this way is termed "platform-independent notation".

To use the PhysicsFS API we need to build it from source. My choice was to use CMake. You don't need to build it on your own as you can find my Visual Studio Solution with the corresponding headers and dll. Here is a simple guide to follow:

1. Download the latest PhysFS release and CMake from their official webpage and create a personal folder to save the CMake files that will be generated.

2. In CMake, select the PhysFS release folder you just have downloaded as the source code and select your destination folder you have created as where to build the binaries.

3. Configure the process for Win32 and Visual Studio 19.

4. Discard all the files in screen except the PHYSFS_ARCHIVE_ZIP and the PHYSFS_BUILD_SHARED. Here my destination folder is called PHYSFS Research:
![](https://github.com/yeraytm/Assets-ZIP-Manager-PhysFS/blob/master/docs/images/cmake.png)

5. Go to the folder where CMake has built a Visual Studio Solution and open it:
![](https://github.com/yeraytm/Assets-ZIP-Manager-PhysFS/blob/master/docs/images/cmake_solution.png)

6. Now you just have to build in Release mode:
![](https://github.com/yeraytm/Assets-ZIP-Manager-PhysFS/blob/master/docs/images/physfs_build.png)

7. Finally, you will find the needed dll and lib of PhysFS in the Release Folder of the Solution:
![](https://github.com/yeraytm/Assets-ZIP-Manager-PhysFS/blob/master/docs/images/physfs_release.png)

## Implementation
As a result, in this project I have implemented a Module called AssetsManager that allows us to load all of our assets from the ZIP file. There are two load methods, the `LoadAsset()` to load assets like textures, music or sound effects, that implements an adaptation of PHYSFS to directly pass to SDL as it is more handy and optimised. And a `LoadXML()` method for any XML file that we may need to use in our game, such as: saved game information, entities positions etc.

The method used to load our assets needs the path of the asset from the ZIP file, so it will be something like: Textures/image.png or Audio/Fx/jump.wav
It returns a SDL_RWops pointer structure to be able to load our asset from SDL in the Textures or Audio modules.
```cpp
SDL_RWops* LoadAsset(const char* path);
```

The method used to load an XML file is a bit more complex. It needs as a parameter a path (like in `LoadAsset()`) and a buffer that must be able to be modified, so we need a [double pointer](https://stackoverflow.com/questions/20589045/modify-buffer-passed-as-a-pointer) to read the XML file and save the data into the buffer. 
It returns the size of the file in bytes.
```cpp
size_t LoadXML(const char* path, char** buffer);
```

As a try to encryption, the archive that contains and compresses the assets instead of being a ZIP file, I have renamed it to Assets.pak to avoid all the users that don't know about PAK files to change any of our games assets. This can be reverted by changing again the extension to .zip.

![](https://github.com/yeraytm/Assets-ZIP-Manager-PhysFS/blob/master/docs/images/assets_archive.jpg)

Following the PhysicsFS documentation and some information to load from memory, here they are the used functions and code:

- `PHYSFS_init()`: Initialize the PhysicsFS library. This must be called before any other PhysicsFS function. The parameter can be NULL.
- `PHYSFS_mount()`: Add an archive or directory to the search path. Should receive the naem and extension of our Assets archive, a mountPoint that we can leave on NULL and the append to search path integer that can be 1.
- `PHYSFS_exists()`: Determine if a file exists in the search path.
- `PHYSFS_openRead()`: Open a file for reading, in platform-independent notation. The search path is checked one at a time until a matching file is found. It returns a PHYSFS_file filehandle that must be saved into a variable.
- `PHYSFSRWOPS_openRead()`: Open a platform-independent filename for reading, and make it accessible via an SDL_RWops structure. The file will be closed in PhysicsFS when the RWops is closed.
- `PHYSFS_eof()`: Check for end-of-file state on a PhysicsFS filehandle.
- `PHYSFS_fileLength()`: Get total length of a file in bytes.
- `PHYSFS_readBytes()`:  Read bytes from a PhysicsFS filehandle. The file must be opened for reading. The buffer parameter should be passed by reference.
- `PHYSFS_close()`: Close a PhysicsFS filehandle. It must be done every time the filehandle has been opened.
- `PHYSFS_getErrorByCode(PHYSFS_getLastErrorCode())`: In case we may need to LOG any error from PhysFS.

In order to load the assets from the SDL_RWops structure we will need specific SDL function that are similar to the ones we have been using, but the parameters are our SDL_RWops pointer and the free source that can be 0. The SDL_WRops is a structure that provides an abstract interface to stream I/O and allows us to use SDL with PhysFS.

- To load a texture from SDL_RWops to SDL_Surface: `IMG_Load_RW()`
- To load music from SDL_RWops to Mix_Music: `Mix_LoadMUS_RW()`
- To load a sound Fx from SDL_RWops to Mix_Chunk: `Mix_LoadWAV_RW()`

After loading a SDL_Texture or Mix_Chunk we will need to close and free the allocated SDL_RWops structure using `SDL_RWclose(SDL_RWops*)` that does it all.

In order to load XML documents we will need to declare a buffer pointer where we want to load the file and pass it to the `LoadXML()` method by reference. From what the method returns (the size of the files in bytes) we will need to use the `load_buffer()` method from inside of the `xml_document` passing a copy of the buffer and its size. After having loaded the file, we can free the buffer array.

# Exercises

TODO 0: Initialize the PhysFS API and mount the Assets file, return false to check if there is any error
```cpp
	if (PHYSFS_init(NULL) == 0)
	{
		LOG("ERROR INITIALIZING PHYSFS LIBRARY: %s\n", PHYSFS_getErrorByCode(PHYSFS_getLastErrorCode()));
		return false;
	}

	if (PHYSFS_mount("Assets.pak", NULL, 1) == 0)
	{
		LOG("ERROR ADDING ARCHIVE TO SEARCH PATH: %s\n", PHYSFS_getErrorByCode(PHYSFS_getLastErrorCode()));
		return false;
	}
```

TODO 1: Check if the file intended to load actually exists in the Assets ZIP
```cpp
	if (PHYSFS_exists(path) == 0)
	{
		LOG("ERROR - FILE %s DOESNT EXIST IN THE SEARCH PATH: %s\n", path, PHYSFS_getErrorByCode(PHYSFS_getLastErrorCode()));
		return NULL;
	}
```

TODO 2: Open the file for reading using the RWops accessible structure by PhysFS, and save that structure for the function to return.
```cpp
	SDL_RWops* ret = PHYSFSRWOPS_openRead(path);

	if (ret == NULL)
	{
		LOG("ERROR OPENING FILE %s FOR READING: %s\n", path, PHYSFS_getErrorByCode(PHYSFS_getLastErrorCode()));
		return NULL;
	}

	return ret;
```

TODO 3: Repeat what you have done in the LoadAsset() method but instead of using a RWops structure, use a PHYSFS_file
```cpp
if (PHYSFS_exists(path) == 0)
		LOG("ERROR - FILE %s DOESNT EXIST IN THE SEARCH PATH: %s\n", path, PHYSFS_getErrorByCode(PHYSFS_getLastErrorCode()));

	PHYSFS_file* file = PHYSFS_openRead(path);
	if (file == NULL)
		LOG("ERROR OPENING FILE %s FOR READING: %s\n", path, PHYSFS_getErrorByCode(PHYSFS_getLastErrorCode()));
```

TODO 4: Check if PhysFS has not ended to read the file and obtain the size of the file in bytes
```cpp
if (!PHYSFS_eof(file))
	{
		PHYSFS_sint64 size = PHYSFS_fileLength(file);

```

TODO 5: Allocate enough memory for the buffer to read the file (Be aware to modify the contents of the buffer)
```cpp
    *buffer = new char[size];

		PHYSFS_sint64 numBytesRead = PHYSFS_readBytes(file, *buffer, size);
		if (numBytesRead == -1)
			LOG("ERROR READING FROM FILEHANDLE: %s\n", PHYSFS_getErrorByCode(PHYSFS_getLastErrorCode()));
```

TODO 6: Close the file when finished and return its number of bytes. If the reading process is successful (has finished) it means that the number of byes read is equal to the size of the file.
```cpp
		if (numBytesRead == size)
		{
			if (PHYSFS_close(file) == 0)
				LOG("ERROR CLOSING FILEHANDLE: %s\n", PHYSFS_getErrorByCode(PHYSFS_getLastErrorCode()));

			return numBytesRead;
		}
		else
		{
			PHYSFS_close(file);
			RELEASE_ARRAY(buffer);
			return 0;
		}
```

TODO 7: Load the texture using the SDL_RWops structure and close the allocated SDL_RWops structure
```cpp
SDL_RWops* rw = app->assetsManager->LoadAsset(path);
SDL_Surface* surface = IMG_Load_RW(rw, 0);
  
SDL_RWclose(rw);
````

TODO 8: Repeat what we have done for the texture but with the sound effects and music
```cpp
SDL_RWops* rw = app->assetsManager->LoadAsset(path);
Mix_Chunk* chunk = Mix_LoadWAV_RW(rw, 0);
  
SDL_RWops* rw = app->assetsManager->LoadAsset(path);
music = Mix_LoadMUS_RW(rw, 0);
```

TODO 9: Load a Font XML document using a buffer. Get the size and load the XML document. Then, release the buffer
```cpp
char* buffer = nullptr;
pugi::xml_document xmlDocFontAtlas;
size_t size = app->assetsManager->LoadXML(rtpFontFile, &buffer);

pugi::xml_parse_result result = xmlDocFontAtlas.load_buffer(buffer, size);
RELEASE_ARRAY(buffer);
```

# Possible Improvements
To improve this implementation, I have mainly found two ways:

As PhysFS is focused on thread security, because it reads one file at a time, it increases loading times. As the game engine is capable of managing different threads of our CPU, with PhysFS only executing one operation at the same time makes it all slow down. However, we can identify this problem in more advanced and bigger-scale games. 
This improvement was done by Mathieu Ropert, and he first worked to integrate PhysFS using C++ in his engine and use macros and gotos instead of the present RAII accessors. He also uses different mount points that are being managed by each thread. [Here](https://youtu.be/TcuPIVKNSN0?t=1412) it is a conference of him explaining this improvement.

The second improvement could be to add more encryption to the files using [Crypto++](https://www.cryptopp.com) and then coding the decryption internally in our program. This will help to have better secured PAK files. The [ZipStorage](https://digitalrune.github.io/DigitalRune-Documentation/html/97e246e8-5bb5-020b-acbc-af2485ceccdf.htm) class from Digital Rune is intended to access package files that use the ZIP format and  manage the compression and encryption.

## Problems Found
- Not enough documentation from the library for beginners.
- Deprecated and scarce information on forums, blogs and in the official weppage.
- The Music files don't allow to do `SDL_RWclose()` for some reason.
- The config file must be outside of the Assets archive. As far it is not a big issue, being loaded first by App is tricky.  

# Documentation and References
- https://icculus.org/physfs/
- https://icculus.org/physfs/docs/html/
- https://icculus.org/physfs/physfstut.txt
- https://icculus.org/physfs/docs/html/physfs_8h.html
- https://gamedev.stackexchange.com/questions/37820/how-do-you-set-up-physfs-for-use-in-a-game
- https://pugixml.org/docs/manual.html#loading.memory
- https://wiki.libsdl.org/SDL_RWops
- https://gamedev.net/forums/topic/532838-using-physfs-with-sdl/4445176/
- https://www.youtube.com/watch?v=hwx3C18eQwc&t=8s
- https://stackoverflow.com/questions/20589045/modify-buffer-passed-as-a-pointer
- https://en.wikipedia.org/wiki/File_system
- https://en.wikipedia.org/wiki/File_system_API
- https://www.randygaul.net/2019/03/20/virtual-file-systems-in-games/
- https://simoncoenen.com/blog/programming/PakFiles
- https://mropert.github.io/2020/07/26/threading_with_physfs/
- https://digitalrune.github.io/DigitalRune-Documentation/html/120bed13-f23b-4774-bae7-d64d410d2122.htm
- https://www.youtube.com/watch?v=TcuPIVKNSN0
