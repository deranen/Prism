#pragma once

#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>

class TriangleWidget : public QOpenGLWidget
{
    Q_OBJECT;
public:
    TriangleWidget(QWidget* parent = nullptr);

    void setRefreshRate(qreal rate);

protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void resizeGL(int w, int h) Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;

private:
    GLuint m_posAttr;
    GLuint m_colAttr;
    GLuint m_matrixUniform;

    qreal m_refresh_rate;

    QOpenGLShaderProgram* m_program;
    int m_frame;
};


