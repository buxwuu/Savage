TEAM MEMBERS:
  Krishna Adettiwar
  Sam Berger
  Hunter Haller
  Max Hayne
  Kevin Kirk

TITLE:
  ALBUQUERQUE

VISION STATEMENT FOR TEAM SAVAGE:
  Vision Statement for Savage: Make a fun text-based adventure game that saves your progress between sessions to a username, being able to store an in-game inventory using mySQL, and being able to access this game via a website which anyone can access and log into their game from. Additionally, we hope to learn how to use software methodologies and work as a well-functioning and cohesive team of five.

FEATURES:
Over the course of the semester, we have been building a text-based adventure game. Of the many features we've decided to include in this game, three features that we will be testing for Milestone 5 is:

1. Being able to login to your personal user account and match the password. If password is incorrect, don't login. If username is not found offer the option to create a new username. The usernames and passwords are stored in a mySQL database.
2. Being able to login and access the game save file and continue progress through the story.
3. Being able to pick up items through the game and store these items in an inventory database in mySQL, where each user has their own inventory.


EXPLANATIONS FOR SCREENSHOTS:

Our game is a C++ file that uses mySLQ Connector to read and write data to the mySQL database that stores all the usernames and passwords, the game save data per user account, and the inventory for each user. For the purpose of Milestone 5, we are running this file in a terminal instead of a web browser (but the actual project will work in a full fledged terminal running
in a web browser.) In the first screenshot (located in this directory), the executable recognizes that a username that doesn't exist in the mySQL database and offers to create a new user account or try again. Then we can see that we try a valid username and it searches through the mySQL database and then after it verifies the username exists, it asks for a password and verifies that from the database as well. Once the username and password is accepted (either from entering an existing username and password or creating a new user account with a password), the game begins.

In screenshot 2, we see the script runs an instance where the user wants to check their inventory. Here, the game checks the backend mySQL database under that user account and prints all the contents in the inventory of that speicific user to the terminal output.

In screenshot 3, we see all three features working together. We see a user login, show the inventory is empty, then pick up an item, then we show that the inventory now has the item.
