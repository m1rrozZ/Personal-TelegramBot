# Imports.
import sys
import os
import pytest
from unittest.mock import MagicMock, AsyncMock
import telebot

sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '../src')))

from src.bot import bot
from src.handlers import register_handlers

# Tests..
def test_bot_initialization():
    assert isinstance(bot, telebot.TeleBot)
    
def test_register_handlers():
    bot.message_handler = MagicMock()
    register_handlers(bot)
    
    # Проверяем, что два обработчика были зарегистрированы.
    assert bot.message_handler.call_count == 2
    
    # Проверяем, что первый обработчик был вызван с командой `start`
    first_call = bot.message_handler.call_args_list[0]
    assert 'commands' in first_call[1]
    assert first_call[1]['commands'] == ['start']
    
    # Проверяем, что второй обработчик был вызван с функцией, которая всегда возвращает True
    second_call = bot.message_handler.call_args_list[1]
    assert 'func' in second_call[1]
    assert second_call[1]['func'](None) # Проверяем, что функция возвращает True


    
@pytest.mark.asyncio
async def test_bot_polling(monkeypatch):
    # Мокаем polling, чтобы он не блокировал тесты.
    mock_polling = AsyncMock()
    monkeypatch.setattr(bot, 'polling', mock_polling)
    
    # Устанавливаем таймаут на 5 секунд.
    mock_polling.return_value = None
    await bot.polling(timeout=5)
    
    # Проверяем, что polling был вызван.
    mock_polling.assert_called_once()
    