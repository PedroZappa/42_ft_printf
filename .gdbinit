set auto-load safe-path /

## Debug ft_print_di.c
# break ft_print_di
# run
# refresh
# display n
# display nbr
# display *numstr
# display count
# display p
# n

# Debug parse digits
break ft_parse_bonus
run
refresh
display i
display speclen
display str[i]
display *p
n

define db_parse_flag
	break ft_parse_flag
	display i
	display *str
	display *p
end

define db_widthprec
	display i
	display numlen
	display str[i]
	display *p
end
