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

### Filesystem APIs in Games
In video games, the filesystem API is in charge of loading the game assets stored on disk, like sprites, music, sound effects, fonts etc. To hardcode the paths for each asset will break the portability to other platforms as many games would need; so the proper way to manage multiple platforms is to use a virtual filesystem that mounts our assets folder that gets rid of any working directories issues.

The main benefit is that the game will load files from local directories without needing to specify each time the disk where it is. This removes any operating system differences and limitations from the game as dependencies, in trade of the virtual filesystem dependency.

The other great benefit is the run-time efficiency when using a filesystem API because the files loading will be done from a single archive (for example a .zip) with its own security processes and simple commands, so the operating system heavy-weight operations for security checks will be avoided.

As an extra feature, the virtual filesystem can handle duplicate aliases for a file, so changing the extension or instead of modifying a file, adding another one entirely that substitutes it is easier to do. This allows the developer to introduce patches to the game without deleting the old files in a faster way; nevertheless, bigger patches may require to modify the old files to avoid long downloads for players.

# Market Study

# Selected Approach

# Possible Improvements

# Documentation and References
