# Technical Quiz - UBC Sailbot Software

> Compress files and submit them software@ubcsailbot.org within 48 hours.

## Programming

Using C++, please write a class, named StandardCalc, that contains the following methods. You may use any resources you find but must complete the quiz individually.

*Keep your code clean, use the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).*

1. An autonomous sailing program uses angles between -180 and 179. Create a method with the following declaration:
```cpp
/**
 * Bounds the provided angle between [-180, 180) degrees.
 * Ex. 360 becomes 0, 270 becomes -90, -450 becomes -90.
 * @param angle Input angle in degrees.
 * @return The bounded angle in degrees.
 */
float BoundTo180(float angle);
```

2. It's incredibly valuable to be able to determine an angle is between two others.  Create a method with the following declaration:
```cpp
/**
 * Determines whether |middle_angle| is in the acute angle between the other two bounding angles.
 * Note: Input angles are bounded to 180 for safety.
 * Ex. -180 is between -90 and 110 but not between -90 and 80.
 * @param first_angle First angle in degrees.
 * @param middle_angle Middle angle in degrees.
 * @param second_angle Second angle in degrees.
 * @return Whether |middle_angle| is between |first_angle| and |second_angle| (exclusive).
 */
bool IsAngleBetween(float first_angle, float middle_angle, float second_angle);
```

3. Unit test your methods with a testing framework of your choosing. Bonus points for Google Test.


## Version Control

For the following questions, write out Git commands as you would from command line.
Write your answer in a file named `sailbot_git_questions.txt`.

1. How would you clone [this repository](https://bitbucket.ubcsailbot.org/projects/TOOLS/repos/bash-settings) onto your computer?
2. Suppose you have some uncommitted changes with a desired message: `“Tuned wind angles and added unit tests.”`  You have a modified file `wind_angles.inc` and added a new file `TestWindAngles.h`.  How would you submit all of your changes to the remote repository you cloned above?
