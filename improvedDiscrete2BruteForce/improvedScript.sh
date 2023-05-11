#!/bin/sh
pdfName="$1"
solutionFile="$2"

pdftotext "$solutionFile" pdfOutput.txt

./discreteScript < pdfOutput.txt > scriptWords.txt

#will loop until dictionary is fully read or output file was made
while IFS=$' \t\r\n' read -r word; do
  qpdf --password="$word" --decrypt "$pdfName" output.pdf > /dev/null 2>&1
  if [ -f output.pdf ]
  then
    echo word: "$word"
    break
  fi
done < scriptWords.txt
rm scriptWords.txt
rm pdfOutput.txt
