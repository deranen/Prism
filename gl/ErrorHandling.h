#ifndef PRISM_ERRORHANDLING_H
#define PRISM_ERRORHANDLING_H

#include <gl.h>
#include <QDebug>

const char* GLErrorToString(GLenum error);

#define GL_CHECK(x) \
    x; \
    { \
        GLenum error; \
        while((error = glGetError()) != GL_NO_ERROR) \
        { \
            QString msg = QString("OpenGL error: %1 in function \"%2\" (Line %3)\nFile: %4\n") \
                                .arg(GLErrorToString(error), __func__, QString::number(__LINE__), __FILE__); \
            qDebug() << msg; \
        } \
    }

#endif //PRISM_ERRORHANDLING_H
