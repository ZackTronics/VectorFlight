#include "objman.h"
#include <QFile>



ObjMan::ObjMan()
{
}

ObjMan::ObjMan(QString objFilePath, QString txtrFilePath, QGLWidget *parentGlWidget)
{
    vertBuffer = new QGLBuffer(QGLBuffer::VertexBuffer);
    normBuffer = new QGLBuffer(QGLBuffer::VertexBuffer);
    texCoordBuffer = new QGLBuffer(QGLBuffer::VertexBuffer);
    indBuffer = new QGLBuffer(QGLBuffer::IndexBuffer);

    ReaderObj(objFilePath);

    m_texture = -1;

    if ( !txtrFilePath.isNull() )
    {
        m_texture = parentGlWidget->bindTexture(QPixmap(txtrFilePath), GL_TEXTURE_2D);
    }
}

ObjMan::~ObjMan()
{
    vertBuffer->destroy();
    normBuffer->destroy();
    texCoordBuffer->destroy();
    indBuffer->destroy();

    //release()
    //ReleaseTexture
}


bool ObjMan::ReaderObj(QString objFilePath)
{
    QFile file(objFilePath);
    if ( !file.open(QIODevice::ReadOnly) )
    {
        return false;
    }

    std::vector<QVector3D>  tempNormals;
    std::vector<QVector2D>  tempCoords;
    std::vector<uint>       tempIndicies;

    QString line;
    while ( !file.atEnd() )
    {
        line = file.readLine();
        if ( line.isNull() )
            return false;



        if ( line[0] == 'v' )
        {
            if ( line[1] == 't' )
            {
                QVector2D tCoords;
                sscanf(line.toStdString().data(), "vt %f %f", &tCoords[0], &tCoords[1]);
                tempCoords.push_back(tCoords);
            }
            else if ( line[1] == 'n' )
            {
                QVector3D vNormal;
                sscanf(line.toStdString().data(), "vn %f %f %f", &vNormal[0], &vNormal[1], &vNormal[2]);
                tempNormals.push_back(vNormal);
            }
            else
            {
                QVector3D vertex;
                sscanf(line.toStdString().data(), "v %f %f %f", &vertex[0], &vertex[1], &vertex[2]);

                vertices.push_back(vertex);
            }
        }
        else if ( line[0] == 'f' )
        {
            GLuint indexs[9];
            sscanf(line.toStdString().data(), "f %d/%d/%d %d/%d/%d %d/%d/%d"
                    , &indexs[0], &indexs[1], &indexs[2]
                    , &indexs[3], &indexs[4], &indexs[5]
                    , &indexs[6], &indexs[7], &indexs[8]);
            for(int i = 0; i < 9; i++)
                tempIndicies.push_back(indexs[i]);
        }
    }

    vNormals.resize(vertices.size());
    texcoords.resize(vertices.size());
    indicies.resize(tempIndicies.size() / 3);

    for (unsigned int i = 0; i < tempIndicies.size() / 3; i++ )  //zsobin I changed i from int to unsigned int
    {
        indicies[i] = tempIndicies[i * 3 + 0] - 1;
        vNormals[indicies[i]] = tempNormals[tempIndicies[i * 3 + 2] - 1];
        texcoords[indicies[i]] = tempCoords[tempIndicies[i * 3 + 1] - 1];
    }

    if (vertices.size() > 0 && vertBuffer->create())
    {
        if ( vertBuffer->bind() )
        {
            vertBuffer->setUsagePattern(QGLBuffer::StaticDraw);
            vertBuffer->allocate(vertices.data(), sizeof(QVector3D) * vertices.size());
            vertBuffer->release();
        }
    }

    if (vNormals.size() > 0 && normBuffer->create())
    {
        if ( normBuffer->bind() )
        {
            normBuffer->setUsagePattern(QGLBuffer::StaticDraw);
            int szV = sizeof(QVector3D);
            normBuffer->allocate(vNormals.data(), szV * vNormals.size());
            normBuffer->release();
        }
    }

    if (texcoords.size() > 0 && texCoordBuffer->create())
    {
        if ( texCoordBuffer->bind() )
        {
            texCoordBuffer->setUsagePattern(QGLBuffer::StaticDraw);
            texCoordBuffer->allocate(texcoords.data(), sizeof(QVector2D) * texcoords.size());
            texCoordBuffer->release();
        }
    }

    if (indicies.size() > 0 && indBuffer->create())
    {
        if ( indBuffer->bind() )
        {
            indBuffer->setUsagePattern(QGLBuffer::StaticDraw);
            indBuffer->allocate(indicies.data(), sizeof(GLuint) * indicies.size());
            indBuffer->release();
        }
    }
    return true;
}

bool ObjMan::Draw(bool bCull)
{
    if ( !bCull )
    {

        glDisable(GL_LIGHTING);
       // glDisable(GL_NORMALIZE);
    }
    else
    {
        //glEnable(GL_CULL_FACE);
        glEnable(GL_LIGHTING);
       // glEnable(GL_NORMALIZE);
    }

     glDisable(GL_CULL_FACE);

    if ( (int)m_texture > 0 )
    {
        glEnable( GL_TEXTURE_2D );
        glBindTexture(GL_TEXTURE_2D, m_texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    }

    //if ( vertBuffer->size() > 0 )
    {
        glEnableClientState(GL_VERTEX_ARRAY);
        vertBuffer->bind();
        glVertexPointer(3, GL_FLOAT, 0, 0);
    }

   // if ( normBuffer->size() > 0 )
    {
        glEnableClientState(GL_NORMAL_ARRAY);
        normBuffer->bind();
        glNormalPointer(GL_FLOAT, 0, 0);
    }

   // if ( texCoordBuffer->size() > 0 )
    {
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        texCoordBuffer->bind();
        glTexCoordPointer(2, GL_FLOAT, 0, 0);
    }


    indBuffer->bind();


    glDrawElements(GL_TRIANGLES, indicies.size(), GL_UNSIGNED_INT, 0);

    if ( vertBuffer->size() > 0 )       glDisableClientState(GL_VERTEX_ARRAY);
    if ( normBuffer->size() > 0 )       glDisableClientState(GL_NORMAL_ARRAY);
    if ( texCoordBuffer->size() > 0 )   glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    return true;
}
