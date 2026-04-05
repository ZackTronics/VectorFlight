#ifndef GL_1_HELICOPTER_H
#define GL_1_HELICOPTER_H

/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/
static inline void qSetColor(float colorVec[], QColor c)    {
    colorVec[0] = c.redF();
    colorVec[1] = c.greenF();
    colorVec[2] = c.blueF();
    colorVec[3] = c.alphaF();
    }

void Geometry::loadArrays() const   {
    glVertexPointer(3, GL_FLOAT, 0, vertices.constData());
    glNormalPointer(GL_FLOAT, 0, normals.constData());
}

void Geometry::finalize()   {
    // Finish smoothing normals by ensuring accumulated normals are returned
    // to length 1.0.
    for (int i = 0; i < normals.count(); ++i)
        normals[i].normalize();
    }

void Geometry::appendSmooth(const QVector3D &a, const QVector3D &n, int from)   {
    // Smooth normals are achieved by averaging the normals for faces meeting
    // at a point.  First find the point in geometry already generated
    // (working backwards, since most often the points shared are between faces
    // recently added).
    int v = vertices.count() - 1;
    for ( ; v >= from; --v)
        if (qFuzzyCompare(vertices[v], a))
            break;

    if (v < from) {
        // The vertex was not found so add it as a new one, and initialize
        // its corresponding normal
        v = vertices.count();
        vertices.append(a);
        normals.append(n);
    } else {
        // Vert found, accumulate normals into corresponding normal slot.
        // Must call finalize once finished accumulating normals
        normals[v] += n;
    }

    // In both cases (found or not) reference the vertex via its index
    faces.append(v);
}

void Geometry::appendFaceted(const QVector3D &a, const QVector3D &n)    {
    // Faceted normals are achieved by duplicating the vertex for every
    // normal, so that faces meeting at a vertex get a sharp edge.
    int v = vertices.count();
    vertices.append(a);
    normals.append(n);
    faces.append(v);
}

Patch::Patch(Geometry *g)
   : start(g->faces.count())
   , count(0)
   , initv(g->vertices.count())
   , sm(Patch::Smooth)
   , geom(g)
{
    qSetColor(faceColor, QColor(Qt::darkGray));
}

void Patch::rotate(qreal deg, QVector3D axis)   {
    mat.rotate(deg, axis);
}

void Patch::translate(const QVector3D &t)   {
    mat.translate(t);
}

void Patch::draw() const    {
    glPushMatrix();
    glMultMatrixf(mat.constData());
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, faceColor);

    const GLushort *indices = geom->faces.constData();
    glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_SHORT, indices + start);
    glPopMatrix();
}

void Patch::addTri(const QVector3D &a, const QVector3D &b, const QVector3D &c, const QVector3D &n)  {
    QVector3D norm = n.isNull() ? QVector3D::normal(a, b, c) : n;

    if (sm == Smooth) {
        geom->appendSmooth(a, norm, initv);
        geom->appendSmooth(b, norm, initv);
        geom->appendSmooth(c, norm, initv);
    } else {
        geom->appendFaceted(a, norm);
        geom->appendFaceted(b, norm);
        geom->appendFaceted(c, norm);
    }

    count += 3;
}

void Patch::addQuad(const QVector3D &a, const QVector3D &b,  const QVector3D &c, const QVector3D &d)    {
    QVector3D norm = QVector3D::normal(a, b, c);

    if (sm == Smooth) {
        addTri(a, b, c, norm);
        addTri(a, c, d, norm);
    } else {
        // If faceted share the two common vertices
        addTri(a, b, c, norm);
        int k = geom->vertices.count();
        geom->appendSmooth(a, norm, k);
        geom->appendSmooth(c, norm, k);
        geom->appendFaceted(d, norm);
        count += 3;
    }
}

static inline QVector<QVector3D> extrude(const QVector<QVector3D> &vertices, qreal depth)   {
    QVector<QVector3D> extr = vertices;
    for (int v = 0; v < extr.count(); ++v)
        extr[v].setZ(extr[v].z() - depth);
    return extr;
}



