# PS1: LFSR / PhotoMagic

## Contact
Name: Ansh Patel

Section: 202

Time to Complete: ~14 Hours


## Description
Explain what the project does.

The project is a C++ implementation of a Fibonacci Linear Feedback Shift Register (LFSR) used for generating pseudorandom numbers. It produces new bits by applying XOR operations on specific tap positions (0, 2, 3, and 5). Each call to the step() method shifts the seed left and inserts the newly generated bit at the rightmost position. The generate(k) method repeatedly calls step() k times to produce a k-bit pseudorandom number. The project also includes Boost unit tests to verify correctness, ensure proper error handling, and validate seed updates and bit generation. Using this FibLFSR, we create a transform method that helps us manipulate individual pixels to encrypt and decrypt images. We use the SFML framework to display the original VS encrypted images and encrypted VS decrypted(original) images.

### Features
Describe the representation you used and why you did things that way as well as any other interesting design decisions you made.

#### Part a
The constructor ensures the seed is exactly or lesser than 16 bits and contains only '0' and '1', with an overloaded constructor converting an unsigned int to a binary string. The step() function shifts the seed left and computes the new bit using an XOR operation on specific tap positions (0, 2, 3, and 5). The generate(k) function repeatedly calls step(), accumulating the result as an integer. The insertion operator is overloaded for easy output, and unit tests validate correctness and error handling. These design choices prioritize simplicity, efficiency, and robustness.

#### Part b
The PhotoMagic class initializes a transform method that access every individual pixel and manipulate its red, green and blue color component to encrypt the given image. It takes in input_filename, output_filename and a seed(string or unsigned int) from the commandline as arguments. The SFML framework is used to display the original image against the new encrypted image. If the encrypted image is passed in as a input_file with the same seed used to encrypt it, the new output_file will return the original/decrypted image.

### Issues
What doesn't work.  Be honest.  You might be penalized if you claim something works and it doesn't.

Overall, the implementation works as intended to. It compiles correctly without any errors and creates all the required files.

### Tests
Describe what is being tested in your Boost unit tests.

The testStepInstr test verifies that the step() function correctly computes the new bit using the XOR operation and updates the LFSR state as expected. The testGenerateInstr test ensures that the generate(k) function produces the correct k-bit output by calling step() k times and accumulating the result. The testStepUpdatesSeed test checks whether the seed is updated correctly after multiple calls to step(). The test compares the expected seed state after each shift to ensure correctness. For error handling, the testConstructorInvalidInput test ensures that the constructor throws a std::invalid_argument exception if the provided seed contains invalid characters or is negative. Similarly, the testGenerateInvalidInput test checks whether generate(k) throws an exception when k is negative. Finally, the testStream test verifies that the overloaded insertion operator correctly outputs the LFSR seed.

### Extra Credit
Anything special you did. This is required to earn bonus points.

Generally the constructor takes a 16 bit string representation as a seed but I have created another constructor that takes an unsigned integer as the seed and then converts it to a 16 bit string.

## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.

Bitset operator: https://bloomfield.online/posts/convert-a-number-to-a-binary-string-and-back-in-cpp/
Shifting to left: https://www.geeksforgeeks.org/left-shift-right-shift-operators-c-cpp/
Unit testing: https://www.boost.org/doc/libs/1_53_0/libs/test/doc/html/utf/tutorials.html
Test Cases: Prof. Dr Daly (testStepInstr, testGenerateInstr)

### Credits
List where you got any images or other resources.

No other images or resources were used for Part a.
Cat.png: provided by Prof. Dr Daly.
pixels.cpp: Prof. Dr Daly
