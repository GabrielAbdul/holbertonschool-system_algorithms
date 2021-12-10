#include "huffman.h"

/**
 * symbol_create - creates a symbol_t data structure
 * @data: data to be stored in structure
 * @freq: associated frequency
 * Return: pointer to symbol or NULL on failure
 */
symbol_t *symbol_create(char data, size_t freq)
{
	symbol_t *symbol = malloc(sizeof(symbol_t));

	if (symbol == NULL)
		return (NULL);

	symbol->data = data;
	symbol->freq = freq;

	return (symbol);
}
