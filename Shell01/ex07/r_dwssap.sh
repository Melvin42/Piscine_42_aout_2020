cat /etc/passwd | sed '/#/d' | sed -n 'n;p' | cut -d : -f1-1 | sort -rd | sed -n -e "$FT_LINE1, $FT_LINE2 p" | tr '\n' ", " | sed 's/,/, /g' | rev | cut -c2- | sed 's/,/./1' | rev | tr -d '\n'
