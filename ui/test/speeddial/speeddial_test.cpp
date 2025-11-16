/*
  Q Light Controller Plus - Test Unit
  speeddial_test.cpp

  Copyright (c) Massimo Callegari

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0.txt

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#include <QtTest>
#include <QCheckBox>

#define private public
#include "speeddial.h"
#undef private

#include "speeddial_test.h"

void SpeedDial_Test::initial()
{
    QWidget w;
    SpeedDial sd(&w);
    QCOMPARE(sd.parentWidget(), &w);
    QCOMPARE(sd.value(), 0);
    QVERIFY(sd.m_timer != nullptr);
    QVERIFY(sd.m_dial != nullptr);
    QVERIFY(sd.m_plus != nullptr);
    QVERIFY(sd.m_minus != nullptr);
    QVERIFY(sd.m_tap != nullptr);
    QVERIFY(sd.m_hrs != nullptr);
    QVERIFY(sd.m_min != nullptr);
    QVERIFY(sd.m_sec != nullptr);
    QVERIFY(sd.m_ms != nullptr);
    QVERIFY(sd.m_infiniteCheck != nullptr);
    QCOMPARE(sd.m_visibilityMask, SpeedDial::defaultVisibilityMask());
}

void SpeedDial_Test::setValue()
{
    SpeedDial sd(nullptr);
    sd.setValue(5000);
    QCOMPARE(sd.value(), 5000);
    sd.toggleInfinite();
    QVERIFY(sd.m_infiniteCheck->isChecked());
    sd.tap();
}

QTEST_MAIN(SpeedDial_Test)
