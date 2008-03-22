TEMPLATE = app
TARGET = ds_gen
QT += core \
    gui
INCLUDEPATH += ./muParser/

# muParser headers
HEADERS += ./muParser/muParserBase.h \
           ./muParser/muParserBytecode.h \
           ./muParser/muParserCallback.h \
           ./muParser/muParserDef.h \
           ./muParser/muParserError.h \
           ./muParser/muParserFixes.h \
           ./muParser/muParser.h \
	   ./muParser/muParserInt.h \
	   ./muParser/muParserStack.h \
	   ./muParser/muParserToken.h \
	   ./muParser/muParserTokenReader.h

HEADERS += zchart.h \
    zframes.h \
    parser.h \
    ds_gen.h

# muParsers sources
SOURCES += ./muParser/muParserBase.cpp \
           ./muParser/muParserBytecode.cpp \
	   ./muParser/muParserCallback.cpp \
	   ./muParser/muParser.cpp \
	   ./muParser/muParserError.cpp \
	   ./muParser/muParserInt.cpp \
	   ./muParser/muParserTokenReader.cpp

SOURCES += main.cpp \
    zchart.cpp \
    zframes.cpp \
    parser.cpp \
    ds_gen.cpp
FORMS += ds_gen.ui
RESOURCES += 

QMAKE_CXXFLAGS += -O3

QMAKE_LIBS += -lmgl

