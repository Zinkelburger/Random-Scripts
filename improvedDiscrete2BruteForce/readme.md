# Explanation
Discrete 2 with James Propp involves him hiding a word in the solution to the previous homework. This word is the key to the next homework.

Instead of finding the word, it is more fun to make a script which brute forces the word. This script unlocks the homework basically instantly. 

## Usage
The first parameter is the pdf name you want to brute force, and the second is the solutions file.

`./improvedScript.sh  <PDF> <Last Week's Solutions>`

The terminal outputs the word, and there is an "output.pdf" saved to the directory with the unlocked pdf.

## Implementation
I rely on three properties of the secret word to get a fast solution
1. It is in the previous week's solution file
2. The word is innocuously placed in the middle of the sentence, meaning it will be fully lowercase
3. The word is a rare, strange word, so it only appears once in the text. It is possible that the word could appear more than once, when this solution fails. Although this assumption has been true for all of the words this semester, if the script ever fails, the older main file will work nearly as fast.

The third property is useful as I do not have to sort the map. I can simply scan for elements of frequency 1.

The bash script first converts the pdf to a txt file with pdftotext. Converting a pdf to text produces a lot of garbage characters, but this doesn't matter as I am only checking for fully lowercase strings.

The C++ program keeps track of the frequency of all the fully lowercase strings. These strings are stored in an unordered_map so I can quickly increment their frequency.

After the file is done reading, I can scan for elements of frequency 1.

qpdf is then used to decrypt the PDF with the frequency 1 characters. The program knows it succeeded if the output.pdf file was created successfully , when it prints the word to the screen and ends the loop.
At the time I did not know that echo $? could be used to check the success/failure of a command, and if I did it again, that way is probably faster than checking for the existence of a file.

I'm not sure why I saved to files instead of piping, but the class is over and I don't feel the need to change it.

If there is a faster way to break Propp's homework unlock passwords, let me know!
