#include <gl/ErrorHandling.h>
#include "TriangleWidget.h"

static const char* vertexShaderSource =
        "#version 410\n"
                "in  vec2 posAttr;\n"
                "in  vec3 colAttr;\n"
                "out vec3 color;\n"
                "uniform mat4 matrix;\n"
                "void main() {\n"
                "   color = colAttr;\n"
                "   gl_Position = matrix * vec4(posAttr, 0.0, 1.0);\n"
                "}\n";

static const char* fragmentShaderSource =
        "#version 410\n"
                "in  vec3 color;\n"
                "out vec4 out_color;\n"
                "void main() {\n"
                "   out_color = vec4(color, 1.0);\n"
                "}\n";

static const GLfloat vertices[] = {
        0.0f, 0.707f,
        -0.5f, -0.5f,
        0.5f, -0.5f
};

static const GLfloat colors[] = {
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f
};

static GLuint VAOs[1] = {};
static GLuint VBOs[2] = {};

TriangleWidget::TriangleWidget(QWidget* parent)
        : QOpenGLWidget(parent)
        , m_posAttr(0)
        , m_colAttr(0)
        , m_matrixUniform(0)
        , m_refresh_rate(60.0)
        , m_frame(0)
{

}

void TriangleWidget::initializeGL()
{
    glClearColor(0.8f, 0.8f, 0.8f, 1.0f);

    m_program = new QOpenGLShaderProgram(this);
    m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    m_program->link();

    m_posAttr = (GLuint)m_program->attributeLocation("posAttr");
    m_colAttr = (GLuint)m_program->attributeLocation("colAttr");
    m_matrixUniform = (GLuint)m_program->uniformLocation("matrix");

    GL_CHECK( glGenBuffers(2, VBOs) );
    GL_CHECK( glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]) );
    GL_CHECK( glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW) );
    GL_CHECK( glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]) );
    GL_CHECK( glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW) );

    GL_CHECK( glGenVertexArrays(1, VAOs) );
    GL_CHECK( glBindVertexArray(VAOs[0]) );

    GL_CHECK( glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]) );
    GL_CHECK( glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, nullptr) );
    GL_CHECK( glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]) );
    GL_CHECK( glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, nullptr) );

    GL_CHECK( glEnableVertexAttribArray(0) );
    GL_CHECK( glEnableVertexAttribArray(1) );
}

void TriangleWidget::resizeGL(int w, int h)
{
    QOpenGLWidget::resizeGL(w, h);
}

void TriangleWidget::paintGL()
{
    const qreal retina_scale = devicePixelRatio();
    GL_CHECK( glViewport(0, 0, GLsizei(width() * retina_scale), GLsizei(height() * retina_scale)) );

    GL_CHECK( glClear(GL_COLOR_BUFFER_BIT) );

    m_program->bind();

    QMatrix4x4 matrix;
    matrix.perspective(60.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    matrix.translate(0.0f, 0.0f, -2.0f);

    matrix.rotate(100.0f * m_frame / float(m_refresh_rate), 0.0f, 1.0f, 0.0f);

    m_program->setUniformValue(m_matrixUniform, matrix);

    GL_CHECK( glBindVertexArray(VAOs[0]) );
    GL_CHECK( glDrawArrays(GL_TRIANGLES, 0, 3) );

    m_program->release();

    ++m_frame;

    update();
}

void TriangleWidget::setRefreshRate(qreal rate)
{
    m_refresh_rate = rate;
}
