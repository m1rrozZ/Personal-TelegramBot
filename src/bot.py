import telebot
from config import TG_TOKEN
from handlers import register_handlers
import sys, os

sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '../src')))

bot = telebot.TeleBot(TG_TOKEN)

register_handlers(bot)

bot.polling()