#!/bin/bash
#ls */src/ | xargs clang-format -i --style=file
#find */src/ -iname *.c -o -iname *.h | xargs clang-format -i --style=file
#find foo/bar/ -iname *.h -o -iname *.cpp | xargs clang-format -i
find . -regex '.*\.\(c\|h\)' -exec clang-format -style=file -i {} \;

