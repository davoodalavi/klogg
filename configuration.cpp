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

#include "configuration.h"

Configuration::Configuration()
{
}

Configuration& Config()
{
    static Configuration conf;
    return conf;
}

// Accessor functions
QFont Configuration::mainFont() const
{
    return mainFont_;
}

void Configuration::setMainFont( QFont newFont )
{
    mainFont_ = newFont;
}

void Configuration::readFromSettings( QSettings& settings )
{
    QString family = settings.value( "mainFont.family" ).toString();
    int size = settings.value( "mainFont.size" ).toInt();
    mainFont_ = QFont( family, size);
}

void Configuration::writeToSettings( QSettings& settings ) const
{
    settings.setValue( "mainFont.family", mainFont_.family() );
    settings.setValue( "mainFont.size", mainFont_.pointSize() );
}
