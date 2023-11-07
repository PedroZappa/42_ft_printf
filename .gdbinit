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
# break ft_parse_bonus
# run
# refresh
# display i
# display speclen
# display str[i]
# display *p
# n

# Debug print hex
# break ft_print_x
# run
# refresh
# display n
# display count
# display nbrstr
# display *p
# n

# Debug %s
break ft_print_s
run
# target record
refresh
display count
display *str
display p
n

define db_parse
	display i
	display speclen
	display str[i]
	display *p
	next
end

define db_parse_flag
	break ft_parse_flag
	display i
	display *str
	display *p
	next
end

define db_print_arg
	display type
	display *p
	next
end

define db_widthprec
	display i
	display numlen
	display str[i]
	display *p
	next
end

define db_print_hexa
	display n
	display nbrstr
	display count
	display p
end

