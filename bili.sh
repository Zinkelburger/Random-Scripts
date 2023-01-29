#!/bin/bash
read -p "Bili bili url to be iterated through: " url
read -p "Highest url number to be put in: " highNum
read -p "Lowest url number to be put in (lowest should be 1): " lowNum
for ((num = $lowNum; num<= $highNum; num++))
do
	lux "${url}?p=${num}"
done
