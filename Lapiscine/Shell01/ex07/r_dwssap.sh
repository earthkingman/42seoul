cat /etc/passwd | grep -v '^#' | awk 'NR%2==0' | cut -d':' -f1 | rev | sort -r | head -n "$FT_LINE2" | tail -n "$(($FT_LINE2-$FT_LINE1+1))" |tr '\n' ','|sed 's/,/, /g'|sed 's/, $/./g'| tr -d '\n'
