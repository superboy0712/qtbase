/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the plugins of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef WINDOWSPRINTERSUPPORT_H
#define WINDOWSPRINTERSUPPORT_H

#include <qpa/qplatformprintersupport.h>

QT_BEGIN_NAMESPACE

class QWin32PrintEngine;

class QWindowsPrinterSupport : public QPlatformPrinterSupport
{
public:
    QWindowsPrinterSupport();
    ~QWindowsPrinterSupport();

    virtual QPrintEngine *createNativePrintEngine(QPrinter::PrinterMode printerMode);
    virtual QPaintEngine *createPaintEngine(QPrintEngine *printEngine, QPrinter::PrinterMode);

    QPrintDevice createPrintDevice(const QString &id) Q_DECL_OVERRIDE;
    QStringList availablePrintDeviceIds() const Q_DECL_OVERRIDE;
    QString defaultPrintDeviceId() const Q_DECL_OVERRIDE;

    virtual QList<QPrinter::PaperSize> supportedPaperSizes(const QPrinterInfo &) const;
    virtual QList<QPair<QString, QSizeF> >supportedSizesWithNames(const QPrinterInfo &printerInfo) const;

    virtual QList<QPrinterInfo> availablePrinters();

private:
    static QList<QPrinterInfo> queryPrinters();
};

QT_END_NAMESPACE

#endif // WINDOWSPRINTERSUPPORT_H
