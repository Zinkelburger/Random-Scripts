#!/bin/sh
echo What Discrete 2 file do you want to brute force?
read pdfName
# Check if the input file exists
if [ ! -f "$pdfName" ]; then
  echo "Error: $pdfName not found"
  exit 1
fi

echo What is the solutions file to find the word from?
read solutionFile
# Check if the input file exists
if [ ! -f "$solutionFile" ]; then
  echo "Error: $solutionFile not found"
  exit 1
fi

#convert pdf to text so it can be parsed by c++
pdftotext "$solutionFile" pdfOutput.txt

./discreteScript < pdfOutput.txt > scriptWords.txt

#will loop until scriptWords is fully read or the output file was made
while IFS=$' \t\r\n' read -r word; do
qpdf --password="$word" --decrypt "$pdfName" output.pdf &>/dev/null
  if [ -f output.pdf ]
  then
    echo word: "$word"
    break
  fi
done < scriptWords.txt
rm scriptWords.txt
rm pdfOutput.txt


