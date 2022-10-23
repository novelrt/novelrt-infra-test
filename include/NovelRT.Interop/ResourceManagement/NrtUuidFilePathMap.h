// Copyright © Matt Jones and Contributors. Licensed under the MIT Licence (MIT). See LICENCE.md in the repository root
// for more information.

#ifndef NOVELRT_INTEROP_RESOURCEMANAGEMENT_UUIDFILEPATHMAP_H
#define NOVELRT_INTEROP_RESOURCEMANAGEMENT_UUIDFILEPATHMAP_H

#include "../NrtTypedefs.h"

#ifdef __cplusplus
extern "C"
{
#endif

    NrtResult Nrt_UuidFilePathMap_Indexer(NrtUuidFilePathMapHandle map, NrtUuid id, const char** outFilePath);

#ifdef __cplusplus
}
#endif

#endif // NOVELRT_INTEROP_RESOURCEMANAGEMENT_UUIDFILEPATHMAP_H