Rod::Rod(Geometry *g, qreal oRad, qreal length, int k)   {
    qreal iRad = 0;
    QVector<QVector3D> inside;
    QVector<QVector3D> outside;
    for (int i = 0; i < k; ++i) {
        qreal angle = (i * 2 * M_PI) / k;
        inside << QVector3D(iRad * qSin(angle), iRad * qCos(angle), length / 2.0);
        outside << QVector3D(oRad * qSin(angle), oRad * qCos(angle), length / 2.0);
        }
    inside  << QVector3D(0.0, iRad, 0.0);
    outside << QVector3D(0.0, oRad, 0.0);
    QVector<QVector3D> in_back  = extrude(inside, length);
    QVector<QVector3D> out_back = extrude(outside, length);

    Patch *front = new Patch(g);
    for (int i = 0; i < k; ++i)
        front->addQuad(outside[i], inside[i],
                       inside[(i + 1) % k], outside[(i + 1) % k]);
    Patch *back = new Patch(g);
    for (int i = 0; i < k; ++i)
        back->addQuad(in_back[i], out_back[i],
                      out_back[(i + 1) % k], in_back[(i + 1) % k]);
    Patch *os = new Patch(g);
    for (int i = 0; i < k; ++i)
        os->addQuad(out_back[(i + 1) % k], out_back[i],
                    outside[i], outside[(i + 1) % k]);
    parts << front << back << os;
    }

RectTorus::RectTorus(Geometry *g, qreal iRad, qreal oRad, qreal depth, int k)   {
    QVector<QVector3D> inside;
    QVector<QVector3D> outside;
    for (int i = 0; i < k; ++i) {
        qreal angle = (i * 2 * M_PI) / k;
        inside << QVector3D(iRad * qSin(angle), iRad * qCos(angle), depth / 2.0);
        outside << QVector3D(oRad * qSin(angle), oRad * qCos(angle), depth / 2.0);
        }
    inside << QVector3D(0.0, iRad, 0.0);
    outside << QVector3D(0.0, oRad, 0.0);
    QVector<QVector3D> in_back = extrude(inside, depth);
    QVector<QVector3D> out_back = extrude(outside, depth);
    // Create front, back and sides as separate patches so that smooth normals
    // are generated for the curving sides, but a faceted edge is created between
    // sides and front/back
    Patch *front = new Patch(g);
    for (int i = 0; i < k; ++i)
        front->addQuad(outside[i], inside[i],
                       inside[(i + 1) % k], outside[(i + 1) % k]);
    Patch *back = new Patch(g);
    for (int i = 0; i < k; ++i)
        back->addQuad(in_back[i], out_back[i],
                      out_back[(i + 1) % k], in_back[(i + 1) % k]);
    Patch *is = new Patch(g);
    for (int i = 0; i < k; ++i)
        is->addQuad(in_back[i], in_back[(i + 1) % k],
                    inside[(i + 1) % k], inside[i]);
    Patch *os = new Patch(g);
    for (int i = 0; i < k; ++i)
        os->addQuad(out_back[(i + 1) % k], out_back[i],
                    outside[i], outside[(i + 1) % k]);
    parts << front << back << is << os;
    }
RectPrism::RectPrism(Geometry *g, qreal width, qreal height, qreal depth)   {
    enum { bl, br, tr, tl };
    Patch *fb = new Patch(g);
    fb->setSmoothing(Patch::Faceted);
    // front face
    QVector<QVector3D> r(4);
    r[br].setX(width);
    r[tr].setX(width);
    r[tr].setY(height);
    r[tl].setY(height);
    QVector3D adjToCenter(-width / 2.0, -height / 2.0, depth / 2.0);
    for (int i = 0; i < 4; ++i)
        r[i] += adjToCenter;
    fb->addQuad(r[bl], r[br], r[tr], r[tl]);
    // back face
    QVector<QVector3D> s = extrude(r, depth);
    fb->addQuad(s[tl], s[tr], s[br], s[bl]);
    // side faces
    Patch *sides = new Patch(g);
    sides->setSmoothing(Patch::Faceted);
    sides->addQuad(s[bl], s[br], r[br], r[bl]);
    sides->addQuad(s[br], s[tr], r[tr], r[br]);
    sides->addQuad(s[tr], s[tl], r[tl], r[tr]);
    sides->addQuad(s[tl], s[bl], r[bl], r[tl]);
    parts << fb << sides;
    }

//heli_QObject::heli_QObject(QObject *parent)
heli_QObject::heli_QObject(QObject *parent, int divisions, qreal scale)
    : QObject(parent)
    , geom(new Geometry()){
    //int divisions = 64; qreal scale = 1.0;
    buildGeometry(divisions, scale);
    }
heli_QObject::~heli_QObject()   {
    qDeleteAll(parts);
    delete geom;
    }
void heli_QObject::setColor(QColor c) {
    for (int i = 0; i < parts.count(); ++i)
        qSetColor(parts[i]->faceColor, c);
    }

