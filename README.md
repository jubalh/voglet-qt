voglet
======

voglet is a **vo**cabulary app**let**.
It's written in C++ using the Qt Framework.
So it runs on OSX, Linux and Windows.

Building
========
Clone it via `git clone https://github.com/jubalh/voglet-qt.git`

Open the `voglet-qt.pro` file with [Qt Creator](http://en.wikipedia.org/wiki/Qt_Creator) and build it.

If you don't want to use Qt Creator, you can use qmake:
`qmake -o Makefile voglet-qt.pro && make`

Configuration
=============
voglet needs the `config.xml` file to be in the same directory like voglet itself. Configuration can be done using that file.

Currently we can only configure two things. The location of the words file and the direction in which voglet will ask you the words.

With the following `config.xml`:
```
<?xml version="1.0" encoding="utf-8" ?>
<voglet>
    <file>file.xml</file>
    <direction>random</direction>
</voglet>
```

we would tell voglet to load the file `file.xml` in the current directory. And to ask us randomly. 
So if the `file.xml` contains the entry: la casa - the house, voglet will choose to ask you for your native word or the word in your target language.

The possibilities for `direction` are:
- `translation`, to show you the word in your mother tongue
- `word`, to show you the word in your target tongue
- `both`, erm..for showing you both, just one at a time.
