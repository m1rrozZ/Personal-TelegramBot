def register_handlers(bot):
    @bot.message_handler(commands=['start'])
    def send_welcome(message):
        bot.send_message(message.chat.id, "Welcome to my awesome bot!")
        
    @bot.message_handler(func=lambda message: True)
    def echo_all(message):
        bot.reply_to(message, message.text)