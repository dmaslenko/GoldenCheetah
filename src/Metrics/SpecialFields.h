/*
 * Copyright (c) 2010 Mark Liversedge (liversedge@gmail.com)
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc., 51
 * Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _GC_SpecialFields_h
#define _GC_SpecialFields_h
#include "GoldenCheetah.h"

class QStringListModel;
class RideMetric;

class SpecialFields
{
    Q_DECLARE_TR_FUNCTIONS(SpecialFields)

    public:

        // Singleton pattern
        static SpecialFields& getInstance() {
            static SpecialFields instance;
            return instance;
        }
        SpecialFields(SpecialFields const&) = delete;
        void operator=(SpecialFields const&) = delete;

        void reloadFields();

        bool isUser(const QString&) const;                  // is this a real user defined field?
        bool isSpecial(const QString&) const;               // is this a special field name?
        bool isMetric(const QString&) const;                // is this a metric override?

        QString makeTechName(const QString&) const;         // return a SQL friendly name
        QString metricSymbol(const QString&) const;         // return symbol for user friendly name
        const RideMetric *rideMetric(const QString&) const; // return metric ptr for user friendly name
        QString displayName(const QString&) const;          // return display (localized) name for name
        QString internalName(const QString&) const;         // return internal (english) Name for display

    private:
        SpecialFields();

        QMap<QString, QString> namesmap; // Map Internal (english) name to external (Localized) name
        QSet<QString> specialset; // Internal names of special fields
        QMap<QString, const RideMetric *> metricmap;
};

class SpecialTabs
{
    Q_DECLARE_TR_FUNCTIONS(SpecialTabs)

    public:
        // Singleton pattern
        static SpecialTabs& getInstance() {
            static SpecialTabs instance;
            return instance;
        }
        SpecialTabs(SpecialTabs const&) = delete;
        void operator=(SpecialTabs const&) = delete;

        QString displayName(const QString&) const;       // return display (localized)
        QString internalName(const QString&) const;      // return internal (english)

    private:
        SpecialTabs();

        QMap<QString, QString> namesmap; // Map Internal (english) name to external (Localized) name
};

#endif
