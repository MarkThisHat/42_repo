#!/bin/sh

cat /etc/passwd | grep -v '^#' | sed -n 'n;p' | cut -f1 -d":" | rev | sort -r | sed -n "$FT_LINE1, $FT_LINE2 p" | xargs | sed 's/ /, /g' | sed 's/$/./'
