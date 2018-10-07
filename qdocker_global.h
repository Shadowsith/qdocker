#ifndef QDOCKER_GLOBAL_H
#define QDOCKER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QDOCKER_LIBRARY)
#  define QDOCKERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QDOCKERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QDOCKER_GLOBAL_H
