
#include "ViewWidget.h"

ViewWidget::ViewWidget(QWidget* parent)
        : QOpenGLWidget(parent)
{

}

void ViewWidget::SetDisplayPipeline(const std::shared_ptr<DisplayPipeline>& display_pipeline)
{
    m_dp = display_pipeline;
}

void ViewWidget::initializeGL()
{
    if(m_dp)
    {
        m_dp->Initialize();
    }
}

void ViewWidget::resizeGL(int w, int h)
{
    QOpenGLWidget::resizeGL(w, h);
}

void ViewWidget::paintGL()
{
    QOpenGLWidget::paintGL();
}
