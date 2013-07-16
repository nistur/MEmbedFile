#include "MEmbedFileManager.h"
#include "MFileTools.h"
#include "MEmbedFileRef.h"

MEmbedFileManager* MEmbedFileManager::s_instance = NULL;

MEmbedFileManager::MEmbedFileManager()
{
	m_standardFileOpenHook = M_getFileOpenHook();
	M_registerFileOpenHook(this);

	s_instance = this;
}

MEmbedFileManager::~MEmbedFileManager()
{
	M_registerFileOpenHook(m_standardFileOpenHook);
}

MFile* MEmbedFileManager::open(const char * path, const char * mode)
{
	MFile* rtn = NULL;
	if(m_standardFileOpenHook)
		rtn = m_standardFileOpenHook->open(path, mode);
	if(rtn) return rtn;

	MEngine* engine = MEngine::getInstance();
	MSystemContext * system = engine->getSystemContext();
	
	char localFilename[256];
	getLocalFilename(localFilename, system->getWorkingDirectory(), path);
	
	filesIter iFile = m_files.find(localFilename);
	if(iFile != m_files.end())
	{
		if(MEmbedFileRef* ref = iFile->second->getRef())
		{
			ref->open(localFilename, mode);
			return ref;
		}
	}
	return NULL;
}

void MEmbedFileManager::add(MEmbedFile* file, const char* filename)
{
	if(s_instance == NULL) return;
	s_instance->m_files[filename] = file;
}

void MEmbedFileManager::remove(MEmbedFile* file, const char* filename)
{
	if(s_instance == NULL) return;
	filesIter iFile = s_instance->m_files.find(filename);
	if(iFile != s_instance->m_files.end() && iFile->second == file)
		s_instance->m_files.erase(iFile);
}