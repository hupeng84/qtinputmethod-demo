/**
 * Copyright 2019 Hu Peng
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QEvent>
#include <QInputMethodQueryEvent>
#include <QtDebug>

class InputEvent: public QObject
{
//   Q_OBJECT
public:
  bool eventFilter(QObject *obj, QEvent *event) {
    
    switch (event->type())
    {
      case QEvent::InputMethodQuery:
        {
            QInputMethodQueryEvent *query = static_cast<QInputMethodQueryEvent*>(event);
            // qWarning() << "InputMethodQuery: " << query->queries();
            Qt::InputMethodQueries queries = query->queries();
            for (uint i = 0; i < 32; ++i) {
                Qt::InputMethodQuery q = (Qt::InputMethodQuery)(int)(queries & (1<<i));
                if (q == Qt::ImEnabled) {
                    query->setValue(q, QVariant(true));
                }
            }
            query->accept();
        }
        break;
      case QEvent::InputMethod:
        {
            QInputMethodEvent *ime = static_cast<QInputMethodEvent*>(event);
            qWarning() << "commitString: " << ime->commitString() <<
             "  preeditString: " << ime->preeditString() << "  rlength: " << ime->replacementLength() << " rStart: " << ime->replacementStart();
        }
        break;
      case QEvent::KeyRelease:
        {
          QKeyEvent *ke = static_cast<QKeyEvent*>(event);
          qWarning() << "Release key: " << ke->key() << " text: " << ke->text() << " native vk: " << ke->nativeVirtualKey() << " modifiers: " << ke->modifiers();
        }
        break;
      default:

        return QObject::eventFilter(obj, event);
    }

    return true;
  }
};

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));
    // qputenv("QT_VIRTUALKEYBOARD_STYLE", QByteArray("retro"));
    // qputenv("QT_VIRTUALKEYBOARD_PINYIN_DICTIONARY", QByteArray("/home/hupeng/.config/qtvirtualkeyboard/pinyin/data"));
    QGuiApplication app(argc, argv);

    InputEvent* ie = new InputEvent;
    app.installEventFilter(ie);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
