This program will read an input file which will have a series of words using the English Alphabet characters a-z, A-Z. These words will be space delimited with no punctuation. Sentences will terminate with a newline.
Syntax: <exe> <input file> <-mc|-e> <output file>
Sample translate to morse code: ./morse message_orig.txt -mc message.mc 
Sample translate to English: ./morse message.mc -e message.txt
For english to morse if a character is passed in other than a-f, A-F or space; return “eeee”
For morse to english if the pattern “eeee” is passed in the function should return a # symbol.

Sample Output:
Example Input File #1:
     abc def ghi
     abc def ghi
     abc def ghi
     abc def ghi
     abc def ghi
To Morse Command: 
morse test.txt -mc testMC.mc
Output File:
     .-|-...|-.-.|/|-..|.|..-.|/|--.|....|..
     .-|-...|-.-.|/|-..|.|..-.|/|--.|....|..
     .-|-...|-.-.|/|-..|.|..-.|/|--.|....|..
     .-|-...|-.-.|/|-..|.|..-.|/|--.|....|..
     .-|-...|-.-.|/|-..|.|..-.|/|--.|....|..
To English Command:
morse testMC.mc -e testENG.txt
Output File:
     ABC DEF GHI
     ABC DEF GHI
     ABC DEF GHI
     ABC DEF GHI
     ABC DEF GHI
Example Input File #2:
     abc def 123
     abc def ghi
     abc def ghi
To Morse Command:
morse bad.txt -mc badMC.mc
Output File:
     .-|-...|-.-.|/|-..|.|..-.|/|eeee|eeee|eeee
     .-|-...|-.-.|/|-..|.|..-.|/|--.|....|..
     .-|-...|-.-.|/|-..|.|..-.|/|--.|....|..
     .-|-...|-.-.|/|-..|.|..-.|/|--.|....|..
     .-|-...|-.-.|/|-..|.|..-.|/|--.|....|..
To English Command:
morse badMC.mc -e badENG.txt
Output File:
     ABC DEF ###
     ABC DEF GHI
     ABC DEF GHI
