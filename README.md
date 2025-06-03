# CashTracker

**CashTracker** — приложение для учёта и анализа финансовых операций.  
Графический интерфейс реализован на C++ с использованием библиотеки Qt.  
Логика обработки данных, включая интеграцию с API валютных курсов, реализована на Python.  
Взаимодействие между модулями осуществляется через файловую буферизацию.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE.txt)
[![Build](https://img.shields.io/badge/build-passing-brightgreen)](#)

---

## 📸 Скриншоты

<p align="center">
  <img src="screenshots/main_window.png" width="500" alt="Главное окно">
  <br>
  <em>Главное окно приложения</em>
</p>

---

## 📁 Структура проекта

```
CashTracker/
├── app/                  # C++/Qt часть (GUI)
├── backend/              # Python-обработка данных
├── buffer/               # Буфер обмена между C++ и Python
├── logs/                 # Файлы логирования
├── run_backend.sh        # Скрипт запуска бэкенда
├── requirements.txt      # Зависимости Python
└── README.md
```

---

## 🚀 Быстрый старт

### Клонирование репозитория

```bash
git clone https://github.com/DanilaEfimov/CashTracker.git
cd CashTracker
```

### Установка зависимостей Python

```bash
pip install -r requirements.txt
```

> Убедитесь, что вы используете виртуальное окружение (`venv`), если это предусмотрено.

---

## ⚙️ Запуск

### Бэкенд (Python)

#### Linux / macOS
```bash
./run_backend.sh
```

#### Windows
```cmd
run_backend.bat
```

> Требуется переменная окружения `FIXER_API_KEY`, содержащая ваш API-ключ (можно указать через `.env`).

Пример `.env`:

```env
FIXER_API_KEY=ваш_ключ
```

---

### Qt-приложение (C++)

1. Откройте `app/app.pro` в Qt Creator.
2. Убедитесь, что используется C++17:
   ```pro
   CONFIG += c++17
   ```
3. Соберите проект (`qmake` → `make`)
4. Запустите исполняемый файл

---

## 🔄 Взаимодействие модулей

1. Qt сохраняет данные в `buffer/args.txt`
2. Вызывает Python-бэкенд
3. Python обрабатывает данные, сохраняет ответ в `buffer/response.txt`
4. Qt читает результат и отображает его
5. Логи → `logs/backend.log`

---

## 🌐 Работа с API Fixer.io

Приложение получает курсы валют через [Fixer.io](https://fixer.io) (требуется API-ключ).  
Бесплатный тариф ограничен базовой валютой `EUR`.

Пример запроса:

```
https://data.fixer.io/api/latest?access_key=YOUR_KEY&symbols=USD,GBP
```

---

## 🛠️ Отладка

* Все ошибки записываются в `logs/backend.log`
* Если бэкенд не запускается — проверьте:
  - Наличие Python 3.6+
  - Установлены зависимости из `requirements.txt`
  - Установлена переменная `FIXER_API_KEY`

---

## 🧠 Часто задаваемые вопросы

> **Q**: Почему CSV-файл открывается как один столбец в Excel?  
> **A**: Используйте точку с запятой (`;`) как разделитель для русской локали, или импортируйте вручную через Excel → Файл → Открыть → Указать `,` как разделитель.

---

## ❓ Есть вопросы?

Открывайте [issue на GitHub](https://github.com/DanilaEfimov/CashTracker/issues), я стараюсь оперативно отвечать.

---

## 📄 Лицензия

Проект распространяется под лицензией MIT.  
Полный текст — в [LICENSE.txt](LICENSE.txt)

---

## 👤 Автор

**Danila Efimov**  
— Архитектура, Qt-интерфейс, Python-бэкенд, взаимодействие между языками.
