#ifndef _SPIRAM_H
#define _SPIRAM_H

#include <WProgram.h>
#include <DSPI.h>

class SPIRAM {
    public:
        SPIRAM(DSPI *spi, uint8_t cs, uint32_t s) : _spi(spi), _cs(cs), _size(s) {}
        uint8_t read(uint32_t address);
        void read(uint32_t address, uint8_t *data, uint32_t len);
        void write(uint32_t address, uint8_t data);
        void write(uint32_t address, uint8_t *data, uint32_t len);
        void begin();
        uint8_t operator[](uint32_t address) { return read(address); }
        uint32_t size() { return _size; }
    private:
        uint32_t _size;
        uint8_t _cs;
        DSPI *_spi;
};

#endif
