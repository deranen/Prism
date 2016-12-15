#pragma once

#include <QOpenGLWidget>
#include "DisplayPipeline.h"

class ViewWidget : public QOpenGLWidget
{
    Q_OBJECT;
public:
    ViewWidget(QWidget* parent = nullptr);

    void SetDisplayPipeline(const std::shared_ptr<DisplayPipeline>& display_pipeline);

protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void resizeGL(int w, int h) Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;

private:
    std::shared_ptr<DisplayPipeline> m_dp;
};


