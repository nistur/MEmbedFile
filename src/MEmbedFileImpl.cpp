#include "MEmbedFileImpl.h"
#include "MEmbedFileManager.h"

#include "MEmbedFileRef.h"

MEmbedFileImpl::~MEmbedFileImpl()
{
	MEmbedFileManager::remove(this, m_filename.c_str());
}

void MEmbedFileImpl::set(const char* name, const char* data, int size)
{
	m_filename = name;
	m_data = data;
	m_size = size;

	MEmbedFileManager::add(this, name);
}

MEmbedFileRef* MEmbedFileImpl::getRef()
{
	return new MEmbedFileRef(m_filename.c_str(), m_data, m_size);
}

void MEmbedFileImpl::destroy()
{
	delete this;
}

MResource* MEmbedFileImpl::getNew()
{
	return new MEmbedFileImpl();
}