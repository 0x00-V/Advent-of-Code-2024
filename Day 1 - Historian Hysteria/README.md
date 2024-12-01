# Day 1: Historian Hysteria

The Chief Historian is always present for the big Christmas sleigh launch, but nobody has seen him in months! Last anyone heard, he was visiting locations that are historically significant to the North Pole; a group of Senior Historians has asked you to accompany them as they check the places they think he was most likely to visit.

As each location is checked, they will mark it on their list with a star. They figure the Chief Historian must be in one of the first fifty places they'll look, so in order to save Christmas, you need to help them get fifty stars on their list before Santa takes off on December 25th.

Collect stars by solving puzzles. Two puzzles will be made available on each day in the Advent calendar; the second puzzle is unlocked when you complete the first. Each puzzle grants one star. Good luck!

## Part 1: The Lists of Locations

You haven't even left yet and the group of Elvish Senior Historians has already hit a problem: their list of locations to check is currently empty. Eventually, someone decides that the best place to check first would be the Chief Historian's office.

Upon pouring into the office, everyone confirms that the Chief Historian is indeed nowhere to be found. Instead, the Elves discover an assortment of notes and lists of historically significant locations! This seems to be the planning the Chief Historian was doing before he left. Perhaps these notes can be used to determine which locations to search?

Throughout the Chief's office, the historically significant locations are listed not by name but by a unique number called the location ID. To make sure they don't miss anything, the Historians split into two groups, each searching the office and trying to create their own complete list of location IDs.

There's just one problem: by holding the two lists up side by side (your puzzle input), it quickly becomes clear that the lists aren't very similar. Maybe you can help The Historians reconcile their lists?

### Puzzle Input Example:

```
3   4
4   3
2   5
1   3
3   9
3   3
```

### Task:
Pair up the smallest number in the left list with the smallest number in the right list, then the second-smallest left number with the second-smallest right number, and so on. For each pair, calculate the **distance** between the two numbers by subtracting one from the other. Sum all the distances to find the total distance between the lists.

### Example Walkthrough:

- The smallest number in the left list is `1`, and the smallest number in the right list is `3`. The distance between them is `|1 - 3| = 2`.
- The second-smallest number in the left list is `2`, and the second-smallest number in the right list is `3`. The distance between them is `|2 - 3| = 1`.
- The third-smallest number in both lists is `3`, so the distance is `|3 - 3| = 0`.
- The next pair is `3` and `4`, distance `|3 - 4| = 1`.
- The next pair is `3` and `5`, distance `|3 - 5| = 2`.
- The largest number in the left list is `4`, and the largest number in the right list is `9`, so the distance is `|4 - 9| = 5`.

### Total Distance:  
`2 + 1 + 0 + 1 + 2 + 5 = 11`

Once you've calculated the total distance between your lists, that will be your solution for Part 1.

---

## Part 2: The Similarity Score

Your analysis only confirmed what everyone feared: the two lists of location IDs are indeed very different.

Or are they?

The Historians can't agree on which group made the mistakes or how to read most of the Chief's handwriting, but in the commotion, you notice an interesting detail: a lot of location IDs appear in both lists! Maybe the other numbers aren't location IDs at all but rather misinterpreted handwriting.

### Task:
This time, calculate a **total similarity score** by adding up each number in the left list after multiplying it by the number of times that number appears in the right list.

### Example Walkthrough:

For the input:

```
3   4
4   3
2   5
1   3
3   9
3   3
```

- The first number in the left list is `3`. It appears in the right list three times, so the similarity score increases by `3 * 3 = 9`.
- The second number in the left list is `4`. It appears in the right list once, so the similarity score increases by `4 * 1 = 4`.
- The third number, `2`, does not appear in the right list, so the similarity score increases by `2 * 0 = 0`.
- The fourth number, `1`, also does not appear in the right list, so the similarity score increases by `1 * 0 = 0`.
- The fifth number, `3`, appears in the right list three times, so the similarity score increases by `3 * 3 = 9`.
- The sixth number, `3`, again appears three times in the right list, so the similarity score increases by `3 * 3 = 9`.

### Total Similarity Score:  
`9 + 4 + 0 + 0 + 9 + 9 = 31`

Once you've calculated the total similarity score, that will be your solution for Part 2.

---

### Goal:
Solve both parts of the puzzle by calculating the total distance between the two lists (Part 1) and the total similarity score (Part 2).
```
