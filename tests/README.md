# For Development and Testing

 This folder contains all the unit tests for `Personal-Bot`.
 These tests ensure that the bot is functioning as excepted and that future changes do not introduce issues.

---

 ## Test Overview.

  Currently, the test foccus on:
*  Initialization of the bot.  
*  Registering of handlers.
*  Polling behavior of the bot.
*  Extracting  the token from the `.env` file. (Read more about `.env` file in the main README.md of the repository)

## Running test.

To run the test: 

1. Set the depedency list:  `pip install -r requirements.txt`

 2. Create a virtual environment to isolate the dependencies: (In the console type the following commands) 
 `python -m venv venv`

3. Log in to the virtual environment using the command:
For Windows: `.\venv\Scripts\activate`
For macOS/Linux `source venv/bin/activate`

4. Run the tests using the command: `pytest` or `pytest -v`.