#!/bin/bash
read -p "Введите путь до файла лог " path
total=$(wc -l $path | awk '{print $1}' )
unique=$(cut -d ' ' -f 1 $path | sort -u | wc -l )
sha=$(cut -d ' ' -f 8 $path | sort -u | wc -l )
echo $total $unique $sha
