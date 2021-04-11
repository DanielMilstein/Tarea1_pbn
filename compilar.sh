#!/bin/bash

echo "Estandar estricto? Y/else"
read ans

nombre="$1"

SUFF=c

nexe=${nombre%.$SUFF}

mkdir "bin"

if [ "$ans" = "y" ] || [ "$ans" = "Y" ]
then
	gcc -std=c99 -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self $nombre -o "bin/"$nexe	
else
	gcc $nombre -o "bin/"$nexe
fi
echo "Archivo compilado!"




