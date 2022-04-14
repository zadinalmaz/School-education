#!/bin/bash
read -p "Введите путь к файлу " path
if [ -e $path ]
then
echo "Путь верный"
else
echo "Путь указан неверно"
exit $?
fi
read -p "Введите текст, который нужно заменить " oldtext
read -p "Введите измененный текст " newtext
if [[ $oldtext!="" && $newtext!="" ]]
then
echo "Текст существует"
else
echo "Текста не существует"
exit $?
fi
sed -i "" "s/$oldtext/$newtext/" $path
size=$(ls -l $path | awk '{print $5}' )
date=$(date -r $path +"%Y-%m-%d %H:%m")
sha=$(openssl sha256 $path | awk '{print $2}')
path2=$(git rev-parse --show-prefix)${path#./}
echo "$path2 - $size - $date - $sha - sha256" >> files.log
echo "Скрипт выполнен"
