#include <SPIRAM.h>

void SPIRAM::begin() {
    _spi->begin();
    _spi->setSpeed(20000000UL);
    pinMode(_cs, OUTPUT);
    digitalWrite(_cs, HIGH);
}

uint8_t SPIRAM::read(uint32_t address) {
    uint8_t b;  
    digitalWrite(_cs, LOW);
    _spi->transfer(0x03);
    _spi->transfer((address >> 16) & 0xFF);
    _spi->transfer((address >> 8) & 0xFF);
    _spi->transfer((address >> 0) & 0xFF);
    b = _spi->transfer(0x00);
    digitalWrite(_cs, HIGH);
    return b;
}

void SPIRAM::read(uint32_t address, uint8_t *b, uint32_t len) {
    digitalWrite(_cs, LOW);
    _spi->transfer(0x03);
    _spi->transfer((address >> 16) & 0xFF);
    _spi->transfer((address >> 8) & 0xFF);
    _spi->transfer((address >> 0) & 0xFF);
    for (uint32_t i = 0; i < len; i++) {
        b[i] = _spi->transfer(0x00);
    }
    digitalWrite(_cs, HIGH);
}

void SPIRAM::write(uint32_t address, uint8_t b) {
    digitalWrite(_cs, LOW);
    _spi->transfer(0x02);
    _spi->transfer((address >> 16) & 0xFF);
    _spi->transfer((address >> 8) & 0xFF);
    _spi->transfer((address >> 0) & 0xFF);
    _spi->transfer(b);
    digitalWrite(_cs, HIGH);
}


void SPIRAM::write(uint32_t address, uint8_t *b, uint32_t len) {
    digitalWrite(_cs, LOW);
    _spi->transfer(0x02);
    _spi->transfer((address >> 16) & 0xFF);
    _spi->transfer((address >> 8) & 0xFF);
    _spi->transfer((address >> 0) & 0xFF);
    for (uint32_t i = 0; i < len; i++) {
        _spi->transfer(b[i]);
    }
    digitalWrite(_cs, HIGH);
}

