Diomidis Spinellis's BASIC interpreter
======================================

Diomidis Spinellis, author of "Code Reading", "Code Quality",
"Beautiful Architecture", "The Elements of Computing Style",
"Effective Debugging", once wrote a BASIC interpreter in C.

This is a beautified version of that BASIC interpreter.

To build and run the tests test, run:

```bash
make
```

To give ideas of what you can do with the BASIC interpreter, you might do
something like this:

``` bash
make dds
./dds
Ok
10 FOR X=1 TO 3
Ok
20 PRINT "HELLO WORLD"
Ok
30 NEXT X
Ok
LIST
10 FOR X=1 TO 3
20 PRINT "HELLO WORLD"
30 NEXT X
Ok
RUN
HELLO WORLD
HELLO WORLD
HELLO WORLD
Ok
BYE
```

The tests are based on expect, which is written in Tcl. Essentially, the
tests test the interpreter's functionality by playing LANDER.BAS, and then
comparing the transcript of the playthrough to a golden transcript.

Notes from the author:

Immediate commands:
-------------------

*   NEW
*   LIST
*   OLD filename
*   RUN
*   SAVE filename
*   BYE

Program statements:
-------------------

*   var = exp
*   INPUT variable
*   PRINT string
*   PRINT exp
*   GOTO exp
*   IF exp THEN exp
*   FOR var = exp TO exp
*   NEXT variable
*   GOSUB exp
*   RETURN
*   REM any text
*   END

Expressions (ranked by precedence):
-----------------------------------

*   Bracketed expressions
*   number (leading 0 for octal, 0x for hex, else decimal),
*   variable
*   Unary -
*   * /
*   + -
*   = <>
*   > <
*   <= >=
*   (* and + are also used for boolean AND and boolean OR)
*   (Boolean expressions evaluate to 0 for false and 1 for true)

Variables:
----------

*   variable names a to z
*   variables initialized to 0 on RUN

Editing:
--------

* Line editor using line re-entry.
* A line number with nothing following it, deletes the line.
* Line number range     1-10000

Input format:
-------------

* ALL INPUT MUST BE UPPERCASE.
* No space is allowed before the line number.
* Exactly one space is needed between the OLD or SAVE command and the filename.

No error checking is performed.
