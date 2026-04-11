# CSE3150-HW-DAY-14

In this homework, I used pointers and parallel arrays to keep track of names and GPAs, which is great practice for managing data manually. I used const and references to make sure that things that shouldn't change (like student names during printing) stayed protected. Using a reference is also way better than copying because it points directly to the data instead of making a huge extra copy, which is a big deal when you start working with larger sets of information.

For control flow, I used a do-while loop and a switch to keep the menu running until the user wants to quit. I also used exceptions to catch errors—like trying to add a student when the list is full or calculating an average with no data—so the program doesn't just crash. Finally, I used static_cast<int> to convert the double GPA average into a rounded integer, which shows how we can change data types on the fly to get the exact output we need.

GITHUB REPO: https://github.com/MEG22019/CSE3150-HW-DAY-14