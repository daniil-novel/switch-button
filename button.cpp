#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

class SwitchButton : public QWidget {
    Q_OBJECT

public:
    SwitchButton(QWidget *parent = nullptr) : QWidget(parent), isOn(false) {
        setFixedSize(60, 30);
        setStyleSheet("background-color: #DDDDDD;");
    }

protected:
    void paintEvent(QPaintEvent *event) override {
        Q_UNUSED(event);

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);

        // Background
        painter.setBrush(QColor(200, 200, 200));
        painter.drawRoundedRect(rect(), 15, 15);

        // Switch
        painter.setBrush(QColor(255, 255, 255));
        if (isOn) {
            painter.drawEllipse(width() - 35, 5, 20, 20);
        } else {
            painter.drawEllipse(5, 5, 20, 20);
        }
    }

    void mousePressEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            isOn = !isOn;
            update();  // Redraw
            emit stateChanged(isOn);
        }
    }

signals:
    void stateChanged(bool newState);

private:
    bool isOn;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Custom Switch Button Example");

    QVBoxLayout *layout = new QVBoxLayout(&window);

    SwitchButton *switchButton = new SwitchButton;
    QObject::connect(switchButton, &SwitchButton::stateChanged, [&](bool state) {
        qDebug() << "Switch button is" << (state ? "ON" : "OFF");
    });

    layout->addWidget(switchButton);

    window.show();

    return app.exec();
}

#include "main.moc"
