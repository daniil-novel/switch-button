# Switch Button на плюсах и qt

## Описание

Моя реализация включает в себя создание собственного класса `SwitchButton`, который наследуется от `QWidget`. Этот класс реагирует на события отрисовки и нажатия мыши для визуализации и изменения состояния кнопки.

## Как это работает

### SwitchButton

**Основные свойства:**
- `isOn`: Булева переменная, отслеживающая текущее состояние кнопки (вкл./выкл.).

**Методы:**
- `paintEvent`: Обрабатывает событие отрисовки, рисуя фон и кнопку (в зависимости от текущего состояния)
- `mousePressEvent`: Обрабатывает событие нажатия мыши. При ЛКМ изменяет состояние кнопки, обновляет отображение и отправляет сигнал `stateChanged`.

### Main

**Создание объекта `SwitchButton`:**
- Создается экземпляр класса `SwitchButton`.
- Устанавливается соединение (connection) между сигналом `stateChanged` и лямбда-функцией, выводящей сообщение о текущем состоянии кнопки в консольку.

**Отображение окна:**
- Создается главное окно (`QWidget`).
- Устанавливается вертикальный лейаут, включающий в себя `SwitchButton`.
- Отображается окно.

## Как использовать

1. Скачайте и установите библиотеку Qt.
2. Запустите программу.
3. Кликните левой кнопкой мыши на пользовательской кнопке-переключателе, чтобы изменить ее состояние.
4. В консоли будет выводиться сообщение о текущем состоянии кнопки (ON/OFF).
5. Наслаждадйтесь процессом
