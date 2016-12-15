#pragma once

#include <QWindow>
#include <QOpenGLFunctions>
#include <QOpenGLPaintDevice>
#include <memory>

using namespace std;

class OpenGLWindow : public QWindow
{
    Q_OBJECT;
public:
    explicit OpenGLWindow(QWindow* parent = nullptr);

    virtual void render();
    virtual void initialize();

    void setOpenGLContext(QOpenGLContext* context);
    void setAnimating(bool animating);

public slots:
    void renderLater();
    void renderNow();

protected:
    bool event(QEvent* event) Q_DECL_OVERRIDE;

    void exposeEvent(QExposeEvent* event) Q_DECL_OVERRIDE;

private:
    bool m_inited;
    bool m_update_pending;
    bool m_animating;

    QOpenGLContext* m_context;
};
