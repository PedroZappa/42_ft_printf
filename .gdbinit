define rfr
	refresh
end

define ft_printf
	display format
	display ap
	display str
	display p
end

define db_print_integer
	display n
	display numstr
	display count
	display p
	next
end

define db_print_i
	display n
	display nbrstr
	display count
	display p
	next
end

define db_print_f
	display n
	display nbr
	display nbrstr
	display count
	display p
	next
end

define db_parse
	display i
	display speclen
	display str
	display str[i]
	display *p
	next
end

define db_parse_arg
	display i
	display type
	display ap
	display *p
	next
end

define db_parse_prec
	display i
	display str
	display *p
	next
end

define db_print_str
	display str
	display count
	display p
end

define db_parse_flag
	break ft_parse_flag
	display i
	display str[i]
	display *p
	next
end

define db_print_arg
	display type
	display *p
	next
end

define db_print_hexa
	display n
	display nbrstr
	display count
	display *p
	next
end



## Start at main
fs cmd
break main
run

## Debug ft_print_di.c
# break ft_print_di
# run
# target record-full
# refresh
# display n
# display nbr
# display numstr
# display count
# display *p
# next

# Debug parse
# break ft_parse_bonus
# run
# refresh
# display i
# display speclen
# display str[i]
# display *p
# n

# Debug %s
# break ft_print_s
# run
# target record-full
# refresh
# display count
# display str
# display p
# next

# Debug print hex
# break ft_print_x
# break ft_print_hexa
# run
# target record-full
# refresh
# display n
# display count
# display nbrstr
# display p
# n
