#ifndef OBJMAN_H
#define OBJMAN_H

#include <QString>

#include <QGLFunctions>
#include <QGLBuffer>
#include <QVector3D>
#include <QVector2D>
#include <vector>

class ObjMan : protected QGLFunctions
{
public:
    ObjMan();
    ObjMan(QString objFilePath, QString txtrFilePath = NULL, QGLWidget *parentGlWidget = NULL);

    ~ObjMan();

    bool Draw(bool bCull);
private:
    bool ReaderObj(QString objFilePath);

private:
    QGLBuffer *vertBuffer;
    QGLBuffer *normBuffer;
    QGLBuffer *texCoordBuffer;
    QGLBuffer *indBuffer;

    std::vector<QVector3D>   vertices;
    std::vector<QVector3D>   vNormals;
    std::vector<QVector2D>   texcoords;
    std::vector<GLuint>      indicies;

    GLuint m_texture;
};

#endif // OBJMAN_H
