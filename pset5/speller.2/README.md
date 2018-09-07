# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

TODO

## According to its man page, what does `getrusage` do?

TODO

## Per that same man page, how many members are in a variable of type `struct rusage`?

TODO

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

TODO

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

TODO

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

TODO

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

TODO
What is pneumonoultramicroscopicsilicovolcanoconiosis?
Lung disease caused by inhaling fine volcanic ash. Maximum length for a word.

According to its man page, what does getrusage do?
getrusage reports resource usage for either 1.all threads 2.children of all threads 3. the calling thread.

Per that same man page, how many members are in a variable of type struct rusage?
16 members

Why do you think we pass before and after by reference (instead of by value) to calculate, even though we’re not changing their contents?
By passing reference, we are not making copies of the values. This hence saves memory allocation and time.

##Explain as precisely as possible, in a paragraph or more, how main goes about reading words from a file.
In other words, convince us that you indeed understand how that function’s for loop works.

The for loop's parameters sets the read for characters until the end of the file. It creates a word out of a character array by only allowing
alphabetical characters and apostrophes up to a certain length. If more characters than LENGTH are read or numbers are read, in other words, if index increases beyond
LENGTH, then the word is reset by setting index to 0. If all parameters are satisfied(  an array of alphabetical/apostrophe characters <LENGTH), then the \0 is appended to the end of the array
to signify the end of the word.

Why do you think we used fgetc to read each word’s characters one at a time rather than use fscanf with a format string like "%s" to read whole words at a time?
Put another way, what problems might arise by relying on fscanf alone?
Using fscanf alone leads to the possibility of buffer overflow if we read a string larger than the maximum length specified for the character array.
Also, fgetc allows us to specify the character types that we read in, rejecting digits and non-apostrophe punctuation.

##Why do you think we declared the parameters for check and load as const?
Since we want the input strings to not be passed by reference as the main program still outputs these strings.