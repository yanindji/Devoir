/*#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Format : %s <parameter1> <parameter2>\n", argv[0]);
        return 1;
    }
    FILE *fichier1, *fichier2;
    int ret;
    fichier1 = fopen(argv[1], "r");
    if (fichier1 == NULL)
    {
        printf("Error, can't open %s\n", argv[1]);
        exit(1);
    }

    fichier2 = fopen(argv[2], "w");
    if (fichier2 == NULL)
    {
        fclose(fichier1);
        printf("Error, can't open %s\n", argv[2]);
        exit(2);
    }
    else
    {
        int current_char = 0;
        while (1)
        {
            current_char = fgetc(fichier1);
            fputc(current_char, fichier2);
            // printf("%c", current_char);
            if (current_char == EOF)
                break;
        }
    }
    printf("La copie s'est bien passée.\n");

    fclose(fichier1);
    fclose(fichier2);

    return 0;
}*/
#include <errno. h>
 #include<stdio. h>
 #include<stdlib. h>



int main()
{
    int i;
unsigned char digest[LENGTH];
static const char hex[] = "0123456789abcdef";
if (!buf) buf = malloc(2 * LENGTH + 1);
if (!buf) return 0;
 MD5Final(digest, ctx);
  for (i = 0; i < LENGTH; i++)

    { buf[i + i] = hex[digest[i] >> 4];
   buf[i + i + 1] = hex[digest[i] & 0x0f];
    }
    buf[i + i] = '\0';
  return buf;
  }
  char *MD5File(const char *filename, char *buf)
  {
      return (MD5FileChunk(filena­me, buf, 0, 0));
      }
      char *MD5FileChunk(const char *filename, char *buf, off_t ofs, off_t len)

{ unsigned char buffer[BUFSIZ];
 MD5_CTX ctx;
  struct stat stbuf;
  int f, i, e;
  off_t n;
  MD5Init(&ctx);
  #ifdef­ _WIN32 f = _open(filename, O_RDONLY | O_BINARY);

  #else

  f = open(filename, O_RDONLY);
  #endif
   if (f < 0)
        return 0;
 if (fstat(f, &stbuf) < 0)
    return 0;
 if (ofs > stbuf.st_size) ofs = stbuf.st_size;
 if ((len == 0) || (len > stbuf.st_size - ofs))
    len = stbuf.st_size - ofs;
 if (lseek(f, ofs, SEEK_SET) < 0)
    return 0;
 n = len;
  i = 0;
   while (n > 0)
    {
        if (n > sizeof(buffer)) i = read(f, buffer, sizeof(buffer));
  i = read(f, buffer, sizeof(buffer));
   else i = read(f, buffer, n);
   if (i < 0)
    break;
   MD5Update(&ctx, buffer, i);
    n -= i;
    }
    e = errno;
     close(f);
      errno = e;
      if (i < 0) return 0;
      return (MD5End(&ctx, buf));

      }


