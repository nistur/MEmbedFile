#include "MEmbedFilePlugin.h"
#include "MEmbedFileImpl.h"

void MPluginStart(MEmbedFile)
{
    MResource::registerFactory("MEmbedFile", MEmbedFileImpl::getNew);
}

void MPluginEnd(MEmbedFile)
{
    MResource::unregisterFactory("MEmbedFile", MEmbedFileImpl::getNew);
}