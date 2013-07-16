#include "MEmbedFilePlugin.h"
#include "MEmbedFileImpl.h"
#include "MEmbedFileManager.h"

MEmbedFileManager s_embedFileManager;
void MPluginStart(MEmbedFile)
{
    MResource::registerFactory("MEmbedFile", MEmbedFileImpl::getNew);
}

void MPluginEnd(MEmbedFile)
{
    MResource::unregisterFactory("MEmbedFile", MEmbedFileImpl::getNew);
}