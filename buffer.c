#include "main.h"
#include <unistd.h>

/**
 * init_buffer - Initialize a buffer structure
 * @buf: Buffer structure
 */
void init_buffer(buffer_t *buf)
{
    buf->index = 0;
    buf->size = BUFFER_SIZE;
}

/**
 * flush_buffer - Flush the buffer to the standard output
 * @buf: Buffer structure
 *
 * Return: Number of characters flushed
 */
int flush_buffer(buffer_t *buf)
{
    int count = 0;

    if (buf->index > 0)
    {
        write(1, buf->buffer, buf->index);
        count += buf->index;
        buf->index = 0;
    }

    return count;
}

/**
 * add_to_buffer - Add a character to the buffer
 * @buf: Buffer structure
 * @c: Character to add
 */
void add_to_buffer(buffer_t *buf, char c)
{
    if (buf->index == buf->size - 1)
        flush_buffer(buf);

    buf->buffer[buf->index++] = c;
}

/**
 * free_buffer - Free memory used by the buffer
 * @buf: Buffer structure
 */
void free_buffer(buffer_t *buf)
{
    flush_buffer(buf);
}
