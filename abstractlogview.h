/*
 * Copyright (C) 2009 Nicolas Bonnefon and other contributors
 *
 * This file is part of LogCrawler.
 *
 * LogCrawler is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * LogCrawler is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with LogCrawler.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ABSTRACTLOGVIEW_H
#define ABSTRACTLOGVIEW_H

#include <QAbstractScrollArea>

#include "abstractlogdata.h"

// Base class representing the log view widget.
// It can be either the top (full) or bottom (filtered) view.
class AbstractLogView : public QAbstractScrollArea
{
  Q_OBJECT

  public:
    AbstractLogView(const AbstractLogData* newLogData, QWidget *parent=0);

    // Makes the widget use the new data set passed,
    // reconfigure itself and then redraw itself.
    // The called retains ownership of the data set.
    void updateData(const AbstractLogData* newLogData);

  protected:
    void mousePressEvent(QMouseEvent* mouseEvent);
    void paintEvent(QPaintEvent* paintEvent);
    void resizeEvent(QResizeEvent* resizeEvent);
    void scrollContentsBy(int dx, int dy);

  signals:
    // Sent when a new line has been selected by the user.
    void newSelection(int line);

  public slots:
    // Makes the widget adjust itself to display the passed line.
    // Doing so, it will throw itself a scrollContents event.
    void displayLine(int line);

  private:
    const AbstractLogData* logData;
    int firstLine;
    int lastLine;
    int firstCol;
    // Line number currently selected, or -1 if none selected
    int selectedLine;

    int getNbVisibleLines() const;
    int getNbVisibleCols() const;
    int convertCoordToLine(int yPos) const;
};

#endif
