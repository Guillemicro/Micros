
void setup()
{
    DDRB |= 0xFF;  // Configura todos los bits de PORTB como salida (PB0..PB7)

    DDRD &= ~0xFF; // Configura todos los bits de PORTD como entrada (PD0..PD7)

    PORTD |= 0xFF; // Habilita resistencias pull-up internas en PD0..PD7
}

void loop()
{
    // Recorre las 8 entradas en PORTD y controla los 8 bits en PORTB
    for (uint8_t bit = 0; bit < 8; ++bit) {
        // Con pull-up activada, el pin está activo cuando lee 0
        if (!(PIND & (1 << bit))) {
            // Enciende el LED correspondiente (set bit)
            PORTB |= (1 << bit);
            delay(1000);
            // Apaga el LED (clear bit)
            PORTB &= ~(1 << bit);
            delay(1000);
        } else {
            // Asegura que esté apagado
            PORTB &= ~(1 << bit);
        }
    }
}