void heli_QObject::buildGeometry(int divisions, qreal scale)  {
    UNUSED(scale);
    //RectPrism stem1(geom, bt, th, ld);          //RectPrism(Geometry *g, qreal width, qreal height, qreal depth)   {
    float headRadius = 0.07;
    float baseRadius = 0.15;
    float stemRadius = 0.03;
    float stemLength = 0.5;
    float footLength = 0.1;

    Rod stem1(geom, stemRadius, stemLength, divisions);  //RectTorus(Geometry *g, qreal iRad, qreal oRad, qreal depth, int k)   {
    Rod stem2(geom, stemRadius, stemLength, divisions);  //RectTorus(Geometry *g, qreal iRad, qreal oRad, qreal depth, int k)   {
    Rod stem3(geom, stemRadius, stemLength, divisions);  //RectTorus(Geometry *g, qreal iRad, qreal oRad, qreal depth, int k)   {
    Rod stem4(geom, stemRadius, stemLength, divisions);  //RectTorus(Geometry *g, qreal iRad, qreal oRad, qreal depth, int k)   {
    Rod stem5(geom, stemRadius, stemLength, divisions);  //RectTorus(Geometry *g, qreal iRad, qreal oRad, qreal depth, int k)   {
    Rod stem6(geom, stemRadius, stemLength, divisions);  //RectTorus(Geometry *g, qreal iRad, qreal oRad, qreal depth, int k)   {
    Rod stem7(geom, stemRadius/3.0, stemLength, divisions);  //RectTorus(Geometry *g, qreal iRad, qreal oRad, qreal depth, int k)   {

    Rod foot1(geom, stemRadius, footLength, divisions);  //RectTorus(Geometry *g, qreal iRad, qreal oRad, qreal depth, int k)   {
    Rod foot2(geom, stemRadius, footLength, divisions);  //RectTorus(Geometry *g, qreal iRad, qreal oRad, qreal depth, int k)   {
    Rod foot3(geom, stemRadius, footLength, divisions);  //RectTorus(Geometry *g, qreal iRad, qreal oRad, qreal depth, int k)   {

    QVector3D x(1.0, 0.0, 0.0);
    QVector3D y(0.0, 1.0, 0.0);
    QVector3D z(0.0, 0.0, 1.0);

    stem1.rotate(90, y);
    stem2.rotate(90, y);
    stem3.rotate(90, y);
    stem4.rotate(90, y);
    stem5.rotate(90, y);
    stem6.rotate(90, y);
    stem7.rotate(90, y);

    stem1.rotate(0, x);
    stem2.rotate(60, x);
    stem3.rotate(120, x);
    stem4.rotate(180, x);
    stem5.rotate(240, x);
    stem6.rotate(300, x);
    stem7.rotate(270, x);

    stem1.translate(QVector3D(0.0, 0.0, baseRadius*2));
    stem2.translate(QVector3D(0.0, 0.0, baseRadius*2));
    stem3.translate(QVector3D(0.0, 0.0, baseRadius*2));
    stem4.translate(QVector3D(0.0, 0.0, baseRadius*2));
    stem5.translate(QVector3D(0.0, 0.0, baseRadius*2));
    stem6.translate(QVector3D(0.0, 0.0, baseRadius*2));
    stem7.translate(QVector3D(0.0, 0.0, baseRadius*2));
    foot1.translate(QVector3D(0.0, 0.12, -footLength/2));
    foot2.translate(QVector3D(-0.084, -0.084, -footLength/2));
    foot3.translate(QVector3D( 0.084, -0.084, -footLength/2));


 //   float toRads = 3.14159265358 / 180.0;

    RectTorus frontDisk(geom, 0, headRadius, 0.07, divisions);
     frontDisk.translate(QVector3D(0, stemLength,0.0 ));
   // frontDisk.translate(QVector3D(stemLength*cos(60.0*toRads), stemLength*sin(60.0*toRads),0.0 ));



    RectTorus body(geom, 0.05, baseRadius, 0.1, divisions);  //RectTorus(Geometry *g, qreal iRad, qreal oRad, qreal depth, int k)   {

    parts << body.parts << foot1.parts << foot2.parts << foot3.parts << stem1.parts << stem2.parts << stem3.parts << stem4.parts << stem5.parts << stem6.parts <<  stem7.parts << frontDisk.parts;
    geom->finalize();
    }

void heli_QObject::draw() const   {
    geom->loadArrays();

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);

    for (int i = 0; i < parts.count(); ++i)
        parts[i]->draw();

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
}

#endif // GL_1_HELICOPTER_H
