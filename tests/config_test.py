import os
from dotenv import load_dotenv

def test_token_from_env():
    dotenv_path = os.path.join(os.path.dirname(__file__), '../.env')
    load_dotenv(dotenv_path=dotenv_path)
    
    token = os.getenv("TG_TOKEN")
    assert token is not None, "TG Token should not be None"