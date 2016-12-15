#include <QPainter>
#include <QCoreApplication>
#include "OpenGLWindow.h"

OpenGLWindow::OpenGLWindow(QWindow* parent)
        : QWindow(parent)
        , m_inited(false)
        , m_update_pending(false)
        , m_animating(false)
        , m_context(nullptr)
{
    setSurfaceType(QWindow::OpenGLSurface);
}

void OpenGLWindow::initialize()
{
    QString gl_vendor   = QString((const char*)glGetString(GL_VENDOR));
    QString gl_renderer = QString((const char*)glGetString(GL_RENDERER));
    QString gl_version  = QString((const char*)glGetString(GL_VERSION));
}

void OpenGLWindow::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void OpenGLWindow::renderLater()
{
    if (!m_update_pending)
    {
        m_update_pending = true;
        QCoreApplication::postEvent(this, new QEvent(QEvent::UpdateRequest));
    }
}

bool OpenGLWindow::event(QEvent* event)
{
    switch (event->type())
    {
        case QEvent::UpdateRequest:
        {
            m_update_pending = false;
            renderNow();
            return true;
        }
        default:
        {
            return QWindow::event(event);
        }
    }
}

void OpenGLWindow::exposeEvent(QExposeEvent* event)
{
    Q_UNUSED(event);

    if (isExposed())
    {
        renderNow();
    }
}

void OpenGLWindow::renderNow()
{
    if (m_context == nullptr || !isExposed())
    {
        return;
    }

    m_context->makeCurrent(this);

    if (!m_inited)
    {
        initialize();
        m_inited = true;
    }

    render();

    m_context->swapBuffers(this);

    if (m_animating)
    {
        renderLater();
    }
}

void OpenGLWindow::setAnimating(bool animating)
{
    m_animating = animating;

    if (animating)
    {
        renderLater();
    }
}

void OpenGLWindow::setOpenGLContext(QOpenGLContext* context)
{
    m_context = context;
}



















