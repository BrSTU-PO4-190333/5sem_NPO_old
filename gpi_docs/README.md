## Скомпилировать PDF

```bash
docker-compose up
```

## Как переименовать в PDF на своё fio

### Таблицы и текст

НЕ МЕНЯТЬ в этом проекте все файлы `gpi*_` на своё `fio*_`,
так как все настройки находятся в файле [env.sty](env.sty).

То есть в файле `env.sty` меняем следующее

```latex
%\def \gpiFIO{gpi}      % это
\def \gpiFIO{fio}       % поменяли на свою fio
```

```latex
%\def \gpiFIObig{GPI}   % это
\def \gpiFIObig{FIO}    % поменяли на своё FIO
```

### Картинки

Для картинок я не сделал такие магические две переменные, поэтому картинки нужно будет сохранить под моим названием.

Либо менять в коде их подключение.

```latex
\begin{figure}[!htb]
    \centering
    \includegraphics[height=19cm]
        {_assets/gpia_part2.png}                        % Тут на свой path
    \caption{Функциональная схема обработки данных}
\end{figure}
```
