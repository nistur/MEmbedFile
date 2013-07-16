#include "MEmbedFileRef.h"

MEmbedFileRef::MEmbedFileRef(const char* filename, const char* data, int size)
: m_open(false)
, m_filename(filename)
, m_data(data)
, m_size(size)
, m_ptr(data)
{
}

void MEmbedFileRef::open(const char * path, const char * mode)
{
	if(strstr(mode, "w") != NULL)
		return;
	m_open = true;
}

int MEmbedFileRef::close()
{
	m_open = true;
	return 0;
}

size_t MEmbedFileRef::read(void * dest, size_t size, size_t count)
{
	long remaining = m_size - tell();
	size_t tocopy = remaining < count ? remaining : count;
	memcpy(dest, m_ptr, tocopy);
	m_ptr += tocopy;

	return tocopy;
}

int MEmbedFileRef::seek(long offset, int whence)
{
	switch(whence)
	{
	case SEEK_SET:
		m_ptr = m_data + offset;
		break;
	case SEEK_CUR:
		m_ptr += offset;
		if(m_ptr > m_data + m_size)
			m_ptr = m_data + m_size;
		break;
	case SEEK_END:
		m_ptr = m_data + m_size;
		break;
	}

	return m_ptr - m_data;
}

long MEmbedFileRef::tell()
{
	return m_ptr - m_data;
}

void MEmbedFileRef::rewind()
{
	m_ptr = m_data;
}

bool MEmbedFileRef::isOpen()
{
	return m_open;
}

void MEmbedFileRef::destroy()
{
	delete this;
}
