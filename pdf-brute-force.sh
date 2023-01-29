#!/bin/bash
#will loop until dictionary is fully read or output file was made
while IFS=$' \t\r\n' read -r word; do
  qpdf --password="$word" --decrypt P1.pdf output.pdf &>/dev/null 
  if [ -f output.pdf ]
  then 
	  echo word: "$word"
	  break
  fi
done < words_alpha.txt 
