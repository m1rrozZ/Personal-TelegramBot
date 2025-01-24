import os
from dotenv import load_dotenv

# Go up a level to find the .env file. (The problem is related to the structure..)
dotenv_path = os.path.join(os.path.dirname(__file__), '../.env')
load_dotenv(dotenv_path=dotenv_path)

TG_TOKEN = os.getenv("TG_TOKEN")

if not TG_TOKEN:
    raise ValueError("TG_TOKEN is not set")